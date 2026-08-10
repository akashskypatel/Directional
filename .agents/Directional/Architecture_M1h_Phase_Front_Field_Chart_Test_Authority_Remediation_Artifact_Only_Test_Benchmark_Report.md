# M1h Phase-Front Field-Chart Test-Authority Remediation — Artifact-Only Test + Benchmark Report

**Status:** ACCEPTED  
**Turn type:** Test + Benchmark only  
**Remediation implementation under test:** `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0`  
**Production implementation:** `de4e2ba7c19d2e49931655dc22d758f50656d054`  
**Product behavior delta:** none observed or accepted  
**Review policy:** `never`  
**Date:** 2026-08-10 UTC

## 1. Result

M1h is **immutable accepted** at the bounded seam:

`build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart`.

The prior blocked runtime was a test-authority defect, not a product regression. The corrected `MultipleOrientationChartsPreserveEstablishedNumbering` witness now proves producer chart-domain authority and constructive-front occurrence authority separately. The exact producer chart domain remains `{0,1,2}`; no test or production behavior was weakened to reinterpret it as `{0,2}`.

The accepted remediation package passes all required M1h semantic, preservation, representative-product, known-red, heavy-case, and immutability gates. M1a through M1h are therefore immutable accepted. Product gate G4 remains active and separate.

## 2. Immutable package authority

| Evidence | Value |
|---|---|
| remediation implementation | `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0` |
| base M1h production implementation | `de4e2ba7c19d2e49931655dc22d758f50656d054` |
| build run/job | `31404102605 / 93506073062` |
| result artifact / SHA-256 | `9069186973` / `d2b334f278f0281c5b3a5a5a6b33ba8bf085b7cf374376beb437e559646d9df8` |
| log artifact / SHA-256 | `9069187317` / `56c0d0fb012b5d3b5fa4bb7284a496d700a4ebf408806b53c27f21f00311679a` |
| recursive manifest | **72/72**, `4b8839695369a114567a38fbcddc4dde7d1cea8b024940cb2071a256d9d594d8` |
| package | **73** regular files; 7 executables; 2 static libraries; 27 fixtures |
| producer executable | `937adceea641f372ee42eeb9a3b91c3bba2088847755cc234eaf0b3754f208ac` |
| build boundary | Release/static/Ninja/PRE_TEST; production-source delta false; every runtime flag false |

Preflight independently matched both outer artifact digests, rejected unsafe archive members, verified `SHA256SUMS` and every **72/72** content checksum, confirmed package cardinalities, checked build-authority metadata, and verified the exact packaged source/test blobs. No package repair or substitution occurred.

The accepted M1h production blobs remain:

- `include/directional/geometry/SurfaceCellTracing.h`: `102b2bbd3f57ec6b994cbe99b39c6d283eb0bf66`;
- `src/geometry/SurfaceCellTracing.cpp`: `0a8d85c20893ef65f2a2ba572096f2f38e2f652e`;
- `src/pipeline/RemeshPipeline.cpp`: `db87264809b35e325ad6c8f44fabef6ddca3883a`;
- `tests/TestFixturePaths.h`: `4a981f772ee70780d0011696010a0e1b8bef6972`.

The remediated `tests/SurfaceCellsPhase10Tests.cpp` blob is `71b991896846a486f29a550ddde4260748b03cd7`.

No runtime fixture symlink was created. Packaged binaries resolved the sibling `../test-data` layout directly.

## 3. Native discovery authority

Package-native GoogleTest discovery produced exactly:

| Target | Tests |
|---|---:|
| producer | **202** |
| validation | **77** |
| M1a authority kernel | **14** |
| T1 independent oracle | **29** |

Unexpected or zero-selection discovery was rejected throughout.

## 4. M1h focused semantic acceptance

Each `SurfaceCellPhaseFrontFieldChartAuthorityMigration` contract ran individually in a fresh process and selected exactly one test. Result: **6/6**.

1. `PlanarMultiFaceFrontPublishesCheckedSingleChart` — pass.
2. `MultipleOrientationChartsPreserveEstablishedNumbering` — pass.
3. `NumericCoincidenceCannotCrossAuthorityDomains` — pass.
4. `MissingOrInvalidChartAuthorityCannotMasqueradeAsValid` — pass.
5. `FaceRowPermutationPreservesTypedPlanarChartAuthority` — pass.
6. `PeriodicAndBoundedDiskSingleChartPathsUseCheckedChartZero` — pass.

The repaired multi-orientation witness retains hard-authored producer numbering `face 3 -> chart 1`, `face 10 -> chart 2`, default chart `0`, and exact producer compatibility domain `{0,1,2}`. Every actual lattice occurrence separately proves that its typed `FieldChartId` matches the producer chart of its paired source face. Actual occurrence coverage is not treated as a surrogate for producer-domain coverage.

## 5. Entering M1 preservation

All earlier focused architecture suites ran individually in fresh processes and remained green:

| Slice | Result |
|---|---:|
| M1g periodic holonomy route transport | **6/6** |
| M1f vertex continuation route transport | **6/6** |
| M1e segment route transport | **6/6** |
| M1d phase-front route identity | **6/6** |
| M1c field-transition consumer | **6/6** |
| M1b source/provenance consumer | **6/6** |

The three accepted M1d route counterexamples remained **3/3** green:

- `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`;
- `SurfaceCellTransitionQuotient.ArtificialInteriorBoundaryIsRejected`;
- `SurfaceCellTransitionQuotient.ComponentBoundaryAndEulerFactsAreComputedFromIncidence`.

The three accepted M1c transition counterexamples remained **3/3** green:

- `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed`;
- `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`.

Aggregate independent preservation also passed:

- validation: **77/77**;
- M1a authority kernel: **14/14**;
- T1 independent product oracle: **29/29**.

## 6. Complete required-green producer segment

Producer discovery is exactly **202**. The required-green segment excludes exactly 15 separately classified tests: four direct representative products, eight historical/deferred reds, strict-validator timing, BunnyRandom, and Vase.

The resulting aggregate selected exactly **187** tests and passed **187/187**, rc=0, in **20.33 s** with **23,116 KiB** peak RSS.

This aggregate includes all six M1h contracts, so the corrected witness is green both individually and in complete required-green accounting.

## 7. Direct representative product preservation

Each required product ran individually from the exact package and remained independent-oracle clean without any fixture symlink:

| Case | Result | Wall time | Peak RSS |
|---|---|---:|---:|
| Plane | pass | **1.21 s** | **11,256 KiB** |
| MultiFaceSeam | pass | **1.95 s** | **10,964 KiB** |
| CloseSheets | pass | **16.21 s** | **13,524 KiB** |
| Cylinder | pass | **8.71 s** | **15,076 KiB** |

The M1g-discovered package-layout defect is therefore closed: sibling `../test-data` is sufficient from arbitrary extraction, and the historical runtime-only `bin/test-data` symlink is no longer needed.

## 8. Historical/deferred red classification

All eight entering historical/deferred producer reds ran individually and retained their prior failure classes:

1. `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` — existing assertion red.
2. `SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize` — `PeriodicHolonomyMismatch`.
3. `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected` — `PeriodicHolonomyMismatch`.
4. `SurfaceCellTransitionQuotient.MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner` — `InvalidHardRailPairing`.
5. `SurfaceCellTransitionQuotient.SwappedPeriodicRelationOwnersAreRejected` — `InvalidHardRailPairing`.
6. `SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected` — `InvalidHardRailPairing`.
7. `SurfaceCellTransitionQuotient.QuotientLineageRetainsScalarPointAndCompleteSortedAuthority` — existing assertion red.
8. `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` — unchanged `NotProductionReady:tracing ... InvalidHardRailPairing`.

Nonzero periodic whole-cycle rotation therefore remains `PeriodicHolonomyMismatch`; `G4-B003` is unresolved. Persistence of these known reds is not a new M1h regression or recurrence.

## 9. Strict-validator timing characterization

`SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` ran in **10 fresh processes** with no retry-based greening. Result: **0/10 pass, 10/10 fail**.

Observed validation/remesh-threshold pairs were:

1. `0.000155801 / 0.0001273751`;
2. `0.000153054 / 0.00010931235`;
3. `0.000176340 / 0.0001132182`;
4. `0.000154708 / 0.00010847365`;
5. `0.000152702 / 0.0001091854`;
6. `0.000148884 / 0.0001026992`;
7. `0.000152531 / 0.0001284394`;
8. `0.000152281 / 0.0001116911`;
9. `0.000151508 / 0.0001140517`;
10. `0.000376248 / 0.00010475485` seconds.

This remains the previously deferred sub-millisecond ratio/microbenchmark defect. No threshold, retry, or product rule was changed.

## 10. Bunny/Vase bounded immutable comparison

Heavy comparison used temporary artifact-only GitHub Actions run `31407263138`. Each job downloaded result artifact `9069186973`, verified its exact outer digest, all **72/72** package checksums, cardinalities, implementation/build authority, production/test blobs, and producer hash before runtime. Neither job configured, built, relinked, regenerated, patched source/tests/fixtures, substituted content, or created a fixture symlink. Both jobs repeated exact postflight verification afterward.

### BunnyRandom

Job `93516513645` selected exactly one BunnyRandom test and returned **rc=1** after GoogleTest **75.295 s** / wrapper **75.30 s**, peak RSS **340,980 KiB**.

The accepted known-red ordering and signature are unchanged:

1. independent oracle rejects first with `EmptyOutput`, `NonQuadOutput`, connected-component mismatch, Euler-characteristic mismatch, output-origin mismatch, and `TerminalFailureObserved:NotProductionReady:completion`;
2. the product-success assertion then reports `terminal=NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.

Evidence artifacts:

- runtime evidence `9070146263`, SHA-256 `81034c9138942abe1b85d2872dc446639e5181f144ce0b61a8386da22239da9c`;
- diagnostic log `9070146878`, SHA-256 `a1ec25501d62cbcc8b8455c5733ec5de43174d3bb3008f9e0206c5b309c0c5f2`.

### Vase

Job `93516513564` selected exactly one Vase test, reached `[ RUN ]`, and was bounded at **60.00 s** with **rc=124**, peak RSS **69,916 KiB**.

This is safety-only evidence. It is not correctness evidence and is not proof of nontermination.

Evidence artifacts:

- runtime evidence `9070135665`, SHA-256 `8db7da4b518dd0b8cf1e37d503201c0dd2e075a81452595c4385648fdc8239ae`;
- diagnostic log `9070135953`, SHA-256 `11fadca2b277860aebee5a39724bcafe4fb7f1bf7be8bbcbe722d7573fba3929`.

The temporary heavy runtime workflow was removed before its trigger marker. Workflow success represents orchestration success only; product dispositions come from the retained GoogleTest evidence above.

## 11. Postflight immutability

Local postflight and both remote heavy jobs independently reverified:

- result ZIP SHA-256 `d2b334f278f0281c5b3a5a5a6b33ba8bf085b7cf374376beb437e559646d9df8`;
- log ZIP SHA-256 `56c0d0fb012b5d3b5fa4bb7284a496d700a4ebf408806b53c27f21f00311679a`;
- `SHA256SUMS` digest `4b8839695369a114567a38fbcddc4dde7d1cea8b024940cb2071a256d9d594d8`;
- every **72/72** package checksum;
- exactly 73 regular files, seven executables, two libraries, and 27 fixtures;
- producer SHA-256 `937adceea641f372ee42eeb9a3b91c3bba2088847755cc234eaf0b3754f208ac`;
- `fixtureSymlink=false` throughout.

No immutable package content was changed during runtime validation.

## 12. Architecture and regression disposition

M1h is **immutable accepted** as the phase-front field-chart authority consumer migration.

- `RP-01`: `FieldChartId` is now checked before persistent constructive-front semantic use — **accepted** at this seam.
- `RP-05`: chart identity no longer depends on a bare persistent integer in `LocalLatticeState` — **accepted** at this seam.
- `RP-02 / TA-05`: independent authority is re-proven by exact discovery, required-green **187/187**, preserved M1g–M1b suites, validation **77/77**, M1a **14/14**, T1 **29/29**, direct representative products, explicit known-red classification, and bounded Bunny/Vase comparison.
- The prior focused failure is retained as a test-authority defect and creates no stable product regression event or recurrence.
- Historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains active and unchanged.

M1h does not repair G4 topology completion, nonzero periodic holonomy, Bunny/Vase production success, or the deferred strict-validator timing test.

## 13. Following turn

Fresh accepted-source inspection selects the next bounded M1 owner as **M1i Phase-Front Cell Source-Scope Consumer**:

`phase_front_cell_source_scope -> SurfacePhaseFrontCell::{sourceComponent, sourceSheet, sourceIsolationSheets}`.

The accepted source still carries source-component and isolation-sheet identity as raw integers at this persistent constructive-cell boundary even though `SourceComponentId` and `IsolationSheetId` already exist in the authority kernel. M1i will migrate only this cell-owned source-scope state through checked IDs and explicit compatibility conversions. It will not broaden into `SurfaceFrontEdge` scope migration, `TopologyRegionId`, hard-rail/periodic owner IDs, M2 single-writer/outcome work, M3 conformity, M4 certificates/quotient relations, or G4 behavior repair.

Next turn:
`.agents/Directional/Architecture_M1i_Phase_Front_Cell_Source_Scope_Consumer_Code_Build_Plan.md`.
