# M5-CP3-CB3 Exact-Span Transport Correction Plan

**Turn:** `M5-CP3-CB3`
**Boundary:** **Code + Build / runtime-free**
**Entering semantic candidate:** source `fc2aa5fa68cac890051614c2104979aef4a60d21`, artifact `10615252806` — **unpromoted**
**Accepted runtime authority:** package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` / selector430 **430/430**
**Owner:** correction frozen by `M5-CP3-TB1-R1-REV`

## 1. Goal

Correct exactly one implementation-authority defect in the CP3 same-region periodic-promotion seam: generator relation transport must come from the exact A3 interval `span` and the existing transition/atlas authority attached to that path, as frozen by `Architecture_M5_Frozen_Definitions.md` §14.3.

The correction must not change the already-reviewed representation rule, production subjects, debt discriminators, tests, fixtures, selector430, CP1/CP2 relation contracts, or the accepted cross-region `HardRail` behavior.

## 2. Review finding that authorizes this turn

Corrected R1 run/job `35548642817 / 106179163233` is mechanically valid but semantic RED: **9/9 mechanism PASS, 0/6 produced PASS, selector430 429/430 PASS**. All six produced-torus identities stop before relation-specific assertions at `PeriodicHolonomyMismatch`; accepted selector ordinal408 receives `Rejected` instead of `Produced` before its evolved final-kind assertions.

Independent source review proves the candidate implementation diverges from frozen §14.3 at relation construction:

- `atlas_rotation_between_faces` scans the whole topology region through `FieldBranchTopology::transports()` and requires one path-independent accumulated rotation for every reached face, returning no value when an alternate regional path composes differently;
- `generator_route_for_span` then takes carrier identities from `GlobalTopologyArc::sourcePath` but gives every route step identity transport except the first, where it injects the separately reconstructed aggregate rotation.

Frozen §14.3 requires one authority chain instead: resolve the exact A3 `span` to the accepted `GlobalTopologyPlan` source path and convert **that exact path** through existing transition/atlas authority into the generator carrier. A region-wide path search or synthesized aggregate transport is not an authorized substitute.

The R1 endpoint diagnostic does not identify which individual `PeriodicHolonomyMismatch` branch fired. CB3 therefore corrects the proved authority mismatch, not a guessed dynamic line.

## 3. Authorized source scope

Semantic mutation is limited to:

- `src/geometry/SurfaceCellTracing.cpp`

No test, fixture, benchmark, selector, frozen definition, public header, CMake/build source, or other product file is authorized to change unless compilation proves a mechanically necessary declaration-only adjustment. If such an adjustment would alter semantics or expand the public contract, **stop** and return to Review rather than widening this turn.

## 4. Required implementation

### 4.1 Remove the whole-region rotation reconstruction from the promotion decision

The promotion path must no longer determine generator rotation by traversing arbitrary alternate routes through all branch transports in a topology region or by requiring a globally path-independent face rotation assignment.

Nontrivial periodic holonomy is the subject being represented; a region-wide consistency search must not erase or reject that information before the selected exact carrier is evaluated.

### 4.2 Convert the exact A3 span path through existing transport authority

For a candidate same-region pair:

1. resolve `sharedBoundaryInterval.span` through the accepted `GlobalTopologyPlan`;
2. require the resulting `GlobalTopologyArc::sourcePath` to be exact and canonical under existing authority;
3. derive the generator `CanonicalRoute` from that ordered path, preserving its exact carrier/orientation identity;
4. obtain each route step's transport from existing transition/atlas authority for that exact step and compose those published transports in route order;
5. do not insert a separately reconstructed aggregate rotation into one arbitrary step.

`FieldBranchTopology::transport`, the already-built transition lookup, or another existing exact transition/atlas product may be used only where the exact path uniquely determines the required directed transport. **If the current A3/path products do not contain enough information to map an exact support step to one unique directed authoritative transport, stop.** Do not infer a route from insertion order, nearest/path search, a global gauge assignment, floating geometry, or a direct-helper relation.

### 4.3 Derive one reciprocal periodic action from the exact route and chart lattice

Use the exact generator-route composed rotation plus the paired edges' authoritative chart/lattice endpoint states to derive one `GridAutomorphism` satisfying both reciprocal endpoint correspondences before publication.

Keep the frozen failure behavior: if the exact route, reciprocal lattice correspondence, owner construction, or relation insertion cannot be proved, fail closed with the existing typed production failure rather than repairing the source authority.

### 4.4 Preserve all surrounding contracts

CB3 must preserve:

- §14.2 same-region promotion preconditions: same source topology region, exact reciprocal A3 intervals, distinct boundary occurrences, canonical reverse routes, matching families, opposing advances;
- cross-region pairs remaining `HardRail`;
- same-region `HardRail` rejection at materialization;
- exact A3 `sharedBoundaryInterval` provenance on promoted `PeriodicCut` edges;
- canonical `PeriodicRelationId` content identity independent of action/value;
- CP2 duplicate/conflicting/nonreciprocal/representation-renumbered checked-factory behavior;
- the nine already-reviewed CP1/CP2 mechanism identities;
- the exact six `M5CP3.Produced...` test bodies and names;
- selector430 bytes/order/hash and its exact first427 prefix;
- row408's committed 18-edge torus subject and evolved final-kind assertions.

## 5. Compile-only verification

This turn is runtime-free. It must not execute a Directional binary, test, benchmark, discovery command, `ctest`, CLI, or generated target.

Before the mandatory compile, statically verify:

- the region-wide `atlas_rotation_between_faces` reconstruction is no longer used by the same-region promotion path;
- generator carrier and transport both derive from the exact `span` source path and existing transition/atlas authority;
- no test/fixture/selector bytes changed;
- selector430 remains LF-only at SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6` and its first427 prefix remains `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- no CP1/CP2 relation owner/value validation was weakened.

Then run the mandatory GitHub compile/package workflow with GMP/GMPXX enabled and `runtimeExecution=false`, compiling the standard package targets including the binaries that own the nine mechanism, six produced, and selector430 identities. Preserve clean source-status and package manifest evidence.

## 6. Falsifiers and stop rules

Stop without semantic repair if any of the following is true:

1. the exact A3 `span` path cannot determine a unique ordered transport route using existing transition/atlas authority;
2. satisfying the route requires new semantic authority, a whole-region reachability/path search, floating geometry, or guessed transport;
3. correction requires changing any `M5CP3.Produced...` body/name, row408 body/name, fixture, selector, frozen definition, or debt discriminator;
4. correction requires weakening CP2 checked relation failures, cross-region `HardRail`, or same-region materializer rejection;
5. compile requires a broader product refactor than the exact relation-construction seam;
6. mandatory GMP compile/package fails after one bounded compile-mechanical correction.

A stop returns to independent Review. It does not authorize a test expectation adjustment.

## 7. Success criterion and next boundary

CB3 succeeds only when the bounded implementation is statically faithful to §§14.2-14.4 and the mandatory GMP compile/package is green with no Directional runtime.

A successful CB3 must route to fresh artifact-only **`M5-CP3-TB1-R2-EXEC`**. That later Test + Benchmark turn must restart at process 1 and execute the unchanged **9 mechanism + 6 produced + selector430 = 445** exact-filter processes, exact-one/zero-skip, benchmark **0**, with immutable pre/postflight. No semantic credit from R1 is reused.

Selector publication remains prohibited. `M5-CP2-TB1-REV-OBS-01` can close only at a later independent pre-publication Review after all proposed publication identities are independently green on one corrected candidate.
