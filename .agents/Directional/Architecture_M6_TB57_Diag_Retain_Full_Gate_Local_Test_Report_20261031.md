# M6-TB57-DIAG-RETAIN-FULL-GATE-EXEC — local five-binary gate on the CB58 package (2026-10-31)

**Scope:** TB-EXEC, run locally at the user's direction. It reports counts and first failures against RA-184.6's pre-registered outcome table.

## Frozen inputs

- **Package:** CB58 `build/local-evidence/CB58/pkg.zip` (gitignored), ZIP `241aeebd…`, root `SHA256SUMS` `8e154d56…`, source `58ddfef02fc0803092c3fc0967c99fe47a6bc0bf`, archive `d2f9f01a…`. macOS arm64, default arithmetic. [CB58 record](Architecture_M6_CB58_Diag_Retain_A5_A7_Snapshots_Code_Build_Record_20261031.md).
- **Gate:** [`Architecture_M6_CP3_TB57_Diag_Retain_Full_Gate_Case_Manifest.tsv`](Architecture_M6_CP3_TB57_Diag_Retain_Full_Gate_Case_Manifest.tsv), 861 rows, `f898c9b6…`. **Ledger v4:** 82 rows, `36241caa…`.
- **Runner:** `tools/m6_cp3_local_gate_driver.py` with harness `78b8002c…`, three workers, from 04:24:12Z to 04:34:34Z:

  ```
  python3 -I .agents/Directional/tools/m6_cp3_local_gate_driver.py \
    --harness .agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh --harness-sha 78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94 \
    --package-zip build/local-evidence/CB58/pkg.zip --package-zip-sha 241aeebd9c925782868f6546399e581bcd4282639231908c02ede2983477cbbb \
    --root-manifest-sha 8e154d568109798caa55ed88bfeed01890e4dec759be24338a6159f6d140a972 \
    --source-sha 58ddfef02fc0803092c3fc0967c99fe47a6bc0bf --source-archive-sha d2f9f01a131f79bd6bae95f4cbe131e462302314f681e526c51b6e07f117a91b \
    --manifest .agents/Directional/Architecture_M6_CP3_TB57_Diag_Retain_Full_Gate_Case_Manifest.tsv --manifest-sha f898c9b67c6f6f2c7ffa5bfaf054cb82dc8b691db0f74f0d28e3bee5ceab2b32 --count 861 \
    --ledger .agents/Directional/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv --ledger-sha 36241caa61d3d27aa062fee05cf3af12a62a81a5a11a42e3ea75e46b0590139d \
    --work build/local-evidence/TB57/run --jobs 3
  ```

## Result

The result is `build/local-evidence/TB57/result.zip` (gitignored), SHA-256 `d0b9fa3808587cff63191e469c71c4b171e59196111e1c440c6c465b8d42f345`, with 1,730 checksum entries.

| Measure | Value |
|---|---:|
| Planned / executed / passed | **861 / 861 / 860** |
| RED / ABNORMAL / missing / skipped / duplicate | **1** / 0 / 0 / 0 / 0 |
| control_bad | 1 |
| Membership (five binaries) | **943** = 861 GATED + 82 DEFERRED |
| postflight / harness exit | true / 90 (`required controls failed`) |

- **The only non-PASS** is row 283 (`selector:241`), which throws `segment_arrangement(): surviving twin has invalid next`. This is the pre-registered O16 signature (RA-183.2).
- **Rows 860** (`ra184:diag-retain-helper-copies`) **and 861** (`ra184:diag-retain-iff-requested`) **PASS**. Rows 854–859 pass.

- **Independent audit (Haiku subagent, read-only), all checks pass:**
  - The input hashes match, and 1,730/1,730 checksum entries verify, with no unlisted files.
  - 861/861 ledger rows equal the manifest in order, and every raw-log SHA matches.
  - All 860 PASS logs contain `[  PASSED  ] 1 test.` and no `FAILED` line.
  - Membership is 943 = exactly the manifest pairs (861) plus the ledger v4 pairs (82), with no overlap.

## Outcome

Per RA-184.6, the result matches the pre-registered outcome: 860/861, with only row 283 red, postflight true and membership 943. **The A5–A7 diagnostic snapshots are landed.** No separate REV is scheduled. The next turn is **`M6-DEFN-DIAG-RETAIN-CLI-GUI`**. Stable 66/17/49, debt 1, unchanged. TB57 (861, 860/1) is the latest local candidate; TB52 853/0 remains the latest reviewed Linux candidate.
