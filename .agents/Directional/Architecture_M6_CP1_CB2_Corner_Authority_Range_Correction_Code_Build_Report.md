# M6-CP1-CB2 A5 Corner-Authority Range Correction Code + Build Report

**Turn:** `M6-CP1-CB2`
**Disposition:** COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / CANDIDATE ONLY
**Semantic source:** `724316a5b3f49e33dc8e649989bb413b3dc6b7c9`
**Compile run/job:** `36061049526 / 107839861958`
**Candidate artifact:** `10834642074`
**Compile log artifact:** `10834671954`
**Exact successor:** `M6-CP1-TB2-EXEC`

## 1. Bounded correction

CB2 changes only `src/pipeline/RemeshPipeline.cpp` at the A5 corner-authority isolation-sheet membership check. The previously invalid `std::binary_search` range called the by-value `isolation_sheets()` accessor separately for `begin()` and `end()`. CB2 materializes that returned vector once as `regionSheets` and searches `regionSheets.begin(), regionSheets.end()`.

The correction is deliberately semantic-neutral. The preceding source-region and component checks remain unchanged, typed isolation-sheet membership remains mandatory, and the following source-support/chart validation remains unchanged. No test, fixture, selector, routing receipt, A4/M5 relation semantics, A6/A7/A8 authority, recovery/fallback behavior, validator, or benchmark code changed.

## 2. Static verification

Static verification against exact source established:

- the Review-identified cross-temporary split range is absent after the correction;
- a whole-tree scan of the known by-value container accessors finds no remaining `X().begin() ... X().end()` split range of this class;
- `SurfaceTopologyRegion::isolation_sheets()` still returns sorted/unique sheet IDs, so `std::binary_search` semantics are preserved;
- all A5 layers remain in order: source face/region, component/sheet, then source support/chart validity;
- selector449 remains exactly **449 LF rows**, SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- routing449 remains SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`;
- all six frozen CP1 focused identities remain present unchanged;
- `src/bench/BenchmarkQuality.cpp` was not touched.

The implementation diff is one file, **3 insertions / 2 deletions**. The exact work-preservation patch is based on `598de1d7befe130d8d9e43b19df1f0d06c2d12fc`, SHA-256 `d87318e9c528c5b0c274ea950b1ef64d5f61b76c8d6aae1e720e6d9ee27052c8`, and passed `git apply --check`, application, `git diff --check`, exact changed-path verification, and final-file comparison before remote application.

## 3. Remote application evidence

Verified patch transport used the durable Google Drive application workflow. Apply run/job `36060679446 / 107838640414` validated the caller, verified the patch and exact base, applied exactly the intended source file, committed, and pushed semantic source `724316a5b3f49e33dc8e649989bb413b3dc6b7c9` with `runtimeExecution=false`.

Apply result/log artifacts are:

- result `10834446812`, SHA-256 `ae6e9718d1657d3593f00a6b13cd9df00e8b65b3d98d1708b3613653dbfdb1c9`;
- log `10834626279`, SHA-256 `606a5db5a595ed7663b4bc885ee1bcab7b81ee2a4d9b11868b66a388c09f2fd3`.

The staging Drive file required owner-side retirement and was permanently deleted after the successful push.

## 4. GMP/GMPXX compile/package evidence

The authoritative reusable compile workflow built exact source `724316a5b3f49e33dc8e649989bb413b3dc6b7c9` and compiled/linked exactly the eight required targets:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Run/job `36061049526 / 107839861958` completed successfully. Candidate artifact `10834642074` has SHA-256 `754cfeae794da3304b39a572ef6feb6250709f908d5688dcd21f387a071d0cb8`; compile log artifact `10834671954` has SHA-256 `9395b4bdaad33c6805779035a418a4f29c80561880f2a870e0d45b2bff0cb5e4`.

The package root manifest verifies **28/28** and hashes to `a0fffc173149d1917ed6ab6a7dbb3c70335dee0b0e4ecb6ce652438d02037c9e`. The packaged source archive hashes to `eaf577ccdc534c2e9e48b8b8fed31079849b268c4a6c1b47b0f253ff3ad6034b` and records the exact semantic source. GMP evidence resolves `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`, and the recorded link command contains both. All five source-status receipts are empty.

The command boundary records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and `semanticContracts=compiled-not-executed`. The compile log explicitly records that no generated Directional binary, test, benchmark, discovery command, CLI, fuzzer, help/version command, or custom input executed.

## 5. Process observations

Two orchestration mistakes were surfaced rather than hidden:

1. The first locally generated work-preservation patch lacked the required patch body after its metadata header. It was detected by `git apply --check`; the accidentally uploaded Drive object was deleted before any application workflow consumed it. The corrected patch above is the only patch credited.
2. The first source-apply caller directly embedded the verified patch SHA-256 rather than materializing the SHA placeholder through the repository's `write_orchestration_payload.py` helper. The caller still passed schema validation and the durable reusable independently verified the exact patch/base before applying it, so source evidence is valid; this is recorded as a **process-policy deviation**, not normalized away. Subsequent orchestration payload authoring must use the helper.

No semantic/runtime regression accounting changes in Code + Build. Stable accounting remains **52 events / 15 categories / 37 recurrences**, produced-witness debt **1**, M6-owned. Accepted runtime authority remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 **449/449 PASS**. CB2 candidate is unpromoted.

## 6. Exit gate

CB2 satisfies its bounded exit gate: one proven source defect corrected, static guards passed, eight mandatory GMP/GMPXX targets compile/package green, immutable evidence is complete, and no generated Directional runtime executed.

Exact successor is **`M6-CP1-TB2-EXEC`** under `Architecture_M6_CP1_TB2_Artifact_Only_Test_Benchmark_Plan.md`. TB2 must consume artifact `10834642074` immutably, execute the unchanged six focused identities plus selector449 as exactly **455 fresh exact-filter processes**, and then hand every mechanically valid semantic outcome to mandatory `M6-CP1-TB2-REV`.
