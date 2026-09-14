# M4-CP-SCALE-TB2 Artifact-Only Test + Benchmark Plan — S2 Vertex-Star Equivalence

**Planned turn:** `M4-CP-SCALE-TB2-EXEC`
**Boundary:** artifact-only runtime execution; immutable package; no rebuild/repair/mutation
**Candidate package:** artifact `10367451675` (`m4-cp-scale-cb2-result-34892831641`)
**Packaged semantic source:** `63cb20d6ba5393058086c62c6422ac58b75c939e`
**Package SHA-256:** `9a1b59bcbf6cbe14e1df180b0feaaeec6bf9e675d010f66303bc39cf4c83ddec`
**Package manifest:** 28/28, SHA-256 `b229f38237f3e3f00dfd70f5f4f28f8faae0af9a888609c2c397b6fb8af1e47b`
**Packaged source archive SHA-256:** `de4667b5677ba3b60ae1737299ae3edb111cefa453e6ac4cc3f7357fe3607f27`

## 1. Authority and purpose

TB2-EXEC tests only the frozen S2 vertex-star certified-filter/exact-oracle prediction on the immutable CB2 package. It does not decide promotion. Current accepted runtime authority entering EXEC remains predecessor package `10360085644` / source `a359b981f9350139304bc5a654041dfba78609b6` / selector423 **423/423**.

The focused identity is outside selector423 and therefore receives **zero gate rows** in EXEC:

`M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`

Mandatory runtime-free `M4-CP-SCALE-TB2-REV` alone may interpret the focused result, decide package promotion, or authorize a later selector-publication Code + Build slice.

## 2. Immutable preflight

Before any Directional runtime:

1. Download artifact `10367451675` exactly once and record provider ZIP SHA-256 `9a1b59bcbf6cbe14e1df180b0feaaeec6bf9e675d010f66303bc39cf4c83ddec`.
2. Verify every root `SHA256SUMS` row and prove the manifest excludes itself; require exactly 28 verified entries and manifest SHA-256 `b229f382...af1e47b`.
3. Verify `metadata/source-commit.txt` equals `63cb20d6...c939e`, `build-exit-code.txt=0`, `preflight-exit-code.txt=0`, all source-status receipts are empty, and `command-boundary.txt` records `runtimeExecution=false` and `exactArithmeticBackend=GMP`.
4. Verify all six packaged executables and two static libraries required by the CB2 package are present with their preflight byte/mode census recorded.
5. Extract the packaged source archive only as evidence and verify its SHA-256 `de4667b5...07f27`.
6. From packaged source, verify selector423 is exactly 423 LF rows / `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`, first422 is `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`, and the static owner partition is **30 / 277 / 75 / 41**.
7. Verify the focused identity is present in packaged `tests/FieldAlignedCurveNetworkTests.cpp` but absent from selector423.
8. Create a fresh execution view copied from immutable package bytes; do not configure, compile, relink, regenerate, repair, edit, or run discovery/list/help/version commands.

Any preflight mismatch is an **orchestration/integrity stop** with zero semantic credit. Do not repair the package in place.

## 3. Focused S2 execution — exactly once

Run only:

`directional_surface_cell_producer_tests --gtest_filter=M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`

in one fresh process with an exact-filter selection check. Require exit 0 and exactly one selected identity. Do not retry a started semantic process inside EXEC.

Preserve raw stdout/stderr and require the PASS receipt to contain all six expected subject labels:

- `positive-strict-interior` — seed `(1,2)`, independent sign `+1`, route `Filter`;
- `negative-opposite-order` — `(2,1)`, sign `-1`, route `Filter`;
- `near-boundary-certified` — `(1099511627776,1099511627775)`, nonzero sign `-1`, route `Filter`;
- `exact-boundary-fallback` — `(1,1)`, sign `0`, route `ExactFallback`, radial=true;
- `tamper-base` — `(5,4)`, sign `-1`, route `Filter`;
- `tamper-crossed` — `(3,4)`, sign `+1`, route `Filter`.

The tamper pair must report different exact signs and expected owners. The exact-boundary subject must report the independently frozen half-open owner and radial boundary. EXEC records what the test proves; it must not infer a numeric tolerance, filter threshold, S1 safety bound, arrival-order authority, or selector membership from these receipts.

## 4. Accepted selector423 re-proof — 423 fresh processes

Execute the unchanged accepted selector423 after the focused identity, one selector row per **fresh process**, exact-filtered by the literal selector identity. Use the frozen static owner mapping from packaged source/CMake; do **not** call `--gtest_list_tests` or any generated discovery path.

For every row require:

- process starts from the immutable execution view;
- exactly one identity is selected;
- exit code and raw log are recorded;
- no SKIP, timeout, crash, or selection mismatch is silently counted as PASS.

Expected owner census is **30 authority-kernel / 277 producer / 75 completion / 41 validation**. Record the complete 423-row process ledger and raw per-process logs. Fail-fast on integrity/orchestration failure. Semantic fail-fast may stop at the first RED only if the frozen execution harness records the untouched remainder as unexecuted rather than PASS.

The focused S2 identity is separate from these 423 accepted rows. The cumulative gate count remains selector423 only.

## 5. Postflight immutability

After all started runtime is complete, compare package, packaged-source and execution-view byte+mode censuses against preflight. Require exact equality and explicitly record:

- configureExecution=false;
- compileExecution=false;
- relinkExecution=false;
- repairExecution=false;
- generatedDiscovery=false;
- mutationExecution=false;
- benchmarkExecution=false;
- package/source/execution-view census equality=true.

No benchmark binary is authorized in TB2-EXEC despite being packaged.

## 6. Evidence package

Publish one non-self-referential evidence archive containing at minimum:

- package/provider identities and full verified preflight;
- focused S2 exact-filter command, raw log, exit/selection result and parsed six-subject receipt;
- selector423 file/hash/first422 hash/static owner map;
- 423-row process ledger plus every raw selector process log;
- exact postflight byte+mode censuses and execution-prohibition booleans;
- a self-excluding evidence `SHA256SUMS` covering every evidence file except itself.

Publication itself must not execute Directional runtime. Re-open the published artifact and reverify the nested evidence archive/manifest before EXEC closeout.

## 7. Mechanical EXEC disposition

TB2-EXEC may report only mechanical facts:

- focused S2 PASS/RED and receipt completeness;
- selector423 PASS/RED/SKIP/timeout/crash/selection-mismatch counts;
- immutable postflight status;
- evidence publication identity.

It may **not** promote artifact `10367451675`, append selector424, declare S2 accepted, modify stable accounting, set an S2 filter threshold, reinterpret the S1 4096-bit operational guard, or choose later S2/arrival/S3/S4/S5 work.

Exact successor after any mechanically complete EXEC is mandatory runtime-free **`M4-CP-SCALE-TB2-REV`**. If EXEC cannot complete because of orchestration/integrity failure, preserve exact evidence and route according to `Turn_Cadence.md`; do not patch or rerun semantics ad hoc.
