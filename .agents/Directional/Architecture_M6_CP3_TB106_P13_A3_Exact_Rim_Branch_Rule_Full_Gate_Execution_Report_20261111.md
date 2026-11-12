# TB106 — exact rim branch rule full gate (2026-11-11 UTC)

## Situation

**COMPLETE / scoped MATCH** against TB105 and RA-226 §6. The immutable CB125 gate passed **943/943** with **1,024** required membership entries. The separate three-case production census retained Cylinder PASS and BunnyRandom/Vase registered RED; no production promotion follows.

## Background

- Canonical turn: `M6-CP3-TB106-P13-A3-EXACT-RIM-BRANCH-RULE-FULL-GATE-EXEC` (64B.25), artifact-only Test + Benchmark. Exact CB125 semantic source `0ff93f167feb69dc290d4f220a0f8d32a906e2f7`, immutable package `13894015691`, ZIP SHA-256 `72aca96c3a4fdfc8707e8a4b24ff678455184f4c573650535dc176f78fa58d54` (28/28 package checksums). No rebuild, configure, relink, repair, or benchmark was performed.
- Frozen gate manifest `.agents/Directional/gates/Architecture_M6_TB106_P13_A3_Exact_Rim_Branch_Rule_Full_Gate_Case_Manifest.tsv`: 943 rows, SHA-256 `938836fc3326df11ccb3d475e0c6a3a4d629d8ac6e252436dcfac47286bfb651`, membership 1,024. The first 942 test rows remain the TB105 controls.
- [Full gate run 43110402612](https://github.com/akashskypatel/Directional/actions/runs/43110402612), event `062889841320852680d711836c24742fc6b0fdd1`: result artifact `13895769513`, ZIP SHA-256 `5647113ed0f135b4265999cad04fbe236abd05999f0f64c3bd5dcca1c842fd5f`, 1,894/1,894 checksum entries; diagnostic artifact `13896966873`, ZIP SHA-256 `dd7d0b3b44d488cb3434f85a732d0ec367c0b57c434bdb5c71f2b025f86ad33b`.
- [Production census run 43110688688](https://github.com/akashskypatel/Directional/actions/runs/43110688688), event `bbac1effc586d8019ae73ef89f9e122f3cf15eae`: result artifact `13897142531`, ZIP SHA-256 `ec75cd1ebcee63f6d01cf3d2fa58215e2d920306bb0825aff2b62a5bf5a9372d`, 9/9 checksums; log artifact `13896647867`, ZIP SHA-256 `9dade29f7578b09b0da939a0a781bcba4db1ac9b851c6f3002d92508c8526230`.
- Exact source-inspection snapshot `99d0e2d5365ca0ea6529944786b04652f7d3fdc4`, [run 43109710948](https://github.com/akashskypatel/Directional/actions/runs/43109710948), artifact `13896240459`, ZIP SHA-256 `8af0ad574dec56288d8ad75436e5e30c759a2b4467361855b8f29c6ab4ff7cb7`; 5,482/5,482 source checksums. This is inspection authority, not compiled-source authority.
- TB105 baseline: gate artifact `13876851723`, ZIP SHA-256 `176f110f9e1a0b7932380ca94a0c530a0430be6ec418d5385fa23bc5d4dab594` (1,892/1,892 checksums), and census artifact `13877545718`, ZIP SHA-256 `26c436c1de39d0e64cfb705b44de834fa7250237dd4ec211c1221bd4da1ab88e` (9/9 checksums).

## Assessment

| Independent check | Outcome |
|---|---|
| Full gate | 943 planned/executed/PASS; 0 RED, abnormal, missing, skipped, duplicate, control error, unexpected pass or later-positive RED; postflight true; exit 0 |
| Inherited test records | All first 942 entries match TB105 on the 12 substantive ledger columns; the only addition is `ra226:exact-rim-branch-threshold-and-ties`, which passed |
| Membership | 1,024 (TB105 1,023), exactly one new entry; none removed |
| Old raw receipts | **25/25 byte-identical** across TB105 gate+census and TB106 gate+census: 7 platform digests, 7 A3 coverage, 4 D4 rims, 4 D4 corners, 2 field corners and 1 derived corner |
| New receipts | Four `rim-branch`, four `rim-branch-agreement`; each has `exactOnly=0`, `binary64Only=0` and `differ=0` |
| Three-case production census | Cylinder PASS, BunnyRandom RED, Vase RED; 3/3 original substantive ledger records, all six platform/coverage lines and both RED terminal lines match TB105; no abnormal |
| Artifact boundary | Exact CB125 package and source; no compile, relink, configure or benchmark; runtime was artifact-only |

The eight new receipt lines, recorded verbatim:

```text
rim-branch case=Plane rimEdges=14 decided=14 undecided=0
rim-branch case=MultiFaceSeam rimEdges=16 decided=16 undecided=0
rim-branch case=CloseSheets rimEdges=24 decided=24 undecided=0
rim-branch case=Cylinder rimEdges=32 decided=32 undecided=0
rim-branch-agreement case=Plane same=14 exactOnly=0 binary64Only=0 differ=0
rim-branch-agreement case=MultiFaceSeam same=16 exactOnly=0 binary64Only=0 differ=0
rim-branch-agreement case=CloseSheets same=24 exactOnly=0 binary64Only=0 differ=0
rim-branch-agreement case=Cylinder same=32 exactOnly=0 binary64Only=0 differ=0
```

The BunnyRandom first failure remains `SurfaceCellDesignAcceptanceTests.cpp:273`, terminal `InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49`. Vase remains the same assertion with `NotProductionReady:completion`, detail `AggregateCompletionValidationFailure`, 189,462 trace segments, 26,817 arrangement cells and 67,750 completed quads. Cylinder remains a direct output PASS. None is a new regression.

**Regression disposition:** No accepted-green loss, new stable regression, event, category or recurrence. Accepted CP2 remains **491/491**; stable events/categories/recurrences **66/17/49**; debt **1**, deferred **81**. O39 is defined and the unwired exact function passes its focused test and four-fixture agreement; O39 is **not discharged** until the separate CB126 → TB107 switch. O36 remains unwired; CP3/selector497 remains unpromoted; PR #8 remains draft and unmerged.

## Recommendation

Close TB106 as **COMPLETE / scoped MATCH**. The sole authorized successor is `M6-CP3-CB126-P13-A3-EXACT-RIM-BRANCH-OWNER` (64B.26), a separate compile-only turn using RA-226's frozen patch. **Do not execute CB126 in TB106.** Preserve the immutable evidence and frozen selectors.
