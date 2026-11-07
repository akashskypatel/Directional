# Chart-binding cache Code + Build continuation (2026-10-31)

Canonical turn: `M6-CP3-CB64-P13-CHART-BINDING-CACHE`. This is the **COMPLETE** Code + Build record. It documents compile evidence only, not runtime acceptance.

## Frozen source and patch
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 draft.
- Starting snapshot/event commit: `28d97499d12d7664034eae2e60c5f8c599596819` (run `41220370685`, artifact `13049582949`; archive SHA-256 `4fca80b34615d74e1f82d4d18de50c1efa2d9de90fbfb762c9d896d2e4c7d7d6`).
- GitHub comparison to `e1fd0e4b7560c4fa5bde96853b978d336c522e8f`: no changes in `src/`, `include/`, `tests/`, `benchmarks/`, `cmake/`, or root `CMakeLists.txt` before application.
- RA-188.8 exact diff body SHA-256 `fad8986caf897b4fc5eba3f9e667f30518077b81143823e7b65c65314f536c1e`. Transport patch SHA-256 `3e7f1cf1884eba033452505faa74af3bf6a54dc1824ad1b0e28570d09105c2a0`, base `28d97499d12d7664034eae2e60c5f8c599596819`; intended paths only `include/directional/geometry/SourceChartTransitions.h` and `tests/SurfaceCellDesignAcceptanceTests.cpp`.
- Exact `git apply --check`, `git diff --check`, and numstat passed (7/4 and 2/2). Output file SHA-256: `aa981c5a916f0ddfff0f4f78fd5acccd3e33148ccbce7a9a7a42f3d1cad256dd`, `fff33d6c1f2b99a92af22ac7fcf24b14ab735ef621eb443a67e5a14ba2422590`.
- `drive_apply` dispatcher run `41221053853`, result artifact `13050485170`: **success**, applied semantic commit `d56d990580163f4fd0ceda4137f7ecd16ceb6027`; `runtimeExecution=false`. GitHub compare confirms only the two intended files. Temporary Drive file ID `1IN1fSfj9ovc31R398SXtwBusBmkXkCMc` was permanently deleted via owner-authorized connector after successful application.

## Linux compile/package — SUCCESS (runtime not executed)
- Compile dispatcher request commit `373c978f2337cd1a2b0863f242d946c297071f1d`; mailbox key `m6-cb64-chart-binding-compile-20261031-v1` on orphan `workflow-mailbox`.
- Exact immutable semantic source `d56d990580163f4fd0ceda4137f7ecd16ceb6027`; [run `41221202501`](https://github.com/akashskypatel/Directional/actions/runs/41221202501), compile job `124596020278` **success**, mailbox `result=success` and `source_sha` exact.
- Result artifact ID `13050072901`, ZIP SHA-256 `5ef36429396d3d21e9c7b184cd10cd3ef6bdcfc3333d55415a0440631aebad00`; dedicated diagnostic artifact ID `13050112829`, ZIP SHA-256 `105591de8d4b8d58f3992d2a60e405eea31a579e366a842a0fdb3e1cda0248b1`.
- Packaged `SHA256SUMS` SHA-256 `2bb9aec67ae9b08aad0692f1c4bd691df71a731c2370f7411a2a8ac0860d1394`: **28/28 checksum entries verified**, with `./` manifest paths normalized only for ZIP member lookup. Source archive `source/source-d56d990580163f4fd0ceda4137f7ecd16ceb6027.tar.gz` SHA-256 `79a084ec7ee6c930f9284027a3b33f937767fdd32b3447d5bb1275643e8726cf`.
- Exactly eight compiled targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- `preflight-exit-code=0`, `build-exit-code=0`, final source status empty. Command boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `preflightCompile=true`. Generated link command contains both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` with `GMP_ROOT=/usr`; Release/static target package with tests/benchmarks ON and CLI/GUI OFF. No generated Directional binary, runtime test, benchmark, discovery, CLI, or GUI command ran.
- Cache: fixed-key `directional-ccache-Linux-gcc-13.3.0-release-static-gmp-pretest-v2`, 143 cacheable calls, 101 hits, 42 misses. This is build optimization, not semantic evidence.

## Authorized continuation
- **Next formal turn, only after final COMPLETE beacon:** `M6-CP3-TB63-P13-CENSUS-FULL-GATE-EXEC`, artifact-only Linux TB-EXEC; the exact package above is frozen, and no rebuild/repair is permitted.
- Run the unchanged P8 harness `--execute` twice, one 863-row TB58 full gate with deferred ledger v4 82, plus a distinct 3-row OBSERVE-only TB63 P13 census without ledger. Required inputs and pre-registered outcomes remain frozen by [RA-188 §5](Architecture_M6_CP3_DEFN_P13_Probe_Adjudication_20261031.md). TB63 must verify source and package hashes and preserve executable mode bits when extracting.
- A green compile/package does **not** claim Cylinder PASS on Linux or any production acceptance. CP2 491/491 remains accepted; TB62 863/863 remains the latest executed full-gate Linux result until TB63 finishes. Stable regression accounting 66/17/49, debt 1, ledger v4 82, selector497 unpromoted; no changes.
