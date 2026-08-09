# Future Chat Session Handoff

## Mandatory next turn

Run **M1d Phase-Front Route Identity Consumer — immutable Test + Benchmark only** under:

`.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Artifact_Only_Test_Benchmark_Plan.md`

Repository:

- `akashskypatel/Directional`;
- branch `agent/surface_cell_quad/p5-recover-bridge-healing`;
- draft PR #8 stays open, draft, and unmerged;
- active product gate: **G4 topology-distinct completion and singularities**;
- architecture migration: **M1 authority kernel and staged production adoption**;
- M1a/M1b/M1c: **immutable accepted**;
- M1d route-identity consumer: **Code + Build compile/package complete; immutable runtime pending**;
- review policy: `never`.

The next turn is non-mutating with respect to source, tests, fixtures, build logic, and packaged regular content. Do not configure, rebuild, relink, regenerate, substitute, edit, or repair anything in the immutable artifact.

## Exact M1d build authority

Selected seam:

`pipeline::build_authoritative_phase_front_mesh -> exact_interior_route_valid`

| Evidence | Value |
|---|---|
| Entering base | `29f2e20a376c907581f119801768d393c19b9d1b` |
| Implementation | `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25` |
| Build/event | `98a21f3d843533dcc44cb296711268e0ebb26fb6` |
| Build run/job | `31342400614 / 93318225812` |
| Result artifact | `9046308272` |
| Result SHA-256 | `6a9dd880e2e7548b8afc88da48e7ed49935e6ce672ba1af208eee8f84678152c` |
| Log artifact | `9046308461` |
| Log SHA-256 | `4813676a45370644fce64854d430822b86a0e406e9446a7ea3159c8fb23d315c` |
| Recursive manifest | **59/59**, `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0` |
| Package | 60 regular files including manifest; seven ELF; two static libs; 27 fixtures |
| Compile | Release/static/Ninja **120/120** |
| Build wall / peak RSS | **6:53.49 / 1,848,616 KiB** |
| Runtime in Code + Build | **false** |
| Retention | through **2026-08-23 UTC** |

Read-only verification already matched both outer GitHub artifact digests, rejected unsafe archive paths, and verified all **59/59** package checksums.

Authoritative report:
`.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Code_Build_Report.md`.

## M1d semantic boundary to prove

Only `exact_interior_route_valid` was migrated:

1. existing nonempty/equal-size/interior-incidence checks remain behavior authority;
2. packed route endpoints cross checked `LegacyAuthorityAdapters::source_vertex(..., sourceVertices.rows())`;
3. semantic route edge identity/uniqueness uses canonical `SourceEdgeTopologyKey`;
4. typed endpoints serialize back only at the existing packed-key compatibility lookup boundary and must reproduce the supplied key exactly;
5. supplied and authoritative compact route values cross checked `LegacyAuthorityAdapters::interior_transition(..., sourceEdgeIndices.size())`;
6. semantic compact identity is `InteriorTransitionId` equality;
7. malformed identity remains fail-closed through the existing `InvalidHardRailAuthority` / `InvalidPeriodicCutAuthority` caller failures;
8. public `sourceRouteEdges/sourceRouteTopology`, route producers/order, per-step transport, relation policy, diagnostics, and known-red dispositions remain unchanged.

Do not introduce `TransitionStep`/`CanonicalRoute` here; this consumer owns no per-step transport.

Final product/test diff is exactly:

- `src/pipeline/RemeshPipeline.cpp`;
- `tests/SurfaceCellTransitionQuotientTests.cpp`.

Implementation blobs:

- pipeline source `481f58169fe73844b12d9e70660d49fa3e13f845`;
- transition-quotient tests `dc82faf06898d8516ddd55b2ae56c2b240c761fb`.

## Exact M1d focused authority

The packaged producer target statically contains exactly six new contracts:

1. `SurfaceCellPhaseFrontRouteAuthorityMigration.ValidHardRailRouteUsesTypedIdentity`;
2. `SurfaceCellPhaseFrontRouteAuthorityMigration.ValidPeriodicCutRouteUsesTypedIdentity`;
3. `SurfaceCellPhaseFrontRouteAuthorityMigration.InvalidInteriorTransitionIdFailsClosed`;
4. `SurfaceCellPhaseFrontRouteAuthorityMigration.OutOfDomainPackedSourceVertexFailsClosed`;
5. `SurfaceCellPhaseFrontRouteAuthorityMigration.RouteTopologyTransitionMismatchFailsClosed`;
6. `SurfaceCellPhaseFrontRouteAuthorityMigration.DuplicateSemanticRouteTopologyFailsClosed`.

Static manifest SHA-256:
`e6d1932a71ee365249d78869c541eb05a55718b4a675f53d5f2afd0a58abee7a`.

The immutable turn must require exact six-member discovery and **6/6** fresh-process semantic success. Zero selection is invalid.

## Existing route counterexamples

Run individually and require green:

- `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`;
- `SurfaceCellTransitionQuotient.ArtificialInteriorBoundaryIsRejected`;
- `SurfaceCellTransitionQuotient.ComponentBoundaryAndEulerFactsAreComputedFromIncidence`.

## Required preservation matrix

The immutable turn must additionally prove:

1. native producer discovery exactly **178**;
2. required-green producer segment exactly **163/163**;
3. all nine historical/deferred producer reds remain explicit and individually classified;
4. M1c exact six **6/6** plus its three transition counterexamples green;
5. M1b focused **6/6**, validation discovery exactly 77 and **77/77**;
6. M1a discovery exactly 14 and **14/14**;
7. T1 discovery exactly 29 and **29/29**;
8. Plane/MultiFaceSeam/CloseSheets/Cylinder remain green and independent-oracle clean;
9. postflight preserves both original ZIP hashes and all **59/59** packaged checksums.

Exact producer accounting target:

- 163 required-green aggregate members;
- four separately run direct-green cases;
- nine historical/deferred known-red producer tests;
- BunnyRandom;
- Vase;
- total **178**.

M1d focused tests cannot substitute for independent preservation authority.

## Bunny/Vase standing procedure

The user has authorized artifact-only GitHub Actions runtime for Bunny/Vase when local execution limits make them impractical. For M1d, if used, the temporary workflow must download exact artifact `9046308272` from run `31342400614`, verify outer digest, all 59 checksums, implementation metadata, and producer executable hash before runtime, perform no rebuild/content mutation, use explicit process guards, retain raw evidence, and be removed before closeout.

Accepted M1c comparison remains:

- Bunny: independent oracle rejects first, then unchanged `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`, rc=1 at about 63 s;
- Vase: one real test reaches `[ RUN ]`, bounded rc=124 at 60 s; safety-only.

Do not promote either to green merely to close M1d.

## Regression/architecture disposition

- `RP-01`: M1d checked `SourceVertexId` / `InteriorTransitionId` adoption **compile-complete; immutable runtime pending**.
- `RP-05`: M1d canonical route topology identity **compile-complete; runtime pending**.
- `RP-07`: accepted M1c quarter-turn transport is untouched and must remain green.
- `RP-02 / TA-05`: independent preservation is pending the immutable turn.
- Historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains **active** and separate.

Production G4 authority is unchanged: direct torus remains 0/3 after 192 quads with 241 `LocalSheetMismatch` issues; historical exact torus remains `InvalidHardRailPairing`.

## Core references

- `.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Artifact_Only_Test_Benchmark_Plan.md`;
- `.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Code_Build_Report.md`;
- `.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Artifact_Only_Test_Benchmark_Report.md`;
- `.agents/Directional/DESIGN.md`;
- `.agents/Directional/REORIENTATION_PLAN.md`;
- `.agents/Directional/Regression_Root_Cause_Tracker.md`;
- `tests/TESTING_STRATEGY.md`;
- `TODO`;
- `MILESTONE_G_TODO.md`.

At the start of the next turn, fetch fresh PR/head state and verify the branch still contains implementation `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25`. Do not assume this documentation head if external commits move the branch.

If any required-green immutable gate regresses, remain at M1d and return to corrective Code + Build. Do not advance to another consumer.

After all branch-file and PR-body writes for a completed turn, the final repository write is exactly one new top-level PR #8 conversation comment.

Last updated: 2026-08-09 UTC