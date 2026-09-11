# M4-CP3-CB4-R1 Code + Build Plan — exact A2b arc-support publication and production A3 binder

**Status:** FROZEN / READY
**Turn:** `M4-CP3-CB4-R1`
**Execution mode:** canonical Code + Build / runtime-free
**Normative contract:** `Architecture_M4_DEFN_Frozen_Definitions.md` §§17 and 17.12
**Review authority:** `Architecture_M4_CP3_CB4_REV_Review_Record.md`
**Accepted runtime predecessor:** package119 / selector394 **394/394**
**Successor after a green package:** artifact-only `M4-CP3-TB2-EXEC` under a CB4-R1-closeout-frozen plan

## 1. Objective

Repair the authority publication gap found by the CB4 derivation guard without beginning the A4 cutover. Publish one canonical exact ordered source path on every accepted A2b `GlobalTopologyArc`, validate and digest that publication independently, derive the production `GlobalConformityBaselineInput` spans 1:1 from those paths, and construct/independently validate exactly one production baseline A3 plan immediately after A2b.

A4 remains behaviorally unchanged in this turn. Region-domain migration, exact shared-boundary materialization, `HardRailPairKey`/floating `support_key` retirement and the exact-torus `InvalidHardRailPairing` gate are deferred until the new A2b→A3 boundary is runtime-proved.

## 2. Shared exact-path authority representation

Create or factor one upstream-neutral exact source-path representation usable by A2b and A3. Prefer an authority-layer header rather than making `GlobalTopologyPlan` depend on `GlobalConformityPlan`.

The representation must support:

- source vertex;
- source edge + exact `FieldExactRational` parameter;
- source face + three exact barycentric rationals associated with canonical source-face vertex order;
- one support piece = `SourceSupport carrier` + exact first/second source points.

Do not create two independently canonicalized path representations. Existing `ConformitySourcePoint` / `ConformitySupportPiece` should become aliases or mechanically reuse the shared representation where source compatibility permits.

Canonicalization/validation is exact:

- an exact edge endpoint is represented as its source vertex;
- an interior edge point remains an edge point;
- a true face-interior point remains a face point;
- every endpoint must be contained by its carrier;
- every piece is nondegenerate;
- consecutive pieces share exactly equal source points;
- no floating tolerance, nearest-point snap or row-order convention is semantic authority.

## 3. Publish exact support on every A2b arc

Extend `GlobalTopologyArc` with its canonical non-empty ordered exact support path in `firstNode -> secondNode` orientation. The canonical A2b builder must populate it while the construction-private exact bindings are still available.

Per-kind contract:

1. **Mandatory** — publish one exact edge-support piece for the actual A2b arc interval. Unsplit mandatory arcs cover the full authoritative source edge. Split arcs use the exact A2a terminal locus already responsible for the synthetic split node, producing complementary endpoint→terminal / terminal→endpoint pieces rather than duplicating the full parent edge.
2. **Cut** — publish one exact edge-support piece between the adjacent exact ordered cut-node parameters already materialized by the A2b cut binding. A split cut edge therefore yields distinct exact subintervals for distinct `NetworkArcId`s.
3. **Trace** — publish one exact support piece per traversed trace segment in `[firstSegment, onePastLastSegment)`, using the accepted A2a exact segment entry and exact exit/contact/terminal authority. Piece order follows semantic trace order. If an arc endpoint cannot be bound exactly to its A2a node/event locus, fail closed instead of synthesizing a geometric point.

Reverse region incidence uses the same arc authority reversed; do not publish a second reversed copy.

## 4. A2b independent validation and digest binding

Strengthen the canonical candidate and validator so exact support is not self-authorizing:

1. reconstruct expected per-arc support from source topology plus accepted A2a/A2a′ products and exact construction rules;
2. compare candidate support exactly, including piece count/order, carriers, endpoint point kinds and exact coordinates;
3. verify path endpoint loci agree with `firstNode` / `secondNode` bindings;
4. reject empty, disconnected, degenerate, off-carrier, incorrectly canonicalized or parent-edge-overbroad support;
5. include exact support in A2b semantic digest/hash and validation candidate coverage.
6. reconcile the published path against the arc's existing `sourceFaces`: the traversed face set must be exactly
   consistent with it (same faces, same order where face-carried), and edge-carried pieces must lie on the arc's
   `cutEdge` / `mandatoryEdge`. Two published source-location authorities on one arc may not go unreconciled —
   for `Trace` arcs both derive from the same `[firstSegment, onePastLastSegment)` A2a range, so agreement holds
   by construction and any failure is diagnostic. See the CB4-REV record §9 V4.

Do not infer expected support from the candidate's own support vector and do not use floating geometry/tolerance as an oracle.

This strengthening must preserve selected cuts, arc IDs/order/kinds, rotations, region boundaries/source-face ownership and region certificates. Any unexpected topology change is a stop condition requiring Review rather than normalization in this turn.

## 5. Production A3 binder and single writer

After successful A2b construction in `RemeshPipeline.cpp` and before A4/tracing regional production:

1. construct `GlobalConformityBaselineInput.sourceVertices` from the exact current source mesh;
2. bind `targetSize` from the accepted A0 target-size field;
3. create exactly one `ConformitySpanInput` per canonical `GlobalTopologyArc`, with `ConformitySpanId::from_network_arc(arc.id)` and the A2b-published exact support copied 1:1;
4. call `build_global_conformity_baseline` exactly once for the production component;
5. independently validate the resulting plan with `validate_global_conformity_baseline` before publication;
6. retain/publish the immutable plan as a declared pipeline stage product and diagnostic snapshot with exact product identity/digest accounting consistent with existing A2a/A2a′/A2b products.

The binder may map shared exact-path types mechanically; it may not reconstruct path geometry from `sourceFaces`, parent cut edges, synthetic-node numbering or private A2b maps.

No A4 consumer is permitted to read or depend on the new A3 product in R1. `SurfaceCellTracingOptions` and A4 shared-boundary decisions remain semantically unchanged until TB2 proves this new boundary.

## 6. Required Code + Build test contracts

Add focused behavior tests that compile now and execute only in the successor TB. At minimum cover:

1. a split `Cut` edge publishes distinct exact adjacent subintervals on its A2b arcs, with exact endpoint-node agreement;
2. a split `Mandatory` edge publishes complementary exact terminal subintervals rather than the full parent edge twice;
3. a multi-segment `Trace` arc publishes an exact contiguous ordered chain from accepted A2a segment/contact authority;
4. reversing an incidence reverses support order/endpoints without changing the canonical arc path;
5. independently tampering any support carrier, endpoint kind/coordinate, piece order or subinterval causes A2b candidate validation to fail closed and cannot preserve the semantic digest;
6. production binding creates exactly one span per A2b arc, with identical exact support and no family/sign invention;
7. production pipeline constructs and independently validates exactly one baseline A3 plan after A2b and exposes the immutable stage product/diagnostic identity;
8. a source audit/test seam proves R1 introduces no A4 semantic dependence on the A3 product and no floating/tolerance path reconstruction.

Where a test uses face barycentrics, deliberately use a source-face row whose vertex order differs from canonical key order so canonical component mapping is actually exercised.

New required-green identities append after accepted selector394. Do not rewrite, reorder or weaken any accepted selector394 identity. Exact appended identity count/order/hash is frozen in CB4-R1 closeout before package creation.

## 7. Compile-only verification

Before compile:

1. preserve/apply the exact intended patch through the required work-preservation workflow;
2. verify intended path set and source cleanliness;
3. commit/push the exact semantic source;
4. run the mandatory exact-source changed-owner/pre-package compile through `.github/workflows/agent-compile-reusable.yml` with GMP/GMPXX and `runtimeExecution=false`;
5. if green, compile/package the complete approved runtime-owner surface needed by the successor TB, including the selector owner executables, `directional_core`, `directional_pipeline`, `directional_compiled_api_tests` and `directional_benchmarks` as applicable to the changed owner set;
6. package exact source, selector, required fixtures/test data, clean source status, command-boundary evidence, GMP evidence and self-excluding manifest.

No local compile is authoritative. No generated Directional test, benchmark, CLI, discovery/listing, help/version command or custom input may execute in this turn.

## 8. Stop conditions

Stop and return to Review rather than broadening R1 if any of these occurs:

- an A2a arc kind lacks exact construction-time endpoint/path authority even before publication;
- exact canonical face-point ordering cannot be derived from existing source topology without adding a new semantic convention;
- publishing support requires changing A2b arc IDs/order/topology, selected cuts, rotations, regions or disc certificates;
- production A3 binding requires caller-invented family/sign or floating/tolerance reconstruction;
- A4 must change to make the new A2b/A3 boundary compile;
- accepted selector394 identities would need weakening/redefinition.

## 9. Success criteria and successor

CB4-R1 is complete only when:

- every accepted A2b arc publishes validated exact support under §17.12;
- all three arc kinds and split-edge cases have compile-valid focused regression coverage;
- A2b digest/candidate validation binds the support independently;
- production derives one A3 span per A2b arc by exact copy and constructs/independently validates one immutable baseline plan;
- A4 semantics remain unchanged;
- changed-owner and full approved package compile are green with GMP/GMPXX and `runtimeExecution=false`;
- work-preservation and temporary workflow state are cleaned.

Then freeze an artifact-only `M4-CP3-TB2-EXEC` plan that runtime-proves the new A2b support publication and production A3 binder against the compiled package. Only after TB2 Review accepts that authority may `M4-CP3-CB5` perform the final A3→A4 shared-boundary cutover from the still-valid downstream portions of the superseded CB4 plan.
