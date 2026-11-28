# CB-197A — exact trace-piece builder extraction (2026-11-23 UTC)

## Situation
The compile-only Code + Build turn `M6-CP3-CB-197A-P13-EXACT-TRACE-PIECE-BUILDER-EXTRACTION` is complete. The authorized successor is `M6-CP3-CB-197B-P13-EXACT-SOURCE-RETRACE-ORDERED-STRETCHES`. No successor work was started.

## Background
The TB-REV-175 adversarial review (G2–G4) authorizes only the exact three-file diff `Architecture_M6_CP3_CB197A_P13_Exact_Trace_Piece_Builder_Extraction_Exact.diff`, SHA-256 `bf679210a15d0f1005b540c09972909e9f47c41db11ae0cc977c24d467eb7fc6` (20,023 bytes, +197/−176). The extraction moves four existing functions and the `FaceChartPoint` alias to `ExactTraceSegmentPieces.h`. It does not connect a new caller or change behavior.

## Assessment
- Source snapshot: [run 45249471298](https://github.com/akashskypatel/Directional/actions/runs/45249471298), source `d64f97951aad051297c73427bf8d0159f282ebb5`, 5,824 source files; source archive SHA-256 verified.
- Git preimages matched: `EmbeddedGraphTopology.cpp` `8547f53692443e5201547e5cf28dd2db2cf5bc64`; `EmbeddedGraphTopology.h` `d46f39d0142d925bafade7286f958ddee5720eb8`.
- GitHub Actions patch application: [run 45250220224](https://github.com/akashskypatel/Directional/actions/runs/45250220224), result artifact `14856281808`; source commit `13bf6131fba0c31a289247b11d10f65b69d1fd92`, `runtimeExecution=false`. The verified work-preservation patch SHA-256 was `322b2c23aa878ba4824f3f670e96ac1df68add89deeecf6d6f11ee6dbaca867f`. The staged Drive transport file was deleted after successful application.
- Exact source postimages: `.cpp` SHA-256 `61a0fbac4ada9b7a5efbb83c725122af78479411a2a1af2d2f02c8f9ebdead30`; `.h` SHA-256 `bb2c298f7e2353a6cc9949228db729b5bb84d5ea266413b849a5ba23b311b2a6`; new header SHA-256 `6279c6d6e08a14d2b80dff799231249d2e8a9939c09fa88bf2b52eb314bac9da`. GitHub blob identities also match the local full-index diff.
- GMP/GMPXX compile-only: [run 45250530743](https://github.com/akashskypatel/Directional/actions/runs/45250530743), source pinned to `13bf6131fba0c31a289247b11d10f65b69d1fd92`, eight required targets, including `directional_surface_cell_producer_tests`. Build artifact `14856397006` ZIP SHA-256 `bf43ab6ca48319a05b38a922b4f4f531d9f4ac7c419df5316acbe2d3c5eebee2`; diagnostic log artifact `14855516711` ZIP SHA-256 `dd2c4c13cc912d8eaad5eae7b09433c095a3fb88e5ebf9d4116331abe24be043`. Packaged internal SHA-256 checks: `28/28`. `runtimeExecution=false`; no executable, test or benchmark was run.
- No test, selector, manifest, CMake, producer, validator or other semantic file changed. CP3/497/D0/H4 are not accepted or activated. TB175 remains rejected at 993/1000, with seven known mechanical RED. Accepted TB169 993/993, CP2 491/491 and stable 67/17/50, debt1, deferred81 remain unchanged.

## Recommendation
Start only `M6-CP3-CB-197B-P13-EXACT-SOURCE-RETRACE-ORDERED-STRETCHES` in a new turn. Apply its separate reviewed exact diff SHA-256 `1fe85e273a1c997fc976f4cbc7779f3a7711d19b511cfc6824a5809a2325be8d`; compile only. After that, run TB-EXEC-176 as a separate immutable test/benchmark turn.
