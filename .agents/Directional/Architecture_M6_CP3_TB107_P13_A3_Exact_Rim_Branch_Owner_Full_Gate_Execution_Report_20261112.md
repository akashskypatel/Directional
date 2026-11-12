# TB107 — exact rim branch owner full-gate execution (2026-11-12 UTC)

## Situation

**COMPLETE / scoped MATCH** against TB106 and RA-226 §7. Immutable CB126 package passed **943/943** required test cases with **1,024** required membership entries. Three-case production census remains **Cylinder PASS / BunnyRandom RED / Vase RED**, exactly as registered. No CP3/selector497 production promotion.

## Background and immutable authority

- Canonical turn: `M6-CP3-TB107-P13-A3-EXACT-RIM-BRANCH-OWNER-FULL-GATE-EXEC` (64B.27); artifact-only Test + Benchmark.
- CB126 semantic source `3ac6801e4bffb721ffce993cba1e4157b6fa31b8`; compile run [43117594163](https://github.com/akashskypatel/Directional/actions/runs/43117594163), packaged artifact `13898984781`, ZIP SHA-256 `6fd3b5a1a4aa2845afd74a4fa48bbb884c68a8977657dbb7634e840c8524f341`, internal build package 28/28 verified. Exact arithmetic uses GMP/GMPXX. No recompilation, repair, fixture change, relink, configuration or benchmark in TB107.
- Frozen full-gate manifest `.agents/Directional/gates/Architecture_M6_TB107_P13_A3_Exact_Rim_Branch_Owner_Full_Gate_Case_Manifest.tsv`, **943 rows**, SHA-256 `938836fc3326df11ccb3d475e0c6a3a4d629d8ac6e252436dcfac47286bfb651`; byte-identical to TB106 manifest. Membership 1,024.
- [TB107 gate run 43123561178](https://github.com/akashskypatel/Directional/actions/runs/43123561178), dispatch event `ca4e6034a364a92f2c7e58f961c3b2f79fc18854`, result artifact `13902266978` ZIP SHA-256 `0811ec78744e3450de2fc9f338a07e4c6ec877084272ef19ae7b977a7b5ed796`, 1,894/1,894 evidence SHA256SUMS checks.
- [TB107 census run 43123599679](https://github.com/akashskypatel/Directional/actions/runs/43123599679), dispatch event `fb648655e34a973431e50c05bc330570edbd49c2`, result artifact `13902008013` ZIP SHA-256 `dd7d6b5322489bce80d0257e9d5e489ce9906ea7e3726e69628afc21c6ad8fff`, 9/9 evidence SHA256SUMS checks.
- TB106 baseline: gate artifact `13895769513` ZIP SHA-256 `5647113ed0f135b4265999cad04fbe236abd05999f0f64c3bd5dcca1c842fd5f`; census artifact `13897142531` ZIP SHA-256 `ec75cd1ebcee63f6d01cf3d2fa58215e2d920306bb0825aff2b62a5bf5a9372d`. All four result ZIP hashes checked locally.

## Assessment

| Independent gate | Outcome |
|---|---|
| Full gate | 943 planned, 943 executed, **943 PASS**, 0 RED, missing, skipped, duplicate, abnormal, unexpected PASS, control failure or later-positive RED |
| Membership | **1,024**, byte-identical membership file to TB106 |
| Test ledger | All 943 substantive records byte-equal by required columns to TB106; log hashes differ as expected for independent processes |
| Inherited raw receipt lines | **25/25 byte-identical** to TB106: 19 from full gate and 6 from production census |
| Rim branch receipt lines | **4/4 byte-identical** to TB106 |
| Removed diagnostic | **0 `rim-branch-agreement` receipts** in both TB107 result streams, as required |
| Production census | **3/3 executed: 1 PASS / 2 registered RED**, same substantive ledger and six raw receipts; no new abnormal or changed typed first failure |
| Evidence and boundaries | Gate evidence 1,894/1,894 checksums and census 9/9; postflight true for both; no compile, relink, configure or benchmark |

Four retained exact raw receipts:

```text
rim-branch case=Plane rimEdges=14 decided=14 undecided=0
rim-branch case=MultiFaceSeam rimEdges=16 decided=16 undecided=0
rim-branch case=CloseSheets rimEdges=24 decided=24 undecided=0
rim-branch case=Cylinder rimEdges=32 decided=32 undecided=0
```

Census observations were unchanged: Cylinder directly produces valid SurfaceCells output. BunnyRandom still rejects at `InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch`, `sourceVertex=49`. Vase still rejects at `NotProductionReady:completion` with `AggregateCompletionValidationFailure` (`traceSegments=189462`, `arrangementCells=26817`, `completedQuads=67750`). These are existing, non-gating, registered RED obligations, not newly introduced production regressions. The raw full terminal lines and six census receipts were compared to TB106; ledger first-failure columns and reasons did not change.

No accepted-green loss or new stable/candidate regression is established. Accepted CP2 remains **491/491**, stable history **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**. O39 exact rule has passed its gated owner change. **O36 remains unwired**; the P13-e and Vase obligations remain open, and CP3/selector497 remains unpromoted. PR #8 remains draft, open and unmerged.

## Recommendation

Close the **TB107 checkpoint as COMPLETE / scoped MATCH**. The authorized successor, in a separate response/turn only, is `M6-CP3-DEFN-P13-A3-ANNULUS-PLAN-CONSUMPTION` (Review-only). Its scope is not part of TB107. No source/test/fixture code change, rebuild or production routing change was authorized in TB107.
