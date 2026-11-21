# CB-173 — exact edge-locus along-edge ray key (Code + Build only)

## Situation

The three-file exact frozen diff was applied to semantic source `47a874ee8baa86284eeee11b4a28f9cca06d73f9`, and all eight GNU Multiple Precision (GMP/GMPXX) compilation targets were packaged. No Directional tests or benchmarks ran in this turn. This record does not assert runtime acceptance.

## Background

- Canonical turn: `M6-CP3-CB-173-P13-STOP-SWITCH-RAY-HELPERS`.
- Authority: [TB-REV-156 adversarial review](Architecture_M6_CP3_TB_REV_156_Adversarial_Review_20261121.md) and [frozen exact diff](Architecture_M6_CP3_CB173_P13_Edge_Locus_Along_Edge_Ray_Key_Exact.diff), SHA-256 `83adf365f6b9924294ce71c238628edd5fa155860f96239b00fcb92df7eb0a59`.
- Snapshot source `d5bb98b934f5d2c925cc0192ed13f0d6ed9322ed`, [snapshot 44932507855](https://github.com/akashskypatel/Directional/actions/runs/44932507855) verified 5,682 file hashes; semantic source `47a874ee8baa86284eeee11b4a28f9cca06d73f9`, [Drive apply 44932790529](https://github.com/akashskypatel/Directional/actions/runs/44932790529) verified exact patch body and source images.
- Work-preservation patch SHA-256 `c009836c24693edb343473fb707e03c100cdfdd7fcf35621620ce47a66b8093d`; temporary Drive file deleted after successful push. No workflow file changed.
- [Compile 44932960771](https://github.com/akashskypatel/Directional/actions/runs/44932960771): artifact `14718074764`, ZIP SHA-256 `cad613506dbadff3179f17a8492a57062d31cf27cfff6d1378417f351ab5ad09`, all eight approved targets, GMP/GMPXX enabled, `runtimeExecution=false`. Exact source and packaged checksums verified.

## Assessment

The exact source/test change only modifies `src/geometry/EmbeddedGraphTopology.h`, `src/geometry/EmbeddedGraphTopology.cpp`, and `tests/FieldAlignedCurveNetworkTests.cpp` (152 insertions, 13 deletions). The edge-locus helper uses slot 0 for a ray toward the second source-edge endpoint and slot 2 toward the first. Along-edge trace rays count in `edgeRayCount`; into-face ray slot is `2*side+1`. Only the compositions (arc, trace) (0,0), (2,0), and (0,2) are valid. Same-direction duplicate rays remain fail-closed. Vertex/face branches, producer switch, cut bindings, and the stop switch are not modified.

Three focused tests were added but not executed: `EdgeLocusAlongEdgeTraceRaysTakeEdgeArcSlots`, `EdgeLocusIntoFaceRaysInterleaveWithEdgeRays`, and `EdgeLocusEdgeRayCompositionAdmitsOnlyThroughPairs`.

The latest independent **runtime** gate remains TB156 972/972, census 3/3 baseline match. CP2 491/491 accepted; stable 66 events / 17 categories / 49 recurrences; one produced-witness debt; 81 deferred. The sphere χ6 versus χ2, four unowned contacts, stop-switch proof, and CP3/497/D0 remain open. No new runtime claim is made.

## Recommendation

After the final COMPLETE beacon, run only `M6-CP3-TB-EXEC-157-P13-EDGE-LOCUS-ALONG-EDGE-RAY-KEY-FULL-GATE` in a separate Test + Benchmark turn against the immutable artifact `14718074764`. Require 975/975 PASS, all 972 earlier rows byte-authoritative matching TB156 with empty allowance, census 3/3 and no forbidden guard reasons. If green, independently review in TB-REV-157 to freeze the stop-switch helper. Do not start the stop switch in this turn.
