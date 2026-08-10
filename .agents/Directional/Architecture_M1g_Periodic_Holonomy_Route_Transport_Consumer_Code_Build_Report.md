# M1g Periodic Holonomy Route Transport Consumer — Code + Build Report

**Status:** compile/package complete; immutable runtime pending  
**Turn type:** Code + Build only  
**Review policy:** `never`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Result

M1g Code + Build is complete at the selected real transport owner:

`periodic canonical face cycle -> ordered source-edge crossings -> whole-cycle holonomy decision`.

Final implementation authority is:

`ee1abbd91d8ab39b84b107bba73ebf7aa0acceb2`.

The Release/static/Ninja compile-only workflow completed all **120/120** build steps and produced an immutable result artifact. No generated Directional binary, GoogleTest discovery, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input was executed. The packaged command boundary and build-authority JSON record every runtime flag as `false`.

M1g is **not accepted yet**. Runtime semantic acceptance belongs only to the next immutable Test + Benchmark turn against result artifact `9053047653` and log artifact `9053048092`.

## 2. Selected ownership boundary

Before M1g, the periodic canonical face cycle discovered each ordered crossing and accumulated raw signed matchings in `int totalMatching`, then rejected when the whole-cycle value was nonzero modulo four.

M1g changes only the representation of that already-discovered ordered route:

1. preserve canonical face-cycle discovery and source/target order;
2. preserve existing source-edge provenance resolution and raw compatibility route output;
3. decode the packed crossing endpoints through checked `SourceVertexId` adapters;
4. construct canonical `SourceEdgeTopologyKey` and verify its packed compatibility round trip;
5. check the existing compact crossing provenance as `InteriorTransitionId`;
6. convert the directed matching to `QuarterTurn` plus zero-shift `GridAutomorphism`;
7. construct one interior `TransitionStep` per observed crossing;
8. construct one `CanonicalRoute::from_observed_steps(...)` after all crossings validate;
9. consume `CanonicalRoute::oriented_steps()` and compose transport in observed route order;
10. preserve the existing `PeriodicHolonomyMismatch` rejection whenever the composed rotation is nonzero;
11. preserve public `SurfacePeriodicHolonomy` compatibility output at zero whole-cycle rotation.

The explicit metadata-absent legacy matching-array path crosses the same typed route-composition boundary. No public schema or product capability was added.

## 3. Preserved behavior and explicit non-goals

M1g does not change:

- canonical periodic face-cycle discovery, start selection, or direction selection;
- source-edge crossing discovery or order;
- route topology or compact route output;
- transition direction resolution;
- legacy matching-array compatibility behavior;
- `PeriodicHolonomyMismatch` failure category or contextual face/edge fields;
- public `SurfacePeriodicHolonomy` rotation, route, component, sheet, lattice translation, or cut-route representation;
- lattice translation or periodic cut-route construction;
- the nonzero whole-cycle rotation rejection;
- `G4-B003` nonzero periodic Z4 capability;
- production `FieldChartId` adoption;
- M2–M6 ownership migration;
- validators, fallback/recovery, optimization, or G4 remediation.

## 4. Focused test authority compiled, not executed

Exactly six new tests are compiled under:

`SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration`.

They exercise the package-visible production consumer on the committed cylinder fixture and use independently authored route/topology/compact-ID expectations:

1. `NonzeroStepsComposeToZeroWholeCycle`
   - independently authors a 32-crossing route with directed turns `+1` and `-1` on the first two crossings;
   - requires zero whole-cycle rotation plus the exact ordered topology and independently enumerated compact IDs.
2. `ReverseObservedCycleUsesExactTransportInverse`
   - reflects circumferential vertex numbering so the observed semantic cycle reverses;
   - requires every paired semantic crossing to use the exact inverse transport and both cycles to retain zero holonomy with exact route output.
3. `EquivalentSignedRepresentationsNormalizeSemantically`
   - changes the two nonzero authoritative steps by `+4` and `-4`;
   - requires a byte-for-semantic-value identical public holonomy snapshot.
4. `RouteTopologyAndCompactIdentityIgnoreFaceRowOrder`
   - reverses face-row order while independently remapping face authority;
   - requires identical semantic route topology and compact source-edge identity.
5. `MalformedAuthoritativeCrossingProvenanceFailsClosed`
   - invalidates the first authoritative crossing's `sourceEdge` provenance;
   - requires `PeriodicHolonomyMismatch`, exact source/target faces, and no produced cells, seeds, traces, or proposals.
6. `LegacyMatchingPathUsesSameTypedAlgebra`
   - removes `edgeTransitions` and independently populates the legacy compact matching vector;
   - requires the authoritative and legacy production paths to emit the same public holonomy snapshot.

These are compile/package facts only. None of the six tests or any other generated executable ran in this turn.

## 5. Compile/package authority

| Evidence | Value |
|---|---|
| starting branch authority | `c4bbc5c347611a024531966ddd22494863da15ef` |
| accepted M1f ancestor | `baed0f24831c476f45a1b742c12314e3fb03e10e` |
| final M1g implementation | `ee1abbd91d8ab39b84b107bba73ebf7aa0acceb2` |
| observable trigger head | `5eca54d06017fce4dcded22262d98a5392e18522` |
| pull-request event commit | `3241133d2c73ad4a36959e46bc68375aefa15c82` |
| build run/job | `31362470744 / 93373936472` |
| result artifact | `9053047653` |
| result ZIP SHA-256 | `296f3ed13f2f09143a14f63555171d013939c2525052a56b807ea7f00cf1bd0c` |
| result size / expiry | **18,022,678 bytes** / `2026-08-24T06:41:56Z` |
| detailed log artifact | `9053048092` |
| log ZIP SHA-256 | `c5c3d964d9210982bfb08d0cf46900308a2498cee9ea2e54879dd35e61cacbd9` |
| log size / expiry | **10,038 bytes** / `2026-08-24T06:41:59Z` |
| recursive content manifest | **64/64**, SHA-256 `89beb0a12c1051a0fd4d55af6a8ee27e897c0f610045efa8b270a42dc09d51ae` |
| package regular files | **65** including `SHA256SUMS` |
| packaged executables / static libraries | **7 / 2** |
| packaged benchmark fixtures | **27** |
| packaged metadata / source / log files | **19 / 3 / 6** |
| build | **120/120**, Release/static/Ninja/PRE_TEST |
| build wall time / peak RSS | **6:48.58 / 1,848,960 KiB** |
| compiler/configure errors and warnings | **0 / 0** |
| runtime execution | **false** |

Final implementation blobs:

- `src/geometry/SurfaceCellTracing.cpp`: `3676ce3bea5c4f52eddc9da8d203076e4df809ca`;
- `tests/SurfaceCellsPhase10Tests.cpp`: `e186c33b8fcb779eff43e0a6ced96575d708088d`;
- `TODO`: `5ba3a72d2c9f9ecaf749e80be5abc78d147924ec`.

The retained source archive independently reproduces all three blob IDs. Local artifact inspection revalidated both ZIP digests, both ZIP structures, every **64/64** manifest entry, the 65-file package count, exact executable/library/fixture cardinalities, build-authority JSON, command boundary, focused-name files, and package/source blob authority.

Executable SHA-256 values:

- producer `ecb53fc658be166d52bc66fb66bb835ff6c8510e1a27b545aeb7378dfaffa5fd`;
- oracle `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`;
- authority kernel `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`;
- validation `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`;
- completion `08432de31070d878a9839d04efdf83e77dc499045214a71abf6b7555653329c1`;
- compiled API `b76d6511dfcb60dd763d0f4e90f9ca3639c2bcfc7ccc0ff05988c8280de35667`;
- benchmark `9945050030b7822d492207ca6b491a3707a2490c8e8c80c28abc53d21d0ccf37`.

## 6. Packaging metadata correction

M1g corrects the non-blocking M1f packaging defect in `metadata/direct-product-test-names.txt`. The immutable package now records the four existing parameterized independent-oracle product names:

- `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Plane`;
- `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/MultiFaceSeam`;
- `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/CloseSheets`;
- `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Cylinder`.

This is packaging metadata only. Product code, product behavior, test semantics, and the existing parameterized tests are unchanged.

## 7. CI observability and cleanup

The installed GitHub connector exposes only pull-request-triggered workflow runs. The initial push-triggered lane therefore could not provide connector-visible run authority, and a workflow added only on PR #8's head could not trigger from base branch `surface_cell_quad` because GitHub evaluates `pull_request` workflows from the base.

The final observable build used temporary draft child PR #11. PR #8's branch first held the temporary workflow as the child PR base; the child head changed only the exact marker path. This registered run `31362470744` directly with the connector. Shared concurrency cancelled any still-live earlier lane. PR #11 was closed unmerged after artifact verification. The temporary workflow was removed before its marker from PR #8's branch.

No earlier unobservable run is acceptance authority. Only run/job `31362470744 / 93373936472` and artifacts `9053047653 / 9053048092` are authoritative for M1g Code + Build.

## 8. Regression disposition

M1g remains compile-complete/runtime-pending:

- `RP-01`: checked periodic crossing domains compile-complete; runtime pending;
- `RP-05`: semantic whole-cycle route identity and observed/canonical orientation compile-complete; runtime pending;
- `RP-07`: typed whole-cycle cumulative transport compile-complete; runtime pending;
- `RP-02 / TA-05`: preservation awaits immutable artifact validation.

No new stable product regression event or recurrence is assigned. Historical totals remain **34 regression events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` stays active and unchanged. `G4-B003` remains unresolved because M1g deliberately retains nonzero periodic Z4 rejection.

## 9. Authoritative next turn

Run **M1g Periodic Holonomy Route Transport Consumer — immutable Test + Benchmark only** under:

`.agents/Directional/Architecture_M1g_Periodic_Holonomy_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

Consume only result/log artifacts `9053047653 / 9053048092`. Rebuild, relink, regeneration, source/test/build/fixture edits, repair, or artifact substitution are prohibited.

Expected native producer discovery after the six new focused tests is exactly **196**. The required-green producer segment is expected to be **181/181** after retaining the same four separately run direct product cases, nine historical/deferred cases, Bunny, and Vase dispositions accepted through M1f.

Any required-green semantic or preservation failure remains at M1g and returns to corrective Code + Build. Do not advance to production `FieldChartId`, another M1 consumer, M2, or G4 remediation until immutable M1g acceptance.
