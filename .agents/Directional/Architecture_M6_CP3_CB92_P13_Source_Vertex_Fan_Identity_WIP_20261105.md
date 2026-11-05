# CB92 source-vertex fan identity — code/build WIP (2026-11-05)

Canonical turn: `M6-CP3-CB92-P13-SOURCE-VERTEX-FAN-SEED-IDENTITY`. Code + Build, compile only. This record is an incomplete checkpoint, not acceptance or promotion. Next action is **one Linux eight-target GMP/GMPXX compile-only dispatcher request**, not TB82.

## Verified code change

- Authority: RA-207 §3 exact preapproved patch, 285 lines, SHA-256 `c377b206c195613b045b0f5a431df5dc31e553035343b567cdeb2ba0751834fa`, with five single-space context lines retained.
- Exact source snapshot: `eec01a19a0bc353b450c5941fd3f403672d0cb8b`, run [42048370347](https://github.com/akashskypatel/Directional/actions/runs/42048370347), artifact `13426335889`; source checksums 6191/6191.
- Pre-application local `git apply --check`: PASS. Expected final SHA-256 values observed locally:
  - `src/geometry/SurfaceCellTracing.cpp`: `9e9b979f0976f3c1714e1dbcddd4d973b21f3268e443cff7518bbd4a987a4c7b`
  - `tests/SurfaceCellREPackageTests.cpp`: `a169667c6c6705be547b257295e6d9eb5ea2d1f933f6958370c7e806cbb28e90`
- Drive transport wrapped the unchanged exact diff body (body SHA identical), 12176 bytes, full SHA-256 `9a30a91270e83d68b6e31cbb558defc458e75366df01ee98e93487a5b16e4f91`, base `eec01a19a0bc353b450c5941fd3f403672d0cb8b`.
- Durable dispatcher event `44b10914a21e3c8edb6fed6b40472249bc1749fa`; [apply run 42050327104](https://github.com/akashskypatel/Directional/actions/runs/42050327104), result artifact `13427125715`, outer ZIP SHA-256 `03caf17d6b56e7cbc2d892484d5658402ebd127de8a3ec7755d21685dedccc0a`, drive_apply job SUCCESS, `runtimeExecution=false`.
- **Applied source commit:** `d9921cdd5a174bbb00b68387082cf08df80f97c5`. Both exact resulting Git blob SHA-1 values verified through GitHub connector at that commit: `05deb3311045c6e3114619a0b9db4a8d74717945`, `017fc8393e4d90092e9fd1f0406c8360fec22296`; these match the locally verified SHA-256 postimages.
- After successful apply, Google Drive transient patch transport required owner cleanup; the owner-authorized connector permanently deleted its exact file `16co-OMgg_wvlwef684YvuP4b5FES75kF` (SUCCESS). Redundant earlier raw Drive staging file `1oo10s3HzVcEWFjWDyF1GO1QULTYic3RB` was also deleted (SUCCESS). Preserve the exact raw patch instead in ChatGPT Library `/Directional/Work-Preservation/Directional__M6-CP3-CB92-P13-SOURCE-VERTEX-FAN-SEED-IDENTITY__base-eec01a19a0bc__work-preservation.patch` (`libfile_60d32c19c38081918d92de74e76006eb`), and transport wrapper Library `libfile_6ab9a486f62c8191a516951996f2b460`.
- Temporary source snapshot marker was cleaned in [cleanup run 42049862473](https://github.com/akashskypatel/Directional/actions/runs/42049862473), source/head after cleanup `253db330aa75a58ac0413fc4829c2de957d37d53`. The patch then advanced source head to `d9921cdd...`.

## Resume-only next action

Submit a single `compile` operation via the retained `.agents/Directional/agent-dispatch-request.json` using `source_sha=d9921cdd5a174bbb00b68387082cf08df80f97c5` and eight exact targets:

`directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.

Require one Linux Release/static GMP/GMPXX build, all eight targets, package checksums/source lineage, and `runtimeExecution=false`. No test/benchmark executable may run. Do not reapply RA-207: its exact source commit has already been verified. After compiling, update owning CB92 result/handoff and close the same turn with a final `STATUS: COMPLETE` beacon and authorized successor `M6-CP3-TB82-P13-SOURCE-VERTEX-FAN-SEED-FULL-GATE-EXEC`. No CP3/selector promotion; retain accepted CP2 491/491, stable 66/17/49, debt 1.

**Reason for WIP:** 15-minute response closeout limit reached after patch application; compile has not started. The turn is unfinished but is not blocked by a prerequisite.
