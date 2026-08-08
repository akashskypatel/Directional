# Gate 4 Topology-Region Materialization and Regression Corrections — Proposed Code + Build Plan

Status: **`proposed_pending_review` — NOT authoritative**  
Turn type if approved: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**

This proposal exists only for the mandatory design review triggered after two Code + Build iterations without accepted material runtime progress. Do not execute it before review approval/amendment/replacement.

## Evidence controlling the proposal

Validated source: `3ca89ab55efff461b050fb12033174be70e7464f`, exact artifact `9022061741`.

The topology-region architecture is runtime-live and removes the torus's artificial bounded-disk seam failure, but accepted material progress is blocked by:

1. embedded-relief fail-closed regression;
2. close-sheets exact deterministic output-hash regression caused by component-order reversal;
3. torus reaching deeper `InvalidAuthoritativePhaseFrontCell` because materialization still requires one `sourceSheet` per cell;
4. torus regression test over-coupling its seam/topology contract to pre-materialization `hasTraceNetwork` retention.

## Proposed design declaration

```text
Active design gate: G4 topology-distinct completion and singularities
Earliest failing retained contract: embedded relief barriers no longer fail closed because topology-region splitting can make every local producer NotApplicable and permit generic tracing; close-sheets also changes exact component emission order/hash
Earliest active G4 fixture blocker: exact torus constructs/consumes topology regions and internal isolation seams, reaches Produced phase-front authority, then fails phase-front materialization as InvalidAuthoritativePhaseFrontCell because materialization still assumes one local sheet per cell
Missing design contract: producer topology-region continuity and local-isolation provenance have been decoupled in tracing, but authoritative materialization, barrier applicability semantics, and canonical multi-region output ordering have not been migrated to the same authority model
Smallest general implementation change: preserve topology-region tracing, restore embedded-barrier fail-closed applicability, restore canonical source-geometric region ordering, and materialize cells/periodic quotients by topology-region lattice identity while retaining exact per-corner/local-isolation provenance rather than requiring a single cell sourceSheet
Observable material-progress condition: compile-only corrections package cleanly; following artifact-only validation restores relief 17/17 and exact close-sheets hash, preserves all topology-region/polygonal/periodic/direct contracts, and exact torus advances beyond InvalidAuthoritativePhaseFrontCell to direct output or the next truthful deeper invariant without fallback/recovery
Explicitly deferred: sphere until torus direct strict-valid production, generalized unrelated producer replacement unless review chooses it, G5/G6, historical completion/simplification failures, validator-threshold changes, fallback/recovery and unrelated optimization
```

## Proposed correction A — embedded relief authority

The review must decide the exact representation, but the implementation must preserve the established observable contract:

- non-embedded relief remains guidance only;
- embedded relief barriers stop authoritative transport;
- an applicable embedded-barrier failure cannot be converted to `NotApplicable` and then bypassed by generic seeds/traces/proposals.

Two acceptable architectural directions for review:

1. keep embedded barriers as topology-region separators, but make region aggregation fail closed when barrier-induced decomposition leaves unsupported authoritative regions; or
2. treat embedded relief barriers as internal transport barriers within the same source-topology region rather than region-connectivity separators, preserving the prior producer's direct encounter with the barrier.

Do not select between these merely to satisfy one fixture. Use the durable relief and topology-region contracts.

## Proposed correction B — canonical multi-region output order

Artifact `9022061741` emits the same close-sheets geometry as the accepted artifact but reverses component order. The new region worklist sorts by `structuralHash` before canonical source vertices; the prior path sorted by canonical source vertices first.

Proposed smallest correction:

- order producer regions first by canonical source-geometric/topological identity derived from their canonical source vertex/face representation, with structural hash only as a deterministic secondary key;
- never order by raw region ID, source row order, component count, proximity, or fixture identity;
- preserve face-row re-enumeration invariance;
- require exact restoration of close-sheets hash `89b052762f52a5af` unless review independently proves that the accepted hash contract itself is invalid.

## Proposed correction C — topology-region-aware authoritative materialization

Current failure is structural:

- a valid region can span multiple local isolation sheets;
- normalized cells may therefore have `sourceSheet=-1` and a non-empty `sourceIsolationSheets` set;
- `build_authoritative_phase_front_mesh()` rejects `sourceSheet < 0` and keys lattice vertices/periodic quotient state by `(component, sheet, u, v)`.

Proposed materialization contract:

1. cell/materialization scope uses `(sourceComponent, sourceTopologyRegion)` plus integer lattice/periodic authority;
2. periodic relation lookup matches topology-region ownership when present, not a representative single sheet;
3. each corner recovers its actual local isolation label from exact source-face provenance and must belong to the cell/region's allowed isolation set;
4. crossing an internal isolation seam never depends on world-space proximity; same lattice identity can unify only through topology-region/phase/periodic authority and compatible exact source geometry;
5. preserve local-isolation provenance explicitly on emitted vertex/cell lineage. If one output vertex is incident to multiple local isolation labels, augment provenance rather than erasing or choosing one by ID/order;
6. hard-feature and source-boundary region separation prevents materialization across true barriers;
7. all existing periodic artificial-cut non-exterior and strict-validation invariants remain unchanged;
8. one accepted authoritative phase-front cell maps directly to one output quad.

The review must inspect whether `SurfacePoint`, `PureQuadVertexLineage`, or adjacent provenance structures need a first-class isolation-sheet set. Do not silently overload a single `sheet` integer with topology-region identity.

## Proposed correction D — torus regression test scope

The fixture is valid. The test's initial `ASSERT_TRUE(result.surfaceCellContext.hasTraceNetwork)` does not directly test its stated seam/topology purpose and currently aborts before runtime-visible diagnostics can be checked.

If review agrees the assertion is over-coupled:

- assert topology-region/seam authority through the public diagnostics that are guaranteed before materialization failure;
- assert torus does not regress to `InvalidBoundedDiskBoundaryTurn`, `InvalidTopologyRegion`, or `InvalidTopologyRegionTransport` without structural evidence;
- retain direct production-path execution, no injected labels/unions, no predicted output counts;
- separately test intermediate-retention semantics only if `retainIntermediateGeometry` is documented to guarantee context retention on pre-retention materialization failure.

No assertion weakening is authorized: the corrected test must strengthen the intended source-topology/isolation contract while allowing truthful deeper materialization failure.

## Compile-only coverage if approved

In addition to existing new topology-region 9/9 sources, add/strengthen compile-only tests for:

- embedded relief barrier remains terminal and produces no generic seeds/traces after authoritative applicability;
- multiple topology regions retain canonical output ordering independent of face-row enumeration;
- close-sheets exact accepted output identity remains stable;
- a valid periodic topology region crossing an internal isolation seam reaches authoritative materialization without requiring one local `sourceSheet`;
- per-corner local-isolation provenance is preserved through materialization;
- malformed cross-sheet materialization provenance fails typed, never welds by position;
- cylinder periodic materialization remains exact;
- exact torus progresses beyond `InvalidAuthoritativePhaseFrontCell` only if the corrected materializer genuinely consumes topology-region/local-isolation provenance.

## Build-only boundary if approved

Use Release/static/Ninja with GoogleTest discovery `PRE_TEST`. Compile only the established seven targets. Execute no generated Directional binary/test/benchmark/ctest/discovery/CLI/GUI/help/list/custom-input command. Package exact source/blobs/logs/fixtures/checksums with `runtimeExecution=false` and clean temporary workflow state afterward.

## Following artifact-only acceptance if approved

The next Test + Benchmark must require:

- topology-region/isolation structural semantics 9/9 retained;
- polygonal boundary phase 5/5 retained;
- non-torus curved-disk authority retained;
- embedded-relief retained G0-G3 restored to **17/17**;
- G4 periodic relations 5/5 retained;
- exact direct hashes restored/preserved: plane `730caeae49ec872c`, seam `5bdf34d7802e9fb0`, close sheets `89b052762f52a5af`, cylinder `32135be51d7a0a26`;
- close sheets remain two source-disconnected components;
- cylinder retains one relation `r=0`, `t=(32,0)`, route 32, cut 4 and exactly two true exterior loops;
- exact torus in at least three independent processes;
- no fallback/recovery and unchanged strict validators.

Sphere remains deferred until torus direct strict-valid production closes.
