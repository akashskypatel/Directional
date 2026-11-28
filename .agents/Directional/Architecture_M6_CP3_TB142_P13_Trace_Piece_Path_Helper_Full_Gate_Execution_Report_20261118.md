# TB142 trace-piece path helper full gate — MATCH (artifact-only)

## Situation

`M6-CP3-TB142-P13-TRACE-PIECE-PATH-HELPER-FULL-GATE-EXEC` resumed 2026-11-18T23:53:38Z; original start 2026-11-18T23:29:08Z. **962/962 prior test records MATCH** TB141 under N1–N6, new row 960 PASS, gate 959/960 with the same permitted row 858 RED. This is a valid semantic comparison, not all-green production acceptance. No Test + Benchmark source, test, fixture, selector, build, benchmark, or package mutation occurred. No successor work ran.

## Background — immutable authority

- Branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 open/draft/unmerged. [CB167 Code + Build record](Architecture_M6_CP3_CB167_P13_Trace_Piece_Path_Helper_Code_Build_Record_20261118.md) and [frozen plan](Architecture_M6_CP3_CB167_P13_Trace_Piece_Path_Helper_Plan_20261118.md).
- Immutable package `14481197196`, exact semantic source `ecc67015cc4ff28ec15c086787a9450bd585bf94`, package ZIP SHA-256 `274064da966f5a0257115c851cbc530c5f8fd9a3b1979b5d06844dab0ce1f04b`; package manifest 28/28, executable modes, clean source and GMP/GMPXX recorded and verified in preflight. Package source archive SHA-256 `5ff6a53d646336512ad74df520823216753934ecfff5835cb6b770c74d30b229`.
- Frozen gate 960 cases SHA-256 `2468d8baed76322bdda79072e54c287aa421fb627a819ba278c7f7ee77e12db0`; census three cases `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; deferred 81 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; harness `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- TB141 comparison baseline: gate result `14473040819` ZIP SHA-256 `5f53a3990d5e49ea08f1440180fb155409229c4739e7b851a4081d1a0f0a47d6`; census result `14473701160` ZIP SHA-256 `fa4afc3b5004e485d34d073e3d26b9897ffab68716203129aa3a12a5c7e86571`.
- Exact source snapshot [run 44421329962](https://github.com/akashskypatel/Directional/actions/runs/44421329962), artifact `14481842641`, ZIP SHA-256 `143096c5535e3d4e6bf22d4cf1b0178e260c53c90688f390bb999cc000d4ae6a`; 5,588 source hashes verified. Snapshot and immutable runtime package were reused from the earlier part of this chat turn.

## Assessment — actual execution

| Role | Run | Result artifact | SHA-256 of result ZIP | Execution |
|---|---:|---:|---|---|
| Gate | [44421716697](https://github.com/akashskypatel/Directional/actions/runs/44421716697) | `14482831297` | `a4352cf815bd8796bf4e2fa7e61ef900c29a034a23fa520e611872bbd385bc51` | 960/960 executed, 959 PASS, one permitted RED, exit 90 |
| Census | [44421843018](https://github.com/akashskypatel/Directional/actions/runs/44421843018) | `14482339143` | `4f245848bd9005b28fcf75d6cc66cc9a02fba9cc2fdc5ded9977f1d49b65ad64` | 3/3 executed, 1 PASS, 2 expected RED, exit 0 |

- Both runs have terminal mailbox evidence: `m6-cp3-tb142-gate-v1` and `m6-cp3-tb142-census-v1` on the isolated `workflow-mailbox` ref. Gate runtime job returned failure only because the frozen expected RED sets `control_bad=1`; both workflows reported valid postflight, no missed/skipped/duplicate/abnormal/unexpected-pass/later-positive-RED records and no build/configure/relink/benchmark flags.
- Validated SHA-256 of both result ZIPs and all 3,872 indexed internal files across TB141 gate/census and TB142 gate/census (1,926+9+1,928+9). Verified each raw log digest binds to its ledger record. Accepted prefix 491/491 PASS. Membership 960 gated + 81 deferred = 1,041.
- Exact ledger identity, verdict, selected test, exit, first-failure and reason for each prior 959 gate rows and 3 census rows match TB141. Complete logs match under **only** N1 GoogleTest time, N2 CRLF, N3 order of contiguous complete `region_support_projection` records, N4 census opaque 16-byte `GetParam` values. N5 raw `slideProposal` and N6 raw `committedSlide` lines were each retained and matched byte for byte (no N6 deletion needed). Three gate rows 172/176/179 differ only in permitted region record ordering; census rows 1–3 differ only in timings and rows 2–3 also in opaque parameter bytes. No other normalized difference.
- Full raw receipt inventories: gate 1,200 proposals and 1,200 committed, census 66 proposals and 66 committed; all match TB141 in order and bytes. This retains the TB141 count of 1,266 traversed receipts, without proof of graph publication. Known region/slide conflict evidence remains unchanged. Row 648 assertion reach unchanged and row 858 remains RED at `SurfaceCellTracingDisplayTests.cpp:155` with `faceLocus.sourceFace.has_value()` false. New row 960 `FieldAlignedCarrierOccupancy.TracePiecePathKeepsNonLastSlideAndCanonicalContactEndpoints` PASS. Cylinder is 288-quads PASS; BunnyRandom continues at trace 82 `TraceEventPositionNodeConflict` RED; Vase is still completion RED.
- Independent offline comparison was repeated against all raw evidence, not generated product tests. No new regression or candidate was observed. Stable accounting remains 66 events / 17 categories / 49 recurrences, produced-witness debt 1, deferred 81; CP2 accepted prefix 491/491, selector497 not promoted. C5/O47/O48/O49, H4 and related held work remain open. No CP3/D0 promotion.

## Recommendation and boundary

Exact successor **`M6-CP3-TB142-P13-TRACE-PIECE-PATH-HELPER-FULL-GATE-REV`** is an independent, runtime-free Review. Re-open evidence and reject false comparison matches before accepting TB142, then freeze the EC1 `carrierLocus` and (entry, entry) coincidence-count receipt exact diff per [RA-263 S3](Architecture_M6_CP3_TB141_P13_Committed_Slide_Receipt_Full_Gate_Independent_Review_20261118.md#ra-263--adversarial-re-review-of-this-review-2026-11-18-utc). Do not start EC1 implementation or any successor work in the execution turn.

Process disclosure: the first TB142 response made direct document reads before `READ_MODE=snapshot`; that error was reported in its continuation record. This resumed response reused the verified source snapshot and completed the missing census comparison without a new runtime run. Offline comparator first rejected census pointer lines because its regex expected hyphen-only separators; correcting it to the exact 16-byte space/hyphen format gave 962/962 without altering evidence or weakening comparison. The initial intermediate rejection was not runtime evidence. Exact cross-attempt tool-call total is unavailable; do not invent a count.
