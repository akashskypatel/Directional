# M4-CP2-TB1 Artifact-Only Test + Benchmark Execution Report

**Status:** COMPLETE / MEASURED GREEN / REVIEW PENDING / NOT PROMOTED

**Turn:** `M4-CP2-TB1-EXEC`
**Boundary:** immutable artifact-only Test + Benchmark execution
**Date:** 2026-09-10

## 1. Immutable authority and execution identity

This turn consumed the exact candidate produced by `M4-CP2-CB1`; it did not rebuild, relink, regenerate, repair, or mutate it.

- semantic/source commit: `eb23177e6ee9cbb27cf1ee30a299911abc0e1c60`;
- package artifact: `10166351695`, `directional-m4-cp2-cb1-package116-result-34512397141`;
- package/provider SHA-256: `c61b9900a2745454594825de81181ce982ec4b7986f40aa3b23c23e12d0e8e61`;
- TB workflow run/job: `34515352025 / 102999258938`;
- TB event/control SHA: `37f2675d0236a4c0ecfe3caf82995018d85d9829`;
- TB result artifact: `10167558308`, provider/download SHA-256 `214c854c0274e1de73b73a3e4fab4906729fda453fe090c60792645edee5fa9a`;
- TB diagnostic-log artifact: `10167558730`, provider/download SHA-256 `dceafa9801564d16ba27ca1b12d3e9bc79d648363f725fb78ee4ac54624f2bb7`.

The workload and independent audit jobs completed successfully. This EXEC report is runtime evidence only; it does not itself promote package116 or close M4-CP2.

## 2. Preflight and immutable-package receipts

Preflight completed before semantic runtime and established the frozen artifact contract:

- package `SHA256SUMS`: **28/28 verified**;
- package source metadata equals `eb23177e6ee9cbb27cf1ee30a299911abc0e1c60`;
- compile metadata reports successful preflight/build, clean packaged source-status receipts, `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`;
- GMP evidence includes both GMPXX and GMP linkage;
- selector380 path/count/hash: `.agents/Directional/Architecture_M4_CP2_Required_Green_Selector_380.txt`, **380** rows, SHA-256 `512c9ecea76b20ed85f6d74cbbdd9c415504ffc69d37a595d68b2de78bc409c4`;
- first 373 selector rows reproduce accepted selector373 exactly at SHA-256 `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`;
- exact one-owner partition: **30 authority-kernel / 234 producer / 75 completion / 41 validation**;
- all four packaged owner executables were already executable; no mode repair was performed;
- package-owned source was used to materialize the established execution view; no generated test discovery was used.

The independent result audit re-read raw per-process logs rather than trusting the inherited summary alone.

## 3. Focused CP2 deterministic receipt

Selector ordinals 374-380 were executed twice, in frozen order, one identity per fresh process. Each phase is **7 PASS / 0 RED / 0 SKIP / 0 timeout / 0 selection mismatch**, and the phase verdict vectors are identical.

| ordinal | identity | phase A | phase B |
|---:|---|---|---|
| 374 | `GlobalConformityExactSolver.MultiCoordinateBidirectedM2MatchesExhaustiveOracle` | PASS | PASS |
| 375 | `GlobalConformityCertificate.CarriesBindingPositivityParityObjectiveAndTerminalWitness` | PASS | PASS |
| 376 | `GlobalConformityCertificate.IndependentVerifierRejectsTerminalWitnessTamper` | PASS | PASS |
| 377 | `GlobalConformityOutcome.FeasibleCP2PathPreservesCP1ScheduleExactly` | PASS | PASS |
| 378 | `GlobalConformityOutcome.InfeasibleComponentReturnsTypedSubsetInsteadOfFatalError` | PASS | PASS |
| 379 | `GlobalConformityOutcome.InfeasibleSubsetIsCanonicalAndVerifierRejectsWitnessTamper` | PASS | PASS |
| 380 | `GlobalConformityOutcome.MixedComponentsCoverEveryIncidenceExactlyOnce` | PASS | PASS |

Each raw process log contains exactly one intended `[ RUN ]` receipt. The focused runs therefore provide direct runtime evidence for the deferred multi-coordinate bidirected `±2` oracle, certificate/tamper semantics, CP1 schedule preservation, typed infeasibility, canonical-subset verification, and mixed-component coverage.

## 4. Complete selector380 gate

The cumulative selector was executed in frozen order, one identity per fresh process, with no full-suite outer timeout.

- selector380: **380 / 380 PASS**;
- accepted predecessor rows 1-373: **373 / 373 PASS**;
- new CP2 rows 374-380: **7 / 7 PASS**;
- RED: **0**;
- SKIP: **0**;
- timeout: **0**;
- selection mismatch: **0**.

Owner totals independently re-derived from the runtime ledger are:

| owner executable | PASS | RED | SKIP | timeout | selection mismatch |
|---|---:|---:|---:|---:|---:|
| `directional_surface_cell_authority_kernel_tests` | 30 | 0 | 0 | 0 | 0 |
| `directional_surface_cell_producer_tests` | 234 | 0 | 0 | 0 | 0 |
| `directional_surface_cell_completion_tests` | 75 | 0 | 0 | 0 | 0 |
| `directional_surface_cell_validation_tests` | 41 | 0 | 0 | 0 | 0 |

## 5. Postflight integrity and execution boundary

Immutable postflight succeeded:

- package census before/after identical: SHA-256 `baa5fa2392219a85a78df0e811ee01b982b49f35b413749a957e763dc5fad463`;
- extracted-source census before/after identical: SHA-256 `686636a28aba5718c8da2019d6cc4f430d81985aaa8fd73a192dc3ad69ad5c43`;
- execution-view census before/after identical: SHA-256 `9b4d2964283d000b01c079df3f3b3e24c9005b6d7ed45aadb99d083f698aa01e`;
- `execution-boundary.txt` SHA-256 `f99c3137ef77c8d7c3be02225cd63a2f6329b5508242fb35a99e29863cff225a` records `script_exit=0`, `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`, `execution_view_verified=true`, `orchestration_failure=false`, `selection_integrity=true`, `timeout_count=0`, `benchmark_execution=false`, `configure_execution=false`, `compile_execution=false`, `relink_execution=false`, `generated_discovery=false`, `package_repair=false`, `mode_repair=false`, and `source_test_fixture_selector_mutation=false`.

Independent evidence-file receipts:

| file | SHA-256 |
|---|---|
| `semantic-audit-summary.txt` | `032271b9edea0796883711468305d161c8ade2ea9a616930e22aeedb05d9a659` |
| `semantic-audit.tsv` | `1992b3f72f4a0fdfc618e05f3511e52c4a16342d6986072ca7cd51086567647c` |
| `ledger.tsv` | `ed16050bf8656ea009c0cbf4ab96287d6ea26c3a34190e4fba5dffc6b49876a3` |
| `focused-a-ledger.tsv` | `fada27180e73b49131b194f3cd5f5b70d6af1ba485aa8391fb71dbf437613e41` |
| `focused-b-ledger.tsv` | `ff8eabaf936c87f34e6abc124c0c5b27a348d11edd422f5b08c69be19f91a19e` |
| `identity-map.tsv` | `3b8c6e8aafea9337da4979d97f802ea3fa5664c88292726d3650e15f038fd555` |
| `owner-distribution.tsv` | `706672abc96970ecde8c1eb77143b03591b9878e984d40a21466bb6fa41e7ec3` |

## 6. Regression accounting

**No regression, candidate, RED, SKIP, timeout, nondeterminism, selection mismatch, package-integrity failure, or orchestration failure was observed.** Consequently this EXEC turn creates no new regression ID and changes no stable regression count. Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**.

Package116 remains an unpromoted candidate in this execution turn. Accepted package authority remains **115** until review adjudicates the primary evidence.

## 7. Disposition and exact successor

`M4-CP2-TB1-EXEC` is **COMPLETE / MEASURED GREEN / REVIEW PENDING**. No retry, corrective CB, compile, package rebuild, or source/test/fixture/selector mutation is justified by this execution evidence.

**Exact next: `M4-CP2-TB1-REV`**, runtime-free REVIEW + adjudication. The review must independently re-open the immutable package/result/log evidence, re-derive the decisive selector, raw-log, owner, and postflight receipts, then decide promotion/CP2 closure. Until that review completes, package115 remains the accepted runtime authority and package116 remains candidate evidence.
