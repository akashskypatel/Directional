# M5-CP3-TB1-R15-R1 — Artifact-Only Test + Benchmark Plan

## 1. Turn contract

**Turn:** `M5-CP3-TB1-R15-R1-EXEC`

**Mode:** **ARTIFACT-ONLY TEST + BENCHMARK / NO BUILD / NO REPACKAGE / BENCHMARK COUNT 0**.

Execute the immutable CB17 candidate using the exact CB18-frozen harness. This is a fresh restart of the entire R15 gate. No process, PASS, raw log, ledger row, selector credit, or semantic observation from either invalid R15 attempt may be carried forward.

Mandatory successor regardless PASS/RED: **`M5-CP3-TB1-R15-R1-REV`**.

## 2. Immutable authorities

Use exactly:

- candidate artifact `10742798135`;
- semantic source `1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`;
- candidate ZIP SHA-256 `eb1e2be55150022cdba05acf6b38433eb16352e4b3b6a561742e62de26cfd866`;
- candidate root manifest SHA-256 `a6c288ff4ef5afff8122f9dae0e330fe1cab4928b7bd5b5604b7d2fd5e32b951`, 28/28;
- packaged source SHA-256 `e6bed804841ecf590ccd1c372c906e19b927e5cf0d253d0d361993fa92ce68e0`;
- routing artifact `10592987234`, ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`;
- routing map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`;
- selector430 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- owner census `31 / 283 / 75 / 41`.

Canonical executor authority:

- harness `.agents/Directional/tools/m5_cp3_tb1_r15_r1_artifact_only_harness.sh`, SHA-256 `7867e779ee1d276617cbf7c0e1a9910dbd5b7388a5fe6bde7aac32a47efb81b7`;
- caller template `.agents/Directional/tools/m5_cp3_tb1_r15_r1_executor.yml`, SHA-256 `0f0a12f9b1b4ef43cde9f42726a60d91ea3ab4606cd3765c04ba6eaae076a15c`.

Do not edit either during EXEC.

## 3. Execution procedure

1. Install the canonical caller template at `.github/workflows/m5-cp3-tb1-r15-r1-exec.yml` byte-for-byte.
2. Verify its SHA/content against the canonical template and schema-validate it with the durable workflow validator.
3. Trigger it only through `.agents/connector-triggers/m5-cp3-tb1-r15-r1-exec.txt`.
4. The caller must verify the canonical harness SHA before execution.
5. Execute exactly one test per process with `GTEST_FAIL_IF_NO_TEST_SELECTED=1`, exact filter, and zero skips.
6. Do not retry after generated runtime starts. A semantic RED is evidence, not an orchestration failure.
7. Do not introduce `timeout-minutes`, shell `timeout`, watchdogs, chmod/mode repair, discovery, rebuild, relink, or package repair.
8. Preserve and upload the complete result tree and log even on semantic RED.

## 4. Frozen process vector — exactly 448

### 4.1 Mechanism/semantic — 11

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

### 4.2 Focused atlas — 1

12. `FieldTransportAtlas.RetainsDirectedTransitionValueForHardFeatureWithoutTraversalAdjacency`

### 4.3 Produced CP3 — 6

13. `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges`
14. `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate`
15. `M5CP3.ProducedTorusMissingPeriodicRelationOwnerRejectsTyped`
16. `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`
17. `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`
18. `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`

Rows 16 and 17 are binding product falsifiers. Preserve the complete raw failure/success path; do not reinterpret or weaken expectations inside EXEC.

### 4.4 Selector430 — 430

Execute selector430 ordinals 1..430 in frozen order. Report protected ordinals **191, 192, 247, 408** explicitly.

Total: **448 fresh exact-filter processes**. Benchmarks: **0**.

## 5. Mechanical validity requirements

A mechanically valid R15-R1 result requires all of the following:

- exact candidate/routing/provider digests verified;
- candidate root manifest 28/28 before and after runtime;
- packaged source status clean;
- exact harness hash verified;
- selector430 and first427 byte hashes exact;
- routing identity sequence equals selector430 and owner census is exact;
- every prescribed row executed exactly once;
- every process selects exactly one GTest and records zero skips;
- all 448 exit/result/raw/resource records present;
- package/source/execution-view censuses unchanged postflight;
- result `SHA256SUMS` excludes itself and covers every other result file exactly once;
- benchmark/configure/compile/relink/discovery/package-repair/mode-repair/source-test-fixture-selector-mutation counters all false/zero;
- no retry after runtime start.

If any mechanical condition fails, classify the gate orchestration-invalid and take no semantic credit.

## 6. Semantic reporting requirements

If mechanics are valid, report without repair:

- mechanism/semantic PASS/RED vector;
- atlas PASS/RED vector;
- produced rows 13..18 individually;
- selector430 PASS/RED ordinals;
- protected ordinals 191/192/247/408;
- exact first false predicate/reason for rows16/17 if RED;
- whether row16 reaches materialization and the independent Forward -> Reverse direction comparator;
- whether row17 reaches the transform-only tamper and exact typed `NonReciprocalPeriodicRelation` rejection;
- complete stable-regression candidate evidence, but do not adjudicate it in EXEC.

EXEC may not promote the candidate, discharge debt, publish selector authority, close observations, or alter stable accounting. Those decisions belong to Review.

## 7. Stop and successor

Do not repair or rerun after runtime begins. On a complete mechanically valid PASS or RED vector, close EXEC and route to **`M5-CP3-TB1-R15-R1-REV`**.

If runtime never begins because preflight/caller orchestration fails, preserve the exact evidence and route to Review/planning under the existing no-silent-retry rules.
