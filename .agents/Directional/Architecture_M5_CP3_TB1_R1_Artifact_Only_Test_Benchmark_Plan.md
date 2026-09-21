# M5-CP3-TB1-R1 Artifact-Only Test + Benchmark Plan

## Validation Identity

- Phase: `M5-CP3-TB1-R1-EXEC`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Evidence commit to validate: `fc2aa5fa68cac890051614c2104979aef4a60d21`
- Candidate build artifact: `10615252806` (`m5-cp3-cb2-result-35542532109`)
- Candidate artifact SHA-256: `1e32fa2b55f84b9097b0d617bcfc1b5f7ad1ab7e5ffc2bdb8e0cde8ea715bf20`
- Candidate root `SHA256SUMS`: 28 entries, file SHA-256 `322b04df9767a80bc246b4b0a03886cc6abb118b8e13147ed8fa1126de74a7c1`
- Candidate packaged source archive SHA-256: `6fe16061079b01079bc53006f102575a5452a950b663807b4f278949ff3ef967`
- Build diagnostic artifact: `10614394740`, SHA-256 `91e768f1f0ecd36f00dd75ce3c5378ed012d1b4a3a521d1059528118eeedffde`
- Accepted selector routing authority: M4 TB3 artifact `10592987234`, ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`, `identity-map.tsv` SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`
- Planned environment/platform: GitHub Actions `ubuntu-24.04`, artifact-only; no checkout-built Directional binary may execute

## Review-Corrected Execution Authority

`M5-CP3-TB1-REV` independently re-opened routing artifact `10592987234` rather than repairing the predecessor executor in place. The frozen predecessor plan contained a **62-character** routing ZIP literal. The live GitHub provider digest, a fresh downloaded copy of artifact `10592987234`, and the accepted M4-TB3 durable reports all agree on the exact **64-character** SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`. The downloaded artifact's `identity-map.tsv` independently hashes to `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`, contains 430 unique identities with ordinals 1..430, and has owner census **31 / 283 / 75 / 41**.

This R1 plan changes **only** the routing ZIP authority literal and the execution/review turn names required for a fresh retry. Candidate artifact/source, candidate/package hashes, the nine mechanism identities, six produced identities, selector430 bytes/order/hash, first427 prefix hash, routing identity-map hash, owner census, exact-one/zero-skip requirements, immutability checks, semantic-RED continuation rule, benchmark count **0**, and all credit/promotion boundaries are unchanged. No evidence from the blocked predecessor attempts is imported as semantic credit. R1 restarts at process **1** and must execute all **445** planned semantic processes if preflight succeeds.

## Validation Objective

Prove the CB2 candidate at runtime without rebuilding or repairing it:

1. all nine already-reviewed M5 mechanism identities remain green;
2. all six new `M5CP3.Produced...` identities execute on the produced torus authority and are green;
3. accepted selector430 remains completely green with the evolved row408;
4. every exact-filter process selects exactly one test and reports zero skips;
5. the immutable candidate package, packaged source and execution view are byte/mode identical before and after runtime;
6. no benchmark, configure, compile, relink, generated discovery, package repair or source/test/fixture/selector mutation occurs.

A green TB execution is pre-publication evidence only. It does not itself discharge the four M5 produced debts, promote the candidate, or authorize selector publication; all such judgments belong to `M5-CP3-TB1-R1-REV`.

## Preconditions

- Download artifact `10615252806` and verify the provider digest and downloaded ZIP SHA-256 are exactly `1e32fa2b55f84b9097b0d617bcfc1b5f7ad1ab7e5ffc2bdb8e0cde8ea715bf20`.
- Extract with ordinary `unzip` (or another mode-preserving extractor). **Do not use Python `zipfile.extractall` for executable payloads, do not `chmod`, and do not repair package bytes/modes.** A missing executable bit is orchestration failure.
- Verify candidate root `SHA256SUMS` is exactly the expected file hash and verifies all 28 entries.
- Verify `metadata/source-commit.txt` equals `fc2aa5fa68cac890051614c2104979aef4a60d21`, build/preflight exits are `0`, all source-status receipts are empty, and `metadata/command-boundary.txt` contains `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and `preflightCompile=true`.
- Verify GMP evidence contains both `gmpxx` and `gmp` and the authoritative generated link command.
- Verify packaged source archive name/hash exactly match the validation identity above, then extract that archive read-only for selector/source authority.
- Verify selector `.agents/Directional/Architecture_M4_CP4_CB8_Required_Green_Selector_430.txt` is exactly 430 LF-terminated rows, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; its first 427 LF rows hash to `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.
- Reuse accepted routing artifact `10592987234`; verify its ZIP and identity-map hashes above, 430 unique selector identities, exact ordinals 1..430, owner census **31 authority-kernel / 283 producer / 75 completion / 41 validation**, and each routed package executable exists with archived executable mode intact.
- Independently map each of the 15 focused identities from packaged source/CMake ownership and require exactly one owner executable; do not use a generated Directional discovery command.
- Capture byte+mode censuses of the immutable package tree, extracted source tree and a separate execution view before runtime.

Required package executables are the packaged `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, and `directional_surface_cell_validation_tests`. The package also contains compiled API/benchmark binaries, but the benchmark binary must not execute.

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

Purpose: re-prove reviewed CP1/CP2 mechanism authority outside selector430 after CB2 changes.

Acceptance criterion: **9/9 PASS**, each selected exactly once, zero skips.

### 2. Six produced rows — exact order

1. `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges`
2. `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate`
3. `M5CP3.ProducedTorusMissingPeriodicRelationOwnerRejectsTyped`
4. `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`
5. `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`
6. `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`

Purpose: execute the exact production witnesses frozen by the reviewed CB2 plan, including the `>=2` produced relation/owned-edge discriminator, storage permutation invariance, typed missing-owner rejection, genuine nonzero-Z4 rotation+translation materialization, frozen one-fact transform tamper rejection, and unused-valid-relation decision neutrality.

Acceptance criterion: **6/6 PASS**, each selected exactly once, zero skips. These rows must derive their positive preconditions from the production path; no runtime harness may inject or repair relation authority.

### 3. Accepted selector430 — exact file order

Execute all 430 selector rows in the exact LF file order from the packaged source, one fresh routed process per row.

Purpose: re-prove the complete accepted pre-publication prefix, including evolved row408, without changing selector bytes.

Acceptance criterion: **430/430 PASS**, exact-one selection, zero skips, execution owner census exactly **31 / 283 / 75 / 41**.

### 4. Immutable postflight

After the final selector process:

- recompute package, source and execution-view byte+mode censuses and require exact equality to preflight;
- re-run candidate root `sha256sum -c SHA256SUMS` and require 28/28;
- re-hash selector430 and first427 and require the frozen values;
- assert counters for configure, compile, relink, generated discovery, package repair, mode repair, source/test/fixture/selector mutation and benchmark execution are all zero.

## Semantic-RED Continuation Rule

Once preflight is valid and semantic execution begins, an ordinary GoogleTest assertion failure is semantic evidence, not orchestration permission to repair the artifact. Preserve it and continue through the remaining planned identities/selector rows so Review receives the complete frozen gate, unless the process failure corrupts the execution environment or makes exact-one/immutability evidence untrustworthy. No same-turn source/test repair or rebuild is allowed.

## Benchmark Plan

- Applicable: no.
- Benchmark executions: exactly **0**.
- The packaged `directional_benchmarks` binary is evidence of compile coverage only and must not be invoked.

## Unit-Test Design Check

- Contract under test: exact canonical periodic relation ownership, selected-certificate decision semantics and typed fail-closed relation validation on produced row408-class authority.
- Scenario/boundary represented: same-region A3 paired cut copies promoted to exact owned `PeriodicCut` relations while preserving A3 provenance; cross-region HardRail remains outside the promoted case.
- Why fixture values expose plausible broken behavior: the produced torus must provide one source region, at least two distinct canonical relations/owned periodic edges and a genuinely nonzero-Z4 rotation+translation relation; these discriminate against direct-helper substitution, single-owner collapse and identity/order shortcuts.
- Isolation/test-double rationale: positive authority comes from the production fixture/path; negative rows clone a produced valid product and mutate exactly one named fact.
- Assertion semantics: independent carrier-content identity checks, reciprocal occurrence/route checks, complete selected-certificate signatures, completion semantic hash, consumed relation semantics and exact typed CP2 rejection.

## Stop and Blocker Conditions

Stop before semantic runtime and preserve evidence if any of these fail:

- artifact/provider/download digest or root manifest;
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
- A fresh execution may be authorized only for a diagnosed orchestration/infrastructure failure that produced no valid semantic credit, and it must restart from process 1 on the same immutable artifact unless Review explicitly changes authority.
- No random seeds/order permutations are authorized; row order is exactly the frozen 9 + 6 + selector430 sequence.

## Completion Criteria

The execution plan is mechanically complete when:

- preflight is exact and immutable;
- all **445** planned fresh processes are attempted under the semantic-RED continuation rule: 9 mechanism + 6 produced + 430 selector;
- every process has exact-one/zero-skip accounting or a preserved semantic RED;
- benchmark count is 0;
- immutable postflight is exact;
- raw per-process evidence, summaries, resource receipts and pre/post hashes are packaged with a self-excluding manifest;
- `M5-CP3-TB1-R1-REV` can independently adjudicate every production debt and the publication precommitment obligation without reconstructing intent from chat.

A fully green result is **445/445 PASS** and routes to `M5-CP3-TB1-R1-REV`. A semantically red but mechanically complete run also routes to that Review; it does not return directly to implementation.
