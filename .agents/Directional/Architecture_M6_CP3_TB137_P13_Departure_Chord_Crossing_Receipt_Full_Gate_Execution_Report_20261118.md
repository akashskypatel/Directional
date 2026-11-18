# TB137 P13 departure-chord crossing receipt — full gate execution (MATCH)

## Situation

`M6-CP3-TB137-P13-DEPARTURE-CHORD-CROSSING-RECEIPT-FULL-GATE-EXEC`. First entry 2026-11-18T09:57:01Z (beacon `442c0f1a4738fca93d259ee7152ee99ab030c0df`), resumed 2026-11-18T10:23:19Z (beacon `5bdfb99d5480b48f1a5e0befb7d3d600b8555775`). **MATCH under RA-258 S4: 957/957 existing rows, row 955 PASS, zero departure-chord crossing receipt lines.** No independent Review or production acceptance. PR #8 stays draft, open and unmerged.

## Background — verified immutable authority

[CB160 record](Architecture_M6_CP3_CB160_P13_Departure_Chord_Crossing_Receipt_Code_Build_Record_20261118.md) and [RA-258 S4](Architecture_M6_CP3_TB136_P13_Carrier_Occupancy_Helpers_Full_Gate_Independent_Review_20261118.md#ra-258--adversarial-re-review-of-this-review-2026-11-18-utc) govern this turn. Source and executor `66fb0c5ec42fa57614a504437724b18d7004cbb1`; package `14414860103`, ZIP `8b2277e9e5ac2fc71ffe4e61a6012e5ac892f2a92c0f03b24613d695437aaec2`, root manifest `2946a306b0f9d6d655188d5fcaf2ad9f7433d2a075e96ee85d818b82639e0b1e`, source archive `30dc5fad7dfb3f9eaf097c62d4eff8a0125faecb958461c52a7eee36e9671911`. 28/28 checksums, six archived executable modes, five empty source status files, eight targets and GMP/GMPXX verified. Snapshot run 44280817854, artifact 14416342764, source `a76e728b9aa2f15430051e7afb4a32e072af6a6c`, ZIP `248a14867359010f2adbb293af6686276b646d6f1768b0b8c6402810f4206712`: 5,556 checksum checks passed; 515/515 checked source/test/fixture/tool/workflow files agree with package. Frozen gate 955 (membership 1,036 including 81 deferred); census 3. Manifest-only checks and 16/16 offline comparator checks passed. No candidate binaries executed locally.

## Assessment — exact submitted requests and terminal execution

| Role | Event commit | Mailbox key |
|---|---|---|
| Gate | `6eb87284f2aef7cb53e9d9e7440de31152514f94` | `m6-cp3-tb137-gate-v1` |
| Census | `9c15ecec7045b6074c4fe95e45cd8acd13cece15` | `m6-cp3-tb137-census-v1` |

Both exact requests are committed, their content blob hashes match local generation, and the dispatcher serializes them on this branch. No source, test, fixture, harness, package or workflow definitions changed. Baseline TB136 gate `14406791564` and census `14406826878` verified against their digests, membership and all raw log bindings (957 rows, 1,925 checksums). Local comparator applies N1–N4 and N5 (strip only complete lines beginning `FieldAlignedCurveNetwork.departureChordCrossing `); verifies other receipt bytes, row 955 PASS, counts per row and distinct crossing records, and existing departure counts. No count is predicted. Offline checks do not establish runtime results.

Both runs are terminal. Mailbox event SHA, source SHA, run/job identities, request hashes and reusable/harness logs agree. Gate request SHA-256 `5c331615b691476b9d8e4900272c135d598e18f8c3ef2a6f5d7debaea999b617`; census `60380e5c3c364af3b65b1ccd004ec7b5df9f645dca1ff2d5f54d7f410e8e193b`. All six ZIP SHA-256 digests below match the mailbox inventory. Both schema validators and request parse passed. Compile, Drive apply and noop were skipped in both runs. No duplicate dispatch, local runtime, rebuild, relink, configure, binary repair, or source/test/fixture/workflow change.

| Role | Run | Runtime job | Mailbox publisher | Runtime UTC | Harness exit |
|---|---:|---:|---:|---|---:|
| Gate | [44281340197](https://github.com/akashskypatel/Directional/actions/runs/44281340197) | 134722865400 | 134728372308 | 10:01:50–10:11:21 | 90 |
| Census | [44281390798](https://github.com/akashskypatel/Directional/actions/runs/44281390798) | 134728938476 | 134731485631 | 10:12:31–10:16:29 | 0 |

| Artifact | ID | ZIP SHA-256 |
|---|---:|---|
| Gate result | 14418131624 | `47465f4365cd9ce39769cecdef386f8402cde9abd97312f6060ecdfa50fcb346` |
| Gate harness log | 14416819980 | `745674d4ebe633b1f2a2c0a9ee8775e3bddca0d777428954b1a664bb23d36e2b` |
| Gate reusable log | 14418316096 | `4c636eaf457c906dc722de288b29ef6900ebf7f30915545d5446e4417a8e7e63` |
| Census result | 14416913949 | `edfdc965df3d8e99568f16ad6a4806800a31a89cb028fee6f0a9f7898e416f19` |
| Census harness log | 14417238305 | `593ef21cd206f52298be4964a883d9f347a42d2c74d7c2b1384871f087678e33` |
| Census reusable log | 14418396491 | `1981f719bef0326b972e4ccd2264c075a207a0220ccc7b4b9283ed688883b407` |

### Full gate — MATCH

955/955 executed: 954 PASS, one permitted RED at row 858 (`apicensus:19`, `SurfaceCellTracingDisplayTests.cpp:155`). The exit 90 and `control_bad=1` are equal to TB136, not a new infrastructure failure. Both postflight states valid; zero missing, skipped, duplicate or abnormal processes, unexpected passes, later-positive RED or bad RED sites. Gate internal checksums 1918/1918, complete raw-log bindings, full membership 1036 (955 gated, 81 deferred), exact TB136 membership plus the single frozen new identity. 954/954 existing ledger fields and logs MATCH under N1–N4 plus N5; 1738 complete region diagnostic records and 66 receipt lines (19 rows) preserved. New row 955 `FieldAlignedCarrierOccupancy.DepartureAlongCarrierMeansTheSlideStartsAtTheEntryPoint` PASS. Accepted CP2 prefix 491/491. No gate departure-chord crossing lines or edge-port departure lines. No new failure.

### Census — MATCH

3/3 executed, one PASS and two established report-only RED, exit 0, valid postflight, 9/9 internal checksums, all ledger/raw-log bindings. All three existing rows match; both BunnyRandom receipts byte-identical including slide/path tokens.

| Row / identity | Fixture | Verdict | Departure-chord crossings | Edge-port departures | Distinct crossing lines |
|---|---|---|---:|---:|---|
| 1 / offgate:362 | Cylinder | PASS, 288 quads | 0 | 0 | empty |
| 2 / offgate:360 | BunnyRandom | RED, contact-cut conflict trace 82, nodes 220/222; no output | 0 | 48 | empty |
| 3 / offgate:365 | Vase | RED, NotProductionReady/completion, AggregateCompletionValidationFailure; no output | 0 | 0 | empty |

### RA-258 S4 measurement and verdict

[Per-row measurement table](evidence/Architecture_M6_CP3_TB137_P13_Departure_Chord_Crossing_Receipt_Counts_20261118.tsv), SHA-256 `404e2ccca0ae829f2545e4092343e3d7cda6fdb2204c5b908ebaef1785b4748c`, 958 data rows, one per executed gate/census identity. The set of distinct `FieldAlignedCurveNetwork.departureChordCrossing ` lines is empty in every row and over the whole scope. All 48 `FieldAlignedCurveNetwork.edgePortDeparture ` lines occur in BunnyRandom census row 2. These counts measure only observed receipt records; they do not prove that the unmeasured paths cannot produce crossings. Baseline 1925/1925 and candidate 1927/1927 internal checksums; 957/957 existing rows MATCH, row 955 PASS, 68/68 other receipt lines byte-identical (66 gate, 2 census). Complete membership and unchanged boundary semantics. No mismatch. The N5 comparison removed no crossing lines. The frozen execution meets S4, not the independent Review or future CB161 acceptance criteria.

### Regression disposition

No new stable event or non-stable product regression. H3 is the statically demonstrated recomputed untraced chord (RA-257 S1, RA-258 S2); zero measured receipt lines establish no observed ProperCrossing dependency in this scope, not a correction. C5/O47 remains the transverse sphere edge endpoint; O48 remains the omitted shared-carrier slide overlap and unsupported cut at X43. BunnyRandom 43/15 slide starts and arrival evidence unchanged; row 858 permitted premise RED and row 648 unreached sphere assertions unchanged; Vase remains completion RED. C5/O42/O43/O46/O47/O48, H2, FC-1/FC-4 and middle-piece direction witness remain open. O45 narrow consumer-proxy closure retained; FC-6, terminal-cut and row858 held. Stable 66/17/49, debt 1, deferred 81; CP2 491/491, CP3 selector497 frozen. D11=A, D12=A, D10 deferred, D6 pending, `chainRimSchedules=false`. No CP3/D0 promotion.

### Procedure and preservation

First attempt read source before explicit snapshot selection; full mandatory policy/skill review and tool ledger were not confirmed, turn-based skill fetch returned 404, timer initialization was late. Resume used the prior verified snapshot and compared it to the current HEAD `5bdfb99d5480b48f1a5e0befb7d3d600b8555775`: five commits, only STATUS, request slot and the execution checkpoint changed; checkpoint preimage verified against blob `532d49cb8b0adc23a03b353d5005a8207f9365a2`. The continuation reused immutable package/baseline bytes; verified terminal artifacts and derived counts locally with no project execution. The prior continuation archive and its initial procedural deviations remain in git history (checkpoint `e77f29c71966fc842d0e3072c7c6f79b38ac97e6`) and the Library backup. Superseded TB136 evidence and CB160 authority remain until the independent Review verifies and folds them; no destructive cleanup. The offline comparison is execution evidence only, not independent Review. Local document audit verifies the touched durable section structure; no policy, selector, manifest, source, test, fixture or workflow definition edits.

## Recommendation

Exact separate next `M6-CP3-TB137-P13-DEPARTURE-CHORD-CROSSING-RECEIPT-FULL-GATE-REV`. Re-open immutable primary evidence and independently adjudicate RA-258 S4. Zero receipt lines select the S5 zero-line branch for Review: freeze CB161 only after the accepted-test grep and fail-before/pass-after witness definition; TB138 equality gate. No classifier switch or future test authored here. Keep the parallel overlap definition and sphere edge-endpoint obligations separate. Do not start successor work in this turn.
