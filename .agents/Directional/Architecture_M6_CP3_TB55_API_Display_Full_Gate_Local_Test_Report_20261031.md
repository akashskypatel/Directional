# M6-CP3-TB55-API-DISPLAY-FULL-GATE-EXEC — local five-binary gate on the CB56 package (2026-10-31)

**Scope:** TB-EXEC, run locally at the user's direction. It reports counts and first failures against RA-182.5's pre-registered outcome table.

## Frozen inputs

- **Package:** CB56 `build/local-evidence/CB56/pkg.zip` (gitignored), ZIP `26d88d20…`, root `SHA256SUMS` `ddf68443…`, source `567d1828301f74a6e3c50bfcdfc4f7e6819d1ad3`, archive `07c5c167…`. macOS arm64, default arithmetic. [CB56 record](Architecture_M6_CP3_CB56_API_Display_Vertex_Stop_Witness_Code_Build_Record_20261031.md).
- **Gate:** [`Architecture_M6_CP3_TB55_API_Display_Full_Gate_Case_Manifest.tsv`](Architecture_M6_CP3_TB55_API_Display_Full_Gate_Case_Manifest.tsv), 858 rows, `eb508378…`.
- **Ledger v4:** [`Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv`](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv), 82 rows, `36241caa…`.
- **Runner:** `tools/m6_cp3_local_gate_driver.py` with harness `78b8002c…`, three workers, from 00:53:07Z to 01:03:28Z. The exact command is in the handoff.

## Result

The result is `build/local-evidence/TB55/result.zip` (gitignored), SHA-256 `d1d89f0d328d1bf9ffbc500667c8aa9b6dfe219f2c3193e291ba4adef9f0c8c7`, with 1,724 checksum entries.

| Measure | Value |
|---|---:|
| Planned / executed / passed | **858 / 858 / 857** |
| RED / ABNORMAL / missing / skipped / duplicate | **1** / 0 / 0 / 0 / 0 |
| control_bad | 1 |
| Membership (five binaries) | **940** = 858 GATED + 82 DEFERRED |
| postflight / harness exit | true / 90 (`required controls failed`) |

- **The only non-PASS** is row 283 (`selector:241`), which throws `segment_arrangement(): surviving twin has invalid next`. This is the pre-registered O2 signature (RA-179 F3).
- **Row 858** (`apicensus:19`, `SurfaceCellTracingDisplay.StopLocationShowsWhatEachStageReported`) **PASSES**. Rows 854–857 (RP-01 and O15) pass.

- **Independent audit (Haiku subagent, read-only), all checks pass:**
  - The input hashes match, and 1,724/1,724 checksum entries verify, with no unlisted files.
  - 858/858 ledger rows equal the manifest in order, and every raw-log SHA matches.
  - All 857 PASS logs contain `[  PASSED  ] 1 test.` and no `FAILED` line.
  - Membership is 940 = exactly the manifest pairs (858) plus the ledger v4 pairs (82), and the display test is GATED.

## Outcome

Per RA-182.5, the result matches the pre-registered outcome: 857/858, with only row 283 red, postflight true and membership 940. **Row 935 has moved to the gate.** No separate REV turn is scheduled (RA-164 lean rule). The next turn is **`M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS`**. Stable 66/17/49, debt 1, unchanged. TB55 (858, 857/1) is the latest local candidate; TB52 853/0 remains the latest reviewed Linux candidate.
