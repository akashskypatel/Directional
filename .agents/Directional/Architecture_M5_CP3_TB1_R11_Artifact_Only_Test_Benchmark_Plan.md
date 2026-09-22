# M5-CP3-TB1-R11 Artifact-Only Test + Benchmark Plan

**Turn:** `M5-CP3-TB1-R11-EXEC`
**Boundary:** immutable artifact-only Test + Benchmark / no configure, compile, relink, repair, fixture mutation, selector mutation, or package mutation
**Mandatory successor:** `M5-CP3-TB1-R11-REV`
**Benchmark count:** `0`

## 1. Immutable candidate authority

R11 consumes only the compile-green CB12 package:

- semantic source `8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`;
- compile run/job `35767608403 / 106881074883`;
- candidate artifact `10713410215` (`m5-cp3-cb12-result-35767608403`), provider/download ZIP SHA-256 `faf4def9e6823f718e56091876bb97047f5e91a8bfb561ca40d91d70d2af61ce`;
- compile log artifact `10713170611`, ZIP SHA-256 `6111b5eb2886f9da7a8a53226b299f417ee4116fc524d5263eadc1e35e12eaee`;
- root `SHA256SUMS` **28/28**, SHA-256 `352f7553e2f0dc627ada385d78327bcb93d4f3b66125f4faf540d6965a1c2c33`;
- packaged source archive SHA-256 `506e9d75976802f7045b95344ef8cc0ff1e4d39b8343bdaddaa009a58e04a673`;
- `build.log` SHA-256 `f7637a0f67097486355f9976cae58624cffa32f9cf37f6cd8cd57335563f9cfb` and `configure.log` SHA-256 `58b6b72f48bff0ed9589cc8815a393d39097156ac1197d4b8d512c9db382165d`;
- `runtimeExecution=false`, `exactArithmeticBackend=GMP`, explicit GMPXX+GMP linkage, clean source receipts;
- all eight targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.

Before any Directional process executes, verify the downloaded ZIP digest, root manifest, source SHA/archive, executable mode bits, clean source receipts, GMP/GMPXX evidence, `runtimeExecution=false`, and exact target inventory. Extraction must preserve archived executable mode bits; missing mode is orchestration failure and must not be repaired.

Accepted routing/selector authority is byte-identical:

- routing artifact `10592987234`, SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`;
- identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`;
- selector430 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

No R11 step may rebuild, regenerate discovery, patch source, alter fixtures/routing/selectors, relink, or repair the immutable package.

## 2. Frozen 446-process execution vector

Run exactly **446 fresh processes**, one exact gtest identity per process, requiring **exactly one selected test and zero skips** per row.

Nine reviewed mechanism identities:

1. `SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator`
2. `SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained`
3. `M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap`
4. `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation`
5. `M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate`
6. `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation`
7. `SurfacePhaseFrontProductFactoryAuthority.ConflictingPeriodicRelationValueRejectsAtCheckedFactory`
8. `SurfacePhaseFrontProductFactoryAuthority.NonReciprocalPeriodicRelationRejectsAtCheckedFactory`
9. `SurfacePhaseFrontProductFactoryAuthority.RepresentationRenumberedPeriodicRelationRejectsAtCheckedFactory`

Focused atlas identity: `FieldTransportAtlas.RetainsDirectedTransitionValueForHardFeatureWithoutTraversalAdjacency`.

Six produced identities:

1. `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges`
2. `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate`
3. `M5CP3.ProducedTorusMissingPeriodicRelationOwnerRejectsTyped`
4. `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`
5. `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`
6. `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`

Then execute all **430** accepted selector identities in frozen order. Protected ordinals **191, 192, 247, 408** must remain PASS. Expected all-green vector is **9/9 + 1/1 + 6/6 + 430/430 = 446/446 PASS**. Benchmark count is 0. Generated discovery/list/help/version commands are prohibited.

## 3. Produced nonzero-Z4 discriminators

Rows 1/2/3/6 are regression controls and must remain PASS.

Row 4 must independently derive one Forward and one Reverse A3 boundary occurrence and prove semantic direction **Forward occurrence/edge -> Reverse occurrence/edge**; source/A3 generator route equals the published relation route; `sourceRotation == action.rotation`; rotation and translation are both genuinely nonzero; the relation materializes; the selected certificate consumes it; and `consumedPeriodicHolonomies > 0`.

Row 5 must use the same independently selected directed relation, change **only** action rotation while preserving relation identity/carriers, and reject exact typed `NonReciprocalPeriodicRelation`. No inverse fallback, best-of-two direction search, endpoint rewrite, or alternate relation identity is permitted.

## 4. Result finalization — complete self-manifest

Do not repair R10. R11 must finalize the fresh result in this order:

1. finish runtime evidence and ledgers;
2. copy `driver-authority.txt` into the result directory;
3. regenerate recursive self-excluding `SHA256SUMS` over **every other** evidence file;
4. run `sha256sum -c SHA256SUMS` and require success;
5. independently count non-manifest files and require exact equality with manifest rows;
6. only then upload.

If evidence shape is otherwise unchanged, expected coverage is **912/912**. The actual file-count equality is authority. There is no orchestration-only exception. This carries `M5-CP3-TB1-R10-EXEC-CAND-01` and `M5-CP3-TB1-R10-REV-OBS-01` to R11 Review.

## 5. Immutable postflight

After all 446 processes, require exact equality for candidate package byte+mode census, packaged-source census, execution-view census, source SHA/archive, selector430/first427, routing artifact/identity map, and runtime binary identities/modes.

## 6. Stop and review rules

Zero-selected filters, skipped required identities, package/source/routing/selector mutation, missing mode, manifest mismatch, startup failure, or other orchestration failure are not semantic evidence. Repair is allowed only before any Directional runtime begins. Once runtime begins, do not silently repair or rerun.

Any mechanically complete R11, green or semantic RED, routes to mandatory `M5-CP3-TB1-R11-REV`. EXEC may not promote the candidate, close `M5-CP3-TB1-R10-REV-CAND-01`, discharge either nonzero-Z4 debt, close `M5-CP3-TB1-R6-REV-OBS-01`, or precommit selector publication.

## 7. Accounting entering R11

Stable accounting remains **50 events / 14 categories / 36 recurrences**; project debt remains **3**. Accepted runtime remains `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. CB12 candidate `10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188` is compile-only and unpromoted. `M5-CP3-TB1-R10-REV-CAND-01` remains OPEN / RP-01 / non-stable / correction compiled, runtime recovery pending / owner R11 Review. `M5-CP3-TB1-R6-REV-OBS-01` and `M5-CP2-TB1-REV-OBS-01` remain OPEN. Selector publication remains prohibited.
