# M5-CP3-CB3 Code + Build Report

**Turn:** `M5-CP3-CB3`
**Boundary:** **Code + Build / runtime-free**
**Disposition:** **COMPLETE / STATIC GREEN / GMP COMPILE-PACKAGE GREEN / CORRECTION BUILT**
**Exact successor:** `M5-CP3-TB1-R2-EXEC`

## 1. Goal and scope

CB3 corrected the implementation-authority defect frozen by `M5-CP3-TB1-R1-REV`: same-region periodic promotion must derive generator carrier **and** transport from the exact A3 `sharedBoundaryInterval.span` source path through existing transition/atlas authority. The turn was product-source-only. No test, fixture, benchmark, selector, frozen definition, public header, CMake/build source, or accepted relation-validation contract changed.

Semantic mutation is exactly one file:

- `src/geometry/SurfaceCellTracing.cpp`

## 2. Exact-span correction

The corrected source is `279efa03471f1e0d6c32f57c8b395dd1cb1a93f5`.

The previous `atlas_rotation_between_faces` path scanned all branch transports in one topology region and required a path-independent aggregate face rotation. CB3 removes that reconstruction from the promotion decision. `generator_route_for_span` now:

1. resolves the exact A3 `span` through `GlobalTopologyPlan::find_arc`;
2. requires the arc to be `Mandatory`, its `sourcePath` to be canonical, and the frozen production subject's path to contain exactly one source-support step;
3. derives the exact `SourceEdgeSupport`, orientation and transition identity from that source path;
4. asks the existing `FieldTransportAtlas` for the directed transport of that exact source-edge carrier between the paired authoritative source faces;
5. stores that transport on the exact `TransitionStep` and obtains generator rotation from the resulting `CanonicalRoute::composed_transport()`;
6. derives the reciprocal periodic action from that route rotation plus the existing paired chart/lattice endpoint states.

The stop rule did not fire: the exact frozen A3 span supplied one unique directed source-edge transition/transport sequence. No whole-region search, insertion-order inference, floating geometry or guessed transport was required.

Cross-region pairs remain `HardRail`; same-region materializer rejection and CP2 checked relation failures remain unchanged. The six `M5CP3.Produced...` bodies, row408, fixtures and selector430 were not modified.

## 3. Patch transport evidence

The source patch was prepared against exact base `00c6765bf83f69cd73dd25324818f6752f5bacad` with:

- patch SHA-256 `d5cc5f23f2465e56d806789e9abd30fb9fdd3276a007a907daf84fbe8ac884fd`;
- diff-body SHA-256 `a9daad2db64f18b0eae9abf31f7a7173a295793677bc662d94ccc0c47b106142`;
- intended path `src/geometry/SurfaceCellTracing.cpp` only.

Google Drive reusable apply run/job `35555753455 / 106198975068` verified those bytes, applied them and pushed commit `279efa03471f1e0d6c32f57c8b395dd1cb1a93f5` with `runtimeExecution=false`. Result/log artifacts are `10620545484 / 10620465573`. The workflow identity could not trash the owner-created Drive file, so owner-authorized Drive deletion was performed successfully after push verification.

## 4. Static contract checks

Before compile:

- semantic diff contains only `src/geometry/SurfaceCellTracing.cpp`;
- whole-region `atlas_rotation_between_faces` reconstruction is removed from the same-region promotion path;
- generator carrier and rotation both originate from the exact `span` source path plus existing atlas authority;
- selector430 remains **430 LF rows** at SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- selector first427 remains `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- no test, fixture or selector byte changed.

## 5. Mandatory GMP compile/package

Authoritative run/job: `35555882867 / 106199345527`.

Exact compile source: `279efa03471f1e0d6c32f57c8b395dd1cb1a93f5`.

All eight standard targets compiled and linked successfully:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Preflight/build exits are `0 / 0`. Configure evidence records `DIRECTIONAL_ENABLE_GMP=ON`, `GMP found for Directional core`, and explicit `libgmpxx.so` + `libgmp.so` linkage. Every packaged source-status receipt is empty.

Candidate result artifact:

- artifact `10620415471` — `m5-cp3-cb3-result-35555882867`;
- provider/download ZIP SHA-256 `700b605167427d21823b90d942dd5bb40d1690f162285d22a20da5ad7898a1cd`;
- root `SHA256SUMS` SHA-256 `ea12d6fc6ab6752f8ef10f46f1900423e9074e62c25edba48bde5b4526623d24`, **28/28 PASS**;
- packaged source archive SHA-256 `198a6454bb3171a863be571b91ec861d1161dbab608d3114a86032ee40dc2f00`;
- diagnostic-log artifact `10620265598`, provider SHA-256 `a82f4871d40c6957f3df22f7a5d7d26b6c32a258e886c9bea09d26a04f178b14`.

`metadata/command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `preflightCompile=true`, and `semanticContracts=compiled-not-executed`. The compile log explicitly states that no generated Directional binary, test, benchmark, discovery command, `ctest`, CLI, fuzzer, help/version command or custom input was executed.

## 6. Authority and accounting

This is compile-only recovery evidence. Candidate artifact `10620415471` is **not promoted** and no produced-witness debt is discharged. Accepted runtime authority remains package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**.

The prior R1 PASS→RED of accepted ordinal408 remains the already-recorded stable `RP-01 AUTHORITY_DOMAIN_CONFLATION` recurrence. CB3 executes no runtime and creates no new stable event/category/recurrence, so corrected totals remain **50 / 14 / 36**, debt **5**.

## 7. Successor

Fresh artifact-only `M5-CP3-TB1-R2-EXEC` must consume artifact `10620415471` exactly and restart the unchanged **9 mechanism + 6 produced + selector430 = 445** process gate from process 1. No R1 semantic credit is reused. Green or semantic-RED mechanically complete R2 evidence routes to independent `M5-CP3-TB1-R2-REV`.
