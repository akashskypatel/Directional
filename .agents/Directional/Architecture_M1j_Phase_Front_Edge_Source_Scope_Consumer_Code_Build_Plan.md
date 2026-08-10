# M1j Phase-Front Edge Source-Scope Consumer — Code + Build Plan

**Turn type:** Code + Build only  
**Review policy:** `never`  
**Accepted baseline:** M1i implementation `b037157921094604f1b0c17f9c8b7076c7604b3b`  
**Prerequisite:** M1i immutable Artifact-Only Test + Benchmark accepted  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Purpose

M1j migrates the next adjacent production owner of source-component/isolation-sheet authority:

`SurfacePhaseFrontCell typed source scope -> SurfaceFrontEdge::{sourceComponent, sourceSheet, sourceIsolationSheets}`.

M1i established checked `SourceComponentId` / `IsolationSheetId` authority on persistent constructive cells. The immediate edge-publication consumer still downgrades that authority to raw integers and later region aggregation overwrites/normalizes the raw edge scope. M1j removes that semantic downgrade while preserving current observable behavior and explicit legacy compatibility only at still-raw downstream boundaries.

This is an architecture migration slice, not G4 behavior repair.

## 2. Accepted entering authority

M1i is immutable accepted under:

`.agents/Directional/Architecture_M1i_Phase_Front_Cell_Source_Scope_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

Accepted runtime authority includes:

- implementation `b037157921094604f1b0c17f9c8b7076c7604b3b`;
- result/log artifacts `9072101943 / 9072102331`;
- producer discovery **208**;
- M1i focused **6/6**;
- required-green producer **193/193**;
- M1h through M1b focused preservation green;
- validation **77/77**, M1a **14/14**, T1 **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean without fixture symlink;
- all eight historical/deferred red classes unchanged;
- strict-validator timing truthfully characterized **0/10 pass, 10/10 fail** as the existing deferred microbenchmark defect;
- Bunny unchanged `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`;
- Vase bounded safety-only at 60 seconds;
- exact immutable postflight preserved all **72/72** package checksums.

Historical regression totals remain **34 events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active.

## 3. Selected source seam

At accepted M1i source:

```cpp
struct SurfacePhaseFrontCell {
  std::optional<authority::SourceComponentId> sourceComponent;
  int sourceTopologyRegion = -1;
  std::optional<authority::IsolationSheetId> sourceSheet;
  std::vector<authority::IsolationSheetId> sourceIsolationSheets;
  // ...
};

struct SurfaceFrontEdge {
  // ...
  int sourceComponent = -1;
  int sourceTopologyRegion = -1;
  int sourceSheet = -1;
  std::vector<int> sourceIsolationSheets;
  // ...
};
```

Edge publication currently performs immediate typed-to-legacy downgrade from the owning cell in multiple construction paths:

```cpp
edge.sourceComponent = legacy_phase_front_source_component(cell);
edge.sourceSheet = legacy_phase_front_source_sheet(cell);
edge.sourceIsolationSheets = legacy_phase_front_isolation_sheets(cell);
```

Later region aggregation then mutates raw edge source scope, including component/sheet normalization. That conflicts with the normative single-writer rule: an aggregator may validate established semantic scope but may not recreate or overwrite it after local production.

## 4. Required implementation

### 4.1 Type only the selected edge-owned domains

Change only these `SurfaceFrontEdge` fields:

```cpp
std::optional<authority::SourceComponentId> sourceComponent;
std::optional<authority::IsolationSheetId> sourceSheet;
std::vector<authority::IsolationSheetId> sourceIsolationSheets;
```

Keep `sourceTopologyRegion` raw in M1j. `TopologyRegionId` is a later bounded M1 consumer and must not be pulled into this slice.

### 4.2 Preserve typed authority at edge publication

Every `SurfaceFrontEdge` created from a `SurfacePhaseFrontCell` must copy the already-established typed component/sheet authority directly:

```text
edge.sourceComponent       <- cell.sourceComponent
edge.sourceSheet           <- cell.sourceSheet
edge.sourceIsolationSheets <- cell.sourceIsolationSheets
```

Do not convert through legacy integers at this semantic boundary.

The typed collection must remain sorted and deduplicated under the same semantic contract as the owning cell. A legitimate multi-sheet edge carries all observed `IsolationSheetId` values and has no representative `sourceSheet`.

### 4.3 Region aggregation validates; it does not rewrite semantic scope

Where topology-region assembly still owns raw `SurfaceTopologyRegion::{sourceComponent,isolationSheets}` compatibility data:

1. cross each raw region component/sheet value through the appropriate checked `LegacyAuthorityAdapters` conversion before semantic comparison;
2. compare the resulting typed values to the edge's established typed scope;
3. reject/fail closed on mismatch, malformed enabled labels, missing authority, unsorted/duplicate/disconnected sheet authority, or invalid representative-sheet semantics;
4. continue assigning `sourceTopologyRegion = region.id` only as the still-raw topology-region representation boundary;
5. do **not** overwrite `edge.sourceComponent`, `edge.sourceSheet`, or `edge.sourceIsolationSheets` merely because a region owns the edge.

For multi-sheet edges, the single-sheet optional must remain empty. Do not synthesize `singleIsolationSheet` as semantic authority.

### 4.4 Explicit compatibility conversion only at raw consumers

Any downstream consumer that still requires the historical raw representation must use named typed-to-legacy conversion helpers at that boundary. Likely sites include:

- pipeline structural hashing where byte-for-byte semantic compatibility of the historical raw integer values is required;
- materialization/validation code that still compares edge scope to raw topology-region or lineage arrays;
- raw grouping keys such as hard-rail compatibility groups, if they remain outside this M1 slice.

Do not reintroduce raw storage merely to simplify those consumers. The conversion must be local, named, and mechanically auditable.

### 4.5 Preserve behavior

M1j must not change:

- source component discovery or numbering;
- isolation-sheet discovery, numbering, connectivity, or normalization rules;
- topology-region construction or numbering;
- field-chart or route transport behavior;
- hard-rail or periodic relation ownership;
- periodic/bounded-disk source-scope schemas;
- G4 completion/singularity behavior;
- fallback/recovery behavior;
- optimization;
- public result success/failure policy;
- fixture discovery or package layout.

## 5. Explicit exclusions

Do **not** migrate in M1j:

- `SurfaceFrontEdge::sourceTopologyRegion` to `TopologyRegionId`;
- `SurfaceTopologyRegion` raw source-scope schema;
- `SurfacePeriodicHolonomy` source component/sheet fields;
- `SurfaceBoundedDiskBoundaryPhase` source component/sheet fields;
- `SurfaceIsolationSeamTransportCertificate` source-scope fields;
- `SurfaceCellRail` component ownership;
- hard-rail IDs, periodic-relation IDs, topology-region IDs, cell IDs, or occurrence IDs;
- M2 closed producer outcomes/single-writer stage snapshots beyond this selected edge owner;
- M3–M6 architecture work;
- G4 behavior remediation.

If implementation pressure requires one of these, stop and record the architectural dependency instead of silently broadening the turn.

## 6. Expected source/test scope

Expected production/test paths are limited to:

1. `include/directional/geometry/SurfaceCellTracing.h`;
2. `src/geometry/SurfaceCellTracing.cpp`;
3. `src/pipeline/RemeshPipeline.cpp`;
4. `tests/SurfaceCellsPhase10Tests.cpp`.

A smaller final diff is preferred. No CMake, fixture, benchmark-data, validator-policy, or unrelated source change is expected.

## 7. Focused semantic contracts to add

Add exactly six production-path tests under suite:

`SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration`

with these contracts:

1. `PlanarEdgesPublishCheckedDefaultComponentAndSheet`
   - a normal planar production path emits edge component/sheet authority as present checked IDs;
   - every edge's typed source scope matches its owning cell.

2. `ExplicitSourceLabelsRemainDistinctTypedEdgeDomains`
   - explicit non-default component/sheet labels survive as distinct semantic types;
   - numeric coincidence between `SourceComponentId` and `IsolationSheetId` cannot substitute one domain for the other.

3. `MultipleObservedSheetsDoNotInventRepresentativeEdgeSheet`
   - an existing reachable reciprocal-isolation production witness produces multi-sheet edge scope;
   - all sheets are retained;
   - `sourceSheet` is empty when more than one sheet participates.

4. `MalformedOrMismatchedEdgeScopeFailsClosed`
   - malformed enabled labels or region-vs-edge semantic mismatch cannot be normalized into apparently valid edge authority;
   - the production path rejects with the existing appropriate typed/fail-closed disposition.

5. `FaceRowPermutationPreservesTypedEdgeSourceScope`
   - equivalent source meshes under face-row permutation produce the same semantic edge component/sheet authority independent of emitted edge positions or cell IDs.

6. `TypedEdgeToLegacyPipelineBoundaryPreservesCompatibility`
   - a downstream raw compatibility observation is derived from typed edge authority through named conversion;
   - historical compatibility values remain unchanged without raw semantic storage on the edge.

Tests must verify intended behavior rather than private layout mechanics. Do not encode the current implementation output as an oracle merely to make the migration green.

## 8. Repeated-pattern controls

### RP-01 — authority-domain conflation

Invariant: edge component and isolation-sheet identity use distinct semantic types. Bare integer equality is never a cross-domain conversion.

Counterexample: use numerically equal component/sheet values and prove domain separation remains explicit.

### RP-02 — test-authority coverage gap

Invariant: focused tests demonstrate the production edge publication path, and later immutable runtime must re-prove complete required-green and representative-product authority.

Counterexample: compile success or direct struct construction alone cannot accept M1j.

### RP-05 — representation-dependent identity

Invariant: semantic source scope is invariant under face-row and edge-emission order.

Counterexample: face-row permutation must not change typed source-scope facts.

### RP-09 — local consumption of global authority

Invariant: region aggregation verifies source scope already established by the producer; it does not replace local semantic authority with a selected raw representative.

Counterexample: a multi-sheet edge cannot be collapsed to one representative sheet merely because the enclosing region has a convenience `singleIsolationSheet` value.

## 9. Code + Build boundary

This turn may edit source/tests and compile/package, but must execute **no** generated Directional binary.

Forbidden execution includes:

- GoogleTest `--gtest_list_tests` or any discovery/list command;
- any test;
- any benchmark;
- `ctest`;
- CLI/GUI/help/version execution;
- fuzzers;
- custom mesh/input execution.

Static source inspection, configuration, compilation, linking, package assembly, metadata generation, hashing, and non-executing binary inspection are allowed.

## 10. Build/package requirements

Build the exact pushed implementation using the established Release/static/Ninja/PRE_TEST package shape and approved target set. Record:

- exact implementation commit and source parent;
- exact final changed source/test paths;
- build run/job IDs;
- target counts and success;
- wall time and peak RSS;
- compiler/CMake/Ninja versions;
- immutable result and log artifact IDs/digests;
- recursive `SHA256SUMS` count/digest;
- package cardinalities;
- producer/test executable hashes;
- source/test blob authority;
- explicit false flags for every generated runtime/test/benchmark/ctest/CLI/fuzzer/custom-input command boundary.

The package must contain the new six test contracts but they remain unexecuted until the following Test + Benchmark turn.

## 11. Expected following runtime authority

If M1j Code + Build succeeds, the next turn is immutable Artifact-Only Test + Benchmark consuming only that exact package.

Expected native producer discovery:

`208 + 6 = 214`.

With the same 15 separately classified exclusions, expected required-green producer selection is:

`214 - 15 = 199`.

The following runtime must require:

- M1j focused **6/6** individually;
- M1i through M1b focused preservation green;
- M1d route witnesses **3/3**;
- M1c transition counterexamples **3/3**;
- required-green producer exactly **199/199**;
- validation **77/77** unless the new M1j tests intentionally belong there instead, in which case discovery authority must be explicitly updated during Code + Build without moving semantic contracts between executables merely to satisfy expected counts;
- M1a **14/14**;
- T1 **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean without fixture symlink;
- all eight historical/deferred red classes unchanged;
- strict-validator 10-process truthful characterization;
- Bunny/Vase bounded comparison if earlier mandatory gates permit continuing;
- exact immutable postflight.

If test placement changes native discovery from the expected producer +6 model, the Code + Build report must explain the ownership choice before runtime. Do not alter filters opportunistically during Test + Benchmark.

## 12. Exit criteria

M1j Code + Build completes only when:

1. the selected edge-owned component/sheet domains are typed;
2. edge publication no longer immediately downgrades typed cell authority;
3. region aggregation verifies rather than overwrites edge semantic source scope;
4. multi-sheet edges retain complete typed sheet authority without representative invention;
5. all still-raw downstream consumers use explicit named compatibility conversion;
6. six focused contracts compile;
7. the intended targets compile/package successfully from the exact pushed implementation;
8. no generated Directional runtime command executed;
9. immutable result/log artifacts and source authority are recorded;
10. the live handoff points to the exact following immutable Test + Benchmark plan and artifacts;
11. PR #8 remains open, draft, and unmerged.

Compile/package success does **not** semantically accept M1j. Runtime acceptance belongs exclusively to the following Test + Benchmark turn.
