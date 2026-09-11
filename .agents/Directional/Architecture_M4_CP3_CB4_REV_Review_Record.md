# M4-CP3-CB4-REV Independent Review + Plan Record

**Status:** COMPLETE / APPROVED WITH AMENDMENTS / GUARD UPHELD / OLD CB4 PLAN SUPERSEDED
**Turn:** `M4-CP3-CB4-REV`
**Execution mode:** independent Review + Plan / runtime-free
**Review-entry semantic head:** `26c6bbd481debc6f8f6b613aff1bb7e7fae40388`
**Snapshot control head:** `0ac90cd1c1c70d15f99393b4f9b84c4d3246ccc3`
**Source-snapshot run/artifact:** `34635857254 / 10277961550`
**Snapshot artifact digest:** `sha256:b731644a92a361cf77dacde16e894dd9364d123f37881154c653cfce255c5252`
**Snapshot archive digest:** `sha256:52d6ea02c7d3936a87ac7362f60bf93e82135fcf51dd08d6f77e177b0f86e5fe`
**Reviewed plan:** `Architecture_M4_CP3_CB4_Code_Build_Plan.md`
**Decision:** `approved_with_amendments`
**Exact next:** `M4-CP3-CB4-R1` under `Architecture_M4_CP3_CB4_R1_Code_Build_Plan.md`

## 1. Reviewer independence and boundary

Same-agent Review is user-authorized. Independence was established by reopening the exact source snapshot and re-deriving the relevant product/publication paths from primary headers and implementations rather than accepting the CB4 guard summary as proof. This turn changed planning/documentation authority only. It did not edit product, test, benchmark, fixture, selector, CMake/build logic, or reusable workflow semantics; compile, generated binaries, tests, benchmarks, discovery/listing and Directional runtime were not executed.

## 2. Evidence reviewed

Primary source evidence:

- `include/directional/geometry/SurfaceCutGraph.h` public A2a′ product surface;
- `include/directional/geometry/GlobalTopologyPlan.h` public A2b `GlobalTopologyArc` and candidate surface;
- `src/geometry/EmbeddedGraphTopology.cpp` construction of cut-node bindings, mandatory/trace/cut arc drafts and exact crossing parameters;
- `include/directional/geometry/SurfaceCellTracing.h` A2a exact trace segment/terminal authority and current A4 ingress;
- `include/directional/geometry/GlobalConformityPlan.h` current A3 exact source-point/support-piece vocabulary;
- `include/directional/geometry/GlobalConformityBaseline.h` production-baseline input/plan/validator contract;
- `src/pipeline/RemeshPipeline.cpp` production A2a/A2a′/A2b construction/publication order;
- `include/directional/pipeline/RemeshPipeline.h` diagnostic product snapshots and component stage-product surface;
- `Architecture_M4_DEFN_Frozen_Definitions.md` §§4.1 and 17;
- `Architecture_M4_CP3_CB4_Derivation_Guard_Record.md` and the halted CB4 plan.

Accepted runtime predecessor remains package119 / selector394 **394/394**. The review did not rerun or reinterpret that runtime evidence.

## 3. Findings

### R1 — the CB4 derivation guard is correct

**Disposition:** UPHELD.

A2b construction already has the exact data required to describe each full arc, but accepted public products discard part of it before A3 can bind:

- cut crossings are collected as exact `entryPoint.parameter` values, associated with synthetic `NetworkNodeId`s, sorted with exact edge endpoints, then adjacent exact points are converted into split `Cut` arcs;
- split `Mandatory` arcs similarly know the exact A2a terminal locus at construction time;
- `GlobalTopologyArc` publishes the parent cut/mandatory identity, endpoint nodes, trace segment range and source faces, but not the exact ordered path or exact split endpoint loci.

For a source cut edge split at one or more trace crossings, two different A2b arcs therefore publish the same parent `cutEdge` without publishing which exact subinterval each arc owns. A3 cannot recover that distinction from the accepted public products without relying on construction-private state, synthetic-node allocation conventions, floating geometry, or an invented reconstruction rule. The old CB4 plan explicitly forbids that move.

### R2 — the defect is publication placement, not missing construction information

**Disposition:** ROOT CAUSE REFINED.

The smallest authority correction is to publish the exact full-arc source path on the A2b arc itself. A2b is the first accepted stage that combines A2a trace/terminal loci with A2a′ cut authority into the actual embedded-graph arc decomposition. Widening `SurfaceCutGraph` with trace-dependent crossing-to-network-node maps would couple A2a′ to later A2b allocation semantics and still would not provide one uniform authority for `Mandatory`, `Trace`, and `Cut` arcs.

A node-locus-only publication is also insufficiently uniform: it repairs edge subintervals but leaves multi-face `Trace` support reconstruction coupled to A2a internals. One canonical ordered exact path per `GlobalTopologyArc` is the smaller downstream contract.

### R3 — §4.1/§17 contained a real ownership ambiguity

**Disposition:** NORMATIVE AMENDMENT REQUIRED.

§4.1 said A3 reconstructs each span path from bound A2a/A2a′ authority, while §17.3 calls exact ordered support pieces the only source-location authority without freezing where that authority must be published. §17.1 also described artificial cuts as already carrying exact support/topology authority, which is true for the selected source edge but not for an A2b split subarc's exact endpoint interval.

That wording is insufficient for production because A2b synthetic split-node binding is not an accepted A2a/A2a′ publication. New §17.12 supersedes only this reconstruction implication: A2b must publish the exact ordered path for every accepted arc, and production A3 must copy that authority rather than reconstruct it.

### R4 — existing A3 path types should not be duplicated downstream

**Disposition:** AMEND IMPLEMENTATION PLAN.

`GlobalConformityPlan.h` already has the exact semantic shape required by the publication: vertex / exact edge-parameter / exact face-barycentric points plus carrier-bound support pieces. But that header includes `GlobalTopologyPlan.h`, so A2b cannot depend on those A3-named structs without inverting the layer or creating a cycle.

The simplest sufficient implementation is to factor the generic exact source-point/path-piece representation into an upstream-neutral authority header, use it from A2b, and keep A3 names as aliases or otherwise preserve one representation. Two independent point/path representations plus conversion code are rejected because they create an avoidable second canonicalization surface.

### R5 — the halted CB4 plan became too broad after this discovery

**Disposition:** SUPERSEDE AND SPLIT.

The old CB4 plan coupled an upstream A2b publication-contract change, A3 production construction, region-domain handoff, shared-boundary materialization, and hard-rail pairing replacement in one Code + Build turn. That is no longer surgical.

The replacement `M4-CP3-CB4-R1` is intentionally narrower: publish and independently validate exact A2b arc support, then construct/publish exactly one production baseline A3 plan from that support. A4 shared-boundary behavior remains unchanged in R1. A focused artifact-only TB must prove the new publication/binder boundary before A4 is allowed to depend on it. The final A3→A4 cutover then belongs to a later `M4-CP3-CB5` plan derived from the still-valid downstream portions of the old CB4 plan.

## 4. Frozen authority amendment

The review freezes these production rules:

1. Every accepted `GlobalTopologyArc` publishes a non-empty canonical ordered exact source path in `firstNode -> secondNode` orientation.
2. The path representation is upstream-neutral and exact: source vertex, source edge + exact parameter, or source face + exact barycentric coordinate, carried by an exact source-support piece.
3. Consecutive pieces join exactly; pieces are nondegenerate; each endpoint is contained by its carrier; first/last path points are the exact loci of `firstNode`/`secondNode`.
4. Exact endpoint canonicalization is semantic, not tolerance-based. Edge endpoints canonicalize to source vertices; interior edge points remain edge points; true face-interior points remain exact face points. Face barycentrics must be associated with the canonical face-topology vertex order.
5. `Mandatory` A2b arcs publish one exact source-edge support piece for the actual arc interval. A split mandatory edge uses its exact A2a terminal locus; it may not republish the full parent edge for both pieces.
6. `Cut` A2b arcs publish one exact source-edge support piece between the adjacent exact cut-node parameters already known during A2b construction.
7. `Trace` A2b arcs publish the exact ordered support chain over their `[firstSegment, onePastLastSegment)` range from accepted A2a exact segment entry/exit/contact authority. Any missing or contradictory exact endpoint fails closed in A2b.
8. Reverse region incidence reverses piece order and piece endpoints; it does not create a second semantic path.
9. A2b semantic digest and validation cover the published exact path. Candidate validation must reconstruct expected support from source + accepted A2a/A2a′ inputs and compare exactly; a mutable candidate cannot authenticate its own support.
10. Production A3 creates exactly one `ConformitySpanInput` per canonical A2b arc and copies the A2b path 1:1. It must not reconstruct support from source faces, parent cut edges, synthetic node numbering, floating geometry or construction-private maps.
11. This is an additive A2b publication/certificate strengthening. It does not change selected cuts, A2b arc IDs/order/topology, rotation system, region walks, disc certificates or the already accepted package119 parity-solver semantics. Existing M3 topological evidence is retained for those unchanged semantics; it does not count as runtime proof of the newly published support field.
12. A4 remains unchanged until the new publication and A3 binder receive artifact-only runtime proof.

These rules are now normative through `Architecture_M4_DEFN_Frozen_Definitions.md` §17.12.

## 5. Engineering-guideline review

- **Material assumption challenged:** the old plan assumed bound A2a/A2a′ public products were sufficient to reconstruct every A2b span path. They are not for split cut/mandatory arcs.
- **Simpler alternative considered:** widening A2a′ or publishing only node loci was considered and rejected as more coupled/less uniform than per-A2b-arc exact support.
- **Unrelated/speculative work removed:** R1 does not touch A4 grid selection, region-domain mapping, hard-rail pairing or the exact-torus gate.
- **Surgical scope:** one shared exact-path representation, A2b publication/validation/digest, one A3 binder/writer, focused regression source, compile-only verification.
- **Observable success:** compiled tests must establish exact support for all three arc kinds, tamper rejection, 1:1 arc→span binding, exactly one production A3 writer and unchanged A4 ingress; runtime proof is explicitly deferred to the succeeding TB turn.

## 6. Decision

**APPROVED WITH AMENDMENTS.** The CB4 stop was correct. The old `Architecture_M4_CP3_CB4_Code_Build_Plan.md` is superseded because its prerequisite authority is absent and its post-discovery scope is too broad.

The sole authoritative next plan is `Architecture_M4_CP3_CB4_R1_Code_Build_Plan.md`.

## 7. Risks and merge implications

- Exact face-point canonicalization must not silently mismatch barycentric component order after canonical `SourceFaceTopologyKey` sorting.
- Support publication must be independently reconstructed during validation; hashing candidate bytes alone would make the new field self-authorizing.
- Existing A2b topology IDs/ordering and accepted M3 semantics must remain byte/semantic stable except where the new support field is intentionally added to the A2b semantic digest.
- A4 must not begin consuming A3 in R1; doing so would combine the newly amended upstream contract with the downstream cutover before the new boundary has runtime evidence.

## 8. Integrity confirmation

- Production code changed: **no**
- Test/benchmark/fixture/selector logic changed: **no**
- Build configuration changed: **no**
- Reusable workflow semantics changed: **no**
- Compile executed: **no**
- Directional tests/benchmarks/binaries executed: **no**
- Accepted package119 / selector394 authority changed: **no**
- Stable regression accounting changed: **no**, remains **47 / 14 / 33**
- Produced-witness debt changed: **no**, remains **5**

---

## 9. Independent verification addendum (reviewing agent)

Runtime-free. The decision is **upheld**: the CB4 derivation-guard stop was genuine, the frozen §17.12
amendment is the right resolution, and splitting the work so CB4-R1 publishes authority without
beginning the A4 cutover is correct sequencing. Accepted authority remains package119 / selector394
**394/394**; accounting stays **47 / 14 / 33**, debt **5**.

### V1 — the stop was genuine, verified from the published structure

`GlobalTopologyArc` (`include/directional/geometry/GlobalTopologyPlan.h:43-56`) publishes `cutEdge` as
a whole `std::optional<SourceEdgeTopologyKey>` — an entire source edge, with no sub-interval endpoints
and no ordered support pieces. A cut arc split by an interior network node therefore has no published
exact locus for where it starts and stops along that edge, and §17.3 requires exact ordered support
pieces as the only source-location authority for breakpoints. The three workarounds CB4 rejected map
exactly onto the three standing prohibitions: the whole parent edge would overlap neighbouring spans
and break shared subdivision, construction-private synthetic node numbering violates single-writer,
and floating reconstruction violates the no-tolerance rule. Stopping was correct, not conservative.

### V2 — the resolution's key move is the right one

The amendment's decisive observation is rule 6: the adjacent exact cut-node parameters are **already
known during A2b construction** and merely unpublished. That reframes the gap from "missing authority"
to "unpublished authority", and publishing what the producer already holds is the only resolution
consistent with both single-writer and exact arithmetic — every alternative requires a downstream
consumer to re-derive what an upstream stage already knew. Rule 10's "copy the A2b path 1:1, never
reconstruct" and rule 9's requirement that validation rebuild expected support from source plus
accepted A2a/A2a′ inputs rather than from the candidate's own vector keep that discipline intact.

CB4-R1 §8 also guards the premise rather than assuming it: if an arc kind lacks exact construction-time
endpoint authority *before* publication, the turn stops instead of inventing one. That is the right
place for that check.

### V3 — the "additive" claim is sound, and here is why

Rule 11 asserts the strengthening cannot disturb arc IDs, order, rotations, region walks or disc
certificates. That holds, for a reason worth recording rather than re-deriving later:

1. `GlobalTopologyOrientedArc` (`:35-40`) carries only `{NetworkArcId arc, Orientation}` — it does not
   embed the arc struct. Region boundaries and node rotations therefore reference arcs by id, and a new
   field on `GlobalTopologyArc` cannot reach them.
2. `GlobalTopologyArc::operator<=>` is defaulted and compares members in declaration order beginning
   with the unique `id`, so any appended field is unreachable for ordering purposes. Arc sort order is
   decided by `id` alone.

The rule-9 digest widening is likewise safe for accepted identities: no test asserts a hard-coded digest
literal, so digests are compared structurally — producer against validator, or one build's outcome
against another's — and both sides move together when the path joins the hash.

### V4 — REQUIRED ADDITION: reconcile the new path against the arc's existing `sourceFaces`

`GlobalTopologyArc` already publishes `std::vector<SourceFaceTopologyKey> sourceFaces` (`:53`). After
this amendment the same arc also publishes an exact ordered source path whose pieces carry faces and
edges. Those are two published source-location authorities for one arc, and §4 of the CB4-R1 plan does
not require them to agree — item 3 checks path endpoint loci against `firstNode`/`secondNode`, and
nothing checks traversed faces against `sourceFaces`.

This is not hypothetical drift between unrelated fields. For `Trace` arcs the two are co-derived from
the *same* upstream range: `sourceFaces` is built from `trace.segments[segment].sourceFace` across
`[first.position, second.position)` (`src/geometry/EmbeddedGraphTopology.cpp:550-553`), and rule 7
derives the published chain from the same `[firstSegment, onePastLastSegment)` A2a segment authority.
They must agree by construction — which is exactly why the check is cheap and why a failure would be
highly diagnostic rather than noisy. `sourceFaces` has **189** consumer sites in `src/geometry` alone,
so silent divergence between the two authorities would propagate widely before anyone noticed.

**Required in CB4-R1 §4, before compile acceptance.** Add a validation conjunct: the face set traversed
by the published exact path must be exactly consistent with the arc's published `sourceFaces` — same
faces, same order where the path is face-carried — and edge-carried pieces must lie on the arc's
`cutEdge` / `mandatoryEdge` as applicable. If the intent is instead that `sourceFaces` become a derived
view of the path, state that and name the single writer; what must not survive this turn is two
independent authorities for the same geometric fact with no stated relation between them.

This does not change the decision or the scope split. It closes the one place where an additive
publication can create a contradiction rather than only adding information.
