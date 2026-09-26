# M6-CP1-TB4 Artifact-Only Test + Benchmark Report

**Turn:** `M6-CP1-TB4-EXEC`
**Disposition:** COMPLETE / MECHANICALLY VALID / SEMANTIC NON-GREEN / REVIEW REQUIRED / CANDIDATE UNPROMOTED
**Candidate:** artifact/source `10871935178 / 20f60bb1412424a6f1093fc8076884d1ea23f1c5`
**Authoritative runtime:** run/job `36157505252 / 108145613689`
**Result/log:** `10874311495 / 10873574681`
**Exact successor:** `M6-CP1-TB4-REV`

## 1. Immutable preflight

TB4 consumed the CB4 package immutably. The provider and downloaded candidate ZIP both verify SHA-256 `dc6e979ac62b4599c2c8b15528524513f3bc5b45eb9068ed508fd3d08ccf7998`; root `SHA256SUMS` verifies **28/28** before and after runtime. The packaged source archive verifies SHA-256 `db894f3e27d880b4d27a593816df6e521dff01583e320ec198b4fd8401e50065` and exact semantic source `20f60bb1412424a6f1093fc8076884d1ea23f1c5`. All packaged source-status receipts are empty, GMP/GMPXX evidence is present, and the package records `runtimeExecution=false` for its Code + Build origin.

Selector449 is exactly **449 LF rows** at SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 is SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707` with owner census **32 / 301 / 75 / 41**. All seven focused identities resolve to the packaged producer-test executable. Extraction preserved archived executable modes; no `chmod`, permission repair, configure, compile, relink, generated discovery, source/test/fixture/selector mutation, package repair, benchmark execution, retry-after-runtime-start, or acceptance-gate watchdog occurred.

## 2. Mechanical execution

The frozen gate executed exactly **456 fresh exact-filter processes** in the required order: seven focused identities followed by all 449 selector identities. Every process selected exactly one test and skipped zero. There were **0 selection mismatches, 0 skips, 0 benchmark processes**, and no elapsed-time watchdog.

| phase | total | PASS | RED |
|---|---:|---:|---:|
| focused | 7 | 6 | 1 |
| selector449 | 449 | 425 | 24 |
| **total** | **456** | **431** | **25** |

The sole focused RED is row 6, `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`, at `MissingIsolationSeamEquivalenceAuthority`. The new seventh focused identity, `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`, **PASSes**. Focused row 5 `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets`, which was RED in TB3, also **PASSes**.

Selector449 RED ordinals are exactly **115, 116, 122, 130, 132, 134, 137, 141, 143, 150, 176, 201, 217, 218, 231, 232, 238, 246, 436, 437, 438, 444, 446, 448**.

## 3. Differential against TB3 and accepted M5 authority

Accepted M5 runtime authority remains selector449 **449/449 PASS**, so all 24 TB4 selector REDs are accepted-prefix PASS -> RED observations. Relative to TB3:

- **Recovered:** focused row 5 and selector ordinals **186, 214, 239** now PASS.
- **Carried RED:** focused row 6 and selector ordinals **444, 446, 448** remain RED at `MissingIsolationSeamEquivalenceAuthority`.
- **New accepted-selector RED:** **21** ordinals — 115, 116, 122, 130, 132, 134, 137, 141, 143, 150, 176, 201, 217, 218, 231, 232, 238, 246, 436, 437, 438.

The observed failure surfaces split mechanically into three groups without EXEC assigning root-cause ownership:

1. `MissingIsolationSeamEquivalenceAuthority` or a tracing `NotProductionReady` carrying that cause: focused row 6 and selector 115, 116, 141, 143, 150, 217, 218, 231, 232, 246, 436, 437, 438, 444, 446, 448.
2. Feature/hard-rail fixture non-vacuity no longer reaches the expected authority seam: selector 122, 130, 132, 134, 137.
3. Earlier tracing termination changes downstream stage expectations: selector 176, 201, 238 (`NotProductionReady`, with 201 explicitly reporting stage `tracing` instead of expected `arrangement`).

TB4 EXEC records **`M6-CP1-TB4-EXEC-CAND-01`** as one non-stable Review-owned regression candidate envelope for the **21 newly RED accepted-selector identities**. EXEC does not decide whether those identities are one event, several events, a shared CB4 producer defect, test/fixture authority drift, or a definition conflict. The carried TB3 REDs remain tied to the already-stable TB3 `RP-01` event until Review adjudicates recovery/continuation.

Stable accounting therefore remains **54 events / 16 categories / 38 recurrences** in EXEC; produced-witness debt remains **1**, M6-owned. Candidate `10871935178` remains unpromoted and receives no CP1 closure, G4/debt credit, or accepted-runtime authority.

## 4. Evidence integrity

Result artifact `10874311495` has provider/download SHA-256 `32dca965d68d060c32e1e8f79ac146cf6381eb6cf5762c0854c5d792ae693e24`. Its self-excluding `SHA256SUMS` verifies **932/932** evidence files and hashes to `cbc2f4e484dab789c2d3a467dc1602e891881c643bf819273dbb0d781f074ffc`. Focused-ledger SHA-256 is `e5adb0efa303ea8361e4fd60b3356fd9c5906572af504dafc55e601da12fa754`; selector-ledger SHA-256 is `3f07cbc98170f24d8ecbf978faa793f5b50ed7ae2edc2631e06ec7cd499726e2`.

Diagnostic log artifact `10873574681` has provider/download SHA-256 `9d50f4e6adb6e17a20bc13071107b41ea8113b55854a7b8dd1f2cafe8d9b4757`.

Postflight proves package/source/execution-view byte-and-mode censuses unchanged, candidate ZIP/source archive/selector/routing unchanged, and root package manifest still **28/28**. `execution-boundary.txt` records `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`, `selection_integrity=true`, all **456** processes executed, and every prohibited build/mutation/benchmark flag false.

## 5. Stop rule and disposition

TB4 stops after this one mechanically valid 456-process result. No semantic result is rerun. No source, test, fixture, selector, routing, package, build, or benchmark logic is changed. No candidate is promoted and EXEC authorizes no corrective implementation.

Exact successor is mandatory runtime-free **`M6-CP1-TB4-REV`**. Review must independently reopen candidate/package/result/log evidence, compare all 24 selector losses against accepted M5 authority, adjudicate `M6-CP1-TB4-EXEC-CAND-01`, determine the formal recovery status of the TB1/TB3 candidates, and update stable accounting only if independently justified.
