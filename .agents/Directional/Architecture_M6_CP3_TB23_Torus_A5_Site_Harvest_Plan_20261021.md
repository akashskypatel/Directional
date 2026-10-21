# TB23 — Torus A5 isolation-site harvest plan (RA-120)

**Turn:** `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST`, Test + Benchmark, artifact-only. **Owner:** TB23; issued by CB22B-REV (RA-120). **Source:** `c6e90916eb90bfd33bc8a38c5ece7def15dcc766`; **package:** artifact `12341307713`, ZIP SHA-256 `b5f9a6688226375ea1c6241c2d9a464d9b9ede7679f9259acd03b3fbbb1c8ad5`, root `SHA256SUMS` `7c396be65a3138eca15ad4c7a37db192d6828b80442a656d38f84d1887767f11`, source archive `c3779cc949a97fd8b6ce73e62fc8cc62598c637e362bb57cc5f5ecb52cd0cd75`, expires `2026-10-28T11:21:37Z`. Verify 28/28 before execution and unchanged bytes after. CB22B was `runtimeExecution=false`; TB23 alone executes.

**Harness:** new `.agents/Directional/tools/m6_cp3_tb23_torus_a5_site_harvest_harness.sh`, derived from the TB22 harness. Change only the package/source identities, the rows and the added columns below. Same discipline: `directional_surface_cell_producer_tests`; one process per row; `GTEST_FAIL_IF_NO_TEST_SELECTED=1`; exactly one selected test per row; zero skips. No rebuild, relink, benchmarks, test, fixture or selector edit, broader census or retry.

## Exactly sixteen rows

Fixture **W** = `nonzero_z4_torus_witness_fixture()`; **T** = `torus_fixture()` (`torus.rawfield`). Path **P** = pipeline failure string; **D** = direct A5 message (CB22B).

| Class | Key | Exact test name | Fixture / path |
|---|---|---|---|
| A5-ISO | `focused30:20` | `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` | W / P |
| A5-ISO | `selector:446` | `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` | W / P |
| A5-ISO | `focused30:24` | `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` | W (3rd `verify`) / D |
| A5-ISO | `focused30:25` | `M6CP1.A6ClosedComplexBoundaryIsCombinatoriallyEquivalentOnProducedTorus` | T / P |
| A5-ISO | `focused30:26` | `M6CP1.A6ClosedComplexBoundaryPreservesHardRailAndPeriodicLabels` | T / D |
| A5-ISO | `focused30:27` | `M6CP1.A6ClosedComplexBoundaryPreservesQuotientVertexLineage` | T / D |
| A5-ISO | `focused30:28` | `M6CP1.A6BoundaryCandidateExtractionHasIndependentEligibilityOracle` (G4-B002) | T / D |
| A5-ISO | `selector:444` | `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate` | T / P |
| A5-ISO | `selector:448` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate` | T / P |
| F | `focused30:6` | `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` | W / P |
| F | `selector:447` | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` | W / P |
| control | `cp3entry:6` | `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` | — |
| control | `selector:217` | `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions` | — |
| control | `TB18 A#14` | `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorVertexEndpointRejectsForgedTags` | — |
| control | `selector:443` | `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges` | — |
| control | `focused30:7` | `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority` | — |

## Ledger columns added to TB22's

- `fixture`, `path` (from the table); `a5_failures` (count of failure lines carrying an A5 isolation code);
- `site_raw`: every `site=` occurrence, untruncated, in output order. The value ends at whitespace or at `;terminalStage=`;
- parsed `label` (one of `side-step`, `side-collinear`, `wedge-edge`, `wedge-fan`, `relation-collinear-seam`), `region`, `seam`, `cert` (side sites) or `certs` plus every `certN=…:<clause>` (relation site).

## Predictions (frozen before runtime)

- **P1 site coverage:** every row whose output carries an A5 isolation code (`…IsolationSeamEquivalenceAuthority:a5-side` or `:a5-wedge`; `A5:OccurrenceMismatchedIsolationEvidence` or `A5:OccurrenceMissingIsolationEvidence`) shows `site=` with one of the five labels, and no clause is `valid`. `a5-side` pairs only with `side-step`, `side-collinear` or `relation-collinear-seam`; `a5-wedge` only with `wedge-edge` or `wedge-fan`.
- **P2 within-fixture agreement:** the W rows (`focused30:20`, `selector:446`, `focused30:24`) name one label, region and seam; the T rows (`focused30:25/26/27/28`, `selector:444/448`) name one label, region and seam. A disagreement is reported, not reconciled. W and T may differ.
- **P3 `focused30:24`:** exactly one A5 failure, carrying the W site. Two or more are reported in `verify` order (hard-rail, split-isolation, witness).
- **P4 F rows:** both pass `atlas-binding` (no `InvalidSourceAuthority` at the atlas). Any failure is a later site, expected to be the W site.
- **P5 controls:** all five GREEN, with no `site=` in their output.

## Falsifiers and stops

- An isolation code without `site=`, a `valid` clause, or a label that contradicts its `a5-side`/`a5-wedge` suffix: instrumentation or classifier gap. Review stop, not a result.
- Any control RED: Review stop.
- Package or source mismatch, `selected≠1`, a skip, a timeout or a runtime-flag mismatch: non-acceptance, classified exactly.

## Routing for TB23-REV (pre-registered, not a verdict)

- `relation-collinear-seam` with `region`, `collinear`, `first-face`, `second-face` or `same-sheet`: A4 certificate disagrees with A5 occurrence authority (H-ISO-2).
- `relation-collinear-seam` with `first-side`, `second-side`, `same-side` or `ambiguous`: the RP reject is a candidate for over-strictness on a legitimate periodic pairing (H-ISO-1).
- `side-step`, `side-collinear`, `wedge-edge` or `wedge-fan`: side-span or wedge crossing (H-ISO-3); `cert=none` against a present certificate separates a missing certificate from a disagreeing one.

## Deliverable

`Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Report_20261021.md`, at most 40 lines: run, result artifact and ZIP SHA-256, harness SHA-256, integrity counts; one line per row (key, fixture, path, verdict, label, region, seam, cert or clauses); P1–P5 marked as observed. No root-cause verdict; that belongs to TB23-REV. **After TB23:** mandatory `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST-REV`; DEFN-ISO only as that Review assigns it.
