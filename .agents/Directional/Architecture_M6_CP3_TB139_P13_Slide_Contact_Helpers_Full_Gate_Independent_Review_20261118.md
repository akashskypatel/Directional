# TB139 P13 slide-contact helpers — independent review (MATCH)

## Situation

`M6-CP3-TB139-P13-SLIDE-CONTACT-HELPERS-FULL-GATE-REV` — 2026-11-18 UTC. **MATCH upheld for the unwired helpers and the measurement only.** 959/959 prior rows match TB138; rows 957 and 958 PASS. No product execution, source/test/selector mutation, or M6-CP3/D0 promotion. PR #8 remains open, draft and unmerged.

## Background — primary authority

[Execution report](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb139_p13_slide_contact_helpers_full_gate_execution_report_20261118md), [TB138 comparator](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb138_p13_departure_chord_classifier_switch_full_gate_execution_report_20261118md), [RA-260 S2–S4](Architecture_M6_CP3_TB138_P13_Departure_Chord_Classifier_Switch_Full_Gate_Independent_Review_20261118.md#s2--ra-257-s53-defined-a-contact-locus-inside-a-slide-or-at-an-entry), and RA-259 S3 govern. CB164 source `4d8ddfee7dfa8dc651406cfb1de816027c859df2`, package `14440134091`, ZIP SHA-256 `5b4a2c7db08cb610dfa2388b7a0e5898435a154b82da09cc61c232b4e92d6c8a`. Comparator CB161 source `f14761715004d7ddc27e032698f6540ae1a9b0c4`, package `14424780973`. Package authority comes from archived runtime preflight and compile records; no binary re-download or execution in Review.

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

## RA-261 — adversarial re-review of this Review (2026-11-18 UTC)

### S0 — verdict

MATCH is upheld. Product source at HEAD equals CB164 (`git diff --quiet 4d8ddfee7dfa8dc651406cfb1de816027c859df2 HEAD -- src include tests`). RA-261 did not re-open the archives (runtime-free). Three contributions of this Review are accepted:
- The per-row count: 1,200 grazing proposals on 20 sphere gate rows.
- The guard that a terminal face contact is committed with its whole proposal, so the record keeps a slide the trace never traversed.
- The vertex-overlap obligation before the wiring.

Its successor is not accepted as written (S1). RA-261 freezes CB165 (S2) and the TB140 gate (S3), and splits the switch (S4).

### S1 — defects

1. **CB165 was handed over as a prose contract.** The implementation agent receives exact patches only (RA-225: a prose-only next turn is either withdrawn or frozen). The plan file leaves the function design, the fixture and the falsifiers to the implementer. RA-261 freezes CB165 exactly (S2). The plan file is superseded.
2. **CB166 was framed as one atomic switch of every reader across four files.** It would carry exact path predictions for 1,200 proposals that nobody can derive by hand. Two of its listed sites are not H4 sites (item 3). RA-261 splits it by consumer (S4).
3. **Corrections to RA-260 S1 (its own errors).**
   - "H4 is latent" is wrong. TB139 shows grazing slides on 20 passing sphere rows (380, 388, 393, 394, 396, 397, 644, 645, 648, 669, 686, 691, 693, 694, 698, 699, 700, 843, 844, 858). Those proposals are not counts of committed segments, but any committed one already publishes the chord.
   - `SurfaceCutGraph.cpp:268` and `GlobalTopologyPlan.cpp:349` (`trace_segment_exit_support`, used only for a failure field at :418) read the slide end as an end point. That is correct, and they need no change.
   - The H4 sites are:
     - `exact_trace_path` and `exact_trace_path_between` (`EmbeddedGraphTopology.cpp:287, 730`);
     - the vertex-ray readers `vertex_trace_ray_second_point` (:1929, used at :2043) and the secondary-rank far end (:2165–2180);
     - `trace_segment_exit_barycentric` (`GlobalTopologyPlan.cpp:256`), which feeds the evidence-only local trace chords at :1295;
     - `FieldAlignedNetworkPolylines.cpp:94`.
4. **RA-260 S2.6 wording.** "Parameters 0 and 1 stay excluded" is wrong.
   - Only a single-point meeting at an edge end is excluded (RA-259 S3.3), and CB163 does exactly that.
   - A positive-length overlap whose first shared point is an edge end returns a contact at parameter 0 or 1, which is a vertex locus.
   - Whether that publishes as a vertex node or an edge node is undecided. It must be decided, with an entry/slide tie control, before the carrier-contact wiring CB is frozen (S4).

### S2 — CB165 frozen

- **Patch.** `.agents/Directional/Architecture_M6_CP3_CB165_P13_Trace_Segment_Pieces_Helper_Exact.diff`, SHA-256 `dd9fdbf514f0ba6a3d4c7413e7412c801c7ae18e4b29f2d98d1919137d49e49b`, 217 lines. Numstat: `13 0` EmbeddedGraphTopology.h, `59 0` EmbeddedGraphTopology.cpp, `112 0` FieldAlignedCurveNetworkTests.cpp. The preimage is CB164.
- **Helper.** `exact_trace_segment_pieces(trace, segment)`, unwired, implementing RA-260 S2.1:
  - **No slide.** It returns the existing `exact_trace_path(trace, k, k+1)`, so existing behaviour is reused unchanged.
  - **Incomplete slide record.** A record with only one slide field, or a slide off its outgoing carrier, returns empty.
  - **Terminal face contact on the last segment.** The contact must lie strictly inside the face piece, entry → slide start (`face_chart_segment_parameter`). The result is then that clipped face piece and no slide.
  - **Otherwise.** The result is a face piece entry → slide start, omitted when the canonical points are equal (a departure, including different edge keys at a vertex), then an edge piece along `outgoingCarrier` to the slide end.
  - A last-segment `terminalPoint` must equal the slide end.
  - The result must pass `exact_source_path_is_canonical`.
- **Test.** `FieldAlignedCarrierOccupancy.TraceSegmentPiecesFollowTheFacePieceThenTheCarrier`, on face (0,1,2), with the exact path asserted in every case:
  - grazing (1/4,3/4,0) → (5/8,0,3/8) → v2, which is two pieces and not the old chord;
  - descending to v0;
  - a departure v2 → v0 as one edge piece (canonical identity across the (1,2) and (0,2) keys);
  - an ordinary single face piece;
  - a contact at (7/16,3/8,3/16) clipped to one face piece;
  - rejections for a contact off the piece, a contact at the slide start, a missing end, a slide on another edge, a terminal point elsewhere, an empty slide, and an index out of range.
- **Checks.**
  - `-fsyntax-only -Wall -Wextra -DUSE_GMP_ENABLED` gives 0 errors. Warnings are unchanged: 22 for EmbeddedGraphTopology.cpp and 42 for the tests.
  - `git apply --check` passes at HEAD.
  - A Haiku audit's results are recorded in S6.
- **Scope and routes.** Compile only; no callers. Mismatch: `M6-CP3-PLAN-P13-SLIDE-CONTACT-HELPERS-STOP`. Infrastructure: `M6-CP3-CB165A-P13-TRACE-SEGMENT-PIECES-HELPER-ORCH`.

### S3 — TB140 criteria (frozen)

- **Package.** CB165.
- **Manifest.** `gates/Architecture_M6_TB140_P13_Trace_Segment_Pieces_Helper_Full_Gate_Case_Manifest.tsv`, SHA-256 `390fe1bd2c2e5f6d490ed21dac52219acefd9646081d361d2d4e174dfdedbf52`. It is the TB139 manifest byte for byte plus row 959 (`ra261:trace-segment-pieces-helper`, `directional_surface_cell_producer_tests`, PASS). `SELF_CHECK_PASS cases=959 deferred=81`; membership 1,040.
- **Unchanged inputs.** Census, deferred and harness.
- **MATCH** requires all of the following:
  1. Gate rows 1–958 and the census equal TB139 under N1–N4 only. The `slideProposal` lines are retained and must be byte-identical, because no product path changed.
  2. Row 959 PASS.
  3. Nothing else differs.
- **Routes.** Mismatch: `M6-CP3-PLAN-P13-SLIDE-CONTACT-HELPERS-STOP`. Infrastructure: `M6-CP3-TB140A-P13-TRACE-SEGMENT-PIECES-HELPER-ORCH`.

### S4 — the H4 switch, split by consumer (TB140-REV freezes each patch)

> **Prospective S4.1 scope suspended by TB140-REV (2026-11-18).** [TB140 Review](Architecture_M6_CP3_TB140_P13_Trace_Segment_Pieces_Helper_Full_Gate_Independent_Review_20261118.md) proves the EmbeddedGraphTopology-only switch conflicts with the existing `GlobalTopologyPlan` mixed-path rejection and the cut/region whole-segment chord contracts. The endpoint-site finding at SurfaceCutGraph:268 still holds. Retain the plan below as the superseded scope proposal, not executable authority. Require a coordinated exact-piece ownership decision and revised scope before freezing CB166. S3 TB140 MATCH stands. No scope expansion or later CB is authorized here. **Replaced by [RA-262 S3](Architecture_M6_CP3_TB140_P13_Trace_Segment_Pieces_Helper_Full_Gate_Independent_Review_20261118.md#s3--revised-sequence-replaces-ra-261-s4)** (EPO contract; CB166 is now the committed-slide receipt).

1. **CB166 — the embedded graph.**
   - **Scope:** `EmbeddedGraphTopology.cpp` only.
   - **Paths.** `exact_trace_path` and the whole-segment pieces of `exact_trace_path_between` concatenate `exact_trace_segment_pieces`.
   - **Rays.** In `vertex_trace_ray_second_point` and the secondary-rank far end, the Forward point is the first piece's end and the Reverse point is the last piece's start. Paths and rotation rays change together, so the graph never pairs piece paths with chord rays.
   - **Interior cut positions on a slide segment stay fail-closed.** `trace_segment_canonical_exit` keeps returning empty for slides until the piece-position CB.
   - **Test.** A focused test drives the public `exact_trace_path_between` and the vertex rank on a grazing trace.
   - **TB criteria.** The 938 zero-proposal gate rows plus Cylinder and Vase must be strictly equal. On the 20 slide-positive rows and BunnyRandom, outcomes and the row-858 RED site are unchanged, and every differing record is listed and tied to a segment with a slide. Any other difference is a MISMATCH.
2. **CB167 — the evidence-only local fragment chords** (`GlobalTopologyPlan.cpp:256/1295`). They use the face piece only, because a slide does not split the face interior.
3. **CB168 — polylines** (`FieldAlignedNetworkPolylines.cpp:94`). They follow the pieces, including the grazing bend.
4. **CB169 — unwired fields.** `TraceCutPosition` gets its piece field and `FieldAlignedTerminalContact` its `carrierLocus` (RA-260 S2.2–S2.3). `trace_segment_canonical_exit` then returns the slide start for a slide segment (the face piece end), and the existing assertion that it is empty for a slide changes as a contract change under S2.2, not a weakening.
5. **CB170 — carrier-contact wiring + TB.** Producer loops, publication and the edge node. It deletes the CB160 receipt. Before it is frozen, the S1.4 vertex-overlap rule and an entry/slide tie control must be decided.
- **Not changed:** `SurfaceCutGraph.cpp:268` and `trace_segment_exit_support`.

### S5 — turn sequence

- **Implementation track:**
  1. CB165 (compile, EXACT NEXT).
  2. TB140-EXEC.
  3. CB166 (compile), then its TB.
  4. CB167 and CB168 (compile each), then one TB.
  5. CB169 (compile).
  6. CB170 (compile), then its TB.
- **Review track:** TB140-REV freezes CB166 and its TB. Each later REV freezes the next patch.
- **Held:** FC-6, TERMINAL-CUT-OUTCOME and the row-858 fix. **Parked:** CB145. D11=A and D12=A are unchanged.

### S6 — audit and lessons

- **Haiku audit of CB165 (read-only, hand-evaluated): PASS.**
  - All 13 expectations hold with exact values. `SourceFaceTopologyKey::make` sorts the face to (0,1,2), and vertex ids compare without regard to extent.
  - Against the old single chord from `exact_trace_path`, the grazing, descending, departure, off-piece, slide-start and four malformed cases all fail. A raw-`FieldBoundaryPoint` comparison fails the departure case.
  - The ordinary case and the positive contact case are controls; the contact branch's added value is in its two rejection cases.
  - No compile risk; additive only; no callers.
  - Gaps carried into CB166's focused test: a slide on a non-last segment, and a contact on a face edge or vertex.
  - All site classifications in S1.3 are confirmed.
- **Lessons:**
  - Before listing a reader as a defect site, classify it: is the field read as an end point, or as the far end of a straight piece?
  - Before calling a defect latent, check the per-row count of the kind it affects.
