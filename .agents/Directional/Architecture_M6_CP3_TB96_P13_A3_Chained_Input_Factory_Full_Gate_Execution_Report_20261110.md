# TB96 — Chained A3 input-factory immutable full-gate execution (2026-11-10)

**Canonical turn:** `M6-CP3-TB96-P13-A3-CHAINED-INPUT-FACTORY-FULL-GATE-EXEC` (64B.10). **Verified disposition: COMPLETE / MATCH** under RA-221 §3.1–§4. The factory remains unwired: this gate proves the new factory's scoped contract, **not** consumption, a production switch, direct remeshing success, CP3 acceptance or selector497 promotion. No CB116 work occurred.

## Frozen source and execution boundary

- Exact CB113 semantic source [`62493cee6c779613dae389e42ef2e60206fec522`](https://github.com/akashskypatel/Directional/commit/62493cee6c779613dae389e42ef2e60206fec522); compile run [42818942851](https://github.com/akashskypatel/Directional/actions/runs/42818942851); immutable GMP/GMPXX package artifact `13767625281` (ZIP SHA-256 `a51a7ff600087f06dd2843b200f8976599f2795a797860635dc670451b341a20`, 28/28 hashes previously verified in [CB113 record](Architecture_M6_CP3_CB113_P13_A3_Chained_Input_Factory_Code_Build_Record_20261110.md)).
- Frozen manifest [`gates/Architecture_M6_TB96_P13_A3_Chained_Input_Factory_Full_Gate_Case_Manifest.tsv`](gates/Architecture_M6_TB96_P13_A3_Chained_Input_Factory_Full_Gate_Case_Manifest.tsv), SHA-256 `227405f4e775717f7941fc1366fac41098e3dadd36b51eeb7b238e6feb633b26`; its first 929 rows are byte-identical to TB95; final row `ra221:d5-chained-input-factory`. Membership `1,011 = 930 GATED + 81 DEFERRED`.
- Gate: dispatcher event `8e251c73b6e7aff1f5815a11965e04d6e68393f9`, [run 42825856146](https://github.com/akashskypatel/Directional/actions/runs/42825856146) SUCCESS, artifact `13768819367`; outer ZIP SHA-256 `dc4f5165eba6d14f6b0954b6b4ecf60b75becda4a58140f6cbe6f9d464c9b3f4`; **1,868/1,868** packaged hashes verified.
- Census: dispatcher event `dfbe038b643d549b924eb9276210e745a51c0b8e`, [run 42825913745](https://github.com/akashskypatel/Directional/actions/runs/42825913745) SUCCESS, artifact `13769079382`; outer ZIP SHA-256 `513abeebb7ee0d8a75eea6a4e3951ec40fd30615668d5d6fd96aeaed7e36d29c`; **9/9** hashes verified.
- Both independent `execution-boundary.json` records pin the CB113 source/artifact; `configure=false`, `compile=false`, `relink=false`, `benchmark=false`, `exit=0`, `postflight=true`, no harness error. Neither workflow ran the compile operation.

## Gate and census comparisons

- Gate: **930 planned / 930 executed / 930 PASS** (all one-run, one-test, zero skips). All `red`, `abnormal`, `missing`, `skipped`, `duplicate`, `control_bad`, `unexpected_pass`, `later_positive_red` and `red_site_bad` counters are zero. GUARD 930 passed on the packaged binary.
- The 929 inherited TB95 rows are **identical on every ledger semantic/control field** (identity, test, binary, verdict, exit, run, passed, skipped, first failure, typed reason); their raw log hashes differ between fresh processes, as expected. The manifest is a byte-exact TB95 prefix.
- All **seven literal `platform-digest`** and **seven literal `a3-coverage`** records (Plane, MultiFaceSeam, CloseSheets, Cylinder in both gate and census, BunnyRandom, Vase) are byte-identical to TB95. There are six unique fixture identities because Cylinder occurs twice. This comparison uses the original result logs from both verified artifacts, not report summaries.
- Census: **3/3 executed**, Cylinder PASS, BunnyRandom RED, Vase RED; no abnormal/missing/skipped/duplicate/control issue. All three rows are semantically identical to TB95, including each registered RED's first failure `SurfaceCellDesignAcceptanceTests.cpp:271` and `reason-not-observed`. These are the existing P13-e and Vase producer/completion failures; no new stable regression or unrelated failure is inferred.

## New factory receipts (verbatim from gate row 930)

```text
D5_FACTORY_RECEIPT case=unit arcs=20 chains=4 chainedArcs=4 perArc=1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1 chained=1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,1:1,2:2,2:2,2:2,2:2
D5_FACTORY_RECEIPT case=fixtureTarget perArc=1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4 chained=1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,1:4,2:8,2:8,2:8,2:8
```

The fixture-target chained vector includes four two-piece spans with a count of eight, versus per-arc one-piece spans counted four each. This is observation only; it is not proof that the A4 consumer accepts mixed source-boundary and hard-feature chaining.

## Disposition and next authority

**MATCH.** Accepted CP2 **491/491**; stable **66 events / 17 categories / 49 recurrences**, debt **1**, deferred ledger v5 **81**. No accepted-green loss, new stable event, regression category, or recurrence. Selector497/CP3 remains unpromoted. O34–O38 and the original P13-e/Vase failures remain open. Source/test/fixture/selector/workflows were not changed to obtain this result.

Authorized **successor only, not started:** `M6-CP3-CB116-P13-A3-CHAIN-AWARE-CONSUMERS`, compile-only under RA-221 §3.2 and the exact 527-line patch `954b11df326285b2aaa5a293d36ef1c82380628d8ea4209a13d8b8461562a7cf`, on top of CB113. A mismatch would instead require `M6-CP3-TB96-P13-A3-CHAINED-INPUT-FACTORY-FULL-GATE-REV`; none was observed.
