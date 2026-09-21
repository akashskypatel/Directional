# M5-CP3-CB4 Hard-Feature Transition Transport Correction Plan

**Turn:** `M5-CP3-CB4`
**Boundary:** **Code + Build / runtime-free**
**Entering corrected candidate:** source `279efa03471f1e0d6c32f57c8b395dd1cb1a93f5`, artifact `10620415471` — **unpromoted**
**Accepted runtime authority:** package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` / selector430 **430/430**
**Owner:** correction frozen by `M5-CP3-TB1-R2-REV`

## 1. Goal

Correct the one remaining deterministic authority-domain error in CP3 same-region periodic promotion without altering the frozen representation rule. The generator carrier continues to come from the exact A3 `sharedBoundaryInterval.span` / accepted `GlobalTopologyPlan::sourcePath`; the generator **transport value** for a mandatory hard-feature support must come from existing exact cross-field edge-transition metadata for that same source edge and directed face pair, not from `FieldTransportAtlas` traversal adjacency.

Also make exact source-path orientation complete for mandatory intervals split at an exact terminal-barrier point by using the existing exact edge-parameter helper rather than requiring both support endpoints to be source vertices.

## 2. Review finding that authorizes this turn

Fresh R2 run/job `35557990692 / 106205308600` is mechanically authoritative but semantic RED: **9/9 mechanism PASS, 0/6 produced PASS, selector430 429/430 PASS**, exact-one/zero-skip with immutable postflight and zero prohibited-operation counters. Candidate `10620415471` remains unpromoted.

Independent Review proves the failed recovery is deterministic:

- the promoted A3 shared-boundary span resolves to a canonical `Mandatory` `SourceEdgeSupport` on the HardRail carrier;
- CB3 calls `FieldTransportAtlas::transport(carrier.edge, fromFace, toFace)` to obtain that support's relation transport;
- `FieldTransportAtlas::make` publishes every hard-feature source edge as `FieldTransportBarrierKind::HardFeature` and `continue`s before creating `FieldTransportAdjacency`;
- `FieldTransportAtlas::transport` searches only those traversal adjacencies, so a hard-feature carrier necessarily returns no value;
- the promotion helper therefore returns no generator route and emits `PeriodicHolonomyMismatch` before periodic action construction.

The raw `CrossFieldEdgeTransition` authority already exists and is keyed by exact source edge before atlas barrier classification. Existing `resolve_branch_transition` logic validates edge identity + directed face pair and maps `matching` to a directed `QuarterTurn`, inverting it for reverse traversal. CB3's own plan explicitly permitted the already-built transition lookup. No new semantic authority is required.

A separate static completeness issue is frozen into this turn: `GlobalTopologyPlan` may split one mandatory edge at an exact terminal-barrier parameter, producing support endpoints that include `ExactSourceEdgePoint`; the existing `exact_edge_parameter` helper already supports both endpoint forms.

## 3. Authorized source scope

Semantic mutation is limited to:

- `src/geometry/SurfaceCellTracing.cpp`

No test, fixture, benchmark, selector, frozen definition, public header, CMake/build source, `FieldTransportAtlas` implementation, or other product file is authorized to change unless compilation proves a declaration-only mechanical necessity. Any semantic widening outside the named seam **stops** the turn and returns to Review.

## 4. Required implementation

### 4.1 Preserve exact span carrier authority

Keep the CB3 exact-carrier correction:

1. resolve `sharedBoundaryInterval.span` through accepted `GlobalTopologyPlan`;
2. require `GlobalTopologyArcKind::Mandatory`, exact canonical `sourcePath`, and the exact `SourceEdgeSupport` carrier;
3. retain `InteriorTransitionId` derivation from the existing exact source-edge matching-index authority;
4. build the generator `CanonicalRoute` only from that exact ordered source path.

Do not restore `atlas_rotation_between_faces`, a topology-region search, path-independence gauge reconstruction, insertion-order inference, floating geometry, or a synthetic aggregate route transport.

### 4.2 Read hard-feature transport from exact edge-transition metadata, not traversal adjacency

For each exact `SourceEdgeSupport` step:

1. require authoritative `edgeTransitions` to be present for the production path;
2. use the existing edge-keyed transition lookup on those raw `CrossFieldEdgeTransition` records and reject duplicate edge authority;
3. require exactly the same `SourceEdgeTopologyKey` as the source-path carrier;
4. validate the transition's source vertices reconstruct that exact edge;
5. validate the requested `fromFace/toFace` is exactly the transition's `firstFace/secondFace` pair in either direction;
6. derive `QuarterTurn::from_integer(matching)` for forward face traversal and its inverse for reverse traversal, matching the existing `resolve_branch_transition` semantics;
7. attach that directed quarter-turn to the exact route step and let `CanonicalRoute` compose it normally.

`FieldTransportAtlas` remains authoritative for traversal/nontraversability. **Do not add a hard-feature adjacency, change `FieldTransportBarrierKind::HardFeature`, or weaken A1 barrier semantics.** Relation transport across the paired cut copies consumes the exact edge-transition value; it does not make the source edge traversable.

If raw edge-transition authority is absent, duplicated, edge-mismatched or face-pair-mismatched, fail closed with the existing production failure. There is no fallback to atlas traversal, edge matching vectors, path search or geometry guessing for this seam.

### 4.3 Derive support orientation from exact parameters

Replace the CB3 vertex-only endpoint requirement with the existing exact parameter conversion:

- `exact_edge_parameter(piece.first, carrier.edge)`;
- `exact_edge_parameter(piece.second, carrier.edge)`.

Require both parameters, require they differ, and select `Orientation::Forward` when first < second and `Orientation::Reverse` when first > second. This preserves full-edge `[0,1]` carriers and supports the already-authorized mandatory split intervals `[0,t]` / `[t,1]` whose endpoint is an `ExactSourceEdgePoint`.

Do not convert exact parameters to floating values for route identity or orientation.

### 4.4 Preserve the reciprocal periodic action and all surrounding contracts

Keep CB3's paired chart/lattice action derivation and all frozen §14.2-14.4 conditions unchanged:

- same source topology region;
- exact reciprocal A3 shared-boundary intervals and distinct occurrences;
- canonical reverse paired routes, family match and opposing advances;
- cross-region pairs remain `HardRail`;
- same-region `HardRail` materializer rejection remains binding;
- promoted edges retain exact A3 provenance on `PeriodicCut` and one canonical periodic owner;
- relation identity remains carrier-content identity independent of transport value;
- CP2 conflict/nonreciprocal/renumbering typed failures remain unchanged;
- nine reviewed mechanism identities, six exact `M5CP3.Produced...` identities, row408 and selector430 remain unchanged.

## 5. Static verification before compile

Before any compile workflow, verify from source/diff:

- the same-region generator route no longer calls `fieldTransportAtlas->transport` for its mandatory HardRail support;
- the route step's quarter-turn comes from the exact raw edge-transition record keyed by the same carrier and validated directed face pair;
- reverse face traversal uses the inverse transition quarter-turn;
- support orientation is derived from exact source-edge parameters and accepts `ExactSourceEdgePoint` endpoints;
- no whole-region path/rotation search or fallback transport inference exists in the promotion seam;
- `FieldTransportAtlas` hard-feature nontraversability is unchanged;
- no test/fixture/selector/frozen-definition bytes changed;
- selector430 remains LF-only at SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, first427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- no CP1/CP2 relation validation is weakened.

## 6. Falsifiers and stop rules

Stop without semantic repair if any of these is true:

1. the exact mandatory support edge has no unique `CrossFieldEdgeTransition` record;
2. the record does not reconstruct the exact source-edge carrier or does not match the requested face pair in either direction;
3. exact support orientation cannot be derived from the two exact edge parameters;
4. recovery requires making a hard feature traversable in `FieldTransportAtlas`, changing A1 barrier classification, or inventing a new transition product/API;
5. recovery requires a topology-region search, reachability/path search, floating geometry, inferred matching, insertion-order identity, or any fallback not keyed by the exact source path;
6. correction requires changing a produced test, row408, fixture, selector, frozen definition, debt discriminator, CP2 checked failure, cross-region HardRail behavior, or same-region HardRail materializer rejection;
7. compilation requires a broader semantic refactor than `src/geometry/SurfaceCellTracing.cpp`;
8. mandatory GMP compile/package fails after at most one compile-mechanical, semantics-neutral correction.

Any stop routes to independent Review. It never authorizes expectation evolution.

## 7. Mandatory compile/package and success criterion

This turn is runtime-free. Do not execute any Directional binary, test, benchmark, discovery command, `ctest`, CLI, fuzzer or generated target.

After static verification, run the mandatory GitHub compile/package reusable with GMP/GMPXX enabled, clean source-status receipts, `runtimeExecution=false`, and all eight standard targets. Preserve package manifest/source/archive evidence exactly as in prior M5 CB turns.

CB4 succeeds only if the correction is statically faithful to frozen §§14.2-14.4 and compile/package is green. A successful CB4 routes to fresh artifact-only **`M5-CP3-TB1-R3-EXEC`**, restarting the unchanged **9 mechanism + 6 produced + selector430 = 445** exact-filter processes from process 1 with exact-one selection, zero skips, benchmark **0**, immutable pre/postflight and no reuse of R1/R2 semantic credit.

Selector publication remains prohibited. Candidate promotion and all four M5 debt decisions remain Review-owned after fresh runtime.
