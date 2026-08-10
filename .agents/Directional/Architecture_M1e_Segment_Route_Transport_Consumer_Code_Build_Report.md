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

The final product/test delta is exactly `src/geometry/SurfaceCellTracing.cpp` and `tests/SurfaceCellsPhase10Tests.cpp`. No public header, pipeline, validator, CMake, fixture, benchmark, periodic-holonomy, field-chart, topology/conformity/quotient, fallback/recovery, optimization, or G4 behavior was intentionally changed.

## 2. Starting and final source authority

| Authority | Value |
|---|---|
| Entering M1e base | `5df33fc11deaac697cb886d8defcaba622ec436f` |
| Accepted M1d ancestor | `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25` |
| Reviewed production-hunk provenance | `bb9cb63a36b64fe2f7c462ad864492c8352b65e8` |
| Final M1e implementation | `a0330d0107f7d7340e9f8644d26dd6c8b753ff10` |
| Workflow staging | `5b9cd7109a192dc76ca44f650c3111d3c527fd0c` |
| Successful build-event commit | `34036600128262e909c377006a056a2b9976f986` |
| Successful workflow run/job | `31351113129 / 93341993183` |
| Post-build workflow/trigger cleanup | `bd68afbd63e2ad711110382900c96ec7f26d8c6f / 693589d438325ef837838d1b803842b292c8f662` |

Final packaged product/test blobs:

- `src/geometry/SurfaceCellTracing.cpp` — `34372a48412213d3b4db6d0bc3e653e7d3225ef0`;
- `tests/SurfaceCellsPhase10Tests.cpp` — `f55d016db2c89710b79c711a0d5e780dcfb2bdfc`.

The production blob is byte-identical to the final independently reviewed production hunk at `bb9cb63`; the focused tests were rewritten from scratch before `a0330d0` and are not the previously rejected positional/proxy tests.

Preserved accepted authority blobs include M1d pipeline `481f58169fe73844b12d9e70660d49fa3e13f845`, M1d transition-quotient tests `dc82faf06898d8516ddd55b2ae56c2b240c761fb`, tracing header `b87e37676a980162e7ef3ac1fa9d954ce2199ad2`, `CanonicalRoute.h` `542b5475ac407ae4541e2ac36f298a727403aff4`, `AuthorityIds.h` `3892126eb7646ac6e1cd47bf0b139286d329b73d`, `LegacyAuthorityAdapters.h` `e23fb460f3b435c8ea9d5958b3d9c9cd813899b6`, `GridAutomorphism.h` `b3e8128707eea56ca52377385758f390e3c5e284`, M1b tests `466e2bbd000413ee60c77cc06fe707641dbe4740`, M1a tests `9dcdab568e204026eb0c2aebc1b43cd8de8db62c`, T1 oracle tests `28932c8c2dbe844b62f8fe848e6ebb9ef67550de`, and direct acceptance tests `aff7894aae3397bef47be777a8bf7e2fbb0c27ef`.

## 3. Final M1e implementation boundary

At each ordered `VertexPathStep`, the implementation preserves existing route discovery, vertex-fan choice, barriers, transition resolution, provenance, and effort; validates packed endpoints with `source_vertex`; canonicalizes semantic edge identity with `SourceEdgeTopologyKey`; validates compact provenance with `interior_transition`; converts directed matching to `QuarterTurn` plus a zero-shift `GridAutomorphism`; creates a forward observed `TransitionStep`; constructs `CanonicalRoute` only after all steps validate; consumes `oriented_steps()` to preserve observed behavior direction; composes typed automorphisms in observed order; and writes only the final semantic quarter-turn back to legacy `current.matching`.

The explicit `edgeTransitions`-absent legacy transition path remains available but crosses the same typed route-composition boundary before the raw matching write. The separate periodic-holonomy loop and chart ownership remain untouched.

## 4. Focused contract package

Exactly six production-path contracts are statically packaged under `SurfaceCellSegmentRouteTransportAuthorityMigration`:

1. `MultiStepVertexFanComposesTypedRouteTransport`;
2. `ReverseObservedRouteUsesExactTransportInverse`;
3. `EquivalentSignedQuarterTurnsComposeSemantically`;
4. `RouteTopologyAndCompactTransitionProvenanceRemainUnchanged`;
5. `MalformedAuthoritativeStepMetadataFailsClosedWithoutFallback`;
6. `LegacyMatchingFallbackUsesSameTypedRouteComposition`.

Static M1e manifest SHA-256: `b6a1c9035b2cd15a13844f812e7261ee0e199e72d0150d9a093a59d1ce713556`.

The rewritten fixture deterministically exercises route `2 -> 3 -> 10` through source vertex `7`, source topology edges `(1,7)` then `(6,7)`, and the exact reverse. Hard-authored branch labels yield nonzero directed turns `3` and `2`; the independent endpoint-label oracle requires forward matching `1` and reverse matching `3`. Expected compact provenance is independently enumerated as `2` and `9`. Equivalent-representation comparisons use sorted semantic route keys, never positional output pairing. The legacy matching vector is independently constructed from the fixture's 29 interior edges.

These tests do not call production route composition to manufacture their final expected matching or provenance. They were **compiled only**; none was discovered or executed in this turn.

Preserved static manifests remain exact: M1d `e6d1932a71ee365249d78869c541eb05a55718b4a675f53d5f2afd0a58abee7a`; M1c `4cb94bd2afc6bc9430a138f794d4395a2847af2e8631e177b86e784c01cf1055`; M1b `a536c0772bc90b8fe3c91dd466b1d515339232bbcaf7c807956fdbfbfeea9320`; M1a `d0fc5ed736b048d5b72136fe17ce579661b3c65ca9118f01cfcbefc35ba8d79d`; T1 `909a53d28c0c5eaa3d8759c95b55a0ff664074259153325e703ccd0e371004bb`.

## 5. Review-authorized reachability correction

The reviewed malformed-step premise was corrected before implementation. Once `source_edge_provenance` succeeds, step topology and compact transition identity are derived from valid mesh/maps and typed construction is total for those validated facts. Corrupting a transition endpoint instead fails earlier in transition lookup, so neither route reaches a distinct typed-constructor failure boundary.

The fifth contract therefore exercises the real immediately preceding authority boundary: it corrupts the nonnegative `CrossFieldEdgeTransition::sourceEdge` sentinel on predetermined route edge `(6,7)`, proves the baseline exact route exists, then requires production rejection at the actual `segment_on_source` vertex-fan seam as `MissingTransitionProvenance` with concrete cell/side, source vertex `7`, faces `3 <-> 10`, and no cells/seeds/traces/proposals. The test deliberately does **not** promote `CrossFieldEdgeTransition::sourceEdge` to semantic `InteriorTransitionId`; the typed ID remains derived only from `source_edge_provenance` compact authority.

This is a narrow plan correction, not a production-scope expansion.

## 6. Static and authoritative build evidence

Local static checks passed:

- `git diff --check`;
- C++20 syntax-only compilation of `src/geometry/SurfaceCellTracing.cpp`;
- C++20 syntax-only compilation of `tests/SurfaceCellsPhase10Tests.cpp` with the existing test source macro and includes.

Local CMake configuration was unavailable because the local environment has no `cmake`; no generated project binary was produced or executed locally.

Authoritative run/job `31351113129 / 93341993183` used Ubuntu 24.04 / GCC 13.3.0, Release/static/Ninja, `PRE_TEST`, approved compile targets only, and completed **120/120** with wall time **8:30.51**, peak RSS **1,848,824 KiB**, and exit 0.

The package command boundary explicitly records `runtimeExecution=false` and false for generated binary execution, GoogleTest discovery/tests, benchmarks, `ctest`, CLI/GUI/help/version, fuzzers, and custom input. Compile success establishes code/build validity only; M1e semantic acceptance remains pending immutable Test + Benchmark.

## 7. Immutable package authority

| Evidence | Value |
|---|---|
| Result artifact | `9049125645` — `m1e-segment-route-transport-code-build-v4` |
| Result ZIP SHA-256 | `d16222c62f6f7491eaa830fe22ac4f768b6f426646639f155ccfd8feb9d378f7` |
| Log artifact | `9049125905` — `m1e-segment-route-transport-code-build-v4-logs` |
| Log ZIP SHA-256 | `fd1d816fd4265f803f6be278941eb7647d056eb6336d05fe98e865621fd5e7be` |
| Retention | through `2026-08-24 03:04 UTC` |
| Recursive manifest | **61/61**, SHA-256 `36a6377350aa4b58205ccd881a7ee34156800d28e3c5edecf634769289d9e7e5` |
| Regular package files | **62** including manifest |
| Fixtures / executables / static libs | **27 / 7 / 2** |

Read-only verification matched both GitHub outer digests, rejected unsafe paths, tested both ZIPs, verified every **61/61** package checksum, and confirmed exact build/source authority. Source patch SHA-256 is `494bc12227219becde7e5b590df34f80eb5b25a8228dc0106ea41c8b5c3b997b`; source archive `9d048835f4884eec07101dce1c97092318fb15cb94170340e95ff0baf63e7a62`; compile database `aa91af44338f8776d982b43ae9ef0a8ba65a58ec879c8a7266d8bf0c1bd11ce9`.

Executable SHA-256 authority:

- producer `5e2e85ede99f50b82aba70ce0a829a59b5c74bb42585845f681d80e578402259`;
- oracle `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`;
- authority kernel `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`;
- validation `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`;
- completion `97a1b99948bc5b76521be2501d2573f75cf958f44aa9918a02dfcd8180619acd`;
- compiled API `84c1bc634770715f095c64d6c749b0ffa46e024af3656d5f0fc3c43982fbc7de`;
- benchmark `6490b7c39c2b58d2ab44ba2b258167b93dccf53dd1f7e8160cc626861c69f42e`.

## 8. Expected immutable runtime accounting

The package records entering producer discovery **178** and exactly six added M1e tests, so the immutable turn requires discovery exactly **184** unless artifact inspection proves an independent packaging discrepancy. Expected accounting is **169 required-green + 4 direct + 9 historical/deferred red + BunnyRandom + Vase = 184**.

No runtime result is inferred from these static counts.

## 9. Regression disposition

This Code + Build turn creates no new stable regression event or recurrence. Final product scope is exactly two paths; source gates, compilation, package integrity, and cleanup passed; no accepted runtime authority was executed or reclassified.

Historical totals remain **34 events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active and unchanged.

- `RP-01`: checked M1e step domains **compile-complete; runtime pending**.
- `RP-05`: semantic step identity / observed-canonical route boundary **compile-complete; runtime pending**.
- `RP-07`: typed cumulative route composition **compile-complete; runtime pending**.
- `RP-02 / TA-05`: independent preservation pending immutable validation.

## 10. Temporary workflow cleanup

After artifact capture and verification, temporary workflow `.github/workflows/m1e-segment-route-transport-code-build-v4.yml` was removed first at `bd68afbd...`; its trigger marker was removed second at `693589d...`. No cleanup run was scheduled. Final workflow state contains only durable `agent-source-snapshot.yml`; `.agents/connector-triggers` is empty.

## 11. Next turn

Run **M1e Segment Route Transport Consumer — immutable Test + Benchmark only** under `.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`, consuming exactly artifacts `9049125645 / 9049125905` and rebuilding/editing nothing. Any required-green or focused semantic regression remains at M1e and returns to corrective Code + Build.
