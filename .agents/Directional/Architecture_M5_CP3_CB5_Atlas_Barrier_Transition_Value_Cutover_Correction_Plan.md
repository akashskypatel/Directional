# M5-CP3-CB5 Atlas Barrier Transition-Value Cutover Correction Plan

**Turn:** `M5-CP3-CB5`
**Boundary:** **Code + Build / runtime-free**
**Authority:** `M5-CP3-TB1-R3-REV`
**Candidate predecessor:** artifact `10624020011` / source `6dd0e5179686a4ea2ca4aacda0577855948864df` — unpromoted
**Accepted runtime authority remains:** package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` / selector430 **430/430**
**Success on compile:** `M5-CP3-TB1-R4-EXEC`

## 1. Goal

Correct the one production-authority cutover error proved by R3 Review without widening M5 semantics: the exact A3 `Mandatory` carrier needs its cross-field transition **value**, but production intentionally cuts raw `CrossFieldResult` containers out after immutable `FieldTransportAtlas` has been built. CB4's raw `edgeTransitions` lookup therefore cannot execute on the production path.

CB5 keeps `FieldTransportAtlas` as the sole production A1 owner. It retains the already-validated exact transition value for interior source edges as immutable atlas semantic metadata distinct from traversable adjacency, then makes the M5 generator route consume that atlas-owned value.

## 2. Authorized semantic paths

Semantic mutation is bounded to:

- `include/directional/authority/FieldTransportAtlas.h`
- `src/authority/FieldTransportAtlas.cpp`
- `src/geometry/SurfaceCellTracing.cpp`

No test, fixture, benchmark, selector, frozen definition, CMake/build source, `RemeshPipeline` source, CP2 checked relation semantics, cross-region HardRail behavior, same-region HardRail materializer rejection, or A1 hard-feature traversability may change.

A declaration-only mechanical adjustment outside these paths is **not pre-authorized**. Stop and return to Review if one is genuinely required.

## 3. Required atlas authority split

### 3.1 Publish transition value independently of traversability

At `FieldTransportAtlas::make`, use the existing exact `transitionByEdge` ingress and validation seam. For every interior source edge with two valid source faces:

1. require exactly one raw `CrossFieldEdgeTransition` for the exact `SourceEdgeTopologyKey`;
2. require its `sourceEdge` row identity and `firstFace/secondFace` pair to match the source mesh edge in either direction;
3. derive exact forward `QuarterTurn::from_integer(matching)`, reverse as its inverse, the signed lift/matching and effort;
4. publish one canonical immutable transition-value fact keyed by exact source edge and face pair;
5. only then classify the edge as traversable adjacency versus `HardFeature` / other nontraversable barrier.

The transition-value fact is semantic metadata, **not traversal permission**. Source-boundary edges have no two-face transition-value requirement.

### 3.2 Keep adjacency semantics unchanged

`FieldTransportAtlas::transport(...)` remains traversal-adjacency-only. A hard-feature edge must still have no `FieldTransportAdjacency`, remain present in `nontraversable_edges()` as `FieldTransportBarrierKind::HardFeature`, and continue to return no value from the traversal `transport()` API.

Expose a separately named exact query such as `transition_value(sourceEdge, fromFace, toFace)` returning a type that does not carry `FieldTransportAdjacencyId` and therefore cannot imply traversability. Reverse face order must return the exact inverse quarter-turn and negated signed lift/effort where the existing directed semantics require it.

### 3.3 Semantic identity must cover the new retained fact

The atlas's immutable semantic digest/hash must include the canonical transition-value facts with storage-independent ordering and directed-value normalization. A transition-value mutation that leaves barrier classification unchanged must change the atlas identity. Do not leave the new semantic fact outside `field_transport_atlas_hash` / the quadrangulability atlas digest.

## 4. Generator-route cutover

Retain CB4's exact carrier and orientation logic unchanged:

- resolve `sharedBoundaryInterval.span` through `GlobalTopologyPlan::find_arc`;
- require canonical one-piece `Mandatory` source path;
- require exact `SourceEdgeSupport` carrier;
- derive Forward/Reverse orientation from `exact_edge_parameter` so `SourceVertexId` and `ExactSourceEdgePoint` endpoints both work;
- retain `InteriorTransitionId` derivation from the existing source-edge transition-index authority.

Replace CB4's raw `edgeTransitions` dependency with the new atlas-owned transition-value query for the **same carrier edge and requested directed source-face pair**. Production must not require, re-enable, or consult raw `CrossFieldResult::{matching,effort,edgeTransitions}` after atlas cutover.

The route remains fail-closed if the atlas value is absent or the exact requested face pair does not match.

## 5. Invariants that must remain unchanged

- Hard features are nontraversable barriers in A1.
- `FieldTransportAtlas::transport` remains adjacency-only.
- No whole-region path, gauge reconstruction, floating geometry, nearest match, guessed value or fallback search is allowed.
- No second production semantic owner for cross-field transition values is introduced.
- Frozen §14.2 same-region promotion preconditions remain exact.
- Cross-region paired cuts remain `HardRail`.
- Same-region `HardRail` materializer rejection remains binding.
- CP2 missing/duplicate/conflicting/nonreciprocal/representation-renumbered relation failures remain unchanged.
- Row408, all six `M5CP3.Produced...` identities, fixtures and selector430 bytes remain unchanged.
- Candidate promotion, produced-debt credit and selector publication are not Code + Build actions.

## 6. Pre-build falsifiers and stop rules

Stop before compile and return to Review if any of these is true:

1. retaining an exact transition value requires making a hard feature traversable or inserting it into `adjacencies_`;
2. production would need both raw `CrossFieldResult` transition containers and atlas authority simultaneously;
3. one interior edge can resolve to zero or multiple raw transition records after exact validation;
4. the raw transition edge identity or two-face pair cannot be validated at atlas construction;
5. the new query cannot distinguish semantic transition value from traversal adjacency in its type/API;
6. the retained transition fact cannot be included in the atlas semantic digest deterministically;
7. the generator carrier requires a global search, inferred transport, tolerance, or floating conversion;
8. any test, fixture, selector, frozen definition, CP2 failure contract, cross-region HardRail behavior or same-region materializer rejection must change;
9. source scope must widen beyond the three authorized files.

A stop is Review evidence, not permission to improvise another fix.

## 7. Static verification before compile

Before triggering build, verify from the exact diff/source that:

- only the three authorized paths changed;
- atlas construction validates and retains transition values before barrier/traversal exclusion;
- every traversable adjacency is derived from the same retained validated fact rather than independently re-reading raw values;
- hard-feature edges remain absent from `adjacencies_` and present in nontraversable barriers;
- the new query supports the exact directed face pair with inverse reverse semantics without `FieldTransportAdjacencyId`;
- atlas semantic identity includes the transition facts;
- `generator_route_for_span` no longer requires raw `edgeTransitions` and consumes only the atlas-owned value for its exact carrier;
- CB4 exact-parameter orientation remains intact;
- no fallback/global search or product/test/fixture/selector/frozen-definition change exists;
- selector430 remains 430 LF rows at `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, first427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

## 8. Mandatory GMP compile/package

Use the durable GitHub compile workflow only. Local compilation and all Directional runtime are prohibited in CB5.

Compile/link all eight standard targets with GMP/GMPXX enabled:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Require preflight/build exits `0 / 0`, explicit GMPXX+GMP linkage, empty packaged source-status receipts, manifest verification, exact semantic source receipt, and `runtimeExecution=false`. No generated Directional binary, test, benchmark, discovery command, `ctest`, CLI, fuzzer, help/version command or custom input may execute.

## 9. Successor gate

If and only if static verification and the mandatory compile/package are green, route to fresh artifact-only **`M5-CP3-TB1-R4-EXEC`**.

R4 must consume the CB5 package exactly and restart the complete frozen **9 mechanism + 6 produced + selector430 = 445** exact-filter process sequence from process 1 with exact-one selection, zero skips, immutable pre/postflight and benchmark execution **0**. No semantic credit from R1, R2 or R3 is reused.

Mechanically complete R4 evidence, green or semantic RED, routes to independent runtime-free `M5-CP3-TB1-R4-REV`. No candidate promotion, produced-debt credit or selector publication occurs before that Review.
