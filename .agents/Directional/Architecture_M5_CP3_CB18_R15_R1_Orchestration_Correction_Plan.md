# M5-CP3-CB18 — R15-R1 Orchestration Correction Plan

## 1. Turn contract

**Turn:** `M5-CP3-CB18`

**Mode:** **CONTROL-PLANE ONLY / RUNTIME-FREE / NO DIRECTIONAL COMPILE / NO REPACKAGE**.

**Purpose:** freeze and statically prove the corrected artifact-only R15-R1 execution plane after R15 attempt 1 executed one exact test successfully but the temporary exact-one parser falsely counted it as zero-selected.

This turn is a Code + Build cadence slot only because it owns executable control-plane bytes for the next Test + Benchmark turn. It does **not** authorize any semantic implementation, test, fixture, selector, benchmark, CMake, package or reusable-workflow permission change.

## 2. Immutable semantic authority

All semantic/runtime inputs are frozen unchanged:

- CB17 semantic source: `1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`;
- candidate artifact: `10742798135`;
- candidate ZIP SHA-256: `eb1e2be55150022cdba05acf6b38433eb16352e4b3b6a561742e62de26cfd866`;
- root manifest SHA-256: `a6c288ff4ef5afff8122f9dae0e330fe1cab4928b7bd5b5604b7d2fd5e32b951`, 28/28;
- packaged source archive SHA-256: `e6bed804841ecf590ccd1c372c906e19b927e5cf0d253d0d361993fa92ce68e0`;
- routing artifact: `10592987234`, SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`;
- routing identity-map SHA-256: `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`;
- selector430 SHA-256: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- first427 prefix SHA-256: `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- owner census: `31 / 283 / 75 / 41`.

CB18 must not rebuild or repackage those inputs.

## 3. Cause-proved defect to correct

The historical R15 retry harness at event commit `9161a05fe5271b8e0a75d365182e49237aa864a6`, blob `5b2f569a1ef4d54daf65ed0d1af3604a3b87db28`, used doubled bracket escapes in its GTest protocol parser. On the preserved raw first process:

- historical selected parser -> `0`;
- corrected selected parser -> `1`;
- historical passed parser -> `0`;
- corrected passed parser -> `1`;
- corrected skipped parser -> `0`.

The product process itself ran exactly once and returned `[ OK ]`. The defect is therefore the temporary exact-one evidence parser.

## 4. Required change

Author one canonical successor harness/control payload for `M5-CP3-TB1-R15-R1-EXEC` with the smallest sufficient correction:

1. replace the malformed doubled-bracket matching with one deterministic parser that recognizes literal GTest protocol lines;
2. keep exact-one selection, zero-skip and PASS accounting fail-closed;
3. keep all candidate/routing/selector hash and immutable-census checks;
4. keep execution-view extraction mode-preserving and prohibit `chmod`/repair;
5. keep all 448 prescribed processes independent and exact-filtered;
6. keep benchmark count exactly 0;
7. keep package/source/execution-view immutable postflight and self-excluding result manifest;
8. keep the no-retry-after-generated-runtime-start rule;
9. keep the full gate free of repository/shell elapsed-time watchdogs;
10. bind the temporary successor caller to the exact frozen harness bytes/hash.

Do not broaden the correction into a parser framework or generalized test runner. One locally auditable exact protocol parser is sufficient.

## 5. Mandatory static falsifier before R15-R1 is authorized

CB18 must test the parser without executing a Directional binary. Feed representative literal GTest protocol text containing:

```text
[ RUN      ] Probe.Test
[       OK ] Probe.Test (0 ms)
```

and require:

```text
selected=1
passed=1
skipped=0
```

The same static control must additionally demonstrate that the historical doubled-backslash parser yields `selected=0` on that input. If the corrected parser and historical parser are not discriminated by this test, CB18 is RED and R15-R1 is not authorized.

Also statically cover a skipped line so `skipped=1` is detected and fails the execution contract when used in the exact-one row helper.

## 6. Required control-plane verification

Before CB18 closes:

- `bash -n` or equivalent shell syntax check passes on the exact harness bytes;
- the static protocol falsifier above passes;
- the successor caller draft is SchemaStore-valid through the durable workflow validator;
- caller permissions satisfy the current observer reusable's static permission ceiling without modifying reusable permissions;
- the caller has one narrow marker trigger and no broad branch trigger;
- there is no `timeout-minutes` or shell `timeout`/watchdog around the complete gate;
- exact candidate/routing/selector hashes and expected process counts are frozen in the control authority;
- no Directional executable, test, benchmark, help/list/version/discovery command is run;
- no CMake configure, compile, link or package operation is run;
- no product/test/fixture/selector/benchmark/CMake byte changes;
- `runtimeExecution=false` is recorded in CB18 validation evidence.

## 7. Frozen R15-R1 execution vector

If and only if CB18 closes GREEN, exact successor is `M5-CP3-TB1-R15-R1-EXEC` on the unchanged candidate. It must restart from process 1 and execute the exact frozen vector below, one exact-filter fresh process per identity with `GTEST_FAIL_IF_NO_TEST_SELECTED=1`, exactly one selected test and zero skips.

### 7.1 Mechanism/semantic — 11

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

### 7.2 Focused atlas — 1

12. `FieldTransportAtlas.RetainsDirectedTransitionValueForHardFeatureWithoutTraversalAdjacency`

### 7.3 Produced CP3 — 6

13. `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges`
14. `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate`
15. `M5CP3.ProducedTorusMissingPeriodicRelationOwnerRejectsTyped`
16. `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`
17. `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`
18. `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`

Rows 16/17 are the binding product falsifiers. Row16 must reach relation/materialization assertions before debt-3 credit is even eligible; if it reaches the carried R6 direction comparator, preserve both independent Forward -> Reverse agreement and inverted-pair rejection. Row17 must reach the transform-only tamper and exact typed `NonReciprocalPeriodicRelation` rejection before debt-4 credit is eligible.

### 7.4 Selector430 — 430

Execute exact selector430 ordinals 1..430 in order. Selector SHA-256 remains `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 remains `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`. Report protected ordinals **191, 192, 247 and 408** explicitly.

Total is exactly **11 + 1 + 6 + 430 = 448** fresh processes; benchmarks are exactly **0**.

No process, PASS, ledger row or semantic observation from R15 attempts 0/1 may be carried forward. In particular, process 1 must run again inside the valid complete ledger. Every process records raw output/resource receipt/exit state. A semantic RED is evidence and does not permit harness repair, process substitution or a reduced gate.

## 8. Acceptance and stop rules

CB18 is GREEN only when all static/control-plane checks pass and all prohibited semantic/runtime/build mutation counts are zero.

Stop and return to Review/planning if any of the following occurs:

- static parser falsifier does not distinguish corrected from historical behavior;
- the successor harness/caller requires changing a product/test/fixture/A3/selector byte;
- candidate/routing/selector authority cannot be pinned exactly;
- workflow correction would require changing reusable-workflow permissions or semantics;
- any generated Directional runtime starts during CB18;
- any configure/compile/repackage operation occurs;
- full-gate timeout/watchdog is introduced;
- the exact 448-process vector cannot be reconstructed unchanged.

Do not “prove” the correction by running one Directional test in CB18. Runtime proof belongs only to R15-R1.

## 9. Successor chain

On CB18 GREEN:

1. `M5-CP3-TB1-R15-R1-EXEC` — fresh 448-process immutable artifact-only gate, benchmark 0.
2. `M5-CP3-TB1-R15-R1-REV` — mandatory independent Review regardless PASS/RED.

Only R15-R1 Review may decide candidate promotion, nonzero-Z4 debt discharge, R6 direction-observation closure, DEFN-R1 mechanism-observation closure, CP3 publication or stable regression accounting.
