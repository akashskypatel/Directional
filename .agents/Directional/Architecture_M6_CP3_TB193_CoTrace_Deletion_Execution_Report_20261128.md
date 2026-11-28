# TB-EXEC-193 — Claimed co-trace deletion full gate (2026-11-28 UTC)

## Situation

`M6-CP3-TB-EXEC-193` executed the frozen 1013-row full gate on the CB-218 candidate. Result: 1013/1013 PASS, membership 1094 (1013 gated + 81 deferred). Root `STATUS` governs formal closeout. Successor: `M6-CP3-TB-REV-193`, the independent review. No gate credit is given before that review. The deletion option stays off in production.

## Background

[Exact manifest](gates/Architecture_M6_CP3_CB217_CB218_TB193_CoTrace_Deletion_Exact_Manifest.md) (TB-EXEC-193 section). Case manifest [`Architecture_M6_CP3_CB217_CB218_TB193_CoTrace_Deletion_Full_Gate_Case_Manifest.tsv`](gates/Architecture_M6_CP3_CB217_CB218_TB193_CoTrace_Deletion_Full_Gate_Case_Manifest.tsv), SHA-256 `b910f2a96626660f46042c34360a8062c7546f35fb1980432d038ba8f41d2fc2`, 1013 rows. Header plus rows 1–1010 equal TB192's manifest `c9f6325eee41ebead3d516d3bfcbef3141c9dee8c7051cef1e08ad146f60e9f5`. Deferred ledger [`Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv`](gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv), SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81 identities). Harness [`m6_cp3_targeted_artifact_harness.sh`](../tools/m6_cp3_targeted_artifact_harness.sh), SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`, unchanged from TB192.

## Assessment

| Evidence | Exact authority |
|---|---|
| Candidate | [CB-218 record](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#tb194-folded-cb218): artifact `15249606947`, ZIP `3d89344569f498cf2ad21afa0d3e61d25e256abe3d9dbbdf15b0cff172665a6f`, source `abe40f6a16e353b25a44a1eafce8f7e46aaee0cb`, root SHA256SUMS `93e75e95f696371cffcbc92c67883879429b7ac55611cc03ec76c941ac11e008`, source archive `dce0391a635cf41166555c9f6b6b217667082773134a49b052c762ec0aad824d`. |
| Request | Commit `f62bec70ea73f00d8fdb4428aa5d897ea54181cb`, `agent-dispatch-request.json` with operation `test_benchmark`, request_id and mailbox `m6-cp3-tb193-exec`, artifact prefix `m6-cp3-tb193`, request sha256 `032e3b0f3b0a34b7ba32a7bc5ebb10b26466d514151667ba28bbbc68a79b14bd`. Shape follows the TB-EXEC-192 request (commit `8f4536c91`). |
| Run | [Run 46110979697](https://github.com/akashskypatel/Directional/actions/runs/46110979697), attempt 1; test_benchmark/runtime job `140874335388`, mailbox publish green. Compile, noop and drive_apply skipped. Mailbox record on `workflow-mailbox`: event sha `f62bec70…`, source sha `abe40f6a…`, key `m6-cp3-tb193-exec`, result success. |
| Result | Artifact `m6-cp3-tb193-result-46110979697`, id `15250401219`, 1,865,029 bytes, expiry `2026-12-12T05:37:58Z`; ZIP SHA-256 `c771dab68abfd32a57e66cb236d5a8d618c124cb3040d0e388e12eb9614daa7b` (equal to the mailbox digest). |

Checks:
- SHA256SUMS: 2034/2034 entries verified, no missing, mismatched, uncovered or extra files. This follows the TB192 convention (TB192: 2028 entries, reference 2024).
- Verdicts: 1013/1013 PASS, exit 0, run 1 for every row. Ledger `log_sha256` equals the sha256 of each `raw/N.log`.
- Execution boundary: planned, executed and passed 1013; red, abnormal, missing, skipped, duplicate, control_bad, unexpected_pass, later_positive_red and red_site_bad all 0; postflight true.
- Membership: 1094 = 1013 GATED + 81 DEFERRED. The identities of rows 1–1010 match TB192 with no differences.

Comparator. The N1–N3 comparison used an out-of-repo script (not committed). N1 is GoogleTest elapsed-time fields, N2 is CRLF conversion, N3 is fragment record ordering, as described in the TB192 record. Calibration: the script reproduces the published TB192-vs-TB191 result exactly, 770 identical, 237 N1, 0 N3, 0 different over the 1007 inherited rows other than 858. TB191 result `15179335926` (ZIP `bab546af…`) was used.

TB193-vs-TB192, rows 1–1010, row 858 included:
- 586 identical, 424 N1 (elapsed-time only), 0 N2-only, 0 N3, 0 different.
- Row 858: N1 only. Six lines differ, all elapsed-time fields (9196 ms vs 13819 ms). Equal under N1, as the contract requires.
- The 27 sphere rows (380, 388, 393, 394, 396, 397, 644, 645, 648, 669, 686, 691, 693, 694, 698, 699, 700, 843, 844, 858, 963, 968, 971, 972, 978, 979, 1006) are all N1. None are different.
- The 13 named controls: 12 are N1 (393, 648, 669, 843, 844, 963, 968, 971, 972, 978, 979, 1006); 1005 is identical.

New rows (all PASS, each runs its single test):

| Row | Identity | Raw-log SHA-256 |
|---|---|---|
| 1011 | `FieldAlignedCurveNetwork.CandidateArrivalClassificationRequiresExactlyOnePortSlot` | `a900a9fd21bfd41d2431a20fa9ea7fceddcd085d08252c4d0ade18a1a4e8e5c6` |
| 1012 | `FieldAlignedCurveNetwork.PrescribedSphereClaimedCoTraceDeletionKeepsOneTracePerSeparatrix` | `2ab9ea185d24f752ecdfd435dc366191b0a6bc7584ffb7c2ee7d1d4a2f1e4db7` |
| 1013 | `FieldAlignedCurveNetwork.PrescribedSphereClaimedCoTraceDeletionRejectsInadmissibleClaims` | `a83d053f159e2bcd0704ab200c488b08215f944502cd47c2317b40759d259371` |

Row 1012 PASS means the EE3 sphere deletion prediction holds with the option on: 24 ports, 14 traces, the 10 `arrivalPort` assignments, every port owned once. Row 1013 PASS covers the five rejection conditions.

## Recommendation

No gate credit before `M6-CP3-TB-REV-193`. The deletion option stays off in production; it is on only in rows 1012/1013. No V5, no promotion of CP3, 497, D0 or H4. Next: `M6-CP3-TB-REV-193` (runtime-free independent review), then the co-trace deletion switch DEFN (27-row premise census), then corners DEFN and O52.
