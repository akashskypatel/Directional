# Architecture M6 CP2 CB1 Verifier R2 Recovery Code + Build Report

**Turn:** `M6-CP2-CB1-VERIFIER-R2`  
**Verdict:** COMPLETE / COMPILE-PACKAGE GREEN  
**Successor:** `M6-CP2-TB1-VERIFIER-R1-EXEC`

## Source and diff

RA-29 + RA-29a recovery was applied as semantic source commit `9c8478aec40bf07144ca7372c2aa58293cd42f5e`.

The exact semantic patch was SHA-256 `2c4f723af19b68410f90ef2b4dd39470784374e256444af5e5ab120b1e1c0299`, based on `05c9cad3262ad8cf6201536cd7adf37de598a40b`, and changed exactly:

- `include/directional/pipeline/RemeshPipeline.h`: +25 / -22
- `src/pipeline/RemeshPipeline.cpp`: +321 / -134
- `tests/SurfaceCellTransitionQuotientTests.cpp`: +145 / -4

Total: **491 insertions / 160 deletions** across exactly three files. No optimizer source changed.

The implementation covers the binding R2 requirements: A0 component-adjacency recomputation; shared source-support resolution; `a6:relation-class`; linear-time edge/cell and vertex/edge topology maps; exact selected-forest path validation; exact A7 step citation through A6 path relations; content-owning `VerifiedSurfaceProducts`; carried `VerificationReport`; post-projection counters read through the verified token; and strengthened existing focused identities 2/6/7/8/11 without adding or reordering CP2 focused identities.

## Patch transport

The first resumed Drive-apply attempt `37391068838 / 112036004976` failed before verification with Google Drive HTTP 404 because the preserved file was in the user's root rather than the service-account-visible `Directional-CI` folder. It made no source change and recorded `runtimeExecution=false`.

The corrected patch was staged in `My Drive/Directional-CI` and consumed by run/job `37391271795 / 112036654053`. The workflow verified the exact patch and base and pushed semantic commit `9c8478aec40bf07144ca7372c2aa58293cd42f5e`. Result/log artifacts:

- result `11380624588`, SHA-256 `d826d719712581fddcba201ffb063c243b3f375a30dd93fec73c269ef8c204b0`
- log `11380559626`, SHA-256 `985fdecc6ce8278a4296372038693f2679610158aea1b0db2e914515596c51a3`

The service account reported owner-side retirement required; both the consumed `Directional-CI` patch and the stale root preservation copy were then permanently deleted through the user-authorized Drive connector.

## Compile/package evidence

Compile workflow run/job: `37391389044 / 112037085233`.

Exact compiled source: `9c8478aec40bf07144ca7372c2aa58293cd42f5e`.

All eight standard targets compiled and linked successfully:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Compile result artifact `11382000465`, SHA-256 `e02e393375de3004beaf725cb859c7ad32e04456df56eb0c2c2239ad5deed4c1`. Compile log artifact `11381555970`, SHA-256 `3b2fd466c7d55695c31095239021b19696031e4bf263bbf72ccb8ec2b8743888`.

The package self-manifest verifies **28/28** entries. All five captured source-status files are empty. Build exit is 0. Configure evidence records GMP and GMPXX linkage through `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `libgmp.so`. The package boundary records `runtimeExecution=false`; no generated Directional executable, test, benchmark, discovery command, ctest, CLI, fuzzer, or help/version command executed in this turn.

## Frozen gate authority

No selector/routing bytes were changed:

- focused30 SHA-256 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`
- CP2-focused12 SHA-256 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`
- selector449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`
- routing449 SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`

Stable regression accounting remains **60 / 16 / 44** with produced-witness debt **1**. This Code + Build turn makes no runtime acceptance or CP2 promotion claim.

## Next turn

`M6-CP2-TB1-VERIFIER-R1-EXEC` must consume immutable package `11382000465 / 9c8478aec40bf07144ca7372c2aa58293cd42f5e` without rebuild or repair and execute exactly **30 + 12 + 449 = 491 fresh exact-filter processes**, followed by mandatory `M6-CP2-TB1-VERIFIER-R1-REV`.
