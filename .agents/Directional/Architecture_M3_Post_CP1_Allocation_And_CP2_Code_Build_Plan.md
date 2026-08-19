# Architecture M3 — Post-CP1 Allocation Amendment and CP2 Code + Build Plan

Date: 2026-08-19 UTC  
Planning turn: `M3-POST-CP1-ALLOC-REPLAN`  
Turn type: **Review / planning only**  
Disposition: **CP2 Code + Build complete; package 9 compile/package green on `6b046e0ba924a8d9f2aee158c64fd7734ab9a3ff / 9375452692`; exact next immutable `M3-CP2-TB`; CP2 not yet accepted**
Runtime/build boundary for this planning turn: **no product/test/fixture/build semantic edit, no compile, no package, no generated Directional runtime**

This file is the authoritative post-CP1 amendment to
`Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md`. It supersedes that
plan's stale status and package-allocation text after CP1 and the M3-specific stale package
ceiling/status text in `REORIENTATION_PLAN.md`; all other durable `REORIENTATION_PLAN.md`
architecture, sequencing, blocker, and obligation content remains authoritative. It preserves
the M3 acceptance contract and semantic decomposition and does **not** amend `DESIGN.md`.
Historical filenames for retired CP0/CP1 per-turn plans/reports that remain inside the older
base plan are provenance only; their necessary current-head facts are preserved in
`CHANGELOG.md`, `Regression_Root_Cause_Tracker.md`, the accepted CP1 immutable report, this
plan, `TODO.md`, and the handoff.

## 1. Entering accepted authority

M3 CP1 is accepted on exact semantic source/package
`9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046`, by immutable
`M3-CP1-TB-R3` `32263614534 / 96102598799` at **281/281**:

- A1 `FieldTransportAtlas` contracts: **6/6**;
- retained M2: **275/275**;
- retained M1 producer: **138/138**;
- failed identities: **0**;
- package and materialized packaged source: byte-identical before/after runtime;
- no rebuild, relink, package repair, source/test/fixture mutation, generated discovery,
  or benchmark execution.

`PR8-R038 / M3-CP1-R001` is **RESOLVED STABLE / RECURRENCE** and
`M3-CP1-TB-CAND-01` is **RESOLVED NON-STABLE**. This planning turn observes no new runtime,
so historical totals remain **38 events / 14 categories / 24 recurrences** and
produced-witness debt remains **5**.

Before this allocation review, cumulative M3 consumption is **8/11** and four Code + Build
checkpoints remain: CP2, CP3a, CP3b, CP4.

## 2. Allocation review

### 2.1 The four remaining checkpoints are four semantic domains

The CP0 census and the normative M3 contract distinguish the remaining work:

1. **CP2 / A2a ownership skeleton** — typed singularity ports plus mandatory boundary and
   hard-feature graph ownership, publishing the closed `FieldAlignedCurveNetwork` skeleton.
2. **CP3a / combinatorial tracing** — branch-consistent trace construction into candidate
   segments, with no contact graph.
3. **CP3b / contact/event composition** — first-contact/intersection/termination incidence
   plus the independent trace/event composition proof.
4. **CP4 / A2b topology plan** — selected network faces and `GlobalTopologyPlan` regions,
   mandatory-topology preservation, and final disc certificates.

CP0 explicitly classified CP3a and CP3b as independently testable domains. M1/M2 cost
calibration established the standing rule that package cost tracks independent semantic
domains, not file count. Combining independently testable domains to satisfy an accounting
ceiling would repeat the package-sizing failure pattern the architecture review is meant to
prevent.

### 2.2 Rejected reconciliations

The review rejects these alternatives:

- **Merge CP3a + CP3b:** rejected because CP0 explicitly separated them and CP3b-TB owns an
  independent composition proof that cannot be reduced to CP3a's trace-construction gate.
- **Fold CP4 into M4:** rejected because `DESIGN.md` A2b and M3 acceptance criterion 6 require
  `GlobalTopologyPlan` and disc proof before M3 closes. M4 begins only after A2b and owns the
  positive conformity schedule, not topology-plan construction.
- **Omit a TB or create an M3 partial-CB chain:** rejected because no M3 partial-CB cadence
  exception is authorized. A compile-green partial is not semantic acceptance.
- **Replace CP4-TB with an extra M3-FULL package:** rejected because it does not solve the
  package conflict and `M3-FULL` is intentionally omitted unless separately justified.

### 2.3 Minimal sound amendment

The hard cumulative M3 ceiling is amended **11 -> 12**. This is the smallest change that
preserves the already-reviewed semantic decomposition and normal Code + Build -> immutable
Test + Benchmark cadence.

Allocation is now fixed:

| Cumulative M3 package | Checkpoint | Local cap |
|---:|---|---:|
| 1-8 | CP0 + CP1 history | consumed |
| 9 | `M3-CP2-CB` | 1 |
| 10 | `M3-CP3a-CB` | 1 |
| 11 | `M3-CP3b-CB` | 1 |
| 12 | `M3-CP4-CB` | 1 |

There is **no retry reserve**. A red immutable TB at any remaining checkpoint stops for
Review. Another package requires an explicit later plan/authorization and a new cumulative
ceiling amendment; there is no automatic package 13. `M3-FULL` remains omitted.

`M3-CP4-TB` is the cumulative M3 exit gate: it must prove all ten M3 acceptance criteria on
one immutable package, including all accepted CP1/CP2/CP3 contracts and the retained M2
predecessor. No separate M3-FULL package is required merely to repeat the same semantics.

## 3. CP2 source audit — current authority seam

The accepted CP1 source already exposes typed A1 facts, but the production tracing seam
immediately projects one of those facts back into raw values:

- `FieldTransportAtlas::singularities()` publishes `FieldSingularityId`, `SourceVertexId`,
  component, exact integer index numerator, topology region, and local cycle binding.
- `RemeshPipeline.cpp` copies those accepted facts into
  `SurfaceCellTracingOptions::singularityVertices` and
  `singularityIndexNumerators` as bare integers before calling
  `build_surface_cell_network(...)`.
- `SurfaceCellTracing.cpp` then uses those raw vectors for seed creation, singularity-hit
  termination, phase-front applicability, and one-ring separatrix enumeration.
- authoritative boundary/hard-feature rails already carry typed `HardRailId`, but their
  mandatory graph ownership is not closed into an immutable A2a product.
- current `SurfaceCellNetwork` is a mutable legacy aggregate. It is not the normative
  `FieldAlignedCurveNetwork` because it lacks typed nodes, singularity-port ownership, and a
  closed mandatory-edge graph.

This is the exact CP2 seam. CP2 removes the production raw-singularity projection as semantic
authority and publishes one typed A2a skeleton. It does **not** change the tracing-order
algorithm, contact semantics, or topology selection.

## 4. Exact CP2 semantic contract

### 4.1 Strong domains

Extend `AuthorityIds.h` with distinct checked semantic IDs for the A2a boundary:

- `NetworkNodeId`;
- `NetworkEdgeId`;
- `SingularityPortId`;
- `TraceId` reserved for the CP3a product surface.

The existing `FieldSingularityId`, `SourceVertexId`, `SourceComponentId`,
`TopologyRegionId`, `HardRailId`, and `SourceEdgeTopologyKey` remain the owners they already
are. Do not introduce a bare integer as the public replacement for any of these domains.

`TraceId` may be introduced now as the declared A2a domain but CP2 must publish no candidate
trace merely to populate it; CP3a owns trace construction.

### 4.2 Immutable `FieldAlignedCurveNetwork` skeleton

Define the CP2 product in the existing surface-tracing module rather than opening a new
module split. M8 owns module-boundary hardening; a new header/source pair is unnecessary for
this checkpoint and would increase mechanical surface without adding authority.

The immutable checked product must expose at minimum:

- canonical network nodes for every source vertex participating in a required singularity
  port or mandatory boundary/hard-feature edge;
- typed singularity ports, each with `SingularityPortId`, owner `FieldSingularityId`, owner
  node, exact source vertex/component/region binding, and deterministic port ordinal stored
  only as representation data;
- exactly `4 - indexNumerator` ports for each accepted A1 singularity, preserving the current
  supported valence precondition used by the production tracer rather than silently widening
  the tracing algorithm in CP2;
- typed mandatory graph edges, each with `NetworkEdgeId`, `HardRailId`, exact
  `SourceEdgeTopologyKey`, boundary/hard-feature kind, endpoint `NetworkNodeId`s, and the
  source region/component ownership derived from checked A0/A1 authority rather than raw rail
  component integers;
- source/A1 binding sufficient to reject a network built from foreign source/topology/atlas
  authority;
- a stable semantic digest whose equality/order is independent of source-face row order,
  rail container order, and numeric coincidence of unrelated typed IDs.

Construction is the only writer. Published node/port/edge storage is immutable to consumers.
The skeleton contains **no candidate traces, contact nodes, intersections, terminal events,
selected topology regions, side counts, or breakpoint schedules**.

### 4.3 Mandatory-edge closure

The checked factory consumes the accepted `FieldTransportAtlas`, the same
`SourceTopologyRegions`, and the already-produced authoritative `SurfaceCellRail` set.
For every source edge classified by A1 as `SourceBoundary` or `HardFeature`, CP2 must establish
exactly one compatible mandatory graph-edge owner. It must reject missing, duplicate,
foreign, or kind-inconsistent rail support. `SurfaceCellRail::component` is a legacy
projection and may not establish the typed component owner.

The rail's geometric samples remain the existing geometry payload used by the legacy tracer;
CP2 does not duplicate them into a new semantic owner. The new network product owns whether
an edge is mandatory and who owns it. Geometry consumers may use the existing rail samples
only after validating that they correspond to the typed mandatory edge/rail authority.

### 4.4 Production cutover without CP3 work

Add `const FieldAlignedCurveNetwork *fieldAlignedNetwork` to the production tracing options.
When non-null:

- singularity seed/hit/applicability/separatrix code obtains singularity membership/index/port
  ownership from the typed network product;
- the raw `singularityVertices` / `singularityIndexNumerators` vectors are not populated by
  the production pipeline and cannot override the typed product;
- authoritative rail geometry is accepted only after its mandatory source-edge/rail identity
  matches the network product;
- the existing branch walking, one-ring ray construction, phase-front logic, capture rules,
  and contact behavior otherwise remain unchanged.

The raw vectors may remain as an explicitly legacy/focused-test ingress when
`fieldAlignedNetwork == nullptr`; the production `SurfaceCells` path must have no caller that
reconstructs A2a singularity authority from them.

Publish the CP2 product in `SurfaceCellComponentStageProducts` as semantic stage authority and,
if diagnostic retention requires it, copy it one-way into
`SurfaceCellDiagnosticProductSnapshots`. No production consumer may read the diagnostic copy
back as authority.

## 5. Frozen CP2 change surface

CP2 is bounded to these eight semantic/test/build files:

1. `include/directional/authority/AuthorityIds.h`
2. `include/directional/geometry/SurfaceCellTracing.h`
3. `src/geometry/SurfaceCellTracing.cpp`
4. `include/directional/pipeline/RemeshPipeline.h`
5. `src/pipeline/RemeshPipeline.cpp`
6. `cmake/DirectionalTests.cmake`
7. `tests/FieldAlignedCurveNetworkTests.cpp` — new
8. `tests/SurfaceCellREPackageTests.cpp`

No new production source file is planned, so `CMakeLists.txt` requires no semantic edit.
If implementation proves that another product/source/test/build file is semantically required,
stop for Review before editing it. Do not silently enlarge CP2 into CP3 or refactor unrelated
tracing code.

## 6. Frozen CP2 contracts

Add exactly six CP2 required identities:

1. `FieldAlignedCurveNetwork.PublishesTypedSingularityPortsAndMandatoryGraph`
2. `FieldAlignedCurveNetwork.RejectsInvalidSingularityPortOwnershipOrCount`
3. `FieldAlignedCurveNetwork.RejectsMissingDuplicateOrForeignMandatoryEdges`
4. `FieldAlignedCurveNetwork.PreservesBoundaryAndHardFeatureOwnersWithoutNumericAlias`
5. `FieldAlignedCurveNetwork.IsInvariantToRailAndSourceFaceOrdering`
6. `SurfaceCellFieldAlignedNetworkAuthority.ProductionConsumesTypedSkeletonWithoutRawSingularityProjection`

The first five belong to the new `tests/FieldAlignedCurveNetworkTests.cpp`, registered in the
default `directional_surface_cell_producer_tests` owner because A2a is a production stage
product rather than an A1 value-algebra contract. The sixth belongs to
`tests/SurfaceCellREPackageTests.cpp` and must reach the actual `SurfaceCells` production
path.

Every negative must first prove its unmodified baseline and then prove the intended mutation
reached the intended checked-factory/production seam. No assertion may accept a different
earlier guard merely because the call failed.

The CP2 immutable selector is the accepted CP1 **281** identities plus these six unique CP2
identities, for a cumulative required-green target of **287/287**. Do not mechanically add
other changed-block tests. Any additional candidate stays non-gating until an accepted-
predecessor differential and its precondition justify promotion.

## 7. CP2 Code + Build execution contract

`M3-CP2-CB` is one Code + Build package at most.

1. **Enumerate before editing.** Freeze the complete site set for:
   `singularityVertices`, `singularityIndexNumerators`, `SurfaceSingularitySeparatrix`,
   `SurfaceCellRail` mandatory-edge ingress, `SurfaceCellNetwork` publication, and stage-product
   copies/consumers. Classify every site as production semantic consumer, legacy/test seam,
   diagnostic leaf, or deferred CP3+ surface. The production requiring-change set must be
   complete before mutation.
2. Make only the eight-file bounded delta above.
3. Audit the source delta against this plan: no tracing-order/contact/topology-plan/M4 work,
   no raw A2a production fallback, no second semantic writer, no weakened retained assertion.
4. Commit one exact semantic source SHA `S`.
5. Run a **separate external pre-package compile** on literal `S`, using the durable reusable
   compile workflow/cache and `runtimeExecution=false`. It must compile at least
   `directional_surface_cell_producer_tests` and the directly affected core/pipeline ownership
   closure. This compile is mechanics evidence and consumes **no package**.
6. If pre-package compile is red, stop for Review/repair within Code + Build mechanics; do not
   create package 9. Any semantic source change invalidates the previous preflight and requires
   a new preflight on the new exact SHA.
7. After green preflight, re-audit the exact source delta/site-set closure and confirm no
   semantic change occurred after preflight.
8. Consume cumulative M3 package **9** by compiling the full approved M3 owner closure on the
   identical `S`, with `runtimeExecution=false`, packaging every executable needed by the
   frozen 287-identity immutable gate plus source/dependency/status/manifest evidence.
9. No generated Directional binary, unit test, benchmark, discovery/listing command, `ctest`,
   CLI/GUI, fuzzer, help/version command, or custom mesh input may execute in Code + Build.
10. Compile/package green does not accept CP2. It advances only to immutable `M3-CP2-TB`.

## 8. Planned immutable `M3-CP2-TB`

The Test + Benchmark successor consumes the exact package-9 artifact without repository
source substitution, rebuild, relink, repair, or source/test/fixture mutation. It must:

- verify package/source/dependency/manifest integrity and the Code + Build runtime boundary;
- reconcile the frozen accepted CP1 selector at **281** identities and the six exact CP2
  identities without generated discovery;
- run CP2 **6/6** and retained accepted CP1 **281/281**, total **287/287**;
- prove the new production-path contract actually reached typed skeleton construction and did
  not pass through raw singularity projection;
- leave package and materialized source byte-identical after runtime;
- classify every observed red/candidate in `Regression_Root_Cause_Tracker.md` before closeout.

Any red stops for Review. There is no automatic CP2 package retry and no package 13.
A green immutable CP2 gate advances to `M3-CP3a-CB`, cumulative package slot 10.

## 9. Success and stop conditions

CP2 succeeds only when one immutable package proves typed port completeness and mandatory
boundary/feature graph ownership while all accepted CP1/M2 behavior remains green. CP2 must
not claim branch-consistent tracing, contact correctness, topology-plan derivation, or M4
conformity.

Stop and replan if CP2 would require any of the following:

- a second semantic owner for A1 singularity/index or mandatory-edge identity;
- use of raw rail component/order values to establish typed ownership;
- nearest-direction branch switching, trace-order policy, or contact/intersection semantics;
- topology-region selection/disc proof or positive rail scheduling;
- weakening A1, predecessor, or CP2 negative assertions;
- a ninth semantic/test/build file outside the frozen surface;
- any package attempt before a green exact-source external pre-package compile.

Exact successor after this planning turn is **`M3-CP2-CB`**. CP3a, CP3b, and CP4 remain
blocked on accepted predecessor checkpoints.

## 9. CP2 Code + Build execution result

`M3-CP2-CB` completed on `6b046e0ba924a8d9f2aee158c64fd7734ab9a3ff`. Mandatory pre-package `32279124852 / 96153441513` was green on the literal SHA with `runtimeExecution=false`; package 9 `32279806492 / 96155630834` then compiled/packaged the identical source as `9375452692`. M3 is **9/12**. Compile/package green does not accept CP2; exact successor is immutable `M3-CP2-TB` at **287/287**, and package 10 / CP3a remains blocked. Exact evidence is in `Architecture_M3_CP2_Code_Build_Report.md`.
