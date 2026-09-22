# Directional Future Chat Session Handoff

## Current authority

`M5-CP3-CB13` is **COMPLETE / CONTROL-PLANE-ONLY / RUNTIME-FREE / STATIC+SYNTHETIC GREEN** once terminal `STATUS` is published.

CB13 corrects only the orchestration defect from invalid R11. The retry finalizer now stages its temporary manifest at
`${RUNNER_TEMP}/${TURN_ID}-SHA256SUMS.final`, outside the result tree; copies `driver-authority.txt` before manifest generation;
runs fail-closed `sha256sum -c SHA256SUMS`; and independently requires manifest-row equality with the actual non-manifest file
count. The retained retry workflow contains no raw 64-hex SHA-256 literals: exact hashes are frozen in the retained R11-R1
plan and materialized through `write_orchestration_payload.py`.

CB13 validation run `35775766068` is GREEN at event SHA `d078db5b8816cd2eed30c4418c26b9b1ce33497e`: retry schema job
`106908450647`, self-schema job `106908451034`, and static/synthetic job `106908512994` all pass. Result/log artifacts are
`10716415780 / 10716260918`, provider ZIP SHA-256
`e8a3d09981e6eb22df70325741bb265cc2f81cc141c507f6f1577e1e8efeb20b /
f1cfbc376c05be90da52f7e6660eb86589ec79578e3f0aba35a44e01b10df88b`. Synthetic manifest baseline is **3/3**;
checksum corruption and late-file count mismatch are both detected. The retry driver is byte-identical to invalid R11 after
restoring only its turn identifier, reproducing historical template SHA-256
`370ebb5aaa6b77f8839ac0a7c5a20f24a22cd584876ea17a11d222a5ec4f9624`. No Directional executable or benchmark ran in CB13.

Immutable candidate authority remains `10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`. Accepted runtime remains
`10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316`; selector430 remains **430/430**; stable accounting remains
**50 / 14 / 36**; produced-witness debt remains **3**; candidate stays unpromoted; selector publication is prohibited.
Invalid R11 artifacts `10714199742 / 10715035437` remain provenance only and contribute zero semantic credit.

## Exact next turn

**`M5-CP3-TB1-R11-R1-EXEC`** under
`.agents/Directional/Architecture_M5_CP3_TB1_R11_R1_Artifact_Only_Test_Benchmark_Plan.md`.

R11-R1 consumes the same immutable CB12 candidate, routing artifact and selector430, restarts all **446** fresh exact-filter
processes from ordinal 1, requires exact-one/zero-skip, executes **0** benchmarks, and imports zero semantic rows or verdicts
from invalid R11. Any mechanically complete retry routes to mandatory `M5-CP3-TB1-R11-R1-REV`; orchestration failure follows
the durable orchestration-failure edge.

## Resume-critical evidence

- CB13 report: `.agents/Directional/Architecture_M5_CP3_CB13_R11_Result_Manifest_Finalization_Orchestration_Correction_Report.md`
- R11-R1 plan: `.agents/Directional/Architecture_M5_CP3_TB1_R11_R1_Artifact_Only_Test_Benchmark_Plan.md`
- retained retry workflow: `.github/workflows/m5-cp3-tb1-r11-r1-exec.yml`
- retained retry driver: `.agents/Directional/turn-payloads/m5_cp3_tb1_r11_r1_exec.py.in`
- CB13 validation run/jobs: `35775766068 / 106908450647 / 106908451034 / 106908512994`
- CB13 result/log: `10716415780 / 10716260918`
- CB13 result/log ZIP SHA-256: `e8a3d09981e6eb22df70325741bb265cc2f81cc141c507f6f1577e1e8efeb20b / f1cfbc376c05be90da52f7e6660eb86589ec79578e3f0aba35a44e01b10df88b`
- source snapshot run/artifact: `35774876423 / 10716035645`, ZIP SHA-256 `8425597c0a694153027e334b8ec49eadba73703b12a365a84cc69f9221d23cd1`
- invalid R11 report: `.agents/Directional/Architecture_M5_CP3_TB1_R11_Invalid_Attempt_Report.md`
- invalid R11 run/job + result/log: `35771152416 / 106892972571`, `10714199742 / 10715035437`
- CB12 candidate/source: `10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`
- candidate/root-manifest/source-archive SHA-256: `faf4def9e6823f718e56091876bb97047f5e91a8bfb561ca40d91d70d2af61ce / 352f7553e2f0dc627ada385d78327bcb93d4f3b66125f4faf540d6965a1c2c33 / 506e9d75976802f7045b95344ef8cc0ff1e4d39b8343bdaddaa009a58e04a673`
- routing artifact/identity map: `10592987234`, `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`
- selector430 / first427: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6 / f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`

## Context Load Plan

```yaml
load_next:
  - references/turns/TB.md
conditional_modules:
  - trigger: GitHub Actions workflow execution/observation
    path: modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M5_CP3_CB13_R11_Result_Manifest_Finalization_Orchestration_Correction_Report.md
  - .agents/Directional/Architecture_M5_CP3_TB1_R11_R1_Artifact_Only_Test_Benchmark_Plan.md
  - .agents/Directional/Turn_Cadence.md
  - .agents/Directional/Regression_Root_Cause_Tracker.md
  - .agents/Directional/M5_Consolidated_Record.md
do_not_preload:
  - product/test/fixture/selector/routing semantic mutation
  - package rebuild or replacement
  - invalid-R11 process outcomes as semantic evidence
  - selector publication
  - M6 occurrence work
```
