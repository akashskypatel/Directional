# M1k Phase-Front Edge Topology-Region Consumer — Code + Build Plan

**Turn type:** Code + Build only  
**Review policy:** `never`  
**Prerequisite:** M1j immutable accepted from implementation `d5f681173600dc32dc7617de6105d9e584e593be`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Purpose

Perform the next smallest authority-domain migration explicitly deferred by M1j:

`SurfaceTopologyRegion::id / normalize_scope -> SurfaceFrontEdge::sourceTopologyRegion -> still-raw pipeline compatibility consumers`

M1j accepted typed edge-owned source-component and isolation-sheet authority but deliberately left `SurfaceFrontEdge::sourceTopologyRegion` as a raw `int`. The authority kernel already defines `TopologyRegionId`, and the normative design treats source topology region, isolation sheet, and field chart as distinct semantic domains. M1k migrates only the persistent edge-owned topology-region identity and preserves every existing topology-region construction, numbering, boundary, and product behavior.

## 2. Entering authority

M1j immutable acceptance:

- implementation `d5f681173600dc32dc7617de6105d9e584e593be`;
- exact result/log artifacts `9076217893 / 9076218338`;
- recursive package checksums **67/67**;
- producer discovery **214**;
- M1j focused **6/6**;
- required-green producer **199/199**;
- M1i-M1b focused preservation green;
- M1d route witnesses **3/3**;
- M1c transition counterexamples **3/3**;
- validation **77/77**, M1a **14/14**, T1 **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean;
- all eight historical/deferred red classes unchanged;
- strict-validator timing remains deferred at fresh **0/10**;
- Bunny remains `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`;
- Vase remains bounded safety-only at 60 seconds.

Historical regression totals remain **34 events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active.

## 3. Selected bounded seam

Current accepted state includes:

- `SurfaceFrontEdge::sourceComponent` as checked optional `SourceComponentId`;
- `SurfaceFrontEdge::sourceSheet` as checked optional `IsolationSheetId`;
- `SurfaceFrontEdge::sourceIsolationSheets` as a typed collection;
- `SurfaceFrontEdge::sourceTopologyRegion` still raw `int`;
- `SurfaceTopologyRegion::id` and neighboring topology-region schemas still raw compatibility representations.

M1k changes only the semantic edge owner:

1. replace `SurfaceFrontEdge::sourceTopologyRegion` with an optional or otherwise explicitly nullable `authority::TopologyRegionId`;
2. establish/check that typed region identity from the existing authoritative region assignment path before semantic use;
3. preserve the existing topology-region partition and deterministic region numbering exactly;
4. preserve existing component/sheet authority already accepted by M1i/M1j;
5. compare topology-region identity semantically as `TopologyRegionId`, never by numeric coincidence with `IsolationSheetId`, `SourceComponentId`, `FieldChartId`, or another integer domain;
6. at still-raw neighboring consumers, convert through a named `LegacyAuthorityAdapters::topology_region` / explicit typed-to-legacy compatibility helper rather than retaining a duplicate raw mirror on `SurfaceFrontEdge`;
7. fail closed through the existing production failure path when a required topology-region identity is missing, out of range, or inconsistent with authoritative region assignment;
8. preserve deterministic semantics under face-row/container-order permutations.

If an extent for checked conversion must be derived from the current raw region representation, derive it explicitly from validated `SourceTopologyRegions::regions` / authoritative region indexing. Do not infer domain compatibility from equal integer values.

## 4. Explicit exclusions

M1k must **not** migrate or redesign:

- `SurfacePhaseFrontCell::sourceTopologyRegion`;
- `SurfaceTopologyRegion::id` itself;
- `SurfaceTopologyRegion::sourceComponent` or `SurfaceTopologyRegion::isolationSheets`;
- `SourceTopologyRegions::regionByFace`;
- any `SurfacePhaseFrontResult` face-to-region raw mapping;
- `SurfacePeriodicHolonomy::{sourceTopologyRegion,...}`;
- bounded-disk topology-region fields;
- isolation-seam transport certificate topology-region fields;
- topology-region discovery, partitioning, construction, numbering, Euler/boundary computation, or structural hashing policy;
- periodic relation owner IDs, hard-rail IDs, CellId, OccurrenceId, QuotientClassId, or other authority domains;
- source-sheet/topology boundary semantics;
- hard features, relief barriers, singularity handling, periodic-holonomy behavior, or G4 completion behavior;
- fallback/recovery semantics;
- optimization;
- M2-M6 architecture work;
- fixtures, validators, benchmark thresholds, strict-validator threshold/retry policy, or historical known-red expectations.

M1k is an authority representation/consumer migration only. It must not make a known-red test green by changing product policy.

## 5. Expected implementation files

Expected bounded source/test surface:

- `include/directional/geometry/SurfaceCellTracing.h`;
- `src/geometry/SurfaceCellTracing.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp`;
- `src/pipeline/RemeshPipeline.cpp` only where compilation or direct source inspection proves a still-raw consumer requires explicit typed-to-legacy conversion.

Do not modify CMake, fixture lookup, validators, benchmark data, public product policy, or unrelated code. If an additional source path is genuinely required for direct compatibility conversion, document the reason before editing and keep it minimal.

## 6. Required implementation shape

### 6.1 Edge-owned typed authority

`SurfaceFrontEdge` should contain one typed semantic topology-region field and no duplicate raw mirror for the same edge-owned meaning.

Recommended representation:

`std::optional<authority::TopologyRegionId> sourceTopologyRegion;`

Use explicit nullability only for legitimate pre-publication/unassigned state. Published authoritative edges must not silently carry missing region identity when the current production contract requires one.

### 6.2 Publication and normalization

The existing region aggregation/normalization path already knows the authoritative `SurfaceTopologyRegion` being processed. Convert/check `region.id` through the topology-region authority domain and establish or validate the edge’s typed region identity.

Preserve the M1j ownership rule: normalization may establish the still-unmigrated region identity, but it must not recreate/overwrite already typed source-component or isolation-sheet semantics.

### 6.3 Consumer compatibility

For still-raw consumers, introduce/reuse narrow named helpers such as:

- typed edge topology region -> legacy `int` representation;
- checked raw authoritative region id -> `TopologyRegionId`.

Do not scatter `.value`/raw casts through product code when a named boundary makes the domain crossing explicit.

## 7. Exactly six focused production-path contracts

Add exactly six tests under:

`SurfaceCellPhaseFrontEdgeTopologyRegionAuthorityMigration`

Required names and intent:

1. `PlanarEdgesPublishCheckedTopologyRegionZero`
   - production planar path publishes a present checked `TopologyRegionId` corresponding to the established default region;
   - component/sheet authority remains intact.

2. `DistinctTopologyRegionsRemainDistinctFromIsolationSheets`
   - construct a production-reachable case where topology-region and sheet/component integers can numerically coincide or differ;
   - prove semantic topology-region authority is obtained from region ownership, not sheet identity or raw numeric reuse.

3. `MissingOrInvalidEdgeTopologyRegionFailsClosed`
   - exercise the nearest production path where required authoritative region assignment is absent/invalid/inconsistent;
   - require the existing fail-closed production disposition, not a partially scoped edge.

4. `FaceRowPermutationPreservesTypedEdgeTopologyRegion`
   - permute source face rows/container order while preserving geometry/authority;
   - compare semantic edge topology-region ownership rather than positional edge IDs.

5. `CrossRegionOppositesRetainDistinctTypedRegionIdentity`
   - exercise adjacent/opposite edge publication across distinct established topology regions where production permits the relationship;
   - prove each edge retains its own checked region identity without aliasing across the boundary.
   - If fresh source inspection proves this exact opposite-edge relationship is structurally unreachable, replace it with the nearest production-reachable cross-region edge relation that proves the same non-aliasing invariant; do not synthesize an impossible fixture.

6. `TypedEdgeTopologyRegionToLegacyPipelineBoundaryPreservesCompatibility`
   - exercise the real pipeline boundary consuming the edge region in raw compatibility form;
   - prove the value comes from typed edge authority and preserves existing observable behavior.

These tests must execute real production paths in the following Test + Benchmark turn. Do not test only adapters or private mechanics.

## 8. Regression-pattern interlock

Before editing, review `.agents/Directional/Regression_Root_Cause_Tracker.md`, especially `RP-01` through `RP-09`.

M1k directly touches:

- `RP-01` authority-domain conflation;
- `RP-05` representation-dependent identity;
- `RP-02 / TA-05` test authority;
- potentially `RP-09` local consumption of global authority if a consumer attempts to reconstruct region ownership locally.

Required counterexample thinking:

- topology region and isolation sheet are not numerically interchangeable;
- invalid/missing region authority fails closed;
- region identity derives from authoritative region membership, not container position;
- face-row permutation preserves semantic identity;
- edge consumers do not reconstruct global region identity from local sheet/component values;
- still-raw compatibility values are derived from the typed edge owner only.

Compile-only failures are diagnosis, not stable product regressions. Do not assign a new regression ID until previously accepted runtime behavior is shown lost.

## 9. Code + Build execution boundary

This turn may:

- inspect accepted source and authority definitions;
- edit only the bounded source/test surface;
- configure a Release/static/Ninja build with GoogleTest discovery mode `PRE_TEST`;
- compile/link approved targets;
- package immutable outputs and metadata.

This turn must **not execute**:

- any generated Directional binary;
- GoogleTest `--gtest_list_tests` or any discovery/list command;
- any test;
- any benchmark;
- `ctest`;
- CLI/GUI/help/version commands;
- fuzzers;
- custom mesh/input execution.

The package/build metadata must explicitly record all runtime/test/benchmark/ctest/CLI/fuzzer/custom-input execution flags as false.

## 10. Approved compile targets

Compile/link only the established approved targets:

- `directional_core`;
- `directional_pipeline`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_oracle_tests`;
- `directional_surface_cell_authority_kernel_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_benchmarks`.

Expected build configuration: Release, static libraries, Ninja, `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`, no CLI/GUI/Python/tutorial execution surface.

## 11. Immutable package requirements

Package the exact successfully compiled implementation with:

- seven approved executables;
- `libdirectional_core.a` and `libdirectional_pipeline.a`;
- the 27 benchmark fixtures in sibling `test-data/benchmarks/fixtures` layout;
- source archive/patch sufficient to bind the exact implementation;
- exact implementation SHA and source parent/M1j accepted reference;
- submodule/toolchain/configuration metadata;
- changed source/test blob IDs;
- exact six M1k focused test names plus retained M1j-M1b/M1a/T1 manifests;
- exact four direct-product names;
- command-boundary metadata with every runtime flag false;
- executable/library SHA-256 metadata;
- recursive `SHA256SUMS` generated **after every package write**, then verified.

Do not repeat the M1j packaging mistake where a package file was added after the recursive manifest was generated.

## 12. Code + Build acceptance gate

M1k Code + Build is complete only if all hold:

1. implementation diff remains inside the declared bounded seam;
2. `SurfaceFrontEdge` carries typed topology-region authority without a duplicate raw mirror;
3. topology-region construction/numbering semantics remain unchanged;
4. component/sheet authority accepted by M1j is not rewritten or weakened;
5. still-raw consumers use explicit named compatibility conversion;
6. exactly six M1k production-path contracts compile;
7. all approved targets compile/link successfully;
8. immutable package and recursive checksums are complete and generated after all package writes;
9. every runtime/test/benchmark/ctest/CLI/fuzzer/custom-input execution flag is false;
10. no fixture, validator, threshold, or historical known-red expectation is weakened;
11. temporary workflows/triggers/payloads are removed before closeout;
12. PR #8 remains open, draft, and unmerged.

Compile success does **not** accept M1k semantics.

## 13. Mandatory following turn

After successful Code + Build, the next turn is:

**M1k Phase-Front Edge Topology-Region Consumer — immutable Artifact-Only Test + Benchmark only**.

Expected semantic authority after adding exactly six producer contracts:

- producer discovery: **220** (`214 + 6`);
- M1k focused: **6/6** individually;
- required-green producer: **205/205** (`220 - 15`);
- preserve M1j-M1b focused authority, M1d/M1c counterexamples, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products, all eight historical/deferred red classes, strict timing characterization, bounded Bunny/Vase comparison, and exact immutable postflight.

No runtime semantic acceptance may be claimed in this Code + Build turn.
