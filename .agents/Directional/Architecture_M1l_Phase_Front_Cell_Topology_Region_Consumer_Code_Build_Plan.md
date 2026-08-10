# M1l Phase-Front Cell Topology-Region Consumer — Code + Build Plan

**Turn type:** Code + Build only  
**Review policy:** `never`  
**Prerequisite:** M1k immutable accepted from implementation `b9181364926cea840e9cb50da21fe721f33fd874`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Purpose

Perform the next smallest authority-domain migration exposed by accepted M1k source inspection:

`SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`

M1k accepted checked `TopologyRegionId` authority on persistent `SurfaceFrontEdge`, but `SurfacePhaseFrontCell::sourceTopologyRegion` remains a raw `int`. The materializer therefore still crosses typed edge authority back into a legacy integer to compare it with the raw owning cell, and cell-owned region identity is reused directly as a map key, connectivity input, occurrence compatibility value, and structural-hash input.

M1l migrates **only the persistent cell-owned topology-region identity**. It preserves topology-region discovery, partitioning, deterministic numbering, and all product behavior.

## 2. Entering immutable authority

M1k is immutable accepted from the exact Code + Build package:

| Evidence | Value |
|---|---|
| implementation | `b9181364926cea840e9cb50da21fe721f33fd874` |
| source parent | `38d6fc4c4042c5a0d200abf4e5594dcf325b8383` |
| result artifact | `9079318682` |
| build-log artifact | `9079319269` |
| result ZIP SHA-256 | `90b8deea85c12460ae45b66d0c7aa67fa3771074b60841fd1a0e586b0088869d` |
| recursive manifest | **68/68**, `0b76267ea2e40c5c417c0cade77e0b95d75fe1c27a6a2a94cc283f6c7660583c` |
| authoritative runtime run/job | `31433794426 / 93603203081` |
| runtime evidence/log artifacts | `9080245848 / 9080246452` |

Accepted runtime authority:

- producer discovery **220**;
- M1k focused **6/6** individually;
- M1j through M1b focused preservation green;
- M1d route witnesses **3/3**, M1c transition counterexamples **3/3**;
- required-green producer **205/205**;
- validation **77/77**, M1a **14/14**, T1 **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean;
- all eight historical/deferred red classes unchanged;
- strict-validator timing fresh **10/10** but still classified as the existing nondeterministic sub-millisecond ratio defect;
- Bunny unchanged `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`;
- Vase bounded safety-only at 60 seconds;
- exact immutable postflight preserved.

Historical regression totals remain **34 events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active.

## 3. Selected bounded seam

Accepted source currently contains:

- `SurfaceFrontEdge::sourceTopologyRegion` as `std::optional<authority::TopologyRegionId>`;
- `SurfacePhaseFrontCell::sourceTopologyRegion` as raw `int`;
- `SurfaceTopologyRegion::id` as the established raw region-number compatibility representation;
- `SurfacePhaseFrontResult::sourceTopologyRegionByFace` and `SourceTopologyRegions::regionByFace` as raw compatibility mappings;
- certificate, periodic-holonomy, bounded-disk, occurrence, and lineage topology-region fields still raw.

In `normalize_scope`, cell region identity is currently assigned as `cell.sourceTopologyRegion = region.id`, while the same `region.id` is separately checked into `TopologyRegionId` before edge publication. In `build_authoritative_phase_front_mesh`, typed edge authority is converted back to legacy form to compare against the raw owning cell.

M1l changes only this representation boundary:

1. replace `SurfacePhaseFrontCell::sourceTopologyRegion` with an explicitly nullable checked `authority::TopologyRegionId`;
2. establish the cell's typed region from the already-authoritative `SurfaceTopologyRegion::id` through `LegacyAuthorityAdapters::topology_region(...)` and the validated topology-region extent;
3. preserve the exact existing region partition and deterministic raw numbering;
4. preserve M1i cell component/sheet authority and M1k edge topology-region authority unchanged;
5. compare cell and edge topology-region ownership semantically as `TopologyRegionId` where both are typed;
6. at still-raw materializer/hash/occurrence consumers, use one narrow named typed-to-legacy compatibility helper rather than scattered casts or a duplicate raw cell mirror;
7. fail closed through the existing production/materializer failure path when required cell region identity is absent, stale, out of range, or inconsistent with authoritative region membership;
8. preserve semantic identity under source-face row/container-order permutations.

The checked region conversion must use the existing authoritative region extent. Numeric equality with `IsolationSheetId`, `SourceComponentId`, `FieldChartId`, or an unrelated integer domain is never a conversion.

## 4. Required implementation shape

### 4.1 Cell-owned typed authority

`SurfacePhaseFrontCell` must contain one semantic region field and no duplicate raw mirror:

```cpp
std::optional<authority::TopologyRegionId> sourceTopologyRegion;
```

Nullability is allowed only for legitimate pre-normalization/unassigned construction state. A published authoritative cell must carry present checked region identity.

### 4.2 Normalize once, then validate

`normalize_scope` already owns the authoritative `SurfaceTopologyRegion` being applied to the local result. Check `region.id` into `TopologyRegionId` once for that region and use that semantic ID consistently when normalizing cells and validating edges.

Do not derive a cell region from its source component, isolation sheets, first corner face, edge region, or container position. Those may validate membership but are not substitute authority.

Where both cell and edge region identities are typed, use direct semantic equality. Do not convert either side to an integer merely to compare them.

### 4.3 Still-raw compatibility consumers

Introduce/reuse a narrow helper such as:

`legacy_phase_front_source_topology_region(const SurfacePhaseFrontCell&)`

for consumers that still require raw region numbers. Expected raw compatibility sites include:

- structural hashing;
- `topologyRegionById` lookup;
- isolation-sheet connectivity queries;
- `consumedTopologyRegions` bookkeeping;
- raw `topologyRegionByFace` compatibility comparisons;
- raw `OccurrenceData::topologyRegion` publication.

These are compatibility boundaries only. Do not migrate those schemas in M1l.

## 5. Explicit exclusions

M1l must **not** migrate or redesign:

- `SurfaceTopologyRegion::id`;
- `SourceTopologyRegions::regionByFace`;
- `SurfacePhaseFrontResult::sourceTopologyRegionByFace`;
- `SurfaceIsolationSeamTransportCertificate::sourceTopologyRegion`;
- `SurfacePeriodicHolonomy::sourceTopologyRegion`;
- `SurfaceBoundedDiskBoundaryPhase::sourceTopologyRegion`;
- `OccurrenceData::topologyRegion`, completion lineage region vectors, or public diagnostics region fields;
- topology-region discovery, partitioning, construction, numbering, Euler/boundary computation, or structural-hash policy;
- M1i component/sheet semantics or M1k edge region semantics beyond typed cell-edge agreement;
- source-sheet/topology boundary policy;
- `HardRailId`, `PeriodicRelationId`, `CellId`, `OccurrenceId`, `QuotientClassId`, or other authority domains;
- periodic-holonomy capability, bounded-disk capability, hard features, relief barriers, singularity behavior, or G4 completion behavior;
- fallback/recovery, optimization, M2–M6 work;
- fixtures, validators, benchmark thresholds, strict-validator threshold/retry policy, or historical known-red expectations.

M1l is an authority representation/consumer migration only. It must not make a known-red case green by altering product policy.

## 6. Expected implementation/test files

Expected bounded source/test surface:

- `include/directional/geometry/SurfaceCellTracing.h`;
- `src/geometry/SurfaceCellTracing.cpp`;
- `src/pipeline/RemeshPipeline.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp`;
- `tests/SurfaceCellTransitionQuotientTests.cpp` only for existing direct raw-cell-region assertions/comparisons that must be updated to express the same semantic contract through the typed representation.

Do not modify CMake, fixture lookup, validator logic, benchmark data, or public product policy. If another path is required by a direct compile error caused by the type migration, document the exact dependency and keep the change to compatibility adaptation only.

## 7. Exactly six focused production-path contracts

Add exactly six tests under:

`SurfaceCellPhaseFrontCellTopologyRegionAuthorityMigration`

Required names and intent:

1. `PlanarCellPublishesCheckedTopologyRegionZero`
   - production planar construction publishes a present checked cell `TopologyRegionId` for the established default region;
   - accepted component/sheet authority remains intact.

2. `DistinctCellTopologyRegionsRemainDistinctFromIsolationSheets`
   - exercise a production-reachable multi-region case where region and sheet integers can coincide;
   - prove cell topology-region authority derives from authoritative region membership and cannot be obtained by cross-domain numeric reuse.

3. `MissingOrInvalidCellTopologyRegionFailsClosed`
   - mutate the nearest authoritative materializer input so a required cell region is missing or stale/out of range;
   - require the existing fail-closed cell/side authority disposition rather than fallback or partial materialization.

4. `FaceRowPermutationPreservesTypedCellTopologyRegion`
   - permute equivalent source face rows/container order while preserving geometry and authority;
   - compare semantic cell region ownership using source-attached/cell-semantic matching rather than positional cell IDs.

5. `TypedCellAndEdgeTopologyRegionAuthorityAgreeSemantically`
   - exercise produced cells and their four persistent front sides, including a production-reachable multi-region case;
   - require each edge's checked M1k region to equal its owning cell's checked M1l region directly as `TopologyRegionId`;
   - prove cross-region owners remain distinct without typed-to-legacy round-tripping.

6. `TypedCellTopologyRegionToLegacyMaterializerBoundaryPreservesCompatibility`
   - exercise the real authoritative materializer and structural/hash compatibility path;
   - prove raw region keys/occurrence compatibility values are derived from typed cell authority and existing observable product behavior is unchanged.

These tests must execute real production paths in the following Test + Benchmark turn. Do not test only adapters or private mechanics.

## 8. Existing-test compatibility rule

Existing tests that directly compare raw `SurfacePhaseFrontCell::sourceTopologyRegion` to `int` region IDs may require representation-only updates to compile. Such edits must preserve the same intended behavior and, where possible, strengthen the assertion to semantic `TopologyRegionId` equality plus an explicit named legacy conversion at the compatibility boundary.

Do not weaken or delete existing assertions. Do not reinterpret a compile mismatch as authority to change fixture/product expectations.

## 9. Regression-pattern interlock

Before editing, review `.agents/Directional/Regression_Root_Cause_Tracker.md`, especially `RP-01` through `RP-09`.

M1l directly touches:

- `RP-01` authority-domain conflation;
- `RP-05` representation-dependent identity;
- `RP-09` local/duplicated consumption of global region authority;
- `RP-02 / TA-05` test authority.

Required counterexample thinking:

- topology region and isolation sheet are not interchangeable even when legacy values are equal;
- cell region identity comes from authoritative region membership, not corner/edge/container coincidence;
- missing/stale typed cell region fails closed;
- face-row permutation preserves semantic region ownership;
- typed cell and edge owners agree without integer round-trip;
- still-raw materializer values are derived from typed cell authority only.

The M1k local Cylinder stall and first remote evidence-upload path error are infrastructure observations already classified by immutable M1k evidence; do not create or “fix” product behavior around them.

Compile-only failures are diagnosis, not stable product regressions. Assign no new regression ID unless a previously accepted runtime contract is subsequently shown lost.

## 10. Code + Build execution boundary

This turn may:

- inspect accepted M1k source and authority definitions;
- edit only the bounded M1l source/test surface;
- configure Release/static/Ninja with `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`;
- compile/link the established approved targets;
- package immutable outputs, fixtures, source authority, metadata, and detailed logs.

This turn must **not execute**:

- any generated Directional binary;
- GoogleTest `--gtest_list_tests` or any discovery/list command;
- any test;
- any benchmark;
- `ctest`;
- CLI/GUI/help/version commands;
- fuzzers;
- custom mesh/input execution.

The package must explicitly record every runtime/test/benchmark/discovery/ctest/CLI/fuzzer/custom-input execution flag as false.

## 11. Approved compile targets

Compile/link only:

- `directional_core`;
- `directional_pipeline`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_oracle_tests`;
- `directional_surface_cell_authority_kernel_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_benchmarks`.

Expected configuration: Release, static libraries, Ninja, `PRE_TEST`, no CLI/GUI/Python/tutorial runtime surface.

## 12. Immutable package requirements

Package the exact successfully compiled M1l implementation with:

- seven approved executables;
- `libdirectional_core.a` and `libdirectional_pipeline.a`;
- the exact 27-fixture sibling `test-data/benchmarks/fixtures` layout;
- exact implementation SHA, source parent, and accepted M1k reference;
- source archive/patch sufficient to bind every changed source/test path;
- submodule/toolchain/configuration metadata;
- exact six M1l focused test names plus retained M1k–M1b/M1a/T1 manifests;
- exact four direct-product names and eight historical/deferred-red names;
- runtime command-boundary metadata with every execution flag false;
- executable/library SHA-256 metadata;
- recursive `SHA256SUMS` generated **after every package write**, then verified.

Do not repeat earlier packaging mistakes where manifest closure or evidence retention was incomplete.

## 13. Code + Build acceptance gate

M1l Code + Build is complete only if all hold:

1. implementation diff remains inside the declared cell topology-region seam;
2. `SurfacePhaseFrontCell` carries checked topology-region authority with no duplicate raw mirror;
3. topology-region construction/partition/numbering semantics are unchanged;
4. accepted M1i component/sheet and M1k edge-region authority are not weakened or reconstructed;
5. cell-edge region agreement is a typed semantic comparison where both sides are typed;
6. still-raw cell consumers use one explicit named compatibility conversion;
7. exactly six M1l production-path contracts compile;
8. required compatibility edits to existing tests preserve or strengthen their semantic assertions;
9. all approved targets compile/link successfully;
10. immutable package/checksum closure is complete;
11. every runtime/test/benchmark/discovery/ctest/CLI/fuzzer/custom-input flag is false;
12. no fixture, validator, threshold, or historical known-red expectation is weakened;
13. temporary workflows/triggers/payloads are removed before closeout;
14. PR #8 remains open, draft, and unmerged.

Compile success does **not** accept M1l semantics.

## 14. Mandatory following turn

After successful Code + Build, the next turn is:

**M1l Phase-Front Cell Topology-Region Consumer — immutable Artifact-Only Test + Benchmark only**.

Expected semantic authority after adding exactly six producer contracts:

- producer discovery **226** (`220 + 6`);
- M1l focused **6/6** individually;
- required-green producer **211/211** (`226 - 15`);
- preserve M1k through M1b focused authority, M1d/M1c counterexamples, validation **77/77**, M1a **14/14**, T1 **29/29**, four direct products, all eight historical/deferred red classes, strict timing characterization, bounded Bunny/Vase comparison, and exact immutable postflight.

No runtime semantic acceptance may be claimed in this Code + Build turn.
