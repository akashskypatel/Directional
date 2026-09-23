# M5-CP3-CB20 Selector448 Publication Code + Build Plan

**Turn:** `M5-CP3-CB20`
**Owner:** Code + Build
**Boundary:** publication-only selector bytes + compile/package; **no Directional runtime**
**Authority:** `M5-CP3-TB1-R16-REV`, frozen §17
**Exact successor if green:** `M5-CP3-TB2-EXEC`

## 1. Goal

Publish the exact cumulative selector precommitted by R16 Review, compile/package the unchanged M5 implementation under mandatory GMP/GMPXX, and stop. This turn is not authorized to alter product, test, fixture, field, A3, CMake target membership, benchmark semantics or frozen definitions.

The only semantic repository payload authorized by this plan is creation of:

`.agents/Directional/Architecture_M5_CP3_CB20_Required_Green_Selector_448.txt`

with the exact 448 precommitted identities below.

## 2. Immutable selector authority

Start from accepted selector430 `.agents/Directional/Architecture_M4_CP4_CB8_Required_Green_Selector_430.txt` and prove it still hashes to:

`1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`

The new file is exact selector430 bytes followed by these rows, in this order:

| ordinal | exact identity |
|---:|---|
| 431 | `M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges` |
| 432 | `M5CP3.StorageCanonicalPeriodicRelationResolvesSemanticForwardReverse` |
| 433 | `SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator` |
| 434 | `SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained` |
| 435 | `M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap` |
| 436 | `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation` |
| 437 | `M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate` |
| 438 | `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation` |
| 439 | `SurfacePhaseFrontProductFactoryAuthority.ConflictingPeriodicRelationValueRejectsAtCheckedFactory` |
| 440 | `SurfacePhaseFrontProductFactoryAuthority.NonReciprocalPeriodicRelationRejectsAtCheckedFactory` |
| 441 | `SurfacePhaseFrontProductFactoryAuthority.RepresentationRenumberedPeriodicRelationRejectsAtCheckedFactory` |
| 442 | `FieldTransportAtlas.RetainsDirectedTransitionValueForHardFeatureWithoutTraversalAdjacency` |
| 443 | `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges` |
| 444 | `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate` |
| 445 | `M5CP3.ProducedTorusMissingPeriodicRelationOwnerRejectsTyped` |
| 446 | `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` |
| 447 | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` |
| 448 | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate` |

Expected publication invariants:

- **448 rows / 448 unique**;
- **36,382 bytes / 448 LF / terminal LF**;
- full SHA-256 **`70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`**;
- first 430 rows byte-identical to selector430: **35,001 bytes**, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- no appended identity already present in selector430 and no duplicate among rows431-448;
- exact owner census **32 authority-kernel / 300 producer / 75 completion / 41 validation**.

Do not regenerate order from CTest discovery, globbing, lexical sort or ownership grouping. CMake/source inspection is used only to verify owner membership/census, never to author ordering.

## 3. Compile/package boundary

After publishing exactly those bytes, run the durable compile workflow against the exact source commit with mandatory `DIRECTIONAL_ENABLE_GMP=ON` / GMP/GMPXX linkage. Compile and link exactly the standard eight targets:

```text
directional_core
directional_pipeline
directional_surface_cell_authority_kernel_tests
directional_surface_cell_producer_tests
directional_surface_cell_completion_tests
directional_surface_cell_validation_tests
directional_compiled_api_tests
directional_benchmarks
```

The package must include the exact published selector448 and unchanged product/test sources. Preserve root-manifest/source-archive/source-status evidence and prove `runtimeExecution=false`. Do not execute any Directional binary, test, benchmark, discovery/list/help command or custom runtime input.

## 4. Falsifiers

CB20 is RED and stops if any of the following occurs:

1. selector430 no longer has 430 unique LF-terminated rows at the frozen hash;
2. selector448 differs by one byte, identity or order from the R16 precommit;
3. the first430 prefix differs from selector430;
4. any appended identity duplicates a prefix/appended row;
5. owner census differs from 32/300/75/41 or any identity lacks exactly one approved owner target;
6. any product/test/fixture/field/A3/CMake/benchmark/frozen-definition semantic file changes;
7. mandatory GMP/GMPXX is not enabled/resolved;
8. any of the eight standard targets fails compile/link;
9. package/root manifest/source receipts are incomplete or fail verification;
10. any Directional runtime/benchmark/test/discovery command executes.

There is no alternate selector, partial publication or on-the-fly identity repair.

## 5. Success criteria

CB20 completes only when exact selector448 is published at the frozen path/hash/prefix/census, all eight mandatory GMP/GMPXX targets compile/link, package evidence is self-consistent and source-clean, and `runtimeExecution=false`.

Compile green grants **no runtime credit and does not close M5**. Exact successor is `M5-CP3-TB2-EXEC`, which must consume the CB20 package immutably and execute exactly the published selector448 as **448 fresh exact-filter processes**, exact-one/zero-skip, benchmark 0, followed by mandatory `M5-CP3-TB2-REV`. No R16 process credit may be stitched into TB2.

## 6. Reviewing-agent amendment (R16-REV addendum) — clarifications, no authority change

These items leave selector bytes, order, hash, prefix and census exactly as §2 states. They clarify how to check the falsifiers and add one receipt TB2 needs.

1. **Falsifier 5 counts owners over the four standard owner executables only:** `directional_surface_cell_{authority_kernel,producer,completion,validation}_tests`. Seven accepted selector430 prefix identities are also defined in sources compiled only into the optional `directional_surface_cell_historical_tests` target (`DIRECTIONAL_BUILD_HISTORICAL_TESTS`). Ordinals 41-46 (`MilestoneGP26.*`) are owned by `tests/SourceGridRecoveryAuthorityTests.cpp` (producer) and duplicated in `tests/MilestoneGP26Tests.cpp`. Ordinal 113 (`SurfaceArrangementPhase16.FaceInteriorSupportAndChartIdentityAreRowIndependentAndDiscriminating`) is owned by `tests/SurfaceArrangementRowIdentityTests.cpp` (completion) and duplicated in `tests/SurfaceArrangementPhase16Tests.cpp`. Each of the seven has exactly one standard owner. These duplicates predate M5 and are **not** a falsifier-5 event. Any other identity with zero or more than one standard-owner definition **is** one. The reviewing agent statically re-derived the census from `cmake/DirectionalTests.cmake` target membership at `a8b33cb7`: **32 / 300 / 75 / 41**. Rows 431-448 are 17 producer + 1 authority-kernel (`FieldTransportAtlas...` at 442).
2. **Record the static routing receipt.** Record the exact 448-row `ordinal / identity / owner-executable` map used for falsifier 5 in the CB20 report, with its SHA-256. The existing routing identity-map (`7a92e7a3...cf6c`, artifact `10592987234`) covers rows 1-430 only. The reviewing agent checked its static map against R16's runtime routing: the owner binaries in R16 `selector-ledger.tsv` (rows 1-430) and `nonselector-ledger.tsv` (rows 431-448) agree **row for row on all 448 rows**. A CB20 map that disagrees on any row is therefore a falsifier-5 event. `M5-CP3-TB2-EXEC` routes from this receipt. It must not rediscover owners at runtime.
3. **Index the published file in `Required_Green_Selector_Manifest.md`** with status **PUBLISHED / NOT YET ACCEPTED**, following the `M4-CP4-CB8` precedent (`aa6cab17`, `8876e084`). The manifest is a derived index, not a semantic file, so this does not trigger falsifier 6. Acceptance and promotion wording belong to `M5-CP3-TB2-REV`.
4. **Do not add, gate, edit or delete** the two compiled but never-executed identities `M5CP3.PeriodicRelationEndpointGaugeIsIndependentAndExact` and `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` (`M5-CP3-TB1-R16-REV-OBS-01`). Their disposition belongs to `M5-CP3-TB2-REV`. Touching them in CB20 is a falsifier-2/6 event.
