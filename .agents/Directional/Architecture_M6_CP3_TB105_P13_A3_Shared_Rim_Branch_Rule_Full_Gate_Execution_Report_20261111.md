# TB105 — shared rim-branch rule full gate (2026-11-11 UTC)

## Situation

**COMPLETE / scoped MATCH** against the frozen TB104 evidence. The immutable CB124 gate passed **942/942** cases with **1,023** required membership entries. A separate production census executed three cases: **Cylinder PASS; BunnyRandom RED; Vase RED**, both RED classifications already registered. No newly observed regression or production promotion follows.

## Background

- Turn: `M6-CP3-TB105-P13-A3-SHARED-RIM-BRANCH-RULE-FULL-GATE-EXEC`, 64B.22, **artifact-only Test + Benchmark**. The source/package were never rebuilt, relinked, repaired or changed during this execution.
- CB124 compiled source `acffbffe7f8cb247f9d6118526f37f7d5a7cebad`; [compile run 43064008515](https://github.com/akashskypatel/Directional/actions/runs/43064008515); immutable package **13876075161**, outer ZIP SHA-256 `7e4cda077030e7db77edbb29eea7d40b43c15ecd452190be4f5ad6a2023cb3f1`; **28/28** package checksums passed. GMP and GMPXX build evidence was preserved by CB124.
- Frozen case manifest: `.agents/Directional/gates/Architecture_M6_TB105_P13_A3_Shared_Rim_Branch_Rule_Full_Gate_Case_Manifest.tsv` SHA-256 `7b0b4545e607b138c03caab682c6d6b698639335fcf497fa8da71751bcea4b9e`; 942 rows byte-identical to TB104, with required membership 1,023. Required harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- [Full gate 43067225397](https://github.com/akashskypatel/Directional/actions/runs/43067225397), event `f315954924413fbe8b44208ddaeb9f8a26798aeb`; result artifact **13876851723**, outer ZIP SHA-256 `176f110f9e1a0b7932380ca94a0c530a0430be6ec418d5385fa23bc5d4dab594`; **1,892/1,892** recursive SHA256SUMS records passed.
- [Census 43067399163](https://github.com/akashskypatel/Directional/actions/runs/43067399163), event `36bac4e43c0f58a69f83484301110b65142b0527`; result artifact **13877545718**, outer ZIP SHA-256 `26c436c1de39d0e64cfb705b44de834fa7250237dd4ec211c1221bd4da1ab88e`; **9/9** checksums passed.
- TB104 reference: [gate 43054464177](https://github.com/akashskypatel/Directional/actions/runs/43054464177) artifact **13870434562** (ZIP SHA-256 `674c06fa8f7277ed22cda5c5b189be39f078adaa6ce85e229778194b9e52d8a7`); [census 43054723909](https://github.com/akashskypatel/Directional/actions/runs/43054723909) artifact **13869789726** (ZIP SHA-256 `1de0e3838c738e26c07233209a0b2a0936c2123232bc71600db26c8b80c2d09f`).
- Source-inspection snapshot event `643baeb5473f0b74d168c9e651efa2fad3eef56c`, [run 43066444219](https://github.com/akashskypatel/Directional/actions/runs/43066444219), artifact **13876795576**, ZIP SHA-256 `c32bbddbfef0867947775d9717866004bbf8df4016b18dcfe2a4a6dd47b68a1d`; 5,474 source file checksums previously verified. The snapshot is not compiled-source authority.

## Assessment

| Evidence | TB105 | TB104 comparison |
|---|---|---|
| Full gate | 942 planned/executed/PASS; zero RED, abnormal, missing, skipped, duplicate, control error, unexpected pass, or later-positive-red | 942/942 case records identical on all 12 substantive ledger columns |
| Membership | 1,023 | Same membership and manifest |
| Full-gate receipts | 25 | All 25 byte-identical: 7 platform digests, 7 A3 coverage, 4 D4 rim, 4 D4 corner, 2 field-corner, 1 derived-corner receipt |
| Production census | 3 executed: 1 PASS / 2 registered RED / 0 abnormal | Three case records identical on all 12 substantive columns |
| Census receipts | 6 | All 6 byte-identical: 3 platform digests and 3 A3 coverage lines |
| Execution boundary | Exit 0, postflight true; configure/compile/relink/benchmark false in both artifacts | Matching frozen execution contract |

The three census case records were verified against TB104 independently of the workflow's success signal. Their log bodies have the same semantic diagnostics. Differences are only process durations and process addresses. Cylinder remains a valid direct output. BunnyRandom remains RED with `SingularityPortClassCountMismatch`; Vase remains RED with `AggregateCompletionValidationFailure`. Both first failing assertions remain `SurfaceCellDesignAcceptanceTests.cpp:273`. The census does **not** justify changing their existing owner or accepting them.

**Regression disposition:** No accepted-green loss, no newly identified production regression, and no new stable event, category or recurrence. The accepted CP2 total remains **491/491**. Stable regression totals remain **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**. O34, O35, O36, O37, D6 and O39 remain open. O36 production switches remain unwired. CP3/selector497 remains unpromoted.

## Recommendation

Close this test turn as **COMPLETE / scoped MATCH**. The sole authorized next turn is **`M6-CP3-DEFN-P13-A3-EXACT-RIM-ARITHMETIC`**, an independent Review definition for O39. **Do not start that Review in this TB105 turn.** Preserve the immutable test and census evidence; do not change source, tests, selector or compiled package.
