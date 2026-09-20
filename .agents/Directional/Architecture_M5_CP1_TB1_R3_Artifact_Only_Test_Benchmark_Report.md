# M5-CP1-TB1-R3 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP1-TB1-R3-EXEC`
**Disposition:** **COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED**
**Candidate:** artifact `10600353027` / source `8a86710dd33d7b6cb9a077aef738577e4075b5f7`
**Accepted runtime authority after EXEC:** unchanged pending mandatory Review; M4 package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430** remains accepted.
**Exact successor:** `M5-CP1-TB1-R3-REV`

## 1. Outcome

R3 is mechanically green: focused **9/9 PASS**, selector430 **430/430 PASS**, exact-one selection / zero skips across all **439** fresh processes, benchmark execution **0**, and exact immutable postflight. The corrected row6 pure-permutation witness now reaches both materializations and the complete comparison surface without failure. This is runtime evidence that the CB3 test-authority correction is behaviorally valid; candidate promotion and CP1 acceptance remain Review-owned.

The first trigger attempt, run `35496056165` at event SHA `31a6821803e0bb90bc0bd4cefc88842dde399f53`, was a **pre-runtime orchestration startup failure / zero semantic credit**: the temporary caller referenced `runner.temp` from job-level `env`, so no jobs were instantiated. The caller was corrected in a separate commit by moving that runner-scoped expression to step-level `env`; retry `35496133258` then self-validated against the mandatory SchemaStore reusable before runtime. No Directional binary executed in the failed attempt.

## 2. Immutable candidate authority

- compile/package run/job: `35494880046 / 106036002599`;
- candidate artifact: `10600353027`;
- provider/download ZIP SHA-256: `cdc0cb798e6b117727ddde0dbfa5008d2a8140c709eeafb0af66872c5c7ae6b0`;
- exact compiled source: `8a86710dd33d7b6cb9a077aef738577e4075b5f7`;
- root manifest: **28/28**, SHA-256 `242b323811a9960a89c723ab04da17cf39449c8d42d2f97947f75f405c6347ff`;
- packaged source archive SHA-256: `594dad05c7078c0c5b2e03486f408ca6621e2c36875873fa045803245497352d`;
- build/preflight exits: **0 / 0**;
- source-status receipts: empty;
- command boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `preflightCompile=true`;
- GMP evidence: `DIRECTIONAL_ENABLE_GMP=ON` with explicit `gmpxx` + `gmp` linkage;
- selector430: **430 LF rows**, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- first427 prefix SHA-256: `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- routing authority: accepted M4 artifact `10592987234`, provider ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`, identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`, owners **31 / 283 / 75 / 41**.

The packaged row6 source is the frozen CB3 witness: it appends a distinct valid second relation, copies identical membership, proves reversal nontrivial, reverses only the copy, materializes both, and compares full selected-certificate signatures, `hash_completion(...)`, and consumed periodic-relation counts.

## 3. Execution authority

- authoritative run/job: `35496133258 / 106039321958`;
- event/control SHA: `f316b0b55baa9c63827581b5e6d54718abd93923`;
- canonical R2 harness input SHA-256: `b706d03adde7d7d3daacb6ac46c4cb35468a40e162d7fb9d1617d4e562d37302`;
- deterministic R3 harness SHA-256 after the five frozen candidate-authority substitutions: `55b451366039673f383d4d8636ba84744c828381493597bf9e24fb92e455788c`;
- result artifact: `10601350461`, provider ZIP SHA-256 `50584a8999581efb2c20c28e920dd3227c92f2cfa5ceb5dba3b9e47ac0ecf60f`;
- diagnostic artifact: `10601380504`, provider ZIP SHA-256 `13110158efb5359c5b338faba6801e15fa6f902663f7dbc6ffe960d382ce6f2c`;
- focused ledger SHA-256: `7ee492b7712f10928d845b40ef03606b5c72898dac7268f45d649320eb76f74e`;
- selector ledger SHA-256: `b88ae9243e1fe8f1a216421d33e91e2205bd1e410ebfd9af57b3cfb525301b34`.

The execution workflow had no elapsed-time watchdog for the complete gate. Every focused and selector identity ran as one fresh exact-filter process.

## 4. Focused gate

| Ordinal | Identity | Result |
|---:|---|---|
| 1 | `SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator` | **PASS** |
| 2 | `SurfaceCellsPhase10.PeriodicHolonomyDistinctTopologyRegionsRetainEveryRelation` | **PASS** |
| 3 | `SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained` | **PASS** |
| 4 | `SurfaceCellsPhase10.PeriodicHolonomyConflictingTransportFailsClosed` | **PASS** |
| 5 | `M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap` | **PASS** |
| 6 | `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation` | **PASS** |
| 7 | `M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate` | **PASS** |
| 8 | `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation` | **PASS** |
| 9 | `SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` | **PASS** |


Focused total: **9/9 PASS / 0 RED**. Every process selected exactly one test and skipped zero.

## 5. Accepted selector gate

Selector430: **430/430 PASS / 0 RED**, exact-one selected and zero skipped for all 430 fresh processes. RED ordinals: `[]`.

Benchmark execution count is exactly **0**.

## 6. Immutable postflight and boundary proof

R3 records exact equality of candidate-package, packaged-source, and execution-view byte+mode censuses before/after runtime. Selector and routing-map bytes remain unchanged, and the candidate root manifest verifies **28/28** again after execution. The execution boundary records no configure, compile, relink, generated discovery, package repair, mode repair, source/test/fixture/selector mutation, or benchmark execution.

## 7. Regression classification and accounting

No semantic RED was observed. `M5-CP1-TB1-R2-REV-OBS-01` is **RUNTIME FALSIFIER PASSED**: the corrected identical-membership/storage-order-only row6 witness is green. No new product regression candidate is created.

The initial caller failure is classified separately as `M5-CP1-TB1-R3-EXEC-OBS-01`: **CLOSED / ORCHESTRATION / RUNNER-CONTEXT SCOPE / NON-STABLE / RECOVERY PROVED**. It executed zero Directional binaries and therefore adds **+0 event / +0 category / +0 recurrence**.

Stable accounting remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**. Candidate `10600353027` is unpromoted; accepted M4 runtime authority remains unchanged. Row6 and row9 remain mechanism/direct-helper evidence only and discharge no produced-witness debt.

## 8. Successor boundary

`M5-CP1-TB1-R3-EXEC` is **COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED**. Exact next is runtime-free independent **`M5-CP1-TB1-R3-REV`**. Review must independently reopen the immutable R3 result/log evidence and candidate source, adjudicate the corrected row6 falsifier, decide candidate promotion/CP1 acceptance, and preserve the frozen production-credit boundary. No Code + Build work is authorized before Review.
