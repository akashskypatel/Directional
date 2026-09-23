# Directional Future Chat Session Handoff

## Current authority

`M5-CP3-TB1-R15-EXEC` is **COMPLETE EXECUTION / ORCHESTRATION INVALID / NO COMPLETE SEMANTIC LEDGER** once terminal `STATUS` is published.

CB17 candidate `10742798135 / 1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3` remains unpromoted. Accepted runtime authority remains package `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316`; R14 remains the latest mechanically valid CP3 runtime at **446/448 PASS** with selector430 **430/430** and complete **916/916** evidence. Stable accounting remains **51 / 14 / 37**, produced-witness debt **3**.

R15 had two orchestration attempts. Attempt 0, run/job `35850838725 / 107147928250`, verified the candidate **28/28** manifest but stopped before generated runtime because the temporary harness had malformed Python escape materialization. Because `runtime_started=false`, a bounded harness-only retry was allowed. Attempt 1, `35851321165 / 107149476143`, completed immutable preflight and began the first prescribed process. Raw output proves `M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges` ran once and returned `[ OK ]` / exit 0, but the temporary exact-one parser contained doubled bracket escapes and therefore reported `selected=0`. It failed closed with `runtime_started=true`, `selection_integrity=false`, zero committed ledger rows, and no remaining 447 processes executed.

Per artifact-only policy, runtime start prohibits another retry in this EXEC turn. There is therefore no R15 448-process PASS/RED vector and no product/recovery/debt/selector credit. The raw first-process result is diagnostic provenance only.

## Exact next turn

**`M5-CP3-TB1-R15-REV`** is mandatory.

Review must independently re-open attempt-0 result/log artifacts `10745895043 / 10745825171` and attempt-1 result/log artifacts `10745985740 / 10745542559`, verify the execution boundaries and first raw process, classify the invalid gate, and decide the bounded successor. Any authorization for a fresh corrected `R15-R1` must be Review-owned and limited to orchestration correction; EXEC did not rerun after runtime start and did not promote CB17.

## Resume-critical evidence

- CB17 Code + Build record: `.agents/Directional/Architecture_M5_CP3_CB17_Relation_Frame_Gauge_Cutover_Code_Build_Record.md`
- exact next plan: `.agents/Directional/Architecture_M5_CP3_TB1_R15_Artifact_Only_Test_Benchmark_Plan.md`
- frozen definition record: `.agents/Directional/Architecture_M5_CP3_DEFN_R1_Same_Region_Nonzero_Z4_Gauge_Reconciliation_Definition_Record.md`
- frozen definitions: `.agents/Directional/Architecture_M5_Frozen_Definitions.md` §16.3
- latest execution report: `.agents/Directional/Architecture_M5_CP3_TB1_R15_Artifact_Only_Test_Benchmark_Report.md`
- latest mechanically valid runtime report: `.agents/Directional/Architecture_M5_CP3_TB1_R14_Artifact_Only_Test_Benchmark_Report.md`
- tracker: `.agents/Directional/Regression_Root_Cause_Tracker.md`
- consolidated history: `.agents/Directional/M5_Consolidated_Record.md`
- CB17 semantic source: `1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`
- CB17 candidate: `10742798135`
- CB17 compile run/job: `35845003340 / 107128980299`
- candidate/log ZIP SHA-256: `eb1e2be55150022cdba05acf6b38433eb16352e4b3b6a561742e62de26cfd866 / cc58680de72ec58dc3cc74d3a1971d881f6232be923f0eb8672dad711e69354c`
- root manifest: `a6c288ff4ef5afff8122f9dae0e330fe1cab4928b7bd5b5604b7d2fd5e32b951`, **28/28**
- source archive: `e6bed804841ecf590ccd1c372c906e19b927e5cf0d253d0d361993fa92ce68e0`
- selector430/first427: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6 / f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`

## Context Load Plan

```yaml
load_next:
  - .agents/Directional/Architecture_M5_CP3_TB1_R15_Artifact_Only_Test_Benchmark_Report.md
  - .agents/Directional/Architecture_M5_CP3_TB1_R15_Artifact_Only_Test_Benchmark_Plan.md
deep_references:
  - .agents/Directional/Architecture_M5_Frozen_Definitions.md
  - .agents/Directional/Architecture_M5_CP3_DEFN_R1_Same_Region_Nonzero_Z4_Gauge_Reconciliation_Definition_Record.md
  - .agents/Directional/Architecture_M5_CP3_TB1_R14_Artifact_Only_Test_Benchmark_Report.md
  - .agents/Directional/Regression_Root_Cause_Tracker.md
  - .agents/Directional/M5_Consolidated_Record.md
do_not_preload:
  - M6 occurrence work
  - selector publication before a complete green CP3 pre-publication Review
  - fixture/field/A3 retuning
  - any rebuild or source mutation inside R15 EXEC
```
