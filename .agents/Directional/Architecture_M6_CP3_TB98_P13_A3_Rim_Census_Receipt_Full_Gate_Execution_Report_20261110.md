# TB98 — A3 rim census receipt full-gate execution (2026-11-10 UTC)

**Canonical turn:** `M6-CP3-TB98-P13-A3-RIM-CENSUS-RECEIPT-FULL-GATE-EXEC` (step 64C.2, artifact-only Test + Benchmark). **COMPLETE / MATCH**, subject to the immutable RA-222 gate as amended by RA-223. This is not the D4/D5 production A3 switch and does not promote CP3 or selector497.

## Immutable authority and execution boundaries

- **Package:** CB117 source `f3ad580ba0f0178e399d1cfeda258e55a5055f7f`, exact compile artifact `13798262569` from [run 42890766143](https://github.com/akashskypatel/Directional/actions/runs/42890766143); ZIP SHA-256 `1373a09070e1092afb9246dacec5a22cb65941221ffacc15114ea65ee1f507d0`, **28/28** internal file hashes verified, GMP/GMPXX build. No package rebuild or repair.
- **Manifest:** [frozen 935-row manifest](gates/Architecture_M6_TB98_P13_A3_Rim_Census_Receipt_Full_Gate_Case_Manifest.tsv), SHA-256 `2c967a93e54223000b30539f8be76a2240d68f874446d9d77350846856e5a3a6`; membership **1016** = 935 GATED + 81 DEFERRED, ledger v5 unchanged.
- **Full gate:** event commit `46528a8019d96dccf0a9ba19e87f85afda712bc7`; [run 42898298137](https://github.com/akashskypatel/Directional/actions/runs/42898298137) SUCCESS, result artifact `13801897851`, ZIP SHA-256 `62c151fa70d77a7d6f0bd82dcdb294a9bd6682364b8b3623e674bceeb67cbe57`, **1,878/1,878** result hashes verified. Source-authoritative executable checkout matched `f3ad580ba0f0178e399d1cfeda258e55a5055f7f`.
- **Three-case census:** event commit `bd3ee0b288f5f95dab2efe448cb6fa5dbd26670f`; [run 42897885854](https://github.com/akashskypatel/Directional/actions/runs/42897885854) SUCCESS, result artifact `13801202935`, ZIP SHA-256 `85bed1ff8e7a610838a61695ef865263f64642afa1734ca73e1adb9ba041de4d`, **9/9** hashes verified.
- **Boundary:** both `execution-boundary.json` documents name the same exact source/package, `configure=false`, `compile=false`, `relink=false`, `benchmark=false`, `postflight=true`, `exit=0`, and an empty error. Runtime ran only in approved immutable GitHub Actions harnesses; no local project binary ran. Workflow compile/Drive-apply jobs were skipped.

## Gate, census, and byte-exact baseline evidence

- **935 planned / 935 executed / 935 PASS**, 925 GUARD and 10 POSITIVE; zero red, abnormal, missing, skipped, duplicate, control error, unexpected pass, later positive red, or invalid red-site result.
- Every one of the inherited first 931 TB97 ledger entries agrees on all semantic and control columns (the process-specific raw-log SHA-256 column is excluded). No inherited positive or guard changed disposition.
- Exactly seven `platform-digest` raw records and seven `a3-coverage` raw records across the gate and census are **byte-identical to TB97**, each compared in its original process order. The hashes were not substituted for the raw lines.
- **Census:** 3/3 executed; Cylinder PASS, BunnyRandom RED, Vase RED. Both REDs are registered earlier production candidates, not new stable regressions. The immutable census did not produce additional typed cause evidence (`reason-not-observed`). Its result had no missing, abnormal, skipped, duplicate, control, or unexpected pass outcome.

## New D4 rim receipts — four verbatim raw lines (evidence, not pass conditions)

```text
d4-rim case=Plane inputs=own phaseFront=Produced rimArcs=14 sides=4 perArcTotal=42 outputRimEdges=32 unresolved=0 arcs:perArc/chained/output/recorded=4:12/10/8/0,3:9/10/8/0,3:9/10/8/0,4:12/10/8/0
d4-rim case=MultiFaceSeam inputs=own phaseFront=Produced rimArcs=16 sides=4 perArcTotal=48 outputRimEdges=32 unresolved=0 arcs:perArc/chained/output/recorded=4:12/10/8/0,4:12/10/8/0,4:12/10/8/0,4:12/10/8/0
d4-rim case=CloseSheets inputs=own phaseFront=Produced rimArcs=24 sides=8 perArcTotal=96 outputRimEdges=80 unresolved=0 arcs:perArc/chained/output/recorded=3:12/11/10/0,3:12/11/10/0,3:12/11/10/0,3:12/11/10/0,3:12/11/10/0,3:12/11/10/0,3:12/11/10/0,3:12/11/10/0
d4-rim case=Cylinder inputs=own phaseFront=Produced rimArcs=32 sides=30 perArcTotal=64 outputRimEdges=64 unresolved=0 arcs:perArc/chained/output/recorded=1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,2:4/4/4/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,2:4/4/4/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0,1:2/2/2/0
```

`inputs=own` and `phaseFront=Produced` for all four fixtures. The chained schedule assigns 10 intervals per side to Plane and MultiFaceSeam, while the output has 8 per side. For CloseSheets, it assigns 11 against 10 output intervals per side. The Cylinder per-arc and output totals agree at 64; its grouped side counts also agree. All four fixtures report `recorded=0` per side and zero unresolved entries. These observed mismatches confirm that the unwired D4/D5 switch **cannot be accepted by these measurements**; the chained schedule alone has not demonstrated matching output side counts. They are not regressions in the frozen TB98 gate because this test reports rather than asserts numerical equality. The later O36 design/review owns the required corrective decision. No heuristic, test assertion, or accepted output was changed here.

## Orchestration correction and disposition

- First gate request event `7184aafb49688a46309ca85041eae24229696382`, [run 42897740832](https://github.com/akashskypatel/Directional/actions/runs/42897740832), exited **90 before test execution** (`case manifest missing/unsafe`; 0 planned/0 executed). It checked out an older harness-executor revision without TB98's manifest. This attempt provides no semantic verdict. No package mutation or rebuild occurred.
- Corrected the request to use the exact CB117 source commit as the executor, retaining the identical immutable artifact, manifest, harness checksum and gate semantics. The corrected [run 42898298137](https://github.com/akashskypatel/Directional/actions/runs/42898298137) produced the complete verified outcome above. No orchestration-correction product turn or source changes were needed.
- **MATCH** under RA-222/RA-223: accepted CP2 **491/491**, stable regression **66 events / 17 categories / 49 recurrences**, debt **1**, deferred ledger v5 **81**; no accepted-green loss or newly established stable issue. CP3 and selector497 remain unpromoted; production A3 still uses per-arc input and uniform producer still ignores the plan. O34/O35/O36/O37, D6, and the remaining D4/D9c/A2b/A4/D8 work stay open.
- **Authorized successor, not started in this turn:** `M6-CP3-CB118-P13-A3-UNIFORM-DECLINES-CHAINED-PLAN` (64C.3, compile only), using RA-223's exact frozen CB118 patch; then TB99 in a different turn. No successor code or test was changed here.
