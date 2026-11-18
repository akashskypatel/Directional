# TB139 P13 slide-contact helpers — full gate execution (MATCH)

## Situation

`M6-CP3-TB139-P13-SLIDE-CONTACT-HELPERS-FULL-GATE-EXEC`. Entry 2026-11-18T15:56:41Z, beacon `11cebb66b63c89c114fe77fac3b1f4c9c968e78f`. Resume 2026-11-18T16:23:01Z, beacon `7fdcaaa37bc4740d856b3b01c35c3e497e22fc4a`. **MATCH: 959/959 prior rows; new rows 957 and 958 PASS.** This is execution evidence, not independent acceptance. PR #8 remains draft, open and unmerged.

## Background — immutable authority

[CB164 record](Architecture_M6_CP3_CB164_P13_Slide_Proposal_Receipt_Code_Build_Record_20261118.md), [RA-260 S3](Architecture_M6_CP3_TB138_P13_Departure_Chord_Classifier_Switch_Full_Gate_Independent_Review_20261118.md#s3--cb164-slide-proposal-receipt-frozen-and-the-tb139-re-freeze) and RA-259 S4–S6 freeze this gate. Source and executor `4d8ddfee7dfa8dc651406cfb1de816027c859df2`, package `14440134091`, ZIP SHA-256 `5b4a2c7db08cb610dfa2388b7a0e5898435a154b82da09cc61c232b4e92d6c8a`, root manifest `dbbae6c6294e09c87360a1c39394bdc056bbe3b1ade2c287a9457fba2bbc76f8`, source archive `8c35fd07525eaf0e0b9d1fa45618ad92804d74913ed6691dcfbe5bc9fb6f75e1`. All 28 checksums and six archived executable modes passed. Source status clean; eight GNU Multiple Precision library (GMP/GMPXX) compile targets. No local product execution.

Snapshot `2b81dbe12c6c19b6b1982fc326aa05baacab9755`, run `44341605859`, job `134933033963`, artifact `14443093942`, ZIP SHA-256 `d2fa9f399147eca68169cbc658540d34323ee5a843208d470ab637127f1e70eb`, archive `1121e3d47fc03cdad8282a973c5599363b964b0723f97df68ff8f9cbe7d0d573`. All 5,571 source checksums passed; 414 product/test/benchmark/CMake files equal the packaged source. The snapshot-to-resume branch comparison showed only STATUS, dispatcher slot, checkpoint and snapshot-marker removal. Intended documentation preimages remain unchanged.

| Frozen input | SHA-256 |
|---|---|
| [Gate](gates/Architecture_M6_TB139_P13_Slide_Arrival_And_Carrier_Contact_Helpers_Full_Gate_Case_Manifest.tsv), 958 rows | `96766f760965c01216cbe94f92f67eefcfc40bf78e17dbcd5379bee7556f2d29` |
| [Census](gates/Architecture_M6_TB63_P13_Census_Case_Manifest.tsv), 3 rows | `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` |
| [Deferred ledger](gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv), 81 rows | `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` |
| [Harness](tools/m6_cp3_targeted_artifact_harness.sh) | `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` |

## Assessment — exact execution

| Role | Event SHA | Mailbox key | Request SHA-256 |
|---|---|---|---|
| Gate | `0c020b4c5f5eb2c1351c0287ec9c2e8e1d59bf47` | `m6-cp3-tb139-gate-v1` | `021a3aa2e19c45a30c137e7c5370aa996a0d1a1a37c226bb3786ffd3a0242d08` |
| Census | `7318cf02eec61614999776b3573864b74fb30103` | `m6-cp3-tb139-census-v1` | `d2d9a39243f15639f03db6759034f32f01a5f0811a3e4746e7c169400ecfb8e9` |

| Role | Run (attempt 1) | Runtime job | Mailbox job | Runtime UTC | Harness exit |
|---|---:|---:|---:|---|---:|
| Gate | [44342203557](https://github.com/akashskypatel/Directional/actions/runs/44342203557) | 134935371444 | 134943265450 | 16:01:27–16:12:33 | 90 |
| Census | [44342268997](https://github.com/akashskypatel/Directional/actions/runs/44342268997) | 134943911621 | 134946820605 | 16:13:41–16:17:37 | 0 |

Both mailbox records bind the event and source. Both schema validators and request parse passed; compile, Drive apply and noop skipped. Gate job failed on the unchanged permitted RED, not an orchestration failure. Census job succeeded. No duplicate dispatch, rebuild, configure, relink, binary repair, discovery or product/test/fixture/workflow change.

| Artifact | ID | ZIP SHA-256 |
|---|---:|---|
| Gate result | 14444439110 | `b4fb0f44f382756b6a51e40f23955aebf6301d82f48b6dbb8d5f87c31c5a1d6e` |
| Gate harness log | 14444932682 | `538feb3d7909b74a58f88ce4c7a8cf0272438711a8266cf89576c0bba68bef96` |
| Gate reusable log | 14444019883 | `95c9abb4b8a514a53f4989e08455972902be8b57c17e1e9d99284f7ec7865909` |
| Census result | 14446181288 | `ac6d424e6412cc634b54e1d69d6bcf5c332a8b81ef90cdcb5c069371c3b50ca0` |
| Census harness log | 14444674102 | `efc6de3c3e34a83666742464a2335d5ff0516bda22f489f74d1bc00bbefb3bb6` |
| Census reusable log | 14446935819 | `ba0d8a7cc1b0f00ada348edcb80151b45aca37663059d2aea9354a69f1dc3a77` |

All six outer hashes match. Baseline [TB138 execution](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb138_p13_departure_chord_classifier_switch_full_gate_execution_report_20261118md) gate `14425931505`, census `14425229608`; 1,929/1,929 baseline and 1,933/1,933 candidate checksums passed. Compare complete manifest coverage, row identities, ledger fields and raw-log hash bindings. Apply only N1 GoogleTest times, N2 CRLF, N3 complete region-record framing/order, N4 census opaque parameter bytes, and N5 whole lines beginning `FieldAlignedCurveNetwork.slideProposal`. All other receipts stay byte-identical. Eleven offline comparator controls passed; these checks are not product tests. Per-row seed comparison uses the common face, carrier and slide-end fields in order, not an additional log normalization.

### Gate — MATCH

958/958 executed, 957 PASS, one permitted RED (row 858 `apicensus:19`, `SurfaceCellTracingDisplayTests.cpp:155`). Row 648 remains unreached at its sphere assertions. No missing, skipped, duplicate, abnormal, unexpected pass, later-positive RED or incorrect RED site; postflight valid. Membership 1,039: prior 1,037 plus the two frozen identities, 958 gated and 81 deferred. CP2 prefix 491/491. All 956 prior gate rows match under N1–N5. All 1,738 complete region records and 66 other receipts equal. Zero departure-chord crossing and edge-port departure lines. New row 957 `FieldAlignedCarrierOccupancy.ArrivalInsideASlideAddsTheFacePieceAndTheCarrierRun` PASS; row 958 `FieldAlignedCarrierOccupancy.FirstCarrierContactMeetsEntriesAndSlidesAcrossFaces` PASS. The helpers are unwired; these tests do not establish production correction.

### Census and slide receipts — MATCH

Three fresh processes, one PASS and two report-only RED, exit 0, valid postflight; all three rows match. All 68 other receipts across gate and census are byte-identical; zero departure-chord crossing lines; 48 departure lines (BunnyRandom only).

| Scope | Result | Seed | Vertex | Grazing | Total |
|---|---|---:|---:|---:|---:|
| Gate | 957 PASS / 1 permitted RED | 0 | 0 | 1200 | 1200 |
| Cylinder | PASS / 288 quads | 0 | 0 | 0 | 0 |
| BunnyRandom | RED / trace 82 conflict, nodes 220/222, no output | 48 | 3 | 15 | 66 |
| Vase | RED / completion, AggregateCompletionValidationFailure, no output | 0 | 0 | 0 | 0 |
| Total | 961 rows | 48 | 3 | 1215 | 1266 |

[Per-row slide-kind counts](evidence/Architecture_M6_CP3_TB139_P13_Slide_Proposal_Counts_20261118.tsv), SHA-256 `8d21f1300a6461fcdd5ad74a692589379584c19feed9eec04c42104b4e71335c`, 961 data rows; all 961 seed identities PASS. Twenty gate rows contain grazing receipts (380, 388, 393, 394, 396, 397, 644, 645, 648, 669, 686, 691, 693, 694, 698, 699, 700, 843, 844, 858). The three BunnyRandom grazing predictions are present in the raw log: trace 43 segment 11 face (60,126,290), carrier (60,290), end 290; trace 43 segment 13 and trace 15 segment 19 face (94,124,210), carrier (94,210), end 94. Each appears three times. These are receipt counts, not distinct physical slide or successful contact counts. All 48 seed lines match departure lines in common projected fields and order. Cylinder has no slide receipt; this is a measurement, not proof about all executions.

### Regression disposition

No new stable regression or candidate. H3 narrow closure retained. H4 geometry consumers remain open; CB164 measures, not fixes, their skipped slide start. The two helper controls and exact equality provide execution evidence only; independent Review must adjudicate before freezing CB165/CB166. C5/O47 sphere transverse endpoint at P and O48 BunnyRandom shared-carrier interval [X43,v94] remain open. The trace-82 conflict and Vase completion RED are unchanged. Row 858 permitted RED and row 648 assertion reach remain unchanged. C5/O42/O43/O46/O47/O48, H4, H2, FC-1/FC-4 and middle-piece direction witness open; O45 narrow closure retained; FC-6, terminal-cut and row858 held. Stable 66 events / 17 categories / 49 recurrences, debt 1, deferred 81; CP2 491/491; CP3 selector497 frozen, not accepted. D11=A, D12=A, D10 deferred, D6 pending, `chainRimSchedules=false`. No CP3/D0 promotion.

### Procedure and preservation

First-attempt checkpoint commits `17289e208bb0761daaa3b8781aef00e2fa5f7f24` and `085355ee91983b57fe6a6747d0b09b33fe9aadac`. Cleanup run `44343856306`, job `134940942615`, commit `4bae7f6166c0d8bed01b9d2bba55045eae5c2fff`, result `14444677380` SHA-256 `696a899c4c8b77e7e2543184946eb9a802757ad0f830db35f93e93ab128b925a`; log `14444986869` SHA-256 `584d053aed768621f652b0f00c47d3d155285c3d363d61c6971281130dc51a09`. Snapshot trigger and manifest removed; ten durable workflows retained; zero PR comments deleted. First-attempt Library archives `Directional_TB139_resume_20261118.zip` (SHA-256 `d799d68262bb603e7754257065b277f1010d377f19683d8d306e1842ffda7262`) and `Directional_TB139_closeout_checkpoint_20261118.zip` (SHA-256 `f088eb98156f0e5229d448443518d1c687cf15fa8455f35e1072bd2db37254fd`) retained. Resume recovered both exact previously dispatched results; no repeated product execution. Initial policy/source reads preceded snapshot selection, skill repository SKILL.md returned 404, first-attempt shell timer started late; full mandatory policy/skill read and cross-attempt tool accounting unconfirmed. Local Git baseline contains verified snapshot preimages, not historical Git objects; workspace ownership correction was local only. Remote comparison supplies unchanged-path authority. Preserve primary artifacts and comparator outputs in the Library execution archive; independent Review remains separate.

## Recommendation

Exact next `M6-CP3-TB139-P13-SLIDE-CONTACT-HELPERS-FULL-GATE-REV` (independent Review). Re-open the primary artifacts and independently verify both new controls, every prior row, complete receipt identities and count/prediction evidence under RA-260 S3. Review owns the CB165 piece helper and CB166 staging decisions. Do not start CB165, CB166, CB167, CB168 or any held definition in this execution turn.
