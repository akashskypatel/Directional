# TB108 — annulus rim census full-gate execution (2026-11-12 UTC)

## Situation

**COMPLETE / scoped MATCH.** The immutable CB127 package completed the full gate at **943/943 PASS** with **1,024** membership entries and the 3-case production census at **Cylinder PASS / BunnyRandom registered RED / Vase registered RED**. This is a test-and-benchmark checkpoint, not CP3/selector497 promotion.

## Background

- **Canonical turn:** `M6-CP3-TB108-P13-A3-ANNULUS-RIM-CENSUS-FULL-GATE-EXEC` (64D.2). No source, fixture, selector, harness, package, compilation, relink, configuration, or benchmark change was authorized or made in this turn.
- **Frozen source and candidate:** `39e91beb507468777aa90ffd83e23c146652d3ca`; CB127 [compile run 43133009660](https://github.com/akashskypatel/Directional/actions/runs/43133009660), artifact `13905818229`, exact ZIP SHA-256 `3d9feda87b4a42ae6adc5f31a75164777a4d8ec0e9442b07304ac4a968fac15e`; 28/28 package checksums; GMP/GMPXX linkage; compile-runtime boundary was `runtimeExecution=false`.
- **Full-gate manifest:** `.agents/Directional/gates/Architecture_M6_TB108_P13_A3_Annulus_Rim_Census_Full_Gate_Case_Manifest.tsv`; 943 rows, SHA-256 `938836fc3326df11ccb3d475e0c6a3a4d629d8ac6e252436dcfac47286bfb651`; membership 1,024, ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`.
- **Execution gate:** [run 43138368852](https://github.com/akashskypatel/Directional/actions/runs/43138368852), event `22d160afdc6df32358aca7c7028e983ec305ceb6`, result artifact `13908358480`, ZIP SHA-256 `ac6a9232e0924e2cb973c11c5c96cb679cf0f7c37a404dc7034f7b4b7a1f6bd1`.
- **Production census:** [run 43138410775](https://github.com/akashskypatel/Directional/actions/runs/43138410775), event `13d5af2257fb4c8c75ae1f0dd911f78eb4f9c89f`, result artifact `13908514778`, ZIP SHA-256 `a136ff56e27bf08297cf9b6dc7ba6c1ca1ba7d1b3568b838428a43c3a8d1dece`; census manifest `.agents/Directional/gates/Architecture_M6_TB63_P13_Census_Case_Manifest.tsv`, three cases, SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.
- **TB107 comparison evidence:** full-gate artifact `13902266978`, ZIP SHA-256 `0811ec78744e3450de2fc9f338a07e4c6ec877084272ef19ae7b977a7b5ed796`; census artifact `13902008013`, ZIP SHA-256 `dd7d6b5322489bce80d0257e9d5e489ce9906ea7e3726e69628afc21c6ad8fff`.

## Assessment — independently checked raw artifact evidence

| Gate | Verified result |
| --- | --- |
| Full-gate case ledger | 943 planned / 943 executed / **943 PASS**, zero RED, skipped, missing, duplicates, abnormal, unexpected PASS, control failure, or later-positive RED |
| Membership | 1,024; file byte-identical to TB107 |
| Required case records | 943 substantive records identical to TB107 after excluding per-run `log_sha256` |
| Internal SHA256SUMS | 1,894/1,894 full-gate; 9/9 census; no missing or altered entry |
| Inherited receipts | 19/19 full-gate and 6/6 census byte-identical to TB107; total **25/25** |
| Exact rim receipts | 4/4 `rim-branch` lines byte-identical to TB107; zero `rim-branch-agreement` lines |
| New annulus receipts | **12/12**, three schedules for each of four analytic cases |
| Cylinder mandatory per-arc census | `periodic=1`, `rimEdges=32`, `split=0`, `vertexBreaks=32`, `equalOutput=32`, `evenSplit=32` |
| Cylinder schedules | `chained` and `stopped` receipt strings identical except `schedule=` |
| Production census | Three executed; Cylinder 1 PASS; BunnyRandom and Vase 2 expected, registered RED; substantive ledger identical to TB107 |
| Execution boundary | Verified source/package IDs, postflight true, exit zero; `compile=false`, `configure=false`, `relink=false`, `benchmark=false` in both results |

### New annulus-rim receipts (verbatim)

```text
annulus-rim case=CloseSheets schedule=chained periodic=0 rimEdges=24 split=0 vertexBreaks=0 equalOutput=0 evenSplit=0
annulus-rim case=CloseSheets schedule=perArc periodic=0 rimEdges=24 split=0 vertexBreaks=24 equalOutput=8 evenSplit=24
annulus-rim case=CloseSheets schedule=stopped periodic=0 rimEdges=24 split=0 vertexBreaks=0 equalOutput=0 evenSplit=0
annulus-rim case=Cylinder schedule=chained periodic=1 rimEdges=32 split=0 vertexBreaks=28 equalOutput=28 evenSplit=28
annulus-rim case=Cylinder schedule=perArc periodic=1 rimEdges=32 split=0 vertexBreaks=32 equalOutput=32 evenSplit=32
annulus-rim case=Cylinder schedule=stopped periodic=1 rimEdges=32 split=0 vertexBreaks=28 equalOutput=28 evenSplit=28
annulus-rim case=MultiFaceSeam schedule=chained periodic=0 rimEdges=16 split=0 vertexBreaks=0 equalOutput=0 evenSplit=0
annulus-rim case=MultiFaceSeam schedule=perArc periodic=0 rimEdges=16 split=0 vertexBreaks=16 equalOutput=0 evenSplit=16
annulus-rim case=MultiFaceSeam schedule=stopped periodic=0 rimEdges=16 split=0 vertexBreaks=0 equalOutput=0 evenSplit=0
annulus-rim case=Plane schedule=chained periodic=0 rimEdges=14 split=0 vertexBreaks=0 equalOutput=0 evenSplit=0
annulus-rim case=Plane schedule=perArc periodic=0 rimEdges=14 split=0 vertexBreaks=14 equalOutput=4 evenSplit=14
annulus-rim case=Plane schedule=stopped periodic=0 rimEdges=14 split=0 vertexBreaks=0 equalOutput=0 evenSplit=0
```

This census is an **observation of three candidate schedules**, not proof that the periodic annulus producer already consumes chained/stopped A3. On Cylinder the chained/stopped schedules place 28 instead of 32 rim vertex breakpoints, although both schedules agree with each other. RA-227 requires the next Review to decide the annulus reader and O36 condition. Do not infer a producer switch from these numbers.

The two registered production failures are unchanged. BunnyRandom still reports `InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch` at source vertex 49. Vase still stops with `NotProductionReady:completion` and `AggregateCompletionValidationFailure` after 189,462 traces, 26,817 arrangement cells and 67,750 partial completion quads. They remain existing obligations, not newly accepted output.

CP2 accepted authority remains 491/491; CP3/selector497 unpromoted. Stable regression accounting remains 66 events / 17 categories / 49 recurrences; debt 1 and deferred 81 unchanged. O36 remains unwired. PR #8 stays draft/open/unmerged.

## Recommendation

Close TB108 as **COMPLETE / scoped MATCH**, without promoting CP3 or changing any producer/selector. The authorized **next separate Review-only** turn is `M6-CP3-DEFN-P13-A3-ANNULUS-RIM-SCHEDULE`; this execution agent must not open, resume, or draft its work. This report and the verified artifact comparison are the review input.
