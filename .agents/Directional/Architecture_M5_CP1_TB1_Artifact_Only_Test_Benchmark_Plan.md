# M5-CP1-TB1-R1 Corrected Artifact-Only Test + Benchmark Plan

**Turn:** `M5-CP1-TB1-R1-EXEC`
**Milestone/checkpoint:** M5 / CP1
**Mode:** Test + Benchmark / immutable artifact-only
**Evidence commit:** `b98f461b9a392cc182891a81c0a84b0b01dfbb45`
**Candidate build artifact:** `10595705100` (`directional-m5-cp1-cb1-result-35478855426`)
**Candidate artifact SHA-256:** `fdc4046630c6f48b2bc76aad74ebc07b443a024fc9cfd76507bae515eb8668ea`
**Accepted M4 routing artifact:** `10592987234`, ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`
**Review authority:** `Architecture_M5_CP1_TB1_Preflight_Review_Record.md`

## 1. Objective

Execute the bounded M5-CP1 mechanism introduced by CB1 on the unchanged immutable candidate while preserving accepted M4 selector430 exactly. This is the corrected retry of the pre-runtime-blocked TB1 plan. CP1 credit is **mechanism-only**: no M5 direct-production debt closes in this turn.

The runtime questions are unchanged:

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
6. From the packaged source verify `Architecture_M4_CP4_CB8_Required_Green_Selector_430.txt` is exactly **430 LF rows / SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`** and its first427 rows hash to accepted selector427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.
7. Reuse the accepted M4-TB3 identity-to-owner routing authority from artifact `10592987234`; verify its downloaded ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`, then verify `identity-map.tsv` is header + **430** data rows with **430 unique identities**, owner census **31 / 283 / 75 / 41**, and SHA-256 **`7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`**. Do not generate test discovery.
8. From immutable packaged source confirm the ninth focused identity below exists exactly once as a compiled test definition and the former `M4CP4.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` identity does not exist.
9. Capture a byte+mode census of the immutable package, packaged source and execution view for postflight comparison.

Any mismatch stops execution as orchestration/infrastructure failure and receives zero semantic credit. Do not silently substitute a different digest, suite, artifact, or test identity.

## 3. Ordered runtime execution

Every test identity below runs in a **fresh process** with an exact `--gtest_filter=<identity>` against packaged binaries only. Require exactly one selected test, zero skip, exit 0 and one PASS. No `--gtest_list_tests`, discovery, rebuild or fallback is permitted.

### A. Focused CP1 mechanism gate

Run from `bin/directional_surface_cell_producer_tests`, in this exact order:

```text
SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator
SurfaceCellsPhase10.PeriodicHolonomyDistinctTopologyRegionsRetainEveryRelation
SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained
SurfaceCellsPhase10.PeriodicHolonomyConflictingTransportFailsClosed
M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap
M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation
M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate
M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation
SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization
```

Acceptance: **9/9 PASS**, exact-one selection, zero skip/crash/timeout/invalid-selection.

For row 9, preserve the original discriminator: require at least **2 distinct canonical periodic relation owners and 2 owned periodic edges** before reorder. The packaged body uses `direct_periodic_owner_product()` and is therefore **CP1 mechanism-only** under `Architecture_M5_Frozen_Definitions.md` §8.1. A green row 9 **does not discharge** `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`; M5-CP3 still requires the same discriminator on produced authority.

### B. Accepted predecessor gate

Run all 430 rows of `Architecture_M4_CP4_CB8_Required_Green_Selector_430.txt` in exact file order, each as one fresh exact-filter process routed by the independently verified accepted M4 identity map.

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
3. verify selector430 and accepted M4 routing-map bytes/digests unchanged;
4. record counters proving configure/compile/relink/generated-discovery/package-repair/mode-repair/source/test/fixture/selector mutation and benchmark execution are all zero.

## 5. Evidence to preserve

Preserve at minimum:

- exact candidate package ID/digest, source SHA, manifest and packaged-source digests;
- accepted M4 routing artifact ID/digest and independently verified identity-map digest/census;
- workflow run/job IDs and immutable harness digest;
- one process-ledger row per focused and selector identity with identity, routed binary, selection count, pass/fail/skip, exit state and raw-log SHA-256;
- row9 relation-owner/periodic-edge multiplicity receipts, explicitly labelled direct-helper mechanism evidence;
- static CP1 source-audit receipt;
- pre/post byte+mode census and package-manifest results;
- result and diagnostic artifacts with self-verifying manifests.

## 6. Stop rules

- Focused RED is semantic RED; preserve evidence and continue to selector430 only if the runtime harness records complete-gate execution as independent of focused success. Do not repair/rebuild in TB.
- Any artifact identity/integrity/mode/source/routing-map mismatch, zero-selection, multiple-selection, skip, generated discovery, configure/compile/relink, package repair or mutation is orchestration failure and blocks semantic credit.
- If either corrected preflight literal fails its independent check, stop; do not make a second plan repair inside EXEC.
- Do not rerun an unchanged semantic failure. Runtime correction belongs to a later Code + Build turn.
- No M5 production debt closes from these direct/helper mechanism tests. CP3 direct-production evidence remains mandatory.

## 7. Benchmark plan

No performance benchmark is required for CP1. Benchmark execution count must remain zero. This checkpoint validates semantic identity/certificate behavior and accepted-regression preservation only.

## 8. Completion criteria and successor boundary

R1-EXEC is mechanically green only if focused **9/9** and selector430 **430/430** satisfy all selection/pass constraints and immutable postflight is exact. Candidate promotion and CP1 semantic acceptance require the normal independent Review cadence after the complete evidence set is recorded; EXEC does not self-promote.

A green direct-helper row 9 may close **CP1 mechanism** evidence only. The M5-CP3 produced-witness debt remains open until a produced subject independently satisfies the original `>=2` produced-relation / `>=2` owned-periodic-edge discriminator.
