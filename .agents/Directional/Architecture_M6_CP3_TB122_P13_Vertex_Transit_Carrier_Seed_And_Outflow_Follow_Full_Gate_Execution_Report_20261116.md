# TB122 — vertex transit carrier seed and outflow follow, full-gate execution (2026-11-16 UTC)

## Situation

**MISMATCH** under [RA-241 §4](Architecture_M6_CP3_DEFN_P13_Edge_Transit_Seed_Conformance_Outcome_Review_20261116.md): the immutable CB141 full gate executed **949/949** registered rows, **948 PASS / 1 RED**. The only RED is the new row 949, `ResolvedBranchCorrection.OwnerWithoutOutflowFollowsFieldAcrossRadialEdge`. The three-case census completed with registered verdicts (Cylinder PASS; BunnyRandom and Vase RED), but the required 949/949 gate condition fails. This turn makes no producer, test, fixture, manifest, selector, or build change. The only authorized next turn is **Review-only** `M6-CP3-TB122-P13-VERTEX-TRANSIT-CARRIER-SEED-AND-OUTFLOW-FOLLOW-FULL-GATE-REV`. It must adjudicate row 949 before any implementation.

## Background — frozen execution authority

- Compiled CB141 source `2dedeb097a7d652fd50979c9edbf7acc11222a9c`; immutable package artifact `14213982150`, ZIP SHA-256 `ea09976a5b961bf5a384e9eaf3ea2c1498a7dbab0a67858c218513d34565f497`; 28/28 package checksums verified in prior session. The package is not rebuilt or modified.
- Full gate: [run 43848562969](https://github.com/akashskypatel/Directional/actions/runs/43848562969), event `a298929cb36cc85ad41b7d75892ea903efb6cebe`, artifact `14216937463`, ZIP SHA-256 `161a6c0bbaaa919672d5f4e9dc067cdabd25cabe6b069109aa2097254820dc23`, **1,906/1,906** internal checksums verified. Frozen manifest SHA-256 `a56ad00ce48424a8505b7a6ab71500a4c60285b3d96ceecaf7cf1a3724f5f2b1`, 949 cases; membership 1,030; deferred 81.
- Census: [run 43848642973](https://github.com/akashskypatel/Directional/actions/runs/43848642973), event `2d1c0a6272e4e77205a52afa176c38819375d271`, artifact `14217871018`, ZIP SHA-256 `91c7273f140fc779e02949a47b9eed6e2da49119910021ff041ab04f4220ebb5`, **9/9** internal checksums verified. Frozen manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.
- Both mailboxes confirm their exact events, source SHA, artifact IDs, and their workflow results. Both result boundaries report `compile=false`, `configure=false`, `relink=false`, `benchmark=false`, `postflight=true`. Gate status `exit=90` is a real failed control, not a transport failure; census `exit=0` records successful execution of the registered census.
- Independently rechecked TB121 baseline: gate artifact `14208145885`, **1,902/1,902** internal checksums; census artifact `14208251561`, **9/9** internal checksums. Comparisons use the verified raw logs and ledgers, not the workflow status badge.

## Assessment — exact gate failure

| Gate item | Observed |
|---|---|
| 949 registered cases | 949 executed, 0 skipped, 0 missing, 0 duplicate, 0 abnormal |
| 949/949 PASS requirement | **FAIL: 948 PASS, 1 RED** |
| Membership and deferred | **1,030** and **81**, as frozen |
| Rows 1–947 | **947/947** semantic ledger rows agree with TB121 after excluding raw-log hashes; all required receipt lines agree in order |
| Row 948 carrier seed | **PASS** |
| Row 949 field outflow follow | **RED**, one Google Test expectation at `tests/FieldAlignedCurveNetworkTests.cpp:12326` |
| R1, seed and follow receipts in gate | **0 in all 949 rows** |

Row 949 fails in its `cross` subcase. The test expects `elected.nextBranch == follow.continuation.nextBranch`, but the exact log records `elected.nextBranch = 2`, `follow.continuation.nextBranch = 3`. The test's own expected continuation *face* and *kind* were not reported as failures. The source code assigns the continuation branch from the destination sector, not by copying the elected branch. Branch values belong to source-face branch frames; cross-face numeric equality is not established by this log. **The defect's owner is not yet proven.** Independent Review must check the test's asserted branch relation against the actual field-transport contract and inspect whether the producer selects a correct branch. Do **not** weaken or remove the assertion merely to obtain a green result, and do not label the source production algorithm correct on this evidence alone.

## Assessment — census and source-authoritative behavior

- Cylinder row 1: **PASS**, all inherited receipts identical to TB121.
- Vase row 3: registered **RED**, all inherited receipts and its exact terminal unchanged: `NotProductionReady:completion / AggregateCompletionValidationFailure` with **189,462** trace segments, **26,817** arrangement cells and **67,750** completed quads (not accepted output).
- BunnyRandom row 2: registered **RED**, but terminal advances from `NotProductionReady:field-aligned-network / BranchContinuationDegenerateEntry`, face `(137,149,162)`, edge `(137,149)`, to `NotProductionReady:surface-cut-graph / CellularityNotEstablished / origin=MandatoryEdgeTerminalOrderUnresolved`, edge `(241,251)`; **0** trace segments, **0** arrangement cells, **0** completed quads are reported at that terminal. The stage owner and root cause of the *new* failure are not established in this Test + Benchmark turn.
- The **16** positive edge-port units across **14** `FieldTransportAtlas.partition edgePorts` lines in BunnyRandom agree **16/16** with TB121, in order. (`edgePorts=2` contributes two units for each of two lines.)
- BunnyRandom `vertexOutflowFollow` emits six raw log occurrences of two distinct lines: `trace=24 step=0 vertex=48 outcome=Slide elected=(48,271,272) continuation=(48,271,272) branch=3 carrier=(48,271)`; and `trace=99 step=0 vertex=349 outcome=Cross elected=(5,102,349) continuation=(5,306,349) branch=2`. The first is repeated three times, as is the second, in the raw log. No seed-conformance line appears. Predictions S1–S4 have the stated observations, but predictions are not acceptance requirements.
- The verbatim complete **102** required R1/sector/seed/follow/departure lines, including repeats and their original ordering, are preserved in the immutable census artifact `14217871018` under `raw/2.log` and in `TB122_VERBATIM_REQUIRED_RECEIPTS.txt` (companion evidence). No gate log contains such a line.

## Regression classification and recommendation

1. **New required-green control failure, non-stable candidate.** Row 949 is the only lost required gate row. The failing assertion compares local branch numbers across two faces after a `Cross` transition. Whether the source or the oracle is wrong requires Review. The result is MISMATCH even though every prior control remains green.
2. **BunnyRandom first-terminal movement, non-stable P13-e candidate.** The prior vertex-137 blockage is no longer the first terminal. The newly visible `surface-cut-graph` edge `(241,251)` failure must be diagnosed independently. It is still an off-gate red case; no new stable accepted regression ID or count change is justified by this turn.
3. **No synthetic acceptance.** The accepted CP2 baseline remains 491/491, stable regression ledger **66 events / 17 categories / 49 recurrences**, produced-witness debt 1, deferred 81. Keep D11=A, D12=A, D10 deferred, D6 pending, O42/O43/O44 open, `chainRimSchedules=false`, and CP3/selector497 unpromoted. No merge or production promotion is authorized.

**Next separate turn:** `M6-CP3-TB122-P13-VERTEX-TRANSIT-CARRIER-SEED-AND-OUTFLOW-FOLLOW-FULL-GATE-REV` (Review). It must diagnose branch-frame semantics and the observed new surface-cut-graph terminal. TB122 does not execute that Review or change compiled inputs.
