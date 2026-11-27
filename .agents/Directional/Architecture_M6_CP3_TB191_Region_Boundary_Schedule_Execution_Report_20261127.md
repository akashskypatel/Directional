# TB-EXEC-191 — Region boundary schedule execution (2026-11-27 UTC)

## Situation

The frozen 1008-row gate on CB-214 passed in one execution. The 16 added row858 records match the recorded predictions. The result awaits independent `M6-CP3-TB-REV-191` adjudication. This execution does not activate the schedule or establish a produced sphere, a filled region, or checkpoint acceptance.

## Background — exact authority

- [Frozen manifest](gates/Architecture_M6_CP3_CB214_TB191_Region_Boundary_Schedule_Exact_Manifest.md); [CB-214 compile record](Architecture_M6_CP3_CB214_P13_Region_Boundary_Schedule_Code_Build_Record_20261127.md). Source and executor `9ed5560822ae435e55101206dcb6ecda59bca706`; compile run `45949296543`, candidate `15175464398`. ZIP `d53298314ab80c89e2fd9e8891b8883b798f4d6e9029acf5e3b177070eba108b`, root manifest `eafa93881c9bfb5e5add286d616a7ec3af1b2d181945a0fba35138109e04ebb9`, source archive `819b4dbf457c575430dc271edd2e3536ae957445c8ce4c4cd093bdf8e9c98236`. 28/28 checks, six executable modes 755 verified on extraction. Build boundary `runtimeExecution=false`.
- Unchanged harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`. Exact manifest `ca16b66da3cb52e77a3540c79f9357e3e9e59b211bae872f87d58f60c4434081`; header and first 1006 rows `a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587`; CP2 header +491 rows `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`; deferred ledger `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81).
- [Run 45954607872](https://github.com/akashskypatel/Directional/actions/runs/45954607872), runtime job `140358236355`, attempt 1; dispatch `2833ca37305c9d8bda245d7b737a5288ce440de8`, request SHA-256 `be8a9c58bb521d75f7386a6f51594c9c2706a6ae38342728e3852f3d5454ae0c`, mailbox `m6-cp3-tb191-exec` on `workflow-mailbox`. Source, event, request and artifact identities match. Both workflow validators, parse, runtime and mailbox succeed. Compile, drive_apply and noop skipped. Wrapper 06:52:28–07:08:44 UTC (976 s), exit0. No retry, rebuild, V5 or local product execution.
- Snapshot run `45954502514`, job `140357789715`, source `80ef29646551ebc25edf103a5d6d90aab2fadd01`, artifact `15177803551`, ZIP `2e2c176065fbcf7204ef13529e0ed56de06f8bef8132b64b17f264798fce33bf`, archive `3ea455aec868c082a802dac0c6efafaa55b5b8bb77843e46bb5e5ccd5de39319`, 5883/5883 checks. Cleanup run `45954720321`, job `140358508719`, result `15178750108` ZIP `67c378a051146802b06c5b827a31fc0df8224f8acaa07a0b15d4a380d5244f8d`, commit `723e7fd5d97b6139d7befd4906f0eb6112a6912e` removed the temporary marker and cleanup manifest only. No PR comments deleted. The snapshot was reused after comparison to resume commit `a13f96a4485c4b6798a86cd6e961057b999e2758`: only STATUS, request, removed snapshot marker, and continuation record changed. Prior continuation preserved at commit `2aa84c64bff9e118341842c32de3fc64c0ddc918` and superseded by this report.

## Assessment — execution and comparison

| Artifact | ID | ZIP SHA-256 |
|---|---|---|
| Result | 15179335926 | `bab546af9cc089db9deb405ede41b3dd859b9e4547f81507d669c58c911bb519` |
| Harness log | 15179440341 | `af88f6bd402065cde9d4ef1ad5b4699e42319da5ed8697e7e0f78a401d8cb14b` |
| Wrapper log | 15178519098 | `cfac2654e344b7eccf56992d0ff1b2d5c17a8ce9d0cc570ce2e0f308af705d1b` |
| TB189 reference result | 15171482516 | `9cf3decbf3dea3a11aa645ec5d5db12307508e73611f962d65c78862ec9b70da` |

All ZIP hashes match; 2024/2024 current checks and 2020/2020 reference checks pass. Membership is exactly 1089 = 1008 gated + 81 deferred across five binaries. The only added membership identities are the two frozen GUARD rows. Membership SHA-256 `90ce5fa167e39655c37ca19d865d31bfa546b830c8f2e69a4a7daf6dd76576aa`; ledger `781d9a2d5e915f023d8ddc0457445e98f1e160b7a2a272e311c4c607791ef985`; boundary `043330cdff0552a6e68ce331718b19a7fe4fe891cd8f909f0a15adda65d85ebc`. All 1008 ordered manifest/ledger identities, raw hashes, single-test envelopes, resource command identities and exits, and ordered harness receipts match. 998 GUARD and 10 POSITIVE; CP2 491/491. All 1008 pass; zero RED, abnormal, missing, skipped, duplicate, control_bad, unexpected_pass, later_positive_red, red_site_bad. Postflight true, exit0. Configure, compile, relink and benchmark false.

All inherited ledger fields except raw-log hash match TB189. Of the 1005 rows other than 858: 766 byte-identical, 239 N1/N2-equal, zero material differences. N1 removes only elapsed GoogleTest summary fields; N2 converts CRLF to LF. An equivalent narrow normalizer passed elapsed/CRLF and semantic/non-summary controls. N3 was not needed. All 13 named controls (393, 648, 669, 843, 844, 963, 968, 971, 972, 978, 979, 1005, 1006) match under N1/N2. Row858: exact prefix 76578 B through the last old SphereAuditedBridge record (`sourceArc=95 curve=-1`), SHA-256 `a54805755d62dc9d691cc24d3f094a69f22c6a9453f6587885ad7609c80bdc74`. Raw TB189 `5edee978137edad1bb5c992a3b0724babcba1131873bafc5576afab074d329d5`; raw TB191 `2a0611f283c8ab32c6356fdbb8d7a593f182222125d022e1d2cc5a64e43b5540`. Exactly 16 added records in the frozen order, then N1/N2-equal suffix. Row858 PASS, exit0, GoogleTest 9.151 s. Previous failure and fallback receipts remain unchanged.

### Row858 — verbatim added records

```text
SphereRegionBoundarySchedules built=1 regions=14 sides=60 arcs=30 pairedArcs=30 otherArcs=0
SphereRegionBoundarySchedule region=0 sides=4 boundaryCount=132 even=1 counts=30,35,35,32, nodes=12,0,17,5,
SphereRegionBoundarySchedule region=1 sides=6 boundaryCount=124 even=1 counts=30,1,31,31,1,30, nodes=0,12,1,9,2,13,
SphereRegionBoundarySchedule region=2 sides=4 boundaryCount=66 even=1 counts=1,32,1,32, nodes=1,12,5,14,
SphereRegionBoundarySchedule region=3 sides=4 boundaryCount=132 even=1 counts=30,32,35,35, nodes=0,13,6,4,
SphereRegionBoundarySchedule region=4 sides=4 boundaryCount=66 even=1 counts=1,32,1,32, nodes=13,2,15,6,
SphereRegionBoundarySchedule region=5 sides=3 boundaryCount=72 even=1 counts=35,35,2, nodes=17,0,4,
SphereRegionBoundarySchedule region=6 sides=5 boundaryCount=142 even=1 counts=35,35,2,35,35, nodes=8,1,16,3,2,
SphereRegionBoundarySchedule region=7 sides=4 boundaryCount=132 even=1 counts=35,35,31,31, nodes=1,8,2,9,
SphereRegionBoundarySchedule region=8 sides=4 boundaryCount=132 even=1 counts=32,30,35,35, nodes=1,14,7,16,
SphereRegionBoundarySchedule region=9 sides=4 boundaryCount=132 even=1 counts=32,35,35,30, nodes=15,2,3,7,
SphereRegionBoundarySchedule region=10 sides=3 boundaryCount=72 even=1 counts=2,35,35, nodes=3,16,7,
SphereRegionBoundarySchedule region=11 sides=5 boundaryCount=142 even=1 counts=35,35,35,35,2, nodes=4,6,10,5,17,
SphereRegionBoundarySchedule region=12 sides=4 boundaryCount=132 even=1 counts=35,35,31,31, nodes=5,10,6,11,
SphereRegionBoundarySchedule region=13 sides=6 boundaryCount=124 even=1 counts=31,31,1,30,30,1, nodes=5,11,6,15,7,14,
GenusRegionBoundarySchedules built=1 regions=14 sides=184 arcs=92 pairedArcs=92 otherArcs=0
```

All 14 sphere regions have the predicted side count; every span count is positive, each total is the sum of the counts, and every total is even. The genus_two record reports 14 regions, 184 sides, 92 paired arcs and zero other arcs. Rows 1007/1008 pass the frozen binding and rejection tests; raw SHA-256 `11bf6c8b6a8bdf9092f113e0d20f3e805c4d71605e70b0b1448475bdd2e8a042` and `47911c1339e8f97763dc04bebd45a0aa890e0ab26fd38195b893a24df2718bcb`. These are measurements of the schedule on the retained plan, not proof of actual A4 producer calls or disc fill. Regions 5 and 10 still have three walk nodes. The A4D5 corner question remains open.

### Regression disposition

No new accepted-green loss or unexpected material log difference. No new stable event, category or recurrence. Stable 67/17/50, debt1/deferred81. O50 remains non-stable duplicate lookup debt; this gate does not compare the two implementation paths for all arcs. B1 remains held: the unchanged negative display witness preserves its known original-node repetition in cell164. B2 is unmeasured here; V5 was not rerun. No new claim of its cause, no promotion of CP3/497/D0/H4. Last independently accepted test gate remains TB189 1006/1006 and CP2 491/491. No production acceptance.

## Recommendation — TB-REV-191 only

Independently reopen CB-214 package, TB191 results and TB189 comparator. Recompute the exact membership, all row verdicts, frozen N1–N3 comparisons and 16 predicted records. Check that the binding/rejection tests measure the frozen contract, and that the report does not imply a produced sphere or a validated disc fill. If accepted, the corners DEFN (A4D5) follows under repository authority. No runtime, repair, new source or test edit, B1/fallback repair, dispatch/veto change, CB-207D or checkpoint promotion in this execution turn. Preserve existing held and carried work.

Process limits: initial document inspection preceded the verified snapshot in the first attempt. The external turn-based coding skill was inaccessible. Full mandatory preliminary policy and LESSONS review and exact historical tool-call ledger are not established. The local equivalent N1/N2 normalizer was checked against positive and negative controls, not recovered byte-for-byte from an earlier agent. The document audit is a static check, not independent semantic acceptance.
