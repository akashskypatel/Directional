# M4-CP2-CB1 Code + Build Report

**Status:** COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / SEMANTIC ACCEPTANCE PENDING TB

**Turn:** `M4-CP2-CB1`
**Boundary:** Code + Build only
**Date:** 2026-09-10

## 1. Implemented scope

CB1 implements the frozen CP2 addition without advancing to CP3:

- additive generic global-conformity input/outcome surface while retaining the accepted CP1 known-feasible API;
- deterministic connected constraint-component partitioning;
- scheduled-component `GlobalConformityCertificate` carrying source/topology/metric/problem binding, exact schedule/objective, positivity/balance/parity facts, WorkLedger bounds, fixed-`M=2` terminal data, and a producer-native weighted-perfect-matching witness;
- a separately implemented independent CP2 verifier that re-derives public semantic facts and rejects certificate/infeasible-subset tampering;
- typed deterministic `BalanceCut | PositivityCut | ParityCut` mathematical infeasibility instead of encoding ordinary infeasibility as a fatal `GlobalConformityPlanError`;
- the deferred CP1 multi-coordinate same-row bidirected `±2` exhaustive-oracle fixture inside the frozen `E<=6, x_s<=8` envelope;
- retroactive CP1 graph-class clarification in `M4_CP1_Closure_Record.md`;
- seven prescribed direct deterministic CP2 identities, owned by `directional_surface_cell_producer_tests`.

The implementation remained surgical. No CP3 producer cutover, fallback semantic authority, validation weakening, tolerance substitution, or reusable-workflow permission change was made.

## 2. Selector and static receipts

`Architecture_M4_CP2_Required_Green_Selector_380.txt` is an exact append-only extension of accepted selector373:

- selector380: **380 LF rows**, SHA-256 `512c9ecea76b20ed85f6d74cbbdd9c415504ffc69d37a595d68b2de78bc409c4`;
- predecessor prefix: first **373** rows SHA-256 `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`;
- appended rows: exactly the seven identities frozen by `Architecture_M4_CP2_CB1_Code_Build_Plan.md`, in order;
- static one-owner partition for selector380: **30 authority-kernel / 234 producer / 75 completion / 41 validation**.

Static diff/selector/owner checks were completed before remote compile. These are source/compile receipts only; the seven new identities were **not executed** in CB1.

## 3. Compile corrections

The first remote compile attempt did not start because the temporary caller's permission ceiling was too low for the nested observer's statically requested `contents: write`. The caller alone was corrected; no reusable workflow permissions changed.

Two later compile attempts exposed ordinary C++ compile errors in the new CP2 source and were corrected minimally:

1. `ConformityRowCertificate` was aggregate-initialized because its exact-integer members make the implicit default construction unavailable.
2. One heterogeneous `auto` declaration in the independent validator was split because position and target lookups have different `std::optional` value types.

Neither correction changed the frozen CP2 contract. No Directional runtime was executed during diagnosis or correction.

## 4. Authoritative compile/package evidence

The exact successfully compiled source is:

`eb23177e6ee9cbb27cf1ee30a299911abc0e1c60`

Authoritative compile workflow:

- run: `34512397141`;
- compile job: `102989549611`;
- result/package artifact: `10166351695`, `directional-m4-cp2-cb1-package116-result-34512397141`;
- package ZIP/provider SHA-256: `c61b9900a2745454594825de81181ce982ec4b7986f40aa3b23c23e12d0e8e61`;
- diagnostic log artifact: `10166352142`, `directional-m4-cp2-cb1-package116-log-34512397141`;
- log ZIP/provider SHA-256: `3c3e3658d3f3341f108af5397f681061cb6c77be85e9dd1355fb28dba77e2dd0`;
- `build_exit=0`, `preflight_exit=0`, source status clean before configure, after configure, after build, and at packaging;
- package root `SHA256SUMS`: **28/28 verified**;
- `runtimeExecution=false` and `turnBoundary=Code+Build-only` are packaged metadata.

Mandatory exact arithmetic authority is present: `DIRECTIONAL_ENABLE_GMP=ON`, `libgmp-dev 6.3.0`, and the link receipt contains both `libgmpxx` and `libgmp`.

The eight approved compile targets all linked successfully:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Packaged executable SHA-256 receipts are:

| executable | SHA-256 |
|---|---|
| `directional_surface_cell_authority_kernel_tests` | `5efacc3ad52085a8ab76bad451bfc70c337e44a73a8f81a165f06ab1cd3041b3` |
| `directional_surface_cell_producer_tests` | `bc9c0adc1932cda698281805b70b7e7ab9f24419e8d7363ff5a23fba6a9898a1` |
| `directional_surface_cell_completion_tests` | `1701820d85d91fe674cb3dd3496669f0a49ca43e6068a170fb0277227aba094a` |
| `directional_surface_cell_validation_tests` | `303af6ab231bf88b6b618df03315c9999a27595b8b55871922935f5098a4ca5f` |
| `directional_compiled_api_tests` | `a41d8dbaa531d30bb82f3fcdaf9d069a5a13866f15fe500e7f0400911bc29ade` |
| `directional_benchmarks` | `d3940d4db3f8ebd31403b85970d9f9c98676b9374926d060aeb38682b48490af` |

## 5. Boundary and acceptance

No generated Directional binary, test, benchmark, `ctest`, test discovery/listing, CLI/GUI entry point, fuzzer, help/version command, or custom input was executed. CB1 therefore proves compile/package authority only. It does **not** prove that the new seven identities pass, that CP1 feasible schedules are runtime-preserved, or that CP2 is accepted/closed.

Accepted runtime authority remains **M4-CP1 package115 / selector373 373/373**. Stable regression accounting remains **47 events / 14 categories / 33 recurrences**, debt **5**, and accepted package authority remains **115** pending runtime review of package116.

## 6. Exact successor

**Exact next: `M4-CP2-TB1-EXEC`**, artifact-only, under `Architecture_M4_CP2_TB1_Test_Benchmark_Plan.md` using immutable package116 artifact `10166351695`. TB-EXEC must execute the seven CP2 rows twice plus the complete selector380 one identity per fresh process, preserve raw evidence, and perform no compile or source/test/fixture/selector mutation. Review/adjudication belongs to the following `M4-CP2-TB1-REV` turn.
