# M6-TB60-DIAG-RETAIN-GUI-FULL-GATE-EXEC — full gate, CLI cases and GUI link check on the CB61 packages (2026-10-31)

**Scope:** TB-EXEC, run locally at the user's direction, against RA-187.5's pre-registered outcome table. It is the full-gate TB for both CB60 (CLI) and CB61 (GUI), whose source it contains.

## Frozen inputs

- **Packages:** CB61 `build/local-evidence/CB61/pkg.zip` (`f39152f7…`, root `SHA256SUMS` `1c5cccb9…`) and `tools.zip` (`c324950f…`, 8 entries, re-verified after extraction); source `e1fd0e4b7560c4fa5bde96853b978d336c522e8f`, archive `2caf2ece…`. macOS arm64, default arithmetic. [CB61 record](Architecture_M6_CB61_Diag_Retain_GUI_Layers_Code_Build_Record_20261031.md).
- **Gate:** the TB58 manifest [`Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv`](Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv) (863 rows, `31c1360a…`); [ledger v4](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv) (82, `36241caa…`).
- **Runner:** `tools/m6_cp3_local_gate_driver.py` with harness `78b8002c…`, three workers, in the form given in the [TB57 report](Architecture_M6_TB57_Diag_Retain_Full_Gate_Local_Test_Report_20261031.md) with the inputs above. CLI cases: `build/local-evidence/TB59/tb59_check.sh` (`16137c4e…`) on `tools.zip`'s `bin/directional`.

## Result

The gate result is `build/local-evidence/TB60/result.zip` (gitignored), SHA-256 `2b098fb43172f4fde89a147b07d5c2ee9798e86cd0de25ffbafb5d8724c44eb6`, with 1,734 checksum entries.

| Measure | Value |
|---|---:|
| Planned / executed / passed | **863 / 863 / 862** |
| RED / ABNORMAL / missing / skipped / duplicate | **1** / 0 / 0 / 0 / 0 |
| Membership (five binaries) | **945** = 863 GATED + 82 DEFERRED |
| postflight / harness exit | true / 90 (`required controls failed`) |
| CLI cases (RA-186.3) | **11/11 PASS**; run A's dump byte-identical to the probe and TB59 (`fa55ca63…`) |
| GUI link check | true: `directional-ui` links the same Homebrew `libgmp.10` and `libgmpxx.4` as the gate binaries |

- **The only non-PASS** is row 283 (`selector:241`), `segment_arrangement(): surviving twin has invalid next`, the pre-registered O16 signature. Rows 854–863 pass.

- **Independent audit (Haiku subagent, read-only), all checks pass:**
  - The input hashes match, and 1,734/1,734 checksum entries verify, with no unlisted files.
  - 863/863 ledger rows equal the manifest in order, and every raw-log SHA matches.
  - All 862 PASS logs contain `[  PASSED  ] 1 test.` and no `FAILED` line.
  - Membership is 945 = exactly the manifest pairs (863) plus the ledger v4 pairs (82), with no overlap.

## Outcome

Per RA-187.5, the result matches the pre-registered outcome. **DIAG-RETAIN is closed:** A5–A7 snapshots (CB58), the display adapter and dump (CB59), the CLI sidecar (CB60) and the GUI layers (CB61) are landed, and CB60 now has its full-gate TB. The layers' on-screen appearance is left to a manual check by the user. No separate REV is scheduled. The next turn is **`M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE`**. Stable 66/17/49, debt 1, unchanged. TB60 (863, 862/1) is the latest local candidate; TB52 853/0 remains the latest reviewed Linux candidate.
