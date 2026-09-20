# M5-CP1-TB1-R2 Artifact-Only Test + Benchmark Plan

**Turn:** `M5-CP1-TB1-R2-EXEC`
**Milestone/checkpoint:** M5 / CP1
**Mode:** Test + Benchmark / immutable artifact-only
**Semantic source:** `b98f461b9a392cc182891a81c0a84b0b01dfbb45`
**Candidate build artifact:** `10595705100`
**Routing authority:** `10592987234`
**Control-plane authority:** `Architecture_M5_CP1_CB2_Orchestration_Correction_Report.md`

## 1. Objective

Execute the unchanged M5-CP1 mechanism gate on the unchanged immutable CB1 candidate using the CB2-proved canonical executor. R2 is a **fresh execution turn**, not an in-place R1 retry. R1 contributes zero process rows and zero semantic credit.

CP1 credit remains mechanism-only. No M5 direct-production debt closes in this turn.

## 2. Frozen executor authority

Before runtime, install `.agents/Directional/tools/m5_cp1_tb1_r2_executor.yml` **verbatim** as `.github/workflows/m5-cp1-tb1-r2-exec.yml`. The source template SHA-256 and installed workflow SHA-256 must both equal:

`9c9c2527176645d143cf1f972ad5d493db44bc819179fb04a1845f7bd20a12a1`

The workflow must pass the durable SchemaStore validator before runtime. Do not edit the reusable workflow permissions. Install the caller first with the trigger marker absent; only after caller/schema authority is established may `.agents/connector-triggers/m5-cp1-tb1-r2-exec-20260920.txt` be created.

The runtime must execute canonical harness:

`.agents/Directional/tools/m5_cp1_tb1_r2_artifact_only_harness.sh`

with SHA-256:

`b706d03adde7d7d3daacb6ac46c4cb35468a40e162d7fb9d1617d4e562d37302`

Require `bash -n` and exact SHA equality before invoking `--execute`. Do not embed, regenerate, hand-transcribe, or substitute a GZip/Base64 payload. No timeout/watchdog may be added.

CB2 proof authority is final static-validation run `35490228347`, including caller/template schema success and static-proof artifact `10598826679` (`d765ed4d54b07f130e83f44dd499d61584e6dab1693b32db9472d14004b05b2d`).

## 3. Immutable package/routing preflight

The canonical harness must independently enforce all of the following before a Directional process starts:

1. candidate artifact `10595705100`, provider/download SHA-256 `fdc4046630c6f48b2bc76aad74ebc07b443a024fc9cfd76507bae515eb8668ea`;
2. candidate root `SHA256SUMS` SHA-256 `8330461b8c5e489059e2ec320cb2e2d5243d6ef36dc01b667b5cefc09f609a3d`, **28/28** verified;
3. semantic source `b98f461b9a392cc182891a81c0a84b0b01dfbb45`, source archive SHA-256 `4f51257db12ae24363a45ddfa62778200e9ac0a8ef4ce2b585c8c606350d78b9`, clean receipts, `runtimeExecution=false`, GMP/GMPXX evidence;
4. selector430 exactly **430 LF rows**, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
5. routing artifact `10592987234`, ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`;
6. `identity-map.tsv` header + **430 rows / 430 unique**, SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`, owner census **31 / 283 / 75 / 41**;
7. all required packaged test binaries retain executable mode; package/source/execution-view byte+mode censuses are captured;
8. the nine focused definitions resolve exactly once in immutable packaged source and the superseded `M4CP4...PeriodicRelationOwners...` identity resolves zero times;
9. the source-side CP1 audit is clean: no production `PeriodicRelationId::from_index(...)`, no periodic-relation offset remapping, no verifier-side hard-rail semantic path reconstruction, and `SelectedRelationPathCertificate` remains producer-published / consumer-validated.

Any mismatch is orchestration failure with zero semantic credit. No package repair, mode repair, fallback package, generated discovery, configure, compile, relink, source/test/fixture/selector mutation, or silent literal repair is authorized.

## 4. Ordered focused gate

Run exactly these nine identities from `directional_surface_cell_producer_tests`, in this order, one fresh process each with exact `--gtest_filter` and `GTEST_FAIL_IF_NO_TEST_SELECTED=1`:

1. `SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator`
2. `SurfaceCellsPhase10.PeriodicHolonomyDistinctTopologyRegionsRetainEveryRelation`
3. `SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained`
4. `SurfaceCellsPhase10.PeriodicHolonomyConflictingTransportFailsClosed`
5. `M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap`
6. `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation`
7. `M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate`
8. `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation`
9. `SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`

Require exactly one selected test and zero skips for every row. A process is PASS only on exit 0 with exactly one `[       OK ]` row. Semantic RED is recorded as RED and does not authorize repair. The complete selector gate still runs when focused rows are semantic RED, provided orchestration/selection integrity remains valid.

Row 9 retains the original `>=2` canonical relation-owner / `>=2` owned-periodic-edge discriminator but uses `direct_periodic_owner_product()`. It is therefore **CP1 mechanism-only / no produced-witness credit**. M5-CP3 still owns the produced-authority proof.

## 5. Accepted predecessor gate

Run all **430** rows from the frozen selector in exact file order, each in a fresh exact-filter process routed only by the accepted M4 identity map. Require exactly one selection and zero skips per row. Preserve a row ledger including identity, routed binary, exit state, selected/skipped/passed counts, semantic PASS/RED, and raw-log SHA-256.

Accepted owner census remains **31 / 283 / 75 / 41**. Focused results never substitute for selector rows; no R1 process row is imported.

## 6. Postflight and evidence

After planned runtime:

- repeat package/source/execution-view byte+mode censuses and require exact equality;
- re-run root candidate manifest and require **28/28**;
- require selector430 and routing-map digests unchanged;
- record that configure/compile/relink/discovery/package-repair/mode-repair/source-test-fixture-selector mutation are all false;
- record benchmark execution **0**;
- preserve focused and selector ledgers, raw log hashes, row9 direct-helper discriminator receipt, source audit, authority receipts, postflight receipts, and self-verifying result/log artifacts.

The execution report must distinguish semantic RED from orchestration failure. A zero-selection, multi-selection, skip, artifact/path/hash/mode mismatch, mutation, or incomplete planned gate is orchestration failure and receives no semantic promotion credit.

## 7. Completion and successor boundary

R2 is mechanically green only if the full planned gate executes with selection integrity, focused **9/9 PASS**, selector430 **430/430 PASS**, and exact postflight. Any complete semantic result is recorded without self-repair. Candidate promotion and CP1 acceptance require the normal independent Review cadence after complete evidence exists; EXEC does not self-promote.

No benchmark is authorized. No M5 production debt closes from direct/helper mechanism evidence.
