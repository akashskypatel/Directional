# M1d Phase-Front Route Identity Consumer — Artifact-Only Test + Benchmark Report

**Status:** ACCEPTED  
**Turn type:** Test + Benchmark only  
**Implementation under test:** `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25`  
**Product behavior delta:** none observed or accepted  
**Review policy:** `never`  
**Date:** 2026-08-10 UTC

## 1. Immutable authority

| Evidence | Value |
|---|---|
| M1d entering base | `29f2e20a376c907581f119801768d393c19b9d1b` |
| M1d implementation | `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25` |
| Build/event commit | `98a21f3d843533dcc44cb296711268e0ebb26fb6` |
| Build run/job | `31342400614 / 93318225812` |
| Result artifact | `9046308272` |
| Result ZIP SHA-256 | `6a9dd880e2e7548b8afc88da48e7ed49935e6ce672ba1af208eee8f84678152c` |
| Log artifact | `9046308461` |
| Log ZIP SHA-256 | `4813676a45370644fce64854d430822b86a0e406e9446a7ea3159c8fb23d315c` |
| Recursive manifest | **59/59**, `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0` |
| Package regular files | **60**, including manifest |
| Producer executable SHA-256 | `0809eccc8625f588d077ab0598d47c9a75b051c58e8375af866a01ff9f2327b7` |
| Validation executable SHA-256 | `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6` |
| Authority executable SHA-256 | `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71` |
| Oracle executable SHA-256 | `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90` |

Preflight matched both outer GitHub artifact digests, rejected unsafe archive paths, verified `SHA256SUMS` and every **59/59** package member, and confirmed 60 regular files, seven ELF executables, two static libraries, and 27 fixtures. Build authority records Release/static/Ninja, `PRE_TEST`, and `runtimeExecution=false`.

The packaged M1d product/test diff remains exactly:

- `src/pipeline/RemeshPipeline.cpp`, blob `481f58169fe73844b12d9e70660d49fa3e13f845`;
- `tests/SurfaceCellTransitionQuotientTests.cpp`, blob `dc82faf06898d8516ddd55b2ae56c2b240c761fb`.

No configure, compile, relink, regeneration, source/test/fixture edit, artifact substitution, or packaged regular-content repair occurred during this turn. Runtime-only executable permission restoration occurred after content verification; the only package-tree addition was the non-regular `bin/test-data -> ../test-data` locator.

## 2. Discovery authority

Native GoogleTest discovery used only the packaged executables.

| Target | Discovery | Output SHA-256 |
|---|---:|---|
| producer | exactly **178 unique tests** | `0bf628d7cb629465e3e70878fb2252ea0010a75ee462a234ca3198b6a84fd8c6` |
| validation | exactly **77** | `ecea7f49605b6df5db31dc2ef407c5dbf455efd9456d301aabfdebae4b9eea35` |
| M1a authority kernel | exactly **14** | `ca359bf4a81d2816daa16cc5c5334f02bc9c7fc33b0a34858714e9bfcdf30991` |
| T1 independent oracle | exactly **29** | `d43cd15871859b7bd26577f0b251508ec736f93a9bd6c8c3f089a2b9cbec02df` |

Static manifests remained exact:

- M1d six: `e6d1932a71ee365249d78869c541eb05a55718b4a675f53d5f2afd0a58abee7a`;
- M1c six: `4cb94bd2afc6bc9430a138f794d4395a2847af2e8631e177b86e784c01cf1055`;
- M1b six: `a536c0772bc90b8fe3c91dd466b1d515339232bbcaf7c807956fdbfbfeea9320`;
- M1a 14: `d0fc5ed736b048d5b72136fe17ce579661b3c65ca9118f01cfcbefc35ba8d79d`;
- T1 29: `909a53d28c0c5eaa3d8759c95b55a0ff664074259153325e703ccd0e371004bb`.

Zero-selection success was rejected throughout.

## 3. M1d focused semantic acceptance

The suite `SurfaceCellPhaseFrontRouteAuthorityMigration` discovered exactly six members. Each ran individually in a fresh process, selected exactly one test, and returned rc=0. Result: **6/6**.

1. `ValidHardRailRouteUsesTypedIdentity` — pass.
2. `ValidPeriodicCutRouteUsesTypedIdentity` — pass.
3. `InvalidInteriorTransitionIdFailsClosed` — pass.
4. `OutOfDomainPackedSourceVertexFailsClosed` — pass.
5. `RouteTopologyTransitionMismatchFailsClosed` — pass.
6. `DuplicateSemanticRouteTopologyFailsClosed` — pass.

This accepts the intended M1d consumer relations: checked packed source-vertex domains, canonical source-edge semantic identity and uniqueness, checked compact interior-transition domains, typed transition equality, and fail-closed malformed route authority while preserving public packed route representation.

## 4. Existing route and M1c counterexamples

All three pre-M1d route witnesses ran individually, selected exactly one test, and remained green:

- `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`;
- `SurfaceCellTransitionQuotient.ArtificialInteriorBoundaryIsRejected`;
- `SurfaceCellTransitionQuotient.ComponentBoundaryAndEulerFactsAreComputedFromIncidence`.

M1c preservation also remained exact:

- M1c focused migration contracts: **6/6** individually;
- `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed` — pass;
- `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed` — pass;
- `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason` — pass.

M1d therefore did not disturb the accepted modulo-four field-transition transport boundary.

## 5. Complete producer accounting

Producer discovery contains exactly **178** tests and is fully accounted for:

| Class | Count | Result |
|---|---:|---|
| required-green producer segment | **163** | **163/163** pass, rc=0, 21.244 s |
| direct required-green product cases | **4** | **4/4** pass |
| historical/deferred known-red tests | **9** | each selected exactly one and remains red |
| BunnyRandom | **1** | known-red signature preserved |
| Vase | **1** | bounded 60 s nonreturn, safety-only |
| **Total** | **178** | exact discovery accounting |

The 163-member required-green segment selected exactly 163 tests from 12 suites, returned rc=0, and used 23,180 KiB peak RSS.

The nine explicitly retained historical/deferred reds remain:

1. `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` — existing assertion red;
2. `SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize` — `PeriodicHolonomyMismatch`;
3. `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected` — `PeriodicHolonomyMismatch`;
4. `SurfaceCellTransitionQuotient.MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner` — `InvalidHardRailPairing`;
5. `SurfaceCellTransitionQuotient.SwappedPeriodicRelationOwnersAreRejected` — `InvalidHardRailPairing`;
6. `SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected` — `InvalidHardRailPairing`;
7. `SurfaceCellTransitionQuotient.QuotientLineageRetainsScalarPointAndCompleteSortedAuthority` — existing assertion red;
8. `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` — existing timing red;
9. `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` — `NotProductionReady:tracing ... InvalidHardRailPairing`.

Their persistence is not a new M1d regression or recurrence.

## 6. M1b, M1a, and T1 preservation

- M1b focused `SurfaceOptimizationRailAuthorityMigration`: **6/6** individually.
- Complete validation executable: discovery **77**, runtime **77/77**, rc=0.
- M1a authority kernel: exact 14, **14/14**, rc=0.
- T1 independent product oracle: exact 29, **29/29**, rc=0.

Focused M1d success therefore supplements rather than substitutes for the independent accepted authority.

## 7. Direct required-green product preservation

Each direct product case selected exactly one existing producer test and remained independent-oracle clean:

| Case | Result | Elapsed | Peak RSS |
|---|---|---:|---:|
| Plane | pass | **1.325 s** | 11,052 KiB |
| MultiFaceSeam | pass | **2.079 s** | 10,844 KiB |
| CloseSheets | pass | **16.648 s** | 13,232 KiB |
| Cylinder | pass | **9.267 s** | 14,664 KiB |

No product disposition change is accepted by M1d.

## 8. Bunny/Vase immutable Actions comparison

Long-running comparison used temporary artifact-only GitHub Actions run `31343763822` after local required-green authority was established.

Each matrix job independently downloaded exact result artifact `9046308272` from build run `31342400614`, verified the GitHub artifact digest, exact implementation/build authority, all **59/59** package checksums, 60 regular files, and producer hash before runtime. Neither job configured, built, relinked, regenerated, substituted, or edited packaged regular content. Both postflights reverified the original artifact hash, manifest hash, producer hash, and regular-file count.

### BunnyRandom

Job `93321764271` selected exactly one existing BunnyRandom test and returned **rc=1** after wrapper **71.705 s** / GoogleTest **71.684 s**. Peak RSS was **341,996 KiB**.

The accepted known-red ordering is preserved:

1. the independent oracle rejects first with `EmptyOutput`, `NonQuadOutput`, connected-component mismatch, Euler-characteristic mismatch, output-origin mismatch, and `TerminalFailureObserved:NotProductionReady:completion`;
2. afterward the unchanged product-success assertion reports `terminal=NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.

Evidence artifact `9046629209`, SHA-256 `6502efcdef8ed94051e571b81f8f9c7ae6c2e1d10d8e0b9804991a42a5cf65a3`, retained through 2026-08-24 UTC.

### Vase

Job `93321764263` selected exactly one existing Vase test, reached `[ RUN ]`, and was bounded at **60.023 s** with **rc=124**. Peak RSS was **67,144 KiB**. This remains safety evidence only; it is not correctness evidence and is not proof of nontermination.

Evidence artifact `9046626009`, SHA-256 `2a5ae0ae047f82ac909cf049aac03785863ee93d1506b10decb0c9507f5c4855`, retained through 2026-08-24 UTC.

Workflow success means orchestration success only. Product dispositions above come from retained runtime logs. The temporary workflow and trigger were removed before closeout.

## 9. Postflight immutability

Postflight reverified:

- result ZIP SHA-256 `6a9dd880e2e7548b8afc88da48e7ed49935e6ce672ba1af208eee8f84678152c`;
- log ZIP SHA-256 `4813676a45370644fce64854d430822b86a0e406e9446a7ea3159c8fb23d315c`;
- `SHA256SUMS` digest `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0`;
- every **59/59** package checksum;
- producer, validation, authority, and oracle executable content hashes;
- exactly 60 regular package files.

Remote Bunny/Vase postflights independently confirmed the same result artifact, manifest, producer, and regular-file authority.

## 10. Architecture and regression disposition

M1d is **immutable accepted** as the authoritative phase-front interior-route identity consumer migration.

- `RP-01`: checked source-vertex and interior-transition domains at the M1d route consumer **accepted**.
- `RP-05`: canonical `SourceEdgeTopologyKey` semantic route identity versus packed-key/index compatibility representation **accepted**.
- `RP-07`: accepted M1c modulo-four/inverse transport **preserved**.
- `RP-02 / TA-05`: independent authority **preserved** by exact 178 accounting, M1c/M1b/M1a/T1, direct product-oracle evidence, and explicit known-red classification.
- No new stable regression event or recurrence is created. Historical totals remain **34 events / 14 categories / 20 recurrences**.
- `PR8-R034 / G4-R007` remains active and separate. M1d does not repair or reinterpret direct-torus `LocalSheetMismatch` or historical exact-torus `InvalidHardRailPairing`.

## 11. Cleanup disposition

Before this Test + Benchmark execution, `.agents/Directional` stale per-turn plans/reports/evidence were removed while durable design, remediation, audit, regression, workflow-policy, and handoff authority was retained. The handoff now contains a mandatory durable cleanup policy: every future Test + Benchmark turn begins by removing stale prior evidence after its durable facts are captured, and ends by replacing consumed evidence with the current authoritative report plus exactly one next Code + Build plan.

For this turn, the consumed M1d Test + Benchmark plan and superseded M1d Code + Build report are removed after this report and the following plan are committed.

## 12. Following turn

Review policy remains `never`. The next bounded turn is **M1e Segment Route Transport Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Code_Build_Plan.md`.

M1e targets the real per-step transport-owning seam inside `surface_cell_tracing_detail::segment_on_source`, where a source-face/vertex-fan route currently accumulates raw signed matching across `VertexPathStep`s. It may adopt `TransitionStep`/`CanonicalRoute` there because that consumer actually owns ordered step transport. It must not broaden into periodic-holonomy production, public route schema retirement, topology planning, conformity, quotient materialization, validators, fallback/recovery, or G4 repair.