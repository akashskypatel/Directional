# M3 CP4c-3 TB2 — Artifact-Only Test + Benchmark Report

Date: 2026-08-31 UTC
Turn: `M3-CP4c-3-TB2`
Status: **COMPLETE / BLOCKED — ORCHESTRATION-INVALID AFTER RUNTIME BEGAN / NO GATE AUTHORITY**

- Phase: M3 / CP4c-3
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Immutable semantic/evidence source: `005512f20ed56edc793f4d6505f3d2b4c2999c71`
- Immutable GMP package **69**: artifact `9742715856`, SHA-256 `2accc6d7cbbd48531919518ceb93a9d8f837b1c5683769a88ef915e4f092efc5`
- Packaged source archive SHA-256: `c7cd8b4bbba2d3b374da7c7f18e27c0e688ffe7679c261b644c6fffbf34426b1`
- Frozen selector 373 SHA-256: `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`
- Execution mode: local artifact-only fresh-process harness; no rebuild/repair/relink/generated discovery/package mutation

## 1. Preflight authority

Package 69 passed the frozen TB2 preconditions before the first Directional process:

- outer Actions artifact SHA-256 matched exactly;
- internal package manifest: **28/28 PASS**;
- packaged source commit matched `005512f20ed56edc793f4d6505f3d2b4c2999c71`;
- packaged source archive SHA-256 matched exactly;
- source-status snapshots were empty;
- packaged producer/authority/completion/validation test binaries retained executable mode `0755`;
- `runtimeExecution=false` and `exactArithmeticBackend=GMP` reproduced from package evidence;
- authoritative link evidence contained both `libgmpxx` and `libgmp`;
- selector 373 had **373 lines / 373 unique identities**;
- frozen 355/357/361/365/367/370/373 hashes reproduced exactly and every predecessor was a byte-exact prefix;
- configure/compile/relink/repair/generated-discovery/benchmark/source/test/fixture/selector/package-mutation flags were all false.

Static target ownership resolved all 373 selectors against the already-packaged binaries without running generated discovery: producer 227, authority-kernel 30, completion 75, validation 41. Seven duplicate source matches were disambiguated from committed CMake target ownership.

## 2. Attempt result — harness invalid, not semantic red

The selector began in frozen order, one exact `--gtest_filter=<identity>` per fresh process. Ordinals **1–40** each selected exactly one test and exited 0. Ordinal **41** selected exactly one test and then failed immediately:

- ordinal: **41**
- identity: `MilestoneGP26.PrescribedSphereSingularitiesMatchRecoveredValence`
- selected count: **1**
- process exit: **1**
- exception: `Failed to open benchmark manifest: /home/runner/work/Directional/Directional/benchmarks/fixtures/milestone_g_manifest.json`

The harness script labeled the nonzero process `SEMANTIC_RED`; that label is **overridden by evidence classification**. The failure occurred before the tested product contract because the fixture loader could not open its input. It is an orchestration/harness failure and receives **zero semantic gate credit**.

Ordinals **42–373 were not executed**. In particular, checkpoint-local ordinals 366–373 were never reached, so TB2 provides no runtime disposition for Amendment 15, the prescribed sphere provenance, R10, or R8.

## 3. Root cause

The required fixture is present and immutable inside package 69's packaged source at:

`benchmarks/fixtures/milestone_g_manifest.json`.

`tests/TestFixturePaths.h` first searches sibling/bin `test-data` layouts. Package 69 does not contain that sibling `test-data`, so it falls back to compile-time `DIRECTIONAL_TEST_SOURCE_DIR`. The producer target was compiled with:

`DIRECTIONAL_TEST_SOURCE_DIR=/home/runner/work/Directional/Directional`.

The local artifact-only launch extracted the packaged source under a different root, so the binary's fallback absolute path did not exist even though the exact fixture bytes were packaged. This is the same defect family as `LESSONS.md` 76 at one level deeper: preserving archive layout is insufficient unless the execution harness also proves the **actual runtime fixture root selected by the binary**.

No package or product change is implicated by this stop.

## 4. Frozen retry/stop rule

The TB2 plan permits an orchestration-only restart from ordinal 1 only when the prior attempt executed **no Directional runtime**. This attempt executed 41 Directional test processes before the harness defect was classified. Therefore this turn may **not** materialize the source at the baked fixture root and retry, even though that would be a control-plane-only correction.

The attempt is preserved as **BLOCKED / ORCHESTRATION-INVALID AFTER RUNTIME BEGAN** and routes to an independent `REVIEW + PLAN`. The review must freeze the correct artifact-only launch precondition and decide whether unchanged package 69 may be re-executed. No product/test/build correction or replacement package is authorized by this TB result.

## 5. Postflight immutability

After the stop:

- package outer SHA-256 remained `2accc6d7cbbd48531919518ceb93a9d8f837b1c5683769a88ef915e4f092efc5`;
- internal package manifest remained **28/28 PASS**;
- packaged source archive remained `c7cd8b4bbba2d3b374da7c7f18e27c0e688ffe7679c261b644c6fffbf34426b1`;
- selector 373 remained `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`;
- packaged producer executable mode remained `0755`;
- a fresh re-extraction of the packaged source compared byte-for-byte equal to the execution source tree;
- no configure, compile, relink, repair, generated discovery, benchmark, source/test/fixture/selector/package mutation occurred.

Package 69 and selector 373 therefore remain immutable future authority; this attempt simply has no acceptance authority.

## 6. Regression and accounting disposition

New candidate: `M3-CP4c3-TB2-ORCH-01` — **ORCHESTRATION / NON-STABLE / REVIEW REQUIRED**.

This is not a stable regression event or recurrence because the accepted product contract was not reached at ordinal 41 and no accepted-prefix semantic failure was observed. The 40 earlier green processes are diagnostic only because the attempt as a whole is invalid under the frozen harness authority.

Stable accounting remains **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative M3 package count remains **69**.

## 7. Disposition and exact successor

`M3-CP4c-3-TB2` is formally complete as **BLOCKED / ORCHESTRATION-INVALID / NO GATE AUTHORITY**. CP4c-3 remains **OPEN**.

Exact successor: independent **`M3-CP4c-3-TB2-REV` — REVIEW + PLAN**. It must update `ORIENTATION.md`, adjudicate `M3-CP4c3-TB2-ORCH-01`, freeze a fixture-root preflight that proves the path actually selected by `TestFixturePaths`, and decide/authorize the next artifact-only execution. Until then, package 69 and selector 373 stay unchanged and no product correction/rebuild is authorized.
