# M5-CP3-CB8 Source-Face Incidence Authority Correction Plan

**Turn:** `M5-CP3-CB8`
**Boundary:** **Code + Build only / runtime-free**
**Authorized semantic source:** `src/geometry/SurfaceCellTracing.cpp` only
**Purpose:** restore exact A3 boundary-occurrence face incidence at the generator-route atlas query
**Compile-green successor:** `M5-CP3-TB1-R7-EXEC`

## 1. Review authority

`M5-CP3-TB1-R6-REV` independently upholds the R6 branch proof and classifies
`M5-CP3-TB1-R5-REV-OBS-01` as **CAUSE PROVED / EXISTING `RP-01 / AUTHORITY_DOMAIN_CONFLATION` CONTINUATION**.
All six produced torus identities stop first at `PeriodicGeneratorRouteUnavailable`. The accepted A3 cut domain
already computes one exact occurrence-owning `SourceFaceId`, but same-region A4 promotion discards that incidence
and queries `FieldTransportAtlas::transition_value` using `first.from.face / second.to.face` representation-point
provenance. At deduplicated A4 boundary junctions that point face is not a per-carrier ownership fact.

Frozen §§14-15 remain valid. The atlas already retains a validated transition value for hard-feature carriers
without making them traversable. The correction is therefore local to the consumer's face-incidence authority.

## 2. Exact implementation contract

Change only `src/geometry/SurfaceCellTracing.cpp` and preserve every unrelated behavior.

1. Reuse the `AcceptedCutBoundarySegment::sourceFace` authority already derived from the exact oriented A3
   `SourceEdgeSupport` and active carrier incidence. Do not recompute ownership from floating geometry.
2. Preserve a local checked association sufficient to resolve a shared interval's exact
   `SurfaceBoundaryOccurrenceId` + `NetworkArcId` + carrier edge to its unique owning `SourceFaceId`. The
   implementation may choose a local map/index shape, but ambiguity, absence or contradictory duplicate facts
   must fail closed through existing front-boundary authority failure ownership.
3. For a same-region reciprocal interval pair, resolve both directed occurrence-owning faces from that accepted
   authority. Do **not** read either directed face from `SurfaceTracePoint::face`, `SurfaceFrontEdge::{from,to}.face`,
   point insertion order, UV deduplication, or region-wide search.
4. Resolve the generator carrier from the interval's exact `span` / canonical one-piece `Mandatory`
   `GlobalTopologyArc::sourcePath` exactly as current code does.
5. Validate that the two resolved occurrence faces are distinct and, as an unordered pair, equal exactly the two
   source faces incident to that carrier in `sourceEdgeFaces`. This check is membership/consistency only.
   **Never use `sourceEdgeFaces[edge][0/1]` storage order to invent the directed query order.**
6. Pass the directed occurrence-owned `SourceFaceId` pair to
   `FieldTransportAtlas::transition_value(carrier->edge, fromFace, toFace)`. Prefer keeping the helper typed in
   `SourceFaceId` so raw A4 integer point provenance cannot be accidentally reintroduced.
7. Preserve existing exact edge-parameter orientation, `InteriorTransitionId`, `TransitionStep`, canonical route,
   `GridAutomorphism`, action-correspondence and `SurfacePeriodicHolonomy::make` logic byte-semantically except for
   the corrected source-face authority feeding the atlas value query.
8. Preserve CB7 diagnostic reason values and mapping. Do not collapse or renumber the six appended reasons.

## 3. Explicit prohibitions

CB8 must not:

- change any public header, `FieldTransportAtlas` API/implementation, atlas construction, hard-feature barrier or
  traversability semantics;
- use raw `CrossFieldEdgeTransition` as a second production owner or restore raw transition ingress;
- use A4 endpoint point faces as a fallback when exact occurrence ownership is missing;
- guess direction from `sourceEdgeFaces` array/storage order;
- change generator/cut route identity, action/lattice mathematics, relation ID/factory semantics, zero-translation
  policy, CP2 typed failures or periodic ownership rules;
- change any test, fixture, selector, benchmark, frozen definition or acceptance expectation;
- execute any Directional generated binary/test/benchmark/discovery/help/version/CLI/fuzzer/custom input in CB8.

If exact occurrence-to-face association cannot be recovered unambiguously from existing accepted-cut authority
within `SurfaceCellTracing.cpp`, **stop**. Do not widen scope or add a header/API just to make the correction fit.

## 4. Static falsifiers before compile

The Code + Build report must prove from the diff/source that:

- the generator-route transition query has no source from `first.from.face`, `second.to.face` or any other
  `SurfaceTracePoint::face` value;
- each occurrence-owned directed face is traced to `AcceptedCutBoundarySegment::sourceFace` and exact conformity
  incidence;
- carrier incidence is revalidated against `sourceEdgeFaces` as a set, with no semantic dependence on its order;
- hard-feature nontraversability remains unchanged and only atlas `transition_value(...)` is consumed;
- no test/fixture/selector/frozen-definition/public-header/atlas source changed.

A violation is a CB8 failure even if compilation would succeed.

## 5. Mandatory compile/package gate

Use `.github/workflows/agent-compile-reusable.yml` only. Build/package all eight standard targets with exact
GMP/GMPXX backend and `runtimeExecution=false`:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Require preflight/build exit 0, explicit `gmpxx` + `gmp` link evidence, clean source-status receipts, exact packaged
source identity, result/log artifacts and recursive self-excluding package manifest. No runtime semantic credit is
created by compile green.

## 6. Fresh R7 artifact-only falsifier after compile green

If and only if CB8 static + compile/package gates are green, exact successor is
`M5-CP3-TB1-R7-EXEC`. R7 consumes the new candidate immutably and repeats the unchanged **446 fresh exact-filter
processes** with benchmark **0**:

- 9 reviewed mechanism identities;
- 1 focused atlas value-without-adjacency identity;
- 6 produced torus identities;
- all 430 frozen selector430 rows in order.

Every process must select exactly one test, skip zero, and retain immutable package/source/execution-view
pre/postflight with all prohibited-operation counters zero. The three protected generic-reason rows at selector
ordinals 191/192/247 remain byte-unchanged and required-green.

### Pre-committed outcomes

**Primary falsifier:** none of the six produced rows may still report `PeriodicGeneratorRouteUnavailable`.
If even one does, CB8's causal correction is falsified and R7 closes semantic RED for mandatory Review.

If all six advance but expose a later typed reason (`PeriodicActionCorrespondenceMismatch` or a checked holonomy
construction reason), record each exact row reason. That is useful evidence but **not** recovery; mandatory Review
owns the next decision and no same-turn repair is allowed.

A full recovery candidate requires all of:

- mechanism **9/9 PASS**;
- focused atlas **1/1 PASS**;
- produced **6/6 PASS**;
- selector430 **430/430 PASS**;
- all 446 exact-one/zero-skip;
- exact immutable postflight and zero prohibited counters.

Even full green does not promote the package, discharge debt or publish a successor selector. Mandatory
`M5-CP3-TB1-R7-REV` must independently re-derive the evidence, close/carry `M5-CP3-TB1-R2-REV-OBS-01`, adjudicate
production-debt credit, and only then decide whether CP3 may enter selector-publication authority.

## 7. Accepted authority and accounting boundary

Entering accepted runtime authority remains package/source
`10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. Stable accounting remains
**50 events / 14 categories / 36 recurrences**, debt **5**. CB8 is recovery of the existing open stable `RP-01`
event: it creates no accounting change by compiling and cannot close any of the four M5 produced debts.
