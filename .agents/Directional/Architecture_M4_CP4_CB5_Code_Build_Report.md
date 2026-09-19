# M4-CP4-CB5 — Code + Build report

**Turn:** `M4-CP4-CB5`
**Result:** **COMPLETE / COMPILE GREEN / TEST-AUTHORITY ONLY / NO GENERATED RUNTIME**
**Exact compiled source:** `4e9ff5003c8dd165dd614c25dd95f0308403719b`

## 1. Authorized semantic diff

CB5 changed exactly the two test-authority files authorized by `Architecture_M4_CP4_CB5_Code_Build_Plan.md`:

- `tests/SurfaceComplexSimplificationPhase17Tests.cpp`
  - `M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle` now reuses the already accepted row408 torus production precondition: exact two generator cycles / **18** user hard edges plus feature-threshold suppression of automatic rails.
  - Direct `SurfaceCells`, `fallbackPolicy=Fail`, `allowSourceGridRecovery=false`, retained intermediate geometry, the independent candidate-eligibility oracle, and the authoritative-support/protection tamper are unchanged in semantic strength.
- `tests/FieldTransportAtlasTests.cpp`
  - `M4CP4.ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection` still proves a nonzero apex angle defect, still requires flat zero-transport success, and now expects exact `FieldAtlasBuildErrorCode::NonIntegralCycleLift` for the unchanged non-flat zero-effort witness.

The applied patch SHA-256 is `0cd1643a4f0232ae9aeb2edc5f9749449ebc5d21164b1c60813a02117c2133dd`; its diff-body SHA-256 is `d42e245587df552e82c85199b989f6e2f04a5b4eb1a62b8968c6d5c95ae619c7`. Apply run/job `35436117274 / 105878958514` produced commit `c5daef9a2250610f0f86e5332d8e1a3edd5a91a6`. Result artifact `10582370366` has provider SHA-256 `56ba2b1c9f76ffe6fdb5d9e67aa4774826887a740f449b6f0a1fc37d89f2a6e1` and records `runtimeExecution=false`.

The patch commit changes exactly those two test files. No `src/**`, `include/**`, committed fixture, selector, benchmark, CMake/build semantic, reusable workflow, or periodic focused identity changed.

## 2. Falsifier audit

None of CB5 plan §2's falsifiers fired:

1. row2 reaches the accepted production precondition using test-local hard-rail/feature-map setup only; no product, fixture, fallback, recovery, or oracle change was required;
2. no synthetic/direct candidate complex or weakened eligibility predicate was introduced;
3. the frozen row6 witness still supports exact `NonIntegralCycleLift` before later transport-composition mismatch authority;
4. `M4CP4.ProducedTorusPeriodicRelationOwnersSurviveContainerReordering` and `M4CP4.ProducedTorusMissingPeriodicRelationOwnerIsRejected` are byte-unchanged and remain M5-owned debt witnesses;
5. selector427, benchmark/CMake semantics, product/fixture source, and durable reusable workflows are unchanged;
6. no generated Directional runtime was executed.

## 3. Mandatory GMP compile evidence

Compile workflow run/job `35436226379 / 105879256297` is GREEN. The reusable compile workflow checked out exact source `4e9ff5003c8dd165dd614c25dd95f0308403719b` and compiled only:

- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_authority_kernel_tests`.

Candidate delta artifact `10582435470` (`m4-cp4-cb5-compile-result-35436226379`) has provider SHA-256 `3e889c4682b35f6de2d30b38b9bf016f0dea526a10e46a0b9f1b404610443ad3`. Its self-excluding manifest is **24/24**, SHA-256 `f5239fa4cb8fb31551599d6f836ca16e44ab203056dc262eb5c26141ed62d270`; packaged source archive SHA-256 is `b904ba5fec938d74d432501396f94de0c015072de6d9009c6213e6d547c19c81`.

Compile metadata records:

- preflight exit `0` and build exit `0`;
- `runtimeExecution=false`;
- `turnBoundary=Code+Build-only`;
- `exactArithmeticBackend=GMP`;
- authoritative link command includes `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`;
- every source-status receipt is empty;
- fixed ccache key `directional-ccache-Linux-gcc-13.3.0-release-static-gmp-pretest-v2` restored and refreshed under the reusable's authority.

Persistent compile-log artifact `10582710217` has provider SHA-256 `459fd3a93021817bb01aa615b61220a262504c0e042744d0b6a3c5b6e49c6630`.

## 4. Runtime and acceptance disposition

CB5 grants **compile authority only**. It does not execute rows2/6, close `M4-CP4-TB1-R3-CAND-01` or `CAND-03`, discharge the remaining M4-owned `G4-B002` produced closed-complex debt, promote a runtime package, change stable accounting, or claim any M5-owned periodic debt.

Accepted M4 runtime authority therefore remains package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

## 5. Frozen successor

Exact successor is artifact-only **`M4-CP4-TB2-EXEC`** under `Architecture_M4_CP4_TB2_Artifact_Only_Test_Benchmark_Plan.md`.

The TB uses an immutable composite execution view rather than rebuilding: producer/validation owner binaries come from full CB4 package `10578784752`, while the two CB5-recompiled owner binaries (authority-kernel/completion) come from delta package `10582435470`. Both source packages remain untouched. This is valid because the exact `c2224f6a… -> 4e9ff500…` repository diff changes compiled test semantics only in `FieldTransportAtlasTests.cpp` and `SurfaceComplexSimplificationPhase17Tests.cpp`; product source, CMake, fixtures, producer-target sources, and validation-target sources are unchanged.

TB2 executes only M4-owned focus rows1/2/5/6 plus exact selector427. Periodic rows3/4 are not executed for M4 acceptance and remain unchanged for M5.
