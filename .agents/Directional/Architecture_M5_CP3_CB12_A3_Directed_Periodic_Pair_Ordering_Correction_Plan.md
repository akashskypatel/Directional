# M5-CP3-CB12 A3-Directed Periodic Pair Ordering Correction Plan

**Turn:** `M5-CP3-CB12`
**Type:** **Code + Build / product-only / runtime-free**
**Owner:** `M5-CP3-TB1-R10-REV-CAND-01`
**Exact semantic source scope:** `src/geometry/SurfaceCellTracing.cpp` only
**If compile green:** `M5-CP3-TB1-R11-EXEC` -> mandatory `M5-CP3-TB1-R11-REV`

## 1. Goal

R10 Review proves that CB11 removed the old same-region raw `family`/`advanceSign` pre-veto and preserved existing `R=0` behavior, but production still chooses the **directed** same-region generator/action orientation from `hardRailGroups` vector insertion order:

```text
pair[0] -> pair[1]
```

That violates frozen M5 §14.3's prohibition on edge/group/vector ordinal or insertion-order relation synthesis and §16's requirement that `R` be taken in the exact directed A3/source-path orientation.

CB12 makes one bounded product correction: **a same-region periodic pair is semantically oriented by its exact reciprocal A3 interval orientation before any directed generator route or periodic action is derived.** The required direction is the accepted A3 **Forward occurrence/edge -> Reverse occurrence/edge** direction already used by the independent produced-witness oracle.

## 2. Authorized semantic scope

Only:

```text
src/geometry/SurfaceCellTracing.cpp
```

may change semantically.

No semantic change is authorized to:

- public headers/API;
- `tests/**` or any committed fixture;
- selector430, selector manifest, routing artifact/identity map;
- CMake/build ownership or benchmark source;
- `FieldTransportAtlas`, `GlobalTopologyPlan`, accepted A3 cut construction, source-face ownership or hard-feature traversability;
- `PeriodicRelationId`, `SurfacePeriodicHolonomy`, materializer/verifier/certificate semantics;
- M6 authority;
- frozen §§14–16.

The existing row4/5 source/A3 direction oracle is already the independent falsifier. Do not rewrite the test to fit the correction.

## 3. Exact correction

### 3.1 Preserve grouping and reciprocal provenance

Keep the current `HardRailPairKey` and all fail-closed pairing requirements:

- exactly two members per group;
- exact same span/ordinal interval with reciprocal ordinals;
- opposite `SurfaceSharedBoundaryInterval::orientation`;
- exact distinct `boundaryOccurrence` values for same-region promotion;
- canonical-reverse edge routes;
- optional `railId` compatibility;
- same-region/cross-region classification from exact `sourceTopologyRegion`.

Do not broaden grouping, introduce floating matching, derive identity from edge indices, or use a search/fallback.

### 3.2 Cross-region behavior is byte/semantically unchanged

For `first.sourceTopologyRegion != second.sourceTopologyRegion`:

- retain direct local `family` equality and opposing `advanceSign`;
- remain `HardRail`;
- publish no periodic relation;
- preserve the current pair/opposite-edge/event behavior.

CB12 is not authorized to reinterpret cross-region ordering.

### 3.3 Semantically orient only the same-region periodic relation construction

After reciprocal structural checks succeed and **only for a same-region pair**:

1. inspect the two already-validated `sharedBoundaryInterval->orientation` values;
2. require exactly one `authority::Orientation::Forward` and one `authority::Orientation::Reverse` member; if that invariant is not true, fail closed through the existing invalid-pairing path — do not choose by index;
3. bind semantic references/pointers such that:

   ```text
   directedFirst  = edge whose interval orientation is Forward
   directedSecond = edge whose interval orientation is Reverse
   ```

4. call the existing `generator_route_for_span(...)` exactly once using:

   ```text
   span,
   directedFirst.boundaryOccurrence,
   directedSecond.boundaryOccurrence
   ```

5. take exactly that route's `composed_transport().rotation`;
6. call existing `periodic_action_for_pair(directedFirst, directedSecond, generatorRotation)` exactly once;
7. pass the same directed generator route/action and the corresponding directed cut carrier into checked `SurfacePeriodicHolonomy::make(...)`;
8. retain existing canonical relation insertion and reciprocal owner publication for both physical edges.

The semantic relation direction must be independent of whether the Forward edge happened to be `pair[0]` or `pair[1]`.

### 3.4 Direction prohibitions

The correction must **not**:

- try `pair[0] -> pair[1]` and then `pair[1] -> pair[0]` until one succeeds;
- try `generatorRotation.inverse()` or any second rotation;
- select whichever of forward/inverse makes endpoint correspondence pass;
- search A3 boundary occurrences;
- choose direction from `sourceEdgeFaces[edge][0/1]`, edge index, filled-cell/side ordering, route lexical order, `HardRailId`, relation ID, translation sign/rank or canonicalized relation output;
- alter lattice endpoints, branch rotations or chart state;
- fit/adjust translation;
- weaken either exact branch-state equation or either exact integer endpoint mapping.

One exact A3 semantic direction produces one exact transition rotation and one action candidate.

## 4. Static pre-compile falsifiers

Before triggering compilation, source review must prove all of the following on the exact semantic source:

1. `hardRailGroups` may still store representation indices, but no same-region generator/action direction is selected from vector position;
2. same-region relation construction explicitly identifies one Forward and one Reverse interval and uses Forward -> Reverse;
3. swapping the two local group members cannot change which occurrence is passed as generator `from` vs `to`;
4. cross-region raw family/sign semantics remain unchanged;
5. `generator_route_for_span(...)` remains the single exact GlobalTopologyPlan/A3/atlas path and is not given inverse fallback;
6. `periodic_action_for_pair(...)` remains unchanged in semantic checks: both branch rotations, one integer shift, both endpoint applications;
7. `SurfacePeriodicHolonomy::make(...)`, insertion/canonicalization and typed error mapping remain unchanged except for receiving semantically directed inputs;
8. no test, fixture, selector, routing, header, build or benchmark semantic bytes change.

**Stop rule:** if the correction requires changing row4/5 test expectations, accepting either direction as equivalent, changing relation canonicalization/identity, modifying atlas/A3 authority, or touching another product domain, stop and return to Review. Do not expand CB12.

## 5. Compile/package requirements

Use the mandatory GitHub reusable compile path; do not compile locally for acceptance and do not execute generated Directional runtime.

Compile/package all eight standard targets with GMP/GMPXX:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Require:

- exact semantic source SHA;
- clean source status around configure/build;
- `DIRECTIONAL_ENABLE_GMP=ON` and explicit GMPXX + GMP link evidence;
- compile/preflight exit 0;
- complete mode-preserving candidate package and root self-manifest;
- `runtimeExecution=false`.

No `ctest`, gtest execution, benchmark, generated discovery/listing, CLI/help/version command or any other Directional runtime is allowed in CB12.

## 6. R11 immutable Test + Benchmark plan requirements if compile green

CB12 closeout must author/freeze `M5-CP3-TB1-R11-EXEC` against the exact compile-green candidate. R11 reuses the unchanged **446** fresh exact-filter identities:

- 9 reviewed mechanism identities;
- 1 focused atlas identity;
- 6 produced torus identities;
- all 430 selector430 identities in exact accepted order;
- benchmark executions exactly **0**.

Require exact-one selection, zero skips, mode-preserving extraction and exact immutable pre/postflight. No configure, compile, relink, generated discovery, package repair, mode repair or source/test/fixture/selector mutation may occur.

### 6.1 Result evidence finalization is corrected before runtime is authorized

The R11 caller/driver must use the established R9 finalization shape:

1. produce runtime evidence;
2. copy `driver-authority.txt` into the result directory;
3. **then regenerate** the self-excluding result `SHA256SUMS` over every other evidence file;
4. run `sha256sum -c SHA256SUMS`;
5. independently verify manifest row count equals the number of non-manifest files before upload;
6. fail closed on any mismatch.

Do not repair the R10 artifact. This rule applies only to the fresh R11 result. If the evidence shape remains unchanged, expected coverage is **912/912** non-manifest files.

### 6.2 Load-bearing semantic falsifiers

A recovery candidate requires:

- produced rows **1/2/3/6 PASS**, preserving the R=0 behavior and already-discharged debts;
- row4 advances through `require_produced(...)` into `select_torus_source_witness(...)`;
- row4 independently confirms the selected A3 **Forward -> Reverse** `generatorRoute` equals the published relation route, and `sourceRotation == relation.action().rotation`; inverse direction is not accepted as a substitute for that comparator;
- row4 proves genuinely nonzero Z4 rotation **and** nonzero translation, successful materialization, a selected certificate consuming the relation/action, and `consumedPeriodicHolonomies > 0`;
- row5 selects that same source/A3-directed relation, changes only the action rotation while keeping semantic relation identity/carriers fixed, and rejects exactly `NonReciprocalPeriodicRelation`;
- mechanism **9/9**, focused atlas **1/1**, produced **6/6**, selector430 **430/430**;
- protected selector ordinals 191/192/247/408 PASS;
- all **446/446** exact-one / zero-skip;
- exact immutable postflight and complete result self-manifest.

Any mechanically complete R11, green or RED, routes to mandatory `M5-CP3-TB1-R11-REV`. EXEC may not promote the package, discharge debt, close the R6 direction observation, or precommit selector publication.

## 7. Accounting and authority entering CB12

Accepted runtime authority remains package/source `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**.

Candidate `10678487447` / source `53a21f550cf67e643e8c67a633bb63a20b055c6a` remains unpromoted historical R10 evidence.

Stable accounting remains **50 events / 14 categories / 36 recurrences**. Project produced-witness debt remains **3**:

- M5 `FullPeriodicRotationAndTranslationMaterialize` — OPEN;
- M5 `TamperedFullPeriodicTransformIsRejected` — OPEN;
- M6 closed-complex produced witness — OPEN.

`M5-CP3-TB1-R10-REV-CAND-01` is OPEN / `RP-01 AUTHORITY_DOMAIN_CONFLATION` / non-stable / owner CB12 -> R11 Review. `M5-CP3-TB1-R6-REV-OBS-01` remains OPEN and is specifically owned by R11 Review. `M5-CP2-TB1-REV-OBS-01` remains OPEN. Selector publication is prohibited throughout CB12/R11 EXEC.
