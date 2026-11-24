# M6-CP3-TB-REV-178 — independent review (2026-11-24 UTC)

## Situation

TB178 product gate remains **REJECTED**. The independently examined evidence meets the frozen comparison rule, but the seven accepted-green mechanical controls still fail. The isolated reference-remap guard passes. The production path has not yet used the helper. No product acceptance.

## Background — exact authority

| Authority | Evidence |
|---|---|
| Candidate | TB178 run `45314763603`, artifact `14885616510`, outer SHA-256 `57260ad2ee62adb02bad56bc09d2ab7e2c4782b8ad4ef43faa76cb5e539600a6`, 2012/2012 member checks, 1002 raw hashes. Source `de65101eb04c73e08ea4b6b31968975f71d9d909`, package `14883418907`. |
| Baseline | TB177 run `45283342400`, artifact `14871900641`, outer SHA-256 `8c5bce907f59b77207833153912805cccca6fa122c70ff9f299a64f68102b068`, 2010/2010 checks, 1001 raw hashes. |
| Accepted baseline | TB169 run `45104059492`, artifact `14787082075`, SHA-256 `dc15a8df5226fc209717f6df2fd15140e9e04abb6e73f831d8285992e72f04e5`, 1994/1994 checks, 993 raw hashes, 993/993 PASS. |
| Snapshot | Source `62be7ebc7649c4b5ba284f1097bf14473b01f8d6`; run `45326605386`, job `138217712531`, artifact `14890440375`, SHA-256 `3083bffcc7e9ba6f8417bf4d18ea8ec0dc45d04ba862c65048a1e70c36b678d9`; 5843/5843 source files verified. |
| Exact amended helper | `src/geometry/RetracedTraceReferences.h` SHA-256 `bcab2d6292b9f1317471c0659e714b4afd7339e1def7c07d5d409f85b2356944`; test SHA-256 `e13d7182355d071e0fe6bd0dc645b8288037af0bf609eb59437711dda7d29b89`. Both match CB-199A postimages. |

Source snapshot was verified before final cross-file review. Initial connector reads preceded mandatory snapshot selection, contrary to the tool conservation policy; corrected by switching to the exact snapshot. No subsequent piecemeal source inspection. Source archive has no remote Git history; report the history-check limit below rather than claiming it passed.

## Assessment — evidence re-derived

All 1,002 planned processes completed, 995 PASS, 7 RED; 1,083 membership = 1,002 gated + 81 deferred. TB177 had 994/1001 PASS. Independently re-hashed all raw logs, compared all inherited ledger fields except raw hash, and compared each raw transcript under the frozen N1–N3 rules. 627 byte-identical, 371 elapsed-time/line-ending differences only, three complete-record multiset differences (172/174/176; six identical diagnostic records in each, non-record remainder unchanged), zero unauthorized differences. No failure-site movement. Both 1,208-byte receipts from rows652/656 have SHA-256 `cea589ac94f174b1ee859d777cf580ff342b39354f5c27191eb1e0c58d46aa69`, identical between both runs. Independent accepted-baseline comparison confirms exactly seven lost accepted-green controls among the first 993 identities. CP2 candidate 490/491. Accepted CP2 prefix plus header SHA-256 `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`; candidate 993-prefix SHA-256 `82581dd14064efe3729923cfd94333ef70113b0bb84e6bb8eabfb2ec61cce436`; 1001-prefix SHA-256 `0f85400ff9713fc8a835f308304ded1db9830e668211bab71c88d580b2e84642`; full 1002 manifest SHA-256 `921bd04bbfab596da6679083d5880d3f4893126e19a91c4687ba5ba63827e8ed`. Runtime boundary record: postflight true, no configure, compile, relink or benchmark; exit90 is the semantic reject, not infrastructure failure.

| RED row | Retained first failure |
|---|---|
| 445 | test line 19446 |
| 652 | `RegionElectedCutComponentEmpty` exception |
| 653 | test line 14457 |
| 656 | `RegionElectedCutComponentEmpty` exception |
| 658 | test line 20027 |
| 660 | test line 14256 |
| 786 | test line 20086 |

Row1002 `RetracedTraceReferences.RemapsExactStruckSegmentAndEndpointPortWithoutPublication` executes one test and passes; raw SHA-256 `90362e165534bee0fab1a2196cdaa31925021619cc5e80d50c9945370b70a62d`. Row979 stays staged `RegionContainsInteriorSingularity`. Stable 67 events / 17 categories / 50 recurrences; debt1, deferred81. No new stable event; the seven controls are the existing TB170 recurrence, not seven new events.

### Guard and production contract

The four reverse pairs (0/3, 2/8, 7/9, 4/11) have five edge pieces each, reversed ends, zero face pieces and reciprocal terminal singularities. The lower port is kept. This proves the D13=A premise on these receipts, not that the remap is already called. DESIGN §7.2 requires unique port ownership and removal of redundant traces without altering required port topology. A later empty-region collapse is not authorized.

J4 is discharged for the isolated helper: it returns the arrival binding separately, preserves `sourcePort` as the trace's origin port, erases the removed origin and reciprocal arrival, and removes an undersized departure-only junction. It remaps the struck trace **and** exact segment index; checks carrier/face support, unique segment, both contact events; rejects incomplete/ambiguous inputs. The guard checks split-carrier and face-piece positives, unchanged unrelated records and input, and negatives for missing terminal singularity, wrong struck index, missing locus/event, repeated path. This is non-vacuous: an identity-only remap cannot satisfy expected exact segment and event equality. The guard does not prove that all actual production contacts are remappable. J6 remains open.

J5 source check: canonical tracing allocates positional trace IDs and uses vector indexing during queue processing (`SurfaceCellTracing.cpp:4287–4885`); the last trace terminal validation precedes the committed-slide diagnostics and `field_aligned_sort_events` at 4930. Place selection there. The legacy diagnostic `finalize_field_aligned_events` is not a production selection caller and stays unchanged. The checked constructor sorts and compares actual vs fresh expected (`5828–5874`) but compares fields individually, so default struct equality alone is insufficient. The semantic hash (`5614` onward) must add arrival ownership with a domain tag only for present values. Finished readers find IDs rather than treating IDs as vector indices; preserve gaps. Do not encode an arrival in origin/junction event fields.

Additional static risk: `exact_source_retraced_traces` can associate more than one later trace with one kept trace. One optional arrival field cannot represent that result. Reject any reused trace in a selected set and do not publish partial changes. Also `exact_trace_segment_end` has no general limit-cycle endpoint rule: read the eligible singularity-terminating paths only; other terminal kinds cannot represent a reciprocal singularity arrival. Missing eligible geometry fails closed. Group by component/region so equal geometry on separate authority regions cannot trigger a cross-region removal. The existing exact helper checks reciprocal endpoint/port and path identity independently. No production claim follows from this static review.

## Recommendation — exact next turn

Freeze only `M6-CP3-CB-199B-P13-RETRACED-TRACE-SELECTION`. [Exact proposal](Architecture_M6_CP3_CB199B_P13_Retraced_Trace_Selection_Exact.diff) SHA-256 `02cc43c4b4ed3144df4bb08d7a8a857afcb6ce6f0cfa582c08da0a3031411fe5`, 11,639 bytes, +172/−0; [manifest and falsifiers](gates/Architecture_M6_CP3_CB199B_P13_Retraced_Trace_Selection_Exact_Manifest.md). The diff is checked in a separate snapshot-derived scratch tree, not applied to live product/test paths. It adds the explicit field, canonical producer selection and checked comparison/digest, and one appended production-path guard. CB compiles eight required targets with GMP/GMPXX, packages, executes no runtime. Separate TB179 follows only on a successful compile. The new guard must establish all 12 port owners, exact four bindings and eight live traces, including checked rejection when a binding is missing. CB-200 port-set readers, region-owns-face assertion, E5 and row979 remain held. Existing validators and fail-closed behavior remain mandatory.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | CP2 491 prefix and 993 accepted identity comparisons above; no selector promotion. |
| Decisive claims independently re-derived | Three archive digests, all member and raw hashes, ledger identities and verdicts, N1–N3 classes, row receipts, stable accepted-green losses. |
| Non-vacuity checked | Existing guard checks reference index and full event equality, including negative controls. Proposed guard reaches actual retained A2a product. No runtime for proposed guard. |
| Prior obligations discharged/carried | J1 historical STOP retained; J2/J3 receipts and isolated guard verified; J4 isolated field convention discharged; J5 selection/ID gap/sort/atomicity and J6 production remap carried to CB-199B; CB-200/E5/row979 held. |
| Stable accounting | 67 / 17 / 50; debt1, deferred81; accepted TB169 result 14787082075, 993/993 and CP2 491/491. |
| New candidates/obligations recorded | Explicit checked equality, domain-tagged digest, disjoint selected pairs and eligibility in tracker; no new stable event. |
| ORIENTATION currency line | TB-REV-178, 2026-11-24 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Current rejection and exact successor; receipt unchanged/guard PASS; priority replaced; unwired helper pattern updated. |
| CHANGELOG | Review entry added; historical CB198 link reconciled. |
| ROADMAP | Current route updated, no milestone change. |
| Selector manifest | n/a — accepted selectors and prior manifests unchanged; proposed new TB179 gate input freezes one additional identity, not acceptance. |
| LESSONS | Existing exact-freeze, real-producer guard and semantic-ownership lessons apply; no new general lesson. |
| Consolidation under CLEAN_UP_POLICY | CB198 compile-only record and historical orientation currency preserved verbatim in [M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#tb-rev-178-folded-records--2026-11-24-utc), original filename/index, hash and source retained. Current TB178 report, CB199A build, exact proposal and required evidence retained. |
| Successor frozen | `M6-CP3-CB-199B-P13-RETRACED-TRACE-SELECTION`; exact diff, pre/postimages, new gate input and falsifiers in [plan](gates/Architecture_M6_CP3_CB199B_P13_Retraced_Trace_Selection_Exact_Manifest.md). |
| Turn boundary held | No project build or runtime; proposed diff lives only in review document. No live product/test/fixture/selector/build byte changed. |
| review_check.py boundary | Executed; no code/selector mutation and every frozen selector hash matches local snapshot HEAD. Four Git-history checks fail because archive lacks rewrite-base history. Independent GitHub compare proves `8b7299b43764a6ba3444e5bc774a2f1b65e99731` ancestor; exact historical blobs yield all five protected headings, all retained (handoff 4/4, orientation 1/1, tracker 0/0). Compare `de65101e..62be7ebc` (17 commits) lists only docs/control changes, no code drift. This is not a clean local history-check exit. |
| Documentation drift audit | 0 errors; four warnings (three protected landing-page updates authorized by review closeout and explicit user authorization; pre-existing orientation size reduced from 43,127 to 38,205 bytes, still above heuristic budget). No policy or frozen source/selector mutation. Prior historical currency folded, residual navigation bloat remains. |
| `STATUS` lifecycle maintained | Entry IN_PROGRESS, start 2026-11-24T04:27:38Z, no resumed time. Final direct beacon only after successful durable closeout; exact successor in plan. |
| Pushed to origin, branch in sync | Connector/Drive workflow is the authorized equivalent of local push; verify semantic commit and branch after transport, before final STATUS. No local remote Git history available. |
