# M6-CP1-CB9-A7-R1 Code + Build Report

**Turn:** `M6-CP1-CB9-A7-R1`
**Authority:** RA-22 + RA-22a in `Architecture_M6_CP1_CB9_A7_R1_Completion_Ownership_Code_Build_Plan.md` and `Architecture_M6_CP1_TB9_A7_Review_Record.md`
**Final semantic source:** `584f80fe27fe3fbe482f3b6db035651a3083257c`
**Boundary:** Code + Build only; runtime forbidden and not executed
**Successor:** `M6-CP1-TB9-A7-R1-EXEC` -> mandatory `M6-CP1-TB9-A7-R1-REV`

## 1. Implemented RA-22 / RA-22a scope

The semantic change is confined to `src/geometry/PureQuadCompletion.cpp`, inside `close_completion_lineage_source_authority`.

For A7 lineage (`sourceOccurrences` non-empty):

- representative-face region/sheet/component values are no longer semantic selected-destination authority;
- retained A7 charts, regions and sheets remain the class-wide authority;
- source components are recomputed from every retained chart via `SourceChartTransitionGraph::source_component` and must form exactly one component;
- selected relation destination region and sheet are validated by retained-set membership;
- selected relation destination source component must equal the retained-chart singleton;
- selected relation endpoint-chart and chart-component certificate checks, relation value/transport composition, support identity, and all earlier fail-closed predicates remain unchanged.

Legacy non-A7 lineage (`sourceOccurrences.empty()`) preserves selected-face region/sheet/component closure and validates relation destinations against those legacy values.

RA-22a diagnostics are present and first-false-clause ordered:

- `CompletionOwnershipInvalidSelectedRelationDestination:dest-unresolved`
- `CompletionOwnershipInvalidSelectedRelationDestination:dest-region`
- `CompletionOwnershipInvalidSelectedRelationDestination:dest-sheet`
- `CompletionOwnershipInvalidSelectedRelationDestination:dest-component`
- `CompletionOwnershipInvalidRetainedSourceAuthority:component-singleton`

Static grep of the exact compiled source found no test or production caller that compares these diagnostic strings exactly; only durable documentation mentions the unsuffixed historical failure.

## 2. Patch application authority

The preserved patch was generated from base `b1cbbad9b46fe8378cd543e4450a3e11c358db6b` and changed exactly `src/geometry/PureQuadCompletion.cpp`.

- patch SHA-256: `69c22073d6b14ec1f777d0ce857f74daae5059e352891cfc51a32277957325b8`;
- diff-body SHA-256: `ec7b85681ec833f882b1ffc9b2db0744a0dd219ec22dd40c326d23541f3c26ca`;
- Drive apply workflow run/job: `37173435429 / 111351004616`;
- apply result artifact: `11291953339`, `sha256:cfe13ebddf124eca19b5f19ec6af09348a55ead8bbd5ba7a5cdfcfc473129941`;
- apply log artifact: `11292072773`, `sha256:ade8567d8f44b3ab114d8328be7e45bcb3d07eb61c25bfcbbbe4d7ed08fd427d`;
- applied semantic commit: `584f80fe27fe3fbe482f3b6db035651a3083257c`;
- apply result records `runtimeExecution=false`;
- workflow Drive identity required owner cleanup; owner-authorized permanent deletion succeeded after push.

The temporary patch-apply caller and marker were retired in workflow-first order before compilation.

## 3. Mandatory compile/package result — GREEN

Authoritative compile/package evidence:

- workflow run/job: `37173519009 / 111351273790`;
- exact compiled source: `584f80fe27fe3fbe482f3b6db035651a3083257c`;
- result/candidate artifact: `11292072930`;
- result artifact digest: `sha256:d871b1decc979cdd09c5156a6f0e667e22815a1c60bacd9bebd618b6fff92752`;
- compile-log artifact: `11292072932`;
- compile-log digest: `sha256:d6d5061de01a146da87d46572bf0bf6bbee4faa2a5478413495efabbaac0586f`;
- all eight standard targets compiled: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`;
- preflight exit `0`; build exit `0`;
- `DIRECTIONAL_ENABLE_GMP=ON`, package metadata `exactArithmeticBackend=GMP`, and authoritative link evidence contains both `gmpxx` and `gmp`;
- recursive self-excluding package manifest verified **28/28**;
- all packaged source-status receipts are empty;
- `runtimeExecution=false` and `turnBoundary=Code+Build-only`.

No test, benchmark, generated Directional binary, discovery command, `ctest`, CLI, fuzzer, help/version command or custom input executed in this turn.

## 4. Turn disposition

`M6-CP1-CB9-A7-R1` is **COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE**. Candidate `11292072930 / 584f80fe27fe3fbe482f3b6db035651a3083257c` is unpromoted pending immutable runtime and Review.

Reviewed runtime authority remains TB8 `11265967968 / 8e0818b1e2f8d12b86c64d8774a3572c5ed5266c` at 461/461. Stable accounting remains **60 / 16 / 44**, debt **1**.

Exact successor is `M6-CP1-TB9-A7-R1-EXEC`, consuming the immutable candidate and executing unchanged focused-20 followed by selector449: exactly **469 fresh exact-filter processes**, exact-one selection, zero skips, benchmark 0, then mandatory `M6-CP1-TB9-A7-R1-REV`. CB10 remains held until that Review.
