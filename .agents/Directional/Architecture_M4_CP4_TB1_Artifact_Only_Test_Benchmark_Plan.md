# M4-CP4-TB1-EXEC — artifact-only focused CP4 Test + Benchmark plan

**Turn:** `M4-CP4-TB1-EXEC`
**Type:** immutable artifact-only Test + Benchmark
**Predecessor:** `M4-CP4-CB1`
**Candidate artifact:** `10574525792`
**Exact compiled source:** `8d6b8ccf5d49966414f8c54b02b130d8196d3af8`
**Selector:** exact byte-frozen selector427, SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`

## 1. Goal

Measure the CB1 evidence surface without rebuilding or mutating it. TB1 must establish whether all six focused CP4 identities are reachable and green on immutable production authority while the entire accepted selector427 prefix remains green from the same package.

TB1 does not publish new selector rows and does not promote the package. Review owns produced-credit and publication authorization.

## 2. Immutable preflight

Before any generated Directional process:

1. download artifact `10574525792` and verify provider/package SHA-256 `857d49282a099d7c0c11b378e99c6b2cb7ab26a44ab0797a9e74157b27dec7c0`;
2. verify package `SHA256SUMS` completely and verify packaged source archive SHA-256 `d58c31b055403c81d663eee16fec65f1b4c447a809093bde94c8cb460280fd88`;
3. verify exact source `8d6b8ccf5d49966414f8c54b02b130d8196d3af8`, clean packaged source receipts, `exactArithmeticBackend=GMP`, both GMPXX/GMP evidence, executable modes and `runtimeExecution=false`;
4. extract selector427 from packaged source and require exactly **427 LF rows** and SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
5. freeze one harness/caller and record its bytes/SHA before runtime. No generated test discovery/list/help/version invocation is allowed.

Any package/source/selector/integrity mismatch is orchestration failure, not semantic evidence.

## 3. Focused CP4 gate — six fresh processes

Run exactly one identity per fresh process with `GTEST_FAIL_IF_NO_TEST_SELECTED=1`; require exactly one selected test and zero skips for each:

1. `M4CP4.ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated` — producer executable;
2. `M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle` — completion executable;
3. `M4CP4.ProducedTorusPeriodicRelationOwnersSurviveContainerReordering` — producer executable;
4. `M4CP4.ProducedTorusMissingPeriodicRelationOwnerIsRejected` — producer executable;
5. `M4CP4.ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder` — producer executable;
6. `M4CP4.ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection` — authority-kernel executable.

Record per-process exit status, selected/passed/failed/skipped counts and raw output. A focused RED is semantic evidence; do not retry or patch it. Preserve the exact blocking stage/locus when a produced precondition fails.

## 4. Accepted-prefix reproof — exact selector427

After focused execution, execute every selector427 row in exact file order, one fresh process per row, against the executable owner resolved from the existing selector-owner mapping. Require exactly one selected identity per process. Record all **427** rows explicitly as PASS/RED/SKIP/crash/timeout/selection-mismatch/unexecuted.

The accepted-prefix result is gating evidence but does not authorize editing selector427. A selector-row RED is an accepted-green regression and routes to Review immediately after evidence preservation; no in-turn correction is allowed.

## 5. Runtime boundary and postflight

- Benchmark count is **0**; no benchmark executable or custom input is authorized.
- No configure, compile, relink, package repair, source/test/fixture/selector mutation, permission repair or generated discovery command.
- Keep package bytes and modes immutable.
- Perform exact package/source/execution-view postflight and require byte+mode equality with preflight.
- Preserve a complete ledger for all 6 focused rows plus 427 selector rows, including explicit unexecuted rows if orchestration or semantic stop prevents later execution.

## 6. Classification and successor

TB1 is evidence intake only. It does not promote artifact `10574525792`, discharge produced-witness debt, or authorize selector publication.

- If all six focused identities and selector427 are green with exact postflight, route to runtime-free **`M4-CP4-TB1-REV`** for independent adjudication of produced reachability, independent oracles, work evidence and tampers.
- If any focused or selector identity is semantic RED, route to the same **`M4-CP4-TB1-REV`** with the first/complete recorded red set; no retry or CB precedes Review.
- If the run is orchestration-invalid before semantic evidence is trustworthy, preserve the invalid attempt and route to the smallest orchestration-correction CB under `Turn_Cadence.md`.

Accepted runtime authority remains package `10565723112` / selector427 **427/427** until Review explicitly promotes later authority.
