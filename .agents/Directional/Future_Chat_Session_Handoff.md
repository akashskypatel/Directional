# Directional Future Chat Session Handoff

## Current authority

`M5-CP3-TB1-R11-EXEC` is **ORCHESTRATION INVALID / NO SEMANTIC LEDGER / ZERO SEMANTIC CREDIT** once terminal `STATUS` is published.

R11 consumed unchanged CB12 candidate `10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188` in run/job
`35771152416 / 106892972571`. All **446/446** planned fresh exact-filter processes ran and immutable runtime postflight is
exact, but those rows are invalid-attempt provenance only. Final result-manifest generation staged `SHA256SUMS.new` inside the
enumerated result tree, leaving **913 manifest rows for 912 actual non-manifest evidence files** after `mv`. All 912 real
evidence files verify; only stale `./SHA256SUMS.new` fails. The workflow correctly failed closed with
`result_finalization_exit=1 / driver_exit=1`.

Invalid result/log artifacts are `10714199742 / 10715035437`, ZIP SHA-256
`26b0d4aa711fa1481f45d6eb4dc8dc0d605126abb08fa744a6843f958df1f23e /
aa80f1859fce582fdba8a0a7e31c6d8a5edae3c0e521b800171a1af8494b3d7f`. The preserved raw vector is diagnostically
9/9 mechanism + 1/1 focused + 4/6 produced + selector430 430/430; rows4/5 report
`PeriodicActionCorrespondenceMismatch`. No product or debt conclusion may be taken from that vector in this turn.

Accepted runtime remains `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316`; selector430 remains **430/430**;
stable accounting remains **50 / 14 / 36**; produced-witness debt remains **3**; CB12 candidate stays unpromoted; selector
publication is prohibited.

## Exact next turn

**`M5-CP3-CB13` — control-plane-only result-manifest finalization correction**, using
`.agents/Directional/Architecture_M5_CP3_CB13_R11_Result_Manifest_Finalization_Orchestration_Correction_Plan.md`.

CB13 keeps candidate `10713410215` unchanged, moves final-manifest temporary output outside the result tree, preserves
copy-before-manifest ordering, and schema/static/synthetic-verifies the corrected finalizer without Directional runtime. If
green, it freezes fresh `M5-CP3-TB1-R11-R1-EXEC`, which restarts all 446 processes from ordinal 1 on the same
candidate/routing/selector with zero semantic carry-forward from invalid R11. A mechanically complete retry then follows normal
cadence; semantic RED routes to `M5-CP3-TB1-R11-R1-REV`.

## Resume-critical evidence

- invalid-attempt report: `.agents/Directional/Architecture_M5_CP3_TB1_R11_Invalid_Attempt_Report.md`
- CB13 plan: `.agents/Directional/Architecture_M5_CP3_CB13_R11_Result_Manifest_Finalization_Orchestration_Correction_Plan.md`
- R11 run/job: `35771152416 / 106892972571`
- R11 result/log: `10714199742 / 10715035437`
- invalid manifest: 913 rows vs 912 actual non-manifest files; SHA-256 `8d66c6993da9cac570c6953d2f802d179ae7186f2ae6d58a6b5dd1c20dd937f4`
- CB12 candidate/source: `10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`
- candidate/root-manifest/source-archive hashes: `faf4def9e6823f718e56091876bb97047f5e91a8bfb561ca40d91d70d2af61ce / 352f7553e2f0dc627ada385d78327bcb93d4f3b66125f4faf540d6965a1c2c33 / 506e9d75976802f7045b95344ef8cc0ff1e4d39b8343bdaddaa009a58e04a673`
- routing artifact/hash: `10592987234 / 352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`
- selector430 / first427: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6 / f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`
- prior R10 Review findings: consolidated in `.agents/Directional/M5_Consolidated_Record.md` and `.agents/Directional/Regression_Root_Cause_Tracker.md`
- cadence/tracker/consolidated record: `.agents/Directional/Turn_Cadence.md`, `.agents/Directional/Regression_Root_Cause_Tracker.md`, `.agents/Directional/M5_Consolidated_Record.md`

## Context Load Plan

```yaml
load_next:
  - references/turns/CB.md
conditional_modules:
  - trigger: GitHub Actions workflow/schema/static harness operations
    path: modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M5_CP3_TB1_R11_Invalid_Attempt_Report.md
  - .agents/Directional/Architecture_M5_CP3_CB13_R11_Result_Manifest_Finalization_Orchestration_Correction_Plan.md
  - .agents/Directional/Turn_Cadence.md
  - .agents/Directional/Regression_Root_Cause_Tracker.md
  - .agents/Directional/M5_Consolidated_Record.md
do_not_preload:
  - product/test/fixture/selector/routing semantic mutation
  - any Directional runtime in CB13
  - package rebuild or replacement
  - invalid-attempt process outcomes as semantic evidence
  - selector publication
  - M6 occurrence work
```
