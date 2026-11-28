# M6-CP3-TB-REV-195 — independent corner-side review (2026-11-28 UTC)

## Situation

Accept the immutable 1015-row test gate and CR1–CR4 for the pinned witness only. DD5 is independently confirmed: six of eight certified sphere discs have unequal opposite-side subdivisions. The two equal-side narrow discs remain O52 quality items. The genus typed unsupported-arc-kind refusal is allowed. The corner producer is not wired to production; no general A4 construction, CP3, 497, D0, H4, V5 or production acceptance. No successor execution.

## Background — immutable authority

| Artifact | ID | SHA-256 of ZIP | Verified manifest |
|---|---:|---|---:|
| CB-220 | 15257943465 | `eb7e5ea11cb129c9d0ff33931967cf9bcf7227a831ff9af59014f44f9faa4f71` | 28/28 |
| TB195 | 15259492817 | `f2fb104ac182cc24f1f8d6f68116eeb0fcb6d0e95f166c73d6a322aadd8f2a4b` | 2038/2038 |
| TB194 | 15255025606 | `5fedd54ddf3416bf1cdb475a8e53206ab6382fcd75e9ea8b4a3bfebb4f8d99b4` | 2034/2034 |

CB-220 source/executor `e55f01b9ac86e2dc0159771a45521cb6f35049be`, run `46131427922`; TB195 run `46134852307`. TB194 source/executor `26eef1ce54b7b311cbf1cedf597ee0c106be52c2`, candidate `15252943713`, run `46122222893`. CB-220 package has empty source status, eight targets and GMP/GMPXX linkage evidence, runtimeExecution=false. Reversed and reapplied exact CB-220 diff `35a164a8b4490ae1e6ab29f480745d49f8bbd0f79db84c0334d94f87bb7141fa` in a scratch copy; all four preimages and postimages match. Harness hash `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`. Source snapshot `cf373ace9722c30d0f4dc0e3090829df14e02f56`, run `46138272279`, artifact `15261185021`, ZIP `43fe65f7490976ca315e5b1438b78a89cae1317abf424766d53c158fbf04431d`, source archive `b0caa06c6a776b306d8b83344a847d31321d34d15844a4d6f1169000c78adf6a`, 5914/5914 checks. GitHub compare from CB-220 source to snapshot: ahead 26, behind 0; only documentation/control state, no source, test, build or selector change.

[Execution report](Architecture_M6_CP3_TB195_Region_Corner_Sides_Execution_Report_20261128.md), [frozen manifest](gates/Architecture_M6_CP3_CB220_TB195_Region_Corner_Sides_Exact_Manifest.md), [corners definition](Architecture_M6_CP3_DEFN_P13_A4_Disc_Corners_20261128.md) and [FF1–FF4](Architecture_M6_CP3_TB_REV_194_Adversarial_Review_20261128.md) govern this review.

## Assessment — independent checks

### Gate identity and non-vacuity

Recomputed SHA-256 on raw manifest header plus each prefix:

| Rows | SHA-256 |
|---:|---|
| 491 | `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038` |
| 993 | `82581dd14064efe3729923cfd94333ef70113b0bb84e6bb8eabfb2ec61cce436` |
| 1008 | `ca16b66da3cb52e77a3540c79f9357e3e9e59b211bae872f87d58f60c4434081` |
| 1010 | `c9f6325eee41ebead3d516d3bfcbef3141c9dee8c7051cef1e08ad146f60e9f5` |
| 1013 | `b910f2a96626660f46042c34360a8062c7546f35fb1980432d038ba8f41d2fc2` |
| 1015 | `34a4e86406f043739c56eec6bc104615bee05fc08960be2dc6ae4a303b43b821` |

Deferred ledger `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`. Independently joined ordered manifest and ledger, membership and per-row log/resource identities in each result. All binary/test/filter identities match; exactly one RUN/OK/PASSED and exit 0 per selected test, raw hashes match, no missing or duplicate membership, all failure counters zero, postflight true. TB195 1005 GUARD + 10 POSITIVE = 1015; 1015 gated + 81 deferred = 1096. TB194 1013 + 81 = 1094. No configure, build, relink or benchmark. Inherited non-log-hash ledger fields equal. 785 exact logs, 226 N1/N2 (only GoogleTest timing and CRLF), one N3 at row164 (six complete projection records compared as counted records, ordered remainder equal). All 1012 inherited comparisons outside row858 match. Row858 exact 448-line prefix and ten-line insertion through the final genus receipt; suffix N1/N2 equal. Insertion SHA-256 `5d096f44135ab1d0d83190f2df5360abca1cac8caf96a4add92edecfe3568e00`; TB194 raw `cff825fdb84885fb9c54389b389dde882060247bab99be351199989af3707c63`, TB195 raw `cdab60c113fdfa7ef6521b950b414c213f6d4285b8bc88268dc528a4cb646568`.

CR1/CR2: `RegionCornerSides.cpp` calculates flat trace continuations from adjacent segment ranges, singular sector gaps from port ordinals, and transverse T-node corners from different trace identities at degree three. The plan face successor is the clockwise predecessor of the reversed incoming arc (`EmbeddedGraphTopology.cpp:3370–3389`); port slots are counter-clockwise (`FieldTransportAtlas.cpp:965–1057`). The positive guard 1014 requires all eight regions, the exact corner identities and side counts, the exact four flat intermediate nodes and complete occurrence coverage. A no-op or wrong side grouping fails. Guard 1015 reverses region 0 and requires TurningNotFourQuarterTurns, the affected region and no side product. Reversal replaces three gap-1 singular corners by gap-2 sectors; the T-node remains gap 1, giving turning sum 1 instead of 4. Both guards pass. No production call site: only definition, declaration and display-test calls. This is not proof for arbitrary mutable schedule vectors, arbitrary arc-interior turning, mandatory/cut arcs or other contact classes. The documented segment-range approximation and validated A3 input assumption remain; fail closed on unsupported kinds. A future consumer must bind the validated producer schedule. No source change is justified by this pinned evidence.

### CR3 and DD5 — independently derived boundary table

Using the TB194 ordered schedule walks, identify corners using the accepted trace/port rule, aggregate counts between them, and compare with each TB195 new receipt. Every region agrees. The intermediate flat nodes are 8,9 in region 1 and 10,11 in region 7. All corner gaps are 1. All eight certificates are disc and interiorSingularityFree.

| Region | Ordered corners | Side counts | Boundary total | Opposite equal |
|---:|---|---|---:|---|
| 0 | 8,0,4,5 | 30,35,35,32 | 132 | no |
| 1 | 0,1,3,2 | 31,35,35,31 | 132 | no |
| 2 | 1,8,5,10 | 1,32,1,32 | 66 | yes |
| 3 | 0,9,6,4 | 30,32,35,35 | 132 | no |
| 4 | 9,2,11,6 | 1,32,1,32 | 66 | yes |
| 5 | 1,10,7,3 | 32,30,35,35 | 132 | no |
| 6 | 11,2,3,7 | 32,35,35,30 | 132 | no |
| 7 | 4,6,7,5 | 35,31,31,35 | 132 | no |

Reconstructed V12/E18/F8, Euler 2, 36 uses, all 18 undirected arcs have precisely two opposite uses with identical positive counts. Each walk is simple and every sum is even. These are boundary/topology conditions, not a completed mesh. A rectangular tensor grid requires equal opposite subdivisions; it cannot satisfy six of these schedules unchanged. This does not disprove a general quadrangulation. Genus unsupported-arc-kind matches the explicit manifest allowance, not general genus acceptance. O52 2/4 equal-side slivers are quality only (FF3); no deletion. D7 counts are validator-backed measured A3 values, not a separately rederived metric oracle (FF2 supersedes earlier AA2 STOP). Do not manipulate counts to fit a grid. CR4 authorizes the next definition, not implementation.

### Prior obligations and scope

FF1 wrong TB194 count/projection predictions remain adjudicated, not new product failures; FF2 D7 numerical re-derivation remains a separate nonblocking oracle, requiring exact supports and metric/parity inputs; FF3 O52 remains M7/O23 quality; FF4/DD5 confirmed above. O51 pinned trace ownership accepted, row971 defect discharged for pinned contract, O50 open pending 65D. B1 legacy fallback held, B2/V5 resource cause unmeasured; no B2 cost inference from selected tests. J6, O42/O43, S4/S6/S7/W6, chain switch, parameter deletion → V3b → R1 → O48, CB-207D remain held as in tracker. No accepted-green loss, new stable event or new regression candidate. Stable 67/17/50, debt1/deferred81; CP2 491/491. V5 Cylinder PASS, Vase RED, BunnyRandom timeout remains the prior evidence, not re-executed.

## Recommendation — exactly one successor, not started

`M6-CP3-DEFN-P13-A4-UNEQUAL-SIDE-CONSTRUCTION` after formal closeout. Definition only: establish a general constructive A4 contract for unequal opposite-side counts on certified four-corner discs, without changing the A3 count schedule or CR1 corner ownership. Require exact boundary occurrence preservation, reciprocal interval ownership, pure-quad disk topology, orientation and index constraints, and typed refusal for unsupported cases. Freeze independent positive/negative falsifiers before any CB: a required occurrence/count lost or changed, mismatched reciprocal use, invalid orientation/disk/index, or a supposed construction not proved for its stated domain. STOP on missing/inconsistent authority, no construction proof, failed constraints or normative choice requiring owner approval. No implementation, runtime, Vase row, production activation, A3 count edits, O52 deletion, fallback repair, dispatch/veto change or checkpoint promotion in the definition. Preserve D7 as independent nonblocking oracle. The handoff and TODO contain the same bounded next turn.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | All six exact hashes above; predecessor 1013 and CP2 prefix unchanged. |
| Decisive claims independently re-derived | Three archives, manifest/ledger/raw membership and logs, 1012 comparisons, exact row858 insertion, graph/count table and source binding. |
| Non-vacuity checked | CR1/CR2 exact positive and reverse orientation negative guards; no-op, changed grouping or wrong orientation would fail. |
| Prior obligations discharged/carried | FF1–FF4, O51/O52/O50, D7, B1/B2 and parked work above. |
| Stable accounting | 67/17/50, debt1/deferred81; CP2 491/491; 1015 pinned test gate only. |
| New candidates/obligations recorded | None new; DD5 owner and falsifiers, D7 nonblocking obligation and O52 quality updated in tracker. |
| ORIENTATION currency line | TB-REV-195, 2026-11-28 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 gate authority, §4 witness, §7 successor and O52/D7 current state updated; §8 unchanged, no new defect pattern. |
| CHANGELOG | Added one independent review entry. |
| ROADMAP | Current gate and next definition updated, no milestone/checkpoint transition. |
| Selector manifest | Additive acceptance note only; no frozen case or selector bytes changed. |
| LESSONS | Existing evidence/prediction/non-vacuity lessons apply; no duplicate lesson. |
| Consolidation under CLEAN_UP_POLICY | Consumed disc-corners entry plan folded in full with original hash and source SHA into Vol D3, link repairs; FF2/FF3 supersession explicit. Current CB220/TB195 and TB194 comparator authority retained. |
| Successor frozen | M6-CP3-DEFN-P13-A4-UNEQUAL-SIDE-CONSTRUCTION; falsifiers and STOP rules in recommendation. |
| Turn boundary held | Runtime-free; documentation only. No product/test/fixture/benchmark/selector/build mutation. |
| review_check.py boundary | Exit 1 on four historical Git-object checks (8b7299b43 ancestor and three historical blobs unavailable in snapshot-only local Git); no product/test/build/selector failure. Snapshot and exact GitHub comparison establish current preimages. Prior review verified historic ancestry/headings; current edits preserve headings. Do not claim script PASS. Drift audit exit0: 0 errors, one inherited orientation size warning and three protected navigation changes authorized by the owner’s current request and mandatory review duties. |
| STATUS lifecycle maintained | Entry IN_PROGRESS, started 2026-11-28T11:05:03Z; final direct write after verified durable push/cleanup. Root STATUS controls formal closeout. |
| Pushed to origin, branch in sync | Dispatcher push receipt and branch/postimage verification required before final STATUS; local snapshot has no origin-tracking branch. No claim that local git status proves remote sync. |
