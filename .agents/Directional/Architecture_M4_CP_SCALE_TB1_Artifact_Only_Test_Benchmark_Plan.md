# M4-CP-SCALE-TB1-EXEC — Artifact-Only S1 Trace-Scale Census Test + Benchmark Plan

**Turn:** `M4-CP-SCALE-TB1-EXEC`
**Type:** Test + Benchmark execution only
**Predecessor:** `M4-CP-SCALE-CB1`
**Mandatory successor:** `M4-CP-SCALE-TB1-REV`

## 1. Immutable input authority

Consume only the CB1 compile result artifact:

- artifact: `10360085644` (`m4-cp-scale-cb1-result-34872546633`);
- provider/result-ZIP SHA-256: `996189b38c26f906bdd86354451571475900d98d0811f50e50a9439f26ff6ec7`;
- semantic source: `a359b981f9350139304bc5a654041dfba78609b6`;
- packaged source archive SHA-256: `b261f468cde2e54974f19931ca5101e2c6d07e273ca555c0526d9e7ce112e3d4`;
- package `SHA256SUMS` SHA-256: `3ac6c9e388d06ed5572613480a587952736657be88cf8dfba393d356e47028b8`, **28 entries**, self-excluding;
- accepted selector under test: `.agents/Directional/Architecture_M4_CP_COND_CB5_Required_Green_Selector_423.txt`, **423 LF rows**, SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`.

Accepted current runtime authority remains package `10331193451` until Review; TB1-EXEC may not promote this candidate.

## 2. Hard execution boundary

Artifact-only means **no** configure, compile, relink, generated test discovery, source/test/fixture/selector mutation, package repair, dependency install that changes package contents, or benchmark rebuild. Do not run CMake or Ninja. Do not use `--gtest_list_tests`. Resolve selector ownership from the packaged source/static CMake authority and the already-frozen selector manifest.

Run only binaries already present in the immutable package execution view. Preserve package/source bytes and file modes before and after runtime.

## 3. Preflight

Before any Directional runtime:

1. verify the downloaded artifact digest and all 28 `SHA256SUMS` entries;
2. verify `metadata/source-commit.txt == a359b981f9350139304bc5a654041dfba78609b6`;
3. verify `metadata/command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and `manifestExcludesSelf=true`;
4. verify the packaged selector is exactly 423 LF rows and re-hashes to `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`;
5. verify static selector ownership remains **30 authority-kernel / 277 producer / 75 completion / 41 validation = 423**;
6. record a byte+mode census of package and extracted source execution view for postflight comparison.

Any mismatch is a hard STOP with zero semantic runtime credit.

## 4. S1 focused diagnostic execution

Execute exactly the authored diagnostic identity from the packaged producer-test binary:

```text
./bin/directional_surface_cell_producer_tests --gtest_filter=M4CPScaleS1.ExactTraceParameterScaleCensusIsDeterministicAndDecisionNeutral
```

Run it in a fresh process and capture stdout/stderr/exit status verbatim. It is **diagnostic/non-gating**, but the identity itself must execute exactly once and PASS mechanically for TB1 evidence to be usable.

The test must emit one `m4CpScaleS1` report for each retained family covered by the authored path:

- `two-ring`
- `torus`
- `mechanical feature`
- `prescribed sphere`

For each line, record `sampleCount`, numerator/denominator/magnitude maxima, baseline outcome, and reachability/deepest-stage evidence where present. Preserve exact reported integers. **Do not infer, propose, or apply a bit-width threshold.** Empty/partial census on an upstream typed production error is reportable evidence only if the authored identity proves the repeated error and repeated census are exactly deterministic.

The focused identity also owns the decision-neutrality and tamper-sensitive oracle checks; do not replace them with output-text-only assertions.

## 5. Accepted selector423 execution

Execute every one of the 423 frozen selector identities in a fresh exact-filter process against its statically owned packaged binary. Require exactly one selected identity per process. Semantic fail-fast must be disabled so the complete selector census is always attempted after preflight.

Expected gate for mechanical success:

- selector423: **423/423 PASS**;
- owner census: **30 / 277 / 75 / 41**;
- RED: `0`;
- SKIP: `0`;
- timeout/crash: `0`;
- selection mismatch: `0`.

The S1 focused diagnostic identity is **outside** selector423 and contributes **zero selector/gate credit** regardless of its measured values.

## 6. Postflight immutability

After all prescribed runtime:

1. recompute package and source execution-view byte+mode censuses;
2. require exact equality with preflight;
3. re-verify `SHA256SUMS` and selector423 hash/row count;
4. prove no configure/build/relink/repair/discovery/mutation occurred;
5. publish a non-self-referential checksum manifest for TB1 evidence.

## 7. Required evidence/report

The TB1 result artifact must contain, at minimum:

- immutable-input identity and preflight verification;
- focused S1 raw stdout/stderr and one-row process ledger;
- parsed four-family S1 measurement table with coverage/deepest-stage/baseline outcome;
- selector423 423-row process ledger and per-process raw logs;
- owner census and exact PASS/RED/SKIP/timeout/selection-mismatch totals;
- pre/post byte+mode censuses and equality proof;
- non-self-referential evidence `SHA256SUMS`;
- explicit booleans showing configure/build/relink/repair/discovery/mutation were not performed.

## 8. STOP and successor

STOP and preserve evidence if immutable preflight fails, the focused identity does not execute exactly once, selector ownership is ambiguous, selector423 is not 423/423, package/source postflight changes, or orchestration would require rebuilding/repairing the candidate.

Do not classify S1 numeric values as safe/unsafe and do not promote package authority in EXEC. Exact successor is mandatory runtime-free `M4-CP-SCALE-TB1-REV`, which alone may interpret the S1 measurements, classify any runtime evidence, and freeze the next bounded CP-SCALE slice.
