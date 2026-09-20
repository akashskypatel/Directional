# M5-CP1-TB1-R3 Artifact-Only Test + Benchmark Plan

**Turn:** `M5-CP1-TB1-R3-EXEC`
**Milestone/checkpoint:** M5 / CP1
**Mode:** Test + Benchmark / immutable artifact only
**Candidate artifact:** `10600353027`
**Candidate source:** `8a86710dd33d7b6cb9a077aef738577e4075b5f7`
**Candidate ZIP SHA-256:** `cdc0cb798e6b117727ddde0dbfa5008d2a8140c709eeafb0af66872c5c7ae6b0`
**Packaged source SHA-256:** `594dad05c7078c0c5b2e03486f408ca6621e2c36875873fa045803245497352d`

## 1. Objective

Execute the corrected CP1 candidate from ordinal 1 and determine whether the pure relation-container permutation witness is behaviorally green. R3 is the first runtime falsifier of the R2 Review classification.

R3 imports **no semantic credit** for R2 ordinal 6. The complete gate is fresh.

## 2. Immutable authority

Before runtime, require all of the following:

- provider/download digest of candidate artifact `10600353027` matches `cdc0cb798e6b117727ddde0dbfa5008d2a8140c709eeafb0af66872c5c7ae6b0`;
- root `SHA256SUMS` verifies **28/28** and excludes itself;
- `metadata/source-commit.txt` is exactly `8a86710dd33d7b6cb9a077aef738577e4075b5f7`;
- packaged source archive hashes to `594dad05c7078c0c5b2e03486f408ca6621e2c36875873fa045803245497352d`;
- build/preflight exits are zero and all source-status receipts are empty;
- command boundary includes `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and `preflightCompile=true`;
- GMP evidence proves `DIRECTIONAL_ENABLE_GMP=ON` plus `gmpxx` and `gmp` linkage;
- selector path is `.agents/Directional/Architecture_M4_CP4_CB8_Required_Green_Selector_430.txt`, exactly **430 LF rows**, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- the first427 selector prefix is `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- reuse the unchanged accepted M4 routing artifact `10592987234`, provider ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`, with identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c` and owners **31 / 283 / 75 / 41**.

Any authority mismatch is an orchestration stop with **zero semantic credit**.

## 3. Focused rows

Execute exactly the same nine focused identities and order as R2, each in its own exact-filter process:

1. `SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator`
2. `SurfaceCellsPhase10.PeriodicHolonomyDistinctTopologyRegionsRetainEveryRelation`
3. `SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained`
4. `SurfaceCellsPhase10.PeriodicHolonomyConflictingTransportFailsClosed`
5. `M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap`
6. `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation`
7. `M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate`
8. `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation`
9. `SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`

Every focused process must select exactly one test and skip zero. Row6 must execute the corrected source from `8a86710d...`; no test substitution or witness mutation is permitted.

## 4. Full accepted selector gate

Execute selector430 from ordinal 1 through 430, one fresh exact-filter process per row, using the accepted routing map. Require exact-one selection and zero skips for every row.

Benchmark execution count is exactly **0**.

## 5. Artifact-only boundary

R3 may not:

- configure, compile, link or relink;
- run generated test discovery;
- repair package bytes, permissions or modes;
- mutate packaged source, tests, fixtures, selectors or routing authority;
- substitute another binary or filter;
- execute any benchmark;
- change product/test semantics.

Record byte+mode censuses for the candidate package, packaged source and execution view before and after runtime. Require exact postflight equality and candidate manifest **28/28** again after execution.

## 6. Decision rules

### Mechanically green

Mechanically green requires:

- focused **9/9 PASS**;
- selector430 **430/430 PASS**;
- exact-one selection / zero skips for all **439** fresh processes;
- benchmark count **0**;
- immutable postflight exact;
- no configure/compile/relink/discovery/repair/mutation.

If mechanically green, R3 routes to independent `M5-CP1-TB1-R3-REV`; candidate promotion and CP1 acceptance remain Review-owned.

### Corrected row6 RED

If row6 selects exactly once, reaches the corrected pure-permutation comparison, and is RED, `M5-CP1-TB1-R2-REV-OBS-01` is falsified: treat the result as product-order-dependency evidence. Do **not** adjust the witness, relax comparisons, alter membership between drafts, or make an in-turn code change. Preserve the raw receipt and route to independent Review + Plan.

### Other semantic RED

Any other correctly selected semantic RED also routes to independent Review + Plan with the candidate unpromoted.

### Orchestration failure

A preflight/authority/selection-integrity failure earns zero semantic credit and must be classified separately from a Directional behavior failure.

## 7. Credit boundary

Row6 and row9 remain mechanism/direct-helper evidence only. Even a fully green R3 does not discharge the four M5 produced-witness debts. M5-CP3 still owns their production re-proof under frozen definitions.
