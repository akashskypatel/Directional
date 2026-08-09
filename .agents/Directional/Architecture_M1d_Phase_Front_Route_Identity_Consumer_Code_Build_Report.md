# M1d Phase-Front Route Identity Consumer — Code + Build Report

**Status:** compile/package complete; immutable runtime pending  
**Turn type:** Code + Build only  
**Architecture milestone:** M1 — authority kernel and staged production adoption  
**Product behavior delta intended:** none  
**Review policy:** `never`  
**Date:** 2026-08-09 UTC

## 1. Implemented boundary

M1d migrates exactly one production consumer:

`pipeline::build_authoritative_phase_front_mesh -> exact_interior_route_valid`

The consumer validates the existing `SurfaceFrontEdge::sourceRouteEdges` / `sourceRouteTopology` route carried by authoritative **HardRail** and **PeriodicCut** front relations.

Final product/test delta is exactly:

- `src/pipeline/RemeshPipeline.cpp`;
- `tests/SurfaceCellTransitionQuotientTests.cpp`.

No public header, CMake, fixture, validator, benchmark, route producer, route transport, periodic certificate, topology-plan, quotient, fallback, or recovery behavior was changed.

## 2. Implementation authority

| Evidence | Value |
|---|---|
| M1d entering documentation/base | `29f2e20a376c907581f119801768d393c19b9d1b` |
| M1d implementation | `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25` |
| Build/event commit | `98a21f3d843533dcc44cb296711268e0ebb26fb6` |
| Workflow run/job | `31342400614 / 93318225812` |
| Result artifact | `9046308272` |
| Result ZIP SHA-256 | `6a9dd880e2e7548b8afc88da48e7ed49935e6ce672ba1af208eee8f84678152c` |
| Log artifact | `9046308461` |
| Log ZIP SHA-256 | `4813676a45370644fce64854d430822b86a0e406e9446a7ea3159c8fb23d315c` |
| Recursive manifest | **59/59**, `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0` |
| Retention | through **2026-08-23 UTC** |

The result package contains **60 regular files including `SHA256SUMS`**, seven ELF executables, two static libraries, and 27 fixture files. Read-only local verification matched both GitHub artifact digests, rejected unsafe archive paths, and verified all **59/59** manifest entries.

## 3. Semantic implementation

The existing empty-route, equal-cardinality, exact source-incidence, interior-edge, and caller failure semantics remain first-class behavior authority.

Within `exact_interior_route_valid` only:

1. each packed `uint64_t` topology value is decoded into its unsigned high/low source-vertex fields without narrowing through signed `int`;
2. both endpoint values cross checked `LegacyAuthorityAdapters::source_vertex(..., sourceVertices.rows())`;
3. endpoints are canonicalized by `SourceEdgeTopologyKey::make` and the typed key is used for route semantic uniqueness;
4. typed endpoints cross back to the existing packed source-edge representation only at the compatibility lookup boundary, and the canonical reserialization must equal the supplied raw value;
5. the existing `exactSourceIncidence` / `sourceEdgeIndices` lookups and two-face interior requirement remain unchanged;
6. both the supplied route compact value and authoritative map value cross checked `LegacyAuthorityAdapters::interior_transition(..., sourceEdgeIndices.size())`;
7. semantic transition identity is compared as `InteriorTransitionId`, not raw integer equality;
8. any malformed endpoint/key/transition fails closed through the existing `InvalidHardRailAuthority` or `InvalidPeriodicCutAuthority` caller path.

M1d does **not** create `TransitionStep` or `CanonicalRoute` objects because this consumer does not own per-step transport. M1c quarter-turn transport remains untouched.

Implementation source blobs:

- `src/pipeline/RemeshPipeline.cpp`: `481f58169fe73844b12d9e70660d49fa3e13f845`;
- `tests/SurfaceCellTransitionQuotientTests.cpp`: `dc82faf06898d8516ddd55b2ae56c2b240c761fb`;
- unchanged `include/directional/pipeline/RemeshPipeline.h`: `7af540b2fc97e1ebcb504c0623b913b72466ddf4`;
- unchanged authority IDs: `3892126eb7646ac6e1cd47bf0b139286d329b73d`;
- unchanged adapters: `e23fb460f3b435c8ea9d5958b3d9c9cd813899b6`.

Accepted M1c source/test blobs remain `053759bec2e07a2827f54411d85e73ef4b4ef71a / 2a1aa2ae17a9be1f2660eef6da396f9b3793566a`.

## 4. Focused contracts compiled

Exactly six new behavior-focused contracts are statically packaged in the existing producer target:

1. `SurfaceCellPhaseFrontRouteAuthorityMigration.ValidHardRailRouteUsesTypedIdentity`;
2. `SurfaceCellPhaseFrontRouteAuthorityMigration.ValidPeriodicCutRouteUsesTypedIdentity`;
3. `SurfaceCellPhaseFrontRouteAuthorityMigration.InvalidInteriorTransitionIdFailsClosed`;
4. `SurfaceCellPhaseFrontRouteAuthorityMigration.OutOfDomainPackedSourceVertexFailsClosed`;
5. `SurfaceCellPhaseFrontRouteAuthorityMigration.RouteTopologyTransitionMismatchFailsClosed`;
6. `SurfaceCellPhaseFrontRouteAuthorityMigration.DuplicateSemanticRouteTopologyFailsClosed`.

Static M1d focused manifest SHA-256:
`e6d1932a71ee365249d78869c541eb05a55718b4a675f53d5f2afd0a58abee7a`.

The tests exercise real `build_authoritative_phase_front_mesh` behavior. Valid HardRail and PeriodicCut cases require actual authoritative routes. Negative cases preserve route cardinality where relevant and independently tamper domain validity, source-vertex extent, route/transition agreement, or semantic uniqueness.

Existing route counterexamples retained for the following immutable turn:

- `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`;
- `SurfaceCellTransitionQuotient.ArtificialInteriorBoundaryIsRejected`;
- `SurfaceCellTransitionQuotient.ComponentBoundaryAndEulerFactsAreComputedFromIncidence`.

## 5. Compile evidence

Configuration:

- Ubuntu 24.04;
- GCC 13.3.0;
- CMake 3.31.6;
- Ninja 1.13.2;
- Release/static;
- GMP ON;
- PARDISO/CUDSS/SuiteSparse OFF;
- tests and benchmarks configured ON;
- CLI/GUI/Python/tutorials OFF;
- GoogleTest discovery mode `PRE_TEST`;
- parallelism 2.

Approved targets compiled successfully: **120/120**.

- wall time: **6:53.49**;
- peak RSS: **1,848,616 KiB**;
- build exit status: **0**.

Compiled targets include core, pipeline, compiled API tests, producer tests, oracle tests, authority-kernel tests, completion tests, validation tests, and benchmarks.

No generated Directional binary was executed. Package command-boundary authority records:

```text
runtimeExecution=false
configured=true
compiled=true
generatedDirectionalBinaryExecuted=false
gtestDiscoveryExecuted=false
testExecuted=false
benchmarkExecuted=false
ctestExecuted=false
cliGuiHelpVersionExecuted=false
fuzzerExecuted=false
customInputExecuted=false
```

Compile success therefore establishes only code/build/package validity, not M1d semantic acceptance.

## 6. Immutable package authority

Package source/evidence hashes:

- patch: `203130449f9e7e8f6c4d1889779e37b750b874c2b80c63da2e248f7aafbbcae5`;
- source archive: `61fc743d266a12f194a5dbc25e8eeea3830d2f02653fb14dab991b91a2f86cd8`;
- compile DB: `aa91af44338f8776d982b43ae9ef0a8ba65a58ec879c8a7266d8bf0c1bd11ce9`;
- preserved M1c manifest: `4cb94bd2afc6bc9430a138f794d4395a2847af2e8631e177b86e784c01cf1055`;
- preserved M1b manifest: `a536c0772bc90b8fe3c91dd466b1d515339232bbcaf7c807956fdbfbfeea9320`;
- preserved M1a manifest: `d0fc5ed736b048d5b72136fe17ce579661b3c65ca9118f01cfcbefc35ba8d79d`;
- preserved T1 manifest: `909a53d28c0c5eaa3d8759c95b55a0ff664074259153325e703ccd0e371004bb`.

Executable/library SHA-256 values:

- producer tests: `0809eccc8625f588d077ab0598d47c9a75b051c58e8375af866a01ff9f2327b7`;
- completion tests: `bd6626c73c25c2d721db7a6e5f6d5fbb1dd15751da5cdc249b8dfd4fa057cfaa`;
- oracle tests: `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`;
- compiled API tests: `04c2228204cdfcb9a8def64f4ec7b49a63e7091277752fa2934eec73edfafac6`;
- benchmarks: `490bf8c6d659b1b91fae032cba0968be09f7d84289f08466e1aa8ec50cdda0d3`;
- validation tests: `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`;
- authority-kernel tests: `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`;
- `libdirectional_core.a`: `59cd0248adc5d7b91436126063036cdfd439b81260bca66f25a874efc7b5112e`;
- `libdirectional_pipeline.a`: `322ba50a5e447ad8a0bd15e4280674feac3d3f7f91b007ac1f36efc5b07306c0`.

The package records the accepted M1c producer baseline discovery as 172 and the expected M1d discovery as **178**. The expected required-green producer segment becomes **163**: the accepted 157 plus the six new M1d contracts. Runtime must prove these counts; they are not inferred from static packaging.

## 7. Regression-pattern disposition

- `RP-01`: checked `SourceVertexId` and `InteriorTransitionId` adoption at this route consumer is **compile-complete; immutable runtime pending**.
- `RP-05`: canonical route `SourceEdgeTopologyKey` versus packed raw topology/index representation is **compile-complete; runtime pending**.
- `RP-07`: M1c cyclic transport is untouched and remains an immutable preservation boundary.
- `RP-02 / TA-05`: M1d focused tests cannot replace producer/M1c/M1b/M1a/T1/direct authority; preservation is pending the immutable turn.
- No stable regression event or recurrence is created from compile-only evidence. Historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains active and unchanged.

## 8. Following turn

The next turn is **M1d Phase-Front Route Identity Consumer — immutable Test + Benchmark only** under:

`.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

Consume exactly artifacts `9046308272 / 9046308461`. Rebuild, relink, regenerate, edit, substitute, or repair nothing. M1d is accepted only after exact focused/counterexample evidence plus independent preservation of producer, M1c, M1b, M1a, T1, and required direct product authority.
