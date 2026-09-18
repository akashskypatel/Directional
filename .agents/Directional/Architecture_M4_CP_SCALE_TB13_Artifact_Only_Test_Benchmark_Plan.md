# M4-CP-SCALE-TB13 — selector427 artifact-only Test + Benchmark plan

**Turn:** `M4-CP-SCALE-TB13-EXEC`  
**Type:** immutable artifact-only Test + Benchmark  
**Input artifact:** `10565723112` / `m4-cp-scale-cb24-result-35391181281`  
**Exact compiled source:** `6fe075f7d9397a561fe50b79517b4f714fb9eeef`  
**Required successor after any valid semantic result:** `M4-CP-SCALE-TB13-REV`

## Goal

Freshly execute the newly published cumulative required-green selector427. This turn determines runtime evidence only; it may not rebuild, repair, edit, regenerate, or promote anything.

## Immutable preflight

Before any generated Directional process:

1. Download artifact `10565723112` exactly once and require provider ZIP SHA-256 `96e9e900e67777f31fbbf97d05efc44ed8c944d9f2bc031a5826e47602ea7bfa`.
2. Extract with an archive tool that preserves archived executable mode bits. Ordinary `unzip`/`tar` is allowed. Python `zipfile.extractall` is forbidden for executable payloads unless archived modes are explicitly restored and verified. **Do not `chmod` or otherwise repair the package.**
3. Verify the package self-excluding `SHA256SUMS` manifest **28/28** before runtime.
4. Require `metadata/source-commit.txt` to equal `6fe075f7d9397a561fe50b79517b4f714fb9eeef` and packaged source archive SHA-256 `3b6b587efadf3b83082b11e5f7a9e1c06b5c8f1ce0671d82db707ffc7fac3bfd`.
5. Require all packaged executable modes to be `0755`, all packaged source-status receipts empty, `runtimeExecution=false`, `exactArithmeticBackend=GMP`, and the authoritative link evidence to include both GMPXX and GMP.
6. From the immutable packaged source require:
   - selector427 exactly **427 LF rows**;
   - full LF SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
   - first426 LF SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`;
   - first425 LF SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
   - row427 exactly `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology`;
   - static ownership **30 authority-kernel / 281 producer / 75 completion / 41 validation**.
7. Freeze a complete byte/mode census of the immutable package/execution view before the first generated process.

Any preflight mismatch is **orchestration/integrity failure**, not semantic RED and not permission to repair the package.

## Runtime gate

Execute every selector427 row exactly once, in **exact file order**, one fresh process per identity, using its owning packaged test binary.

For every row:

- use the exact GTest filter for that single identity;
- set `GTEST_FAIL_IF_NO_TEST_SELECTED=1` (or the equivalent packaged exact-selection contract);
- require exactly one selected identity and classify PASS/RED/SKIP/timeout/crash/selection mismatch explicitly;
- record ordinal, owner binary, process exit code, elapsed time, and raw stdout/stderr evidence;
- do not use discovery/listing generated from the packaged binaries to construct the selector;
- do not combine identities into one process.

The full current gate is **427 rows**. Do not stop merely because an earlier row is semantic RED; execute the complete selector so the turn has one complete cumulative ledger. A zero-selected filter or selection mismatch is orchestration failure, never PASS/RED.

Expected green condition: **427/427 PASS** with zero RED, SKIP, timeout, crash, or selection mismatch.

## Benchmark contract

**Execute zero benchmarks.** `directional_benchmarks` is packaged compile evidence only for this publication checkpoint.

## Immutable postflight

After the final selector process, repeat the complete byte/mode census and package hash verification. Require exact equality with preflight. Record benchmark/build/configure/relink/discovery/repair/source/test/fixture/selector mutation counts as zero.

No configure, compile, relink, generated discovery, source/test/fixture/selector edit, package repair, permission repair, or benchmark execution is authorized.

## Evidence package

Retain at minimum:

- artifact/provider/source/package identities and all immutable preflight receipts;
- the complete ordered 427-row process ledger;
- per-row raw stdout/stderr and exact selection counts;
- owner census and selector/prefix hashes;
- pre/post byte+mode censuses and equality receipt;
- aggregate PASS/RED/SKIP/timeout/crash/selection-mismatch counts;
- zero benchmark/build/configure/relink/discovery/repair/mutation receipts;
- persistent execution log and a self-excluding evidence manifest.

## Disposition

A mechanically all-green TB13 still **does not itself promote selector427 or grant cumulative S5 credit**. Every valid semantic result routes to mandatory runtime-free `M4-CP-SCALE-TB13-REV`, which must independently re-open the immutable evidence, re-derive selector/prefix/owner authority, adjudicate any regression evidence, and decide promotion.

Orchestration/integrity failure routes only to the smallest orchestration-correction CB required by cadence; it must not be converted into product evidence.
