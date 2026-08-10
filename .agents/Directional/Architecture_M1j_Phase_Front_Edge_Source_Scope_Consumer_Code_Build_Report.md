# M1j Phase-Front Edge Source-Scope Consumer — Code + Build Report

**Status:** compile/package complete; immutable runtime pending  
**Turn type:** Code + Build only  
**Review policy:** `never`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Scope

M1j migrates the bounded seam:

`SurfacePhaseFrontCell typed source scope -> SurfaceFrontEdge::{sourceComponent, sourceSheet, sourceIsolationSheets}`

Final implementation: `d5f681173600dc32dc7617de6105d9e584e593be`  
Source parent for the M1j production/test delta: `391271e253557b5c6b267befb3f2f33330c090c9`  
Accepted M1i ancestor: `b037157921094604f1b0c17f9c8b7076c7604b3b`

The final source/test delta remains exactly four paths:

1. `include/directional/geometry/SurfaceCellTracing.h`
2. `src/geometry/SurfaceCellTracing.cpp`
3. `src/pipeline/RemeshPipeline.cpp`
4. `tests/SurfaceCellsPhase10Tests.cpp`

`tests/TestFixturePaths.h` is unchanged.

## 2. Implemented contract

`SurfaceFrontEdge` now owns:

- `std::optional<authority::SourceComponentId> sourceComponent`;
- `std::optional<authority::IsolationSheetId> sourceSheet`;
- `std::vector<authority::IsolationSheetId> sourceIsolationSheets`.

`sourceTopologyRegion` deliberately remains the existing raw integer representation for a later bounded `TopologyRegionId` migration.

Edge publication copies the already-checked cell source scope directly. Region aggregation continues assigning only the still-raw topology-region representation and now validates that every edge retains the typed source component and complete sorted/deduplicated isolation-sheet authority established by its owning cell. A legitimate multi-sheet edge retains all typed sheets and has no invented single-sheet representative.

Still-raw consumers use named compatibility conversion through `LegacyAuthorityAdapters::to_legacy_index`. This includes structural hashing, hard-rail grouping, periodic relation compatibility, and isolation-connectivity checks. The pipeline's cell/edge ownership validation compares typed source scope directly before converting only at legacy boundaries.

M1j does **not** migrate periodic/bounded-disk source-scope schemas, `TopologyRegionId`, hard-rail or periodic owner IDs, M2–M6 architecture, G4 product behavior, fallback/recovery, or optimization.

## 3. Unit-test design changes

Exactly six production-path contracts were added under `SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration`:

1. `PlanarEdgesPublishCheckedDefaultComponentAndSheet`
2. `ExplicitSourceLabelsRemainDistinctTypedEdgeDomains`
3. `MultipleObservedSheetsDoNotInventRepresentativeEdgeSheet`
4. `MalformedOrMismatchedEdgeScopeFailsClosed`
5. `FaceRowPermutationPreservesTypedEdgeSourceScope`
6. `TypedEdgeToLegacyPipelineBoundaryPreservesCompatibility`

The existing M1i cell-to-edge compatibility contract was updated to compare typed cell/edge authority directly and then verify the explicit legacy compatibility representation. These tests **compiled only** in this turn; none were executed or discovered.

## 4. Compile-remediation provenance

The first implementation commit was `274b7ab88b581aa63e2e99c3abca2bc89eb742e2`. Its compile attempt reached the pipeline and exposed one incomplete compatibility conversion at `build_authoritative_phase_front_mesh`: a raw periodic-relation component was still compared directly with the newly typed edge component.

The correction was one compatibility-boundary line:

`relation.sourceComponent != legacy_phase_front_source_component(first)`

No semantic scope was broadened. The corrected implementation is `d5f681173600dc32dc7617de6105d9e584e593be`; corrected pipeline blob `8761e60166f5c1711a4f8ee15f54c864a55497bb`.

This is Code + Build provenance, not a stable product regression: no previously accepted runtime authority was lost and no generated Directional binary had been executed.

Several earlier temporary Actions attempts also failed before authoritative build completion because of workflow/payload orchestration mistakes. They did not execute generated Directional binaries and do not constitute product evidence. The final build below is authoritative.

## 5. Authoritative Code + Build evidence

| Evidence | Value |
|---|---|
| implementation | `d5f681173600dc32dc7617de6105d9e584e593be` |
| source parent | `391271e253557b5c6b267befb3f2f33330c090c9` |
| build run/job | `31422691741 / 93566993166` |
| configuration | Release / static / Ninja / `PRE_TEST` |
| approved build targets | **120/120** |
| build wall time | **8:17.83** |
| build peak RSS | **1,860,968 KiB** |
| result artifact | `9076217893` — `m1j-edge-source-scope-code-build-result-final` |
| result ZIP SHA-256 | `a428735f68793e7f4721094b11400c6b4d1276dbea4e6eeb1496fd0ce13f178c` |
| log artifact | `9076218338` — `m1j-edge-source-scope-code-build-logs-authoritative` |
| log ZIP SHA-256 | `76684f4ac412f4da7fd1ccf3cbee5fddfbb7dd14efd43940c6a7568b3d22d1f9` |
| recursive manifest | **67/67**, SHA-256 `2134a0102a38b75d16c859be8fd862ab037c312609ab9bbae19499c9f875da59` |
| package cardinality | **68** regular files including `SHA256SUMS`; 7 executables; 2 static libraries; 27 fixtures |
| producer SHA-256 | `04d5d4d59c3e7e9d15cc3e57b0887086939735867aeb1a122a4b3b82be826e40` |

The immediately preceding successful 120/120 build run `31421704442` produced artifact `9075863759`, but its manifest was generated before one final package log copy. It is therefore retained only as successful compile provenance and is **not** runtime authority. The authoritative retry above rebuilt the exact same implementation and finalized every package write before computing and verifying the manifest.

## 6. Compiled source/package authority

Packaged source blobs:

- tracing header: `9098daea41e3ca3f75eca4a1683d5c4674c97319`;
- tracing implementation: `5d5404a98caf69abb962d477dde2f0e2b68aebf0`;
- pipeline: `8761e60166f5c1711a4f8ee15f54c864a55497bb`;
- phase-10 tests: `512edcb333f1f9770cc980d335cbb060a24e36dc`;
- fixture paths: `4a981f772ee70780d0011696010a0e1b8bef6972`.

Executable SHA-256 values:

- producer: `04d5d4d59c3e7e9d15cc3e57b0887086939735867aeb1a122a4b3b82be826e40`;
- completion: `3435ec9a3a0879d56db7b422d26a7f8d14f215d6f42d6f59f9e2ec8b808e0ec9`;
- independent oracle: `359d605bee931e488f3aa4031db9741c90f13cff1994883bea5dad8d196f8695`;
- benchmarks: `83b0fe8234c3cff2b521f5280c7093fc020e689cec96d9d5430717d49f2cf310`;
- compiled API: `96cc5a049214f4f93a9e06ed954210c0b8a7f665b8bda7b61cbeec5c1e1d7404`;
- authority kernel: `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`;
- validation: `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`.

Library SHA-256 values:

- `libdirectional_core.a`: `1624010a9856552d79a2fff939631e5e78f8b6d31ff92b1356c0198a0a5f8573`;
- `libdirectional_pipeline.a`: `d082733ead9ec314fcddfb4041a1e6cb35b7fe9ab22f82bdd5e73cb08c2ab5b4`.

Independent local inspection of the downloaded result/log ZIPs verified their outer digests, safe archive paths, **67/67** recursive manifest entries, manifest digest, 68-file closure, 27 fixtures, zero symlinks, exact build-authority metadata, source blobs, executable/library hash metadata, and all runtime flags false. No packaged binary was executed during this inspection.

## 7. Command-boundary compliance

The build authority records all of the following as `false`:

- generated Directional runtime execution;
- test execution;
- benchmark execution;
- `ctest` execution;
- CLI/GUI/help/version execution;
- fuzzer execution;
- custom-input execution.

GoogleTest native discovery/listing was also not run. `PRE_TEST` was configuration only.

## 8. Regression disposition

Compile/package success does not establish M1j semantic acceptance. No stable product regression event or recurrence is assigned from this compile-only evidence. Historical totals remain **34 regression events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active, and G4 is unchanged.

The initial compile mismatch and the earlier incomplete package manifest are recorded as Code + Build/orchestration defects. They did not alter accepted M1i runtime authority and were corrected before declaring this turn complete.

## 9. Next turn

Run **M1j Phase-Front Edge Source-Scope Consumer — immutable Artifact-Only Test + Benchmark only** under:

`.agents/Directional/Architecture_M1j_Phase_Front_Edge_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Plan.md`

Consume **only** artifacts `9076217893 / 9076218338`. Rebuild, relink, configure, regeneration, source/test/build/fixture edits, package repair/substitution, and runtime fixture symlinks are prohibited.

Expected native producer discovery is **214**; M1j focused **6/6**; required-green producer **199/199**, with all entering preservation gates and exact immutable postflight.
