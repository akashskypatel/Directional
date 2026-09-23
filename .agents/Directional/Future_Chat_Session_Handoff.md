# Directional Future Chat Session Handoff

## Current authority

`M5-CP3-CB17` is **COMPLETE / RUNTIME-FREE / COMPILE GREEN / RUNTIME UNPROVED** once terminal `STATUS` is published.

Accepted runtime authority remains package `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. R14 on CB16 remains the latest runtime at **446/448 PASS** with complete **916/916** evidence; produced rows4/5 remain the only RED identities and that candidate remains unpromoted. Stable accounting remains **51 events / 14 categories / 37 recurrences**; produced-witness debt remains **3**.

CB17 implements frozen §16.3 at semantic source `1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`:

```text
Q = G_R^-1 o A o G_F
Forward: branch = G_F^-1 sourceBranch; coord = rawCutCoord
Reverse: branch = Q o (G_R^-1 sourceBranch); coord = rotate(Q, rawCutCoord)
```

`Q`, not raw `A`, is relation rotation authority. `SurfacePeriodicRelationEndpointState.generatorRotation` is renamed to `relationRotation`; checked-product validation consumes the same authority. A synthetic focused contract uses `A=1, G_F=2, G_R=1`, yielding `Q=2 != A`, and independently proves both gauge terms are required. Fixture/field/A3/`PeriodicRelationId`/selector430 bytes remain unchanged.

CB17 compile/package evidence is `35845003340 / 107128980299`, candidate/log artifacts `10742798135 / 10743207155`; all eight mandatory targets compile/link with GMP/GMPXX, root manifest is **28/28**, source receipts are clean and `runtimeExecution=false`. No Directional binary was executed.

## Exact next turn

**`M5-CP3-TB1-R15-EXEC`** under `.agents/Directional/Architecture_M5_CP3_TB1_R15_Artifact_Only_Test_Benchmark_Plan.md`.

R15 is immutable artifact-only runtime of the CB17 candidate. Exact final CB17 inventory freezes **448 fresh processes**: corrected mechanism/semantic **11**, focused atlas **1**, produced **6**, selector430 **430**, benchmark **0**. It must then route to mandatory **`M5-CP3-TB1-R15-REV`** regardless of PASS/RED.

R15 Review must independently adjudicate product recovery, the carried R6 direction observation, the two nonzero-Z4 produced debts, the CP2 publication observation, and R14-REV's requirement that the synthetic nonzero-gauge mechanism be explicitly distinguished from the committed produced witness's zero-gauge `G_F=G_R=0` case.

## Resume-critical evidence

- CB17 Code + Build record: `.agents/Directional/Architecture_M5_CP3_CB17_Relation_Frame_Gauge_Cutover_Code_Build_Record.md`
- exact next plan: `.agents/Directional/Architecture_M5_CP3_TB1_R15_Artifact_Only_Test_Benchmark_Plan.md`
- frozen definition record: `.agents/Directional/Architecture_M5_CP3_DEFN_R1_Same_Region_Nonzero_Z4_Gauge_Reconciliation_Definition_Record.md`
- frozen definitions: `.agents/Directional/Architecture_M5_Frozen_Definitions.md` §16.3
- latest runtime report: `.agents/Directional/Architecture_M5_CP3_TB1_R14_Artifact_Only_Test_Benchmark_Report.md`
- tracker: `.agents/Directional/Regression_Root_Cause_Tracker.md`
- consolidated history: `.agents/Directional/M5_Consolidated_Record.md`
- CB17 semantic source: `1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`
- CB17 candidate: `10742798135`
- CB17 compile run/job: `35845003340 / 107128980299`
- candidate/log ZIP SHA-256: `eb1e2be55150022cdba05acf6b38433eb16352e4b3b6a561742e62de26cfd866 / cc58680de72ec58dc3cc74d3a1971d881f6232be923f0eb8672dad711e69354c`
- root manifest: `a6c288ff4ef5afff8122f9dae0e330fe1cab4928b7bd5b5604b7d2fd5e32b951`, **28/28**
- source archive: `e6bed804841ecf590ccd1c372c906e19b927e5cf0d253d0d361993fa92ce68e0`
- selector430/first427: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6 / f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`

## Context Load Plan

```yaml
load_next:
  - .agents/Directional/Architecture_M5_CP3_TB1_R15_Artifact_Only_Test_Benchmark_Plan.md
  - .agents/Directional/Architecture_M5_CP3_CB17_Relation_Frame_Gauge_Cutover_Code_Build_Record.md
deep_references:
  - .agents/Directional/Architecture_M5_Frozen_Definitions.md
  - .agents/Directional/Architecture_M5_CP3_DEFN_R1_Same_Region_Nonzero_Z4_Gauge_Reconciliation_Definition_Record.md
  - .agents/Directional/Architecture_M5_CP3_TB1_R14_Artifact_Only_Test_Benchmark_Report.md
  - .agents/Directional/Regression_Root_Cause_Tracker.md
  - .agents/Directional/M5_Consolidated_Record.md
do_not_preload:
  - M6 occurrence work
  - selector publication before a complete green CP3 pre-publication Review
  - fixture/field/A3 retuning
  - any rebuild or source mutation inside R15 EXEC
```
