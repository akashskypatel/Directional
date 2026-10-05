# `M6-CP1-TB12-CLOSE-R1-EXEC` — Artifact-Only Test + Benchmark Plan

**Owner:** `M6-CP1-TB12-CLOSE-R1-EXEC`  
**Type:** immutable artifact-only Test + Benchmark.  
**Candidate:** artifact/source `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`.  
**Candidate outer ZIP SHA-256:** `0c50b034e80595514f4891d964360151339a31fe5d870aa83eade85587721524`.  
**Compile authority:** run/job `37278068286 / 111659540374`, package manifest 28/28, GMP/GMPXX, `runtimeExecution=false`.

## Preflight

1. Download artifact `11330703256` exactly once.
2. Extract with ordinary `unzip`/`tar` so archived executable mode bits are preserved. **Do not use Python `zipfile.extractall` for the executable package and do not `chmod` or otherwise repair immutable bytes.**
3. Verify outer digest, packaged `SHA256SUMS` **28/28**, package-manifest SHA-256 `cb17574a31fe6afcbf56325022f452fd649fad4b58d0996727cada9fe92b199b`, packaged source `3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`, and source-archive SHA-256 `80d5a02e2394f00051e6c537715df9efbe8d0aaf8acc69bb68ca11bb8026deca`.
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

Total: **479** processes. Every process must select exactly one test and report zero skips. Zero-selected filters are orchestration failure. Benchmark count remains zero. No retry, repair, rebuild, or mutation after runtime starts. The complete gate runs uninterrupted to its organic process results; no repository timeout/watchdog may terminate it.

Recovery-sensitive identities remain:
29. `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition`
30. `M6CP1.A5PhaseFrontSourceFailuresKeepDistinctDiagnostics`

## Postflight and reporting

- Re-hash the immutable package, execution view, focused/selector/routing authorities, and manifest after runtime.
- Record focused/selector/aggregate PASS/RED counts, exact-one selection, skips, benchmark count, and immutable postflight.
- Categorize every observed regression in `Regression_Root_Cause_Tracker.md`; if no regression is observed, record that the R1 execution created no candidate/event and stable accounting remains unchanged.
- EXEC grants no promotion or CP1 closure.
- Every mechanically valid outcome advances to mandatory runtime-free `M6-CP1-TB12-CLOSE-R1-REV`; only that Review may adjudicate promotion and then route to `M6-CP1-CLOSE-REV`.
