# TB141 P13 committed-slide receipt full gate execution — MATCH

## Situation

`M6-CP3-TB141-P13-COMMITTED-SLIDE-RECEIPT-FULL-GATE-EXEC`: entry 2026-11-18T21:09:32Z (`43d84e045c00c17ed7156239f3e32de44852b3ea`); resume 21:33:16Z (`1bb6d97aac9e670318f4fae55a33bbbdb2c46b63`). **962/962 MATCH under N1–N6.** No new test identity, independent Review, product correction or promotion. PR #8 open draft, unmerged.

## Background — immutable authority

[CB166 compile record](Architecture_M6_CP3_CB166_P13_Committed_Slide_Receipt_Code_Build_Record_20261118.md), [RA-262 S3–S4](Architecture_M6_CP3_TB140_P13_Trace_Segment_Pieces_Helper_Full_Gate_Independent_Review_20261118.md#s4--cb166-and-tb141-frozen), [TB140 execution](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb140_p13_trace_segment_pieces_helper_full_gate_execution_report_20261118md). Source/executor `3b599879ac05a79fb2ddce9a930da3683051017d`, package `14468664897`, SHA-256 `02382960246e34577e34780b842472213ac7fa6925d60dc886fba2f7273d7ddc`, root manifest `c56c3e38e1151a2eae9776957c06ca4fecb94b8f8e2692bf0147e9cdf5162561`, source archive `cfaca03117adbe12942dd1eab2b7f66c2dc00b8b33dbc96da03830ba601b797a`. Compile log `14468509984`, SHA-256 `c757996d5bdc776e2307bade02e112456fbeae10a8e8c6cdaf1a49631a69522e`. Preflight 28/28 checksums, six ELF executable modes (755), eight GMP/GMPXX compile targets, clean source, runtimeExecution=false. Runtime harness verifies immutable package, preserves modes; dependency logs show no missing libraries, producer links GMP/GMPXX. No local product execution, configure, compile, relink, package repair, source/test/fixture/selector or digest edits. No discovery regeneration.

Source snapshot `28d8f9275ac5cff98f1209c2d4db3e2d61c1139b`, run `44398697102`, job `135135652806`, artifact `14472107893`, ZIP SHA-256 `7262cd04300bd352ad769a634e7e5aa6c977dc96cff88d0f53c2f15cd87267e1`; archive `69d773d645d8c9aff34d1ac942b66b6fd87dced838c8b4dcc3659dcc2a54e21a`; 5,582 checksums reverified. Snapshot→resume comparison: five commits, STATUS, dispatcher slot, temporary checkpoint only. No semantic or frozen input drift.

| Frozen input | SHA-256 |
|---|---|
| [Gate, 959 rows](gates/Architecture_M6_TB140_P13_Trace_Segment_Pieces_Helper_Full_Gate_Case_Manifest.tsv) | `390fe1bd2c2e5f6d490ed21dac52219acefd9646081d361d2d4e174dfdedbf52` |
| [Census, 3 rows](gates/Architecture_M6_TB63_P13_Census_Case_Manifest.tsv) | `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` |
| [Deferred, 81](gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv) | `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` |
| [Harness](tools/m6_cp3_targeted_artifact_harness.sh) | `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` |

## Assessment

| Role | Event SHA | Request SHA-256 | Mailbox key |
|---|---|---|---|
| Gate | `f78b7a45ef330b51ce46bd1bf92a6bd09783d837` | `f2b72ba2eb9c62391d7affdfe0c2dd210fd378f9feb02b321ef1af43f77ec19f` | `m6-cp3-tb141-gate-v1` |
| Census | `d8c31d792b0ebcae6b6b4bb003af97121e87cbb4` | `e028a9f20e7a0dd5d9665380defd5b6a0b2ac177b81bbbfd446767022b18b319` | `m6-cp3-tb141-census-v1` |

| Role | Run (attempt 1) | Runtime job | Mailbox job | Runtime UTC | Exit |
|---|---:|---:|---:|---|---:|
| Gate | [44399195712](https://github.com/akashskypatel/Directional/actions/runs/44399195712) | 135137438653 | 135145350213 | 21:13:44–21:26:18 | 90 |
| Census | [44399200774](https://github.com/akashskypatel/Directional/actions/runs/44399200774) | 135145910098 | 135148431113 | 21:27:25–21:31:20 | 0 |

Schema validators, request parse and mailbox succeeded; compile, Drive apply, noop skipped. Gate runtime job failed because of the same permitted RED, census succeeded. Postflight true both. Exact terminal mailbox identity verified, no repeated tasks.

| Artifact | ID | ZIP SHA-256 |
|---|---:|---|
| Gate result | 14473040819 | `5f53a3990d5e49ea08f1440180fb155409229c4739e7b851a4081d1a0f0a47d6` |
| Gate harness log | 14473285645 | `ac2d63f76dc9f006c08d8226fba0ea1a9f5657a904a99db4183672827de6a91c` |
| Gate reusable log | 14472701054 | `3b6975022a2912b7a52d73676bc0498cfc1328012d5d0a4fa008ab3baff1e564` |
| Census result | 14473701160 | `fa4afc3b5004e485d34d073e3d26b9897ffab68716203129aa3a12a5c7e86571` |
| Census harness log | 14474490720 | `93a74e61e1ed4873be619c1d73e89c55eb7af916d9575e7f63d2375de4295d6b` |
| Census reusable log | 14473171358 | `d8a860e8422150bb9f64d3904a6b7cd79b98fd9d90049b7fef29d5ebf359f50b` |

Six ZIP hashes match terminal mailbox. TB140 comparator source `fb51da7142646ebed97527d976fd8b382607160a`, package `14459000178`, gate `14458589267` (`4816ea208223cac9c48507602d491edf9542176654d580acf25a6f2b4a989d84`), census `14460885073` (`1c472957c6f84ac17114f3e2c070c57331eee0e261596baeb6055869d3ee9521`). Baseline and candidate each 1,926 gate + 9 census checksums = 3,870/3,870 verified. Comparator verifies exact ledger identity, selected-test execution, log hash bindings, boundary and membership; both exit 0, empty mismatch/R-x arrays. N1–N6 only: GoogleTest timing, CRLF, region-record framing/order, census opaque parameter bytes, N5 slide proposal comparison (raw bytes retained), N6 removes only well-formed committedSlide lines. All retained logs, other receipts and 1,266 raw proposal lines match. Nine prior offline comparator controls passed (not product tests).

959 gate rows executed; 958 PASS, one permitted RED 858 (`apicensus:19`, `SurfaceCellTracingDisplayTests.cpp:155`, `faceLocus.sourceFace.has_value()` false). Row648 still does not reach its sphere assertions; row959 PASS. No missing, skipped, duplicate, abnormal, unexpected PASS, later-positive RED or changed RED site. `control_bad=1`, exit 90, postflight true. Accepted prefix 491/491; exact membership 959 gated + 81 deferred = 1,040.

| Scope | Result | Proposals | edgeOnly/0 | edgeOnly/1 | faceThenEdge/0 | faceThenEdge/1 |
|---|---|---:|---:|---:|---:|---:|
| Gate | 958 PASS / 1 permitted RED | 1200 | 0 | 0 | 0 | 1200 |
| Cylinder | PASS / 288 quads | 0 | 0 | 0 | 0 | 0 |
| BunnyRandom | RED / trace82 conflict, no output | 66 | 0 | 51 | 0 | 15 |
| Vase | RED / AggregateCompletionValidationFailure | 0 | 0 | 0 | 0 | 0 |
| Total | 962 rows | 1266 | 0 | 51 | 0 | 1215 |

All three census outcomes and retained logs match. Proposal kind inventory 48 seed, 3 vertex, 1,215 grazing. Retained segment receipt kinds: 51 edgeOnly, 1,215 faceThenEdge; all traversed=1. Independent scan proves equality of proposal and commit multisets keyed by trace/face/carrier/slide end for every contiguous commit block (120 gate, 3 census); no duplicate trace:segment in a block, invalid index, missing slide end or excess receipt. The emission loop at SurfaceCellTracing.cpp:4590–4641 follows terminal-kind validation but precedes downstream event finalization/graph construction. The receipts prove retained segment traversal, not graph publication. All 1,200 gate receipts are last-segment. BunnyRandom edgeOnly 42 non-last + 9 last; faceThenEdge 9 non-last + 6 last. Trace43:11 (60,290), 43:13 and 15:19 (94,210) each appear three times as traversed non-last faceThenEdge. Twenty positive gate rows: 380, 388, 393, 394, 396, 397, 644, 645, 648, 669, 686, 691, 693, 694, 698, 699, 700, 843, 844, 858. Counts include repeated executions, not unique physical slides.

- [Per-row counts](evidence/Architecture_M6_CP3_TB141_P13_Committed_Slide_Counts_20261118.tsv): 962 rows, SHA-256 `b58c932a7d01b95213f519ce117fb92de751e1732446242ff2ff6259ed9bbc4c`.
- [Every traversed receipt](evidence/Architecture_M6_CP3_TB141_P13_Committed_Slide_Traversed_20261118.tsv): 1,266 records indexed by scope, row, block and raw-log line; SHA-256 `86eff4e201e0fad771a49ff136e68400c1a0c39e7e223eefafc2129349bda805`. Row identity in counts table; raw logs in immutable artifacts.

**Regression disposition:** no new stable event or candidate; all previous outcomes and retained logs match. Existing row858 RED, row648 unreached, C5/O47, BunnyRandom trace82 (nodes 220/222) and O48 shared carrier interval, Vase completion RED remain. H3 narrow closure unchanged. H4/O49 open. R0 no-traversal hypothesis contradicted; zero R-x; R+/R-edge adjudication and graph-publication reach proof belong to Review. Stable 66/17/49, debt 1, deferred 81; CP2 491/491, selector497 frozen; D11=A, D12=A, D10 deferred, D6 pending, chainRimSchedules=false. No CP3/D0 promotion.

## Recommendation

Independent runtime-free Review `M6-CP3-TB141-P13-COMMITTED-SLIDE-RECEIPT-FULL-GATE-REV`: verify exact artifacts, comparison, receipt blocks and affected trace:segment set; decide publication reach (especially RED BunnyRandom), adjudicate RA-262 S3 and freeze CB167 only after decision. No successor work in TB141 execution.

Procedure: both prior requests recovered without rerun. First response had premature direct reads and external skill 404; full cross-attempt checklist and exact tool accounting not attested. Resume snapshot and comparison inventory reverified. Original documentation audit zero errors/warnings. Local scratch Git ownership setup failed and was corrected without modifying source. Documentation-only work-preservation patch; cleanup and final beacon require separate verification.
