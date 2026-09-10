# M4-CP2-CB2 Code + Build Report

**Status:** COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / PACKAGE117 CANDIDATE

**Turn:** `M4-CP2-CB2`
**Boundary:** corrective Code + Build only
**Date:** 2026-09-10

## 1. Authority and scope

CB2 repaired only the four review-directed CP2 contract candidates from `M4-CP2-TB1-REV` while preserving accepted CP1 semantics and the existing CP2 component/infeasibility/terminal-witness contract.

- patch base/control authority: `399ea4ecc8f69b107286e2fa66cf8b3c5f51cdb6`;
- semantic evidence source: `534c0d41ae05b31e66711f21f4b4280b59f6483f`;
- work-preservation patch SHA-256: `a2caace911ccc8833c9d7995200d7f679d549995f4a000ce577b43bce17b630a`;
- embedded diff-body SHA-256: `391ac7fbf98d0d39d4cbe092fe4926c224340b6612f3922d363c4c03beb0a877`;
- patch apply run/job: `34528840311 / 103044366813`;
- apply result/log artifacts: `10172660705 / 10172661298`, provider SHA-256 `495181d207f2e50b2418a199d551bf345b5c18505415f4fb1426ceb504980f2b` / `e471a1cd5f9c234632de27a15010d7174fcb641c2a12bcb38a74fc213c252a6b`.

The patch changed exactly eight intended semantic/test/CMake/selector paths, with **786 insertions / 15 deletions**. The consumed Google Drive transport file was permanently deleted through the owner-authorized control plane after successful push.

## 2. Corrective implementation

### CAND-01 + CAND-04 — load-bearing `±2` oracle and success-visible receipt

Ordinal 374 remains `GlobalConformityExactSolver.MultiCoordinateBidirectedM2MatchesExhaustiveOracle`, but its four-coordinate fixture now contains a live parity obstruction. The exact exhaustive oracle gives full `±2` optimum `(1,2,2,2)` and magnitude-one twin `(1,2,1,1)`; every coordinate is strictly below the oracle bound 8. Passing execution now writes the deterministic receipt:

`M4_CP2_ORACLE_RECEIPT coordinateCount=4; containsBidirectedCoefficientMagnitude2=true; magnitude2LoadBearing=true`

This turn only compiled that test; the receipt has not yet been executed.

### CAND-02 — complete WorkLedger carriage and independent verification

`GlobalConformityWorkLedger` now carries the frozen finite-convergence assurance class and `maximumObservedExactIntegerBitWidth`. The independent CP2 verifier checks initializer dimensions, exact-initializer feasibility, refinement count/history, peak matching dimensions, every width/maxima family, overall observed exact width, terminal witness facts, and retry-reset semantics. Ordinal 381 is:

`GlobalConformityCertificate.IndependentVerifierRejectsWorkLedgerBoundHistoryAndAssuranceTamper`

Its tamper matrix mutates the omitted assurance/bound/history families individually and is compiled but not executed in CB2.

### CAND-03 — CP2 semantic outcome digest

`GlobalConformityOutcome` now carries additive `semanticDigest` without changing the accepted CP1 `GlobalConformityPlan::semantic_digest()` contract. Producer digest derivation binds normalized input, full ordered support pieces, incidences, canonical component results, complete scheduled certificates/WorkLedgers, infeasible subsets and optional CP1-compatible plan identity. The validator independently re-derives the digest through a separate implementation path. Ordinal 382 is:

`GlobalConformityOutcome.SemanticDigestBindsFullCP2Outcome`

It compiles coverage for feasible/infeasible outcomes, permutation stability, digest tamper and full-support/certificate semantic tamper.

## 3. Selector and ownership receipts

`Architecture_M4_CP2_Required_Green_Selector_382.txt` is exactly selector380 plus ordinals 381-382.

- selector382 rows: **382**;
- selector382 LF SHA-256: `1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f`;
- first380 prefix SHA-256: `512c9ecea76b20ed85f6d74cbbdd9c415504ffc69d37a595d68b2de78bc409c4`;
- accepted first373 prefix SHA-256: `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`;
- exact static one-owner partition: **30 authority-kernel / 236 producer / 75 completion / 41 validation**;
- zero missing or duplicate selector identities.

Ordinals 374, 381 and 382 are producer-owned in `tests/GlobalConformityPlanTests.cpp`.

## 4. Compile/package evidence

The exact semantic source was compiled only by durable `.github/workflows/agent-compile-reusable.yml`.

- compile workflow run/job: `34529050994 / 103045247639`;
- candidate package: **package117**;
- result artifact: `10172820820`, `directional-m4-cp2-cb2-package117-result-34529050994`;
- result ZIP/provider SHA-256: `e804c8a88082befcdfbc7091f64182b854f5fe8eac00861ddf1ccdb47ecb7725`;
- compile-log artifact: `10172821494`, provider SHA-256 `9ad32693bebf78fc757dec039598083df15b38defdcb0edfe5fed6060b6337f2`;
- packaged source archive SHA-256: `a366908f0f52cc7bcdff4123893acbc553201880aa86a07f9418aac2734082f4`;
- package `SHA256SUMS`: **28/28 verified**, manifest SHA-256 `ce3ed680698c443716d55bfa3839cae43d7225f0cf69ca37e201cf764878b1cc`;
- preflight compile exit: `0`; full compile exit: `0`;
- all five recorded source-status files: empty/clean;
- exact arithmetic backend: GMP, `libgmp-dev 6.3.0`, with both `libgmpxx` and `libgmp` in the link command;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`.

Approved targets compiled and linked: `directional_core`, `directional_pipeline`, all four selector-owner test executables, `directional_compiled_api_tests`, and `directional_benchmarks`. No produced Directional binary was executed.

### Packaged binary/library SHA-256

| packaged file | SHA-256 |
|---|---|
| `bin/directional_surface_cell_authority_kernel_tests` | `5efacc3ad52085a8ab76bad451bfc70c337e44a73a8f81a165f06ab1cd3041b3` |
| `bin/directional_surface_cell_producer_tests` | `2363de846e7f59a34be2d1e60bce524f3d4567c459c37a75f6b69ed6933c3968` |
| `bin/directional_surface_cell_completion_tests` | `1701820d85d91fe674cb3dd3496669f0a49ca43e6068a170fb0277227aba094a` |
| `bin/directional_surface_cell_validation_tests` | `303af6ab231bf88b6b618df03315c9999a27595b8b55871922935f5098a4ca5f` |
| `bin/directional_compiled_api_tests` | `a41d8dbaa531d30bb82f3fcdaf9d069a5a13866f15fe500e7f0400911bc29ade` |
| `bin/directional_benchmarks` | `d3940d4db3f8ebd31403b85970d9f9c98676b9374926d060aeb38682b48490af` |
| `lib/libdirectional_core.a` | `ce204a79a49acd35b4c967c2a87faaab45173925ef660714f4de05d329f423ea` |
| `lib/libdirectional_pipeline.a` | `2915ce680907d0a1ea4c480ec2281a707141188109e43066b52ffcf30aac0735` |

## 5. Boundary and disposition

No test, benchmark, `ctest`, generated discovery/list/help/version command, fuzzer, CLI or custom runtime input executed in CB2. Compile success therefore proves only build/package integrity, not semantic acceptance.

Package117 and selector382 are **candidate evidence only**. Accepted runtime authority remains package115 / selector373 **373/373** until immutable artifact-only TB2 execution and its required review adjudicate the candidate. Stable regression accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**.

**Exact successor:** `M4-CP2-TB2-EXEC` under `Architecture_M4_CP2_TB2_Artifact_Only_Test_Benchmark_Plan.md`.
