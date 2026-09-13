# M4-CP-COND-TB3-EXEC Test + Benchmark Execution Report

**Turn:** `M4-CP-COND-TB3-EXEC`
**Disposition:** COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED
**Execution boundary:** artifact-only; no build/configure/relink/repair/generated discovery/mutation
**Immutable artifact:** `10325879420`
**Artifact provider / downloaded ZIP SHA-256:** `d046b8cbdcfe22af5ca732139612e96673d597fef47b5e36d1a54b1542493b2b`
**Packaged semantic/test source:** `4d9206cd059d7bb0c10fe3c0a0c91f8af248e675`
**Exact successor:** `M4-CP-COND-TB3-REV`

## 1. Frozen authority and execution boundary

TB3-EXEC consumed CB3 artifact `10325879420` exactly. The root `SHA256SUMS` re-verified **27/27** and hashes to `d292ee76bd1234b073084ebdfc772e248dd6757ee477b484dded158463194c2d`; the packaged source archive hashes to `c5e8ea58d2564a6cf0f70691f14ee2329f3d92b855f0bd58c9e22811494c9c5c`. Selector408 is exactly 408 LF rows / `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`; first403 remains `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`. Static source-derived owner census is **30 authority-kernel / 262 producer / 75 completion / 41 validation**.

Runtime used the immutable packaged owner executables in a mode-preserving derived execution view inside the ChatGPT Web Linux container. This is runtime execution only; no local build occurred. The artifact command boundary remained `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `semanticContracts=compiled-not-executed` as CB3 package provenance, while TB3 separately executed the packaged binaries.

## 2. Prescribed 423-process result

- focused CP-COND gate: **14/14 PASS**;
- `InputConditionerCPCondCB1.NegativeIndexRawPreconditionIsIndependentAndPreserved`: **PASS** in its fresh exact-filter process;
- report-only boundary witness: **1/1 SKIP**, selected exactly once, exit 0;
- accepted selector408: **408/408 PASS** in selector order, each in one fresh exact-filter process;
- gating total: **422/422 PASS**;
- total processes: **423**;
- semantic RED: **0**;
- selection mismatch: **0**;
- crash/timeout in the authoritative attempt: **0**.

The boundary witness retained the exact named blocker text:

> `CP-COND proves boundary/correspondence only; A2a separatrix reachability remains unproved and non-selector.`

It remains report-only / non-selector. EXEC does not reclassify that obligation.

## 3. Mechanical evidence digests

| Evidence | SHA-256 |
|---|---|
| focused ledger | `c5adebb56f283edd98c50d39b97f0b9be1eded2b59d00f5313e47e83928f65e8` |
| report-only ledger | `201f9efa06b701dcd3a710f3565cd53ce81c52bdd402dd36769d4ca43c68c084` |
| selector408 ledger | `9d9b910c54c659f76c8ed492e3a0d22df63d65bbdacd0898b844919e10358495` |
| combined 423-process ledger | `bbe96d77a18844f9c050924f4964b8cb052f40f6f1ec75d980ae9c945ae3a034` |
| package byte+mode census | `e36b87bf39c17d2505166bfaa1650861b291643c203e5ec6b939fdb71bc9a2be` |
| packaged-source byte+mode census | `305e54773b26f99bce7b54a07710cf441cdd9c6287cea246ef56df225d63f0b8` |
| derived execution-view byte+mode census | `952f15529bc630758158954ec65a58d07805b13fb99433459aec2e0caa085d80` |
| TB3 runtime harness | `baf57e0cb743740d4870716e9109fcc91d69a3cd055c5139da057516dbb2176f` |
| post-runtime orchestration revalidation | `c77a52f03cfa18f188436224813c0cecf45c74b2843279897093ec1232ab195c` |
| revalidation script | `5cc1d74d53dee74c1a7fe0cfb70b18d3bad5a5f9c491a0b54920ba22dcd75c83` |

Preflight and postflight package/source/execution-view censuses are byte-identical. Postflight records `configure_execution=false`, `compile_execution=false`, `relink_execution=false`, `package_repair=false`, `mode_repair=false`, `generated_discovery=false`, `benchmark_execution=false`, and `source_test_fixture_selector_mutation=false`.

## 4. Orchestration history

Two local orchestration incidents occurred before the authoritative full attempt and receive **zero semantic credit**:

1. the first harness invocation stopped before any Directional binary because a shell-local variable was referenced in the same declaration under `set -u`; only the external harness was corrected;
2. the next invocation completed the focused/report-only surfaces and selector rows through ordinal 114 before the surrounding ChatGPT container tool call hit its external platform wall-clock limit. That partial execution was preserved as interrupted evidence but was not stitched or continued.

The complete authoritative attempt restarted the frozen **entire 423-process surface from process 1** with unchanged artifact/package/source/selector bytes and ran all 423 Directional processes plus immutable postflight to organic completion. After postflight, the external harness itself exited 90 because its final selection-integrity `awk` used `NR>1` across three input ledgers, thereby counting the second and third TSV headers as two false mismatches. This is a post-runtime evidence-checker defect, not a test selection failure: the generated summary already reports `selection_mismatches=[]`, every one of the 423 ledger rows has `selected=1`, and a separate non-runtime revalidation using `FNR>1` proves zero mismatches with the same byte-identical postflight. No semantic process was rerun for this correction.

No semantic identity from the interrupted attempt was credited to the final census.

## 5. EXEC boundary and mandatory Review

This report is deliberately mechanical. `M4-CP-COND-TB3-EXEC` does **not** adjudicate whether the corrected raw-byte-derived negative-index oracle discharges `M4-CP-COND-TB2-REV-CAND-01`; it does not promote artifact `10325879420`, alter stable-event accounting, or close CP-COND.

Accepted runtime authority therefore remains CP3 package `10307919492` / selector408 **408/408**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5** pending mandatory runtime-free `M4-CP-COND-TB3-REV`.
