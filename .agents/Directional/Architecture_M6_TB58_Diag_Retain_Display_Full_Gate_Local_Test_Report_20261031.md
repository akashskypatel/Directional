# M6-TB58-DIAG-RETAIN-DISPLAY-FULL-GATE-EXEC — local five-binary gate on the CB59 package (2026-10-31)

**Scope:** TB-EXEC, run locally at the user's direction. It reports counts and first failures against RA-185.5's pre-registered outcome table.

## Frozen inputs

- **Package:** CB59 `build/local-evidence/CB59/pkg.zip` (gitignored), ZIP `1bd8c0ba…`, root `SHA256SUMS` `fb1ac1ea…`, source `39a77d2ef90602a19245ddfc5a73a3d9b753c3ee`, archive `0fa1bd04…`. macOS arm64, default arithmetic. [CB59 record](Architecture_M6_CB59_Diag_Retain_Materialization_Display_Code_Build_Record_20261031.md).
- **Gate:** [`Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv`](Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv), 863 rows, `31c1360a…`. **Ledger v4:** 82 rows, `36241caa…`.
- **Runner:** `tools/m6_cp3_local_gate_driver.py` with harness `78b8002c…`, three workers, from 04:57:47Z to 05:08:14Z. The command has the form given in the [TB57 report](Architecture_M6_TB57_Diag_Retain_Full_Gate_Local_Test_Report_20261031.md), with the frozen inputs above (`--count 863`).

## Result

The result is `build/local-evidence/TB58/result.zip` (gitignored), SHA-256 `647bd326fb9edf94c327db667daa38a4dbb7ce24d2296d0cdf0f96cebcd5ede5`, with 1,734 checksum entries.

| Measure | Value |
|---|---:|
| Planned / executed / passed | **863 / 863 / 862** |
| RED / ABNORMAL / missing / skipped / duplicate | **1** / 0 / 0 / 0 / 0 |
| control_bad | 1 |
| Membership (five binaries) | **945** = 863 GATED + 82 DEFERRED |
| postflight / harness exit | true / 90 (`required controls failed`) |

- **The only non-PASS** is row 283 (`selector:241`), which throws `segment_arrangement(): surviving twin has invalid next`. This is the pre-registered O16 signature (RA-183.2).
- **Rows 862** (`ra185:materialization-display-retained`) **and 863** (`ra185:materialization-display-absent`) **PASS**. Rows 854–861 pass.

- **Independent audit (Haiku subagent, read-only), all checks pass:**
  - The input hashes match, and 1,734/1,734 checksum entries verify, with no unlisted files.
  - 863/863 ledger rows equal the manifest in order, and every raw-log SHA matches.
  - All 862 PASS logs contain `[  PASSED  ] 1 test.` and no `FAILED` line.
  - Membership is 945 = exactly the manifest pairs (863) plus the ledger v4 pairs (82), with no overlap.

## Outcome

Per RA-185.5, the result matches the pre-registered outcome: 862/863, with only row 283 red, postflight true and membership 945. **The materialization display adapter is landed.** No separate REV is scheduled. The next turn is **`M6-DEFN-DIAG-RETAIN-CLI-GUI-WIRING`**. Stable 66/17/49, debt 1, unchanged. TB58 (863, 862/1) is the latest local candidate; TB52 853/0 remains the latest reviewed Linux candidate.
