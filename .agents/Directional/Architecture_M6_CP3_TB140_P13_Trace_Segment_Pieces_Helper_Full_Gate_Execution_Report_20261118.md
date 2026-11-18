# TB140 P13 trace-segment-pieces helper — full gate execution (MATCH)

## Situation

`M6-CP3-TB140-P13-TRACE-SEGMENT-PIECES-HELPER-FULL-GATE-EXEC`. Initial entry 2026-11-18T18:24:00Z, beacon `31d154d456bdbb63fd42ee65f325d2331abface7`; continuation 2026-11-18T18:48:33Z, beacon `bf64ea2a99ac59e7ccba693dfc325bdb572dbbc6`. **MATCH: 961/961 prior rows, new row 959 PASS, no unexpected delta.** The helper has no production callers. This is execution evidence; independent acceptance and CB166 authorization remain the scope of the next Review. PR #8 remains open, draft and unmerged.

## Background — immutable authority

[CB165 compile record](Architecture_M6_CP3_CB165_P13_Trace_Segment_Pieces_Helper_Code_Build_Record_20261118.md), [RA-261 S3](Architecture_M6_CP3_TB139_P13_Slide_Contact_Helpers_Full_Gate_Independent_Review_20261118.md#s3--tb140-criteria-frozen), [TB139 execution comparator](Architecture_M6_CP3_TB139_P13_Slide_Contact_Helpers_Full_Gate_Execution_Report_20261118.md). Candidate source/executor `fb51da7142646ebed97527d976fd8b382607160a`, package `14459000178`, ZIP SHA-256 `501bc0fe607d38a14fa3afe49814809fd0a7505c18f0ad61bb2e09674ffd486e`, root manifest `b1165f72f5b888d533b4ab2a9f9a9dc4c0c1c44dbaa1047d16c6ccf76dd37057`, source archive `47afd1f7347d2029ae666ba5626aa032d658a477c0cc5b485533f7b0de0acf2b`. First-attempt verification: 28/28 package checksums, six archived executable modes, clean source status, eight GMP/GMPXX compile targets. Source snapshot `2653b6c5f3d4df9fce669ded9ebb716f35f2df85`, run `44369467893`, job `135032121854`, artifact `14459126968`, ZIP SHA-256 `d90f4abf69f6a30eaca3d3ce41aec7410108af22c494b47815fe2730834b8876`, 5,577/5,577 checksums, 418 source/build/test files matched package source. The comparison of snapshot→resume beacon gives five commits affecting only STATUS, dispatcher slot and temporary checkpoint. No product or frozen-input change.

| Frozen input | SHA-256 |
|---|---|
| [Gate](gates/Architecture_M6_TB140_P13_Trace_Segment_Pieces_Helper_Full_Gate_Case_Manifest.tsv), 959 rows | `390fe1bd2c2e5f6d490ed21dac52219acefd9646081d361d2d4e174dfdedbf52` |
| [Census](gates/Architecture_M6_TB63_P13_Census_Case_Manifest.tsv), 3 rows | `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` |
| [Deferred ledger](gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv), 81 rows | `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` |
| [Harness](tools/m6_cp3_targeted_artifact_harness.sh) | `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` |

Gate manifest equals its TB139 preimage plus row 959 byte for byte; membership 1,040. Census, deferred and harness unchanged.

## Assessment — execution and comparison

| Role | Exact event SHA | Mailbox key | Request SHA-256 |
|---|---|---|---|
| Gate | `f480107eac326df84622b79471c3867a6d6912bd` | `m6-cp3-tb140-gate-v1` | `438843d452f21bf7882eedc2ff09bac08c185e5fc9a2bf60d93f96b827c1ce6b` |
| Census | `02f1393b5604d8cee0530502f15a60c614cf02fe` | `m6-cp3-tb140-census-v1` | `83e3d450df35bd722ffb32d33a7f4a9c0a805bceff36a13024a389a0df26125a` |

| Role | Run (attempt 1) | Runtime job | Mailbox job | Runtime UTC | Harness exit |
|---|---:|---:|---:|---|---:|
| Gate | [44370095372](https://github.com/akashskypatel/Directional/actions/runs/44370095372) | 135034674976 | 135040152778 | 18:29:16–18:37:34 | 90 |
| Census | [44370153728](https://github.com/akashskypatel/Directional/actions/runs/44370153728) | 135040701951 | 135043280904 | 18:38:38–18:42:33 | 0 |

Both mailbox records bind exact event/source. Schema validation, request parse and mailbox publication succeeded for both; compile, Drive apply, and noop skipped. Gate runtime job failed because of the same permitted row 858 RED as TB139, not an infrastructure failure. Census job succeeded. Both postflight checks passed; no configure, compile, relink, package repair, discovery-file regeneration, fixture/test/source modification or repeated execution. The frozen gate used read-only `--gtest_list_tests` on five packaged test binaries to verify 1,040 membership identities; the census did not enumerate membership. No local product execution.

| Artifact | ID | ZIP SHA-256 |
|---|---:|---|
| Gate result | 14458589267 | `4816ea208223cac9c48507602d491edf9542176654d580acf25a6f2b4a989d84` |
| Gate harness log | 14457559609 | `0d80a1a4ff979deabccbdb62c726d173d079a4ff3dba85483b4eecbd25816452` |
| Gate reusable log | 14457914407 | `5b858960f258ee2c473a2591e46ac980c40c4195c058fc068ac4a2b0813536ed` |
| Census result | 14460885073 | `1c472957c6f84ac17114f3e2c070c57331eee0e261596baeb6055869d3ee9521` |
| Census harness log | 14460755159 | `439c2627f042b24bf6aa5f4ea7e5fbbcfbd59d72dc6e68dc1f91cfc9c5d24446` |
| Census reusable log | 14459154777 | `439cb3f789691c5d4faba26742edfe9933fac48936eb8ed99c52ff1a962e21d7` |

All six outer hashes match the mailbox and run artifact inventory. TB139 source `4d8ddfee7dfa8dc651406cfb1de816027c859df2`, package `14440134091`; gate `14444439110` ZIP SHA-256 `b4fb0f44f382756b6a51e40f23955aebf6301d82f48b6dbb8d5f87c31c5a1d6e`, census `14446181288` ZIP SHA-256 `ac6d424e6412cc634b54e1d69d6bcf5c332a8b81ef90cdcb5c069371c3b50ca0`. Complete checksum inventory: baseline 1,933/1,933; candidate 1,935/1,935; 3,868/3,868 combined. Compare exact membership, manifest row identities, owning binaries, verdict/exit and other ledger fields, raw-log SHA-256 bindings and raw selected-test execution summaries. N1–N4 only: GoogleTest timing, CRLF, complete region record framing/order, census opaque parameter bytes. No N5 removal. Slide, departure and other retained receipts compared in original bytes/order. Eight offline comparator controls passed (not product tests). Both candidate comparison exits 0, mismatch arrays empty.

### Gate — MATCH

959/959 executed, 958 PASS, one permitted RED: row 858 `apicensus:19` at `SurfaceCellTracingDisplayTests.cpp:155`; row 648 still does not reach its sphere assertions. No missing, duplicate, skipped, abnormal, unexpected pass, later-positive RED or changed RED site. `control_bad=1` unchanged; harness exit 90, postflight true. Accepted prefix 491/491. Membership 1,040 = 959 gated + 81 deferred; exact prior membership plus new identity. All prior 958 rows match. All 1,738 complete region records, 66 other receipts and 1,200 grazing `slideProposal` lines match. New row 959 (`ra261:trace-segment-pieces-helper`, `FieldAlignedCarrierOccupancy.TraceSegmentPiecesFollowTheFacePieceThenTheCarrier`, `directional_surface_cell_producer_tests`) PASS: one selected test, one PASS, exit 0. Raw log SHA-256 `dd5435aa33fd8f149609af550c2d918aa4e7466e2bdb2a3b0d6752fbbe67c5d8`. No unexpected receipt on this row. This proves only the frozen helper test, not a production wiring correction.

### Census and slide receipts — MATCH

| Scope | Result | Seed | Vertex | Grazing | Total |
|---|---|---:|---:|---:|---:|
| Gate | 958 PASS / 1 permitted RED | 0 | 0 | 1200 | 1200 |
| Cylinder | PASS / 288 quads | 0 | 0 | 0 | 0 |
| BunnyRandom | RED / trace 82, nodes 220/222, no output | 48 | 3 | 15 | 66 |
| Vase | RED / AggregateCompletionValidationFailure, no output | 0 | 0 | 0 | 0 |
| Total | 962 rows | 48 | 3 | 1215 | 1266 |

Three fresh census processes, one PASS and two report-only RED; all three match TB139, postflight true and exit 0. All 68 other receipts and 48 edge-port departure lines match; zero departure-chord crossing lines. All 1,266 slide lines are byte-identical, including 48 seed/departure projected identities. [Per-row counts](evidence/Architecture_M6_CP3_TB140_P13_Trace_Segment_Pieces_Helper_Slide_Counts_20261118.tsv) (SHA-256 `865e68f02c2caf2ce321883c78bc132bfb93b45b292d58e9a80ff0d7bf6502f0`); 962 data rows, 20 sphere gate rows contain grazing receipts (380, 388, 393, 394, 396, 397, 644, 645, 648, 669, 686, 691, 693, 694, 698, 699, 700, 843, 844, 858). BunnyRandom retains trace 43 segment 11 carrier (60,290), 43 segment 13 and 15 segment 19 carrier (94,210), each present three times. These are proposal receipt counts, not committed path or contact counts. Cylinder's passing result does not promote the representative matrix.

### Regression disposition

No new stable regression or candidate: every previously measured row and retained receipt agrees with the reviewed TB139 comparator, and the only new row passes. Existing C5/O47 sphere and O48 BunnyRandom shared-carrier interval, the trace-82 conflict and Vase completion rejection remain open, not new events. H3 closure remains narrow. H4 remains live; the unwired helper does not yet correct paths/rays, evidence-only local chords or polyline consumers. RA-261 S4 controls the consumer-specific switch and the positive-overlap-at-vertex rule remains required before CB170. C5/O42/O43/O46/O47/O48 open; O45 narrow consumer-proxy closure retained; H2, FC-6, terminal-cut and row858 held; middle-piece direction witness open. Stable 66 events / 17 categories / 49 recurrences, debt 1, deferred 81, CP2 491/491; CP3 selector497 frozen and not accepted. D11=A, D12=A, D10 deferred, D6 pending, `chainRimSchedules=false`; no CP3/D0 promotion.

### Procedure and preserved evidence

First attempt committed both requests; new response recovered their existing terminal records without rerun. Exact initial checkpoint `4f15876978bb7adfab5c4ddc5d3f22d3f7174cc1`, incomplete beacon `952b59460d2bede996d5cd96bd42f693e4fa4fac`. Library archive `Directional_TB140_verified_execution_20261118.zip`, SHA-256 `41198ab6add12e2e919ee2f7c60d0af9d42bf488312527c4b604ac426c907cf1`, contains candidate and baseline archives, comparison scripts/results, preflight evidence, request records, manifests and deadline record. Prior continuation files retained. First-attempt direct reads preceded selection of snapshot mode; corrected via verified snapshot. External turn-based skill returned 404; complete mandatory context reading and cross-attempt exact tool accounting not attested. First-response timer reminder unavailable; recorded bounds observed; continuation shell reminder set with 15-minute closeout deadline. The local snapshot Git baseline uses verified preimage bytes, not historical Git objects; scratch directory ownership corrected locally only. No policy or workflow change.

Cleanup [run 44374224785](https://github.com/akashskypatel/Directional/actions/runs/44374224785), job `135049026057`, event `111ce814b3860837cbc209efbc4fc88a80f1ab5f`, commit `bc776d93f94739fbf4ca7ad1a54c768182845e4f`; result `14459224218` ZIP SHA-256 `aab57658ace5f0205d9bf9610bfe9f7a171d73a877467aed8dd2aaf8f8895d6e`, log `14459298994` ZIP SHA-256 `38bda66afddecd7911bfc7b1c336cf05c4ee8ed4dd478bfd80387e995153f47f`. Both verified; current marker and manifest removed, ten durable workflows retained, zero PR comments deleted. Snapshot→cleanup comparison shows only dispatcher slot, STATUS, temporary checkpoint and marker removal. The six documentation paths have unchanged preimages or remain absent. Unrelated historical markers are not within this cleanup scope.

Documentation drift audit: baseline 0 errors/warnings; prepared tree and projected successor 0 errors, one protected-handoff edit warning. The warning is the authorized in-place lifecycle update; all durable headings, policies, frozen definitions, accepted evidence and unresolved obligations remain. Retain CB165/TB139 primary authority for the independent Review; consolidation is not part of this execution turn.

Closeout application [run 44375376509](https://github.com/akashskypatel/Directional/actions/runs/44375376509), job `135053332376`, event `7f4ed94522bdab1f4a6a94ea2fb871843aaf3666`, applied commit `335aa5bdbd980888fbf9d87960dcba4473ab3c70`; result `14460822751` ZIP SHA-256 `504b152251884031e85a5531108415cdb02f32409741c8285f318fa4ceee78a9`, log `14461327584` ZIP SHA-256 `7960b633272275bd69ea0ecd6986ffbd97c72fecff85cc8a29dcac420b59819f`. Both digests and all six remote postimage Git blob IDs matched. Patch SHA-256 `d4de02313cb41a9994b0078849c249bde631832943490af8c6cbdeff25704c75`, diff body `d5f28eb4b82f8c7056d64bca3e95ed60d45c01201cd68e41a43048c28850d220`. The Drive owner-retirement call succeeded; temporary checkpoint retired in `315225f59646aca919c41b8c874d7cdef62c07d4`. This clarification corrects the original report wording about membership enumeration, not a runtime result or the frozen harness.

## Recommendation — exact next Review

`M6-CP3-TB140-P13-TRACE-SEGMENT-PIECES-HELPER-FULL-GATE-REV`: independently reopen immutable TB140/TB139 evidence, rederive the frozen MATCH and new control's scope/non-vacuity; adjudicate before freezing the exact CB166 embedded-graph path/ray patch and TB criteria under RA-261 S4.1. No CB166 implementation, runtime rerun, source mutation or CP3/D0 promotion in this execution turn. Historical conditional STOP and infrastructure routes in RA-261 S3 do not apply to this MATCH.
