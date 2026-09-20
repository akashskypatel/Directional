# M5-CP1-TB1 Artifact-Only Test + Benchmark Plan

**Turn:** `M5-CP1-TB1-EXEC`
**Milestone/checkpoint:** M5 / CP1
**Mode:** Test + Benchmark / immutable artifact-only
**Evidence commit:** `b98f461b9a392cc182891a81c0a84b0b01dfbb45`
**Candidate build artifact:** `10595705100` (`directional-m5-cp1-cb1-result-35478855426`)
**Candidate artifact SHA-256:** `fdc4046630c6f48b2bc76aad74ebc07b443a024fc9cfd76507bae515eb8668ea`

## 1. Objective

Runtime-validate the bounded M5-CP1 mechanism introduced by CB1 while preserving the accepted M4 selector430 predecessor unchanged. CP1 credit is mechanism-only: no M5 direct-production debt closes in this turn.

The runtime questions are:

1. canonical periodic relation identity is stable under representation/storage changes but distinguishes topology-distinct carriers;
2. action/transport remains relation value rather than identity;
3. component aggregation preserves canonical IDs without ordinal offsets;
4. the producer publishes the exact selected relation path and downstream validation accepts that certificate without reconstructing an alternate route;
5. unused valid relations do not perturb selected lineage;
6. accepted selector430 behavior remains intact.

## 2. Immutable preflight

1. Download artifact `10595705100` exactly once. Verify provider/download SHA-256 equals `fdc4046630c6f48b2bc76aad74ebc07b443a024fc9cfd76507bae515eb8668ea`.
2. Extract with an archive tool that preserves stored executable mode bits (`unzip`/`tar` as appropriate). **Do not repair modes or package bytes.** A missing executable bit is orchestration failure.
3. Verify root `SHA256SUMS` **28/28**, manifest SHA-256 `8330461b8c5e489059e2ec320cb2e2d5243d6ef36dc01b667b5cefc09f609a3d`.
4. Verify `metadata/source-commit.txt == b98f461b9a392cc182891a81c0a84b0b01dfbb45`, packaged source archive SHA-256 `4f51257db12ae24363a45ddfa62778200e9ac0a8ef4ce2b585c8c606350d78b9`, clean source receipts, `runtimeExecution=false`, `exactArithmeticBackend=GMP`, `DIRECTIONAL_ENABLE_GMP=ON`, and explicit `gmpxx` + `gmp` linkage evidence.
5. Verify all required packaged test executables retain their archived executable mode. Do not configure, compile, relink, regenerate discovery/code, patch source/fixtures, or mutate selectors.
6. From the packaged source verify `Architecture_M4_CP4_CB8_Required_Green_Selector_430.txt` is exactly **430 LF rows / SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`**. Reuse the accepted M4-TB3 identity-to-owner routing authority (identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6`) rather than generated test discovery.
7. Capture a byte+mode census of the immutable package, packaged source and execution view for postflight comparison.

Any mismatch stops execution as orchestration/infrastructure failure and receives zero semantic credit.

## 3. Ordered runtime execution

Every test identity below runs in a **fresh process** with an exact `--gtest_filter=<identity>` against packaged binaries only. Require exactly one selected test, zero skip, exit 0 and one PASS. No `--gtest_list_tests`, discovery, rebuild or fallback is permitted.

### A. Focused CP1 mechanism gate

Run from `bin/directional_surface_cell_producer_tests`:

```text
SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator
SurfaceCellsPhase10.PeriodicHolonomyDistinctTopologyRegionsRetainEveryRelation
SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained
SurfaceCellsPhase10.PeriodicHolonomyConflictingTransportFailsClosed
M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap
M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation
M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate
M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation
M4CP4.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization
```

Acceptance: **9/9 PASS**, exact-one selection, zero skip/crash/timeout/invalid-selection. The final witness must remain non-vacuous with **>=2 distinct canonical periodic relation owners and >=2 owned periodic edges**; a vacuous pass is RED.

### B. Accepted predecessor gate

Run all 430 rows of `Architecture_M4_CP4_CB8_Required_Green_Selector_430.txt` in exact file order, each as one fresh exact-filter process routed by the accepted identity map.

Acceptance: **430/430 PASS**, zero skip/crash/timeout/invalid-selection, owner census unchanged at **31 / 283 / 75 / 41**. No focused result substitutes for a selector row and no prior runtime row is imported.

### C. Source-side CP1 audit

From the immutable packaged source, independently verify:

```text
no production PeriodicRelationId::from_index(...)
no periodicRelationOffset-style component renumbering
no reachableHardRailComponents / hardRailAdjacency semantic path reconstruction
SelectedRelationPathCertificate is producer-published and consumer-validated
```

This is static evidence only; do not compile or invoke a generated binary for inspection.

## 4. Postflight

After all planned runtime:

1. repeat package/source/execution-view byte+mode censuses and require exact equality to preflight;
2. re-run package root `SHA256SUMS` verification and require **28/28**;
3. verify selector430 digest and bytes unchanged;
4. record counters proving configure/compile/relink/generated-discovery/package-repair/mode-repair/source/test/fixture/selector mutation and benchmark execution are all zero.

## 5. Evidence to preserve

Preserve at minimum:

- exact package ID/digest, source SHA, manifest and packaged-source digests;
- workflow run/job IDs and immutable harness digest;
- one process-ledger row per focused and selector identity with identity, routed binary, selection count, pass/fail/skip, exit state and raw-log SHA-256;
- focused non-vacuity receipts for relation-owner/periodic-edge multiplicity;
- static CP1 source-audit receipt;
- pre/post byte+mode census and package-manifest results;
- result and diagnostic artifacts with self-verifying manifests.

## 6. Stop rules

- Focused RED is semantic RED; preserve evidence and continue to selector430 only if the runtime plan explicitly records complete-gate execution as independent of focused success. Do not repair/rebuild in TB.
- Any artifact identity/integrity/mode/source mismatch, zero-selection, multiple-selection, skip, generated discovery, configure/compile/relink, package repair or mutation is orchestration failure and blocks semantic credit.
- Do not rerun an unchanged semantic failure. Runtime correction belongs to a later Code + Build turn.
- No M5 production debt closes from these direct/helper mechanism tests. CP3 direct-production evidence remains mandatory.

## 7. Benchmark plan

No performance benchmark is required for CP1. Benchmark execution count must remain zero. This checkpoint validates semantic identity/certificate behavior and accepted-regression preservation only.

## 8. Completion criteria

TB1-EXEC is mechanically green only if focused **9/9** and selector430 **430/430** satisfy all selection/pass constraints and immutable postflight is exact. Promotion/next-checkpoint decisions are not inferred from this plan; they are made by the project cadence after the complete evidence set is recorded.
