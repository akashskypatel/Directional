# TB139 P13 slide-contact helpers — independent review (MATCH)

## Situation

`M6-CP3-TB139-P13-SLIDE-CONTACT-HELPERS-FULL-GATE-REV` — 2026-11-18 UTC. **MATCH upheld for the unwired helpers and the measurement only.** 959/959 prior rows match TB138; rows 957 and 958 PASS. No product execution, source/test/selector mutation, or M6-CP3/D0 promotion. PR #8 remains open, draft and unmerged.

## Background — primary authority

[Execution report](Architecture_M6_CP3_TB139_P13_Slide_Contact_Helpers_Full_Gate_Execution_Report_20261118.md), [TB138 comparator](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb138_p13_departure_chord_classifier_switch_full_gate_execution_report_20261118md), [RA-260 S2–S4](Architecture_M6_CP3_TB138_P13_Departure_Chord_Classifier_Switch_Full_Gate_Independent_Review_20261118.md#s2--ra-257-s53-defined-a-contact-locus-inside-a-slide-or-at-an-entry), and RA-259 S3 govern. CB164 source `4d8ddfee7dfa8dc651406cfb1de816027c859df2`, package `14440134091`, ZIP SHA-256 `5b4a2c7db08cb610dfa2388b7a0e5898435a154b82da09cc61c232b4e92d6c8a`. Comparator CB161 source `f14761715004d7ddc27e032698f6540ae1a9b0c4`, package `14424780973`. Package authority comes from archived runtime preflight and compile records; no binary re-download or execution in Review.

Snapshot `bb05ce88a2649ac0367923b3b7de5f8eea87382f`, run `44351917058`, job `134969719860`, artifact `14449525553`, ZIP SHA-256 `1eb8a8c0a86d0f57d9d73b4163c1e75576070c333ca52d5047973150e7055ca0`, archive `d2c011b0084d8f4bd0d01a57fbed1ebc04be145433b5eccee5210e54b968ce2b`. All 5,573 file checksums pass. GitHub comparison from CB164 to snapshot: 24 commits ahead, zero behind, 13 changed paths, all documentation/control state; no product/test/build/gate source drift. Frozen CB162/163/164 exact diffs individually re-hash to `1a3cbb1a74dd4d071e29006b49f379b3af053a3fcc71f17609d2612c5efcb853`, `3a7f96f20eb9f9f6d8af825b7649d7bd603baa5b4007a639ceb60f9a918e67a8`, `599524c449eb04b4387ac55667ad63bfe186a70e14f03af375390a2fabecd6a5`.

| Raw result ZIP | Artifact | Verified SHA-256 |
|---|---:|---|
| TB138 gate | 14425931505 | `884cadd19104322d764c87690e53827391806ca3d56765433f7bdb7e5cf8859e` |
| TB138 census | 14425229608 | `c7b9001a718b827ad8d910e511a1e44f3618df13de44e3623097edba716e619b` |
| TB139 gate | 14444439110 | `b4fb0f44f382756b6a51e40f23955aebf6301d82f48b6dbb8d5f87c31c5a1d6e` |
| TB139 census | 14446181288 | `ac6d424e6412cc634b54e1d69d6bcf5c332a8b81ef90cdcb5c069371c3b50ca0` |

Raw ZIPs are retained in the Library archive `Directional_TB139_verified_closeout_20261118.zip` (including the TB138 baseline). Both outer manifests pass. Live mailbox records bind run `44342203557` event `0c020b4c5f5eb2c1351c0287ec9c2e8e1d59bf47` and run `44342268997` event `7318cf02eec61614999776b3573864b74fb30103` to CB164. All four candidate log ZIP hashes match their mailbox digest. See the execution report for log IDs, timestamps and exact frozen inputs. Gate manifest SHA-256 `96766f760965c01216cbe94f92f67eefcfc40bf78e17dbcd5379bee7556f2d29`, census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`, deferred `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, harness `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.

## Assessment — independent derivation

Fresh Python comparator `independent_tb139.py` verifies all four raw result ZIPs, complete case/manifest coverage, every checksum (1,920+1,924+9+9=3,862), raw log SHA-256 bindings, exact ledger identities and fields, deferred membership, and outcomes. It compares logs under N1–N5 only. N5 removes complete `FieldAlignedCurveNetwork.slideProposal` lines only after recording their fields; no deletion of other receipt bytes. Six independent offline comparator controls pass. These are parser controls, not product tests.

| Evidence | Gate | Census | Total |
|---|---:|---:|---:|
| Prior exact normalized match | 956/956 | 3/3 | 959/959 |
| New helper controls PASS | 2 | 0 | 2 |
| Other receipts byte-identical | 66 | 2 | 68 |
| Region diagnostic records | 1,738 | 0 | 1,738 |
| Seed / departure pairs | 0 | 48 | 48 |
| Vertex proposals | 0 | 3 | 3 |
| Grazing proposals | 1,200 | 15 | 1,215 |

All 961 data rows of [the count table](evidence/Architecture_M6_CP3_TB139_P13_Slide_Proposal_Counts_20261118.tsv) equal the independent counts; SHA-256 `8d21f1300a6461fcdd5ad74a692589379584c19feed9eec04c42104b4e71335c`. In every row, each seed receipt immediately follows its corresponding departure line and matches the projected trace, segment zero, face, carrier/end identity. No new departure-chord crossing lines. Gate: 958 executed, 957 PASS and one permitted RED (row 858, `apicensus:19`, `SurfaceCellTracingDisplayTests.cpp:155`), row 648 sphere assertions unreached. Zero abnormal/missing/skipped/duplicate, unexpected pass, later positive RED or wrong RED site. Membership 1,039 = 958 gated + 81 deferred. Gate exit 90 (`control_bad=1`), census exit 0, both postflight valid. Cylinder PASS/288; BunnyRandom RED at trace82 contact-cut binding conflict nodes 220/222; Vase completion RED. No production outcome changed.

**Non-vacuity.** Row 957 `FieldAlignedCarrierOccupancy.ArrivalInsideASlideAddsTheFacePieceAndTheCarrierRun` checks a unit square triangle. Independently: the entry (3/4,0) to slide start (3/8,3/8) has length 3√2/8, then to (1/2,1/2) adds √2/8; to v2 adds 5√2/8. Start arrival 2; expected 2+√2/2, 2+3√2/8, 2+√2; descending departure to 1/4 yields 2+3√2/4. The test asserts range rejection, no-slide rejection, error bound and one segment advance. A chord-only measurement, wrong direction, skipped face piece or absent range guard fails at least one assertion. `SurfaceCellTracing.cpp:5634–5663` uses both lengths in recorded order. Row 958 `FieldAlignedCarrierOccupancy.FirstCarrierContactMeetsEntriesAndSlidesAcrossFaces`: descending intervals [9/10,0], [3/10,0] first meet at 3/10 in either role; opposite-face entries at 1/3 meet exactly, 34/100 misses; crossing/slide meets at 1/2, ascending first at 7/10; disjoint and singleton endpoint meetings reject. The helper keys by carrier, checks moving entry first, and prefers wall entry on an equal-parameter tie (`:5670–5710`). A face-only or unordered interval algorithm would fail. No before-state binary was run; these are static counterexamples. The tests do not directly exercise the tie or positive overlap beginning at a vertex. RA-259 S3.3 excludes a singleton vertex meeting; RA-260 S2.6 abbreviates this as excluding parameters 0/1. Before CB168 wiring, explicitly resolve the positive-overlap-at-vertex case and freeze a control for entry/slide ties. Do not reinterpret the existing test or change the helper in this Review. This is an open definition/test obligation, not an observed stable regression, and does not impede the unwired piece helper.

**Prediction and scope.** BunnyRandom contains 3 copies each of grazing 43:11 face (60,126,290), carrier (60,290), end 290; 43:13 and 15:19 face (94,124,210), carrier (94,210), end 94. There are three repeated 22-receipt blocks (16 seed, one vertex, five grazing) in the census. These are proposals, not counts of unique or committed/published segments. The prior exact path receipt gives starts t43≈0.26324148596788688 and t15≈0.93470265131543506; (t15−t43)/t15≈0.71836873940881; earlier arrival of 43 is prior verified evidence, not a new measurement. O48 predicts a future cut at X43; TB139 does not prove that the contact is produced.

**H4 remains open.** Source inspection confirms RA-260 S1 at `EmbeddedGraphTopology.cpp:258–305,730–770,1948,2174`, `GlobalTopologyPlan.cpp:260,349`, `SurfaceCutGraph.cpp:268`, and `FieldAlignedNetworkPolylines.cpp:94`. `field_aligned_publish_contact` (`SurfaceCellTracing.cpp:4090–4170`) commits a full proposal before publishing a terminal face contact; recorded transit fields can therefore be present on a segment whose actual face contact ends earlier. The helper must respect the terminal record before producing any slide, and consumers must not accidentally publish the untraversed tail. Existing cut positions represent face-contact fractions on the face piece. This is an explicit CB165 control and CB166 integration guard, not authorization to change tracing or contacts.

## Recommendation — bounded successor and staging

[CB165 plan](Architecture_M6_CP3_CB165_P13_Trace_Segment_Pieces_Helper_Plan_20261118.md) is the sole exact next turn. It freezes the unwired helper contract, source scope, static witness, compile boundary and stop rules; CB166 staging is specified prospectively, not authorized to execute in this turn. Gate-positive proposal rows: 380, 388, 393, 394, 396, 397, 644, 645, 648, 669, 686, 691, 693, 694, 698, 699, 700, 843, 844, 858; BunnyRandom census. All 938 other gate rows and Cylinder/Vase census have zero production slide proposals. Do not infer exact output deltas from these counts; they scope the verification, not an exclusion mask. Require exact piece/path witnesses and reviewed causal diagnostics before the switch can be accepted.

Carry C5/O42/O43/O46/O47/O48, H2/H4, FC-1/FC-4, middle-piece direction witness. H3 and O45 narrow closures retained; C3/O44/C1 stay closed. FC-6, terminal-cut, row858 held; CB145 parked. D11=A, D12=A, D10 deferred, D6 pending, `chainRimSchedules=false`. Stable 66 events / 17 categories / 49 recurrences, one produced-witness debt, 81 deferred; accepted CP2 package `11391685901`, 491/491. Selector497 frozen, not accepted. No new stable event or product correction.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491 names in exact order and PASS. focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, selector449 `d4a0d1b731cfd99e832f3c983e5741ab27a314f380184c5ff84bd88d6414`, joined newline-terminated sequence `452360f771daacb96f87697286ec7708832f63c876b9df9b1857e93433e5300b`. |
| Decisive claims independently re-derived | Raw result ZIPs, 3,862 checksums, 959 prior equal rows, two new PASS, membership, exact count table, predicted identities, path arithmetic. |
| Non-vacuity checked | Six comparator controls, analytical counterexamples, focused test assertions and noted gaps above. |
| Prior obligations discharged/carried | RA-260 S3 measurement and TB139 evidence discharged. RA-259 S3 helper tests PASS; wiring, H4, O47/O48, and other obligations carried as above. |
| Stable accounting | 66/17/49, debt 1, deferred 81, package 11391685901 selector491 491/491. No promotion. |
| New candidates/obligations recorded | No new stable event; tracker records terminal face-contact truncation guard and tie/vertex-overlap clarification before CB168. |
| ORIENTATION currency line | Updated to TB139-REV, 2026-11-18 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 evidence/selector, §4 measured witnesses, §7 priority updated; §8 existing RA-260 lesson applies. No unrelated change. |
| CHANGELOG | New TB139 Review entry. |
| ROADMAP | Current CP3 evidence refreshed; checkpoint remains active. |
| Selector manifest | n/a: no selector change or promotion. |
| LESSONS | n/a: RA-260 existing reader/scope rule and lesson 170 apply; no new generalized lesson. |
| Consolidation under CLEAN_UP_POLICY | TB138 execution report folded verbatim into Volume D3 and indexed; live references repaired. Immediate comparator evidence preserved; CB162–164 exact patches/records and RA-259/260 retained as current authority. |
| Successor frozen | `M6-CP3-CB165-P13-TRACE-SEGMENT-PIECES-HELPER`; plan linked above contains scope, falsifiers and stop rules. |
| Turn boundary held | Runtime-free; no product/test/fixture/selector/build mutation. |
| review_check.py boundary | Product/test/selector bytes unchanged; local boundary tool FAIL only for missing historical rewrite baseline `8b7299b43` in source-snapshot workspace. Remote ancestor comparison and local exact preimage diff independently verify source scope. Drift audit: zero errors, three protected-change warnings for authorized handoff/orientation/roadmap updates. Historical baseline check remains unverified. |
| STATUS lifecycle maintained | Entry IN_PROGRESS at 2026-11-18T16:49:00Z, no resume stamp. Final direct beacon required after verified remote application and cleanup. |
| Pushed to origin, branch in sync | ChatGPT Web uses exact-base Drive patch and remote verification instead of local origin history; verify application, cleanup and final beacon before COMPLETE. |

Procedure qualifications: initial batched source/policy reads preceded the selected snapshot mode; corrected with the verified snapshot. Timer reminder used shell rather than Python; absolute deadline retained. Full mandatory context/policy read and exact tool-call ledger cannot be certified; no product evidence inferred from these procedural steps.
