# M1g Periodic Holonomy Route Transport Consumer — Code + Build Plan

**Status:** authoritative next turn  
**Turn type:** Code + Build only  
**Review policy:** `never`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Purpose

Migrate the next real cumulative field-transport owner from unrestricted signed quarter-turn accumulation to the already accepted checked route/transport algebra without changing periodic topology discovery, current capability, failure semantics, public compatibility representation, or G4 product behavior.

Selected owner in `src/geometry/SurfaceCellTracing.cpp`:

`periodic canonical face cycle -> ordered source-edge crossings -> totalMatching -> PeriodicHolonomyMismatch`

At accepted M1f implementation `baed0f24831c476f45a1b742c12314e3fb03e10e`, the production owner still performs:

```text
int totalMatching = 0
for crossing in canonical periodic face cycle:
    establish source-edge provenance
    append source route/topology
    read directed matching
    totalMatching += matching
if normalized_branch(totalMatching) != 0:
    reject PeriodicHolonomyMismatch
```

This is the separate periodic whole-cycle transport accumulator deliberately excluded from M1e and M1f.

## 2. Entering immutable authority

M1f is immutable accepted from exact artifact-only validation:

- implementation `baed0f24831c476f45a1b742c12314e3fb03e10e`;
- build run/job `31356131866 / 93356062724`;
- result artifact `9050850344`, SHA-256 `a2ac9f21cae7f3496a9ffd7cade8b550b5c8e1de57c91d693dde5ece4fcd499f`;
- log artifact `9050850513`, SHA-256 `3f5595a14d7c2b8c8931772fbdb770c9bc1944b211710ccc4939f2fc1dd54c99`;
- recursive manifest **59/59**, SHA-256 `3607c79873f45d035e6b1339288ed26582007a9068768da167abc603c376059e`;
- producer discovery **190**;
- M1f **6/6**, M1e **6/6**, M1d **6/6 + 3/3**, M1c **6/6 + 3/3**, M1b **6/6**;
- required-green producer **175/175**;
- validation **77/77**, M1a **14/14**, T1 **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder green and independent-oracle clean;
- Bunny known-red and Vase bounded safety-only preserved;
- no new stable regression event or recurrence.

Authoritative entering report:
`.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

## 3. Architectural boundary

M1g changes only the representation and composition of the complete periodic route's quarter-turn transport.

For each already discovered source-face crossing:

1. keep existing canonical face-cycle discovery and ordering unchanged;
2. keep existing shared source-edge discovery unchanged;
3. keep existing `source_edge_provenance` fail-closed validation;
4. check packed source endpoints through `SourceVertexId` adapters;
5. canonicalize edge topology through `SourceEdgeTopologyKey`;
6. check compact source-edge provenance through `InteriorTransitionId`;
7. convert the directed matching to checked `QuarterTurn` plus zero-shift `GridAutomorphism`;
8. construct one `TransitionStep` per observed crossing;
9. construct the complete periodic `CanonicalRoute` only after every crossing validates;
10. consume `CanonicalRoute::oriented_steps()` and compose transport algebraically in observed face-cycle direction;
11. derive the compatibility quarter-turn only at the existing whole-cycle decision boundary;
12. preserve the existing requirement that normalized whole-cycle rotation must be zero, otherwise return `PeriodicHolonomyMismatch`.

The explicit legacy `edgeTransitions == nullptr` / `edgeMatching` compatibility path must cross the same typed route-composition boundary.

## 4. Critical non-goal: do not implement G4-B003

M1g is **not** authorization to support nonzero periodic Z4 holonomy.

The current product rejects a periodic whole-cycle whose quarter-turn composition is nonzero. That behavior remains mandatory in M1g. `SurfacePeriodicHolonomy::quarterTurnRotation` remains compatibility output under the existing zero-rotation assumption unless a later explicitly authorized product-capability turn changes the design.

Therefore M1g must preserve:

- nonzero whole-cycle rotation -> `PeriodicHolonomyMismatch`;
- `G4-B003` as an unresolved product capability blocker;
- existing torus/periodic known-red dispositions;
- no reinterpretation of a migration pass as periodic-rotation feature completion.

## 5. Behavior that must remain unchanged

Do not change:

- active periodic-face selection;
- dual construction;
- canonical starting face or face-cycle direction selection;
- shared-edge discovery;
- source route and topology ordering;
- hard-feature/source-sheet/component policy;
- `PeriodicHolonomyMismatch` failure category or its caller behavior;
- lattice translation computation;
- periodic cut source-edge/topology construction;
- `SurfacePeriodicHolonomy` public/raw schema;
- route canonicalization performed later for compatibility storage;
- validation or quotient semantics;
- fallback/recovery behavior;
- optimization;
- G4 completion or hard-rail scheduling;
- production `FieldChartId`;
- M2–M6 work.

## 6. Focused contract additions — compile only this turn

Add a minimal focused suite, preferably under `SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration`, that invokes the real production periodic owner rather than a duplicated test-only transport helper.

Provide exactly the contracts necessary to establish:

1. **zero whole-cycle composition through nonzero steps** — an independently authored ordered periodic route whose individual quarter turns are nonzero but compose to identity is accepted through the current periodic transport boundary;
2. **reverse observed cycle is exact inverse** — reversing the same semantic cycle yields inverse per-step transports and the same zero whole-cycle result;
3. **equivalent signed representations normalize semantically** — `+4/-4` equivalent step representations do not change the whole-cycle semantic transport;
4. **independent route topology/compact authority** — route topology and compact transition identity are authored independently of row/index order and remain the same semantic route;
5. **malformed authoritative crossing provenance fails closed** — invalid authoritative transition provenance reaches the existing `PeriodicHolonomyMismatch` failure without legacy/geometric substitution;
6. **legacy matching path uses the same typed algebra** — metadata-absent compatibility input composes through the same semantic route boundary and retains the existing result.

If inspection shows one of these scenarios cannot be reached through the current public/package-visible periodic producer without synthetic fixture manipulation, stop and revise the focused set to the nearest real reachable predecessor boundary. Do not create a test-only production API merely to inspect internal state.

No focused test may be executed in this Code + Build turn.

## 7. Packaging metadata correction

Correct the compile/package metadata generator that currently emits stale nonexistent direct-product test names for MultiFaceSeam and CloseSheets in `metadata/direct-product-test-names.txt`.

The authoritative product selections are the package-visible parameterized tests:

`UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/{Plane,MultiFaceSeam,CloseSheets,Cylinder}`.

This correction is packaging/test-selection metadata only. It must not modify product behavior, tests' semantic assertions, or accepted disposition counts.

## 8. Code + Build boundary

This turn may:

- edit the selected production owner;
- add the narrowly scoped M1g contracts;
- correct the direct-product packaging metadata generator;
- configure a compile-only-safe build;
- compile/link approved targets;
- package immutable binaries, libraries, fixtures, source authority, metadata, logs, and checksums.

This turn may **not execute any generated Directional binary**, including:

- GoogleTest discovery/listing;
- any unit/integration/product test;
- benchmark executable;
- `ctest`;
- CLI/GUI/help/version/smoke command;
- fuzzer;
- custom mesh/input execution.

Use PRE_TEST or equivalent compile-only-safe discovery configuration. The package must record `runtimeExecution=false` and the specific runtime-boundary flags as false.

## 9. Build verification

A successful Code + Build turn must verify without executing generated project binaries:

1. accepted M1f implementation remains an ancestor;
2. product source diff is limited to the selected periodic transport owner plus only required helper placement;
3. test diff is limited to the focused M1g contracts;
4. packaging change is limited to correcting direct-product metadata names;
5. no public compatibility schema changes unless strictly required and separately justified — default expectation is none;
6. static suite accounting proves the intended M1g focused contract count;
7. all required targets compile/link successfully;
8. exact source/blob/submodule/toolchain/configuration authority is packaged;
9. all packaged regular files receive a recursive SHA-256 manifest;
10. result and diagnostic-log artifacts are uploaded separately;
11. detailed activity logs are retained even on failure;
12. no generated project runtime occurred.

If compile failure exposes an implementation mistake, a surgical correction may remain within the same Code + Build turn under the durable workflow policy. Do not broaden ownership or run tests to debug it.

## 10. Regression guardrails

Before editing, review `Regression_Root_Cause_Tracker.md` and specifically avoid the recurring patterns already accepted against M1c–M1f:

- raw/domain identity reuse (`RP-01`);
- ambiguous or positional semantic identity (`RP-05`);
- unrestricted signed quarter-turn accumulation at a route transport owner (`RP-07`);
- implementation-shaped test oracles (`RP-02 / TA-05`);
- fallback substitution after authoritative metadata failure;
- canonical storage order accidentally changing observed traversal direction.

The periodic route is closed; ensure canonical representation does not erase the behaviorally observed face-cycle orientation used to determine per-step inverse transport.

## 11. Explicit stop conditions

Stop rather than broadening the patch if:

- the inspected owner no longer performs the raw cumulative transport described above;
- typed migration requires changing canonical face-cycle discovery or periodic product semantics;
- supporting nonzero Z4 holonomy becomes necessary to make tests pass;
- existing authoritative provenance cannot identify steps without introducing a new product-wide authority source;
- the focused tests require test-only production hooks rather than a reachable production boundary;
- any compile/build correction would modify unrelated architecture or G4 behavior.

## 12. Required closeout

On successful compile/package-only completion:

- produce `.agents/Directional/Architecture_M1g_Periodic_Holonomy_Route_Transport_Consumer_Code_Build_Report.md`;
- update live handoff/TODO/migration/regression records additively or narrowly correctly;
- retain M1f immutable acceptance as entering authority;
- create exactly one next **M1g immutable Test + Benchmark** plan against the exact build artifact;
- keep PR #8 open, draft, and unmerged;
- remove temporary Code + Build workflow/trigger/payload state in workflow-first order;
- make the final repository write exactly one new top-level PR #8 conversation comment.
