# M5-CP3-TB1-R6 Artifact-Only Test + Benchmark Plan

**Turn:** `M5-CP3-TB1-R6-EXEC`
**Boundary:** **artifact-only Test + Benchmark**
**Immutable candidate:** artifact `10637998372` / packaged source `8f77ec403f16930145bba5bfc526a5b881b9f166`
**Purpose:** dynamically identify the active CB7 periodic-promotion failure branch without changing semantics
**Mandatory successor:** `M5-CP3-TB1-R6-REV`

## 1. Immutable authority

Consume only CB7 candidate artifact `10637998372`:

- artifact ZIP SHA-256: `1c92e42939081ec9f041f72e916c99d80a700b39a61e3917e8cf8830c5a3f98f`
- root `SHA256SUMS`: **28 rows**, SHA-256 `1b0bc0b8ce4ff0c339659c7f7c5c3c4e9e26143d352424f7aecf1a2b8f91f737`, must verify **28/28**
- packaged source: `8f77ec403f16930145bba5bfc526a5b881b9f166`
- source archive SHA-256: `dbc083059b4dbd8ea7b429ca32819ce8a91b179b5e2cbd6201a66113d37a9163`
- compile log artifact `10637858795`, SHA-256 `ad626d649fdae2bb8fe591e2a3a38d0ee670ed152967f08cb800c098e4c4645a`
- command boundary must remain `runtimeExecution=false` for the build package

Accepted routing authority remains artifact `10592987234` with identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`. Selector430 remains exactly `.agents/Directional/Architecture_M4_CP4_CB8_Required_Green_Selector_430.txt`, **430 LF rows**, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; exact first427 SHA-256 remains `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

Extract the immutable package with ordinary `unzip`/`tar` while preserving archived executable mode bits. Python `zipfile.extractall`, `chmod`, package repair, source repair, fixture staging that mutates package bytes, or any other mode/content repair is prohibited. Missing executable mode or missing immutable input is orchestration failure.

## 2. Exact 446-process gate

Execute every identity as a **fresh exact-filter process**, require selected test count exactly one, zero skips, and preserve raw stdout/stderr plus exit status for each row. The gate is unchanged from R5:

### 2.1 Nine reviewed mechanism identities

1. `SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator`
2. `SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained`
3. `M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap`
4. `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation`
5. `M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate`
6. `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation`
7. `SurfacePhaseFrontProductFactoryAuthority.ConflictingPeriodicRelationValueRejectsAtCheckedFactory`
8. `SurfacePhaseFrontProductFactoryAuthority.NonReciprocalPeriodicRelationRejectsAtCheckedFactory`
9. `SurfacePhaseFrontProductFactoryAuthority.RepresentationRenumberedPeriodicRelationRejectsAtCheckedFactory`

Required entering expectation: **9/9 PASS**.

### 2.2 Focused atlas identity

`FieldTransportAtlas.RetainsDirectedTransitionValueForHardFeatureWithoutTraversalAdjacency`

Required entering expectation: **1/1 PASS**.

### 2.3 Six produced identities

1. `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges`
2. `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate`
3. `M5CP3.ProducedTorusMissingPeriodicRelationOwnerRejectsTyped`
4. `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`
5. `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`
6. `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`

CB7 is diagnostic-only, so R6 pre-commits **no production recovery**. The expected semantic shape remains **0/6 PASS** unless runtime proves an unexpected semantic change, which itself requires Review. Every RED must expose the phase-front failure reason and identify one of:

- `PeriodicGeneratorRouteUnavailable`
- `PeriodicActionCorrespondenceMismatch`
- `PeriodicHolonomyZeroTranslation`
- `PeriodicHolonomyMissingGeneratorRoute`
- `PeriodicHolonomyMissingCutRoute`
- `PeriodicHolonomyInvalidRelationIdentity`

The old generic `PeriodicHolonomyMismatch` is a diagnostic-cutover failure or evidence that a different call site owns the endpoint. Record the exact reason per produced row; do not collapse them in the report even when all six agree.

### 2.4 Selector430

Execute all **430** selector rows in their frozen order. Entering expectation remains **429/430 PASS** with sole RED ordinal **408**, `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`, because CB7 changed diagnostics only and does not repair production.

The following accepted rows are an explicit R5-Review hazard audit and must remain byte-unchanged and required-green:

- `SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration.NonzeroNetCycleFailsClosedAtPeriodicHolonomyGuard`
- `SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration.MalformedAuthoritativeCrossingProvenanceFailsClosed`
- `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`

If any turns RED because it reaches a newly relabelled same-region site, record that as diagnostic-label exposure on accepted authority; do **not** change its expectation, selector bytes, or test source in R6.

Total planned fresh processes: **9 + 1 + 6 + 430 = 446**. Benchmark executions: **0**.

## 3. Failure-branch interpretation

R6 records evidence only; it does not repair. Mandatory Review owns the next semantic decision.

- `PeriodicGeneratorRouteUnavailable`: Review may activate `M5-CP3-TB1-R5-REV-OBS-01` and inspect whether transition incidence must derive from exact A3 carrier `sourceEdgeFaces` rather than A4 endpoint face labels.
- `PeriodicActionCorrespondenceMismatch`: inspect branch rotation / lattice endpoint correspondence; do not alter generator-route face authority merely because the static candidate exists.
- `PeriodicHolonomyZeroTranslation`: preserve the frozen zero-translation prohibition and inspect the paired same-region cut copies/lattice coordinates.
- `PeriodicHolonomyMissingGeneratorRoute`, `PeriodicHolonomyMissingCutRoute`, or `PeriodicHolonomyInvalidRelationIdentity`: reconcile the observed contradiction with the already-checked route inputs and relation factory contract before authorizing repair.
- old `PeriodicHolonomyMismatch`: diagnostic cutover did not reach the owning branch or another site owns the failure; no semantic correction is authorized.

## 4. Artifact-only prohibitions

R6 must not:

- configure, compile, link, relink, regenerate build files, or invoke `ctest`;
- execute benchmark binaries or any benchmark mode;
- run generated discovery/list/help/version commands;
- modify packaged source, tests, fixtures, selectors, manifests, executable modes, or routing authority;
- repair or substitute any missing artifact/file;
- change accepted runtime authority, promote CB7, discharge debt, publish selector bytes, or perform a same-turn semantic repair.

A zero-selected exact filter, nonzero skip, missing log/receipt, package/hash mismatch, mode mismatch, or incomplete 446-row ledger is orchestration failure, never semantic PASS/RED evidence.

## 5. Required evidence and postflight

Before runtime:

1. verify artifact SHA-256, packaged source SHA, source archive SHA and **28/28** root manifest;
2. verify selector430/first427 hashes and routing identity-map hash;
3. record immutable package/source/execution-view byte+mode censuses;
4. record all build/mutation counters at zero.

After runtime:

1. preserve one ledger row and raw-log SHA-256 per exact-filter process;
2. prove all **446/446** rows selected exactly one identity and skipped zero;
3. record the 9/1/6/430 PASS/RED vector and exact six produced failure reasons;
4. verify package/source/execution-view byte+mode censuses are identical to preflight;
5. emit a recursive self-excluding result `SHA256SUMS` and verify every entry;
6. record benchmark/configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation counters all zero.

Every observed accepted-green→RED regression must be categorized in `Regression_Root_Cause_Tracker.md` before R6 closes. The known ordinal408 RED is the existing `RP-01` recovery event unless new evidence changes its classification. CB7's expected diagnostic relabeling alone does not create production credit.

## 6. Stop and successor

R6 ends after immutable evidence publication and durable regression classification. It performs no correction. Exact successor is mandatory runtime-free **`M5-CP3-TB1-R6-REV`**, which independently re-derives the artifact/ledger/postflight evidence, adjudicates the active typed branch, audits the three accepted generic-reason rows, and only then may freeze a semantic correction or another stop condition.
