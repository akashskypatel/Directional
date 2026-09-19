# M4-CP4-TB3-EXEC Artifact-Only Test + Benchmark Plan

**Turn:** `M4-CP4-TB3-EXEC`
**Type:** immutable artifact-only Test + Benchmark
**Predecessor:** `M4-CP4-CB8`
**Input package:** artifact `10591801825` / `m4-cp4-cb8-result-result-35468097574`
**Exact compiled source:** `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431`
**Benchmark gate:** none; benchmark execution count must remain zero

## 1. Immutable preflight

1. Download artifact `10591801825` once and verify provider ZIP SHA-256 `20d9b07bae631e68f3292ee37ccb80c4724bae6eec0c50cd2274c36443183da6`.
2. Extract with a mode-preserving archive tool. Do not repair package bytes or executable modes.
3. Verify package `SHA256SUMS` **26/26**, manifest SHA-256 `30c3f51fa0e43882d1a3c1227f58c069023007e38dbdc9a96c832ce152157b5a`, source archive SHA-256 `4d057381ba3f1caed55579f7a9b662753632637eb0aff7b1432326d8e557021a`, exact source commit, clean source receipts, GMP/GMPXX evidence, and `runtimeExecution=false` from CB8.
4. Require the four packaged owner executables to retain mode `0755`.
5. Read selector430 only from the immutable packaged source. Require **430 LF rows / 35,001 bytes / SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`**, exact first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`, exact final three rows, and owner census **31 / 283 / 75 / 41**.
6. Freeze byte+mode censuses for package, packaged source and execution view before runtime.
7. A zero-selected filter, missing owner, wrong executable mode, package mismatch, selector mismatch, or any repair requirement is orchestration failure, never PASS/SKIP.

## 2. Runtime gate

Execute all **430 selector identities**, in exact file order, as **430 fresh processes**. Route each row to its owning packaged binary and use an exact GTest filter. Every process must select exactly one test and skip zero tests.

Required complete ledger fields include identity, owner binary, process ordinal, selected count, skipped count, process result, exit code, and raw-log digest. Do not use generated discovery/listing as authority.

The complete gate has no repository-imposed elapsed-time cutoff. Do not split, retry, or stitch a partial ledger to evade runtime. An interrupted full gate is orchestration failure and receives no semantic credit.

## 3. Immutable postflight

After the final selector process, re-hash the frozen package, packaged source, execution view, selector and package manifest. Require exact pre/post equality. Record execution-boundary counters proving configure/compile/relink/generated-discovery/package-repair/mode-repair/source/test/fixture/selector mutation and benchmark execution are all zero.

## 4. Result rules

- Mechanically GREEN requires **430/430 PASS**, zero RED/SKIP/crash/selection mismatch/unexecuted, exact owner-pass census **31/283/75/41**, and complete immutable postflight.
- Any semantic RED is preserved exactly and routes to mandatory Review; do not patch, rebuild, rerun a corrected binary, or weaken the selector in TB3.
- Every observed regression must be classified in `Regression_Root_Cause_Tracker.md` before TB3 closes, including an explicit non-stable candidate entry when stable repricing is not justified.
- TB3 EXEC cannot promote package authority or close CP4/M4. It produces immutable evidence for Review only.

## 5. Successor

Every orchestration-valid semantic outcome routes to **`M4-CP4-TB3-REV`**. Only that runtime-free Review may independently re-derive selector/package/ledger/postflight authority, promote package `10591801825`, grant cumulative selector430 credit, and decide CP4/M4 closure against all amended exit conjuncts.
