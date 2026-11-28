# TB151 — source-piece counts, immutable Test + Benchmark (2026-11-20 UTC)

## Situation

**Full gate PASS: 966/966; accepted CP2 prefix 491/491.** The first 964 cases are **964/964 MATCH TB150** under the frozen N1–N3 rules. The separate representative three-case census is **3/3 MATCH TB150** under N1–N4: Cylinder PASS; BunnyRandom/Vase expected RED. This is a successful scoped test of CB168M/CB168N, not M6-CP3, selector497, D0, H4, row686, or direct representative acceptance.

## Background — immutable authority

| Item | Independently verified evidence |
|---|---|
| Semantic source | `2d587a2e7ec00b7dc8d0a24df9f6902f03fec931` (CB168N); no source/fixture/test modification in TB151 |
| Immutable compile-only package | GitHub artifact `14618335833`, ZIP SHA-256 `fca8a9fcc4166e708e82933d84d4aacc02b73ef5306f3ac40154baa2d4a97bde`, 28/28 package hashes verified in previous turn; GMP/GMPXX compile evidence, runtimeExecution=false |
| Gate manifest | `.agents/Directional/gates/Architecture_M6_TB151_P13_Source_Piece_Counts_Full_Gate_Case_Manifest.tsv`, SHA-256 `2a902d364612071db04ffa5a116cd988c0babccae58308152cb368df0ff612da`, 966 required + 81 deferred |
| Census manifest | `.agents/Directional/gates/Architecture_M6_TB63_P13_Census_Case_Manifest.tsv`, SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`, 3 cases |
| Harness | `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` |
| Source snapshot | [run 44715627610](https://github.com/akashskypatel/Directional/actions/runs/44715627610), exact inspection snapshot `c5c0b6d1411d9c357d724487aa92355f00435ed6`, artifact `14618359200`, 5,640/5,640 verified indexes |
| Full-gate dispatch | Request `m6-cp3-tb151-gate-20261120-v1`, event `030347448cd633c70ff8af0adcfcc40e76de27d2`; [run 44716246061](https://github.com/akashskypatel/Directional/actions/runs/44716246061), result `14619414153`, ZIP SHA-256 `c28d6ecc128bf9994d3c5f5ba2e2c799c192176f11d8818ca08c70d65caf1dab` |
| Census dispatch | Request `m6-cp3-tb151-census-20261120-v1`, event `e0deb9643024f0b3bf53d7421f8362c7e5d80762`; [run 44719007530](https://github.com/akashskypatel/Directional/actions/runs/44719007530), result `14621727104`, ZIP SHA-256 `4eacb6f3d9d272a2ee380527fc8f7abab516508a596d3dea3f955e8086a4c611` |
| Previous gate baseline | TB150 artifact `14609657696`, ZIP SHA-256 `9e2117dc4bf4d5e097beeaa90236b1c44ceafdba90bc3fd4751ef2cd2472874f` |
| Previous census baseline | TB150 artifact `14610319026`, ZIP SHA-256 `b5033d6939a14ce8716455f5dd5f6f20d15087b2ae229c8c646c96052c68225c` |

## Assessment — full gate

- The schema validation, request parsing, immutable runtime and mailbox jobs completed successfully. Outer result ZIP SHA-256 matches GitHub's artifact digest; all **1,940/1,940** internal SHA-256 checks passed. `planned=executed=passed=966`; `red=abnormal=missing=skipped=duplicate=control_bad=unexpected_pass=0`; `membership=1047`, `postflight=true`, `exit=0`.
- New row 965 (`FieldAlignedCarrierOccupancy.SourcePieceCountsBindEachTraceSegmentToItsRealPieces`) and row 966 (`GlobalTopologyPlan.IndependentValidationBindsTraceSegmentsToSourcePieceCounts`) both PASS in their raw, independent test logs. The frozen CP2 accepted 491/491 prefix remains green.
- The complete preceding **964/964** ledger rows and raw output match TB150. N1 normalizes only Google Test timing fields; N2 normalizes line endings; N3 compares full `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` records as multisets and leaves all other records in order. The exact **1,738** M3 region-support records agree, and all **504** `slideContactArrival` lines remain unchanged and unmasked.
- `compile=false`, `configure=false`, `relink=false`, `benchmark=false`. The reusable did not rebuild, repair or repackage the executable.

## Assessment — separate census

- Immutable result ZIP digest and **9/9** internal SHA-256 checks passed. `planned=executed=3`, `passed=1`, `red=2`; `abnormal=missing=skipped=duplicate=control_bad=unexpected_pass=0`; `postflight=true`, `exit=0`. No configure, compile, relink or benchmark.
- All **3/3** records match TB150 under the frozen N1–N4 comparison. Cylinder remains PASS; BunnyRandom and Vase remain expected RED at `SurfaceCellDesignAcceptanceTests.cpp:493`. N4 removes only the four process-varying `GetParam()` 16-byte address contents (two per RED test). All other text, verdicts, typed failure fields and platform digests match.

## Regression classification and disposition

No new stable regression event or candidate is justified: the test and census results preserve existing classifications and no previously accepted test became RED. Production BunnyRandom/Vase remain expected RED; the O47/C5 sphere slide-ownership defect and O49/H4 piece-path cutover remain open. The production arc graph still represents slides as face chords, with all-ones piece counts until the coordinated cutover. This test does **not** prove that row686's χ6 versus source χ2 (+4), rows669/698 exhaustion, or other direct-output limitations have been fixed.

Stable accounting remains **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, and **81 deferred** cases. Accepted CP2 remains **491/491**. CP3, selector497, D0, row858 and H4 are not promoted.

**Recommendation:** Start only `M6-CP3-TB151-P13-SOURCE-PIECE-COUNTS-FULL-GATE-REV` in the next turn. The independent Review must reopen both immutable archives and independently verify the frozen comparisons, non-vacuity and cutover split. It may reject conclusions not supported by exact evidence. No successor code or Review work was performed during TB151 execution.

**Tool procedure note:** A previous response initially inspected several source files before selecting snapshot read mode. It recorded this miss. The subsequent full source inspection used the exact verified snapshot; the TB151 runtime did not depend on that procedural mistake. The temporary source-snapshot trigger marker is retired in the same authorized documentation patch.
