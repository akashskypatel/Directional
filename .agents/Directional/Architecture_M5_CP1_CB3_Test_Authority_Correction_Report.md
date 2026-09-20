# M5-CP1-CB3 Test-Authority Correction Code + Build Report

**Turn:** `M5-CP1-CB3`
**Milestone/checkpoint:** M5 / CP1
**Mode:** Code + Build / test-authority-only correction
**Disposition:** **COMPLETE / STATIC ACCEPTANCE GREEN / GMP COMPILE+PACKAGE GREEN / RUNTIME UNADJUDICATED**
**Semantic source:** `8a86710dd33d7b6cb9a077aef738577e4075b5f7`
**Candidate artifact:** `10600353027`
**Exact successor:** `M5-CP1-TB1-R3-EXEC`

## 1. Authorized correction

CB3 changed only the body of `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation` in `tests/SurfaceCellTransitionQuotientTests.cpp`.

The corrected witness now:

1. starts from `direct_full_periodic_materializer_draft()`;
2. constructs one distinct valid unused periodic relation with the runtime-green row7 construction;
3. proves that relation ID is absent before insertion;
4. inserts it into the baseline table before copying;
5. copies identical relation membership into `reorderedDraft`;
6. proves the first and last stored relation IDs differ;
7. reverses only `reorderedDraft.periodicHolonomies` and proves the reversal changes the first stored ID;
8. materializes both drafts; and
9. compares complete selected-relation certificate signatures, `hash_completion(...)`, and consumed periodic-relation counts.

The remote semantic commit is exactly `8a86710dd33d7b6cb9a077aef738577e4075b5f7`. Its diff contains one file and one test-body correction; product code, shared helpers, row7, row9, fixtures, selectors, CMake and reusable workflows are unchanged.

Work-preservation patch authority:

- base `9d4e04c9713f8accc74681873ca390d0cdfba6f2`;
- patch SHA-256 `8060e01de16d44726dc520f60523733ff3bd749e219b7960f63a2afa2c6ea519`;
- diff-body SHA-256 `ad6b4696d518fe4e104e10cab784e81df0c0f06381e470fc6874a69bcfb35a47`;
- Drive apply run `35494732498` / job `106035607980`;
- apply result artifact `10599468935`, provider digest `c288c20d7d49050627d6d929a77c56a9a540e0b5bf5514d008801d8979c8ad85`;
- staged Drive file was permanently deleted by the owner-authorized connector after the workflow reported `owner-cleanup-required`.

## 2. Frozen selector/static acceptance

The packaged candidate independently preserves:

- selector430: **430 LF rows**, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- first427 prefix: SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

No accepted selector identity body or shared helper was edited. The corrected row6 is a pure-permutation witness: the two materialization subjects have identical relation membership and values; only relation-table storage order differs.

`M5-CP1-TB1-R2-REV-OBS-01` therefore advances from “witness not yet authored” to **witness authored + compiled / runtime falsifier pending R3**. CB3 does not claim the order-invariance behavior passes; only R3 may adjudicate it by executing the corrected witness.

## 3. Mandatory GMP compile/package

Workflow run `35494880046`, compile job `106036002599`, is green on exact source `8a86710dd33d7b6cb9a077aef738577e4075b5f7`.

All eight standard package targets compiled/linked:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Candidate evidence:

- result artifact `10600353027`, provider ZIP SHA-256 `cdc0cb798e6b117727ddde0dbfa5008d2a8140c709eeafb0af66872c5c7ae6b0`;
- persistent log artifact `10600552020`, provider ZIP SHA-256 `fadd1f67c89fdd2f8cd16074bea6ea7d8fec22ee50d3bb13c0a7d50c27f8f851`;
- root manifest **28/28 PASS**, self-excluding and self-verifying;
- packaged source archive SHA-256 `594dad05c7078c0c5b2e03486f408ca6621e2c36875873fa045803245497352d`;
- `DIRECTIONAL_ENABLE_GMP=ON`;
- `exactArithmeticBackend=GMP`;
- generated link evidence contains both `libgmpxx.so` and `libgmp.so`;
- all source-status receipts are empty;
- build exit `0`, preflight exit `0`;
- `runtimeExecution=false`.

No Directional test, benchmark, generated discovery command, CLI or other generated binary was executed in CB3.

## 4. Cleanup and process evidence

Temporary source-snapshot/apply/compile trigger state was removed by cleanup run `35494988958`, cleanup commit `540fdee1c31e431119c3c4d6eb68767bf4802206`. The cleanup result removed exactly three inventoried marker paths and reports `runtimeExecution=false`. Temporary apply and compile workflow callers were deleted first.

Two process limitations are recorded without changing semantic authority:

- the web session selected `READ_MODE=snapshot` after initial repository-authority reads rather than before every repository/doc read; all semantic inspection and edit construction thereafter used the immutable snapshot `9d4e04c9713f8accc74681873ca390d0cdfba6f2`;
- the available GitHub connector exposed no workflow-dispatch write action for pre-publication invocation of the schema-validator reusable. Each temporary caller was therefore installed inert behind a unique marker path, then schema-validated by `agent-workflow-schema-validator-reusable.yml` in the triggered run, with the workload gated by `needs: validate`. Both validations passed before their workloads ran. This is recorded as a control-plane limitation, not semantic evidence.

## 5. Acceptance and successor

CB3 satisfies its static and compile/package gate. It does **not** promote the candidate and does **not** close CP1 because the corrected witness has not run.

Accepted runtime authority remains M4 package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430**. Stable accounting remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**.

Exact successor: `M5-CP1-TB1-R3-EXEC` under `Architecture_M5_CP1_TB1_R3_Artifact_Only_Test_Benchmark_Plan.md`.
