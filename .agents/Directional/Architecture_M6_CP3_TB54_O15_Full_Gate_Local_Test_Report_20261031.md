# M6-CP3-TB54-O15-FULL-GATE-EXEC — local five-binary gate on the CB55 package (2026-10-31)

**Scope:** TB-EXEC, run locally at the user's direction. This report gives counts and first failures only; classification belongs to `M6-CP3-TB54-O15-FULL-GATE-REV`.

## Frozen inputs

- **Package:** CB55 `build/local-evidence/CB55/pkg.zip` (gitignored), ZIP `69104b95…`, root `SHA256SUMS` `34791360…`, source `0402716703e26cb640f6bc8a423389c31987107f`, archive `6066039e…`. macOS arm64, default arithmetic. [CB55 record](Architecture_M6_CP3_CB55_A3_Exact_Branch_Topology_Code_Build_Record_20261030.md).
- **Gate:** [`Architecture_M6_CP3_TB54_O15_Full_Gate_Case_Manifest.tsv`](Architecture_M6_CP3_TB54_O15_Full_Gate_Case_Manifest.tsv), 857 rows, `53683907…`. **Ledger v3:** 83 rows, `32b43fc5…`.
- **Runner:** `tools/m6_cp3_local_gate_driver.py` with harness `78b8002c…`, three workers, from 2026-10-30T23:58:44Z to 2026-10-31T00:09:00Z. The command has the form given in the [TB57 report](Architecture_M6_TB57_Diag_Retain_Full_Gate_Local_Test_Report_20261031.md), with the frozen inputs above.

## Result

The result is `build/local-evidence/TB54/result.zip` (gitignored), SHA-256 `706f4ce759651a505cdc393e9ddaf18bdc8c3f2a5f286c0f01152cf7f1d9f3ea`, with 1,722 checksum entries.

| Measure | Value |
|---|---:|
| Planned / executed / passed | **857 / 857 / 856** |
| RED / ABNORMAL / missing / skipped / duplicate | **1** / 0 / 0 / 0 / 0 |
| control_bad | 1 |
| Membership (five binaries) | **940** = 857 GATED + 83 DEFERRED |
| postflight / harness exit | true / 90 (`required controls failed`) |

- **The only non-PASS** is row 283 (`selector:241`, `SurfaceCellsPhase10.LegacySyntheticOutputHashIsStableAcrossTenRuns`). Its first failure is `unknown file`, an exception `segment_arrangement(): surviving twin has invalid next`, the same signature as in RA-179.
- **Rows that passed:**
  - row 854 (`offgate:223`) and row 855 (`offgate:225`);
  - row 856 (`ra180:o15-edge-parallel`) and row 857 (`ra180:o15-mechanical-ports`);
  - all 21 rows that RA-179 lists for O15.
- **Factual observation:** row 637's log shows `incidences=3 classes=3` at source vertices 10, 35, 47 and 71.
- **Independent audit (Haiku subagent, read-only), all checks pass:**
  - The input hashes match, and 1,722/1,722 checksum entries verify, with no unlisted files.
  - 857/857 ledger rows equal the manifest in order, and every raw-log SHA matches.
  - All 856 PASS logs contain `[  PASSED  ] 1 test.` and no `FAILED` line.
  - Membership is 940 = exactly the manifest pairs (857) plus the ledger v3 pairs (83).

## Outcome

Per RA-180.6: 856/857 PASS, with row 283 the only RED, postflight true and membership 940 → **`M6-CP3-TB54-O15-FULL-GATE-REV`**. No selector, CP3 or O15 acceptance is made here.
