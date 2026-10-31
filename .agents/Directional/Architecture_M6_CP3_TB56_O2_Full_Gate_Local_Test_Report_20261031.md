# M6-CP3-TB56-O2-FULL-GATE-EXEC — local five-binary gate on the CB57 package (2026-10-31)

**Scope:** TB-EXEC, run locally at the user's direction. It reports counts and first failures against RA-183.5's pre-registered outcome table.

## Frozen inputs

- **Package:** CB57 `build/local-evidence/CB57/pkg.zip` (gitignored), ZIP `2401b5d3…`, root `SHA256SUMS` `f2eaf731…`, source `fb4f637bcdd9bd3ae4d8a7e4e97cdf2023d3e4c7`, archive `07435e5c…`. macOS arm64, default arithmetic. [CB57 record](Architecture_M6_CP3_CB57_O2_No_Atlas_Entry_Gate_Code_Build_Record_20261031.md).
- **Gate:** [`Architecture_M6_CP3_TB56_O2_Full_Gate_Case_Manifest.tsv`](Architecture_M6_CP3_TB56_O2_Full_Gate_Case_Manifest.tsv), 859 rows, `c8437d61…`. **Ledger v4:** 82 rows, `36241caa…`.
- **Runner:** `tools/m6_cp3_local_gate_driver.py` with harness `78b8002c…`, three workers, from 02:07:29Z to 02:17:49Z. The command has the form given in the [TB57 report](Architecture_M6_TB57_Diag_Retain_Full_Gate_Local_Test_Report_20261031.md), with the frozen inputs above.

## Result

The result is `build/local-evidence/TB56/result.zip` (gitignored), SHA-256 `9e138c0168f7017a3972d7d5a9ad468c1eb95cce9bf53b6028dea86cc40db724`, with 1,726 checksum entries.

| Measure | Value |
|---|---:|
| Planned / executed / passed | **859 / 859 / 858** |
| RED / ABNORMAL / missing / skipped / duplicate | **1** / 0 / 0 / 0 / 0 |
| control_bad | 1 |
| Membership (five binaries) | **941** = 859 GATED + 82 DEFERRED |
| postflight / harness exit | true / 90 (`required controls failed`) |

- **The only non-PASS** is row 283 (`selector:241`), which throws `segment_arrangement(): surviving twin has invalid next`. This is the pre-registered O16 signature (RA-183.2).
- **Row 859** (`ra183:o2-no-atlas-not-applicable`) **PASSES**. Rows 854–858 pass.

- **Independent audit (Haiku subagent, read-only), all checks pass:**
  - The input hashes match, and 1,726/1,726 checksum entries verify, with no unlisted files.
  - 859/859 ledger rows equal the manifest in order, and every raw-log SHA matches.
  - All 858 PASS logs contain `[  PASSED  ] 1 test.` and no `FAILED` line.
  - Membership is 941 = exactly the manifest pairs (859) plus the ledger v4 pairs (82).

## Outcome

Per RA-183.5, the result matches the pre-registered outcome: 858/859, with only row 283 red, postflight true and membership 941. **The O2 entry gate is landed.** No separate REV is scheduled. The next turn is **`M6-DEFN-DIAG-RETAIN-A5-A7`**. Stable 66/17/49, debt 1, unchanged. TB56 (859, 858/1) is the latest local candidate; TB52 853/0 remains the latest reviewed Linux candidate.
