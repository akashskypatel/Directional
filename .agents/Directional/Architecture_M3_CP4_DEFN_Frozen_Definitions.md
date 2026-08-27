# Architecture M3 CP4-DEFN — Frozen Definitions for A2b Topology-Plan Derivation

Date: 2026-08-21 UTC
Turn type: **Planning / Review only.** No product, test, build, package, or runtime. Consumes no
acceptance attempt.
Status: **FROZEN, WITH TWELVE AMENDMENTS.** Sections 2–9 remain normative for `M3-CP4ab` and `M3-CP4c`
and may change only by an explicit plan update.

> **Retired-provenance note (added 2026-08-24 at CP4ab closure review).** Each amendment below names the
> independent review that authored it. Those per-turn review documents were **retired into
> `M3_CP4ab_Closure_Record.md`** when CP4ab closed; the files no longer exist. This was verified safe:
> every amendment inlines the content it froze, so **this document is self-contained and remains the
> implementation authority for `M3-CP4c`.** The citations are provenance only — do not go looking for
> the files, and do not treat a missing file as missing authority. Historical narrative for the retired
> documents is in `CHANGELOG.md`; the accepted outcome is in `M3_CP4ab_Closure_Record.md`.

**Amended 2026-08-22 by `M3-CP4b-MANDATORY-INDEPENDENT-REVIEW` (Part A of
`Architecture_M3_CP4b_Mandatory_Independent_Review_Plan.md` — RETIRED at CP4ab closure, binding):**

1. **The CP4a/CP4b split made by this document is withdrawn.** They are one checkpoint, `M3-CP4ab`,
   at the unchanged gate **316**. Region derivation and the disc proof are not independent semantic
   domains — the proof is a predicate on the regions — and splitting them put an accepted predecessor
   between the two halves, which obliged CP4b to preserve a partition that was wrong. Section 7.1 and
   7.2 remain correct as *identity definitions*; only their allocation to separate checkpoints is
   withdrawn. Section 7.3 (CP4c) is unchanged.
2. **Section 7.1 identities A1 and A3 as implemented were unfalsifiable and must be rewritten**
   under corrective measure K4. `CoversEverySourceFaceExactlyOnce` asserted only that ownership is
   total, which a flood fill guarantees by construction; it never asserted that a face's owner is the
   region whose boundary encloses it. Any rewrite that the superseded CP4a implementation would still
   pass is still vacuous.
3. **Section 6.3's rejection vocabulary is binding, not advisory.** The original thirteen
   locus-bearing codes remain frozen. CP4b emitted `RegionCoversNoSourceFace` at seven sites for
   seven distinct conditions and three immutable gates consequently localized nothing. Corrective
   measure K1 therefore extends that vocabulary by four condition-specific codes where no existing
   code can truthfully carry the required locus, and reuses an existing code only where its frozen
   meaning and locus match. The split lands alone, before any semantic change.

**Amended again 2026-08-22 by `M3-CP4ab-K5-ROUTING-REVIEW` (Part A of
`Architecture_M3_CP4ab_K5_Routing_Independent_Review_Plan.md` — RETIRED at CP4ab closure, binding):**

4. **Section 4.4 is amended.** A region is one face of the embedded graph and owns the set of **face
   fragments** it covers, where a fragment is the portion of one source face lying in one graph face,
   keyed `(SourceFaceTopologyKey, orbit)`. The prior wording — "plus the set of source faces it
   covers" — is **withdrawn as inconsistent with the product**: mandatory arcs run along source edges
   but **trace arcs cross face interiors**, and a source face is atomic, so whole-face ownership cannot
   express a graph face. On the accepted two-ring witness the entire singular fan collapses into one
   cut component while the rotation walk correctly reports one orbit per sector, which is why
   `cutComponents.size() == drafts.size()` is not merely self-referential but **unsatisfiable** on any
   witness carrying a singularity port. Under fragment ownership every source face's fragments
   partition it, which is a *stronger* exact-once rule than the withdrawn one. Ownership is derived only
   from the embedded network cut and oriented boundary evidence. The following inputs remain prohibited:
   **no container/map order; no BFS/distance/proximity; no arbitrary unclaimed-face fallback; no A0
   `SourceComponentId`/`TopologyRegionId`; no unsigned whole-trace support; no repair path.**

**Amended again 2026-08-23 by `M3-CP4ab-TB-R1-INDEPENDENT-REVIEW` (Part A of
`Architecture_M3_CP4ab_TB_R1_Independent_Review.md` — RETIRED at CP4ab closure, binding):**

5. **"Computes on fragments" is made exact.** Amendment 4 said the disc proof "now computes on
   fragments" without defining fragment adjacency or the meaning of `V`, `E`, `F` for a fragment
   complex. That under-specification is why `build_region_certificate(...)` was left computing on whole
   source faces and whole source edges, and why `M3-CP4ab-TB-R1` returned nine reds at
   `RegionInteriorDisconnected`. Review section 5 supplies the missing definitions and is normative:
   - **barrier vs crossing** — a mandatory `Boundary`/`HardFeature` edge is a true barrier; a trace
     crossing is a *subdivision point* that removes no interval and blocks no adjacency by itself.
     `network_cut_edges(...)` conflates the two and must no longer gate adjacency;
   - **fragment adjacency** — `(F1, o1)` and `(F2, o2)` sharing source edge `e` are adjacent **iff `e`
     is not mandatory and `o1 == o2`**. Fully combinatorial; no geometry, no interval ordering;
   - **Euler characteristic** — **WITHDRAWN, see amendment 6.** This clause froze `χ = F − E_int`,
     which is mathematically wrong for any region containing an interior source vertex;
   - **pinch rejection** — fragments sharing a 0-cell but no 1-cell are a typed rejection with its own
     frozen code and both source-face loci.

**Amended again 2026-08-23 by `M3-CP4ab-TB-R2-INDEPENDENT-REVIEW`
(`Architecture_M3_CP4ab_TB_R2_Independent_Review.md` — RETIRED at CP4ab closure, binding):**

6. **Amendment 5's Euler clause is WITHDRAWN and replaced.** `χ = F − E_int` is valid only when the
   fragment-dual graph is acyclic — it silently assumes the very property it was meant to test. The
   faces around an interior source vertex of valence `n` form an `n`-cycle in that dual graph, giving
   `F − E_int = 0` for a patch that is unambiguously a disc. Computed on the accepted CP3a two-ring
   witness this turn: `F − E_int = −5` where the true `χ = 1`. `M3-CP4ab-TB-R2`'s nine-identity
   `RegionEulerCharacteristicNotOne` baseline is therefore a **false rejection**; the regions are
   genuine discs.

   **The correct reduction is `χ = V_int − E_int + F`**, where `V_int` counts source vertices strictly
   interior to the region, `E_int` counts source-edge pieces strictly interior to it (one per adjacent
   fragment pair under amendment 5's adjacency rule), and `F` counts fragments. The boundary terms
   cancel because `V_bd = E_bd` for a single closed walk with no pinch — both preconditions are already
   validated upstream, and that dependency is what licenses dropping them. Verified this turn on two
   glued triangles (1), a pentagon fan (1), a hexagon fan (1), and the whole two-ring witness (1).

   A source vertex is **interior** iff it is incident to a fragment of the region, is not an endpoint of
   any **mandatory** arc on the region's boundary, and is not the `sourceVertex` of a singularity port
   whose trace arc lies on that boundary. `FieldAlignedCurveNetworkNode::sourceVertex` must **not** be
   used for this — section 3.2 records that for a contact node it is an arbitrary face vertex.

   Amendment 5's other three clauses — barrier vs crossing, fragment adjacency, and pinch rejection —
   are **unaffected and proven correct** by TB-R2, which cleared `RegionInteriorDisconnected`.

**Amended again 2026-08-23 by `M3-CP4ab-CB-R6-STATIC-AUTHORITY-INDEPENDENT-REVIEW`
(`Architecture_M3_CP4ab_CB_R6_Static_Authority_Independent_Review.md` — RETIRED at CP4ab closure, binding):**

7. **Fragment-corner incidence is defined, and needs no carrier-contact order.** Amendment 6 requires
   `V_int`, which requires knowing which fragment of a cut face carries each source corner. That is now
   frozen, and it is derivable from existing accepted authority — **no earlier product is reopened**:

   - **Taxonomy.** A source face carries at most **one full chord**: `field_aligned_first_trace_contact`
     (`SurfaceCellTracing.cpp:496-527`) terminates any later trace entering an occupied face. The sole
     exemption is two first-segments sharing a face, singularity, and source vertex, which is how a face
     comes to hold several rays from one origin.
   - **Terminal segments are slits, not cuts.** The trim at `:608-613` retains the contacting segment,
     so its non-optional `outgoingCarrier` names an edge the trace never reaches. A segment of a trace
     whose `terminalBarrier` is unset ends inside its face; **its `outgoingCarrier` must never be treated
     as a chord exit.** A slit does not separate and does not change corner incidence.
   - **One chord.** The chord separates the corner **shared by `incomingCarrier` and `outgoingCarrier`**
     from the other two. Total and unambiguous in a triangle.
   - **Co-facial rays at a shared origin — orbit-side chaining.** Walk the oriented fan around the vertex
     via `build_vertex_fan_slots(...)` carrying a running orbit label. A non-mandatory fan edge does not
     end the sector; a mandatory arc does; and inside a face holding *k* rays the next ray is **the
     unique one carrying the running label on a side**, crossing it advancing the label to its other
     side. The rays' intra-wedge order is never read — it is forced by orbit-label chaining. Uses only
     `walk.orbitByDart` and the oriented fan; no ID, no container position, no coordinate, no distance.
   - **Residual ambiguity is a typed rejection.** If two or more candidate rays carry the running label,
     the reconstruction is genuinely ambiguous: emit a frozen condition-specific code with the
     `SourceVertexId`, `SourceFaceTopologyKey`, and competing `NetworkArcId` loci. **Never break the
     tie.** Ordering by `TraceId`, `NetworkNodeId`, arc ID, segment index, container order, source row,
     or Euclidean position is prohibited — all are the arbitrary carrier order section 2.1 forbids.

   If that rejection ever fires, the ordered-contact relation must be owned by **A2a (the CP3b event
   graph)** — never by A2b, which would create a second writer for contact authority — under the exact
   re-proof boundary in the Review's section 8.

**Amended again 2026-08-23 by `M3-CP4ab-CB-R7-PRECONDITION-INDEPENDENT-REVIEW`
(`Architecture_M3_CP4ab_CB_R7_Precondition_Independent_Review.md` — RETIRED at CP4ab closure, binding and superseding amendment 7's order source):**

8. **Amendment 7's `orbitByDart` order source is WITHDRAWN as circular; its chord/slit facts remain.**
   `walk.orbitByDart` is computed *after* `build_rotation_system(...)`, and the current rotation breaks a
   co-facial-ray tie with `trace`/`arc`/`orientation` identifiers. It therefore cannot independently
   prove or reconstruct the ray order that created those orbits.

   - **Single writer:** A1 `FieldTransportAtlas` owns the missing singularity-ray order because
     `build_singularity_attachments(...)` already owns the `TriMesh`, deterministic ordered fan,
     canonical branch directions, branch-class partition, elected representatives, and published
     `FieldSingularityPortAttachment::localSlot`.
   - **`localSlot` semantic:** for one singularity, slots `0..valence-1` are the strict
     **fan-anchored counter-clockwise order of elected port representatives**. Equivalent-Z4 relabeling
     must preserve the published slot assignment. A non-strict/ambiguous order is an A1
     `AmbiguousBranchTopology` rejection, never an ID/container/source-row tie-break.
   - **Transport:** A2a `FieldAlignedSingularityPort::ordinal` carries that A1 slot unchanged; A2a is not
     a second writer and does not invent a contact ordinal.
   - **A2b rotation:** co-facial singularity trace rays consume the transported ordinal as semantic
     secondary order *before* face walking. Only after this is true may `walk.orbitByDart` be consumed
     for fragment-corner assignment.
   - **Corner facts retained from amendment 7:** a real one-chord segment separates the corner shared by
     its distinct incoming/outgoing carriers; a last segment with unset `terminalBarrier` is a slit and
     its retained `outgoingCarrier` is not a chord exit.
   - **No A2b ambiguity code is frozen by amendment 7.** Its Q2/Q4 combination was internally
     inconsistent because Q2 prohibited public-header changes while Q4 required a new public code and
     plural arc loci. Ordering failure belongs to the A1 writer instead.

   This reopens the **semantics** of the existing A1 port slot and therefore requires re-proof of the
   accepted CP2b/CP3a/CP3b surface on the successor package. No identity is removed or weakened.

**Amended again 2026-08-23 by `M3-CP4ab-DG-R3-INDEPENDENT-REVIEW`
(`Architecture_M3_CP4ab_DG_R3_Independent_Review.md` — RETIRED at CP4ab closure, binding):**

9. **Amendment 6's interior-vertex rule is CORRECTED: it omitted the mesh boundary.** DG-R3 measured
   `V_int=2 E_int=6 F=6 chi=2` for region 2/orbit 3 and `V_int=1 E_int=1 F=2 chi=2` for B3 — both off by
   exactly **+1** in `V_int`. The over-counted vertex on the two-ring witness is **outer-ring vertex 6, a
   mesh-boundary vertex** (`make_cp3a_two_ring_skew_disc` asserts `isBoundaryVertex != 0` for `6..10`).
   `E_int` and `F` are correct: a fragment-dual graph with `F = 6`, `E_int = 6` has cycle rank 1, so
   exactly one interior vertex is possible.

   **The rule text and its own verification table disagreed.** The TB-R2 Review computed `V_int` as *all
   source vertices minus mesh-boundary vertices* in every verified case, then froze the rule in terms of
   arcs on the region's walk. Those coincide only when every mesh-boundary edge touching a region appears
   as a mandatory arc on that region's own walk.

   **Corrected rule.** A source vertex is interior to a region iff **all** of:
   - **(a) it is not a mesh-boundary vertex** — no incident source edge has `incidentFaces.size() == 1`.
     **This clause is new and is the fix.** Derive it combinatorially from `SourceTopologyIndex`: no
     `TriMesh`, no `isBoundaryVertex`, no geometry, no public widening;
   - (b) it is not the `sourceVertex` of a singularity port whose trace arc lies on the region's boundary;
   - (c) it is not an endpoint of a mandatory arc on the region's boundary — still required, because it
     catches interior hard-feature rails that (a) does not;
   - (d) every fragment incident to it belongs to this region.

   A **mesh-boundary vertex's fan is a half-disc**, so the existing "every incident face owned" test is
   satisfiable while the vertex still lies on the region's topological boundary. That test cannot detect
   this case and must not be tightened in place of clause (a).

   **Ownership and walk must also be proven consistent.** Region 2 reaches outer-ring vertex 6 yet
   records **no mandatory boundary endpoints**, which is contradictory. Add a typed rejection: if any
   owned fragment lies in a face incident to a mesh-boundary edge, that edge's mandatory arc **must**
   appear on that region's boundary walk. Without it, clause (a) would make χ come out to 1 while
   ownership and the walk still disagreed — a green gate over an unfixed defect.

   Amendments 5, 7, and 8 are **unaffected and proven reached** by DG-R3:
   `RegionInteriorDisconnected` and `RegionCutComponentCountDeficit` are both absent, and the R7
   cyclic-order sanity checks are 3/3 PASS.

**Amended again 2026-08-24 by `M3-CP4ab-CB-R8-S0-INDEPENDENT-REVIEW`
(`Architecture_M3_CP4ab_CB_R8_S0_Independent_Review.md` — RETIRED at CP4ab closure, binding):**

10. **Section 4.1's arc definition is CORRECTED: mandatory arcs must be split at trace terminal points.**
    Section 4.1 defined the arc set as *"one mandatory arc per `FieldAlignedMandatoryEdge`"* while
    subdividing trace arcs at every incident event node. That asymmetry was never justified and is the
    defect `M3-CP4ab-CB-R8` stopped on.

    A trace terminating at a barrier has `terminalBarrier` set and reaches a point **interior** to that
    mandatory edge. That point is a genuine 0-cell: it separates the edge's two pieces into two different
    graph faces. With the edge unsplit, the whole arc lands in at most one orbit's walk and is absent
    from the other's — which is exactly why region 2 / orbit 3 owns fragments in faces incident to
    boundary edges `(6,7)` and `(6,10)` yet records `mandatory_boundary_endpoints=[]`.

    **Corrected definition.** A mandatory edge carrying `k` trace terminal points yields **`k + 1` arcs**,
    one per piece between consecutive 0-cells (edge endpoint or terminal node). Each piece keeps the
    parent edge's `SurfaceCellRailKind` and provenance to the originating `FieldAlignedMandatoryEdge`, so
    identity A4's mandatory-edge preservation still sees every mandatory edge. `k = 0` is unchanged.

    **The terminal node is a real graph node** of degree 3 — the incoming trace arc and the two mandatory
    pieces. Without it the rotation and face walk cannot turn onto the boundary, which is the mechanism
    by which the boundary arcs were lost.

    **`k = 1` needs no ordering**: the two pieces run from each edge endpoint to the terminal point, and
    each piece's owning region is given by the terminating trace's dart orbit on that side. **`k ≥ 2` is
    a typed rejection** with the `SourceEdgeTopologyKey` and competing `TraceId` loci — never an
    identifier or coordinate tie-break. If it is ever genuinely needed, the order belongs with amendment
    8's A1 authority, not A2b. On the accepted witness `k ≤ 1` everywhere.

    ~~**This correction is A2b-local.** The arc set is built in `GlobalTopologyPlan.cpp` from already
    published authority (`terminalBarrier`, `FieldAlignedMandatoryEdge`, `incidentFaces`, and the trace
    darts' orbits). **The CP3b product is not reopened.**~~ — **WITHDRAWN by amendment 11.** The terminal
    0-cell this rule splits at is not published by A2a, so the rule is not A2b-local. Everything else in
    amendment 10 stands.

    This is the third instance of one class — source faces atomic (fixed by amendment 4), non-mandatory
    edges atomic in adjacency (fixed by amendment 5), mandatory edges atomic in the arc set (this
    amendment). Amendment 9's `V_int` mesh-boundary exclusion and its companion ownership/walk
    consistency rejection remain required and are applied **after** this correction, at which point the
    consistency check is expected to be satisfiable rather than firing.

**Amended again 2026-08-24 by `M3-CP4ab-DG-R4-INDEPENDENT-REVIEW`
(`Architecture_M3_CP4ab_DG_R4_Independent_Review.md` — RETIRED at CP4ab closure, binding):**

11. **Amendment 10's A2b-locality claim is WITHDRAWN; A2a must publish every trace terminus as a real
    0-cell.** Amendment 10 assumed the interior barrier-contact node already existed. It does not. A2a
    binds both the `FirstContact` and the `MandatoryBarrierTermination` event to `mandatory->firstNode`
    (`SurfaceCellTracing.cpp:657-669`) — an **endpoint** of the mandatory edge — so CB-R9's correct
    endpoint rejection (`GlobalTopologyPlan.cpp:374-381`) fires on every barrier-terminating trace.
    Amendment 10's arc rule, `k + 1` piece count, degree-3 terminus, parent-edge provenance, and typed
    `k ≥ 2` rejection are all **retained**. Only the locality claim is wrong.

    **(a) A trace never exits through a vertex.** A2a's transport loop has exactly one exit primitive and
    it returns a `SourceEdgeTopologyKey` (`field_aligned_outgoing_carrier`, `SurfaceCellTracing.cpp:257-282`);
    termination occurs when that carrier is mandatory (`:385-390`). The terminus is therefore an interior
    point of the mandatory edge **by construction of A2a's own model**, and can never be an endpoint.
    Substituting an endpoint is prohibited.

    **(b) A2a is the single writer of network 0-cells, and already owns the mechanism.**
    `field_aligned_append_contact_node(...)` (`:528-537`) is already used for the trace/trace contact case
    (`:614-615`) and the loop-closure case (`:688`). The barrier case is the sole exception. Publishing the
    terminus introduces **no coordinate, no barycentric parameter, no ordinal, and no proximity test** —
    the node's `SourceVertexId` remains the placeholder frozen by section 3.2, and the locational datum
    (`sourceEdge = terminalBarrier`) is already on both events. A2b may **not** mint the node: `A2`
    requires `plan.rotation_system().size() == network.nodes().size()`
    (`tests/FieldAlignedCurveNetworkTests.cpp:1957`), and `build_node_loci` / `build_rotation_system`
    enumerate `network.nodes()` (`GlobalTopologyPlan.cpp:506`, `:774`).

    **(c) The edge locus is the frozen home of an interior terminus, and its cyclic order already exists.**
    `NodeLocus::edge` (`GlobalTopologyPlan.cpp:495-498`) is assigned to any node that is neither a
    singularity-port node nor a mandatory endpoint, from its events' `sourceEdge` (`:545-570`). The
    edge-locus rotation branch already requires exactly **two mandatory rays and degree three**
    (`:897-909`) and orders the three darts strictly — `primary 0` toward the second endpoint, `primary 2`
    toward the first (`:938-950`), the trace ray at `2·sideRank + 1` (`:983-986`) — with no identifier,
    container, or coordinate tie-break. That branch is **dead code under the current A2a product**. No
    further order authority is required at `k = 1`, and none may be invented.

    Note that `build_node_loci` discards a node's `sourceEdge` when the node already has a vertex locus
    (`:554`); this is exactly how the endpoint substitution destroys the terminus location.

    **(d) The global cellularity identity is not an oracle for terminus placement.** Publishing a terminus
    adds **+1 node and +1 arc**, so `V_g − E_g + F_g` is invariant
    (`tests/FieldAlignedCurveNetworkTests.cpp:1818-1826`). B4 is structurally blind to this defect, which
    is why CP3b's 304/304 accepted it. Terminus questions are settled by ownership and walk membership
    (A1, A3, B1) only — never by Euler.

    **(e) The re-proof surface is exactly one accepted constant.** `EXPECT_EQ(5U, network.nodes().size())`
    (`tests/FieldAlignedCurveNetworkTests.cpp:471`) becomes **8**. `validate_field_aligned_candidate` is
    recompute-and-compare (`SurfaceCellTracing.cpp:1144-1301`) and every digest assertion is relative, so
    both track the producer automatically. No accepted assertion binds the terminal node's identity.
    CP3b is reopened to that one constant plus a strengthening of
    `PublishesTypedFirstContactAndTerminationEvents` requiring the terminal node to differ from both
    endpoints. The CP4ab gate stays **316**.

**Amended again 2026-08-24 by `M3-CP4ab-DG-R5-INDEPENDENT-REVIEW`
(`Architecture_M3_CP4ab_DG_R5_Independent_Review.md` — RETIRED at CP4ab closure, binding):**

12. **Structural inputs must be validated before any consumer derives from them, and global cellularity
    on a bounded source surface must exclude the exterior orbits.** Two independent rules, both proven
    from DG-R5.

    **(a) Validation ordering.** No derived quantity — orbit election, fragment-corner incidence, χ, or a
    region certificate — may be the first authority to reject a defect in its own input. A candidate's
    structural inputs (per-region single closed boundary walk, canonical arc/rotation/boundary equality,
    canonical fragment ownership) are validated first; consumers run only on inputs already proven
    well-formed. Three instances of the violation are on record: `region_orbit` shadowing the
    interior-singularity check (fixed by the P4 hoist; B3 green), certificate χ shadowing canonical
    fragment ownership (A5), and `region_orbit` shadowing `validate_single_boundary_walk` (B2). The
    product's own comment at `GlobalTopologyPlan.cpp:2373-2374` names the single-walk validation as the
    reason χ's boundary terms cancel, while that validation is evaluated after the path that consumes it.
    Both open instances are **product** defects; neither tamper may be weakened to recover an expected
    enum, and no error code may be added or relaxed for them.

    **(b) Global cellularity on a surface with boundary.** A combinatorial dart-orbit face walk yields the
    faces of the graph embedded in the **closed** surface obtained by capping each source boundary
    component. For a source surface `S` with `b` boundary components the frozen identity is therefore

        V_g − E_g + F_g^interior = χ(S),   with F_g^interior = F_g^all − b

    equivalently `V_g − E_g + F_g^all = χ(S) + b`. `F_g^interior` is the region count. The independent B4
    oracle compares the all-orbits count against `χ(S)` and is wrong by exactly `b` on every bounded
    witness — `9 − 11 + 4 = 2 ≠ 1` on the two-ring disc after CB-R10, and `6 − 8 + 4 = 2 ≠ 1` before it,
    so the defect predates and is independent of the terminal-0-cell correction. The exterior orbits are
    already derived lawfully and geometry-free from `SurfaceCellRailKind::Boundary`
    (`tests/FieldAlignedCurveNetworkTests.cpp:1647-1652`); they must be excluded, never approximated by a
    constant, an orientation heuristic, or a geometric test. Amendment 11(d) is unaffected: the terminal
    0-cell correction remains Euler-neutral under either form.

    **(c) An independent oracle must publish a typed failure reason.** A bare boolean turns a red into a
    search and costs a diagnostic to localize. This applies to B4 and to any future independent oracle
    admitted to a gate.

Section 6's disc proof is unchanged in *content* and now computes on fragments as defined above, with χ
computed by amendment 6 as corrected by amendment 9, and corner incidence/order authority by
amendment 8; identity B2
(`RejectsRegionWithMultipleBoundaryWalks`) becomes reachable for the first time, because a two-walk
region is now representable and reaches the validator instead of aborting construction.

Sections 3, 5, 6, 8, and 9 are unaffected and were not contradicted by anything CP4a, CP4b, or CP4ab
found.

Incoming accepted authority: CP3b source/package `611b3f8f3926792baee9d1078d6677d22006a6c4 / 9456073195`,
immutable `M3-CP3b-TB` `32515222447 / 96875297990`, **304/304**. Accepted combined selector SHA-256
`c05a4c4329d7e01a47fd1ecb094be438595533bf90585b24b94a3c4221ffb666`.

## 1. Why this turn exists, and how to read this document

CP4 was a single checkpoint carrying three semantic domains plus witness production plus the cumulative
M3 exit gate. It is now four turns (this one plus CP4a/CP4b/CP4c). Two things had to be frozen before
any CP4 code could be written, and both are now settled here:

- the **per-region disc-topology proof had no definition** — plan section 2 criterion 6 and section 3
  A2b both require one and nothing defined it, which is the undefined-certificate shape plan section
  1.1.2 records M1 paying for twice;
- **CP4c's required torus witness appeared to collide with the open `G4-B001` blocker.** Section 9
  resolves this from the tracker and the source: **there is no collision.**

This document assumes no prior familiarity with the codebase. Every type, file, line, enum value, and
fixture named below was read at its cited location during this turn. Where a name in the existing code
means something *different* from what a CP4 reader would expect, that is called out explicitly rather
than left to be discovered.

**Three things in the accepted code will mislead you if nobody says them out loud.** Read section 3
before designing anything.

## 2. What A2b is, in one paragraph

CP3a/CP3b published a `FieldAlignedCurveNetwork`: singularity ports, mandatory boundary/hard-feature
edges, candidate traces, and a typed event graph. Geometrically that product is an **embedded graph
drawn on the source mesh**. A2b's job is to take the faces of that embedded graph and publish them as
`GlobalTopologyPlan` regions, each with a proof that it is a topological disc, such that M4 can later
schedule one shared rail sequence over them. A2b selects and derives; it never repairs the network.

## 3. Three facts about the accepted code that are not obvious

### 3.1 `TopologyRegionId` already exists and is NOT the CP4 region

`include/directional/authority/AuthorityIds.h:208` defines
`using TopologyRegionId = SemanticId<detail::TopologyRegionTag>;`, and it is used throughout
`SurfaceCellOwnership.h`, `PatchDescriptor.h`, `FlowRepStrands.h`, `RemeshPipeline.h`, and inside the
accepted CP3 product (`FieldAlignedSingularityPort::sourceTopologyRegion`,
`FieldAlignedCandidateTrace::sourceTopologyRegion`, `FieldAlignedMandatoryEdge::sourceTopologyRegions`).

**That is A0 *source* topology-region authority** — a partition of the source mesh by
`build_source_topology_regions(...)`, barriered by hard features. It is an **input** to CP4, not the
thing CP4 produces.

CP4's regions are faces of the *network* graph. They are a different semantic domain and **must get
their own ID type**. Do not reuse `TopologyRegionId`, and do not add a second meaning to it — that
would be exactly the single-authority violation plan section 7 lists as a stop condition. Section 5
gives the exact new-ID recipe.

### 3.2 A contact node's `sourceVertex` is a placeholder, not a location

`src/geometry/SurfaceCellTracing.cpp:528-535`, `field_aligned_append_contact_node(...)`:

```cpp
const std::size_t nodeIndex = candidate.nodes.size();
const auto node = authority::NetworkNodeId::from_index(
    static_cast<std::int64_t>(nodeIndex), nodeIndex + 1U);
if (!node) return std::nullopt;
candidate.nodes.emplace_back(node.value(), sourceFace.vertices().front());
```

`FieldAlignedCurveNetworkNode` (`SurfaceCellTracing.h:141-150`) carries exactly two fields — a
`NetworkNodeId` and a `SourceVertexId`. For a **contact** node that `SourceVertexId` is
`sourceFace.vertices().front()`: an arbitrary vertex of the face the contact happened in. It is not
where the contact is. Two distinct contacts in the same source face receive **distinct
`NetworkNodeId`s but identical `sourceVertex` values.**

Consequence, and this is binding: **CP4a must never use `FieldAlignedCurveNetworkNode::sourceVertex` to
locate, order, or identify a contact node.** Doing so silently merges distinct junctions and produces
wrong region boundaries with no error anywhere.

The information you actually need is on the **event**, not the node.
`FieldAlignedNetworkEvent` (`SurfaceCellTracing.h:265-283`) carries `node`, `kind`, `sourceFace`, an
optional `sourceEdge`, and `incidences`. Build all locational reasoning from events.

### 3.3 `FieldAlignedNetworkEventKind::SingularityTermination` is declared and never produced

`SurfaceCellTracing.h:243` declares `SingularityTermination = 4`. A repository-wide search over
`src/`, `include/`, and `tests/` finds **exactly one occurrence — that declaration.** Nothing produces
it and nothing tests it.

This matters because plan section 2 criterion 5 requires that every trace terminate at a typed event
"(existing trace, boundary, hard feature, **singularity**)". A trace that runs into another
singularity currently has no representable terminal kind that is actually emitted. This is a real
unowned obligation, not a cosmetic one, and section 7 assigns it to CP4c identity C5.

## 4. The embedded graph whose faces become regions

This is the definition CP4a implements. It is frozen.

### 4.1 Arcs

The graph's arcs are of exactly two kinds, and no others:

1. **Mandatory arcs** — one per `FieldAlignedMandatoryEdge` in `network.mandatory_edges()`
   (`SurfaceCellTracing.h:285-308`). Each already carries a `NetworkEdgeId`, its
   `SourceEdgeTopologyKey`, its `SurfaceCellRailKind` (`Boundary` or `HardFeature`), and its two
   endpoint `NetworkNodeId`s. These are the source boundaries and hard features.
2. **Trace arcs** — obtained by cutting each `FieldAlignedCandidateTrace`
   (`SurfaceCellTracing.h:215-236`) at every event node incident to it. A trace from its origin port to
   its first contact is one arc; from that contact to the next is the next arc; and so on to its
   terminal. A trace with no interior contact contributes exactly one arc.

Trace arcs are **new** typed objects. Do not overload `NetworkEdgeId`, which is already the mandatory
edge's domain.

### 4.2 Nodes

Nodes are exactly `network.nodes()`. Every node is either a singularity-port origin node or an event
node; both already exist in the accepted product. CP4 adds no nodes and merges none. Subject to §3.2,
identify nodes only by `NetworkNodeId`.

**Amendment 11 qualifies this.** "CP4 adds no nodes" remains binding for **A2b** — `GlobalTopologyPlan`
must never mint a `NetworkNodeId`. It is **not** a statement that A2a's published node set is complete:
A2a does not publish a 0-cell for a barrier terminus, and amendment 11 requires it to. The node set grows
in **A2a**, upstream of this section.

### 4.3 The rotation system — a CP4a prerequisite, not deferred debt

To compute the faces of an embedded graph you need, at every node, the **cyclic order of its incident
arcs** in the surface's orientation. That is the rotation system. Faces are then the orbits of the
"next arc clockwise after the reversal" permutation — the standard face-walk.

`M3_CP3_Closure_Record.md` section 6 recorded rotation-system/face-walk consistency as CP3b debt and
placed it in CP4c. **That placement was wrong and is corrected here:** it is not a nice-to-have proof
obligation that can wait for the exit gate, it is the input CP4a cannot compute regions without.
CP4a must **derive and publish** the rotation system (identity A2); CP4c separately **proves it on
produced witnesses** (identity C3). Both are needed; they are not duplicates.

Derive the rotation at a node from source-attached data only:

- for a mandatory arc, from its `SourceEdgeTopologyKey` and the incident `SourceFaceTopologyKey`s;
- for a trace arc, from the incident segment's `sourceFace`, its `outgoingCarrier` /
  `incomingCarrier`, and — where a face is crossed — its `entryTransport`
  (`FieldAlignedCandidateTraceSegment`, `SurfaceCellTracing.h:194-213`).

Order arcs around a node by walking the source fan of the node's incident faces. Do **not** order them
by any floating-point angle: this project has four recorded instances of geometry-derived fixture
degeneracy, and an angle comparison here would be a fifth waiting to happen. The fan walk is exact
integer/topological work.

### 4.4 Regions

A **region** is one face of that embedded graph: a cyclic boundary walk of arcs, plus the set of source
faces (`SourceFaceTopologyKey`) it covers. Every source face belongs to exactly one region — this is
CP4a identity A3, and it is the coverage property everything downstream relies on.

## 5. The region product and its ID domain

### 5.1 The new ID

Add a `NetworkRegion` domain following the existing pattern exactly. In
`include/directional/authority/AuthorityIds.h`:

1. add `NetworkRegion,` to `enum class AuthorityDomain` (currently at `:23-46`), appended **after
   `QuotientClass`** so no existing enumerator's value changes;
2. add, in `namespace detail` beside `NetworkEdgeTag` (`:128-130`):
   ```cpp
   struct NetworkRegionTag {
     static constexpr AuthorityDomain domain = AuthorityDomain::NetworkRegion;
   };
   ```
3. add, beside `NetworkEdgeId` (`:217`):
   ```cpp
   using NetworkRegionId = SemanticId<detail::NetworkRegionTag>;
   ```

`SemanticId` (`:158-201`) has a deleted default constructor and is constructed only through
`from_index(value, extent)` / `from_domain_index(domain, value, extent)`, both returning
`DomainResult<SemanticId>`. `index()` is a representation projection and is never a semantic identity.
Do a domain-typed arc ID the same way if you add one.

### 5.2 The product

`GlobalTopologyPlan` has **zero occurrences** in `src/`, `include/`, and `tests/` — verified this turn.
It is genuinely new.

- Header: `include/directional/geometry/GlobalTopologyPlan.h`
- Source: `src/geometry/GlobalTopologyPlan.cpp`, registered in `CMakeLists.txt` in the
  `src/geometry/...` block (alphabetically it sits just after `src/geometry/FlowRepStrands.cpp`; the
  block runs from about `CMakeLists.txt:165`) so it builds into `directional_core`.

Follow the accepted `FieldAlignedCurveNetwork` shape exactly, because it is the idiom every M3 gate has
accepted and because CP4b's negatives depend on it:

- a mutable `GlobalTopologyPlanCandidate` struct that is explicitly **not** authority, exposed solely
  so tamper negatives have a seam — mirror the comment at `SurfaceCellTracing.h:310-315`;
- `static ... make(...)` building from accepted inputs, and
  `static ... make_from_candidate(...)` accepting a candidate — **construction is the only validation
  seam**;
- a `...BuildResult` class exposing `has_value()`, `explicit operator bool()`, `value()`, `error()`
  (mirror `FieldAlignedCurveNetworkBuildResult`, `SurfaceCellTracing.h:421-444`);
- an error struct carrying a code **plus optional loci** — mirror `FieldAlignedCurveNetworkError`
  (`:130-139`), which carries `sourceVertex`, `sourceEdge`, `rail`, `singularity`;
- `validation_candidate()` returning a round-trippable candidate;
- `source_digest()`, `network_digest()`, `semantic_digest()`.

### 5.3 The digest split is mandatory and is not optional style

CP3a lost a diagnostic round to exactly one defect here, and the fix is now accepted behaviour:
`src/geometry/SurfaceCellTracing.cpp:1351-1364` feeds
`fieldTransportAtlas.branch_topology().semantic_digest()` (gauge-invariant) into the semantic digest
while keeping `authority::field_transport_atlas_hash(...)` (gauge-**dependent**) as a separate binding
digest.

`GlobalTopologyPlan` must do the same one level up: its `semantic_digest()` consumes the network's
`semantic_digest()`, **never** its `atlas_digest()`. Fold provenance into a separate binding field.
If you fold a gauge-dependent value into semantic identity, identity A6's relabel-invariance assertion
will fail and you will spend an attempt rediscovering a solved problem.

## 6. The disc-topology proof — frozen construction

### 6.1 What is proven

A region is a **topological disc** iff, over the region's closure:

1. its **boundary is a single closed walk** — exactly one boundary component;
2. its covered source faces are **connected** through source adjacencies that no network arc crosses;
3. its **Euler characteristic is 1**, computed as `χ = V − E + F` over the region's covered source
   faces, the source edges incident to them, and the source vertices incident to those, with boundary
   incidences counted once per the boundary walk;
4. it contains **no singularity in its interior** — every `FieldSingularityId` reachable in the region
   lies on its boundary walk.

### 6.2 Sufficient *and* necessary — say so, and say why

The A1 `FieldQuadrangulabilityCertificate` deliberately claims only a **conservative sufficient**
holonomy witness (`FieldQuadrangulabilityWitnessKind::ClosedShenSufficient`,
`FieldTransportAtlas.h:54-57`; plan section 3 A1 states the gcd condition is not claimed necessary).
**Do not copy that hedge here.** Conditions 1–3 are necessary *and* sufficient for a compact connected
surface-with-boundary to be a disc; that is a theorem, not a heuristic, and the inputs are exact
integer combinatorics on the source mesh with no tolerance anywhere.

Condition 4 is different and must be labelled honestly. A cone point is still *topologically* a disc.
Condition 4 is not part of the topological claim; it is the additional **field-regularity** requirement
that makes a region quadrangulable. State it in the code and in the report as a separate named
requirement, not as part of the disc proof, or the certificate will be attesting to two things under
one name — the single-authority defect that cost CP2b and CP3a a round each.

### 6.3 Rejection reasons — exhaustive, each naming its locus

CP2b lost three turns of review to a diagnosability collapse: 21 distinct `nullopt` sites folded into
two opaque codes while the product was already carrying the locus fields it discarded. Do not repeat
it. Freeze this enum, and populate every locus listed:

| Code | Locus fields to populate |
|---|---|
| `RegionBoundaryNotSingleWalk` | region, the arc starting the second boundary component |
| `RegionInteriorDisconnected` | region, the two `SourceFaceTopologyKey`s that do not connect |
| `RegionEulerCharacteristicNotOne` | region, computed `χ`, and the `V`/`E`/`F` counts |
| `RegionContainsInteriorSingularity` | region, `FieldSingularityId`, `SourceVertexId` |
| `RegionCoversNoSourceFace` | region |
| `RegionSourceFaceUnowned` | `SourceFaceTopologyKey` |
| `RegionSourceFaceMultiplyOwned` | `SourceFaceTopologyKey`, both `NetworkRegionId`s |
| `RegionBoundaryArcNotOwnedByNetwork` | region, arc |
| `MandatoryEdgeNotOnAnyRegionBoundary` | `NetworkEdgeId`, `SourceEdgeTopologyKey` |
| `RotationSystemInconsistent` | `NetworkNodeId`, the arc whose successor is wrong |
| `InvalidNetworkBinding` | — (network digest mismatch) |
| `InvalidSourceBinding` | — (source digest mismatch) |
| `InvalidRegionCertificateBinding` | region (tampered/absent certificate) |
| `EmbeddedGraphHasNoInteriorFace` | a `NetworkArcId` on the walked embedded graph (all walked faces classified exterior) |
| `RegionCutComponentCountDeficit` | the first `NetworkRegionId` graph face for which no distinct network-cut component exists under the current K1-only construction |
| `RegionBoundaryEvidenceMissing` | region |
| `RegionElectedCutComponentEmpty` | region |

The four final rows are the K1 extensions explicitly authorized by the mandatory independent Review.
They distinguish conditions for which the original thirteen cannot be used without inventing a locus
or overstating what has been proved. In particular, an all-exterior face walk does not identify a
wrong rotation successor, so it is not `RotationSystemInconsistent`; a region with no boundary-side
evidence does not establish a particular unowned source face, so it is not
`RegionSourceFaceUnowned`. `RegionBoundaryArcNotOwnedByNetwork` is used for an oriented trace dart
with no side component, `RegionInteriorDisconnected` carries two source-face representatives when
boundary evidence conflicts across cut components, and `RegionCoversNoSourceFace` is reserved for
candidate validation where a concrete region actually has an empty `sourceFaces` set.

Add a `..._error_code_name(...)` free function returning the enumerator's exact spelling, mirroring
`geometry::field_aligned_curve_network_error_code_name(...)` used at
`src/pipeline/RemeshPipeline.cpp:6595`. Every CP4 test that expects a rejection must assert the
**exact code**, and diagnostic-gate output must print it. A test that only asserts `ASSERT_FALSE(built)`
tells a reviewer nothing about which guard fired — `LESSONS.md` section 3 opens with exactly this.

### 6.4 The independent oracle — factory-free, test-only

Mirror what CP3b did and what its accepted gate proved (`tests/FieldAlignedCurveNetworkTests.cpp`,
`independent_trace_event_composition_oracle`, around `:1060-1180`): a **test-only** function that
recomputes the answer from the published product and **never calls the production validator**.

For CP4b the oracle must, from the published arcs, rotation system, and region membership alone:

1. re-walk the faces independently and check the walk it obtains matches the published regions;
2. recompute `χ` independently from the source-face/edge/vertex incidences;
3. independently confirm one boundary component and interior connectivity;
4. compare its verdict against each published region certificate.

Keep it in `tests/FieldAlignedCurveNetworkTests.cpp` or a new `tests/GlobalTopologyPlanTests.cpp`. If
you add a new test file it **must** be added to `DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES` in
`cmake/DirectionalTests.cmake:69-83`, or the identities will not be built and the gate will silently
run fewer tests than the selector names.

## 7. Frozen identities, counts, and gates

Six identities per checkpoint, matching the accepted CP1/CP2/CP2b/CP3a/CP3b rhythm. **These names are
frozen.** If implementation shows a name no longer describes its contract, correct it in planning and
re-freeze — never rename inside a Code + Build turn.

### 7.1 `M3-CP4a` — gate **310 = accepted 304 + 6**

| | Identity |
|---|---|
| A1 | `GlobalTopologyPlan.DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph` |
| A2 | `GlobalTopologyPlan.PublishesRotationSystemConsistentWithNetworkEvents` |
| A3 | `GlobalTopologyPlan.CoversEverySourceFaceExactlyOnce` |
| A4 | `GlobalTopologyPlan.PreservesMandatoryBoundaryAndHardFeatureEdges` |
| A5 | `GlobalTopologyPlan.RejectsForeignNetworkBindingOrTamperedRegionOwnership` |
| A6 | `GlobalTopologyPlan.RegionAuthorityIsInvariantToEnumerationOrderAndBranchRelabeling` |

File surface: `AuthorityIds.h`, `GlobalTopologyPlan.h`, `GlobalTopologyPlan.cpp`, the test file,
`CMakeLists.txt`, `cmake/DirectionalTests.cmake`. **`src/pipeline/RemeshPipeline.cpp` is frozen for
CP4a and CP4b** and enters the surface only at CP4c.

### 7.2 `M3-CP4b` — gate **316 = 310 + 6**

| | Identity |
|---|---|
| B1 | `GlobalTopologyPlan.ProvesDiscTopologyForEveryEmittedRegion` |
| B2 | `GlobalTopologyPlan.RejectsRegionWithMultipleBoundaryWalks` |
| B3 | `GlobalTopologyPlan.RejectsRegionWithWrongEulerCharacteristicOrInteriorSingularity` |
| B4 | `GlobalTopologyPlan.IndependentDiscProofOracleAgreesWithPublishedCertificates` |
| B5 | `GlobalTopologyPlan.RejectsTamperedDiscProofCertificate` |
| B6 | `GlobalTopologyPlan.UnestablishedFieldTransportCannotProduceATopologyPlan` |

### 7.3 `M3-CP4c` — the M3 exit gate, **322 = 316 + 6**

| | Identity |
|---|---|
| C1 | `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath` |
| C2 | `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` |
| C3 | `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` |
| C4 | `FieldAlignedCurveNetwork.RejectsTamperedTraceIntersectionCrossing` |
| C5 | `FieldAlignedCurveNetwork.EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced` |
| C6 | `GlobalTopologyPlan.ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation` |

C3, C4, and C5 are the previously-unowned obligations. C4 and C5 are named on
`FieldAlignedCurveNetwork` rather than `GlobalTopologyPlan` because they test the CP3b product; that is
deliberate and is not a scope violation — CP4c is the cumulative exit gate and owns section 2's
criteria wherever they live.

### 7.4 B6 — read this before implementing it, it is the easiest way to lose the checkpoint

Plan section 4A.3 B4 says "represent A1 certificate failure as the architecture's
`FieldTransportUnestablished` catastrophic precondition rather than deferring it to M4."

`FieldTransportUnestablished` is a **D4 catastrophic disposition** in `DESIGN.md` section 2.3's closed
enumerated set. **The disposition tier machinery (D0–D4) is M7 work and does not exist yet.** M1
criterion 5 was authored in terms of a disposition tier scheduled for M7 and made M1 unclosable by
construction; `LESSONS.md` section 6 opens with that lesson. Do not build D4 machinery in M3.

What already exists: `FieldTransportAtlas::make(...)` **already rejects** an unestablished field, with
`FieldAtlasBuildErrorCode::UnestablishedAdmissibility` (`FieldTransportAtlas.h:73`, raised at
`src/authority/FieldTransportAtlas.cpp:1674` and `:1730`), and
`FieldQuadrangulabilityCertificate::established()` (`FieldTransportAtlas.h:204`) is the published
predicate.

So the M3-scope obligation is **structural and negative**, not a disposition implementation: prove
there is **no path** by which a `GlobalTopologyPlan` is produced from an atlas whose certificate is not
established, and that no degraded producer or local substitution exists to route around it. That is
what B6 asserts, and it is fully provable today. Record in the CP4b report that the D4 *tier* remains
M7's, with this named as the M3 equivalent — the handoff's standing rule that earlier milestones use
the equivalent stated in their own gate.

### 7.5 Section 2 criterion → identity map

This table is the point of the whole exercise. `M3_CP3_Closure_Record.md` section 6 records that CP3b's
prose obligation list and its frozen selector were never reconciled, so two obligations ended up with
no owning identity and a green gate proved neither. Nothing in a green result reports what the selector
forgot to ask. **Before freezing each CP4 package, re-walk this table and confirm every row still has a
live owner.**

| Plan section 2 criterion | Proven by |
|---|---|
| 1. Field precondition explicit at A1 | accepted CP1 + **B6** |
| 2. Singularity ports typed and complete | accepted CP2 |
| 3. Mandatory topology first-class | accepted CP2 + **A4**, **C6** |
| 4. Tracing branch-consistent | accepted CP3a |
| 5. Network geometry structurally clean | accepted CP3b + **C3**, **C5** |
| 6. Topology regions derived, disc proof per region | **A1**, **A3**, **B1**–**B5**, **C6** |
| 7. Reduction preserves required topology | **A4**, **C6** |
| 8. Metamorphic invariance | accepted CP2/CP3a/CP3b + **A6** |
| 9. Independent/tamper evidence | accepted CP3a/CP3b + **A5**, **B4**, **B5**, **C4** |
| 10. Frozen predecessor green | the 322 selector as a whole |

## 8. Witnesses — provenance and self-asserted preconditions

### 8.1 Reuse; do not author

Both representative witnesses **already exist as committed fixtures**, verified this turn:

- `benchmarks/fixtures/milestone-g/torus.obj` + `torus.rawfield`
- `benchmarks/fixtures/milestone-g/mechanical_feature.obj` + `mechanical_feature.rawfield`

`tests/TestFixturePaths.h:66` provides `directional::tests::benchmark_fixture_path(...)`.

More usefully, `tests/SurfaceCellTransitionQuotientTests.cpp:512-541` already contains
`make_torus_pipeline_fixture()`, which reads that fixture and drives it through the **production entry
path** `directional::pipeline::remesh_from_raw_cross_field(...)` with
`fallbackPolicy = SurfaceCellFallbackPolicy::Fail` and `allowSourceGridRecovery = false`, then requires
`result.surfaceCellContext.hasTraceNetwork`. Its `read_rawfield(...)` helper is at `:261`. That file is
in the **same CMake target** as `FieldAlignedCurveNetworkTests.cpp`
(`cmake/DirectionalTests.cmake:69-83`), so the pattern is directly reusable.

Copy that pattern for both witnesses. Do not hand-author a torus.

### 8.2 Preconditions each fixture asserts about itself

This is the control that broke the four-checkpoint degenerate-fixture streak, and it is binding. The
accepted CP3a fixture is the model: `tests/FieldAlignedCurveNetworkTests.cpp:304-330`,
`make_cp3a_two_ring_index_one_field(...)`, asserts at runtime that **every** singular-fan opposite
carrier is interior — the exact capability the previous witness silently lacked — plus that there is
exactly one interior singularity after filtering boundary rows, and that an independently reconstructed
index equals the producer's.

Each CP4c witness must assert, before any target assertion becomes required-green evidence:

1. the network published **at least one region with more than one covered source face** — otherwise
   region derivation is vacuous;
2. **at least two distinct regions exist** — otherwise coverage and boundary-sharing prove nothing;
3. for the torus: **genus is actually 1**, from the source Euler characteristic, and at least one
   region boundary uses a non-trivial cycle — otherwise the "periodic/torus-style" claim is unearned;
4. for the mechanical witness: **at least one `SurfaceCellRailKind::HardFeature` mandatory edge exists
   and lies on a region boundary** — otherwise "feature-bearing" is unearned;
5. the quadrangulability certificate is `established()`.

`LESSONS.md` section 2 now states the general rule directly: a witness proven adequate for one
checkpoint's contract is not thereby adequate for the next one's, and a non-vacuity requirement is only
as good as the check that the witness can satisfy it. CP3a's plan directed reuse of the CP2b fan on the
strength of a green gate; every edge opposite that fan's singular vertex is a boundary edge, so the
required multi-face traversal was unsatisfiable on that mesh by construction. Re-derive capability
against **CP4's** contract, and encode the result as a runtime assertion.

## 9. The `G4-B001` collision — resolved, no collision

**Finding: CP4c's torus witness does not touch the `G4-B001` seam. It is not an M3 exit prerequisite.**

This was checked against the tracker and the source rather than assumed:

- `Regression_Root_Cause_Tracker.md:1043` classifies `PR8-R034 / G4-R007` as
  `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY`; `:1045` records the authority as "direct torus 0/3 with 241
  `LocalSheetMismatch` issues **after 192 quads**".
- `:734` locates the root cause precisely: the production path calls
  `classify_source_surface_labels(..., hardFeatureRailEdges, ...)` and publishes its `localSheetByFace`
  as `sourceFaceSheets`; the supplied barrier set terminates local-sheet adjacency, so a hard rail is
  incorrectly promoted into `IsolationSheetId` authority, and
  `close_completion_lineage_source_authority(...)` then rejects the opposite-side chart with
  `LocalSheetMismatch`.

That is **completion/materializer-stage** work — isolation sheets, chart lineage closure, and quad
emission. It is downstream of A2b topology planning. The evidence that the torus reaches trace
authority intact is that `make_torus_pipeline_fixture()` requires
`result.surfaceCellContext.hasTraceNetwork` and calls `require_produced(...)`, both of which throw on
failure, and that fixture is in an accepted, currently-building test target.

So the first of the three options section 4A.3 posed is the true one: **the M3 topology-network witness
exercises a path that stops before the `G4-B001` seam.** CP4c's witnesses must therefore assert
regions and disc proofs and **stop there** — they must not run to final quad emission, and CP4c must
not claim any `G4-B001` progress. Plan section 8's prohibition on claiming its closure by unrelated
network green stands unchanged, and `G4-B001` remains an open product blocker owned later.

Record this reasoning in the CP4c report so the question is not re-litigated.

## 10. Budget and cadence

> **ABOLISHED 2026-08-25 by user authorization.** The attempt budget, the diagnostic-gate cap, the
> mandatory-review-on-third-red ratchet, and the **`DG` turn type** no longer exist. The workflow is
> `CB → TB → (red) → REVIEW+PLAN → CB`; a red TB consumes nothing and mandatorily routes to review. The
> text below is retained as historical context only and must not be treated as live procedure. See
> `Future_Chat_Session_Handoff.md` "Turn workflow" and
> `M3_CP4c_Consolidated_Record.md` §3b (retired CP4c parent TB-R1 review).

Each of CP4a, CP4b, CP4c holds its own **3-attempt budget** (one attempt = one complete
Code + Build → immutable TB pair) with its own mandatory-review ratchet and its own cap of 2
diagnostic gates. This DEFN turn consumes nothing.

**Allocate a diagnostic gate to CP4a and to CP4c.** Both introduce new witnesses, and the diagnostic
gate is the control that has demonstrably paid for itself: CP3a's red 2/6 diagnostic bought a full
round of semantic evidence and a corrective build for zero acceptance attempts, and CP3a then closed
on attempt 1 of 3. CP4b consumes accepted CP4a authority and reuses its witness, so it may go straight
to acceptance.

Cumulative M3 cost stands at **21 packages**, reported only. Stable accounting is **41 / 14 / 27** and
produced-witness debt is **5**; this turn changes neither.

## 11. Standing stop conditions specific to CP4

Stop and return to Review rather than patching around any of these:

- a second writer appears for region or topology-plan authority;
- `TopologyRegionId` acquires a second meaning, or CP4 regions are represented by raw indices or
  parallel arrays instead of `NetworkRegionId`;
- a region's disc proof is repaired, downgraded, or retried rather than typed-rejected;
- rotation order is decided by a floating-point angle comparison rather than an exact fan walk;
- a gauge-dependent digest is folded into `GlobalTopologyPlan::semantic_digest()`;
- CP4 mutates, weakens, or reconstructs accepted CP3a/CP3b product or test authority;
- D0–D4 disposition machinery is introduced in M3 (see 7.4);
- a witness cannot satisfy a non-vacuity requirement and the requirement is weakened rather than the
  witness replaced.

## 12. Exact successor

Exact next is **`M3-CP4a-CB`** — Code + Build only, under sections 4, 5, and 7.1 of this document.
Author the product and the six frozen A-identities, hold the file surface in 7.1, run the mandatory
pre-package compile, create one immutable package, and stop. `runtimeExecution=false`. Package creation
consumes no attempt. Its successor is the attempt-free `M3-CP4a-DG`.

Do not begin CP4a inside this planning turn.
