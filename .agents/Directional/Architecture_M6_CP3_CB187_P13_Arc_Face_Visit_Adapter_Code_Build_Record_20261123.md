# CB-187 — exact arc-face-visit adapter (Code + Build)

## Situation

The frozen 348-line patch adds a pure arc-face-visit adapter and four gated tests. The adapter remains unwired. No test, benchmark, discovery, or compiled binary was executed in this turn.

## Background

- Authority: [TB-REV-167 adversarial record](Architecture_M6_CP3_TB_REV_167_Adversarial_Review_20261123.md), P1–P8. The prose CB-187 reader plan and v1–v5 candidates remain withdrawn.
- Exact frozen source diff: `Architecture_M6_CP3_CB187_P13_Arc_Face_Visit_Adapter_Exact.diff`, SHA-256 `806a64feba6d58d6333c4bd14b7ab465eb85b5ec4a6091afaac3cca2e48996ac` (+348/−0), only `src/geometry/ArcFaceVisits.h` and `tests/FieldAlignedCurveNetworkTests.cpp`.
- Exact code source commit: `486704038a6bf659a253a2e2f99edde5d03c7ffe`. [Apply workflow 45090512356](https://github.com/akashskypatel/Directional/actions/runs/45090512356) reported success, exact two-path commit, and `runtimeExecution=false`. The connector independently verified both expected Git blob hashes.
- Full work-preservation patch SHA-256: `802c32ed04298a5e3108736e9bc1cec68e9e801bb7410859d1f48fcb9045580b`; diff body SHA-256: `806a64feba6d58d6333c4bd14b7ab465eb85b5ec4a6091afaac3cca2e48996ac`. Google Drive File ID `1fKin3ibuGuI-Fe3Qsz3iMPvveOUnhdRS` was retired by the owner-side connector after successful apply. An exact Library backup remains available.
- [Compile workflow 45090657623](https://github.com/akashskypatel/Directional/actions/runs/45090657623) created immutable package `14781561211` (ZIP SHA-256 `fa9781a710f29c926c9fd60a39cf6868d15b8d3e50ea5b7989b17aebd59b67a6`) from source `486704038a6bf659a253a2e2f99edde5d03c7ffe` using the eight required targets. GMP/GMPXX evidence: GMP on, gmpxx and gmp both present on the compiled link command, exactArithmeticBackend=GMP. `runtimeExecution=false`.

## Assessment

The compiler accepted the isolated adapter and its four registered tests. This turn did not run them. The `build_regions` and `build_fragment_corner_incidence` readers and all selectors/manifests were unchanged. The staged sphere still has the known unpromoted `SourceFaceCarriesMultipleTraceCuts` failure; the production sphere still has `CutSearchExhaustedBeforeCellularity`. Last runtime gate remains TB167 989/989, CP2 491/491, membership 1070. Stable 66/17/49, debt1, deferred81; CP3/497/D0/H4 held.

## Recommendation

Start only `M6-CP3-TB-EXEC-168-P13-ARC-FACE-VISIT-ADAPTER-FULL-GATE` in a separate turn. Execute package `14781561211` without rebuilding or source edits using manifest `gates/Architecture_M6_TB168_P13_Arc_Face_Visit_Adapter_Full_Gate_Case_Manifest.tsv` (SHA-256 `82581dd14064efe3729923cfd94333ef70113b0bb84e6bb8eabfb2ec61cce436`). Require 993/993 cases PASS, CP2 491/491, membership 1074, rows 1–989 unchanged against TB167 artifact `14770748728` under N1–N3, four new cases PASS, and no census. Follow it with the independent `M6-CP3-TB-REV-168-P13-ARC-FACE-VISIT-ADAPTER-FULL-GATE` review. The Code + Build turn makes no runtime acceptance claim.
