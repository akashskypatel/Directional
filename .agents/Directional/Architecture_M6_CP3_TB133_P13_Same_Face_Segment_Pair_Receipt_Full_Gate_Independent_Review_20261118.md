# TB133 independent review — same-face segment-pair receipt (2026-11-18 UTC)

## Situation

`M6-CP3-TB133-P13-SAME-FACE-SEGMENT-PAIR-RECEIPT-FULL-GATE-REV` — independent, artifact-only review. **MATCH upheld** under [RA-254 S4](Architecture_M6_CP3_TB132_P13_Cut_Binding_Conflict_Receipt_Full_Gate_Independent_Review_20261117.md#ra-254--adversarial-re-review-of-this-review-2026-11-17-utc). Sphere: transverse shared endpoint. BunnyRandom: co-directional overlap, not merely a duplicate node. No geometry acceptance or promotion.

## Background — evidence authority

- [TB133 execution](Architecture_M6_CP3_TB133_P13_Same_Face_Segment_Pair_Receipt_Full_Gate_Execution_Report_20261118.md); CB156 source `779fe661e260f506592c64791fbe655734029478`, package `14369087138`, ZIP `9bec7da392d32c0dafedb77bc08426a2aeaa795c7905e6e5facde7ad8c14d032`; comparator CB155 source `cce5be20ea7237f59f3c0acca25a4ba57813644e`, package `14357189158`. Package digests are inherited from the verified compile records, not freshly downloaded in this review. Both runtime boundary files name their exact package/source and show postflight=true, compile/relink/configure/benchmark=false. Gate exit 90/control_bad=1 is the same permitted RED, not a green gate or orchestration failure.
- [Snapshot run 44207019784](https://github.com/akashskypatel/Directional/actions/runs/44207019784), source `8a796dc905a07f188c5a5b2834e4e16b9b9a8642`, artifact `14384581058`, ZIP `f59b4b1cdfbae652f0a69abe1358f7a240a5f7872b9e596ac1dfd4ad258c1ec2`, inner archive `c0af13b0eaca44d9a9b932904ebfbad95180f4ba6248e1f02191e20adbb28884`; 5,541/5,541 checks. CB156 is an ancestor; 19 intervening commits change docs/control only. CB155→CB156 has exactly one semantic change, +65/-0 in `src/geometry/EmbeddedGraphTopology.cpp`; frozen diff SHA `1246f12b3cc22f62aa70ea503cf14e1f8438b160995e85225ba26c8fb7bfc205`, postimage blob `08060fbda168795efc15929e1bfdf1854722136e`. No source change in this review.

| Scope | Artifact | Recomputed ZIP SHA-256 |
|---|---:|---|
| TB132 gate | 14359654903 | `b2a9997c5f41ba760a75003d3edc7682cbd20dbd852f7df49bd8a90de6c2611e` |
| TB132 census | 14362615302 | `a44f41eb558fd9205d9725d85d9f83b8d754beef1b24a3d886b847f6e1d639a2` |
| TB133 gate | 14381507340 | `d0647213767e3dc7152ebc1e5c31ac0221ad6ea66d4389fe4a8cab68630863f2` |
| TB133 census | 14383400603 | `0d0accf8103db8b5b5b584646935e7c7d4fdd0f0dc08583f32b2947a7af214a5` |

Reopened original result archives from the retained TB133 evidence bundle. Candidate ZIP digests also match provider inventories for runs 44200479694/44203730406; comparator digests match TB132 authority. Verified all 3,846 internal checksums and 1,912 individual raw log bindings. Gate/census/deferred/harness hashes remain `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962`, `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`, `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.

## Assessment — independent derivation

A separate offline parser (not the execution comparator) checked every ledger field except the independently verified raw-log digest, exact manifest identity and one actual RUN per row, membership (953 gated + 81 deferred), outcomes and archive coverage; compared complete M3 record field tuples as multisets, nonrecord bytes in order, only permitted elapsed-time/newline/parameter bytes, and removed only the one new receipt field. 953 + 3 = 956/956 substantive and normalized comparisons match; all 14 negative controls rejected altered receipts, missing/duplicate fields, removed/duplicated/changed M3 records or nonrecord changes. The original comparator also reproduces MATCH. The raw field data are checked separately, not assumed valid because the normalizer removes them.

Gate 952/953; row 858 only RED (`SurfaceCellTracingDisplayTests.cpp:155`); row 648 sphere assertions remain unreached. Census Cylinder PASS with 288 quads, BunnyRandom/Vase RED. All 491 accepted rows PASS. Selector bytes in gate prefix exactly concatenate CP1 focused30 (`1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`), CP2 focused12 (`2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`), M5 selector449 (`d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`); concatenation `452360f771daacb96f87697286ec7708832f63c876b9df9b1857e93433e5300b`.

### Sphere — transverse endpoint, C5 and O47

All 66 receipts across rows 380, 388, 393, 394, 396, 397, 644, 645, 648, 669, 686, 691, 694, 698, 699, 700, 843, 844, 858 contain the same pair data. Counts equal TB132 per row. Trace 4 and trace 6 enter segment 7 through edge (0,2), opposite face transitions, exact same edge parameter (display 0.12749386848657163), no shared events. `EmbeddedGraphTopology.cpp:365–401` uses the exact edge/parameter map before the receipt. The decimal is not the proof.

| Face | Segments 4/6 | Orientation signs | Equal ends |
|---|---|---|---|
| (0,1,2) | 6/7 | 0:+1:+1:0 | xe (first exit = second entry) |
| (0,2,3) | 7/6 | -1:0:0:-1 | ex (first entry = second exit) |

Each has a nonzero exact sign in each direction; neither segment is degenerate or collinear. Shared canonical endpoint gives `EndpointTouch`, not same-face `ProperCrossing` (strict opposite signs required). This establishes the transverse shared-edge endpoint class in RA-254 S4, not head-on overlap. It does not by itself prove an alternating four-ray order across the edge, arrival chronology, terminal versus through incidence, or a particular repair. Producer classifiers at `SurfaceCellTracing.cpp:2378–2494`, pending/pending filter `:4344–4349` and pending/wall filter `:4411–4417` reject non-proper contacts. The final stored trace pairs demonstrate the missing class; which scheduler path is responsible must still be proved. O47 is required because `EmbeddedGraphTopology.cpp:533–556` accepts only strict interior segment parameters; an edge endpoint needs certified identity with the struck trace's crossing, not a fabricated face-interior node.

### BunnyRandom — co-directional overlap, FC-1/FC-4

Both census row 2 receipts agree. Nodes 220/222 each have exactly one printed terminating trace (43/15); both claim exact trace 82 segment 0 position 0.2305473011248014 in face (21,72,273) with edgeless FirstContact/TraceIntersection events. Receipt producer takes the first terminating trace per node; no general result for multi-terminator sets.

| Face | Segments 43/15 | Signs | Equal ends |
|---|---|---|---|
| (72,94,243) | 14/20 | 0:0:0:0 | ee+xx |
| (72,243,273) | 15/21 | 0:0:0:0 | ee+xx |
| (21,72,273) | 16/22 | 0:0:0:0 | ee+xx |

The exact emitter checks all four cross-end equalities (`EmbeddedGraphTopology.cpp:1025–1076`). No ex/xe, so the coincident entry and exit are distinct, not zero-length segments. These are identical oriented segments in three faces, including the struck locus. The classifier would return `CollinearOverlap` (two distinct shared endpoints). Nine earlier measured pairs are nonmatching; 13/19 in (94,124,210) is unevaluated. Earliest overlap onset, scheduler eligibility, arrival order and upstream causal event are not established. A node merge alone would conceal a doubled arc. Select the co-directional case of `M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP` as a **held obligation**, not the immediate successor; remeasure after sphere correction. Do not select COINCIDENT-CONTACT-NODE-IDENTITY on this evidence.

## Recommendation — one immediate successor, not started

`M6-CP3-DEFN-P13-EDGE-ENDPOINT-CONTACT` — definition/review only; no source, runtime, or build. Own C5 edge-endpoint contact and O47 together. Freeze exact incident-face, edge parameter, branch/port/gauge and ordered incidence authority; determine whether eligible arrival/continuation is simultaneous, terminal, or through and determine the producer path. Represent a certified shared event/node with the struck trace's edge crossing, preserve event roles and crossing/cut bijections, and define consumer handling of the boundary position without weakening the interior-only helper. Define exact positive and near-miss negative witnesses (including distinct edge parameters, wrong sheet/edge, grazing/overlap, barriers, arrival/role disagreement, reverse and permutation cases) and artifact-only gate; preserve all accepted selectors and typed failure authority. Stop if roles, ordering or shared incidence cannot be justified from exact source authority. Falsifiers: an existing shared event at the locus; nonmatching canonical locus; collinear/degenerate rather than transverse pair; loss of port/barrier or cut incidence; disappearance through an earlier failure; changed accepted outcomes. No coordinate welding, guessed cuts, relaxed guards, producer proxy removal, or consumer invention. Do not implement either repair in this review. Hold BunnyRandom overlap correction pending sphere results; only one next turn is authorized.

Carry C5/O42/O43/O46/O47, H2 unobserved, FC-1/FC-4 broad producer proof, middle-piece direction witness and BunnyRandom overlap ownership. O45 remains closed only for consumer proxy misuse; C3/O44/C1 narrow closures unchanged. FC-6/terminal-cut outcome/row858 fix held; CB145 parked; D11=A, D12=A, D10 deferred, D6 pending, chainRimSchedules=false. Stable 66 events / 17 categories / 49 recurrences, debt 1, deferred 81; CP2 accepted package 11391685901 and 491/491. No CP3/selector497/D0 promotion. Vase RED unchanged.

## Review closeout evidence

- [x] Reopened primary artifacts, independently compared frozen gate/census, rehashed selectors and classified each site against exact code and raw data.
- [x] Snapshot source authority, semantic delta and no product/fixture/test/build/selector changes; no project runtime or local build. Offline comparator only.
- [x] Documentation: current review, TODO, CHANGELOG, orientation, roadmap, tracker and handoff; preserve current TB132 comparison/RA-254 and CB156 authorities; fold superseded TB130 report with exact recovery index and repair links. Historical rewrite base resolved via connector; preserved all four handoff and one orientation durable heading; scratch checkout has no historical commit object, so stock boundary script cannot certify that ancestry locally. Connector ancestry comparison is ahead 6130, behind 0, merge-base exact rewrite commit. No fabricated local Git history.
- [x] One next definition identified, not executed. Repository transport, cleanup and final STATUS are verified separately during closeout; this record does not itself certify an applied patch.
## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | CP1 focused30, CP2 focused12, M5 449 exact byte hashes and 491/491 in Assessment; concat 452360f771daacb96f87697286ec7708832f63c876b9df9b1857e93433e5300b. |
| Decisive claims independently re-derived | Four ZIPs, 3,846 internal checks, 956 paired rows, 68 pair fields, exact classifier and canonical endpoints; reverse/forward exact CB156 diff pre/postimage. |
| Non-vacuity checked | 14 independent negative controls reject missing/duplicate/changed receipts, M3 fields, or other log bytes; no zero-selected filter; independent exact orientation and endpoint proof. |
| Prior obligations discharged/carried | Contact-kind ambiguity discharged for measured pairs only. C5, O42/O43/O46/O47, H2, FC-1/FC-4, middle-piece witness and BunnyRandom overlap carried. O45/C3/O44/C1 narrow closures unchanged. FC-6, terminal-cut, row858 fix held. |
| Stable accounting | 66/17/49, one produced-witness debt, 81 deferred, accepted CP2 package 11391685901, 491/491. Selector497, CP3/D0 not promoted. |
| New candidates/obligations recorded | Tracker updated with measured C5/O47 edge class and FC-1/FC-4 co-directional overlap, owners and falsifiers. No new stable event. |
| ORIENTATION currency line | TB133 independent Review, 2026-11-18 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated each in place; superseded TB132-only diagnoses replaced with exact measured classifications; priorities and recurrence rule updated. |
| CHANGELOG | TB133 review entry added. |
| ROADMAP | Current checkpoint summary updated; no checkpoint closure. |
| Selector manifest | n/a — no selector added, accepted or changed. |
| LESSONS | Existing RA-254 exact coincidence lesson applies; no new general pattern. |
| Consolidation under CLEAN_UP_POLICY | TB130 execution report folded verbatim into D3 (118 lines, indexed, SHA-256 61efb7203088499355892a7c38a5e3d32f393f07532603b233e75391dbc1e1a0); live references repaired. TB132 comparator and RA-254 criteria/current package authority retained. |
| Successor frozen | M6-CP3-DEFN-P13-EDGE-ENDPOINT-CONTACT only; Recommendation states falsifiers and stop rules. |
| Turn boundary held | Runtime-free, offline Python comparison only; no product, test, fixture, selector, benchmark or build change. |
| review_check.py boundary | Product/selector checks PASS; stock script FAIL for absent historical Git object in verified source snapshot. Independent connector comparison of rewrite base 8b7299b43764a6ba3444e5bc774a2f1b65e99731 proves ancestor; exact historical headings fetched and matched (four handoff, one orientation); drift audit 0 errors and three authorized document-change warnings. |
| `STATUS` lifecycle maintained | Current TB133-REV, initial entry IN_PROGRESS, started 2026-11-18T00:19:46Z, Resumed at empty. Final beacon follows verified closeout and names exact successor only when COMPLETE; not claimed by this receipt. |
| Pushed to origin, branch in sync | See verified Drive application and branch comparison at final closeout; local git is snapshot-only, not an origin checkout, so no fabricated git status -sb result. |
