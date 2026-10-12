# R4 composite periodic/bounded-disk source-A3 ingress — Code + Build evidence (2026-10-12)

**Turn** `M6-CP3-CB1-ENTRY-R4`, continued `IN_PROGRESS`, successor UNKNOWN. This is compile-only work, not authorization for the frozen Test + Benchmark 497 selector gate.

Exact source snapshot run `38204970531`, event/source SHA `284bba01c90f100520b8a1b31ce6de897bd291c5`, artifact `11726264840`, ZIP SHA-256 `baa71455914a2cbb74289b08ade6d6d3c97b30750b07a6e1e9bb2acac074f08a`, source archive SHA-256 `58a1e6a4047d779ecec9a084ecfaa2f9b682fc54cc7797777e0d38bf5059b16c`. All 6356 source checksums passed; archive `runtimeExecution=false`.

## Exact source correction

A two-line test-only modification in `tests/SurfaceCellsPhase10Tests.cpp` changes the ingress of existing `SurfaceCellsPhase10.PolygonalCurvedDiskRetainsPeriodicAuthorityWithoutPartialSheetCells` to the existing `build_phase10_with_source_atlas(mesh, crossField, targetSize, options)` helper instead of an A3-null legacy call. The helper constructs original-source A2 and `FieldTransportAtlas::make` A3 independently from the existing authoritative `crossField`; it refuses an unavailable atlas. The composite plane+cylinder+polygonal curved-disk geometry, hard feature edges, labels, source field, exact test identity and `InvalidBoundedDiskFrontPairing` rejection assertion remain unchanged. No runtime result is inferred.

Patch `Directional_M6_CP3_R4_Composite_Reject_A3_WIP.patch`, full SHA-256 `0e4d602428bb373ba12205e2fa4babc7c754c1678ee2e74b94cb3167af572e47`, diff-body `8ba991e69ead3509ab654adf12c4255d8eb5a0726b0c87c348e2689532bfc699`, exact base `284bba01c90f100520b8a1b31ce6de897bd291c5`, intended path only `tests/SurfaceCellsPhase10Tests.cpp`. Forward/reverse `git apply --check` and `git diff --check` passed. Drive apply workflow `38205257494`, result artifact `11726777320` ZIP SHA-256 `5e22572aa8d6d69969b2fb6b478a581a8d2e78d534cf7cd5a2d9b7d9c428a4c9`, verified semantic commit `0ffc7857c544d050a70516dbaeea6092fad1b6d7`. Original staged Drive file `1IYfwRAjB4wAflht7NsodScoRoMcgn38Z` owner-deleted after verified push; user-visible patch preserved.

## Mandatory eight-target GMP/GMPXX compile-only verification

Dispatcher compile request event `9c839d9720adfcd804dc8406225e9f678a08917f`, workflow `38205407002`, job `114667758421`, compiled source `0ffc7857c544d050a70516dbaeea6092fad1b6d7`. Compile **GREEN**. Exact eight targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`. Mandatory GMP/GMPXX: `DIRECTIONAL_ENABLE_GMP:BOOL=ON`, `exactArithmeticBackend=GMP`, authoritative generated link line contains `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`. Preflight/build exit codes both `0`; final worktree status clean, `runtimeExecution=false`. Result artifact `11727133144` ZIP SHA-256 `82026586b7286971b8aadb16a6e8031f338ca4ff65b0b2facc9b0a156ef537a6`; independently verified package `SHA256SUMS` **28/28**. Diagnostic artifact `11727003381` provider SHA-256 `2a1831f5b2e48d1da7ebebc11f89b7e54be9ebda4ad7c681946ccadb5d753917`.

No Directional test, benchmark, `--gtest_list_tests`, discovery, help, version, CLI or other generated binary was run here. No frozen test identities, selectors, workflow permission, production contracts, fallback/recovery or PR metadata were changed. **No runtime first-error proof or PASS is claimed** for this regression.

## R4 continuation

All original obligations remain open: independent overfull-A3 source-feasibility Review; RA-43.4 untyped-rail migration; 39 carried endpoint regressions; 34 Phase10 positives; seven DCEL negative oracles; 88 accepted-prefix CP2 losses; six CP3 positives; genuine odd-τ multi-carrier/sector evidence and related source-star duties. CP2 491/491 accepted, R3 403/497 rejected (94 RED, 88 accepted-prefix losses), ledger 66/17/49 and debt 1 are unchanged frozen historical results. R4 continues; do not start TB497 or an invented successor.
