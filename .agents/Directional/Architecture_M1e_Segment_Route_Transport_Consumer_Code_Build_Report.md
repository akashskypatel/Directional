# M1e Segment Route Transport Consumer — Code + Build Report

**Status:** COMPILE/PACKAGE COMPLETE — immutable runtime pending  
**Turn type:** Code + Build only  
**Review policy:** `never`  
**Runtime execution:** **false**  
**Date:** 2026-08-10 UTC

## 1. Bounded objective

M1e migrates exactly one real transport-owning production seam: `surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments`.

The legacy consumer accumulated unrestricted signed integers with `totalMatching += transition.matching`. M1e replaces semantic accumulation with checked source/transition identity, typed per-step quarter-turn automorphisms, `TransitionStep`, `CanonicalRoute`, and ordered algebraic composition while preserving existing raw public/provenance representation.

The final product/test delta is exactly `src/geometry/SurfaceCellTracing.cpp` and `tests/SurfaceCellsPhase10Tests.cpp`. No public header, pipeline, validator, CMake, fixture, benchmark, periodic-holonomy, field-chart, topology/conformity/quotient, fallback/recovery, optimization, or G4 behavior was intentionally changed.

## 2. Source authority

- entering base `5df33fc11deaac697cb886d8defcaba622ec436f`;
- accepted M1d ancestor `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25`;
- first M1e implementation attempt `9edbef1fe34d60d2a507160aa4a27883cea36903`;
- final implementation `bb9cb63a36b64fe2f7c462ad864492c8352b65e8`;
- successful build/event `106e408065e5bda1eb680bc54aef007a1a2d68d6`;
- successful run/job `31345475101 / 93326482946`.

Final blobs: tracing `34372a48412213d3b4db6d0bc3e653e7d3225ef0`; Phase10 tests `eba2febae6d5a226ea2dd90035e8e5ac28bf0de4`. Preserved M1d pipeline/test blobs remain `481f58169fe73844b12d9e70660d49fa3e13f845` / `dc82faf06898d8516ddd55b2ae56c2b240c761fb`.

## 3. Implemented semantic boundary

At each ordered `VertexPathStep`, final M1e preserves existing route discovery/fan selection/barriers/transition resolution/provenance/effort; checks packed endpoints via `source_vertex`; canonicalizes `SourceEdgeTopologyKey`; checks compact provenance via `interior_transition`; converts directed matching to `QuarterTurn` + zero-shift `GridAutomorphism`; creates one observed `TransitionStep`; constructs `CanonicalRoute` only after validation; consumes `oriented_steps()` to preserve observed direction; composes typed automorphisms in order; and writes only the final quarter-turn to raw `current.matching`.

The explicit `edgeTransitions`-absent legacy transition path remains but crosses the same typed composition boundary.

## 4. Focused contracts

Exactly six `SurfaceCellSegmentRouteTransportAuthorityMigration` tests are statically packaged: multi-step composition, reverse exact inverse, modulo-equivalent signed quarter-turns, provenance preservation, malformed-authoritative fail-closed, and legacy matching typed composition.

Static M1e manifest SHA-256: `b6a1c9035b2cd15a13844f812e7261ee0e199e72d0150d9a093a59d1ce713556`. M1d/M1c/M1b/M1a/T1 static manifests are preserved. None of these tests was discovered or executed in Code + Build.

## 5. Compile correction history

Initial commit `9edbef1fe34d60d2a507160aa4a27883cea36903` failed compilation in run/job `31345156696 / 93325609589`: it passed `Eigen::Vector2i` where `GridAutomorphism` requires `LatticeTranslation` and called the hidden-friend grid `compose` as a qualified function instead of via unqualified ADL. No generated runtime executed. Log artifact `9047121549`, SHA-256 `0d330e46e11f0f884fdf478e8bf8de38ee34b4e1c9f5485d6293ba3057750596`.

Final `bb9cb63...` uses `LatticeTranslation{0,0}`, `GridAutomorphism::identity()`, and unqualified `compose`. Two v2 workflow events (`31345414148`, `31345419666`) contained invalid temporary YAML and created no jobs; they are infrastructure-only failures.

## 6. Successful build/package authority

Successful run/job `31345475101 / 93326482946` used Ubuntu 24.04 / GCC 13.3.0, Release/static/Ninja, PRE_TEST, and approved targets only. Build: **120/120**, wall **8:08.51**, peak RSS **1,848,636 KiB**, exit 0.

Command-boundary metadata records `runtimeExecution=false` and false for generated binary execution, discovery/tests, benchmarks, `ctest`, CLI/GUI/help/version, fuzzers, and custom input.

- result artifact `9047295489`, SHA-256 `74e5a1abe37d14c5cdf8a13b753b3f70b80b6a61d83ec051d3b8e4d44b8b8e9f`;
- log artifact `9047295703`, SHA-256 `9df806949994145dba689b58afcc49106cedd1aadafbff409d70705188400f52`;
- retention through `2026-08-24 00:58 UTC`;
- manifest **61/61**, SHA-256 `ae82db8c02575926fe28ede2cbd6a4738cf7ed4e7ae1576ce8778970c532bc8e`;
- package **62** regular files including manifest, 27 fixtures, 7 executables, 2 static libs.

Read-only artifact verification matched GitHub outer digests, rejected unsafe paths, and verified all 61 checksums. Source patch SHA-256 `301f236eddc3ea31374868b4f9da982965b4098d212784b65d18b0e157f31cc0`; source archive `cb408cef116008446b7c68f1f421e062826c8eb2550cead2a88df0f6bf614e55`; compile database `aa91af44338f8776d982b43ae9ef0a8ba65a58ec879c8a7266d8bf0c1bd11ce9`.

Executable hashes: producer `0a8e67953e7221daf0fe607794c3b69f2e3fb8331b91ab08a02c10d52152943e`; oracle `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`; authority `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`; validation `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`.

## 7. Expected immutable accounting

Entering producer discovery was 178 and exactly six M1e tests were added, so the following immutable turn requires producer discovery **184** and expected accounting **169 required-green + 4 direct + 9 historical/deferred red + BunnyRandom + Vase = 184**. No runtime result is inferred from static counts.

## 8. Regression disposition

No new stable regression event or recurrence is created: the first issue was compile-time and corrected before runtime; v2 failures created no jobs; final product scope remains exactly two files; no accepted runtime authority was executed/reclassified. Historical totals remain **34 events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active.

`RP-01`, `RP-05`, and primary `RP-07` are compile-complete/runtime pending at M1e; `RP-02 / TA-05` preservation is pending immutable validation.

## 9. Temporary workflow cleanup

After artifact capture/verification, all three temporary M1e workflows were removed **before** their trigger markers; then all triggers and the temporary apply script were removed. This follows the durable workflow-order rule.

## 10. Next turn

Run **M1e Segment Route Transport Consumer — immutable Test + Benchmark only** under `.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`, consuming exactly artifacts `9047295489 / 9047295703` and rebuilding/editing nothing. Any required-green or focused semantic failure remains at M1e and returns to corrective Code + Build.
