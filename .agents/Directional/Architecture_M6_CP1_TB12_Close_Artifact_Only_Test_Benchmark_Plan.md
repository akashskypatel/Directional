# `M6-CP1-TB12-CLOSE-EXEC` — Artifact-Only Test + Benchmark Plan

**Owner:** `M6-CP1-TB12-CLOSE-EXEC`
**Type:** immutable artifact-only Test + Benchmark.
**Candidate:** artifact/source `11324028392 / 02149f1518fc6a753acf3235f7dcdc6fcdf59f24`.
**Candidate outer ZIP SHA-256:** `4e6b208acd328036d849a8d71f12804a6d9e6a34d804e3129953ce7a7e3afba1`.
**Compile authority:** run/job `37259524323 / 111603703243`, package manifest 28/28, GMP/GMPXX, `runtimeExecution=false`.

## Preflight

1. Download artifact `11324028392` exactly once.
2. Extract with ordinary `unzip`/`tar` so archived executable mode bits are preserved. **Do not use Python `zipfile.extractall` for the executable package and do not `chmod` or otherwise repair immutable bytes.**
3. Verify outer digest, packaged `SHA256SUMS` **28/28**, package-manifest SHA-256 `1527cabe67a4d09c8cabd8b117ba0c50d46750554bad6aa247afd2b8675a3e06`, packaged source `02149f1518fc6a753acf3235f7dcdc6fcdf59f24`, and source-archive SHA-256 `0cd4dc2eaa2778bdc906e06cf854d7b84f5082877fd45e5c99c5c830722e6a5a`.
4. Do not configure, compile, relink, regenerate discovery/code, patch packaged source, or alter fixtures/manifests.
5. Verify frozen authorities:
   - focused30: `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`;
   - focused28: `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d` and exact prefix of focused30;
   - selector449: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
   - routing449: `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

## Runtime gate

Execute exactly:
- focused30: **30** fresh exact-filter processes in frozen file order;
- selector449: **449** fresh exact-filter processes in frozen routing order.

Total: **479** processes. Every process must select exactly one test and report zero skips. Zero-selected filters are orchestration failure. Benchmark count remains zero. No retry, repair, rebuild, or mutation after runtime starts.

The appended identities are:
29. `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition`
30. `M6CP1.A5PhaseFrontSourceFailuresKeepDistinctDiagnostics`

## Postflight and reporting

- Re-hash the immutable package, packaged source, execution view, focused/selector/routing authorities, and manifest after runtime.
- Record focused/selector/aggregate PASS/RED counts, exact-one selection, skips, benchmark count, and immutable postflight.
- Categorize every observed regression in `Regression_Root_Cause_Tracker.md`; use candidate/non-stable disposition unless stable-history criteria are met.
- EXEC grants no promotion or CP1 closure.
- Every mechanically valid outcome advances to mandatory runtime-free `M6-CP1-TB12-CLOSE-REV`; only that Review may adjudicate promotion and then route to `M6-CP1-CLOSE-REV`.
