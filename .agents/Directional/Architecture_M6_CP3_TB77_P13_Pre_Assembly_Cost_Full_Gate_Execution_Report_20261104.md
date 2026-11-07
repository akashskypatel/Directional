# TB77 — CB86 immutable full gate and production census (2026-11-04)

**Turn:** `M6-CP3-TB77-P13-PRE-ASSEMBLY-COST-FULL-GATE-EXEC` — artifact-only Test + Benchmark. **Execution complete; registered outcomes MATCH; no CP3 promotion.** No rebuild, reconfiguration, relink, source/test/fixture repair, or CB87 implementation in this turn. The next separate authorized turn is `M6-CP3-CB87-P13-BOW-TIE-VERTEX-EDGES`.

## Frozen authority and independent checks

- Immutable CB86 compiled source `0f4c78c433211b0ece549e35cfb0bc975ca02258`; Linux GMP/GMPXX compile [41879102285](https://github.com/akashskypatel/Directional/actions/runs/41879102285), package `13347299644`, ZIP SHA-256 `cf8c1a9b9786c369c664eed22ba583c798ff6384fc048f62fd410f206d0a40aa`, 28/28 packaged hashes; build-time `runtimeExecution=false`.
- TB77 gate manifest SHA-256 `48ef4743b18683e78d9f740c4eb0e7f249abcab78a4aeac849620e251d9fface`, 896 identities; deferred-ledger v5 SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, 81 deferred; census three-case manifest `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`. Harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Exact executor snapshot SHA `2230cc56fc055d56e07cc5635c528bbf40fc1c03`, [run 41885432228](https://github.com/akashskypatel/Directional/actions/runs/41885432228), artifact `13349999565`; source file SHA256SUMS 6162/6162 verified; source tar SHA256 `6d3247df4b8b17210683190d47ac7794c86e981a69d895b11f2899995b012a41`.
- Gate [run 41886202087](https://github.com/akashskypatel/Directional/actions/runs/41886202087), result artifact `13351163736`, ZIP SHA-256 `9416a3b1c19c4084c329d18e6fa5879574b6cecf8a2075c06faa6b51f9e6c773`: **896/896 PASS**, 896 raw logs, 896 resource files, 1,800/1,800 internal SHA256SUMS. Exact ledger/manifest test and binary identities agree for all 896 rows. Membership **977** = 896 gated + 81 deferred; new GUARD rows 894–896 PASS. Execution boundary exit 0, postflight true; configure/compile/relink/benchmark false. No red, abnormal, missing, skipped, duplicate, control, unexpected positive or site failures.
- Census [run 41886240724](https://github.com/akashskypatel/Directional/actions/runs/41886240724), artifact `13351834589`, ZIP SHA-256 `e5a1dc8ac8379bac2b05dbb733c1ea2694461cc5c0ef62a165b50d72c71b527b`: 9/9 internal hashes verified, every case log hash matched; source/package authority and runtime boundary matched the immutable contract. Execution boundary: planned/executed 3/3, one PASS, one RED, one ABNORMAL, no missing/skipped/duplicate/control failures, postflight true, exit 0; configure/compile/relink/benchmark false.

## Production census and registration

| Fixture | Evidence | Registered disposition |
|---|---|---|
| Cylinder | PASS exit 0, wall 8.56 s, completed direct Cylinder test | PASS — MATCH |
| BunnyRandom | RED exit 1, wall 0.80 s; InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49; incidences=4 expectedClasses=5; no produced quads | Existing P13-e sourceVertex 49 RED — MATCH |
| Vase | ABNORMAL exit 124, HARNESS_TIMEOUT 600s, no completed terminal or completedQuads count, empty resource-time record | RED `NotProductionReady:completion detail=SelfIntersectingFace` and 67,829 quads **or** ABNORMAL `HARNESS_TIMEOUT 600s`, both registered — MATCH |

The Vase ABNORMAL is a **registered TB77 outcome**, not a successful direct Vase run. Its log stops after region-support projection diagnostics without a completed post-assembly terminal, so it does not prove the completed-mesh orientation behavior or 67,829 quad count. The absence of a completed terminal prevents timing a terminal Linux Vase run. No inference is made that an unobserved correction failed.

## Regression and promotion disposition

TB77 does not promote selector497 or CP3. Accepted CP2 remains **491/491**; stable **66 events / 17 categories / 49 recurrences** and produced-witness debt **1** are unchanged. P13-m remains an unpromoted cost candidate (the timing and terminal observations are evidence for the next turn, not a stable new event). P13-l completed-mesh orientation and BunnyRandom P13-e port-class count are separate Review obligations. O27, O28 and O29 remain open. Next gate TB78 is a separate later turn after CB87/CB88; no TB78 claim is made here.

**Stop boundary:** `M6-CP3-CB87-P13-BOW-TIE-VERTEX-EDGES` is authorized by the registered outcome routing. No successor work occurred in this TB77 turn.
