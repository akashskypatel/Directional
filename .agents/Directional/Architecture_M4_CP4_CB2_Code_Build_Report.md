# M4-CP4-CB2 — orchestration/package closure Code + Build report

**Turn:** `M4-CP4-CB2`
**Result:** COMPLETE / BUILD GREEN / RUNTIME NOT EXECUTED
**Semantic implementation:** `024427475aebf438c678caa27c35415f32c31198`
**Exact compiled source:** `ad54c12774e10480fd3cef8138cacb8d5dec1529`
**Compile run/job:** `35413725768 / 105818192513`

## 1. Scope and immutability

CB2 repaired only the two deterministic TB1 orchestration/package-closure defects. Product, test, fixture, benchmark, CMake and selector semantics were not changed. Comparing CP4 semantic implementation commit `024427475aebf438c678caa27c35415f32c31198` through the completed pre-CB2 head `ad54c12774e10480fd3cef8138cacb8d5dec1529` shows no changes under `include/**`, `src/**`, `tests/**`, `benchmarks/**`, `cmake/**` or `CMakeLists.txt`; later CB2 repository changes are control/documentation only. Selector427 remains byte-identical at **427 LF rows**, SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`, owner partition **30 / 281 / 75 / 41**.

No generated Directional binary, test, benchmark, discovery/list/help/version command, CLI, fuzzer or custom input executed in CB2. Compile evidence records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and `semanticContracts=compiled-not-executed`.

## 2. Mandatory all-eight GMP compile/package

The only compile implementation was durable `.github/workflows/agent-compile-reusable.yml`. It compiled all eight standard targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and `directional_benchmarks`.

Run/job `35413725768 / 105818192513` completed successfully. Preflight `directional_core` exited `0`; the full build exited `0`. Fixed cache key `directional-ccache-Linux-gcc-13.3.0-release-static-gmp-pretest-v2` recorded 129/129 cacheable calls, **127 hits / 2 misses**.

Candidate package authority:

- result artifact `10575545321`, provider/package ZIP SHA-256 `602632ed05f2d6e8a4c9ccbfb1ef135417b1d1e2eb30c2c29e74892007f7ba00`;
- diagnostic log artifact `10575465548`, provider SHA-256 `2ae9a797ccc3f0d5f64f3acd0d2570803859ae775236b804286729a85dd2e64c`;
- packaged source archive SHA-256 `781155c61419f999ebb9631136ca24e998f01dff0c160b071240c946b4afa4ed`;
- fresh package `SHA256SUMS`: **28 entries**, complete verification PASS;
- exact packaged source `ad54c12774e10480fd3cef8138cacb8d5dec1529`;
- actual clean receipts `source-status-before-configure.txt`, `source-status-preconfigure.txt`, `source-status-after-configure.txt`, `source-status-after-build.txt`, `source-status-final.txt`: all present and empty;
- GMP link evidence binds both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`.

All six packaged executables have mode `0755`. The four selector-owner executables are present/executable, including `directional_surface_cell_validation_tests`. This closes TB1 root cause B at build/package level: the fresh package contains every frozen selector owner before later runtime begins.

## 3. Corrected frozen TB1-R1 control surface

The corrected retry harness is `.agents/Directional/turn-payloads/m4-cp4-tb1-r1-harness.sh`, historical recovery commit `cfb6d5a97419fb119c8f73c02d9c42a2235db21b`, **19,871 bytes**, SHA-256 `4b956829e4b656ccc71f00c781028fcb08452cad995cbcdfaaacde314954d29f`. Relative to frozen TB1, only candidate identities, TB1-R1 scratch/result/log names, retry label and the clean-receipt correction changed: `source-status-preconfigure.txt` replaces nonexistent `source-status-after-package.txt`. Owner mapping, six focused rows, exact 427-row selector replay, 433-row ledger, benchmark zero, no-discovery/no-repair boundary and immutable postflight are unchanged.

The corrected caller is `.github/workflows/m4-cp4-tb1-r1-exec.yml`, historical recovery commit `7ca49c0b345b3e6baa50b7e6718d9909125fb77f`, **4,974 bytes**, SHA-256 `617e9e3634cccffd7a68ab2c30e82fb5bc48026823232ada59eae81e89a9790f`. Schema validation run `35413925663` is GREEN; validation result/log artifacts `10575590440 / 10575615384` have provider SHA-256 `30f6bfbd1bfe4aee1fe1628f93fa17687ef8fbb82190c9927bdaa9770538562b / 322cdf50678b98e2d936c67feb3b4fb6a21d63fb03d43cc2680df707b66c36c9`. The R1 caller/harness were **not executed** in CB2.

Closeout transport provenance: the first documentation-apply trigger, run `35414329844` at event SHA `a8824a40c4633b06900706f7674c6b91d253dd59`, was an invalid-workflow startup failure with **zero jobs** because the temporary caller left a colon-bearing `commit_message` as an unquoted YAML scalar. It applied nothing and executed no runtime. The caller was corrected without touching the marker, then retry run/job `35414510032 / 105820380738` schema-validated, verified the exact staged patch, and pushed documentation commit `114b1fea22aa8008b7e311b8b6aafcb6c6f2609c`; result/log artifacts are `10575616010 / 10575556059` with provider SHA-256 `03627d906411f6d30729f63e3c4f18037bf56cab60b8a625d71ee9ba71ce5c0a / 9b7996bc27df4ab7957a3d4cd0f05926a5269e4bddfc6db9194ea31bed9e394b`. The workflow reported owner-side Drive retirement required; the exact staged file was then permanently deleted through the owner-authorized Drive control plane.

## 4. Classification and authority

Both deterministic TB1 orchestration causes are correction-built without semantic edits. This is build/orchestration closure, not semantic acceptance. Candidate artifact `10575545321` is **not promoted** by CB2. Accepted current M4 runtime authority remains package `10565723112` / exact source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**. Stable regression accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

Exact successor: **`M4-CP4-TB1-R1-EXEC`** under `Architecture_M4_CP4_TB1_R1_Artifact_Only_Test_Benchmark_Plan.md`.

## 5. Turn cleanup provenance

Temporary workflow callers were deleted first. Mandatory batch cleanup then ran as `35414587311 / 105820587254` from event SHA `83ba4ea27ba8d37487469a3148ba7866a9f769c8` and pushed cleanup commit `9e2c2bfc26c9e84da15f51fae2805eda0047f68a`. Cleanup result/log artifacts are `10575038087 / 10574788232`, provider SHA-256 `2dad7277efe729dd80e6111028ea694bec73e71c29395c0da65efa8739eb17d2 / baa6d3dce5f998bd21910f43dea5fdf4cef6b9977a5daa842fb8ab93cb5364d6`.

The cleanup removed the CB2 source-snapshot marker, compile marker, schema marker, closeout-apply marker, frozen retry harness copy and cleanup manifest after all exact recovery hashes/commits were durably recorded. It deleted five PR conversation comments and zero inline review comments before publishing its observer. The cleanup workflow verified the repository workflow inventory contained only the seven durable workflows. `runtimeExecution=false` throughout cleanup.
