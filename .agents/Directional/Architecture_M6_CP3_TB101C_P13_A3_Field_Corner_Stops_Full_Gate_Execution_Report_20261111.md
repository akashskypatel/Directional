# TB101C — Field-corner stops full test gate (2026-11-11 UTC)

## Situation

The exact CB120C immutable package passed **940/940** full-gate cases with membership **1021**; the separate three-case census produced **1 PASS / 2 RED / 0 abnormal**, matching the registered outcomes. Disposition: **MATCH within this gate's scope**, pending the separate independent TB101C Review. CP3 is not promoted.

## Background

- Canonical turn `M6-CP3-TB101C-P13-A3-FIELD-CORNER-STOPS-FULL-GATE-EXEC` (artifact-only Test + Benchmark). Source `e1e5b17e94f189c88c74172e12dfd6ac93cc532b`, GMP/GMPXX compile run [43013777504](https://github.com/akashskypatel/Directional/actions/runs/43013777504), immutable package `13852160952`; ZIP SHA-256 `17dfdcf06d33b312a282d1c6f3cce68223df7010dce367b04897e848a2e16e74`. Packaged checksums 28/28 and compiled source archive SHA-256 `73d340ebf49a7a7a4be95e06ce5a8e4e4d8a8fe7c6a115033a7da7d6e829444f` verified before execution.
- Full gate: [run 43016290356](https://github.com/akashskypatel/Directional/actions/runs/43016290356), result artifact `13853426731`, ZIP SHA-256 `b94d9c201720490e8651655218ebb9ade7f71f62396e25b45d31eef99e7285ee`; **1888/1888** internal checksums correct. `execution-boundary.json` confirms `planned=940, executed=940, passed=940, red=0, abnormal=0, missing=0, skipped=0, duplicate=0, control_bad=0, membership=1021, postflight=true, exit=0`.
- Census: [run 43016362575](https://github.com/akashskypatel/Directional/actions/runs/43016362575), result artifact `13853038984`, ZIP SHA-256 `ce0a4d256449e5aea6108044ddfe90b31634eefe394031922bb98c6482d0f05e`; **9/9** checksums correct. `planned=3, executed=3, passed=1, red=2, abnormal=0, control_bad=0, postflight=true, exit=0`.
- Both execution boundaries name source `e1e5b17e94f189c88c74172e12dfd6ac93cc532b` and artifact 13852160952; `configure=false, compile=false, relink=false, benchmark=false`. No local executable was run, and source, fixtures, tests, selector, or workflow logic were not modified.
- Exact source snapshot for read-only inspection: source `d12ac0bfecf3461fe35bc3e3c16a98d33360481d`, [run 43014623233](https://github.com/akashskypatel/Directional/actions/runs/43014623233), artifact `13851584015`; **5458/5458** source checksums matched. It is not the compiled package identity.

## Assessment

- Compared with accepted TB100B gate, all **938 inherited** ledger rows equal on `row, kind, identity, test, binary, verdict, exit, run, passed, skipped, typed_reason`. Two appended stops cases passed. The older full gate was 938/938 with membership 1019.
- Four gate `platform-digest` records and four `a3-coverage` records are byte-identical to prior TB100B. Three census platform and three A3 records are also byte-identical. Total **7/7 platform and 7/7 A3** records unchanged. All **four `d4-rim`** records and both `FIELD_CORNER_RECEIPT` lines match TB100B.
- Raw new `d4-corner` results (recorded verbatim):
- `d4-corner case=Plane inputs=own fieldCorners=4 chains=4/4 spans=4/4`
- `d4-corner case=MultiFaceSeam inputs=own fieldCorners=4 chains=4/4 spans=4/4`
- `d4-corner case=CloseSheets inputs=own fieldCorners=8 chains=8/8 spans=8/8`
- `d4-corner case=Cylinder inputs=own fieldCorners=0 chains=2/2 spans=79/79`
- **Historical receipt difference:** the superseded TB101 one-shot plan mentioned `FIELD_CORNER_STOP_RECEIPT`, but no such line exists in CB120C source or 940-case logs. Do not fabricate this receipt or count its absence as a failed executed test. The independent Review must judge whether the changed split-slice evidence contract meets the corrected current TB101C authority.
- Census controls match prior TB100B: Cylinder PASS; BunnyRandom and Vase preserve their two pre-existing registered RED results. These are not newly introduced accepted-green regressions. This limited test result does not establish production path acceptance, exact O39 branch authority, or a D4/D5 switch.

## Recommendation

Keep accepted CP2 **491/491** and stable accounting **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**. Do not promote CP3/selector497 or treat the independent Review as performed. Next and only successor: `M6-CP3-TB101C-P13-A3-FIELD-CORNER-STOPS-FULL-GATE-REV`. Its independent evidence review should examine the four corner receipts, historical stop receipt expectation, strict source/fan-sheet authority, and remaining O39 before O36.
