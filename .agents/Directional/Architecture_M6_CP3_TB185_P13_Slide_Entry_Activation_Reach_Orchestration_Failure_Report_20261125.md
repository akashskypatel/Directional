# TB-EXEC-185 — invalid slide-entry reach execution (2026-11-25 UTC)

## Situation

`M6-CP3-TB-EXEC-185` stopped on invalid execution. The gate executed 1006 selected cases: 1005 PASS, one INVALID, zero semantic RED. The harness killed row1006 after its 600-second timeout. This attempt is invalid-attempt provenance, not semantic runtime authority. TB184 remains independently accepted at 1005/1005. No production activation or checkpoint promotion.

## Background — exact authority

| Evidence | Exact value |
|---|---|
| Candidate | Source `21087c8285a5dd367cc16f610386accc061bd194`, package [14995401750](https://github.com/akashskypatel/Directional/actions/runs/45554728034/artifacts/14995401750), ZIP SHA-256 `7e66ef7b3b16e76618a60b250a76038e65bf2e092601958f8252ac993b778da9`, root manifest `255e344116e2faa2d351b637cdfc6d11805b83352965f794b8bddaf56409f5d3`, source archive `bba6f2ce82c27a1481dad5fb16952b88476fca25411840a3e6d588ad67d2502e`, 28/28 checks. [CB-205 record](Architecture_M6_CP3_CB205_P13_Slide_Entry_Activation_Reach_Code_Build_Record_20261125.md). |
| Gate | [Exact manifest](gates/Architecture_M6_CP3_CB205_P13_Slide_Entry_Activation_Reach_Exact_Manifest.md); [1006-case manifest](gates/Architecture_M6_TB185_P13_Slide_Entry_Activation_Reach_Full_Gate_Case_Manifest.tsv) SHA-256 `a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587`, first 1005 rows with header `94f02d6bd2d599f02bbc7dc7cd317e490cdb00e18827596acac2cfdd827460be`; deferred ledger v5 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, 81 deferred. |
| Execution | [Run 45557127344](https://github.com/akashskypatel/Directional/actions/runs/45557127344), job `139011954262`, request `m6-cp3-tb185-exec`, event `940ef038fd8841b0730a8515449d5ab1d0e9fe11`, request SHA-256 `78d82be8d9ae27b51654267df52701942eb161ca788b733dd8876813ebbb8075`, harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Final orphan mailbox `.workflow-mailbox/m6-cp3-tb185-exec/latest.json`: failure. |
| Result | [14997312958](https://github.com/akashskypatel/Directional/actions/runs/45557127344/artifacts/14997312958), ZIP SHA-256 `a203a59e2a7becfaa66fd43fa6c2035e4c47c6d05ed2158c8f50ed3dbe381477`, 2020/2020 internal member hashes. |
| Harness log | [14996494547](https://github.com/akashskypatel/Directional/actions/runs/45557127344/artifacts/14996494547), ZIP SHA-256 `ffab6b1aaf81bfd18b60979dc4f53bd4e2b1fe5a028c52f1cf94148e13edbba7`. |
| Wrapper log | [14996404710](https://github.com/akashskypatel/Directional/actions/runs/45557127344/artifacts/14996404710), ZIP SHA-256 `cc6697455963443a4e99bb4c815c4c076500296d2eae8446558666601b0f57d1`. |
| Accepted baseline | TB184 [14992995631](https://github.com/akashskypatel/Directional/actions/runs/45546583508/artifacts/14992995631), ZIP SHA-256 `8686e64c07fed5e72a5285fa6071a50944f1ea0b24c4b9e61eea831c46e0dd9c`, 2018/2018 hashes. |
| Inspection source | Snapshot run `45556950597`, artifact `14994904623`, source `aaa6a22e58c3d653d3d84d73f568826adea9a3e6`, ZIP SHA-256 `acab04e4f57212a01d0785f456e3e1cb15b7089f6a04fa75edc5a44aedcd2460`, archive `a430758a93380a4f1e6af44f324a3660d0dcd749f0e821bfa4aeb392fab6cbfe`, 5830/5830 checks. |

## Assessment

- Exact execution boundary: `{"planned":1006,"executed":1006,"passed":1005,"red":0,"abnormal":0,"missing":1,"skipped":0,"duplicate":0,"control_bad":1,"unexpected_pass":0,"later_positive_red":0,"red_site_bad":0,"membership":1087,"postflight":true}`. Harness exit 90, `ValueError: selection failure`. No configure, compile, relink or benchmark. Immutable postflight passed. Membership is exactly 1006 gated + 81 deferred, one addition versus TB184 and no removed member.
- First 1005 ledger fields except raw-log hash equal to TB184; all named tests PASS with matching resource commands, verified log hashes and exit 0. Comparison: 774 exact, 231 N1/N2, zero N3/material; 1582 complete projection records in each. Negative controls reject removed, duplicated or altered complete records and non-record byte changes. No new allowance for row979 or any prior row. This is invalid-attempt evidence only.
- Row1006 ran once but has no terminal GTest verdict. Raw SHA-256 `184bd104f0ace186944e92de7f7af6fd29b70ac3a762c1f9a79859f32e530ab2`; last marker `HARNESS_TIMEOUT 600s`, process exit 124, verdict INVALID. Resource file empty (SHA-256 `e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855`), so actual completed test elapsed time is unknown. `m6_cp3_targeted_artifact_harness.sh:520` calls `process.wait(timeout=600)` for every case, including the full gate; lines 521–531 kill/reap the process group and force exit 124. This contradicts the full-suite timeout policy in `GitHub_Workflow_Policy.md`. The runner stopped after ~22 min overall, including the 600 s case window. A product hang or runtime cost defect is not established.
- Last complete recipe: `polyline-defaults/genus_two`; next recipe in source order is `close_sheets`, then `cylinder` (`FieldAlignedCurveNetworkTests.cpp:24035–24054`). The log does not prove the exact blocked producer or that either recipe would finish. No missing recipe or final polyline-selection receipt may be inferred. No semantic acceptance from partial records.

### Partial receipt inventory (invalid attempt only)

| Recipe | Fixture | Production digest | Staged digest | Later-entry stops (production / staged) | Published digest |
|---|---|---:|---:|---:|---|
| observe | sphere_prescribed | 9084693800288509401 | 12659562395504099178 | 0 / 4 | 9084693800288509401 |
| observe | torus | 13466378781049494490 | 13466378781049494490 | 0 / 0 | 13466378781049494490 |
| observe | mechanical_feature | 7059319813685616393 | 7059319813685616393 | 0 / 0 | 7059319813685616393 |
| pipeline-products | sphere_prescribed | 9084693800288509401 | 12659562395504099178 | 0 / 4 | 9084693800288509401 |
| pipeline-products | torus | 13466378781049494490 | 13466378781049494490 | 0 / 0 | 13466378781049494490 |
| atlas-census | two-ring | 4155612135388465130 | 4155612135388465130 | 0 / 0 | not-applicable |
| atlas-census | four-triangle-fan | 4544773262561843459 | 4544773262561843459 | 0 / 0 | not-applicable |
| atlas-census | sphere_prescribed | 9084693800288509401 | 12659562395504099178 | 0 / 4 | not-applicable |
| atlas-census | torus | 4209930161671820097 | 4209930161671820097 | 0 / 0 | not-applicable |
| polyline-defaults | sphere_prescribed | 9084693800288509401 | 12659562395504099178 | 0 / 4 | 9084693800288509401 |
| polyline-defaults | genus_two | 9472719824482522776 | 9472719824482522776 | 0 / 0 | 9472719824482522776 |
| polyline-defaults | close_sheets | UNMEASURED | UNMEASURED | UNMEASURED | UNMEASURED |
| polyline-defaults | cylinder | UNMEASURED | UNMEASURED | UNMEASURED | UNMEASURED |

Explicit unstaged sphere digest `9084693800288509401` equals production; staged `12659562395504099178` differs, with four later-entry stops. All 11 printed records have successful production and staged builds; published digests bind where present. Atlas-census serialization concatenates `not-applicable` directly after the equality bit; local evidence parser decodes that exact source format without changing raw bytes. These facts do not authorize reader classification; the whole receipt and selection control are incomplete.

The failure is a non-stable orchestration candidate, not a stable product regression. Historical accounting unchanged: 67 events / 17 categories / 50 recurrences, witness debt1/deferred81. TB170 and K6 closed; P1 supported, D-U carried. J6/E5/CB-190 and CP3/497/D0/H4 promotion held.

## Recommendation — bounded successor

[Turn Cadence](Turn_Cadence.md) item 5 requires a separate control-plane-only correction, then a full immutable re-execution. Authorize `M6-CP3-CB-205R-HARNESS-TIMEOUT` as the correction identity and `M6-CP3-TB-EXEC-185R` as the re-execution identity. Do not perform either in this execution turn.

1. Correct the full-gate branch of `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` so selected gate cases wait for organic process results, without a per-case or whole-gate elapsed cutoff. Retain a justified bounded timeout only for non-gate diagnostic/census work; preserve abnormal-exit, selection, membership, resource, checksum, postflight and STOP semantics. Inspect the reusable workflow for any additional imposed gate timeout. Do not increase a fixed full-gate timeout as a substitute. Do not modify production, test, fixture, selector, case/deferred manifest or workflow permissions.
2. Verify the correction statically and with control-plane-only checks (no Directional runtime). Freeze exact executor SHA and harness hash separately from immutable candidate source. Reuse package 14995401750 unchanged; no configure, compile, relink or repackage required.
3. `M6-CP3-TB-EXEC-185R` runs all 1006 frozen cases afresh with identical candidate package and inputs. No row-only rerun, stitched ledger, or new comparison allowance. Require the exact 13 recipe keys, sphere binding, selection receipt, resource time and frozen prior-row comparison. Route subsequent semantic RED to review; route orchestration failure per cadence. `M6-CP3-TB-REV-185` remains held until a valid gate; CB-206 activation remains held.

Snapshot cleanup run `45557205982` succeeded, result `14994949864`, commit `c9fba96a65e55201fc27d4f0e30ba0db2c85c313`. Dispatcher slot and orphan mailbox retained. No local Directional runtime or source/test edits. Initial-attempt document reads preceded snapshot acquisition; the named library skills were not found; complete pre-work LESSONS review and whole-turn tool ledger were not established. The earlier PASS-only generator was not used. The invalid-attempt verifier permits the observed empty resource file only as a recorded failure and returns nonzero.
