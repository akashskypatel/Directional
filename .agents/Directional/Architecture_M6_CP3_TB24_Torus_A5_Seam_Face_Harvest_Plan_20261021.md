# TB24 — torus A5 seam-face diagnostic harvest (2026-10-21)

**Canonical turn:** `M6-CP3-TB24-RP01-TORUS-A5-SEAM-FACE-HARVEST`. **Type:** artifact-only Test + Benchmark; **authority:** RA-122 independent CB23 review and RA-121.6. **Semantic source:** `e859175333f879273a75e3bfc321600e451048aa`; compile run `39623185718`, artifact `12355892070`, ZIP SHA-256 `5215e5c216cde5cd45d851d36c9aa9b2a62de496aa78db2aac54d828996af91f`, source tar SHA-256 `b570e9815e8f6b438f3356970f79b80557f4e07941e5501517eb941644222281`.

## Fixed test matrix — exactly nine identities

| Row | TB23 reference | Exact gtest identity | Predicted |
|---|---|---|---|
| 1 | `focused30:20` | `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` | A5 RED (W/P) |
| 2 | `selector:444` | `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate` | A5 RED (T/P) |
| 3 | `focused30:28` | `M6CP1.A6BoundaryCandidateExtractionHasIndependentEligibilityOracle` | A5 RED (T/D; G4-B002) |
| 4 | `selector:447` | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` | PASS atlas guard |
| 5 | `cp3entry:6` | `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` | PASS |
| 6 | `selector:217` | `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions` | PASS |
| 7 | `TB18 A#14` | `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorVertexEndpointRejectsForgedTags` | PASS |
| 8 | `selector:443` | `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges` | PASS |
| 9 | `focused30:7` | `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority` | PASS |

## Execution contract

- Use the durable `test_benchmark` dispatcher with an artifact-only harness under `.agents/Directional/tools/`. Freeze and hash the exact harness before dispatch. Use **only** the packaged CB23 binary, existing source tar and immutable fixtures, with original permissions, no relink, local compile, new source/test/fixture/selector changes, or benchmarking; package status must remain clean. Maintain Code + Build and Test + Benchmark boundaries.
- Verify original artifact provider SHA-256, all 28 root `SHA256SUMS` entries, source tar/source SHA, `runtimeExecution=false`, GMP/GMPXX and the frozen accepted selector bytes. Stage `torus.obj` and `torus.rawfield` in the executable's actual lookup layout as in the reviewed TB23 harness. `GTEST_FAIL_IF_NO_TEST_SELECTED=1`; isolate one direct process and raw log per identity, require exactly one `[ RUN ]` and no skip, enforce per-process timeout, hash raw logs, full result and postflight package/source/execution-view immutability.
- Collect each A5 failure's **complete** `site` string (do not truncate), `sel`, `support`, `wedge`, ordered `certN` and `spanOnlyN` values, exit status and first failure. Record separate `site` strings if a process emits multiple; do not silently choose one. Preserve the TB23 site prefix through `certN` for exact comparison and compare all three new suffixes byte for byte across A5 rows. A literal `none`, missing field or missing span-only certificate is a measured outcome, not a fabricated binding.
- Require 9/9 selected/executed, predicted **3 RED + 6 PASS**, zero skips, guard and controls free of A5 isolation site, per-row raw hashes and package manifest checks. Retain all unexpected results without changing assertions to obtain green. Produce one immutable result artifact, signed/hashed ledger, failure snippets, full raw logs and report.

## Falsifiers and routing — registered before execution

1. **P1:** All three A5 rows fail with the TB23 byte-identical site prefix `relation-collinear-seam;region=0;seam=60,61;relation=0:1,1:0;first=120/0;second=97/2;certs=1;cert0=120/0->97/2:first-face`. Their appended `sel`, `support`, `wedge`, `spanOnly0` fields must be present, in order, and byte-identical across the three. A mismatch, absent field, altered prefix, missing A5 failure, multiple incompatible sites, or a changed first failure **falsifies P1**; stop design selection and send evidence to independent TB24-REV.
2. **P2:** Guard `selector:447` and all five controls PASS, with no A5 site. Any RED, unselected, skipped or site-bearing control **falsifies P2**; distinguish fixture/harness behavior before attributing A5.
3. **Pre-registered isolation branches (TB24-REV only):** first `sel=97/2` with corresponding `support=edge` suggests **B-across**; first `sel` from `(96, 99, 122, 123)/0` at vertex 60 or `(118, 119, 121, 142)/0` at vertex 61 with `support=vertex` suggests **B-fan**. Any other combination remains **unclassified**. For every `spanOnlyN`, a value other than `forward` or `reverse` means dropping face equality alone is insufficient: DEFN-ISO must own the additional rejecting clause. No inferred repair or relaxation is authorized in TB24.
4. **Stop conditions:** any archive, harness/source SHA, selector, execution count or immutability mismatch; missing fixture staging; unexpected dependency; previously green guard/control regression. Stop, preserve evidence and request Review rather than modifying the packaged binaries, changing test criteria or dispatching a repair within TB24.

## Deliverables and boundary

A reviewable `Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Report_20261021.md`, exact nine-row ledger, raw immutable logs and checksums, updated candidate tracker/TODO/handoff/CHANGELOG and authorized **independent TB24 Review only** (its canonical ID remains `UNKNOWN` until Review or existing authority explicitly assigns it). No stable count/selector/CP3 promotion in TB24; **66/17/49**, debt 1, accepted CP2 491/491, rejected R3 403/497, candidate TB21 449/497 remain unchanged unless independently justified.
