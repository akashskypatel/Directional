# M1e Segment Route Transport Consumer — Code + Build Report

**Status:** COMPILE/PACKAGE COMPLETE — immutable runtime pending  
**Turn type:** Code + Build only  
**Review policy:** `never`  
**Runtime execution:** **false**  
**Date:** 2026-08-10 UTC

## 1. Bounded objective

M1e migrates exactly one real transport-owning production seam:

`surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments`

The legacy consumer accumulated unrestricted signed integers with `totalMatching += transition.matching` and normalized only after the route. M1e replaces that semantic accumulation with checked source/transition identity, typed per-step quarter-turn automorphisms, `TransitionStep`, `CanonicalRoute`, and ordered algebraic composition while preserving the existing raw public/provenance representation.

The final product/test delta is exactly:

- `src/geometry/SurfaceCellTracing.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp`.

No public header, pipeline, validator, CMake, fixture, benchmark, periodic-holonomy, field-chart, topology/conformity/quotient, fallback/recovery, optimization, or G4 behavior was intentionally changed.

## 2. Starting and final source authority

| Authority | Value |
|---|---|
| Entering branch/base for M1e | `5df33fc11deaac697cb886d8defcaba622ec436f` |
| Accepted M1d ancestor | `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25` |
| First M1e implementation attempt | `9edbef1fe34d60d2a507160aa4a27883cea36903` |
| Final corrected M1e implementation | `bb9cb63a36b64fe2f7c462ad864492c8352b65e8` |
| Successful build-event commit | `106e408065e5bda1eb680bc54aef007a1a2d68d6` |
| Successful workflow run/job | `31345475101 / 93326482946` |

Final packaged product/test blobs:

- `src/geometry/SurfaceCellTracing.cpp` — `34372a48412213d3b4db6d0bc3e653e7d3225ef0`;
- `tests/SurfaceCellsPhase10Tests.cpp` — `eba2febae6d5a226ea2dd90035e8e5ac28bf0de4`.

Preserved accepted authority blobs include:

- M1d `src/pipeline/RemeshPipeline.cpp` — `481f58169fe73844b12d9e70660d49fa3e13f845`;
- M1d `tests/SurfaceCellTransitionQuotientTests.cpp` — `dc82faf06898d8516ddd55b2ae56c2b240c761fb`;
- tracing header — `b87e37676a980162e7ef3ac1fa9d954ce2199ad2`;
- `CanonicalRoute.h` — `542b5475ac407ae4541e2ac36f298a727403aff4`;
- `AuthorityIds.h` — `3892126eb7646ac6e1cd47bf0b139286d329b73d`;
- `LegacyAuthorityAdapters.h` — `e23fb460f3b435c8ea9d5958b3d9c9cd813899b6`;
- `GridAutomorphism.h` — `b3e8128707eea56ca52377385758f390e3c5e284`;
- M1b tests — `466e2bbd000413ee60c77cc06fe707641dbe4740`;
- M1a tests — `9dcdab568e204026eb0c2aebc1b43cd8de8db62c`;
- T1 oracle tests — `28932c8c2dbe844b62f8fe848e6ebb9ef67550de`;
- direct acceptance tests — `aff7894aae3397bef47be777a8bf7e2fbb0c27ef`.

## 3. Final M1e implementation boundary

At each ordered `VertexPathStep`, the final implementation now:

1. preserves existing route discovery, source-vertex fan choice, topology-region barriers, `resolve_branch_transition`, source provenance lookup, and matching effort;
2. decodes packed source-edge endpoints only at the compatibility boundary and validates both through `LegacyAuthorityAdapters::source_vertex`;
3. constructs semantic edge identity with `SourceEdgeTopologyKey::make` and requires canonical reserialization to reproduce the supplied packed key;
4. validates the existing compact provenance/index through `LegacyAuthorityAdapters::interior_transition`;
5. converts directed `transition.matching` to `QuarterTurn::from_integer` and a zero-shift `GridAutomorphism` using `LatticeTranslation{0,0}`;
6. builds one forward observed `TransitionStep` per route crossing;
7. constructs `CanonicalRoute::from_observed_steps` only after the route validates;
8. consumes `typedRoute.oriented_steps()` so canonical storage cannot reverse behaviorally observed route direction;
9. composes each step using the typed grid-automorphism operation (`compose(step.transport(), routeTransport)`; apply prior accumulated transport first, then the new step under the kernel convention);
10. writes only the final semantic quarter-turn value back to legacy `current.matching`;
11. preserves existing ordered `transitionSourceEdges`, `transitionSourceTopology`, singular last-edge compatibility storage, and accumulated effort.

The explicit `edgeTransitions`-absent legacy transition path remains available, but its route transport now crosses the same typed composition boundary before the raw matching write.

## 4. Focused contract package

Exactly six new production-path contracts are statically packaged under `SurfaceCellSegmentRouteTransportAuthorityMigration`:

1. `MultiStepVertexFanComposesTypedRouteTransport`;
2. `ReverseObservedRouteUsesExactTransportInverse`;
3. `EquivalentSignedQuarterTurnsComposeSemantically`;
4. `RouteTopologyAndCompactTransitionProvenanceRemainUnchanged`;
5. `MalformedAuthoritativeStepMetadataFailsClosedWithoutFallback`;
6. `LegacyMatchingFallbackUsesSameTypedRouteComposition`.

Static M1e manifest SHA-256: `b6a1c9035b2cd15a13844f812e7261ee0e199e72d0150d9a093a59d1ce713556`.

Preserved static manifests remain exact:

- M1d focused six — `e6d1932a71ee365249d78869c541eb05a55718b4a675f53d5f2afd0a58abee7a`;
- M1c focused six — `4cb94bd2afc6bc9430a138f794d4395a2847af2e8631e177b86e784c01cf1055`;
- M1b focused six — `a536c0772bc90b8fe3c91dd466b1d515339232bbcaf7c807956fdbfbfeea9320`;
- M1a authority 14 — `d0fc5ed736b048d5b72136fe17ce579661b3c65ca9118f01cfcbefc35ba8d79d`;
- T1 oracle 29 — `909a53d28c0c5eaa3d8759c95b55a0ff664074259153325e703ccd0e371004bb`.

These tests were **compiled only**. None was discovered or executed in this turn.

## 5. Compile correction history

The first bounded implementation commit `9edbef1fe34d60d2a507160aa4a27883cea36903` failed compilation in workflow run `31345156696`, job `93325609589`. The code had used two APIs incorrectly:

- `Eigen::Vector2i::Zero()` was supplied to `GridAutomorphism.shift`, whose actual type is `authority::LatticeTranslation`;
- the hidden-friend grid-automorphism `compose` was called as `authority::compose`, rather than by unqualified ADL.

The failure occurred during compilation; no generated Directional binary, test discovery, test, benchmark, `ctest`, CLI/help/version command, fuzzer, or custom input executed. Its detailed-log artifact is `9047121549`, SHA-256 `0d330e46e11f0f884fdf478e8bf8de38ee34b4e1c9f5485d6293ba3057750596`.

The correction was intentionally surgical: final commit `bb9cb63a36b64fe2f7c462ad864492c8352b65e8` replaced the shift with `LatticeTranslation{0,0}`, initialized with `GridAutomorphism::identity()`, and used unqualified `compose` for ADL. No scope expansion occurred.

Two attempted v2 workflow events (`31345414148`, `31345419666`) had invalid temporary YAML and created no jobs. They are infrastructure-only failures: no product source mutation, configure/build, or generated runtime resulted from those runs, and they are not regression evidence.

## 6. Successful Code + Build authority

Successful run `31345475101`, job `93326482946`:

- Ubuntu 24.04 / GCC 13.3.0;
- Release/static/Ninja;
- `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`;
- approved compile targets only;
- build **120/120**;
- build wall time **8:08.51**;
- peak RSS **1,848,636 KiB**;
- exit status 0.

The workflow activity log and package command boundary explicitly record:

- `runtimeExecution=false`;
- generated Directional binary executed = false;
- GoogleTest discovery executed = false;
- tests executed = false;
- benchmarks executed = false;
- `ctest` executed = false;
- CLI/GUI/help/version executed = false;
- fuzzer executed = false;
- custom input executed = false.

Compile success establishes code/build validity only. M1e semantic acceptance is pending the following immutable Test + Benchmark turn.

## 7. Immutable package authority

| Evidence | Value |
|---|---|
| Result artifact | `9047295489` — `m1e-segment-route-transport-code-build-v3` |
| Result ZIP SHA-256 | `74e5a1abe37d14c5cdf8a13b753b3f70b80b6a61d83ec051d3b8e4d44b8b8e9f` |
| Log artifact | `9047295703` — `m1e-segment-route-transport-code-build-v3-logs` |
| Log ZIP SHA-256 | `9df806949994145dba689b58afcc49106cedd1aadafbff409d70705188400f52` |
| Retention | through `2026-08-24 00:58 UTC` |
| Recursive manifest | **61/61**, SHA-256 `ae82db8c02575926fe28ede2cbd6a4738cf7ed4e7ae1576ce8778970c532bc8e` |
| Regular package files | **62** including manifest |
| Fixtures | **27** |
| Executables | **7** |
| Static libraries | **2** |

Read-only verification after artifact download established:

- both outer ZIP SHA-256 values exactly match GitHub artifact digests;
- neither archive contains absolute or `..` traversal paths;
- all **61/61** recursive package checksums pass;
- build authority identifies base `5df33fc...`, failed compile commit `9edbef1...`, final implementation `bb9cb63...`, event `106e408...`, run `31345475101`, PRE_TEST, and `runtimeExecution=false`;
- source patch SHA-256 `301f236eddc3ea31374868b4f9da982965b4098d212784b65d18b0e157f31cc0`;
- source archive SHA-256 `cb408cef116008446b7c68f1f421e062826c8eb2550cead2a88df0f6bf614e55`;
- compile database SHA-256 `aa91af44338f8776d982b43ae9ef0a8ba65a58ec879c8a7266d8bf0c1bd11ce9`.

Executable SHA-256 authority:

- producer `0a8e67953e7221daf0fe607794c3b69f2e3fb8331b91ab08a02c10d52152943e`;
- oracle `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`;
- authority kernel `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`;
- validation `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`;
- completion `97a1b99948bc5b76521be2501d2573f75cf958f44aa9918a02dfcd8180619acd`;
- compiled API `84c1bc634770715f095c64d6c749b0ffa46e024af3656d5f0fc3c43982fbc7de`;
- benchmark executable `6490b7c39c2b58d2ab44ba2b258167b93dccf53dd1f7e8160cc626861c69f42e`.

## 8. Expected immutable runtime accounting

The package records the accepted entering producer discovery count **178** and exactly six added M1e tests, so the following immutable turn must require producer discovery exactly **184** unless artifact inspection proves an independently explainable packaging discrepancy.

The complete expected producer accounting is:

- **169** required-green producer tests;
- four direct required-green product cases run separately;
- nine historical/deferred known-red tests;
- BunnyRandom;
- Vase;
- total **184**.

No runtime result is inferred from these static counts.

## 9. Regression disposition

This Code + Build turn does **not** create a new stable regression event or recurrence:

- the initial issue was a compile-time API misuse caught before runtime and corrected within the same bounded Code + Build turn;
- v2 failures were temporary workflow syntax/infrastructure failures with no jobs;
- final approved source scope remains exactly two paths;
- no previously accepted runtime authority was executed or reclassified.

Historical totals therefore remain **34 events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active and unchanged.

Pattern state:

- `RP-01`: M1e checked source-vertex/interior-transition step domains **compile-complete; runtime pending**;
- `RP-05`: canonical semantic step identity and observed-vs-canonical route representation **compile-complete; runtime pending**;
- `RP-07`: typed cumulative route composition is **compile-complete; runtime pending** and is the primary M1e migration;
- `RP-02 / TA-05`: independent preservation remains pending the immutable turn.

## 10. Temporary workflow cleanup

After successful artifact capture and verification, all three temporary M1e workflows were removed **before** their trigger markers, then all three trigger files were removed, and the temporary apply script was removed. This follows the durable workflow-order rule and avoids cleanup-triggered reruns.

## 11. Next turn

Run **M1e Segment Route Transport Consumer — immutable Test + Benchmark only** under:

`.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

Consume exactly result artifact `9047295489` and log artifact `9047295703`; rebuild or edit nothing. Any required-green or focused semantic regression keeps work at M1e and returns to a corrective Code + Build turn.