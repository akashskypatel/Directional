# TB138 P13 departure-chord classifier switch — full gate execution (MATCH)

## Situation

`M6-CP3-TB138-P13-DEPARTURE-CHORD-CLASSIFIER-SWITCH-FULL-GATE-EXEC`. Entry 2026-11-18T11:56:30Z, beacon `e4f52e00502ec9b364a90b32c03ba5d9c72f1c41`. Resume 2026-11-18T12:22:00Z, beacon `1eed9e70be1eaa1c50f4cdf8e670bfd765ce3792`. **MATCH: 958/958 prior rows, new row 956 PASS.** This is execution evidence, not independent acceptance. PR #8 remains draft, open and unmerged.

## Background — immutable authority

[CB161 record](Architecture_M6_CP3_CB161_P13_Departure_Chord_Classifier_Switch_Code_Build_Record_20261118.md) and [TB137 Review / RA-259](Architecture_M6_CP3_TB137_P13_Departure_Chord_Crossing_Receipt_Full_Gate_Independent_Review_20261118.md) freeze this gate. Source and executor `f14761715004d7ddc27e032698f6540ae1a9b0c4`, package `14424780973`, ZIP `b55fa59e6c93abd4d40adde92547b309998e03803a3dc95db37feb254346c058`, root manifest `e6f5d899229039e3bc12e3435ee96ef03157db457590c8a3b72696424612dc06`, source archive `e3f65c11d1eb26cdef0710a67ad062561260fdd27baa58bf168958df8996b547`. All 28 checksums and six archived executable modes passed. Source status was clean. CB161 built eight targets with GNU Multiple Precision arithmetic (GMP/GMPXX). No local product execution.

Snapshot `1f2db73f4c45b6dd120990a8f6b832ced0f0826f`, run `44299355256`, job `134784809683`, artifact `14425183230`, ZIP `7803be4907a1a902286ec3e176ed0ae35a321b7cefd046de58b4a8dac3f73f7b`, archive `7758410b2f5314b2b59a752b81f62e26e892c0f1de5125d40bfffd22891cfe85`. All 5,565 source checksums passed. The 572 relevant source, test, fixture, selector, harness and workflow file bytes match the packaged source. Resume rechecked the snapshot, continuation archive and gate evidence hashes. The remote comparison from snapshot to resume HEAD shows only STATUS, dispatcher slot, checkpoint and removal of the snapshot marker. The documentation preimages are unchanged.

| Frozen input | SHA-256 |
|---|---|
| [Gate](gates/Architecture_M6_TB138_P13_Departure_Chord_Classifier_Switch_Full_Gate_Case_Manifest.tsv) (956 rows) | `95e61be9132e159a5c3f041a20b875aed4d55ea5cf7bade0c93e07b329a6641a` |
| [Census](gates/Architecture_M6_TB63_P13_Census_Case_Manifest.tsv) (3 rows) | `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` |
| [Deferred ledger](gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv) (81 rows) | `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` |
| [Harness](tools/m6_cp3_targeted_artifact_harness.sh) | `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` |

## Assessment — exact execution

| Role | Event SHA | Mailbox key | Request SHA-256 |
|---|---|---|---|
| Gate | `4ad2ef87d2bc153e102c31c69df7046e572feab8` | `m6-cp3-tb138-gate-v1` | `4a6a98901e0f1d62dcabc5e7d5525d10842431560d8a9603df2e6bb4e7af2071` |
| Census | `79db639b60d3a6cc195b0f37089f6a5e50fb8516` | `m6-cp3-tb138-census-v1` | `64eb6dab80ea00d11c989dd71ca2437eaa4b3e096258480371338aa35a97cdfc` |

| Role | Run (attempt 1) | Runtime job | Mailbox job | Runtime UTC | Harness exit |
|---|---:|---:|---:|---|---:|
| Gate | [44299742312](https://github.com/akashskypatel/Directional/actions/runs/44299742312) | 134786361274 | 134791011686 | 12:00:40–12:08:59 | 90 |
| Census | [44299795875](https://github.com/akashskypatel/Directional/actions/runs/44299795875) | 134791650206 | 134793881083 | 12:10:24–12:14:21 | 0 |

Both mailbox records bind the event and source. Both schema validators and request parse passed. Compile, Drive apply and noop were skipped. Both workloads finished without duplicate dispatch, rebuild, relink, configure, binary repair, discovery or product/test/fixture/workflow changes. The gate job failed because the preserved permitted RED causes harness exit 90. This is not an orchestration failure. Census job succeeded.

| Artifact | ID | ZIP SHA-256 |
|---|---:|---|
| Gate result | 14425931505 | `884cadd19104322d764c87690e53827391806ca3d56765433f7bdb7e5cf8859e` |
| Gate harness log | 14426790075 | `84e4c31b24aeec88789145d0e59b1e3b502617060f022f8aa00663a5efab3ff1` |
| Gate reusable log | 14425427360 | `05e977954c8615d1a0ee313f67d8ab2de9879a10c38a19c26b96ed153469161c` |
| Census result | 14425229608 | `c7b9001a718b827ad8d910e511a1e44f3618df13de44e3623097edba716e619b` |
| Census harness log | 14427055668 | `b33edf774922f89cced822975fd46ef1146aab9ebfd65df316fdf8e95f46581b` |
| Census reusable log | 14427115482 | `7f13077c2aac78016fc76c2a0441bb5e4c2abd424e6074de65ed431cc7921977` |

All six outer hashes match the mailbox inventories. Baseline TB137 gate `14418131624` (ZIP `47465f4365cd9ce39769cecdef386f8402cde9abd97312f6060ecdfa50fcb346`), census `14416913949` (ZIP `edfdc965df3d8e99568f16ad6a4806800a31a89cb028fee6f0a9f7898e416f19`) match their retained hashes. Baseline 1,927/1,927 and candidate 1,929/1,929 internal checksums passed. The comparator checks complete manifest coverage, row identities, ledger fields and exact raw-log hash bindings. It compares logs under N1 GoogleTest times, N2 CRLF, N3 complete region-record framing/order, N4 census opaque parameter bytes. It retains all crossing/departure/other receipt bytes. No N5 removal. Fourteen offline controls passed. They check the comparator, not product behavior.

### Gate — MATCH

956/956 executed. **955 PASS, one permitted RED** at row 858 `apicensus:19`, `SurfaceCellTracingDisplayTests.cpp:155`. Row 648 remains unreached at its sphere assertions. No missing, skipped, duplicate, abnormal, unexpected pass, later-positive RED or incorrect RED site. Postflight valid. Membership 1,037: 956 gated, 81 deferred, exactly prior membership plus the frozen identity. Gate logs and ledger fields match all 955 old rows under N1–N4. All 1,738 complete region records and 66 other receipts are identical. Zero departure or crossing lines. New row 956 `FieldAlignedCarrierOccupancy.DepartureSlideHasNoInteriorChordContact` PASS. Accepted CP2 prefix 491/491. The sole RED and `control_bad=1` are unchanged.

### Census — MATCH

3/3 executed. One PASS, two report-only RED, exit 0, postflight valid. All three prior rows match; both BunnyRandom receipts remain byte-identical, including slide/path tokens.

| Row / identity | Fixture | Result | Crossing lines | Departure lines |
|---|---|---|---:|---:|
| 1 / offgate:362 | Cylinder | PASS, 288 quads | 0 | 0 |
| 2 / offgate:360 | BunnyRandom | RED, trace 82 contact-cut conflict (nodes 220/222), no output | 0 | 48 |
| 3 / offgate:365 | Vase | RED, completion / AggregateCompletionValidationFailure, no output | 0 | 0 |

[Per-row counts](evidence/Architecture_M6_CP3_TB138_P13_Departure_Chord_Classifier_Switch_Counts_20261118.tsv) SHA-256 `4aa9876fb42339b8f70ef25271319a15fe581995d0285fc6b0867359f43acd9a`, 959 data rows. All 958 prior rows MATCH. All 68 other receipts are byte-identical. All 48 departure lines occur in BunnyRandom, as before. Zero distinct crossing lines. The zero-line condition follows from RA-259 S2.1 and is not an independent proof of correction. The decisive evidence is row 956 plus equality. H3 closure requires the separate Review.

### Regression disposition

No new product regression or candidate. The H3 fix passes the execution gate, but independent verification remains open. C5/O47 (sphere transverse edge endpoint) and O48 (missing shared-carrier overlap and unsupported X43 cut) remain open. The BunnyRandom path, onset ratio and contact conflict are unchanged. Vase remains completion RED. The row 858 premise and row 648 assertion reach remain unchanged. C5/O42/O43/O46/O47/O48, H2, FC-1/FC-4 and middle-piece direction witness remain open. O45 narrow consumer-proxy closure remains. FC-6, terminal-cut and row858 are held. Stable 66 events / 17 categories / 49 recurrences, debt 1, deferred 81. CP2 491/491, CP3 selector497 frozen. D11=A, D12=A, D10 deferred, D6 pending, `chainRimSchedules=false`. No CP3/D0 promotion.

### Procedure and preservation

First attempt checkpoint history: commits `7c55b590562a1feb098645f273efb607cc6d209f` and `963b562248123f8648d27465acb6309d55398757`. Cleanup run `44300641872`, job `134789279948`, commit `811afdab3b3d0a10b3bb2212a3d77c04fec8c826`, result `14425741796` and log `14426150648` verified. Snapshot trigger and cleanup manifest removed. Ten durable workflows preserved, zero PR comments deleted. Initial gate verification and pending census were saved in Library archives `Directional_TB138_resume_20261118.zip` and `Directional_TB138_gate_verified_20261118.zip`. This resume reused the verified snapshot and gate rather than re-executing. Initial direct policy/source reads preceded snapshot selection; first-attempt timer started late in shell. Full mandatory policy/skill read and complete cross-attempt tool accounting are not confirmed. Resume started the Python closeout reminder and preserved the original turn start time. Local Git baseline contains exact preimages, not historical repository objects. Remote comparison supplies unchanged-path authority. No product acceptance inferred from procedural checks. Offline execution evidence and raw logs are preserved in the Library closeout archive.

## Recommendation

Exact next `M6-CP3-TB138-P13-DEPARTURE-CHORD-CLASSIFIER-SWITCH-FULL-GATE-REV` (independent Review). Re-open the primary artifacts and independently check row 956 and all 958 prior rows under N1–N4. Review owns H3 closure and CB162 authorization. Do not start CB162, CB163, slide wiring, or any held definition in this execution turn.
