# M1k Phase-Front Edge Topology-Region Consumer — Code + Build Report

**Status:** compile/package complete; immutable runtime pending  
**Turn type:** Code + Build only  
**Review policy:** `never`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Scope

M1k migrates the bounded seam:

`SurfaceTopologyRegion::id / normalize_scope -> SurfaceFrontEdge::sourceTopologyRegion -> still-raw pipeline compatibility consumers`

Final implementation: `b9181364926cea840e9cb50da21fe721f33fd874`  
Immediate source parent for the M1k product/test delta: `38d6fc4c4042c5a0d200abf4e5594dcf325b8383`  
Accepted M1j ancestor: `d5f681173600dc32dc7617de6105d9e584e593be`

The product/test delta remains exactly four paths:

1. `include/directional/geometry/SurfaceCellTracing.h`
2. `src/geometry/SurfaceCellTracing.cpp`
3. `src/pipeline/RemeshPipeline.cpp`
4. `tests/SurfaceCellsPhase10Tests.cpp`

`tests/TestFixturePaths.h` is unchanged.

## 2. Implemented contract

`SurfaceFrontEdge::sourceTopologyRegion` now owns one explicitly nullable checked semantic identity:

```cpp
std::optional<authority::TopologyRegionId> sourceTopologyRegion;
```

The migration preserves the existing topology-region partition and deterministic raw region numbering. During region aggregation, the current authoritative `SurfaceTopologyRegion::id` is checked through `LegacyAuthorityAdapters::topology_region(...)` using the validated region extent and is then established on persistent front edges. Published edges are rejected if their typed topology-region authority is absent or inconsistent with the owning authoritative region.

M1k preserves the previously accepted M1i/M1j component and isolation-sheet authority. It does not infer topology-region identity from `SourceComponentId`, `IsolationSheetId`, numeric coincidence, world-space proximity, or container position.

Still-raw neighboring consumers cross the representation boundary through a named typed-to-legacy helper. This includes structural hashing and the existing raw topology-region compatibility checks in authoritative materialization, isolation-seam certificates, connectivity queries, and periodic relation compatibility. Direct edge-to-edge semantic comparisons continue to use the typed identity.

M1k deliberately does **not** migrate or redesign:

- `SurfacePhaseFrontCell::sourceTopologyRegion`;
- `SurfaceTopologyRegion::id`;
- `SourceTopologyRegions::regionByFace` or phase-front face-to-region raw maps;
- periodic/bounded-disk/certificate topology-region schemas;
- topology-region discovery, partitioning, numbering, Euler/boundary computation, or structural hashing policy;
- source component/sheet authority;
- G4 completion behavior, fallback/recovery, optimization, M2–M6, validators, fixtures, or thresholds.

## 3. Unit-test design changes

Exactly six production-path contracts were added under `SurfaceCellPhaseFrontEdgeTopologyRegionAuthorityMigration`:

1. `PlanarEdgesPublishCheckedTopologyRegionZero`
2. `DistinctTopologyRegionsRemainDistinctFromIsolationSheets`
3. `MissingOrInvalidEdgeTopologyRegionFailsClosed`
4. `FaceRowPermutationPreservesTypedEdgeTopologyRegion`
5. `CrossRegionOppositesRetainDistinctTypedRegionIdentity`
6. `TypedEdgeTopologyRegionToLegacyPipelineBoundaryPreservesCompatibility`

The contracts exercise real producer/materializer paths and cover checked publication, cross-domain numeric coincidence, fail-closed missing/stale authority, face-row permutation, cross-region hard-rail counterpart ownership, and the named typed-to-legacy pipeline boundary.

These tests **compiled only** in this turn. No generated test binary was discovered, listed, or executed.

## 4. Code + Build orchestration provenance

Several temporary control-plane/package attempts were required before the final immutable package was complete. None executed a generated Directional binary and none establishes a stable product regression.

- Run `31428058924`, job `93584409018`: patch preflight failed before source/build because generated unified-diff hunk counts required `git apply --recount`.
- Run `31428248928`, job `93585041361`: committed/pushed exact implementation `b9181364926cea840e9cb50da21fe721f33fd874`; all approved targets compiled/linked **121/121** in 8:35.92 with peak RSS 1,860,804 KiB. Packaging then stopped because a cleanliness guard incorrectly counted the newly generated untracked build/log directories.
- Run `31429186438`, job `93588109467`: exact implementation rebuilt **121/121** in 8:01.47 with peak RSS 1,860,800 KiB; packaging then stopped because the workflow incorrectly expected all 27 fixtures under `benchmarks/fixtures/milestone-g` rather than the source-authoritative 21 files there plus six root fixture files.
- Run `31430110544`, job `93591192882`: exact implementation and corrected 27-fixture layout compiled/packaged successfully, but this package was superseded while completing the full retained authority metadata.
- Run `31430308648`, job `93593668297`: another successful exact-source compile/package attempt was superseded because optional Bunny/Vase metadata still used stale non-parameterized names.
- Temporary metadata-fix run `31430766530`, job `93593355238`: failed only because the Actions token lacked permission to push a workflow-file change. No product/source change and no generated Directional execution occurred.

The final package below is the sole Code + Build runtime authority for the following turn.

## 5. Authoritative Code + Build evidence

| Evidence | Value |
|---|---|
| implementation | `b9181364926cea840e9cb50da21fe721f33fd874` |
| source parent | `38d6fc4c4042c5a0d200abf4e5594dcf325b8383` |
| accepted M1j implementation | `d5f681173600dc32dc7617de6105d9e584e593be` |
| build run/job | `31430898273 / 93593780187` |
| configuration | Release / static / Ninja / `PRE_TEST` |
| approved build targets | **121/121** |
| build wall time | **8:19.09** |
| build peak RSS | **1,860,456 KiB** |
| result artifact | `9079318682` — `m1k-edge-topology-region-code-build-result-final` |
| result ZIP SHA-256 | `90b8deea85c12460ae45b66d0c7aa67fa3771074b60841fd1a0e586b0088869d` |
| log artifact | `9079319269` — `m1k-edge-topology-region-code-build-logs-authoritative` |
| log ZIP SHA-256 | `1a9a06fe42e2329cff1ff9d5b4eba0b7986af47d855229119e6d76bc2f07e381` |
| recursive manifest | **68/68**, SHA-256 `0b76267ea2e40c5c417c0cade77e0b95d75fe1c27a6a2a94cc283f6c7660583c` |
| package cardinality | **69** regular files including `SHA256SUMS`; 7 executables; 2 static libraries; 27 fixtures |
| milestone-G fixture files | **21** |
| package symlinks | **0** |

Independent non-executing inspection of the downloaded result/log ZIPs verified:

- the two outer SHA-256 digests above;
- no absolute or `..` archive paths;
- zero package symlinks;
- all **68/68** recursive manifest entries;
- the manifest digest and 69-file package closure;
- exactly seven executables, two libraries, 27 fixture files, and 21 files under `milestone-g`;
- exact build-authority metadata for implementation `b9181364926cea840e9cb50da21fe721f33fd874`, run `31430898273`, Release/static/Ninja/PRE_TEST;
- every command-boundary flag false;
- final Ninja progress `[121/121]` and build exit status 0.

No packaged executable was run during this inspection.

## 6. Compiled source/package authority

Packaged source blobs:

- tracing header: `f4d228fa815925d6ff361dd4093d24fb8d14c732`;
- tracing implementation: `56cb32248c1173b8acd5b7660885c468a3919f72`;
- pipeline: `a10808a9d267e664ea6484f9064ffb5b0972b6d3`;
- phase-10 tests: `a524a39ce21740442c904490952b9f7c41c0cf23`;
- fixture paths: `4a981f772ee70780d0011696010a0e1b8bef6972`.

Executable SHA-256 values:

- producer: `3218b439a038adff6834d6003289488a3fb266231d7f157151964ed58c3430d1`;
- completion: `fde413de5e07f121f9041e0c15dc814151335f24152aeb5e72c9854ed496c21b`;
- independent oracle: `9ef54b65e1a00c5d46e769379bcef548beeb16cce94c92dbaa00ed4a5887db84`;
- benchmarks: `26f760ad8da67c020964320fffaf1ab4f2a72d3b18a53cba588585428838b1b2`;
- compiled API: `ccae143d464ddc374fe5f4055fbf5f9b6ea3f6d17dbae9d6bd90037987bf1a24`;
- authority kernel: `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`;
- validation: `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`.

Library SHA-256 values:

- `libdirectional_core.a`: `03461b4a4a6fed347e124042c457fe52afa111132cf0c9e3736937cccbb2eb7a`;
- `libdirectional_pipeline.a`: `87f69d1eb59eb2c6925af166621b2e02701a7f7992b68f82bc0496acb29efbcc`.

The package also contains the exact implementation source archive, compile commands, submodule status, exact retained test-name manifests from M1j through M1b, M1a/T1 names, direct-product names, historical/deferred-red names, and corrected parameterized Bunny/Vase names.

## 7. Command-boundary compliance

The final build authority records every one of these as `false`:

- generated Directional runtime execution;
- GoogleTest discovery/list execution;
- test execution;
- benchmark execution;
- `ctest` execution;
- CLI/GUI/help/version execution;
- fuzzer execution;
- custom-input execution.

`CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST` was configuration only. Compile success therefore does **not** establish semantic M1k acceptance.

## 8. Regression disposition

No stable product regression event or recurrence is assigned from this compile/package-only evidence. The orchestration failures above occurred before semantic runtime and did not demonstrate loss of previously accepted product behavior.

Historical totals remain **34 regression events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active. G4 topology-distinct completion and singularities is unchanged.

The M1k implementation specifically continues the `RP-01`, `RP-05`, `RP-02 / TA-05`, and `RP-09` authority-hardening direction by preventing topology-region identity from being reconstructed by numeric coincidence or local source-sheet/component values. Runtime acceptance remains pending.

## 9. Next turn

Run **M1k Phase-Front Edge Topology-Region Consumer — immutable Artifact-Only Test + Benchmark only** under:

`.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Plan.md`

Consume **only** artifacts `9079318682 / 9079319269`. Rebuild, relink, configure, regeneration, source/test/build/fixture edits, package repair/substitution, and runtime fixture symlinks are prohibited.

Expected native producer discovery is **220**; M1k focused **6/6** individually; required-green producer **205/205**, with all entering preservation gates and exact immutable postflight.
