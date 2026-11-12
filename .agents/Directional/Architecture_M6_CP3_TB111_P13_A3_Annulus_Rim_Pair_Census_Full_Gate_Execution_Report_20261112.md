# TB111 — annulus rim-pair census full-gate execution (2026-11-12 UTC)

## Situation

**COMPLETE / scoped MATCH.** The immutable CB130 package passed the **944/944** full gate with **1,025** memberships. Its unchanged three-case production census returned Cylinder PASS and BunnyRandom/Vase registered RED. Row 729 proved **16/16 paired annulus strips**, so RA-229 §5 authorizes CB129 as the **next separate Code + Build turn**. This test result does not promote CP3 or selector497.

## Background

- Canonical turn: `M6-CP3-TB111-P13-A3-ANNULUS-RIM-PAIR-CENSUS-FULL-GATE-EXEC` (64D.10); artifact-only test and observation. No source, test, fixture, selector, harness, compile, relink, configure or benchmark change.
- Frozen CB130 source: `d9dde92f938fab7688644fe2e420214bcefa93cb`. [Compile run 43163829447](https://github.com/akashskypatel/Directional/actions/runs/43163829447), package artifact `13918449673`. Package ZIP SHA-256 `a2e42a855cd0469a137465fb631fa74c98c3d522eec24b9ad1a41a89db15679c`; 28/28 package hashes and eight GMP/GMPXX compile targets valid; package compile `runtimeExecution=false`.
- TB111 manifest `.agents/Directional/gates/Architecture_M6_TB111_P13_A3_Annulus_Rim_Pair_Census_Full_Gate_Case_Manifest.tsv` SHA-256 `46e5c8a8ffb1a8d6337d782bef44fa852d3b17870e2f06ab037d55a8ea201f61`, identical to TB109 (944 rows, 1,025 members, deferred 81).
- [Full-gate run 43166348659](https://github.com/akashskypatel/Directional/actions/runs/43166348659), artifact `13919949883`, ZIP SHA-256 `b60e44da3b1d8858d39b9e5bb23c5bf7808c62d653d24a5cd5d7d52173cb9f7f`; 1,896/1,896 internal hashes verified.
- [Production census 43166395557](https://github.com/akashskypatel/Directional/actions/runs/43166395557), artifact `13920309303`, ZIP SHA-256 `be0f9c1e20464b7f56a482141c7c782124c936dd773b2b12e69808f1e5984465`; 9/9 internal hashes verified.
- Independent baseline: TB109 gate `13916127330` / census `13915439007`. Both raw ZIP archives and internal hashes verified before comparison.

## Assessment

| Check | Observed result |
|---|---|
| Full gate | 944 planned, 944 executed, **944 PASS**, 0 RED/skipped/missing/abnormal/duplicates/control failures |
| Gate membership | 1,025 |
| Inherited receipts | **41/41 unchanged, byte for byte**; including row 729 `annulus-read` |
| Substantive ledger | All 944 gate records match TB109, excluding run-specific digests |
| Census | Cylinder PASS; BunnyRandom and Vase registered RED; 3 substantive records and inherited receipts unchanged |
| Execution boundary | Both runs exit 0, postflight true, `compile=false`, `relink=false`, `configure=false`, `benchmark=false` |

Verbatim new row-729 pairing receipt:

```text
annulus-pair case=CommittedCylinder strips=16 paired=16 rimSources=16/16 planRims=32/32
```

Verbatim unchanged row-729 reader receipt:

```text
annulus-read case=CommittedCylinder rimEdges=32 readable=32 equalOutput=24 outputRimEdges=56 recorded=0
```

The two count rules still disagree on 8 of the 32 rim edges, but each column's paired rim edges receive equal planned counts. The two rim totals are 32/32. This meets RA-229 §5 without adding a pairing rule to A3. It does not establish that the annulus now consumes the plan; CB129 must implement that consumer in its separate Code + Build turn, then TB110 must test it.

**Regression accounting:** The two non-gating production RED cases have the same verdict, case membership, and substantive ledger as TB109. No new accepted-green loss, stable regression event, category, recurrence, or candidate is justified. Accepted CP2 remains **491/491**; stable **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**. O36 remains unwired. PR #8 remains draft/open/unmerged.

## Recommendation

Close TB111 as **COMPLETE / scoped MATCH**. Exact authorized successor: `M6-CP3-CB129-P13-A3-ANNULUS-RIM-CONSUMPTION` (64D.6). Apply only the frozen CB129 change on top of CB130 in that next turn, with the re-registered TB110 acceptance rules in RA-229 §5. Do not run CB129 or TB110 in this turn. No A3 pairing constraint, O36 wiring, CP3/selector497 promotion, or production acceptance is authorized here.
