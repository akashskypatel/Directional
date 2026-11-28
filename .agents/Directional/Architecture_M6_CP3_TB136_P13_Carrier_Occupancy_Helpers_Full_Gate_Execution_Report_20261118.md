# TB136 P13 carrier occupancy helpers — full gate execution (MATCH)

## Situation

Current canonical turn: `M6-CP3-TB136-P13-CARRIER-OCCUPANCY-HELPERS-FULL-GATE-EXEC`. First entry 2026-11-18T07:05:54Z; repository STATUS originally showed CB159 COMPLETE with TB136 as successor. Entry beacon commit `2173cfa350ba6b531d35ed4a0ca8f84dab1f764a`. **MATCH under RA-257 S4:** 956/956 existing rows match TB135 and row 954 passes. No independent Review or production acceptance is claimed.

## Background — frozen authority

- [RA-257 S4](Architecture_M6_CP3_TB135_P13_Edge_Transit_Entry_Full_Gate_Independent_Review_20261118.md#ra-257--adversarial-re-review-of-this-review-2026-11-18-utc), [CB159 record](Architecture_M6_CP3_CB159_P13_Carrier_Occupancy_Helpers_Code_Build_Record_20261118.md).
- Package 14405225071, compile run 44251239457, exact source and executor `18cc4a7d3e8ae43ce854c0edc834ab156156dcbf`. Verified ZIP SHA-256 `2e142b042d02b81e6626c40b03f2116628d017adf510a9c2ea7f96f9a8994e8c`, root manifest `6ba41479543ba299e4afa02c3cd6c211d7c713d32b71c5d66c10d93e909ad97d`, source archive `d97314c08f1b4a49ab47c6962d041cb0be37d1d25ed427dbfbbd031a5bfeb183`. All 371 packaged implementation/test files equal snapshot, four frozen inputs match, six executable modes checked. No local candidate binaries executed.
- Snapshot run 44256358394, job 134639021136, artifact 14406282185, source/event `733fb5400a7e4938b73faff75a882b444988ddd5`, ZIP SHA-256 `52fc32bd101504c366d1da3bac10dca7d183e850a7cf946a19fe9ede8c4c5eb9`; 5551 file checksum checks passed. Temporary snapshot marker: `.agents/connector-triggers/source-snapshot/m6-cp3-tb136.txt`.

## Assessment — requests already committed

| Role | Exact event commit | Mailbox key | Expected rows |
|---|---|---|---:|
| Gate | `086df51d38d7eeb1132d51642e52b1d76cb787d0` | `m6-cp3-tb136-gate-v1` | 954 |
| Census | `8e3b3993de65bcf0785f5d47a142741d8271c8ff` | `m6-cp3-tb136-census-v1` | 3 |

Both exact event request contents agree with frozen values. The serialized dispatcher ran the census after the gate. Both terminal mailbox records match the event and source identities. No duplicate dispatch.

TB135 comparator artifacts 14398029488 (gate) and 14398329619 (census) verified against their recorded ZIP digests. Independent offline check of all 956 baseline row/log bindings and 1923 internal checksums passed. Local offline comparison helper passed 14 controls, including rejection of mutated receipt slide/path tokens and changed ledger identity. These checks are not TB136 runtime evidence or the independent Review. No source, test, fixture, harness, workflow YAML or package changes and no local rebuild. No new regression in either execution. Stable accounting stays 66/17/49, with one witness debt and 81 deferred.

## Verified gate result — MATCH

Run [44256775123](https://github.com/akashskypatel/Directional/actions/runs/44256775123), runtime job 134640375885, mailbox publisher 134644020823. Event and semantic SHA match the request. Artifact 14406791564 ZIP SHA-256 `1a1cccc01f86d1e1555ef896cb449dc42da8c0c30f8c41e6b2685c1e0b7045c8`, harness log 14406324158 ZIP `5a383edafca5e0cb326da6226a7f34bbf2fbe25e5382058dc19513b8788cd849`, reusable log 14407011203 ZIP `12c81c48a3533afc3e4dba9de4aa32fad5a1730f59f2b3132a2ee3daa74839b2`. All three ZIP digests verified. Both validators and parse succeeded; compile skipped; runtime from 07:10:38Z to 07:19:00Z. Harness preflight 954 cases/81 deferred, source and package exact. Postflight true, 1916/1916 internal checks, 954/954 executed with 953 PASS/1 permitted RED, no missing/skipped/duplicate/abnormal. Exit 90 and control_bad=1 equal TB135; red_site_bad=0, later_positive_red=0, unexpected_pass=0. Gate rows 1–953 equal TB135 under N1–N4; 1738 region diagnostic records and 66 byte-identical receipt records across 19 rows; row 954 `FieldAlignedCarrierOccupancy.FirstSharedParameterFollowsTheMovingTraceAlongOneCarrier` PASS. Membership equals TB135 plus precisely the new test, 1035/81 deferred. Zero comparator mismatches. No new regression; no CP3 acceptance. The gate MATCH meets the gate part of RA-257 S4.

## Verified census result — MATCH

Run [44256959318](https://github.com/akashskypatel/Directional/actions/runs/44256959318), runtime job `134644387322`, publisher `134646520239`. Both validators and parse passed. Compile, Drive apply and noop were skipped. Runtime 07:20:06Z–07:24:58Z; exit 0. The mailbox published at 07:25:23Z. Preflight: three cases, source and package exact. Postflight true; 9/9 internal checksums; all three logs bind to the ledger. Zero missing, skipped, duplicate or abnormal cases. Result, harness log and reusable log ZIP digests match the mailbox and run inventory.

| Artifact | ID | ZIP SHA-256 |
|---|---:|---|
| census result | 14406826878 | `f855a98e9c5a85d3afa21659f35f3ff8c6339b56a8965057f7b54164efd64ce3` |
| census harness log | 14406816846 | `29ce913826f09ef1db736938de86505a523fc1cb8d1ca77c1c29b7bc22d0b62f` |
| census reusable log | 14407435848 | `210950a8e7fb14b2ddf69860afdea6ad7d1b874e277e4675404710296b58a6f3` |

| Census row | Fixture | Outcome |
|---|---|---|
| 1 / offgate:362 | Cylinder | PASS, 288 quads, accepted=1, strict=0 |
| 2 / offgate:360 | BunnyRandom | RED, contact-cut conflict on trace 82, nodes 220/222; no output |
| 3 / offgate:365 | Vase | RED, `NotProductionReady/completion`, `AggregateCompletionValidationFailure`; no output |

All three ledger rows and retained logs match TB135 under N1–N4. Both BunnyRandom receipts match byte for byte, including slide and path fields. The slide starts on (94,210) remain t43=0.26324148596788688 and t15=0.93470265131543506. No behavioural correction is claimed.

## Full verdict and regression disposition

- 956/956 existing rows match (953 gate + 3 census), and new row 954 PASS. Candidate executed 957 rows across both runs; 954 PASS and three known RED. Independent raw-log hash bindings: 956 baseline and 957 candidate. Internal checksum entries: 1923 baseline and 1925 candidate. The 1,738 gate region-support records, 66 gate receipt records and two census receipt records match. Membership is precisely the previous inventory plus the new test: 1035 (954 gated, 81 deferred). No unexpected process or semantic delta.
- CP2 491/491 remains accepted. The helper test establishes the unwired unit contract only. C5/O47 (sphere edge endpoint), O48 (BunnyRandom slide overlap), H3 (recomputed chord instead of traced zero-length face piece), Vase completion, row 858 permitted RED at :155, and row 648 unreached sphere assertions remain unchanged. No new stable regression event. C5/O42/O43/O46/O47/O48, H2, FC-1/FC-4 and middle-piece direction witness remain open. O45 narrow consumer-proxy closure remains. FC-6, terminal-cut and row858 remain held. Stable 66/17/49, debt 1, deferred 81. D11=A, D12=A, D10 deferred, D6 pending, `chainRimSchedules=false`. No CP3/selector497/D0 promotion.
- Procedure deviations in the first attempt: repository reads preceded explicit snapshot-mode selection; full mandatory policy reads and tool accounting were not confirmed; timer used a shell. The continuation reused the verified snapshot and confirmed unchanged document preimages by exact remote comparison. Local Python timer started on resumption. No implementation, test, fixture, harness, workflow YAML, or package mutation. No local build or candidate runtime. The local offline comparator is execution evidence, not the separate independent Review.

## Recommendation

Exact separate next `M6-CP3-TB136-P13-CARRIER-OCCUPANCY-HELPERS-FULL-GATE-REV`. Re-open both immutable result archives and independently verify RA-257 S4. Keep the parallel sphere DEFN (S5.1/S5.3/S5.4) and the later overlap DEFN (S5.2). Keep helper and wiring CB/TB pairs separate. Do not start successor work in this execution turn.
