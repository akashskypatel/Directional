# M3-CP4c-3-CB30 — Uncut-Component Certificate Census + Seed Restoration Code + Build Report

**Turn:** `M3-CP4c-3-CB30`
**Verdict:** **COMPLETE / COMPILE GREEN / RUNTIME NOT EXECUTED / SEMANTICALLY UNACCEPTED**
**Date:** 2026-09-04

## Scope and authority

CB30 implemented only the runtime-free successor frozen by `Architecture_M3_CP4c3_TB25_Independent_Review_Record.md` CJ6–CJ9. It does not claim any runtime result, does not choose a certified owner among disagreeing seeds, and does not alter the accepted 1–365 boundary.

- frozen reviewed source: `7fd50bee894d9f8949eb78dac4cc647078f5d2fd`;
- source-snapshot trigger/control source: `b8a8b404a381fbd5cd2f1c900261ac300affeb1a`, semantically identical to the frozen source except the approved snapshot marker;
- semantic patch commit: `0ff22eafd61c0500dac8c8c69bd07454f029dafe`;
- exact compile source after temporary Drive-control retirement: `e045bf7147afc02bd90eff4822e4b609edbaba66`;
- no product/test/selector/build-semantic change exists between `0ff22eaf...` and `e045bf7...`; only temporary Drive-apply caller/marker retirement occurred;
- selector 405: `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_405.txt`, **405 identities**, LF SHA-256 `615370b65e590dadb59d7a233c6ce74b7dc8cb46a1f40fd3ea5a44257583aae7`;
- selector 403 is its exact 403-line prefix, SHA-256 `60ff6daa0e1dc71fe9c856ee9559d665628b756ed634f70ffce5881ec2514007`;
- selector 401 remains its exact 401-line prefix, SHA-256 `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869`;
- selector 397 remains byte-frozen, SHA-256 `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`.

## CJ6–CJ9 implementation

**CJ6 — three owner-independent censuses.** `SurfaceCutGraphCellularityCertificate` now publishes, for every uncut source-face component and on the ownership-failure path, (1) a complete boundary-edge census including independently derived barrier class, opposite-face trace-cut state and side-owner presence; (2) an interior arc-incidence census carrying arc kind and the two dart-orbit identities; and (3) a source-vertex transit census carrying the incident uncut faces and whether a pair remains adjacent across a non-barrier source edge. Publication is computed independently of an established source-face owner. The mechanical production witness asserts publication/completeness, not a predicted value.

**CJ7 — restore the dropped seed source without certification by heuristic.** Component seeding again admits both pre-CB27 sources: a neighboring component with a single established owner and unique per-edge side evidence. A singleton seed set may publish `Established`; a multi-seed set publishes `Conflicting` with the full seed multiset/per-edge attribution. No winner is selected, no barrier is added/removed, and `proves_cellularity()` remains the strong ownership-totality predicate.

**CJ8 — one contract per gate.** Ordinals 389, 390 and 393 now gate their own embedded-cellularity contracts through `proves_embedded_cellularity()` instead of additionally demanding source-face ownership totality. Ordinal 390 replaces the refuted `distinctCount > 1` hypothesis with publication/completeness and equality between the attribution distinct count and the component seed count. Ordinal 398 is untouched and remains the sole gate on complete certified ownership.

**CJ9 — selector 405.** Selector 405 appends exactly two gating identities to frozen selector 403:

1. `SurfaceCutGraph.UncutComponentArcIncidenceCensusPublishesOnOwnershipFailure`
2. `SurfaceCutGraph.VertexTransitCensusNamesAFaceSeparationNoSourceEdgeBarrierCanCarry`

The first proves that all three CJ6 censuses are available and complete even with no established owner. The second is an independent constructed vertex-transit falsifiability witness. The first 403 lines are byte-identical to selector 403.

## Engineering review

- Material assumption: trace arcs carry `GlobalTopologyArc::sourceFaces`; mandatory/cut arcs are source-edge-supported and therefore belong to the independent boundary-barrier census rather than the component-interior arc census.
- Smallest sufficient design: one shared internal census builder (`UncutComponentCertificateCensus.h`) computes the three observations from the embedded graph/source topology/partition/barriers without introducing a new ownership authority.
- No broader partition redesign, barrier change, heuristic winner selection, unrelated refactor, or predicate weakening was performed.
- The constructed vertex-transit witness avoids default construction of topology-key types and asserts the missing-separator capability independently of the production prediction.

## Files changed

- `include/directional/geometry/SurfaceCutGraph.h`
- `src/geometry/SurfaceCutGraph.cpp`
- `src/geometry/UncutComponentCertificateCensus.h`
- `tests/FieldAlignedCurveNetworkTests.cpp`
- `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_405.txt`

## Final compile evidence

Compile-only run **`33927223741`**, workload job **`101198287660`**, completed **SUCCESS** against exact source `e045bf7147afc02bd90eff4822e4b609edbaba66`.

- configuration: Ubuntu 24.04, GCC 13.3.0, CMake 3.31.6, Ninja 1.13.2, Release/static, `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`;
- GMP/GMPXX: enabled, found under `/usr`, and linked into the authority-kernel target;
- preflight target `directional_core`: exit 0;
- approved targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`;
- build exit/compile status: 0 / 0; source remained clean;
- immutable compile result/package artifact: **`9957324848`**, provider SHA-256 **`7ea9446f2e8cde520b8f7570cc62ba189ccffe801bd68a298f56560c661f81de`**;
- persistent compile-log artifact: **`9957325254`**, provider SHA-256 **`626b1d49c46f9bdc09f7f7ef5fb83d9ed5b1f1d51dd667f98891d7f8a9a8153a`**;
- recursive package manifest self-verification: PASS;
- compiler cache restored and refreshed under the durable compatible key `directional-ccache-Linux-gcc-13.3.0-release-static-gmp-pretest-v2`;
- `runtimeExecution=false`.

The compile workflow explicitly records that no generated Directional binary, test, benchmark, discovery command, `ctest`, CLI, fuzzer, help/version command, or custom input executed.

## Acceptance and accounting

CB30 is **compile-green only** and does not provide semantic acceptance. The latest valid semantic runtime remains TB25-R1 at **393 PASS / 10 RED**, accepted **365/365**, RED ordinals `366,367,368,369,370,374,389,390,393,398`. Stable regression accounting therefore remains **44 events / 14 categories / 30 recurrences** and produced-witness debt remains **5**. CB30 becomes semantic M3 package **91**. CP4c-3 remains **OPEN**.

## Exact successor

**`M3-CP4c-3-TB26-EXEC`** — artifact-only runtime execution of selector 405 against immutable CB30 artifact `9957324848` under `Architecture_M3_CP4c3_TB26_Artifact_Only_Test_Benchmark_Plan.md`. TB26-EXEC must not configure, compile, relink, repair the package, mutate source/tests/fixtures/selectors, interpret a semantic RED as authorization to patch, or perform independent review. Its direct successor is `M3-CP4c-3-TB26-REV` for diagnostic review of the recorded runtime evidence.
