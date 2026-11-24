# M6-CP3-TB-REV-179 — independent review (2026-11-24 UTC)

## Situation

**TB179 rejected, six mechanical controls recovered.** Row786 is a stale witness premise, not evidence of a missing arrival-port reader. The next turn is test-only Code + Build (CB); this review does not implement it. No CP3/497/D0/H4 or production promotion.

## Background — authority

- TB178 run `45314763603`, result `14885616510`, ZIP SHA-256 `57260ad2ee62adb02bad56bc09d2ab7e2c4782b8ad4ef43faa76cb5e539600a6`; 2,012/2,012 member checks and 1,002 raw log hashes independently verified. Source `de65101eb04c73e08ea4b6b31968975f71d9d909`.
- TB179 [run 45338168889](https://github.com/akashskypatel/Directional/actions/runs/45338168889), result `14895572803`, ZIP SHA-256 `aeaacb099ea7d51292706802ccf3a9a64702abf70575d01bd8c52847acb0c636`; 2,014/2,014 member checks and 1,003 raw log hashes verified. Source `5d9468d168ee3c9eed086bd787979ced7f86843b`, package `14893165901`. Execution boundary: all rows executed once, immutable postflight, no configuration/compile/relink/benchmark. See [execution report](Architecture_M6_CP3_TB179_P13_Retraced_Trace_Selection_Full_Gate_Execution_Report_20261124.md).
- Exact review snapshot `0151eb6e9dc94e06987820d570a1fe83b654c30a`, run `45343836467`, job `138273652996`, artifact `14897372028`, ZIP SHA-256 `7ee9303f82e84704d131131cf63b0f6b0a95f5c710faf1a4e534459cf4402b2a`, 5,849/5,849 files checked. GitHub compare from package source to snapshot shows 21 commits, only documentation/control changes, no product/test/build drift. Test source SHA-256 `2b32275e271299da175317aa1d70514ede85926f8976fb5ff083ece975c2650a`. PR #8 open, draft, unmerged. The initial multi-document connector reads preceded the mandatory snapshot gate; corrected by using one verified snapshot for subsequent source analysis. This is a procedural miss, not a source discrepancy.
- Full TB178 manifest SHA-256 `921bd04bbfab596da6679083d5880d3f4893126e19a91c4687ba5ba63827e8ed` is the exact 1,002-row byte prefix of TB179 `2928fd3181eb06e635c0b88527550cddc7ff602b95b757ebd8d569e699e2f724`. Header + accepted TB169 993 rows `82581dd14064efe3729923cfd94333ef70113b0bb84e6bb8eabfb2ec61cce436`; header + CP2 491 rows `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`. All frozen ledger identities and membership rechecked; 81 deferred unchanged (`fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`).

## Assessment — independent comparison

TB178 995/1002 → TB179 1002/1003. Of the inherited 1,002 raw logs, 594 identical, 385 N1/N2 (elapsed time and line endings only), two N3 (174/176, counted complete fragment records only), 21 material changes. No green-to-red loss. Complete `M3_CP4AB_FRAGMENT_DIAG` records 1,450→1,550 (100 additions, no removals), `committedSlide` records 1,560→1,560 with identical per-row records. Recomputed all identity and verdict changes; no unlisted ledger change except raw hash. New row1003 PASS. The following records are material, not permitted normalization:

| Row | Fragment count before→after | Other change and adjudication |
|---|---:|---|
| 396 | 16→24 | Additional projection for two now-elected mechanical regions; no other change. |
| 397 | 16→24 | Same. |
| 445 | 0→4 | Plan-existence assertion now passes. |
| 637 | 0→4 | Two region projections only. |
| 638 | 0→4 | Same. |
| 649 | 0→4 | V22 E26→22 F6→2, source/graph Euler characteristic 2 unchanged. |
| 650 | 0→4 | Projection only. |
| 652 | 0→4 | Empty-region exception replaced by two-region and three face-binding receipts. |
| 653 | 0→4 | Plan existence passes; 300/300 owner map, 197 plan component faces, ordinal393 positive and corruption rejected. |
| 656 | 8→12 | Empty-region exception removed; real mechanical plan exists. |
| 658 | 0→4 | Plan existence passes; ordinal406 positive/corruption negative, named superset relation. |
| 660 | 0→4 | Plan existence passes; BW3 and ordinal390 positive/corruption negative. |
| 662 | 0→4 | Projection only. |
| 665 | 0→4 | Same. |
| 669 | 16→24 | Mechanical 12→8 traces, 32→23 events, E26→22/F6→2; two regions; torus and sphere reachability unchanged. |
| 687 | 0→8 | Repeated two-region projection only. |
| 784 | 0→4 | Projection only. |
| 786 | 0→4 | Plan now exists; later predicate at line20101 fails (was line20086). |
| 787 | 0→4 | Projection only. |
| 788 | 0→4 | Full certifier census changes (below). |
| 857 | 0→4 | Projection only. |

The 100 added records are the two-region projection repetitions, not removed slide records. Row652 and row669 agree on two distinct boundary anchors (arc0 reverse and arc14 reverse), one boundary walk each, 40 and 4 oriented boundary arcs, disk topology and field regularity true, graph/source Euler characteristic 2, one component, no exterior/boundary loops. Source-support projection reports 250 and 50 faces; do not equate support counts with exclusive owner counts. Row652's actual test binds each plan region to a unique certificate anchor; the explicit every-region-owns-a-face assertion remains required. Row788 census: 212→222 faces, digest `835099723348023536`→`8007243191870856758`, boundary edges 74→72, vertex transits 50→39, seed attributions 43→47. Two arcs 20/24→19/21 have the same five source faces each; both forward and reverse orbits remain 0. Boundary/seed/vertex-transit rows reflect the new trace and orbit inventory, with no unrelated non-census change. These are consequences of selection, not an acceptance of the full product. Row979 remains staged `RegionContainsInteriorSingularity`.

### L1 — producer selection and non-vacuity (K1–K6, J4–J6)

Row1003 (`FieldAlignedCurveNetwork.MechanicalRetracesPublishBothPortsBeforeTopologyReaders`) raw SHA-256 `43b0bda76f69493cf98909450c79ed859a11d9bb4527c05f76c95df3e97d38c7`, PASS. Its assertions at test lines23591 onward check the four exact bindings 0→3, 2→8, 4→11, 7→9, eight trace IDs, all twelve ports owned once, retained trace origin identities and every event's live trace and origin port. It reconstructs the network and checks digest equality, then removes a present arrival binding and requires `InvalidCandidateTraceBinding`. The explicit arrival comparison in checked construction makes this negative discriminating. Selection is after positional trace accesses and before sorting (`SurfaceCellTracing.cpp:4874–4930`), applies disjoint pairs to a copy, and retains trace IDs. Row669 independently lists retained 0,1,2,4,5,6,7,10 and removed 3,8,9,11. K1 prior compile authority retained; K2/J4/J5 discharged for the selected mechanical path; K3 full gate no new rejection; K4 comparison adjudicated. K5: no failing arrival-port reader evidenced; do not change one. K6 namespace/layering rename deferred until mechanical controls green.

**J6 not proved by row1003:** both TB178 and TB179 row669 report all terminal kinds as 3 (mandatory barrier) or 4 (singularity), zero trace intersection terminal events, with every trace represented. Actual contact termination assigns `terminalContact` and emits terminal `TraceIntersection` or `TraceSelfClosure` (`SurfaceCellTracing.cpp:4120–4285`; enum 2/6 in `SurfaceCellTracing.h:493`). Thus this fixture has no such struck-reference case; the conditional live-contact check executes no positive remap witness. The isolated row1002 exact struck-segment test remains PASS and non-vacuous, but cannot establish the production case. Carry J6 as explicit unexercised production witness debt; no invented counter or extra production change in CB-200.

### L2 — row786 root cause: a stale test-domain premise

The first creditable plan component is 0 (row658, same fixture/call path and correspondence predicate); it is a strict subset of certifier component 0, plan digest `4162449148105191564`, certifier digest `8007243191870856758`. Row653 gives 197 plan faces; row788 gives 222 certifier faces. The first plan component has two reported interior arcs because `GlobalTopologyPlan.cpp:765–822` copies the matching certifier census and enriches each crossed-face record from the plan partition map. `SurfaceCutGraph.cpp:824–870` admits arcs that meet the certifier component, not the plan subject. `RemeshPipeline.cpp:590–612,774–805` projects both labels. Both arc records have five distinct crossed faces, no truncation; only the terminal visit of each is in certifier component 0:

| Retained trace | TB178 arc → TB179 arc | Terminal face | Along-edge visit in TB178 row652 | TB179 row788 reason |
|---|---|---|---|---|
| 6 | 20→19 | (36,38,39) | visit4, edge36–39, side orbit0, forward/reverse0 | TerminalSlit |
| 10 | 24→21 | (66,67,120) | visit4, edge66–67, side orbit0, forward/reverse0 | TerminalSlit |

For each, TB178 row652's exact `alongEdgeVisit[32]`/`[52]` classify the terminal visit as edge-only using the same source-piece classifier (`append_along_edge_visit_receipt`, test lines8085 onward). The other four faces per arc match TB179 row788, as do their ordered vertex transits. CB-199B selection copies the candidate, does not change retained segments or the endpoints of traces 6/10, and no contact termination exists (L1); these are not selected pairs. Their final face therefore remains edge-only; both orbit labels are still 0. The certifier excludes an equal-orbit terminal segment from `traceCutFaces` (`SurfaceCutGraph.cpp:570–593`). The plan intentionally assigns its edge-side orbit even on an equal-orbit terminal visit (`GlobalTopologyPlan.cpp:1195–1207`), so that face is not in the empty-fragment domain (`:1510–1527`). All other four faces on each arc have absent certifier membership and cannot belong to its plan subset. Thus neither arc touches plan component 0. This conclusion uses source plus the retained visit receipt, not the raw `planComponent=absent` printed in row788 (that test prints the certifier before plan enrichment). The latter alone is not proof of plan absence.

The shared correspondence predicate passes row658; row786 reaches the selected nonempty arc row. Its remaining count/extent/reason checks agree with row788 and the copy/projection code. The `touchesPlanSubject` Boolean at test lines5562–5586 is necessarily false for this valid superset. The frozen R8.4/5 contract (`M3_Closure_Record.md`, ordinal407) requires an actual plan subject, its matching certifier census, each crossed face and both component labels **where defined**, not an intersection of reported arc faces with the plan subject. This is an independently established witness defect. Do not make the partitions equal, insert an owner, alter terminal slit semantics, or accept absence without exact membership verification. Row786's corruption negative did not run; it gets no credit yet.

## Recommendation — L3

Freeze only [CB-200 test-only census membership correction](gates/Architecture_M6_CP3_CB200_P13_Cross_Partition_Arc_Census_Test_Plan.md). Preserve every-region-owns-a-face (C4), J6, K6, E5, row979, Branch A and CB-190. Stable TB170 recurrence still open, six recovered controls; no new accepted-green loss; 67 events / 17 categories / 50 recurrences, witness debt1/deferred81. No acceptance advance. The next full gate must establish the positive census and corruption-negative cases, not merely remove a RED assertion.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB169 993 and CP2 491, full SHA-256 values above; TB178 exact prefix of TB179. |
| Decisive claims independently re-derived | Both immutable result archives, ledger/membership and all raw hashes, 21 changes, region anchors and terminal slit classification. |
| Non-vacuity checked | L1 arrival binding removal discriminates; J6 contact positive not exercised. L2 row786 negative not reached; CB-200 must prove positives and specific corruptions. |
| Prior obligations discharged/carried | K1 compile preserved; K2/J4/J5 selected path; K3 no green loss; K4 itemized; K5 reader premise withdrawn; J6/K6/C4/E5 and staged work carried as above. |
| Stable accounting | 67/17/50, debt1/deferred81; TB169 993/993 package 14786260085 and CP2 491/491 accepted unchanged. |
| New candidates/obligations recorded | L2 non-stable witness premise, tracker and plan; no new event. |
| ORIENTATION currency line | TB-REV-179, 2026-11-24 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated current state, witness, priority and recurring defect pattern. |
| CHANGELOG | Entry added. |
| ROADMAP | Current status and exact next updated. |
| Selector manifest | n/a; no selector added or promoted. |
| LESSONS | Existing witness preconditions, structure/membership and non-vacuity rules apply; no new generalized rule. |
| Consolidation under CLEAN_UP_POLICY | Prior TB178 Review text retained in the folded record; current TB178 comparison and TB179 source/runtime authority retained. |
| Successor frozen | `M6-CP3-CB-200-P13-CROSS-PARTITION-ARC-CENSUS-TEST`, plan and falsifiers above. |
| Turn boundary held | Runtime-free, no product/test/build/fixture/selector mutation. |
| review_check.py boundary | Executed: product/test/build and selector boundaries PASS; all frozen selector hashes match snapshot HEAD. Four history-dependent checks fail because snapshot has no rewrite-base history. All live durable headings retained (handoff 4/4, orientation 1/1, tracker 0/0), consistent with prior TB178 historical-baseline audit. Document drift audit: 0 errors; two size and three protected-landing-file warnings (existing Review duties authorize these edits). No clean history-dependent exit claimed. |
| STATUS lifecycle maintained | Entry `IN_PROGRESS`, Started at 2026-11-24T06:52:00Z, Resumed empty. Final beacon after verified patch and cleanup only. |
| Pushed to origin, branch in sync | Required via Drive apply result and GitHub ref verification; local snapshot is not an origin checkout. Do not claim success until verified. |
