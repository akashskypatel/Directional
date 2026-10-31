# TB37 periodic-route atlas verification — artifact-only execution (2026-10-25)

Canonical turn: `M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY`.
Run: https://github.com/akashskypatel/Directional/actions/runs/40179570318 (successful workflow).
Executor commit: `35b808fbbcc7a8337005a1af59b75c4caaaa8217`.
Immutable build source: `038ae7fd7c290731c28225d2693a3e13866e325a`.
Immutable CB36 package artifact: `12590917524` (ZIP SHA-256 `6dcbfe5a468be5f548c368bfebeba411c6abd19ed4a4efd01be9923da9eb7d03`).
Frozen case manifest: `Architecture_M6_CP3_TB37_Periodic_Route_Atlas_Verification_Case_Manifest.tsv`, SHA-256 `d14b24d96c66c6a2c346b60003a5697dfab1764109b45854a3f145bba70b667d`.

## Execution and evidence

Result artifact `12593545901`, outer ZIP SHA-256 `d7fd939bfb3ab79b412d856ce214082558c3039c4a692b08613478dbafa31348`; diagnostic log artifact `12593955561`, ZIP SHA-256 `9ed45905ac1235ad0d6893c79cbd10b38e6cd69c9fea2e180f7e1c137aad28b8`. The result SHA256SUMS contains 21 verified entries. Original immutable package rechecked 28/28 before and after, source SHA and GMP boundary were verified; binary/test-data view hash inventory unchanged. No build, relink, configuration, benchmark, selector mutation, package repair, or test-source changes. Sixteen unique tests each ran in a fresh process; zero missing, skipped, crashed or zero-selected cases.

| Manifest rows | Result | Interpretation |
|---|---|---|
| 1–3 (new quarter, half and directed route witnesses) | 3 PASS | Candidate behavioral confirmation of CB36 atlas transport |
| 4–5, 8–16 (historical passing controls) | 11 PASS | Zero historical PASS regression |
| 6–7 (frozen selectors 191/192) | 2 RED | Historical failure dispositions unchanged; not a newly introduced regression |
| Total | **14 PASS / 2 RED / 0 invalid** | Artifact-only focused candidate result |

## Raw-log adjudication of harness false-positive stop flags

The harness `review_stop` recorded `FROZEN_191_192_DISPOSITION_CHANGED` on rows 6 and 7. This classification is **wrong**: its predicate searched for literal text `Produced` and `None` in Google Test output, while Google Test displayed enums as 4-byte objects. Raw row 6 shows disposition `<01-00 00-00>` instead of expected `Rejected <02-00 00-00>`, and reason `<00-00 00-00>` instead of expected 29 `<1D-00 00-00>`. Row 7 shows the same, and additionally prints `is_produced() Actual: true`. Both correspond to the prior `Produced/None` classification. These are inherited frozen oracle failures, not changed dispositions. This is a harness classification defect; independent Review should certify it from the immutable raw logs. No rerun or test repair is warranted solely to make the harness warning green.

## Previous failed orchestration attempt

Run `40179382655` (result artifact `12593920797`, log `12594110635`) executed 0 tests. The TB37 harness erroneously retained the old 13-case uniqueness check. Its zero-execution result is not semantic evidence; the corrected harness was committed at `35b808fbbcc7a8337005a1af59b75c4caaaa8217` and the corrected fresh dispatcher run above executed all 16 cases. The earlier no-op failure is preserved for honest orchestration history.

## Disposition and follow-up

Candidate verification succeeds on the 14 expected-green cases. Frozen 191/192 remain RED exactly as planned. Stable regression accounting **66 events / 17 categories / 49 recurrences**, debt **1**, and CP2 **491/491 accepted** are unchanged; 497 selector remains frozen and unpromoted. CP3 RP-01 remains open. The next authorized boundary after durable closeout is independent `M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY-REV`; **do not run TB38 or change frozen oracles within TB37**.

Independent Review must inspect the two raw RED logs, classify the false-positive stop flags, verify manifest/process coverage and immutable-source authority, and decide whether TB37 is accepted. The TB38 full census remains a separate later turn.
