# TB-EXEC-188 — activated full gate and V5 census (execution finished; review pending)

## Situation

The full gate of M6-CP3-TB-EXEC-188 is valid: 1006/1006 PASS. The frozen comparisons permit the separate V5 census, executed once. The sphere completion receipt identifies boundary parity repair rejection; no produced sphere or independent activation acceptance is established. Do not repeat either dispatch. Independent review follows formal execution closeout.

## Background

- [Frozen CB-210/TB188 contract](gates/Architecture_M6_CP3_CB210_TB188_Completion_Receipt_Activated_Full_Gate_Exact_Manifest.md). Source `0409304d6f9f423685ccddc26b19baf4e41ea61e`, package `15162357312`, ZIP SHA-256 `9aa9f28b3830275c6eb6b1bb712126094976e9556abcfe61d7921b2ed91bd74a`; root manifest `2522abfe0e6e698b116c6abdee5496bf172107a5e5c4bd67729a9837e52c04cc`; source archive `693ba0bd522aee5fe690322c958919e1082d3d15e42f014418fd1880eee72ac3`.
- Executor `cc25a6402cdd3ca1a33a9a9778250176b182bb2a`, harness SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`. Frozen case manifest `a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587`, deferred ledger `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`. No selector, package, implementation, test, fixture, harness or workflow-definition change.
- Gate [run 45918483650](https://github.com/akashskypatel/Directional/actions/runs/45918483650), runtime job `140243405720`, dispatch `7695f7af26e9de6dccbd928f614c4be5e86310a9`, request SHA-256 `3b737fc286a11be86226045124c728a33f671e886be5930cd68432b01284fd42`. Mailbox `m6-cp3-tb188-exec` on `workflow-mailbox` matches event/source and attempt 1. Validators, parse, runtime, mailbox success; compile, Drive apply, noop skipped.
- Snapshot [run 45918284177](https://github.com/akashskypatel/Directional/actions/runs/45918284177), job `140242720777`, source `2e2a6222062ede749e6735e85fbb39fb4fecb08f`, artifact `15162759446`, ZIP `0756e4f6a8c4e0139ea4964bd989e7fee39db30a508d2c2f256b1856e848436a`, archive `00a6db692da0654fec0b60063889157293d8ab1d52bf61af4fea2d558e7fea47`, 5867/5867 file checks. Compare to V5 dispatch `27723a4547b3bddd95fa5fd00b369278abb07228`: eight commits ahead, zero behind; only report, request, STATUS, and removed snapshot trigger differ. Prior cleanup [run 45918563067](https://github.com/akashskypatel/Directional/actions/runs/45918563067), commit `72d88f10aa80e68581ab2f629d03ec004f0d101c`, removed only snapshot trigger and cleanup manifest.

## Assessment — full gate

| Artifact | ID | ZIP SHA-256 |
|---|---|---|
| Result | 15163822727 | `59957c5adbb95a5e5a90f1eada11f3aec60366ee3a8c22694edf8de799293780` |
| Harness log | 15163812600 | `608a3c0a707d5a79de64e1037e41ac021a8d575d296300048bb9b40e4ff99c52` |
| Wrapper log | 15163847561 | `117962b98fe9b24253509bc5c9fc5287e96f920c04480881f4ac2efc77d0123e` |

All three outer hashes match the mailbox. Exact ZIP inventory, 2020/2020 member checks, 1006 ordered manifest, ledger, raw-log hashes, organic single-test envelopes, resource exits and ordered harness receipts verified. Membership 1087 = 1006 gated + 81 deferred, byte-identical to TB186, SHA-256 `29f997463824520bb66544ac9b33830067013366328cb63e7ccc301bc40b54f9`. Ledger `79e852715c67943cd5321a8a565e5f6db95b016e27587d38453d18fed556ee40`; boundary `5cfa69648fe7df3dc8dc97a6b7031d535b551974656b6e2231fdaea1c0d2dc27`. CP2 491/491 PASS. Planned/executed/PASS 1006, zero RED, abnormal, missing, skipped, duplicate, control_bad, unexpected_pass, later_positive_red, red_site_bad. Postflight true, exit0, compile/relink/configure/benchmark false. Wrapper confirms exact executor, harness, source, and request; harness exit0, 00:44:52–01:04:58 UTC. No runtime executed locally.

### Frozen comparisons

Prior result archives TB186 `15155787349` ZIP `ee1e603907561d773034c9e48fd76fa2d1e8fe6273ace85f9425f5bf557f76fa`, TB185V `15066180913` ZIP `16983f7e40ac9f5934b3a50ffd556925d582e857e41aaf34aae8f5fb3b181082`, TB187Q `15130286146` ZIP `a3fb3a89a3dd72ccc2870412fd0d6e78af4921943d7f491c4735443264de8ecc`: each exact inventory and 2020/2020 checks. Preactivation comparators equal (738 exact, 268 N1/N2), 1614 region records each.

| Comparator | Exact | N1/N2 | N3 | Material | Ledger changes |
|---|---:|---:|---:|---|---|
| TB186 | 623 | 380 | 1 | 858,971 | 971 only |
| TB185V | 653 | 327 | 0 | 26 | none |
| TB187Q | 651 | 329 | 0 | 26 | none |

N1 elapsed GoogleTest fields only; N2 CRLF; N3 exact multiset of complete region projection records plus ordered residual. Reused prior normalizer and its positive/negative controls; no new normalization. Region records 2902→2902 vs TB186, 1614→2902 vs both preactivation comparators. Same 26 material row identities against each: 380,388,393,394,396,397,644,645,648,669,686,691,694,698,699,700,843,844,858,963,968,971,972,978,979,1006. All other rows N1–N3 equal to TB186; hence all controls including 393,669,843,844,963,968,972,978,1005 unchanged. Explicit 648,979 and 11 row1006 receipts independently checked against frozen predictions, including the unstaged controls; row1006 receipt hash `d8407bea068c219f04c785fc2701e0a82093c9b8220514d3786c84869f4ca00c`. All complete changed-line diffs and raw logs preserved for Review.

### Row971 — PASS, cross-representation arc/ray test

Raw SHA-256 `4ca35bee1919f600b6d9edb49775f7b7bb65f9771f2e84c2451db5eb2bd8df5a`. Organic exit0, 22.244 s GoogleTest time. Only prior six failed assertions and failed envelope replaced by new receipts and PASS envelope; all preceding bytes N1/N2 equal. Exact oracle assertions pass: 10 distinct source slide identities, 6 whole + 4 face/edge prefix + 4 edge-only suffix occurrences, exact endpoints, source supports, terminal/interior roles, cut-node fraction and both orientations per split. The test pins contact values from earlier cross-representation witnesses; it does not independently derive geometric contact parameters. Receipt:

```text
SpherePieceRayReceipt vertexRays=34 alongEdge=10 inWedge=24 edgeRays=16 alongLocusEdge=8 intoFace=8 changedVertexParameter=0 changedOrdinary=0 failures=0 coincidentAlongEdge=0 coincidentWithEdgeArc=0
```

Four split wall traces 0:6 edge6-8, 1:6 edge16-21, 21:6 edge33-34, 22:6 edge45-46 each report both Forward and Reverse along-locus rays, toward opposite endpoints (8 total). All 10 vertex-end receipts for traces 0,1,9,10,11,12,13,14,21,22 are present; 18 ray lines and 10 slide-end lines independently counted and checked. Complete exact ray lines are in raw/971.log and the comparison evidence. Prior non-stable test-authority defect correction measured, independent disposition pending.

### Row858 — PASS, new exact completion predicate receipt

Raw SHA-256 `4c53c20b7c24095e3c1f3386516b52e9bc9f9b9a6599a319ffa4cda08032361f`. Exact 69196-byte prefix SHA-256 `32d6de52259ed91a9968109bda21b68d3dc4d37a3b1aed7b59193301c61a42d9`; same detail line, PASS suffix N1/N2 equal after removal of precisely one new receipt.

```text
SphereDisplayStop stage=completion code=NotProductionReady sourceFace=- relatedSourceFace=- sourceEdge=- sourceVertex=-
SphereDisplayStopDetail detail=PreparationRejected firstInvalidStage= firstInvalidReason=
SphereCompletionFailure detail=BoundaryParityRepair:InvalidReplacementBoundary:repeated-boundary-node;AlternativeRepairBudgetExhausted;attempted=106;budget=106
```

This is a measured boundary parity repair failure at replacement boundary validation, not a proved causal diagnosis of the repeated node or justification for increasing the budget. No produced sphere or new stable event. Retain independent review to choose the next completion measure.

## V5 — terminal evidence, not accepted

[Run 45920872749](https://github.com/akashskypatel/Directional/actions/runs/45920872749), job 140251189913, event `27723a4547b3bddd95fa5fd00b369278abb07228`, request `0f5769d89b0881ea8ad2fb09aece6872f636fff3b74407bad7b7f8c8e0ec38b1`, exact mailbox/source/executor match. Result 15165185584 ZIP SHA-256 `088d7ba4f2b0daee8c7eaeb14479052d77796affa9d2c30d180b2810c4a2cacb`; harness 15164960868, wrapper 15165690015. All three outer digests match; 9/9 result checks. Prior TB161 14741883606, 9/9. Exact three OBSERVE identities, no membership.

- Cylinder PASS, 288 faces, N1/N2 equal; 8.65→10.64 s.
- BunnyRandom RED→ABNORMAL, exit124, `HARNESS_TIMEOUT 600s`, no terminal verdict or resource receipt. Prior 325.23 s RED: RotationSystemInconsistent / TraceEventPositionNodeConflict trace82, face (21,72,273). Both pending contacts recorded with identical stop attributes: 142:2→87:0 2 vs prior3, 26:1→99:0 3 vs prior3. No InvalidNetworkBinding or struck-index rejection in captured bytes; no final-state proof. New runtime candidate, cause unproved.
- Vase RED unchanged terminal AggregateCompletionValidationFailure; 200.18→252.30 s. N1/N2 difference only two opaque GetParam object renderings.

Postflight true, harness exit0, planned/executed3, PASS1 RED1 ABNORMAL1. The prior strict offline verifier rejected missing resource evidence; retain the failure, no acceptance. No rerun or timeout substitution. Preserve all raw logs and diffs. No V5 gate credit.

## Recommendation

Finish execution documentation, then TB-REV-188 independently adjudicates full gate and V5 timeout, not acceptance. Stable 67/17/50, debt1/deferred81. No CP3/497/D0/H4 promotion, CB-207D, or fine-resolution close_sheets proof. Initial policy-read ordering and unavailable external skill remain procedural deviations; cumulative tool ledger incomplete.
