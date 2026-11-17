# TB126 same-turn execution continuation (2026-11-17 UTC)

## Situation
The canonical active turn is `M6-CP3-TB126-P13-EDGE-TERMINAL-CORRECTION-FULL-GATE-EXEC`. It has not completed. Do not start its successor. The root STATUS entry was committed as `6dbcbc8be0b2fe355fdd2a2146a7adc2277f472a`; original Started at `2026-11-17T02:42:30Z`, which must be preserved. PR #8 is open, draft, and unmerged.

## Background
- RA-244 §5 freezes a 951-test full gate (1,032 total membership, 81 deferred) and three-case census. Do not edit the manifests, source, compiled package, fixtures, or selectors.
- Immutable CB144 source `7b0668d432ccb187c5a2d856494064f0bcb2fb95`, artifact `14293047782`, ZIP SHA-256 `638eaf00618283551bbec607c1f9484447d96d0bb5000f5ad5df7870d42af929`, all 28/28 package hashes valid, GMP/GMPXX compiled, runtimeExecution=false.
- Frozen executor source snapshot event `a4141a2d6ac2183e977cf43d9eb6e9e8b0b3c92f`: workflow run `44005047937`, artifact `14293942606`, outer ZIP SHA-256 `f88424eef94dc3914371d41dc3378f3ed6b925be6a584b42098d637b34e77296`; 5,576 source file hashes verified. Snapshot trigger removed at commit `ab8b087478d0b0c510ad2416612b6dbb4c9bbc82`.
- Exact harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`; both manifest self-checks passed without running binaries.

## Gate execution evidence (02:56 UTC; primary mismatch)

The gate run `44005423680` reached the test step and emitted result artifact **`14294372593`**, outer ZIP SHA-256 **`c13a0f5e29ab961a6c6d7a31c2883cfaafbdc577d5727f291eb127e9cc8ea55e`**. All **1,910/1,910** internal SHA256SUMS verified. Its `execution-boundary.json` records **951 planned, 951 executed, 950 passed, 1 RED, 0 skipped, 1,032 membership, postflight=true, no compile/relink/configure/benchmark, exit=90**. All **950 inherited substantive ledger rows** match TB125. The new **row 951** `MandatoryEdgeTerminalSplit.SplitsAtOrderedDistinctCutsAndRejectsAmbiguousOnes` is RED. Raw `951.log` shows `C++ exception with description "std::get: wrong index for variant" thrown in the test body`.

**Source-derived candidate root cause, not a validated test correction:** `tests/FieldAlignedCurveNetworkTests.cpp` defines `constexpr std::size_t idCount = 16U` and builds `trace(index)` using `TraceId::from_index(index,idCount).value()`. The third test scenario calls `cut(38,13,...)`, and a later expected `trace(38)`; index 38 is outside the 16-element range, and `.value()` can throw before the N=2 split is tested. This invalid test input is consistent with the immediate exception; a separate Review must confirm the first throw site and authorize any corrected test source. Do not weaken the assertion or label this test green. **TB126 is already a full-gate MISMATCH** regardless of its pending census.

## Assessment
- **Full gate dispatched**, no duplicate: request event `d18120e83be9ba573e777a2cab1761656d7772b3`, mailbox key `m6-cp3-tb126-gate-v1`, Actions run `44005423680`. As of 02:53 UTC, it remained IN PROGRESS with validated dispatcher and test harness; immutable test step active. Gate manifest SHA-256 `44d5a734a819a6d353bf3cb83254af86939e017dbd3a6dc3313d71f814ffdd1f`.
- **Census dispatched**, no duplicate: event `82389b7425565a9513a6e9adadb82f95854dd059`, mailbox key `m6-cp3-tb126-census-v1`, Actions run `44005461405`. As of 02:53 UTC, PENDING behind gate. Census manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.
- Baseline TB125 gate artifact `14289730737`, ZIP SHA-256 `c1754245b4ecbde49ba9bbaf9103cbb7975fdb34d40cae57b4e25b7ac56061c8` (1,908/1,908 hashes), 950/950 PASS. Baseline census `14289927334`, ZIP SHA-256 `2f5a4b511d1fac710338acba368b3a892f05e5621eb5e0c89dcbb5143e3ff8d6` (9/9 hashes), Cylinder PASS, BunnyRandom/Vase RED.
- The TB126 verdict is **not established**. Do not treat a queued run, a live job, or a pre-compile success as an execution result. No production or selector promotion has been made. The legacy handoff's CB144-to-TB126 text is previous-turn history; this continuation record tracks the now-started TB126.

## Recommendation — continue TB126 only
1. Read mailbox `.workflow-mailbox/m6-cp3-tb126-gate-v1/latest.json` and `.workflow-mailbox/m6-cp3-tb126-census-v1/latest.json` on orphan ref `workflow-mailbox`. If unpublished, observe exact known run IDs rather than redispatch.
2. On terminal results, verify event SHA, immutable package/source, job and result-artifact IDs and ZIP SHA256, every internal SHA256SUMS, full ledger, postflight, no compile/relink/configure/benchmark, and immutable-package 28/28 integrity.
3. Gate requires 951/951 PASS, 0 skips, 1,032 membership; inherited rows 1–950 substantively equal TB125; no mandatory-edge inventory line; only elapsed time and known M3_CP4AB_FRAGMENT_DIAG concurrency may vary. Census requires unchanged Cylinder/Vase and BunnyRandom pre-cut/inventory receipts; BunnyRandom terminal may be RED but must advance past the three frozen edge-terminal error kinds on edges (241,251) and (251,278). Record its actual new terminal.
4. Publish TB126 execution report, regression tracker classification, live handoff, TODO and root CHANGELOG in a verified bounded patch through standard Google Drive staging. If transfer fails, preserve exact user-downloadable patch and leave the same turn IN_PROGRESS; do not classify mere Drive failure as BLOCKED.
5. **Only after verification:** MATCH routes to Review-only `M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME`; mismatch routes to `M6-CP3-TB126-P13-EDGE-TERMINAL-CORRECTION-FULL-GATE-REV`; infrastructure failure routes to `M6-CP3-TB126A-P13-EDGE-TERMINAL-CORRECTION-FULL-GATE-ORCH`. Do not execute any of these successors in this turn.
6. Carry O42/O43/C3 open, O44/C1 closed, stable 66/17/49, debt1, deferred81, accepted CP2 491/491, unpromoted CP3/selector497, chainRimSchedules=false.
7. On same-turn resumption preserve original Started at and set Resumed at; final GitHub action must update root STATUS. Response ends with exact STATUS footer.

**Turn-local process note:** a source-read ordering miss occurred before selecting snapshot mode; subsequently all source work used the exact verified snapshot. No Directional binaries were run locally. Tool-call ledger from this session is incomplete; do not infer a total.
