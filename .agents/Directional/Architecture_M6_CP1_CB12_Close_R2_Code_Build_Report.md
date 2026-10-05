# `M6-CP1-CB12-CLOSE-R2` — Code + Build report

## Disposition

**COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE.** This turn implements only the RA-27a-authorized wedge correction, C4 diagnostic-name correction, and identity29 recovery. No generated Directional runtime, test discovery, test, benchmark, CLI, fuzzer, or custom input executed.

## Semantic source

- Exact semantic source: `3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`.
- Patch apply run/job: `37277892065 / 111658980414`.
- Verified patch SHA-256: `694f89a68c4a0610d9061764d920db09554748d32d6b32c551a61d9de4133840`.
- Diff-body SHA-256: `b95ff29818d60bfe86dcf2a6947e937d2d10f63620b8614d1254657906b490e4`.
- Delta: exactly two paths, `+48 / -54`:
  - `src/pipeline/RemeshPipeline.cpp`
  - `tests/SurfaceCellTransitionQuotientTests.cpp`
- Workflow-side Drive retirement was unavailable; owner-authorized permanent deletion of staged file `1Zyk_jYMdU3Q1_0meqw_IKT6XH9o78c_a` succeeded after the push.

## RA-27a implementation

1. A7's per-occurrence multi-sheet wedge check now builds an exact undirected sheet graph from that occurrence's region-matching `cornerWedgeIsolation` records and requires all `cornerWedgeSheets` to be connected. Rejection remains `UncertifiedCrossSheetBinding`, with site `cross-sheet:wedge`.
2. The existing selected-forest cross-sheet edge rule is unchanged.
3. C4's fail-closed diagnostic string is `QuotientClosedComplexStripContinuationMismatch`.
4. Focused identity29 keeps its name and order. It proves baseline A5→A6→A7 acceptance, tampers only one bridge occurrence's wedge transitions, republishes A5, re-produces A6 and requires A6 success, then requires A7 `UncertifiedCrossSheetBinding` at `cross-sheet:wedge`. No stale A6 product is reused.

Frozen bytes remain unchanged:

- focused30 SHA-256 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`;
- selector449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- routing449 receipt SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

## Compile/package evidence

Authoritative reusable compile run/job: `37278068286 / 111659540374`.

- Standard eight targets compiled and linked successfully.
- Preflight target `directional_core`: exit `0`.
- Full compile: exit `0`; propagated compile status `0`.
- Mandatory GMP backend found; authoritative test link command includes both `libgmpxx.so` and `libgmp.so`.
- Exact compiled source: `3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`.
- Result artifact: `11330703256`, SHA-256 `0c50b034e80595514f4891d964360151339a31fe5d870aa83eade85587721524`.
- Log artifact: `11330837905`, SHA-256 `200a29e15ed7eef71fb3311dfaa8fd90a91aa4328daf15b2f6d5a21ec5fdcbb9`.
- Package contains 29 regular files including `SHA256SUMS`; self-excluding manifest is **28/28 PASS**.
- Packaged source archive SHA-256: `80d5a02e2394f00051e6c537715df9efbe8d0aaf8acc69bb68ca11bb8026deca`.
- Five packaged source-status receipts are empty.
- Command boundary records `runtimeExecution=false`, `exactArithmeticBackend=GMP`, `semanticContracts=compiled-not-executed`, and out-of-tree build authority.

## Acceptance boundary

This is compile/package evidence only. It does not promote the candidate or claim runtime recovery. Reviewed runtime authority remains `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0`; the previous TB12 candidate remains unpromoted. Stable accounting remains **60 / 16 / 44**, debt **1**.

Exact successor: immutable artifact-only **`M6-CP1-TB12-CLOSE-R1-EXEC`**, consuming `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05` as **30 + 449 = 479** fresh exact-filter processes, followed by mandatory `M6-CP1-TB12-CLOSE-R1-REV`. `M6-CP1-CLOSE-REV` remains held until that Review.
