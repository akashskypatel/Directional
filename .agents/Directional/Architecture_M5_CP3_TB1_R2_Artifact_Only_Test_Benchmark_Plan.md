# M5-CP3-TB1-R2 Artifact-Only Test + Benchmark Plan

## Validation Identity

- Phase: `M5-CP3-TB1-R2-EXEC`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Evidence commit to validate: `279efa03471f1e0d6c32f57c8b395dd1cb1a93f5`
- Candidate build artifact: `10620415471` (`m5-cp3-cb3-result-35555882867`)
- Candidate artifact SHA-256: `700b605167427d21823b90d942dd5bb40d1690f162285d22a20da5ad7898a1cd`
- Candidate root `SHA256SUMS`: 28 entries, file SHA-256 `ea12d6fc6ab6752f8ef10f46f1900423e9074e62c25edba48bde5b4526623d24`
- Candidate packaged source archive SHA-256: `198a6454bb3171a863be571b91ec861d1161dbab608d3114a86032ee40dc2f00`
- Build diagnostic artifact: `10620265598`, SHA-256 `a82f4871d40c6957f3df22f7a5d7d26b6c32a258e886c9bea09d26a04f178b14`
- Accepted selector routing authority: M4 TB3 artifact `10592987234`, ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`, `identity-map.tsv` SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`
- Selector430 SHA-256: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`
- Selector first427 SHA-256: `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`
- Planned environment/platform: GitHub Actions `ubuntu-24.04`, artifact-only; no checkout-built Directional binary may execute
- Mandatory successor after mechanically complete execution: `M5-CP3-TB1-R2-REV`

## Frozen-Literal Provenance Check

This plan obeys `M5-CP3-TB1-REV-OBS-01`: every SHA-256 literal above is exactly 64 hexadecimal characters and the semantic git commit is exactly 40 hexadecimal characters. Existing routing/selector literals are copied verbatim from the durable accepted M4/M5 records; candidate package literals are copied from the verified CB3 compile package and provider artifact metadata. Do not re-type or substitute these values during execution.

## Corrected Candidate Authority

CB3 changed only `src/geometry/SurfaceCellTracing.cpp` at semantic source `279efa03471f1e0d6c32f57c8b395dd1cb1a93f5`. The whole-region path-independent branch-rotation reconstruction used by the R1 candidate has been removed from same-region periodic promotion. Generator carrier and transport now derive from the exact A3 `span` source path and existing directed `FieldTransportAtlas` authority; no test, fixture, selector, frozen definition, CP2 failure contract or cross-region HardRail behavior changed.

The mandatory GMP compile/package is green on run/job `35555882867 / 106199345527`; artifact `10620415471` contains all eight standard targets, root manifest **28/28**, empty source-status receipts, explicit GMP/GMPXX linkage and `runtimeExecution=false`. This R2 execution is the first runtime proof of the correction. **No R1 semantic credit is reused.**

## Validation Objective

Prove the CB3 candidate at runtime without rebuilding or repairing it:

1. all nine already-reviewed M5 mechanism identities remain green;
2. all six frozen `M5CP3.Produced...` identities execute on produced torus authority and are green;
3. accepted selector430 remains completely green, including ordinal408;
4. every exact-filter process selects exactly one test and reports zero skips;
5. the immutable candidate package, packaged source and execution view are byte/mode identical before and after runtime;
6. no benchmark, configure, compile, relink, generated discovery, package repair or source/test/fixture/selector mutation occurs.

A green R2 is pre-publication evidence only. Candidate promotion, produced-debt credit and selector-publication precommitment belong to independent `M5-CP3-TB1-R2-REV`. A semantic RED after valid preflight is preserved as evidence and still routes to that Review.

## Preconditions

- Download artifact `10620415471` and verify provider/download ZIP SHA-256 exactly `700b605167427d21823b90d942dd5bb40d1690f162285d22a20da5ad7898a1cd`.
- Extract with ordinary `unzip` or another mode-preserving extractor. Do **not** use Python `zipfile.extractall` for executable payloads, do not `chmod`, and do not repair package bytes/modes. Missing executable mode is orchestration failure.
- Verify candidate root `SHA256SUMS` hashes to `ea12d6fc6ab6752f8ef10f46f1900423e9074e62c25edba48bde5b4526623d24` and verifies all **28/28** entries.
- Verify `metadata/source-commit.txt` equals `279efa03471f1e0d6c32f57c8b395dd1cb1a93f5`, build/preflight exits are `0`, all source-status receipts are empty, and `metadata/command-boundary.txt` contains `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and `preflightCompile=true`.
- Verify GMP evidence contains both `gmpxx` and `gmp` and the authoritative generated link command.
- Verify packaged source archive SHA-256 exactly `198a6454bb3171a863be571b91ec861d1161dbab608d3114a86032ee40dc2f00`, then extract that archive read-only for selector/source authority.
- Verify selector `.agents/Directional/Architecture_M4_CP4_CB8_Required_Green_Selector_430.txt` is exactly **430 LF-terminated rows**, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; its exact first 427 LF rows hash to `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.
- Reuse accepted routing artifact `10592987234`; verify ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce` and `identity-map.tsv` SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`, 430 unique selector identities, exact ordinals 1..430, and owner census **31 authority-kernel / 283 producer / 75 completion / 41 validation**.
- Independently map each of the 15 focused identities from packaged source/CMake ownership and require exactly one owner executable; do not use generated Directional discovery.
- Capture byte+mode censuses of the immutable package tree, extracted source tree and a separate execution view before runtime.

Required package executables are `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, and `directional_surface_cell_validation_tests`. Compiled API/benchmark binaries may be present but the benchmark binary must not execute.

## Ordered Execution Plan

Every semantic row is a **fresh process** using the routed packaged executable and exact `--gtest_filter=<identity>`. For every process record command, start/end time, exit code, raw stdout/stderr, selected count, pass/fail/skip state, executable SHA-256 and resource measurement. Require selected count exactly 1 and skip count 0; zero or multiple selected tests is orchestration failure, never PASS.

### 1. Nine reviewed mechanism rows — exact order

1. `SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator`
2. `SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained`
3. `M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap`
4. `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation`
5. `M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate`
6. `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation`
7. `SurfacePhaseFrontProductFactoryAuthority.ConflictingPeriodicRelationValueRejectsAtCheckedFactory`
8. `SurfacePhaseFrontProductFactoryAuthority.NonReciprocalPeriodicRelationRejectsAtCheckedFactory`
9. `SurfacePhaseFrontProductFactoryAuthority.RepresentationRenumberedPeriodicRelationRejectsAtCheckedFactory`

Acceptance criterion: **9/9 PASS**, each selected exactly once, zero skips.

### 2. Six produced rows — exact order

1. `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges`
2. `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate`
3. `M5CP3.ProducedTorusMissingPeriodicRelationOwnerRejectsTyped`
4. `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`
5. `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`
6. `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`

Acceptance criterion: **6/6 PASS**, each selected exactly once, zero skips. Positive preconditions must derive from the production path; the runtime harness must not inject or repair relation authority.

### 3. Accepted selector430 — exact file order

Execute all 430 selector rows in exact LF file order from packaged source, one fresh routed process per row.

Acceptance criterion: **430/430 PASS**, exact-one selection, zero skips, execution owner census exactly **31 / 283 / 75 / 41**.

### 4. Immutable postflight

After the final selector process:

- recompute package, source and execution-view byte+mode censuses and require exact equality to preflight;
- re-run candidate root `sha256sum -c SHA256SUMS` and require **28/28**;
- re-hash selector430 and first427 and require the frozen values;
- assert counters for configure, compile, relink, generated discovery, package repair, mode repair, source/test/fixture/selector mutation and benchmark execution are all zero.

## Semantic-RED Continuation Rule

Once preflight is valid and semantic execution begins, an ordinary GoogleTest assertion failure is semantic evidence, not orchestration permission to repair the artifact. Preserve it and continue through the remaining planned identities/selector rows unless the failure corrupts the execution environment or makes exact-one/immutability evidence untrustworthy. No same-turn source/test repair or rebuild is allowed.

## Benchmark Plan

- Applicable: no.
- Benchmark executions: exactly **0**.
- `directional_benchmarks` is compile-coverage evidence only and must not be invoked.

## Stop and Blocker Conditions

Stop before semantic runtime and preserve evidence if any of these fail:

- candidate artifact/provider/download digest or root manifest;
- source commit/archive identity;
- executable archived mode;
- GMP/build-boundary receipt;
- selector430/first427 bytes or row count;
- accepted routing artifact/hash/owner census;
- exact focused identity ownership;
- preflight package/source/execution-view census.

Also stop if continuing would require `chmod`, package repair, configure, compile, relink, generated test discovery, fixture/source/test/selector mutation, benchmark execution, or a substituted artifact. Such a result is orchestration failure with zero semantic credit.

A semantic RED after valid preflight is **not** a blocker for completing the frozen evidence sweep and does not authorize repair. Record it and route the complete evidence to Review.

## Plan-Defined Reruns

- No retry for semantic failure.
- No repeated run merely to seek a green outcome.
- A fresh execution may be authorized only for diagnosed orchestration/infrastructure failure that produced no valid semantic credit, and it must restart from process 1 on the same immutable artifact unless Review explicitly changes authority.
- No random seeds/order permutations are authorized; row order is exactly the frozen 9 + 6 + selector430 sequence.

## Completion Criteria

The execution plan is mechanically complete when:

- preflight is exact and immutable;
- all **445** planned fresh processes are attempted under the semantic-RED continuation rule: 9 mechanism + 6 produced + 430 selector;
- every process has exact-one/zero-skip accounting or a preserved semantic RED;
- benchmark count is 0;
- immutable postflight is exact;
- raw per-process evidence, summaries, resource receipts and pre/post hashes are packaged with a self-excluding manifest;
- `M5-CP3-TB1-R2-REV` can independently adjudicate correction recovery, every production debt and the publication precommitment obligation without reconstructing intent from chat.

A fully green result is **445/445 PASS** and routes to `M5-CP3-TB1-R2-REV`. A semantically red but mechanically complete run also routes to that Review; it does not return directly to implementation.
