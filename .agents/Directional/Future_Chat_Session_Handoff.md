---
Turn: M4-CP-SCALE-TB4-EXEC
Status: COMPLETE / ORCHESTRATION INVALID / NO SEMANTIC LEDGER / CANDIDATE UNPROMOTED / CP-SCALE OPEN / M4 OPEN
Repository: akashskypatel/Directional
Working branch: agent/surface_cell_quad/p5-recover-bridge-healing
PR: 8, open / draft / unmerged
Canonical next turn: M4-CP-SCALE-CB5
---

# Future Chat Session Handoff — Directional

## Purpose — DURABLE, DO NOT DELETE

This file contains durable operating policy, the exact next action, current immutable authority, standing product state, and resume-critical blockers/lessons required to continue safely. Architecture belongs in `DESIGN.md` and frozen-definition records; tasks belong in `TODO.md`; completed history belongs in `CHANGELOG.md`; exact runtime evidence belongs in retained reports/review records and `Regression_Root_Cause_Tracker.md`.

All `[ChatGPT Web]` instructions remain mandatory for ChatGPT Web sessions. Other agents may ignore only instructions explicitly prefixed `[ChatGPT Web]`.

## Authoritative pre-turn documents — DURABLE, DO NOT DELETE

Read in full at every new formal turn:

- `.agents/Directional/Durable_Handoff_Policy.md`
- `.agents/Directional/Mandatory_Start_Checklist.md`
- `.agents/Directional/Mandatory_End_Checklist.md`
- `.agents/Directional/Patch_Application_Strategy.md`
- `.agents/Directional/Turn_Cadence.md`

## Current accepted runtime authority

`M4-CP-SCALE-TB1-REV` remains accepted runtime authority:

- package `10360085644`;
- semantic source `a359b981f9350139304bc5a654041dfba78609b6`;
- selector423 **423/423**, SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`;
- first422 SHA-256 `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`;
- owner census **30 authority-kernel / 277 producer / 75 completion / 41 validation**;
- stable accounting **49 events / 14 categories / 35 recurrences**; produced-witness debt **5**.

S1 remains deterministic decision-neutral diagnostic authority only. No S1 numeric threshold is frozen; observed 429 bits are not a safety envelope and the 4096-bit continuation guard remains operational fail-closed authority only.

## TB4-EXEC disposition — orchestration invalid; retry required before Review

`M4-CP-SCALE-TB4-EXEC` is **COMPLETE / ORCHESTRATION INVALID / NO SEMANTIC LEDGER** on immutable CB4 candidate artifact `10378808176` / semantic source `905dabe390577d63ed6a9289e3f3d53aa4144936`. Run/job `34938070127 / 104280301940` passed exact package/source/selector preflight and observed focused S2 **1/1 PASS**. It then executed all 423 selector rows, observing 383 PASS / 40 RED / 0 SKIP / 0 timeout / 0 selection mismatch. Every one of the 40 RED logs carries the same runner-only missing-test-data exception because the payload copied packaged `benchmarks/fixtures` one directory too shallow: `view/test-data/benchmarks/<...>` instead of the required `view/test-data/benchmarks/fixtures/<...>`.

The attempt is independently invalid a second way: preflight wrote `execution-view-before.tsv`, while mandatory `postflight()` required `execution-view-census-before.tsv`, producing `FileNotFoundError`, mechanical exit `97`, and `postflightPass=false`. Captured package/source/execution-view before/after censuses are byte-identical and package checksum verification passed again after runtime, so no immutable input drift is observed; nevertheless the frozen postflight contract was not satisfied.

Result artifact `10384800591` has provider SHA-256 `3c6b5cc9ae54f8ebc0bfed9d4097003dbd0250f8cfc3053a89ad3ef95ca27065`; diagnostic log artifact `10384696446` has provider SHA-256 `79abfc66e2d7883444a60fcccc81b904e11ca378b93f2bd94abebdd8e76d810b`; nested evidence ZIP SHA-256 is `ee5948335006b10e4f00d295e181489a6b9352634df26952f4c52dacf7c8e0ca`. No configure, compile, relink, repair, generated discovery, benchmark or mutation occurred.

Per durable `Turn_Cadence.md` rule 5, an orchestration failure receives no semantic ledger. The observed S2 PASS is not promoted; the 40 selector RED observations are not product regressions; candidate `10378808176` remains unpromoted; accepted runtime authority and stable accounting remain unchanged.

## Exact next — `M4-CP-SCALE-CB5`

Execute `.agents/Directional/Architecture_M4_CP_SCALE_CB5_Orchestration_Correction_Plan.md` as a **runtime-free control-plane correction only**. Reuse exact immutable artifact `10378808176`; change no product source, test source, fixture bytes, CMake/build semantics, selector bytes, package bytes, or reusable workflow permissions.

CB5 must correct only: (1) execution-view fixture materialization to `view/test-data/benchmarks/fixtures`, sourced byte-for-byte from the packaged source archive; and (2) the execution-view census receipt names so preflight and postflight consume the same filenames. Verify these statically without executing Directional binaries.

If and only if CB5 is statically GREEN, exact next becomes fresh `M4-CP-SCALE-TB4-R1-EXEC` against the same package, restarting the full gate from process 1. Only after a mechanically valid retry does `M4-CP-SCALE-TB4-REV` become the mandatory semantic adjudication turn.

## Carried obligations

- `M4-CP-SCALE-TB1-REV-OBS-01`: S1 representative/stress calibration before any future numeric gate.
- `M4-CP-SCALE-TB2-REV-OBS-01`: **DISCHARGED by TB3 Review**; 423/423 rows were preserved UNEXECUTED with exact immutable postflight.
- `M4-CP-SCALE-TB2-REV-OBS-02`: audit the remaining `make_zero_transport_field` callers in a later dedicated turn; not CB3/TB3 scope.
- `M4-CP-SCALE-DEFN-OBS-01`: arrival-order exact fallback not frozen; not owned by vertex-star S2.
- `M4-CP-SCALE-DEFN-OBS-02`: dedicated full exact-state repeat S3 witness + typed outcome owed.
- `M4-CP-SCALE-DEFN-OBS-03`: S4 independent incremental earlier-never-different oracle/reachability owed.
- `M4-CP-SCALE-DEFN-OBS-04`: genus>=2 construction/reachability owed.
- `M4-CP3-TB1-R1-REV-OBS-01`: same-region multiplicity-2 independent oracle before cumulative M4-CP4.
- `M4-CP3-CB4-REV-OBS-02`: row399 path/`sourceFaces` divergence tamper at next legitimate row399 touch.
- row408 provenance warning remains historical-bound.
- `G4-B002`: 3 produced-witness debts, M4-CP4. `G4-B003`: 2 debts, M5.

## Context Load Plan

```yaml
load_next:
  - .agents/Directional/Architecture_M4_CP_SCALE_CB5_Orchestration_Correction_Plan.md
  - .agents/Directional/Architecture_M4_CP_SCALE_TB4_Artifact_Only_Test_Benchmark_Report.md
project_plan:
  - .agents/Directional/Architecture_M4_CP_SCALE_Frozen_Definitions.md
  - .agents/Directional/M4_Consolidated_Record.md
conditional_modules:
  - trigger: GitHub connector/workflow/artifact work
    path: .agents/Directional/GitHub_Workflow_Policy.md
deep_references:
  - .agents/Directional/Architecture_M4_CP_SCALE_TB1_Artifact_Only_Test_Benchmark_Report.md
  - .agents/Directional/Required_Green_Selector_Manifest.md
  - TODO.md
do_not_preload:
  - consumed TB4-EXEC plan and folded TB2/TB3 execution material
  - unrelated historical milestone reports
```
