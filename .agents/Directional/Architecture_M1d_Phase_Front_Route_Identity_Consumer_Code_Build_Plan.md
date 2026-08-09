# M1d Phase-Front Route Identity Consumer — Code + Build Plan

**Status:** authoritative next turn  
**Turn type:** Code + Build only  
**Architecture milestone:** M1 — authority kernel and staged production adoption  
**Depends on:** immutable accepted M1a + M1b + M1c  
**Product behavior delta intended:** none  
**Review policy:** `never`

## 1. Objective

Migrate exactly one additional real production consumer from parallel raw route identity to the accepted M1 authority types without changing public storage or product disposition:

`pipeline::build_authoritative_phase_front_mesh -> exact_interior_route_valid`

This local consumer validates the `SurfaceFrontEdge::sourceRouteEdges` / `sourceRouteTopology` route used by authoritative **HardRail** and **PeriodicCut** front relations. Today it establishes semantic route identity using raw compact transition integers and raw packed `uint64_t` source-edge keys.

M1d makes that validation typed at the point of consumption using:

- `InteriorTransitionId` for compact interior-transition identity;
- checked `SourceVertexId` for decoded source-edge endpoints;
- canonical `SourceEdgeTopologyKey` for semantic source-edge identity.

M1d deliberately does **not** migrate route transport to `TransitionStep` or `CanonicalRoute`: this consumer does not own per-step transport data, so manufacturing identity transport merely to use those types would add false semantics. Their production adoption remains a later bounded M1 slice at a consumer that actually owns step transport.

## 2. Accepted entering authority

M1c is immutable accepted under:

`.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

Exact M1c comparison authority:

| Evidence | Value |
|---|---|
| implementation | `e139fca885538e310dc47ed7ba531517603d92cf` |
| build/event | `ebda31859a18005844f81274393211991361cbbb` |
| build run/job | `31334345368 / 93297618568` |
| result artifact | `9043971772` |
| result SHA-256 | `dde120c94be222dc93aeebb08f7a674882c5f8011ede62ec420209b0e0f4fd85` |
| log artifact | `9043971968` |
| log SHA-256 | `7747b3b25882fc86e54890a1efb69d753f9b2e08bff7db8fd2be4f4a8a82fedb` |
| package manifest | **54/54**, `d9a4bdfe5b160095a6cf4949c57e54d726d36f745ff0a6580e9080d5319d495d` |
| M1c focused | **6/6** |
| M1b focused / validation | **6/6**, **77/77** |
| M1a / T1 | **14/14**, **29/29** |
| producer required-green segment | **157/157** |
| direct required-green | Plane / MultiFaceSeam / CloseSheets / Cylinder green and oracle-clean |

Producer discovery is exactly 172 with explicit accepted accounting: 157 required-green, four separately run direct-green cases, nine historical/deferred known-red tests, Bunny known-red, and Vase bounded safety-only.

## 3. Current legacy seam

Inside `build_authoritative_phase_front_mesh`, the local `exact_interior_route_valid` currently accepts:

```text
vector<int> routeEdges
vector<uint64_t> routeTopology
```

and validates each parallel pair by:

1. requiring nonempty topology and equal vector sizes;
2. using raw `uint64_t` topology as uniqueness identity;
3. looking the raw key up in `exactSourceIncidence` and `sourceEdgeIndices`;
4. requiring an interior two-face source edge;
5. comparing raw `sourceEdgeIndices[topology] == routeEdges[index]`.

That truth table is behavior authority. M1d changes only how semantic identity is established before the same compatibility lookup/comparison.

## 4. Allowed implementation scope

Default allowed paths:

1. `src/pipeline/RemeshPipeline.cpp`;
2. `tests/SurfaceCellTransitionQuotientTests.cpp`.

No header, CMake, fixture, validator, benchmark, public result, or tracing-producer change is expected.

Any need to change a different production/test/build path is a stop condition requiring plan revision before coding.

## 5. Required implementation

### 5.1 Checked source-edge topology consumption

For each `routeTopology[index]` inside `exact_interior_route_valid`:

1. decode the existing packed compatibility key into its two unsigned 32-bit source-vertex row values without narrowing through signed `int` first;
2. convert both values through `LegacyAuthorityAdapters::source_vertex(..., sourceVertices.rows())`;
3. reject adapter failure;
4. construct `SourceEdgeTopologyKey::make(v0, v1)` and reject degenerate-edge failure;
5. use `SourceEdgeTopologyKey` as the semantic uniqueness identity;
6. convert the typed endpoints back to legacy row indices and re-create the existing raw `surface_cell_source_edge_key` only at the compatibility map boundary;
7. require that this representation equals the supplied raw topology key before using the existing maps.

Do not introduce another hash scheme. Do not treat packed integer coincidence as semantic source-edge identity.

### 5.2 Checked interior-transition identity

For the route's compact transition index and the index retrieved from `sourceEdgeIndices`:

1. use `sourceEdgeIndices.size()` as the exact compact transition extent for this consumer;
2. convert both values through `LegacyAuthorityAdapters::interior_transition`;
3. reject negative/out-of-range route values through typed conversion failure;
4. compare `InteriorTransitionId` values, not raw integers, to establish semantic equality.

Do not change how `sourceEdgeIndices` is produced or stored in M1d.

### 5.3 Preserve the public compatibility representation

Keep unchanged:

- `SurfaceFrontEdge::sourceRouteEdges` as `std::vector<int>`;
- `SurfaceFrontEdge::sourceRouteTopology` as `std::vector<std::uint64_t>`;
- `SurfacePeriodicHolonomy` route storage;
- route ordering;
- boundary kind and periodic relation storage;
- diagnostic copies/hashes;
- source-edge lookup maps.

M1d is a consumer-boundary migration only.

### 5.4 Preserve fail-closed behavior

The existing failures remain authoritative:

- malformed HardRail route -> `InvalidHardRailAuthority`;
- malformed PeriodicCut route -> `InvalidPeriodicCutAuthority`;
- genuine source boundary continues to use its separate topology-only validation;
- ordinary front relations continue to prohibit route metadata.

Malformed typed route metadata must never be normalized, clamped, dropped, replaced, or allowed to fall through to a different relation class.

## 6. Explicit non-goals

Do not change in M1d:

- route producer logic in `SurfaceCellTracing.cpp`;
- `CrossFieldEdgeTransition` or `CrossFieldResult`;
- quarter-turn transport semantics accepted in M1c;
- `TransitionStep`, `CanonicalRoute`, `FieldChartId`, or per-step transport production;
- public route vector schemas;
- periodic-holonomy transform/certificate policy;
- topology regions, isolation certificates, hard-rail scheduling, quotient materialization, completion, optimization, validation, fixtures, or fallback/recovery policy;
- historical known-red producer dispositions;
- G4-R007, Bunny, or Vase behavior.

## 7. Mandatory regression-pattern review

### `RP-01` — authority-domain conflation

**Touched.** Raw route integers represent `InteriorTransitionId`, not source vertices, faces, cells, or arbitrary rows.

Invariant: compact transition identity is established only after checked `interior_transition` conversion; source-edge endpoints cross checked `source_vertex` conversion.

Counterexamples: negative transition index, out-of-range transition index, out-of-range decoded source vertex.

### `RP-05` — representation-dependent identity

**Touched.** Packed `uint64_t` and compact vector index are compatibility representations, not semantic authority.

Invariant: semantic edge uniqueness/equality is `SourceEdgeTopologyKey`; semantic compact-transition equality is `InteriorTransitionId`.

Counterexamples: malformed packed endpoint domain, duplicate semantic topology, topology/transition pair mismatch.

### `RP-02 / TA-05` — independent test authority

**Preservation boundary.** Focused route tests cannot replace M1c/M1b/M1a/T1/direct product evidence. The immutable following turn must retain exact producer accounting and independent-oracle evidence.

`RP-03/04/06/07/08/09` are not migrated by this slice. In particular `RP-07` quarter-turn behavior is intentionally untouched after M1c acceptance.

## 8. Focused test additions

Add the minimum behavior-focused coverage to the existing default-built `directional_surface_cell_producer_tests`, preferably under a dedicated suite such as `SurfaceCellPhaseFrontRouteAuthorityMigration` in `SurfaceCellTransitionQuotientTests.cpp`.

Required contracts:

1. **ValidHardRailRouteUsesTypedIdentity** — a real hard-rail fixture materializes successfully and retains exact route/cardinality semantics.
2. **ValidPeriodicCutRouteUsesTypedIdentity** — a real accepted cylinder periodic-cut route materializes successfully through the same consumer.
3. **InvalidInteriorTransitionIdFailsClosed** — negative and clearly out-of-range route transition IDs reject as `InvalidHardRailAuthority` rather than being interpreted as another domain.
4. **OutOfDomainPackedSourceVertexFailsClosed** — a route topology key containing a source-vertex row outside `sourceVertices.rows()` rejects fail-closed.
5. **RouteTopologyTransitionMismatchFailsClosed** — a valid semantic topology paired with a different valid compact transition ID rejects rather than passing by raw representation accident. If the selected fixture cannot naturally provide two distinct valid compact transitions, use the smallest existing fixture that does; do not fabricate an impossible scenario.
6. **DuplicateSemanticRouteTopologyFailsClosed** — duplicating the same semantic source edge in one authoritative interior route rejects.

Use `build_authoritative_phase_front_mesh` through existing real fixture helpers. Expected values must come from source topology/fixture intent, not by calling the migrated validator to compute its own oracle.

Retain explicit visibility in the immutable following turn for:

- `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`;
- `SurfaceCellTransitionQuotient.ArtificialInteriorBoundaryIsRejected`;
- `SurfaceCellTransitionQuotient.ComponentBoundaryAndEulerFactsAreComputedFromIncidence`;
- all six M1c field-transition authority contracts;
- all three M1c pre-existing transition counterexamples.

Do not rewrite historical known-red quotient/torus tests to make this slice green.

## 9. Code + Build execution boundary

This turn may:

- edit only the approved source/test paths;
- run static source inspection;
- configure Release/static/Ninja;
- compile/link approved targets;
- package immutable binaries, fixtures, source diff/archive, compile database, source blobs, command-boundary metadata, static test-name manifests, and exact known-red accounting metadata.

This turn must **not** execute any generated Directional binary, GoogleTest discovery/test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input.

Use `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`.

Compile at minimum:

- `directional_core`;
- `directional_pipeline`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_oracle_tests`;
- `directional_surface_cell_authority_kernel_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_benchmarks`.

## 10. Code + Build acceptance

M1d Code + Build is complete only if:

1. final implementation/test diff is bounded to the two approved paths;
2. source-edge endpoints cross checked `SourceVertexId` adapters before semantic use;
3. source-edge route uniqueness/equality uses `SourceEdgeTopologyKey`;
4. route compact transition identity uses checked `InteriorTransitionId`;
5. packed topology and raw vector index remain explicit compatibility boundaries only;
6. public route storage and all relation/product policy remain unchanged;
7. required semantic/counterexample tests compile into the default producer target;
8. Release/static/Ninja approved targets compile/link completely;
9. immutable package/source/manifest authority is complete and hashable;
10. `runtimeExecution=false` is explicit and no generated project binary was executed.

Compile success does **not** accept M1d semantics.

## 11. Following immutable Test + Benchmark

The following turn must consume only the exact M1d artifact and must not rebuild or edit source.

Required evidence:

1. exact package/source/dependency/manifest preflight;
2. exact discovery of the M1d focused suite and all focused contracts individually green;
3. explicit existing route counterexamples green;
4. M1c exact six discovery and **6/6**;
5. the three M1c transition counterexamples remain green;
6. producer discovery/accounting remains exact, with all previously required-green members green and the nine historical/deferred known-red members still explicit rather than hidden;
7. M1b **6/6** + validation **77/77**;
8. M1a exact 14 + **14/14**;
9. T1 exact 29 + **29/29**;
10. Plane/MultiFaceSeam/CloseSheets/Cylinder green and independent-oracle clean;
11. Bunny remains evidence-classified known-red and Vase remains bounded safety-only unless the actual immutable result legitimately changes;
12. postflight preserves all original artifact/package content hashes.

Bunny/Vase may use the standing temporary artifact-only GitHub Actions procedure already documented in the handoff.

## 12. Stop conditions

Stop and revise before coding if the slice requires:

- changing public `SurfaceFrontEdge` or `SurfacePeriodicHolonomy` route storage;
- changing route production or transport semantics;
- inventing transport merely to force `TransitionStep`/`CanonicalRoute` into this consumer;
- changing periodic, topology, rail, quotient, validator, fixture, benchmark, or fallback policy;
- repairing historical known-red tests;
- editing more than the approved narrow source/test paths.

If the immutable following turn finds a required-green regression, remain at M1d and return to a corrective Code + Build. Do not advance to another consumer.
