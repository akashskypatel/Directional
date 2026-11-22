# TB164 — Third-edge side-owner census: immutable full-gate execution

## Situation

**TB164 PASSED the full 982-case gate and the separate 3-case production census.** The new 16-line sphere receipt matches every frozen `nearest=6/12` prediction. This is measurement of a diagnostic helper, **not** source-face owner repair or production acceptance.

## Background

- Canonical execution turn: `M6-CP3-TB-EXEC-164-P13-THIRD-EDGE-SIDE-OWNER-CENSUS-FULL-GATE`. Working branch `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 is draft and unmerged.
- Exact semantic source: `a8f7dc13a737487080095fa1aad1901b346ddacb`. CB-182 GMP/GMPXX compiled package `14755496064`, [compile 45023580643](https://github.com/akashskypatel/Directional/actions/runs/45023580643); package SHA-256 `69fff98ad8203b7e2151fed48aa49100bc2a61d14eeb05b85b38a71f7a736aa5`.
- Frozen 982-case manifest: `gates/Architecture_M6_TB164_P13_Third_Edge_Side_Owner_Census_Full_Gate_Case_Manifest.tsv`, SHA-256 `ed615c22e85cbdfa61bb304370ddde51aa68038b04b7139e73066f1e8dae517b`. Separate three-case manifest unchanged, SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.
- Full gate [run 45026871528](https://github.com/akashskypatel/Directional/actions/runs/45026871528), result artifact `14757020531`, outer ZIP SHA-256 `176ab6229182826ecf43d44346e63960c4a40007dde44d6661af9e891c192611`.
- Census [run 45026920896](https://github.com/akashskypatel/Directional/actions/runs/45026920896), result artifact `14757007212`, outer ZIP SHA-256 `69ef085dae88be19d9737eee8e2b7b9c68f9dc00e8929383d6c29cbbaa05465f`.
- Comparison references: TB163 full-gate result `14750681733` (SHA-256 `ed9112f827ae22cea3f80fb32e32594d6a332da30946e0c6fded00e0ae56461e`) and TB161 three-case census `14741883606` (SHA-256 `cc3f200101168f5fd3ff1e0e0dca986adb750dcd7e107a0b03ecc786b4d50b59`).

## Assessment — verified results

| Rule | Measured result |
|---|---|
| Full gate | **982/982 PASS**; 0 RED, abnormal, missing, skipped, duplicate or control failure |
| Accepted CP2 prefix | **491/491 PASS**, unchanged |
| New rows 980–982 | **3/3 PASS**: nearest chord, undecided chord order and carrier-apex distance |
| Gate membership | **1063 = 982 gated + 81 deferred**; TB163's 1060 records preserved and exactly three new gated members added |
| Archive checks | **1972/1972** internal SHA-256 file records match; **982/982** raw-log hashes agree with ledger |
| Predecessor rows 1–978 | **978/978** ledger and normalized raw logs equal TB163 under N1–N3, zero allowance |
| Row 979 | Existing **108/108** `SphereStaged*` lines retained verbatim and in order; only 16 new `SphereStagedUncutSideOwner` lines added |
| N3 whole-record census | **1750/1750** identical; **622/979** predecessor raw logs byte-identical (remaining differences limited to N1–N3) |
| New third-edge receipts | **16/16** match the frozen edge sets, pairwise chord orbit sets and exact `nearest=6`/`12` expectations |
| Production census | **3/3** same expected outcomes as TB161 (Cylinder PASS, BunnyRandom RED, Vase RED), **3/3** normalized case logs equal under N1–N4, 0/3 byte-equal |
| Runtime boundary | `runtimeExecution=true`; unchanged package and exact source; `configure=false`, `compile=false`, `relink=false`, `benchmark=false`, `postflight=true`, exit 0 |

All 16 new row-979 lines are retained verbatim in [the raw receipt](evidence/Architecture_M6_CP3_TB164_P13_Third_Edge_Side_Owner_Census_Raw_20261122.txt). Component 1 has eight edges and `nearest=6`; component 5 has eight edges and `nearest=12`. Every listed `chordOrbits` pair equals the corresponding `sideOrbits` pair as a set. Each set has two members: the middle orbit and the expected outer orbit. The nearest-chord helper resolves these cases; the existing production seed still does not use it.

**Census comparison detail:** All three ledger rows agree, including the exact first-failure and typed reason fields. N4 removes only the approved opaque 16-byte parameter display. Eight N3 records agree. No outcome or failure-site allowance was needed.

**Regression classification:** There is no new stable failure or PASS-to-RED case. The existing sphere source-face ownership defect is not repaired by the census. The retained candidate is the site-C nested-chord over-recording rule; TB164 supports the predicted nearest-chord selection but does not show an active owner seed or source-face cellularity improvement. Site-D fan over-recording (Y7) and the separate H5 lead remain open. Stable counts remain **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, and deferred identities **81**. CP3/497/D0/H4 remain unpromoted. Production sphere still stops at `CutSearchExhaustedBeforeCellularity` and staged row 979 still reports `UncutFaceComponentOrbitSeedNotUnique` at `2-5-12`.

## Recommendation

Next separate turn: `M6-CP3-TB-REV-164-P13-THIRD-EDGE-SIDE-OWNER-CENSUS-FULL-GATE`. That review must independently verify the 16 lines and all unchanged evidence. It must apply the frozen Y6/Y7 decision map before authorizing CB-183. Do not wire owner seeds, modify selectors, alter the frozen test manifest, or claim a production result in TB164.
