# M6-CP1-TB10-A5V-R1-EXEC — Artifact-Only Test + Benchmark Plan

**Owner:** `M6-CP1-TB10-A5V-R1-EXEC`  
**Type:** immutable artifact-only Test + Benchmark.  
**Candidate:** artifact/source `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea`.  
**Result artifact digest:** `sha256:142bac1bb485ff1f2b8017a08c8457053659867716c7b44edcceb117dca75afd`.  
**Compile authority:** run/job `37192727051 / 111408174395`, manifest 28/28, GMP/GMPXX, `runtimeExecution=false`.

## Preflight

1. Download artifact `11299078582` exactly once.
2. Verify the outer artifact digest and the packaged `SHA256SUMS` **28/28**.
3. Verify packaged source commit equals `96b456f925be00e00bad6645e6eb905a804c14ea`.
4. Extract with an archive tool that preserves executable mode bits. Do not use Python `zipfile.extractall` for executable payloads and do not `chmod` or otherwise repair the immutable package.
5. Do not configure, compile, relink, regenerate discovery/code, patch packaged source, or alter fixtures/manifests.
6. Verify focused24, focused20, selector449 and routing449 hashes remain:
   - `6bcc8a544cbc0296df4cdb66dcb0c2dc7f86c88dfb340b795462c8c9544067bf`;
   - `15d04a2a09eeb678923b0bfcf70bf9c07b79e7ff343ec468316f6510b16827d2`;
   - `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
   - `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

## Runtime gate

Execute exactly:
- focused24: **24** fresh exact-filter processes in frozen file order;
- accepted selector449: **449** fresh exact-filter processes in frozen file order.

Total gate: **473** processes.

For every process require exactly one selected test and zero skips. Zero-selected filters are orchestration failure. Do not run benchmarks; benchmark count must remain zero. Do not partition or repair the immutable package.

## Postflight and reporting

- Re-hash package/source/execution-view and fixture authorities after runtime.
- Record focused, selector, aggregate pass/fail counts, exact-one selection, skip count, benchmark count, and immutable postflight.
- Categorize every observed regression in `.agents/Directional/Regression_Root_Cause_Tracker.md` before closeout; use a candidate/non-stable entry when stable-history criteria are not met.
- No promotion occurs in EXEC.
- If mechanically valid, exact successor is mandatory runtime-free `M6-CP1-TB10-A5V-R1-REV`.
- CB11 remains held until Review adjudicates this candidate.
