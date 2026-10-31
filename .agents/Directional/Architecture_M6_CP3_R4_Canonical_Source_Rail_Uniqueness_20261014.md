# M6-CP3-CB1-ENTRY-R4 — canonical source-rail edge uniqueness (2026-10-14)

**Boundary:** Same R4 Code + Build turn, PR #8 draft/unmerged; no tests/benchmarks, successor, frozen selector497, ABI, or acceptance change.

## Orphan mailbox first live proof

User-directed workflow/policy migration is atomic commit `618c6d0d41729e7516ebd2eef04d2cbf11110aae`. Snapshot smoke [run 38605863426](https://github.com/akashskypatel/Directional/actions/runs/38605863426) succeeded (validate/snapshot/mailbox); `workflow-mailbox` orphan ref carries global `latest.json`, per-key `.workflow-mailbox/repo-source-snapshot/latest.json`, and immutable `runs/38605863426-attempt-1.json` even after subsequent runs. Exact event/source `14411a89a05e2be5ca652bb674c9536393117679`, result artifact `11915642777`, ZIP SHA256 `9e5da6ada64d7e76bd4d12f7210a9844a4b99990c06b94e822517bd84c9dff57`, source tar SHA256 `ffc9803954b4cbce92ce8715a55fbcb40315013c2e680146c0494d5aeb710938`, **5593/5593** recursive SHA256SUMS verified, `runtimeExecution=false`. The source branch's corresponding mailbox path is absent. The consumed snapshot trigger was removed in `0b17cd77e2a7cff58db981ecf140f3ce8dd8e55c`.

## Source-integrity correction

The builder in `include/directional/geometry/AdaptiveFeatureMap.h` emits one `AdaptiveFeatureEdge` per canonical source-edge pair. The direct `build_authoritative_surface_cell_rails` first producer previously accepted two separately sourced feature records referring to the same physical source edge and could publish duplicated support across distinct rails. This is a static direct-input integrity defect, not a measured runtime regression.

- `src/pipeline/RemeshPipeline.cpp`: at common `append_edge_interval` source authority boundary, record canonical published source-edge keys and fail a repeated emission with existing `InvalidFeatureEdge` and the exact second feature-edge index.
- `tests/SurfaceCellREPackageTests.cpp`: extend existing `SurfaceCellClosedProductContracts.RailBuildRejectionCarriesFailureWithoutConsumableRails` without introducing a test identity. Preserve real two-distinct-rail positive; add third forged standalone reversed `(1,0)` edge duplicating `(0,1)`, expect rejection and `failedEdgeIndex=2`.
- Exactly two paths, +9/+19, zero deletions. Full-index patch base `14411a89a05e2be5ca652bb674c9536393117679`, full SHA256 `7c4755085fbbfbb140ecefa9323d67a318f368c5860a6c889bafbfaaab843b92`, diff-body SHA256 `a4a91009cbae948546e369f9ce122e216212b6d13a8572e286920993154aaf0d`. Static diff, forward/reverse exact-source patch checks pass. No local build.

Apply [run 38612798933](https://github.com/akashskypatel/Directional/actions/runs/38612798933) succeeded with artifact `11919115506`, outer ZIP SHA256 `15cdfcb4136b33e18e08c67710ee4b360a11b2c7f7982572463f05076fad2558`, exact base/patch hashes and `runtimeExecution=false`; applied semantic commit `5ecaa2acbec9a03622e14e6afac4dfc71763778f`. Independent compare confirms exactly the intended two paths. Consumed Drive staging permanently owner-deleted.

## Remote compile and carried obligations

Mandatory eight-target GMP/GMPXX compile requested at dispatcher commit `e0ff9fd4f31db6307c6127371684117e98550b39`, pinned semantic source `5ecaa2acbec9a03622e14e6afac4dfc71763778f`, orphan mailbox key `m6-cp3-r4-duplicate-canonical-edge-compile`. [GMP compile 38613136344](https://github.com/akashskypatel/Directional/actions/runs/38613136344) **GREEN**: compile job `116021476447`, immutable result artifact `11919172109`, outer ZIP SHA256 `3158307c79c5c6ea1fd1b553bcf2b8209e5811cbac7966d89d131634776ddab5`, inner source TAR SHA256 `a0c25ccfecada0f28143ef3b1c74303bf90752500dae616a33edfa6205becaec`, 28/28 manifest, 8/8 required targets, preflight/build 0/0, CMake GMP ON, generated `libgmpxx.so` and `libgmp.so` link, all five source-status snapshots empty, `runtimeExecution=false`. The archived source contains the new guard and unchanged-identity test. Compiled, **not executed**; no TB, benchmark or acceptance promotion. No runtime PASS or benchmark.

R4 still owes independent RA-43.1 source-selected branch/filled-side Review, RA-43.4 global diagnostic disposition, RA-47.12 runtime liveness, 39/34/seven/88/six historical regressions, genuine organic D1/D2/D3/D5/A6/A7 and produced odd-τ multi-carrier. Only future authorized artifact-only Test+Benchmark and independent Review may accept runtime recovery.
