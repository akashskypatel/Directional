# TB97 — Chain-aware A3 consumers full-gate execution (2026-11-10)

**Canonical turn:** `M6-CP3-TB97-P13-A3-CHAIN-AWARE-CONSUMERS-FULL-GATE-EXEC` (64B.12). **Verified COMPLETE / MATCH** under RA-221 §3.3–§4. Source-grid/production D5 chaining was not enabled. This is an artifact-only test-and-benchmark turn, not a direct-remeshing production acceptance or a CP3/selector497 promotion.

## Immutable source, workflows and execution boundary

- CB116 semantic source `57c253ba782ebc5fbf61b953e0169c4c85f66253`; GMP/GMPXX compile [run 42861295562](https://github.com/akashskypatel/Directional/actions/runs/42861295562); artifact `13784269032`. Previously verified package ZIP SHA-256 `c4eab00c7862b47eff1625fb16a62e836f087d80f5e5ab3762500b1866d5db09`, 28/28 internal hashes.
- Frozen 931-case [TB97 manifest](gates/Architecture_M6_TB97_P13_A3_Chain_Aware_Consumers_Full_Gate_Case_Manifest.tsv) SHA-256 `111afe9375f78ac12d5118f2af494fac87cf43f7ad79fe5ee274bada1aa16341`; ledger v5 deferred 81; membership `1,012 = 931 GATED + 81 DEFERRED`.
- Gate: dispatcher event `f7c132df92f5f53a9477c4c08ab25bd203944239`, [run 42874840055](https://github.com/akashskypatel/Directional/actions/runs/42874840055) SUCCESS, artifact `13792396105`, ZIP SHA-256 `a6d029ad6276f6faa6305ed55aa92a0d277345de71dc7597ec69f3dfe55ed77d`, **1,870/1,870** internal hashes verified.
- Census: event `313a8374638bc41ee758a94e0e83c0d3f0a3510a`, [run 42875147804](https://github.com/akashskypatel/Directional/actions/runs/42875147804) SUCCESS, artifact `13792656711`, ZIP SHA-256 `461e3e97377868acdb40d937a3b91a0baacb46d7443677c3cd02209cde7b1814`, **9/9** internal hashes verified.
- Both workflow mailboxes on isolated `workflow-mailbox` match their exact event and semantic source SHAs. Jobs for `test_benchmark / runtime` succeeded; the compile and Drive-apply jobs were skipped. Each result `execution-boundary.json` verifies package/source, `configure=false`, `compile=false`, `relink=false`, `benchmark=false`, `postflight=true`, `exit=0`, empty error.

## Gate, census and baseline equality

- Full gate: **931 planned / 931 executed / 931 PASS**. `GUARD=921`, `POSITIVE=10`; all 931 ledger verdicts PASS. Missing, skipped, duplicate, abnormal, control, unexpected pass, later positive red, and red-site-bad counts are all zero. Inherited first 929 TB95 ledger rows agree on all semantic/control fields (raw process log hashes are not treated as semantic fields).
- Census: **3/3 executed**; Cylinder PASS, BunnyRandom RED, Vase RED. These are previously registered, non-promoted producer/completion failures; the census boundary records no abnormal, missing, skipped, duplicate, or control issue.
- Literal comparison of raw logs to immutable TB95: **7/7** `platform-digest` records and **7/7** `a3-coverage` records are byte-identical, counting four gate lines plus three census lines per family. No unchanged output digest has been inferred from a summary alone.

## Consumer receipts — verbatim from gate row 931

```text
D5_CONSUMER_RECEIPT case=unit chains=4 chainedArcs=4 cells=8 chainIntervals=8 coveredPerArc=20 coveredChained=16
D5_CONSUMER_RECEIPT case=fixtureTarget spans=1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,2:8,2:8,2:8,2:8 disposition=Produced reason=None covered=16/16
```

The `fixtureTarget` receipt reports `disposition=Produced`, `reason=None`, and `covered=16/16`. This is required evidence, **not a gate pass condition**. The consumers remain behind the unwired production switch, O36; it does not certify hard-feature chaining, disc-corner stops or every production layout.

## Disposition, preservation and next turn

**MATCH.** Accepted CP2 remains **491/491**, stable **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**; no accepted-green loss, new stable event or new regression category is inferred. P13-e BunnyRandom and Vase remain registered RED; selector497/CP3 unpromoted. No product source, tests, selectors, fixtures or workflows were modified by TB97. Snapshot/compile package were reused and no local project binaries were executed.

A prior same-turn attempt had an initial read-mode ordering violation and a stale GitHub blob SHA write conflict; it recovered without changing source. All TB97 gate/census result archives were retrieved once in the continuation and checked independently. The prior 15-minute attempt closed while awaiting mailbox publication; this continuation verified both. Tool-call ledger across both attempts was incomplete; total **unknown**, not fabricated.

**Authorized successor, NOT started in this TB97 turn:** `M6-CP3-DEFN-P13-A3-UNIFORM-PLAN-CONSUMPTION` (Review only), RA-221 step 64C. O36 production switch remains unscheduled; O37 and O38 work remain open. No production switch or successor review was performed.
