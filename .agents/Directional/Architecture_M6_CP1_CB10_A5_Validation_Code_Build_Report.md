# M6-CP1-CB10-A5V Code + Build Report

**Turn:** `M6-CP1-CB10-A5V`
**Authority:** `Architecture_M6_CP1_CB10_A5_Validation_Code_Build_Plan.md`, RA-19, RA-22b, and the `M6-CP1-TB9-A7-R1-REV` release amendment
**Final semantic source:** `7c56845d4fac7ccb28898bbf4c681fc509ff9c3b`
**Boundary:** Code + Build only; no Directional runtime executed
**Successor:** `M6-CP1-TB10-A5V-EXEC` -> mandatory `M6-CP1-TB10-A5V-REV`

## 1. Implemented CB10 scope

CB10 completes the bounded A5-validation / thin-adapter migration without changing quotient topology, relation semantics, selector449, fixtures, or the accepted source-support tolerance value.

- RA-19 category-(a) phase-front semantic validation is now owned by A5 after the pre-existing A5 checks. The moved failures retain their compatibility names and loci through `SurfaceOccurrenceComplexErrorCode` / adapter mapping.
- `build_authoritative_phase_front_mesh` is reduced to A5/A6/A7 invocation, typed-error compatibility mapping, and serialization. A static scan of its exact final body finds no floating tolerance literal, `.norm()` decision, source-region/sheet lookup, route-validity predicate, `phaseFront.edges()` traversal, or other phase-front semantic selector.
- RA-22b restores the A7 representative-face retained-region/sheet reject-only guard in `close_completion_lineage_source_authority`; failure is exactly `CompletionOwnershipInvalidRetainedSourceAuthority:representative-face`.
- Focused20 keeps its original positive production-completion case and adds the RA-22b negative by removing the representative face's sheet from a multi-sheet materialized A7 lineage and requiring the exact `:representative-face` failure.
- The accepted source-support barycentric tolerance has one owner: `SurfacePointSourceSupportResolver::default_barycentric_tolerance() == 1.0e-8`. A5 and A7 both consume that accessor; the numeric value and support predicates are unchanged.
- Focused identities 21-24 are appended. Identity 24 is the RA-19 behavioral contract `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts`, independently constructing A5/A6/A7 products for hard-rail, split-isolation, and produced-torus fixtures before comparing adapter mesh/provenance/lineage serialization.

Focused-24 SHA-256 is `6bcc8a544cbc0296df4cdb66dcb0c2dc7f86c88dfb340b795462c8c9544067bf`. Its first 20 lines are byte-identical to focused20 (`15d04a2a09eeb678923b0bfcf70bf9c07b79e7ff343ec468316f6510b16827d2`). Selector449 and prior focused files are unchanged.

RA-22b is gate-neutral with respect to reviewed pre-R1 evidence: before R1 removed this guard, every TB9 gate process passed this exact representative-face preflight. CB10 therefore restores the reviewed reject-only condition rather than introducing a new accepted-path restriction.

## 2. Patch application and compile-only repair

The main preserved patch changed exactly six paths:

- `.agents/Directional/Architecture_M6_CP1_Required_Green_Focused_24.txt`
- `include/directional/geometry/SurfacePointSupport.h`
- `include/directional/pipeline/RemeshPipeline.h`
- `src/geometry/PureQuadCompletion.cpp`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/SurfaceCellTransitionQuotientTests.cpp`

Main patch evidence:

- base: `f12a6b6fc0518f5df0bd152c3500c4d0ce391f93`;
- patch SHA-256: `32f3fbbb3453db2fbf860e29cfe71881745f6f7eb49f2977ecab6f58d208eaee`;
- diff-body SHA-256: `0fb4106d02ac5aebbd55275790890baf8896cbf96600ed4aabf8f59900bcd04f`;
- Drive apply run/job: `37181546953 / 111374991845`;
- apply result/log artifacts: `11295580732 / 11295730411`;
- applied semantic commit: `406c6237541e6b6cffab24813f995461c96d12f0`.

The first mandatory compile attempt (`37181663554 / 111375326376`) was compile-only and failed while compiling identity 24: Eigen rejected a `3x1` transposed adapter row compared with a `1x3` expected position (`YOU_MIXED_MATRICES_OF_DIFFERENT_SIZES`). Production sources had compiled; no Directional binary was executed. A surgical one-line test-only repair removed the erroneous `.transpose()`:

- repair patch SHA-256: `376c5f7674272bcdbd32616e0b87ec976c883480c7f112afa61ac30569b1e2b0`;
- repair diff-body SHA-256: `27b2f206bf95ba72029750d09fb427694ea46ac5ebfa1f2c1f541bc9521bc2ce`;
- repair run/job: `37182092640 / 111376563037`;
- final semantic commit: `7c56845d4fac7ccb28898bbf4c681fc509ff9c3b`.

No implementation semantics changed in the repair.

## 3. Mandatory compile/package result — GREEN

Final compile/package evidence:

- workflow run/job: `37182633770 / 111378124041`;
- exact compiled source: `7c56845d4fac7ccb28898bbf4c681fc509ff9c3b`;
- candidate/result artifact: `11295692493`;
- result artifact digest: `sha256:e65cd6ee6b3f883b526207d83718a028b111f7ecc4de89e70e9365f38ea77065`;
- compile-log artifact: `11295527848`;
- compile-log digest: `sha256:1b2a9031b7d44013a8b3fd699b93c7c28ee2b0769485ab555ad4f19569760455`;
- all eight standard targets compiled: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`;
- preflight exit `0`, build exit `0`;
- `DIRECTIONAL_ENABLE_GMP=ON`, `exactArithmeticBackend=GMP`, and authoritative link evidence includes both `gmpxx` and `gmp`;
- recursive self-excluding manifest verified **28/28**;
- final source-status receipt is clean;
- `runtimeExecution=false` and `turnBoundary=Code+Build-only`.

No test, benchmark, test discovery, CLI, generated executable, or other Directional runtime was executed in CB10.

## 4. Disposition and next gate

CB10 is compile/package GREEN and the candidate remains unpromoted until immutable TB10 and mandatory Review.

Exact next is `M6-CP1-TB10-A5V-EXEC`: consume candidate `11295692493 / 7c56845d4fac7ccb28898bbf4c681fc509ff9c3b` immutably and execute focused24 then selector449 as exactly **24 + 449 = 473** fresh exact-filter processes, with exact-one selection, zero skips, benchmark 0, and immutable postflight. Then perform mandatory `M6-CP1-TB10-A5V-REV` before CB11.

Reviewed runtime authority remains TB9-R1 `11292072930 / 584f80fe27fe3fbe482f3b6db035651a3083257c` until TB10 Review accepts or rejects the CB10 candidate. Stable accounting remains **60 / 16 / 44**, project debt 1. The A7 cross-sheet certification proxy and remaining provenance-face consumer audit remain owned by `M6-CP1-CLOSE-REV`.
