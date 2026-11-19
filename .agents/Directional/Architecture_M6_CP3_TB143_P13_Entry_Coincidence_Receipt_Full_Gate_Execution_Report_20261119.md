# TB143 entry-coincidence receipt — Test + Benchmark execution

## Situation

`EXECUTION COMPLETE — strict prior-log comparison exception`. Full gate run [44441063722](https://github.com/akashskypatel/Directional/actions/runs/44441063722) reached terminal `failure` only because the known row 858 RED makes `control_bad=1`. All 960/960 rows executed: 959 PASS, one unchanged RED, zero skipped, missing, abnormal, duplicate or unexpected positive cases. New row 960 PASS. The 491/491 accepted prefix remains PASS. This is **not** a green full gate or production acceptance.

## Background

Immutable compile package `14488684741` from source `b77a81ff5250aabbf6dd58cf4e9e6c208d4a973f`: original ZIP SHA-256 `7dbeb68dd7832fd75976646b77575b3b7848f3bd58a3fe2de005aa41fdd7da39`; 28/28 internal hashes verified; runtimeExecution=false during compile. Full gate result artifact `14490999571`, ZIP SHA-256 `ffa03f7e359eeed8e76ad3f4f7a1624bed5f69d44c97a50b860939a8a044b11d`, 1,928/1,928 internal SHA-256 checks; separate log `14491976376`, ZIP SHA-256 `f2b44df5df726f4d263732504e97bcab65ee802b2ca89941528e433aa1d5bcd9`. No compile, configure, relink, source, test, selector, fixture or benchmark changes during TB.

Census [run 44441139661](https://github.com/akashskypatel/Directional/actions/runs/44441139661) completed successfully. Result artifact `14492518198` ZIP SHA-256 `4089fc0de5bf38620f98e077b80a0b00706c17240869ff564ff36eb9b8b7cfa1`, **9/9** indexed SHA-256 checks; separate log `14492663147` ZIP SHA-256 `31bb6885bee5c312c6d49c9da9e39dc15204b9eaec6a26e06d3b73fc0fa78d56`. Three of three executed, Cylinder PASS, BunnyRandom RED, Vase RED, no skipped, missing, abnormal, duplicate or unexpected-pass cases, exit 0 and `postflight=true`. No build/configure/relink/benchmark took place. All three prior census ledger records and logs match TB142 under frozen N1/N2/N4/N7 (N3 not required); raw N5/N6 receipts are byte-identical. Thus **960/962** prior logs are exact normalized matches when combined with 957/959 gate matches, and **2/962** are strict deviations (gate rows 169/477). This is not a 962/962 MATCH.

## Assessment

- Prior 959 gate ledger rows match TB142 for identity, selected test, binary, verdict, exit and first-failure/reason. Membership 1,041 entries is byte-identical. Row 858 still RED at `tests/SurfaceCellTracingDisplayTests.cpp:155`.
- N1 GoogleTest timings, N2 line endings, N3 full `region_support_projection` record ordering, and N7 exact complete-line removal of `FieldAlignedCurveNetwork.entryCoincidence ` were applied in the offline comparison. N5 `slideProposal` and N6 `committedSlide`: 1,200/1,200 gate **raw** lines and 66/66 census **raw** lines of each kind match TB142 byte-for-byte (1,266 records of each type across both runs).
- **Strict comparison exception:** 957/959 prior gate logs match after N1–N3 and N7. Rows **169** and **477** each contain two complete `region_support_projection` records joined with no newline and one extra blank line. Their parsed record values and counts match the baseline; exact line layout does **not** match under the frozen normalization list. Independent Review must decide if this is an output-interleaving presentation issue. Do not claim 959/959 or 962/962 strict equality.
- Raw gate entry-coincidence receipts: **240 lines in 20 rows**, 40 distinct fixture-scoped tuples. All observed tuples are the exact pair sets `4:7/6:7` on `(0,2)` and `15:7/19:7` on `(25,27)`, both at `574181338608147/4503599627370496` (double `0.12749386848657163`). The full per-row census is below; repeats are separate producer invocations within a row, not independent fixture identities. In the three-case census, BunnyRandom adds **six** receipt lines (two distinct contacts repeated three times): `15:21/43:15` carrier `(72,243)` at `191903898244039/562949953421312`; `15:22/43:16` carrier `(72,273)` at `1755811011335563/2251799813685248`. Cylinder and Vase add none. These observations do not prove the BunnyRandom routing defect is repaired.
- All **66** `EmbeddedGraphTopology.duplicateCutCrossing edge=(0,2)` records in **19** sphere rows have a matching `entryCoincidence first=4:7 second=6:7 carrier=(0,2)` with the exact binary rational. No missing sphere witness was found. Row 693 contains a receipt without that crossing diagnostic; this is not evidence of a new mismatch.
- Other execution failures remain the baseline debt, not proof of a repair: sphere C5/O47, BunnyRandom trace82, Vase completion, and row858. Stable regression accounting **66/17/49**, debt **1**, deferred **81**; selector497 frozen and no product promotion. The two log-format differences are an *unadjudicated presentation candidate*, not an added stable regression.

### Gate receipt census (all source logs retained in artifact)

| Row | Fixture identity | Raw lines | Distinct tuples |
|---:|---|---:|---:|
| 843 | `apicensus:12` | 6 | 2 |
| 844 | `apicensus:13` | 6 | 2 |
| 858 | `apicensus:19` | 6 | 2 |
| 644 | `offgate:180` | 6 | 2 |
| 645 | `offgate:181` | 6 | 2 |
| 648 | `offgate:185` | 6 | 2 |
| 669 | `offgate:210` | 26 | 2 |
| 686 | `offgate:229` | 6 | 2 |
| 691 | `offgate:234` | 12 | 2 |
| 693 | `offgate:239` | 6 | 2 |
| 694 | `offgate:240` | 18 | 2 |
| 698 | `offgate:246` | 18 | 2 |
| 699 | `offgate:247` | 12 | 2 |
| 700 | `offgate:248` | 18 | 2 |
| 380 | `selector:338` | 18 | 2 |
| 388 | `selector:346` | 18 | 2 |
| 393 | `selector:351` | 12 | 2 |
| 394 | `selector:352` | 14 | 2 |
| 396 | `selector:354` | 14 | 2 |
| 397 | `selector:355` | 12 | 2 |

## Recommendation

Both runs and the offline comparison are complete. The execution report must be reviewed independently. **Do not accept a strict MATCH** without resolving rows 169/477 against frozen normalization authority. No EC2/EC3, selector, source, test, or benchmark changes are authorized in this execution turn. Its separately authorized Review successor is `M6-CP3-TB143-P13-ENTRY-COINCIDENCE-RECEIPT-FULL-GATE-REV`. No successor work starts here.
