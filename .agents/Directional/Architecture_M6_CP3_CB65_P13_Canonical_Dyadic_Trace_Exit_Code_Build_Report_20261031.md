# CB65 canonical dyadic trace exit — Code + Build (2026-10-31)

Canonical turn: `M6-CP3-CB65-P13-CANONICAL-DYADIC-TRACE-EXIT` — **COMPLETE** as a compile-only turn, not runtime acceptance.

## Exact source and patch
- RA-190.8 exact four-file patch on semantic source `d56d990580163f4fd0ceda4137f7ecd16ceb6027`. No intervening changes to `src`, `include`, `tests`, `benchmarks`, `cmake`, or root `CMakeLists.txt`.
- Snapshot `ca6335c9eee89f9b36d7d55353a7ef0f00b6675f`; source-snapshot run `41253264839`, artifact `13060924885`, ZIP `34c98005b2eccda248b2ba412280de81109bc77a508583c5132e3c6f6fb758c5`.
- Exact patch SHA-256 `ed125319bb38f9ed5352c8b18b3513a53dc5e994d3e7f964d27f82341ac6f91b` (9637 bytes), `git apply --check` and `git diff --check` verified. Exact numstat: 26/1 `SurfaceCellTracing.h`, 26/2 `SurfaceCellTracing.cpp`, 79/0 `FieldAlignedCurveNetworkTests.cpp`, 2/1 `SurfaceCellDesignAcceptanceTests.cpp`. All four RA-190.5 resulting file SHA-256 checks matched.
- Drive transport patch `065c9bb029f4041f4e6881bbf032e9fd3133b7fb9490bba4735cac1b0cf85a2a`; [apply run 41253565883](https://github.com/akashskypatel/Directional/actions/runs/41253565883), artifact `13062645897`, result success; exact source commit `dbc38661efabdfa051f48f8f71ee3c604841842c`. Four-file GitHub compare matched numstat. Google Drive staging file deleted after success.

## Linux GMP/GMPXX compile/package — SUCCESS (no binary runs)
- Exact immutable source `dbc38661efabdfa051f48f8f71ee3c604841842c`, [run 41253674256](https://github.com/akashskypatel/Directional/actions/runs/41253674256); artifact `13062413347`, ZIP SHA-256 `1a2ab39d43742cfa5d3b7b2c09242482ef63712b2efbaf9644a54b83e2b0948b`.
- Packaged root `SHA256SUMS` SHA-256 `0c69aaea7a2eea6d1a9fe1fcd78724a0c3a320f757357de0b07aece738286ff5` with **28/28** entries verified. Source archive SHA-256 `c30b58f0aa85375480ed7d794c543faa59f5c613480dba1aaa3df0647cbd3ba5`.
- Eight Release/static targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`; tests and benchmarks were built but **not executed**; CLI/GUI OFF, GMP/GMPXX linked.
- Build workflow `runtimeExecution=false`; no Directional binary, test, benchmark, CLI, or GUI ran in this turn.

## Successor boundary
The exact successor is `M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-EXEC`. TB64 must verify this immutable package and run the pre-registered 866-row manifest (`289d887c7d1eedcdfdc42c5869055915abf5aec8a0436a62e67acf566a99dbce`) with ledger v5 81 (`fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`), membership 947, plus the separate 3-row P13 census (`3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`). Expected: Cylinder PASS, BunnyRandom RED `CutTransportDomainIdentityMismatch`/`cutChi=-3`, Vase RED at completion `SideSubdivisionRepair:InvalidInputIncidence` with no A4 exact-magnitude failure. No TB64 gate execution or CP3 acceptance is claimed here.

Accepted CP2 491/491, stable regression accounting 66/17/49, debt 1, selector497 unpromoted, and macOS O16 remain unchanged.
