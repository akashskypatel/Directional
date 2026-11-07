# TB25 — immutable seam frame values harvest (frozen by RA-125, 2026-10-21)

**Exact successor:** `M6-CP3-TB25-RP01-SEAM-FRAME-VALUES-HARVEST`. **Type:** artifact-only Test + Benchmark; no rebuild, source/test/selector mutation, benchmark, or local Directional runtime setup. **Authority:** RA-124.6 and RA-125. **Semantic source:** `dae267a82fb884ff9eba4fd0122ad61750d0c924`. **Package:** `12378590512` from run `39667030493`, ZIP SHA-256 `bbaaa3853e4a0d3cef13d327fefa10676ab0d10108213964772215ec79d630b4`, source tar SHA-256 `21b47d49d6059f946c4112231691fdd0972625552a4bb2fcd5251568c8e9dba0`; GMP/GMPXX and `runtimeExecution=false`.

## Fixed matrix — exactly 11 identities, one fresh process each

| Row | Selector/fixture | Exact gtest name | Expected diagnostic class |
|---|---|---|---|
| 1 | `focused30:20` | `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` | A5 W/P RED; full site |
| 2 | `selector:444` | `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate` | A5 T/P RED; full site |
| 3 | `focused30:28` | `M6CP1.A6BoundaryCandidateExtractionHasIndependentEligibilityOracle` | A5 T/D RED; full site |
| 4 | `cp3entry:3` | `M6CP3.OrdinaryFrontIsolationSeamUsesCoordinateIdentityAndCertifiedSheetTransition` | D3 witness, full assertion and candidate sites |
| 5 | `cp3entry:5` | `M6CP3.ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition` | D3 witness, full assertion and candidate sites |
| 6 | `selector:447` | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` | PASS atlas guard |
| 7 | `cp3entry:6` | `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` | PASS control |
| 8 | `selector:217` | `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions` | PASS control |
| 9 | TB18 A#14 | `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorVertexEndpointRejectsForgedTags` | PASS control |
| 10 | `selector:443` | `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges` | PASS control |
| 11 | `focused30:7` | `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority` | PASS control |

Rows 1–3 and 6–11 use the same test/binary mapping as the reviewed TB24 plan; rows 4–5 belong to `directional_surface_cell_producer_tests`. Preserve both torus fixture families and stage `torus.obj` and `torus.rawfield` at the established executable lookup path. No prediction of PASS/RED for the two contested D3 rows may be manufactured from this compile-only review.

## Execution, falsifiers, routing

1. Before dispatch, freeze the exact source SHA and immutable harness path/hash. Use only the existing reusable `test_benchmark` dispatcher; verify provider ZIP digest, 28/28 manifest, source/selector checksums, unchanged file modes and package postflight. Each identity must select exactly once with `GTEST_FAIL_IF_NO_TEST_SELECTED=1`, one full untruncated raw log, timeout/exit status, no skips, an independently computed SHA-256, and separate result records. No compile, relink, mutation, or benchmark.
2. For every A5 `relation-collinear-seam` site, preserve the full original TB23/TB24 prefix plus ordered `branch`, `gaugeSel`, `gaugeSpan`, `turnN`, `certN`, and `spanOnlyN` suffixes. Extract every emitted site rather than choosing one. `none`, no site, missing certificate, wrong site order, or different site bytes are measured outcomes. The three A5 rows must reach the expected branch and six guard/controls must PASS; any discrepancy is a falsifier, not permission to relax a test.
3. Independently classify producer signature by `branch-gaugeSel` modulo 4 for both occurrences: both 0 = uniform; both equal same nonzero c = curved; both branch values 0 with nonzero gauge = annulus. If none fits, mark UNCLASSIFIED; do not assign a producer by conjecture. Confirm A6 stripped turn (P3) identity or flag a counterexample.
4. Gauge routing: in the certificate's canonical orientation, calculate `d=(gaugeSpan(second)-gaugeSpan(first)) mod 4`, `F=turn0.forward`: `F=0` means D3 is satisfiable and family (i) reduces to A5 side authority; `F!=0 && d==F` makes family (i) admissible and requires D3 definition review; `d!=F` assigns the defect to the producer gauge table. Never infer an outcome when values are absent/unparseable; send UNRESOLVED to TB25-REV.
5. For `cp3entry:3/5`, retain every attempted candidate's full assertion messages and earliest rejection. If any candidate shows `relation-collinear-seam`, the witness joins the seam family; otherwise it remains fixture debt at its observed stage. Preserve all raw data even on unexpected PASS.
6. **Stop:** any artifact/hash/source mismatch, wrong test count/identity, lost assertion or field, fixture staging failure, source mutation, relink, skipped control, or broken immutability. Record orchestration failure separately from semantic RED. Emit one retained immutable result artifact with raw logs, ledger, hashes, and postflight. Next is mandatory independent TB25 Review, canonical ID `UNKNOWN` until authorized there. **No CP3, stable-regression, selector or D3 promotion during TB25.**

Stable accounting remains 66/17/49, debt 1; accepted CP2 491/491, R3 403/497 rejected and TB21 449/497 unpromoted; CP3 selector 497 frozen. DEFN-SEAM, DEFN-M1 and DEFN-T1 are not authorized to execute during TB25.
