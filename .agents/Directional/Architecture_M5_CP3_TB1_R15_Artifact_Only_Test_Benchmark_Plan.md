# M5-CP3-TB1-R15 Artifact-Only Test + Benchmark Plan

**Turn:** `M5-CP3-TB1-R15-EXEC`
**Boundary:** immutable candidate-artifact execution only; no rebuild, configure, relink, source/test/fixture/selector mutation or package repair
**Candidate:** CB17 compile package `10742798135` from semantic source `1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`
**Mandatory successor:** `M5-CP3-TB1-R15-REV`

## 1. Purpose

R15 is the first runtime falsifier of frozen §16.3 as implemented by CB17. It must answer only whether the immutable candidate satisfies the corrected relation-gauge contract under the already-frozen fixture, A3 authority and selector430 surface.

No result in EXEC may promote the candidate, discharge debt, close Review observations or publish a selector. Those decisions remain Review-owned.

## 2. Immutable preflight

Before runtime, verify exactly once:

1. candidate provider digest equals expected artifact digest;
2. root `SHA256SUMS` verifies completely (**28/28**);
3. packaged source archive hashes to `e6bed804841ecf590ccd1c372c906e19b927e5cf0d253d0d361993fa92ce68e0` and records exact source `1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`;
4. source status receipts are clean;
5. package compile receipts record `runtimeExecution=false` and GMP/GMPXX linkage;
6. executable mode bits are already correct in the immutable archive; no permission repair is allowed;
7. routing identity map, selector430 and first427 bytes equal the R14 authorities unless the candidate package contains an explicitly authorized identical copy; no regenerated discovery is allowed.

Any preflight mismatch is an orchestration/evidence failure and stops before runtime.

## 3. Exact fresh process vector — 448 processes

Every runtime invocation must use an exact `--gtest_filter`, set `GTEST_FAIL_IF_NO_TEST_SELECTED=1`, select exactly one test, skip zero tests, and execute in a fresh process. Benchmark count is **0**.

### 3.1 Mechanism/semantic vector — 11

Execute these eleven identities in this order:

1. `M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges`
2. `M5CP3.StorageCanonicalPeriodicRelationResolvesSemanticForwardReverse`
3. `SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator`
4. `SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained`
5. `M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap`
6. `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation`
7. `M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate`
8. `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation`
9. `SurfacePhaseFrontProductFactoryAuthority.ConflictingPeriodicRelationValueRejectsAtCheckedFactory`
10. `SurfacePhaseFrontProductFactoryAuthority.NonReciprocalPeriodicRelationRejectsAtCheckedFactory`
11. `SurfacePhaseFrontProductFactoryAuthority.RepresentationRenumberedPeriodicRelationRejectsAtCheckedFactory`

This is exactly the R14 11-process mechanism vector with its first CB16 identity replaced one-for-one by the CB17 `Q != A` discriminator. Process cardinality does not increase.

### 3.2 Focused atlas control — 1

12. `FieldTransportAtlas.RetainsDirectedTransitionValueForHardFeatureWithoutTraversalAdjacency`

### 3.3 Produced CP3 vector — 6

13. `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges`
14. `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate`
15. `M5CP3.ProducedTorusMissingPeriodicRelationOwnerRejectsTyped`
16. `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`
17. `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`
18. `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`

Rows 16/17 above are the prior produced rows4/5 and are the binding product falsifiers for CB17 recovery.

### 3.4 Selector430 — 430

Execute the exact immutable selector430 identities, ordinals 1..430, one process each. Selector430 SHA-256 remains:

`1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`

First427 SHA-256 remains:

`f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`

Protected ordinals **191, 192, 247 and 408** must be reported explicitly.

Total: **11 + 1 + 6 + 430 = 448** fresh processes.

## 4. Binding semantic observations

EXEC must record exact first-false behavior without changing the package or inventing a diagnosis from a reason name.

- The CB17 focused identity must prove the hand-authored `Q != A` contract at runtime.
- Produced rows1/2/3/6 must retain their accepted R14 behavior.
- Produced row4 must reach the relation/materialization assertions for debt-3 recovery credit; if it reaches the carried R6 direction comparator, capture both independent Forward -> Reverse agreement and the inverted-pair rejection for Review.
- Produced row5 must reach its transform-only tamper and exact typed `NonReciprocalPeriodicRelation` rejection for debt-4 recovery credit.
- Selector430 must remain **430/430** before any later publication discussion.

A row4/5 RED is evidence, not permission to repair during EXEC.

## 5. Evidence and postflight

Package complete evidence with a self-manifest that is externalized while generated and then verifies every final non-manifest evidence file exactly once. Preserve:

- exact process ledger with selected/skipped/passed counts;
- raw stdout/stderr and resource receipts per process;
- executable hashes;
- selector/routing authority receipts;
- candidate/package/source hashes;
- immutable package, packaged-source and execution-view pre/post censuses;
- execution boundary and prohibited-operation counters.

Postflight must prove no rebuild/configure/relink/generated discovery, source/test/fixture/selector mutation, package mutation, permission repair, retry after runtime start or evidence stitching occurred.

## 6. Review gate

`M5-CP3-TB1-R15-REV` is mandatory regardless of PASS/RED.

Review must independently re-open and verify the complete R15 evidence, then decide:

- whether CB17 recovered the frozen relation-gauge seam;
- whether `M5-CP3-TB1-R6-REV-OBS-01` is discharged by independent direction agreement plus inverted-pair rejection;
- whether the two nonzero-Z4 produced debts are discharged;
- whether `M5-CP2-TB1-REV-OBS-01` can advance under a fully green corrected CP3 gate;
- whether the candidate can be promoted or a new bounded successor is required;
- whether `M5-CP3-TB1-R14-REV-OBS-01`'s synthetic-gauge condition is satisfied independently of the zero-gauge produced witness.
