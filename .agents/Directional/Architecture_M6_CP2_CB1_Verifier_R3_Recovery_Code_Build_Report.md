# Architecture M6 CP2 CB1 Verifier R3 Recovery Code + Build Report

**Turn:** `M6-CP2-CB1-VERIFIER-R3`
**Verdict:** COMPLETE / COMPILE-PACKAGE GREEN / CANDIDATE UNPROMOTED
**Successor:** `M6-CP2-TB1-VERIFIER-R2-EXEC`

## Source and diff

RA-29b §2/§4/§5 plus binding RA-29c were implemented at exact semantic source `c64baacd6c767c4ba053b6963651c0aa6eceed20`.

The exact semantic patch was SHA-256 `ff363f0ea6daa9cfe12c90cbc03f901e9084164d336aae9be01bf4bc932c7c97`, diff-body SHA-256 `2766a2827652c95413fd80b498e4eb14bff2e88aa36a5cdc67e3c181bae84a05`, based on `8cb9903dc4491351e79891aace27e838cce7844e`, and changed exactly:

- `include/directional/pipeline/RemeshPipeline.h`: +0 / -2
- `src/pipeline/RemeshPipeline.cpp`: +80 / -140
- `tests/SurfaceCellTransitionQuotientTests.cpp`: +229 / -41

Total: **309 insertions / 183 deletions** across exactly three files. No optimizer source changed.

The verifier now implements RA-29c's exact three-hop binding: A5 `a5:selected-step-value`; A6 `a6:legacy-projection` reconstructed only from each path's own ordered relations/orientations with named-certificate inversion/composition; and A7 `a7:selected-paths` as the class-local sorted-unique set of A6 legacy projections. R2's `a7:a5-relation-step` reverse lookup and O(V·P) scan are removed. The invalid raw-connectivity `a0:component-adjacency` rule and its identity-2 sub-witness are removed. Identity 6 carries the three RA-29c tampers with no ambiguity witness. Identity 11 replaces the vacuous `owns_products` constant/static assertion with behavioral copied-product address inequality plus record equality, and the constant is deleted.

Static closeout confirmed `a7:a5-relation-step`, `a0:component-adjacency`, and `owns_products` are absent from the changed implementation/test surface; `git diff --check` and an exact `git apply --check` against the frozen source snapshot passed before transport.

## Patch transport

Drive-apply workflow run/job `37401490404 / 112069495253` verified the exact staged patch/base/intended paths and pushed semantic commit `c64baacd6c767c4ba053b6963651c0aa6eceed20`. Result/log artifacts:

- result `11384869072`, SHA-256 `8f000a8b1a36de4d7b11df484e5f314ffb00b952c160c73f06948b1eff9c7f9a`
- log `11385018777`, SHA-256 `6d1f2a946a157bf93d1791815ffedbdf3cd19800e91ccc0466919a233dc7dc65`

The reusable recorded `runtimeExecution=false`. Its service account could not trash the staged Drive file, so owner-authorized permanent deletion was performed successfully after the push.

## Compile/package evidence

Compile workflow run/job: `37401647591 / 112069997705`.

Exact compiled source: `c64baacd6c767c4ba053b6963651c0aa6eceed20`.

All eight standard targets compiled and linked successfully:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Compile result artifact `11385836615`, SHA-256 `40ea2966011865090ce49382300885ee132e82655fba4f98575f326b53ca2ea4`. Compile log artifact `11385671776`, SHA-256 `97a7aee4888c938d356894c6f661ad8a0a00f526eb87e9d8f88c7fa132a3f675`.

The package self-manifest verifies **28/28** entries. Preflight/build exits are `0/0`; all five captured source-status receipts are empty. Configure/link evidence records GMP and GMPXX through `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `libgmp.so`; `exactArithmeticBackend=GMP`. The packaged source archive SHA-256 is `fb7f08f193aa335944c5a3ff460ef481ec9f1dec6cefba676a563d374305bce9`. The command boundary records `runtimeExecution=false`; no generated Directional executable, test, benchmark, discovery command, ctest, CLI, fuzzer, or help/version command executed in this turn.

## Frozen gate authority

The frozen gate bytes remain unchanged:

- focused30 SHA-256 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`
- CP2-focused12 SHA-256 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`
- selector449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`
- routing449 SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`

Their row counts remain 30 / 12 / 449 / 449. Stable regression accounting remains **60 / 16 / 44** with produced-witness debt **1**. This Code + Build turn makes no runtime acceptance or CP2 promotion claim.

## Next turn

`M6-CP2-TB1-VERIFIER-R2-EXEC` must consume immutable package `11385836615 / c64baacd6c767c4ba053b6963651c0aa6eceed20` without rebuild or repair and execute exactly **30 + 12 + 449 = 491 fresh exact-filter processes**, using `TURN_ID`-derived upload paths, zero benchmarks, and immutable package/source/execution-view postflight. It then routes to mandatory `M6-CP2-TB1-VERIFIER-R2-REV` regardless of semantic green/red outcome.
