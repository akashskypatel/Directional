# M1l Phase-Front Cell Topology-Region Consumer — Code + Build Report

**Status:** compile/package complete; immutable runtime pending  
**Turn type:** Code + Build only  
**Review policy:** `never`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Scope and result

M1l implements only the bounded consumer seam:

`SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`.

Final implementation: `bd140cff4572412e6f4ecd70a6ce0fe85310932c`.  
Semantic source base: `d5a97953416196a8fc74c8d9790a1ae7b646ca2d`.  
Immediate implementation parent: `2d050cd056edd87103d6bf4f0d7ab7184b143f8f`.  
Entering immutable M1k implementation: `b9181364926cea840e9cb50da21fe721f33fd874`.

The final semantic product/test delta is limited to:

1. `include/directional/geometry/SurfaceCellTracing.h`
2. `src/geometry/SurfaceCellTracing.cpp`
3. `src/pipeline/RemeshPipeline.cpp`
4. `tests/SurfaceCellsPhase10Tests.cpp`
5. `tests/SurfaceCellTransitionQuotientTests.cpp`

No CMake, fixture, validator, benchmark-threshold, fallback/recovery, optimization, or G4 product-policy change was made.

## 2. Implemented contract

`SurfacePhaseFrontCell::sourceTopologyRegion` is now explicitly nullable checked semantic authority:

`std::optional<authority::TopologyRegionId>`.

The migration:

- establishes the checked topology-region ID from existing authoritative `SurfaceTopologyRegion::id` during normalization using the validated topology-region extent;
- removes the raw persistent cell-region mirror;
- requires persistent cell and edge topology-region authority to agree by direct typed equality;
- uses named typed-to-legacy conversion only where still-raw materializer, occurrence, hashing, map-key, or compatibility schemas require the legacy representation;
- preserves topology-region discovery, partition, numbering, `SurfaceTopologyRegion::id`, raw face-to-region maps, certificate/periodic/bounded-disk/occurrence/lineage region schemas, accepted component/sheet and edge-region authority, and existing failure/product behavior;
- keeps missing, stale, or mismatched cell topology-region authority fail-closed through existing authoritative materialization/phase-front failure paths.

## 3. Focused compile contracts

Exactly six production-path contracts were added under `SurfaceCellPhaseFrontCellTopologyRegionAuthorityMigration`:

1. `PlanarCellPublishesCheckedTopologyRegionZero`
2. `DistinctCellTopologyRegionsRemainDistinctFromIsolationSheets`
3. `MissingOrInvalidCellTopologyRegionFailsClosed`
4. `FaceRowPermutationPreservesTypedCellTopologyRegion`
5. `TypedCellAndEdgeTopologyRegionAuthorityAgreeSemantically`
6. `TypedCellTopologyRegionToLegacyMaterializerBoundaryPreservesCompatibility`

These contracts compiled only. They were not discovered, listed, or executed in this turn.

## 4. Compile/package remediation provenance

Two bounded non-semantic failures preceded the final package.

- Run/job `31440241452 / 93623230585` reached producer-test compilation and exposed one existing test assertion that still compared integer zero directly with the newly typed optional cell region. The correction changed only that compatibility assertion to use the existing named legacy helper. No generated Directional binary executed and no stable product regression is assigned.
- Run/job `31440985022 / 93625446238` compiled and linked the corrected implementation **121/121** but package provenance failed afterward because the shallow checkout did not contain semantic base `d5a97953416196a8fc74c8d9790a1ae7b646ca2d` for the retained semantic diff. No result package was declared authoritative. Its log artifact is `9083016010`, SHA-256 `946490f115398519aa2b3e5bcb9955eb12775ea496ca4c426bcf6be06a1c9991`.

The final workflow explicitly fetched the immutable semantic base before producing the retained source diff. These are Code + Build/orchestration defects only; they provide no semantic runtime evidence.

## 5. Authoritative Code + Build evidence

| Evidence | Value |
|---|---|
| implementation | `bd140cff4572412e6f4ecd70a6ce0fe85310932c` |
| semantic source base | `d5a97953416196a8fc74c8d9790a1ae7b646ca2d` |
| immediate implementation parent | `2d050cd056edd87103d6bf4f0d7ab7184b143f8f` |
| build run/job | `31441661026 / 93627457924` |
| configuration | Release / static / Ninja / `PRE_TEST` |
| approved build targets | **121/121** |
| build wall time | **8:38.45** |
| build peak RSS | **1,860,672 KiB** |
| result artifact | `9083262395` — `m1l-cell-topology-region-code-build-result-final` |
| result artifact ZIP SHA-256 | `3d79b86dbda5e87134aef79330d02c227e0c1ba1f291f24bff6a3946c1aa895c` |
| log artifact | `9083262833` — `m1l-cell-topology-region-code-build-logs-authoritative-r3` |
| log artifact ZIP SHA-256 | `a638cf52e9761ddead175aa32aa6824703c98c4553f97c0627e81baa82b3f1b8` |
| recursive manifest | **56/56**, SHA-256 `be8ec12bab5fc7cc76e6a36d2f833c76330593dada820a3b0c72c0e60fff0454` |
| package regular files | **57** including `SHA256SUMS` |
| executables / static libraries | **7 / 2** |
| fixtures / milestone-G fixtures | **27 / 21** |
| producer SHA-256 | `fe7da9a182c785ae14ba24264682470cce7ceec119ce34251a4bee80c7113856` |

The package includes the exact implementation source archive, semantic source diff from the declared base, `compile_commands.json`, recursive submodule status, build/configure logs, command-boundary metadata, focused-test manifests, direct-product names, historical/deferred-red names, fixture inventory, executable/library hashes, and recursive `SHA256SUMS`.

All **56/56** manifest entries verified successfully during packaging.

## 6. Command-boundary compliance

The authoritative package records all of the following as false:

- generated Directional runtime execution;
- GoogleTest discovery/list execution;
- test execution;
- benchmark execution;
- `ctest` execution;
- CLI/GUI/help/version execution;
- fuzzer execution;
- custom-input execution.

`CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST` was configuration only. Compile/package success therefore does **not** semantically accept M1l.

## 7. Regression and product disposition

No stable product regression event or recurrence is assigned from this compile/package-only turn. Historical totals remain **34 regression events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active, and G4 behavior is unchanged.

M1l is **runtime pending**. M1a through M1k remain the current immutable semantic architecture authority.

## 8. Mandatory next turn

Run **M1l Phase-Front Cell Topology-Region Consumer — immutable Artifact-Only Test + Benchmark only** under:

`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

Consume only result/log artifacts `9083262395 / 9083262833` with the exact outer SHA-256 values recorded above. Rebuild, relink, configure, regenerate, edit source/tests/fixtures/build logic, repair/substitute the package, alter executable permissions, or create runtime fixture symlinks are prohibited.

Expected native producer discovery is **226**; M1l focused **6/6** individually; required-green producer **211/211**, plus all entering preservation, representative-product, known-red, and exact postflight gates defined by the plan.
