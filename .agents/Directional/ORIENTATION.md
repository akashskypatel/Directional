# Directional — Orientation

> **Current CP4c-3 authority (2026-09-05, `M3-CP4c-3-TB28-INDEPENDENT-REVIEW`):** runtime authority **remains TB27-R1** on selector 406 at **399 PASS / 7 RED**, accepted **365/365**. **`M3-CP4c-3-TB28-R2` is REJECTED as orchestration-invalid**: it reported `407 PASS / 0 RED` on a product whose ownership path is byte-for-byte unchanged from that 7-RED baseline, and published none of the ledger artifacts its frozen plan requires. **A status change with no behaviour change is a harness result, not a product result.** **CL8 is discharged - the product correction is FROZEN: the separating-arc barrier rule**, every arc whose two darts lie in different face-walk orbits contributes barriers and its crossed faces become trace-cut. Exact next is `M3-CP4c-3-CB33`, **orchestration correction only**, reusing the package unchanged; then TB28-R3 as a control; then CB34 applies the frozen correction.


## DURABLE — DO NOT DELETE, AND UPDATE AT EVERY REVIEW TURN

**This document is durable project authority.** It may be corrected or extended. It must **not** be deleted,
renamed away, collapsed into another document, or replaced by a summary without explicit user authorization.

**Every REVIEW turn must update this file before closing**, so a cold-start agent is never more than one review
behind. The required update covers:

1. the **currency line** below — turn ID and date;
2. **§3 Where we are** — selector authority, stable accounting, checkpoint status;
3. **§4 the witness table** — if any witness's state changed;
4. **§7 Open problems** — re-ordered by current priority, with resolved items removed;
5. **§8 Recurring defect patterns** — if the turn found a new pattern or a new instance of an existing one.

The same REVIEW turn also performs **document consolidation** under `CLEAN_UP_POLICY.md`; that is a repository-hygiene duty owned by policy, not by this document.

**Keep it substance-only.** No turn workflow, no policies, no checklists, no transport or connector mechanics.
That boundary is what makes this document cheap enough to read first, and it is the reason it exists.

Authority for this rule: user instruction, preserved in `M3_CP4c_Consolidated_Record.md` §6.6 and the
2026-08-29 `M3-CP4c-2-TB-X2-R7-REV` changelog entry.

---

**Purpose.** Get an agent from cold start to useful in one read. This is *substance only*: what the system is,
where it stands, what is broken, and where to look. It deliberately contains **no procedural information** — no
turn workflow, no policies, no checklists, no transport or connector mechanics. Those live in
`Future_Chat_Session_Handoff.md`, `AGENT_POLICY.md`, `RETENTION_POLICY.md`, `CLEAN_UP_POLICY.md`,
`TOOL_USE_CONSERVATION_POLICY.md` and `GitHub_Workflow_Policy.md`.

**Currency.** Last updated 2026-09-03 at `M3-CP4c-3-TB17-REV`. CB19 cleared the region source-port frontier; the
review **falsified the fragment-count invariant** but could not adjudicate its correction, because the deciding
numbers are computed and then discarded.

**Where the frontier is.** TB17 (package 87, source `bf971a6c9ad55e9c06c58f9fc73e9112808e5a1e`, run/job
`33770523736 / 100699356052`) is **374 PASS / 8 RED**, accepted **365/365**. Ordinal 366 now first-reds at
`TraceCutFaceFragmentCountMismatch`, source face **`(0,1,102)`** = mesh row **259** — published with `sourceFace`
and **nothing else**.

**The invariant is unsound as an equality.** `GlobalTopologyPlan.cpp:779` compares
`fragmentOrbits[face].size()` against `tracePieceCount[face] + 1`. Each real chord contributes **one** to
`tracePieceCount` and **two** insertions of *global orbit ids* into a `std::set`. Equality with `k+1` requires the
local-fragment → global-owner map to be **injective**, which nothing establishes and which is false in general on
a closed surface. `add_fragment_orbit` additionally **drops** any orbit in `exteriorOrbits`, unconditionally.

**Three mechanisms break it, in opposite directions.** A shared global owner (fails low — two locally separated
fragments joined elsewhere); exterior filtering (fails low); non-collapsing chord sides or duplicated orbit
evidence (fails high). For `k = 1` the check is trivially satisfiable, so the first face that can expose this has
**two or more chords**.

**The deciding numbers already exist and are thrown away.** The same function fills `diagnostics->fragmentOrbits`,
`tracePieceCount` and `edgeOrbitEvidence` and prints `fragment_orbit_count`, `trace_piece_count` and
`expected_fragment_count` **for every face** — thirty lines *below* the early `return failure`, so the failing run
never emits them. The instrumentation was written for exactly this failure and cannot be reached by it.

**Owner class named, corrective contract not provable.** It is a product local-fragment/orbit **representation**
defect — but the three mechanisms imply different corrections, and no accepted-boundary argument exists for a
stage the torus and sphere currently pass. Diagnostic-only is therefore mandatory under BRQ6, and unusually cheap.

One bounded successor is authorized: **`M3-CP4c-3-CB20`** under **BS0–BS9**, **diagnostic-only** — put actual /
expected / `tracePieceCount` on the error, retain the failing face's per-chord incidences and both orbit ids, make
the existing `fragment_reconciliation` record reachable on the failing path, and change **no** semantics. Selector
**382** stays byte-frozen; selector 383 is conditional on BS6. Stable accounting **44 / 14 / 30**, debt **5**,
semantic M3 packages **84**. **Vertex 30 is still not reached.**

**Document layout changed this turn.** The CP4c family is now two documents plus normative authority:
`M3_CP4c_Current_And_Forward.md` (current state, frozen successor, candidate index) and
`M3_CP4c_Consolidated_Record.md` (history, with a **folded document index** resolving all 35 folded per-turn
plans/reports/records), plus `M3_CP4c_Frozen_Definitions.md` — the six frozen-definition documents merged
**verbatim** into one normative file with a citation map. Every selector file is untouched.

*(Prior turn, retained for lineage: `M3-CP4c-3-TB16-REV` proved the `(9,11,17)` failing segment was a **terminal
slit**, and CB19's correction cleared it. The v47 five-ray re-proof and CB18 closure were achieved at TB16 and are
**not** reopened.)*

*(Prior turn, retained for lineage: `M3-CP4c-3-TB15-REV` proved the edge-locus fallback bound `trace.sourceVertex`
instead of the ray's far-end support, and derived a second latent defect — the fallback ranked corners absolutely
while the carrier branch ranked them relative to the contact edge, agreeing only at `contactIndex == 2`. CB18
implemented both.)*

*(Prior turn, retained for lineage: `M3-CP4c-3-TB14-REV` proved the edge locus was newly reachable — contact nodes
are appended after every vertex node — and that the helper's five `nullopt` branches were collapsed into one
untyped result, so the branch could not be attributed. CB17's typed split produced the evidence above.)*

*(Prior turn, retained for lineage: `M3-CP4c-3-TB13-REV` determined the vertex-10 emitter — CB15's
`vertex_locus_secondary_parameter == nullopt`, not the legacy port branch — and proved the cause was a missing
**vertex-exit** case in `vertex_trace_ray_second_point`'s Forward chain. CB16 implemented it and split the
collapsed reason, closing `M3-CP4c3-TB13-CAND-01` and `M3-CP4c3-TB13-REV-CAND-01`.)*

*(Prior turn, retained for lineage: `M3-CP4c-3-TB12-REV` proved the v47 collision was BI2 alternative 2 — two
valid rays collapsed because `RayOrderKey::secondary` was the ray's **origin** port ordinal rather than a
locus-relative within-wedge rank — and froze the CB15 correction that produced the state above.)*

*(Prior turn, retained for lineage: `M3-CP4c-3-TB11-REV` proved the collision was underdetermined because the
emitter retained neither operand, and froze the diagnostic-only CB14 that produced the evidence above. Its
predicted mechanism — lesson 85, "an identifier is only a discriminator inside the scope that makes it unique" —
is now runtime-confirmed.)*

*(Prior turn, retained for lineage: `M3-CP4c-3-TB10-REV` proved the firing site was one of **28**
`RotationSystemInconsistent` emission sites publishing neither a reason nor a locus, making the phase undecidable;
CB13 discharged that diagnostic owner. `M3-CP4c-3-CB13` was diagnostic-only and build-green on package 81.)*

*(Prior turn, retained for lineage: `M3-CP4c-3-TB9-REV` classified TB9's first red as a **genuine product ownership
defect on a valid witness** — a `FieldAlignedSingularityPort`, an *origin* credential, was being used as an
*arrival* credential, and a `BarrierAbsorbed` singularity has no ports by design although its network node is
allocated unconditionally. It froze `M3-CP4c-3-CB12` under BD0–BD9, which TB10 has now runtime-proved.)*

*(Prior turn, retained for lineage: `M3-CP4c-3-TB8-REV` reduced the twelve `InvalidNetworkTerminalOwnership`
emission sites to **two** and classified the red as **diagnostic insufficiency**, because the two survivors emitted
an identical rendered locus while every discriminating field of `FieldAlignedCurveNetworkError` was dropped at the
pipeline projection — and accepted ordinal 329's losslessness guarantee turned out to assert against a
**test-local** renderer. CB11 discharged BB0–BB9 diagnostically: the discriminator was added as a **field**, so
accepted ordinal 328 still asserts `InvalidNetworkTerminalOwnership` unchanged.)*

*(Prior turn, retained for lineage: `M3-CP4c-3-TB7-REV` proved ordinal 366 was a **CB9-introduced** product defect —
CB9's fifth seed guard reused the **half-open ownership convention** as an admissibility test on one incoming ray,
making every edge-collinear vertex arrival unresolvable in `FaceInterior` mode — and classified ordinal 374 as an
**invalid witness**: the folded cone has `Θ = 3π/2`, so Gauss–Bonnet forces `exactLift = 1` against
`make_zero_transport_field`'s declared `effort ≡ 0`, and that helper carries an unstated precondition — the mesh
must be **intrinsically flat at every interior vertex**. Amendments 22 and 23 survived intact. Ordinal 374 remains
deferred as `M3-CP4c3-TB7-CAND-02` and the atlas must not be weakened for it.)*

*(Prior turn, retained for lineage: `M3-CP4c-3-DEFN-R2` discharged CB8-REV's AX1–AX8 and froze the vertex-star
continuation semantics. **Amendment 22:** a curve continues through a source vertex along the **straightest
geodesic** of the intrinsic vertex star — one exact arrival-anchored ray, one isometric development of the fan,
continuation at `β = α + Θ/2`, the *unchanged* half-open sector convention applied to developed sectors, one typed
certificate. Choosing `Θ/2` over `π` makes the gap/overlap pathology of a non-flat star **impossible** rather than
adjudicated, and coincides with the ordinary straight line at every flat vertex. **Amendment 23:** the exact
election is the sign of a sum of arccosines, degree up to `4^k` in fan length, so the architecture owes a certified
filter, an implemented exact fallback, and a **published budget** with a typed fail-closed state. Vertex 30 is
proved exactly there: four rational identities give `Θ(v30) = 2π` with no factorization and no floating point, the
developed sectors give `sector(209) ∪ sector(208) = [π, 3π/2)`, so the owner is row 209 `(30,119,123)` or row 208
`(30,31,119)` split at `α = θ₂₀₉`, and **row 41 `(25,30,31)` is unreachable by any continuation**.)*

*(Prior turns, retained for lineage: `CB8-REV` upheld CB8's architectural stop and proved the missing authority was
definition-level; `TB3-R1-REV` confirmed Amendment 16/P2 effective and ordered the typed failure-locus channel CB5
delivered; `TB4-REV` falsified all three enumerated mechanisms and declared **Amendment 17**.)*

---

## 1. What the project is

A hard fork of **libdirectional** adding a **quad-remeshing pipeline** built on exact arithmetic. Given a
triangle mesh and a cross field, it produces a pure-quad mesh carrying an explicit, independently verified
guarantee. The distinguishing commitments:

- **Exact arithmetic, no tolerances** in topological decisions. `FieldExactRational` / GMP-backed integers.
  A predicate that needs an epsilon is treated as a design defect, not a tuning problem.
- **Single-writer authority.** Every datum has exactly one producer. Consumers get `const` views or typed IDs.
  Products are immutable once produced; a later stage may not repair an earlier stage's output.
- **Derived, not assumed.** Regions, ports, terminations and certificates are computed and certified, never
  asserted by fiat.
- **Typed failure over silent degradation.** Every stage fails closed with a typed error and a locus.

`DESIGN.md` is the normative architecture. `ROADMAP.md` maps checkpoints to the production-ready exit
(`M8-CP3`).

## 2. Pipeline stages

| Stage | Product | One-line contract |
|---|---|---|
| A0 | `SourceAuthoritySnapshot` | exact source support, typed IDs, topology regions |
| A1 | `FieldTransportAtlas` | per-face cross frame + typed transport across every interior edge; singularities |
| A2a | `FieldAlignedCurveNetwork` | traces from singularity ports + mandatory edges from features/boundaries |
| **A2a′** | **`SurfaceCutGraph`** | **added cuts guaranteeing the network's complement is a disjoint union of discs** |
| A2b | `GlobalTopologyPlan` | regions as faces of the embedded graph, with disc proofs |
| A3 | `GlobalConformityPlan` | — |
| A4 | `RegionCellComplex` per region | — |
| A5 | `SurfaceOccurrenceComplex` | — |
| A6 | `QuotientCertificate` + quad mesh | — |
| A7 | source-attached vertex geometry | — |
| A8 | `VerificationReport` + `OutputDisposition` | independent verifier assigns the tier |
| A9 | logs and public result | — |

A2a′ was added and closed in CP4c-2. A2b now derives regions with disc proofs on the produced torus. Everything
from A3 onward is unreached, and the prescribed sphere still cannot reach A2b (§7 item 1).

**Disposition ladder** (assigned by A8, never asserted by a producer; a run only moves down):
`D0 Certified` → `D1 QualityRelaxed` → `D2 LocallyDegraded` → `D3 Partial` → `D4 DiagnosticOnly`.

## 3. Where we are

**Runtime authority — `M3-CP4c-3-TB27-R1`, unchanged.** Selector **406**, **399 PASS / 7 RED**, accepted
**1–365 = 365/365**, reds {366, 367, 368, 369, 370, 374, 398}. The mechanical actual embedded complex is
**certified cellular** — `V=22, E=26, F=6, componentCount=1, χ=2, residual=0`.

**`M3-CP4c-3-TB28-R2` produced no runtime authority.** Its `407 PASS / 0 RED` is rejected as orchestration-invalid.
The proof is short: selector 407 is selector 406 plus one identity with 406 as its exact prefix, so ordinals 366,
367 and 398 are present unchanged; CB32's entire source diff is diagnostic — every added reference to
`traceCutFaces` is a `.count()` read, and nothing writes `barriers`, `directOwners`, the seed rule, the partition or
`proves_cellularity()`. **No behaviour change can account for the status change.** The report also omits the
ledger, identity map, RED ordinal list, accepted-prefix count, censuses and resource evidence its own frozen plan
requires, and records **one** runtime binary hash where the package holds five test executables — consistent with
every row being routed to a single binary, where an unmatched `--gtest_filter` exits 0 and "exit 0 is PASS"
manufactures the green. `LESSONS.md` 129, 130.

**Its CL6 census was also off-object, for the fourth consecutive turn** — `ReliefTopologyBuildFailed` at
`quadPatchIndex=0` over a 27-face candidate set in component 1 with `censusFailureCount=0`, where the frontier is
component 0 with 191 faces and 4 interior arcs. The `subset=true` result compares neither of the sets CL7 asked
about.

**CL8 is discharged: the correction is frozen.** *The separating-arc barrier rule* — in
`build_source_face_ownership`, every arc with `orbitByDart[forwardDart] != orbitByDart[reverseDart]` contributes its
source edges to `barriers`, and every source face it crosses becomes trace-cut. It is derived from certified data
and is therefore non-circular; it is the invariant a partition of certified ownership must satisfy; and it does
**not** over-cut, since arcs 20 and 24 have equal orbits and are untouched. **Accepted-prefix safety must be
demonstrated, not argued.** Only its application *order* is sequenced, because the one instrument that could
confirm it currently reports green on a product that provably fails.

**Definition authority — `M3-CP4c-3-DEFN-R3`, Part VII of `M3_CP4c_Frozen_Definitions.md`.** It supersedes Parts
IV–VI where they conflict, and only there. Its decisions:

- **DEFN-R3.1 — the certifier must publish a total source-face owner map.** The question every recent diagnostic
  tried to answer — *which certified face contains this source triangle* — is not answerable from
  `SurfaceCutGraphFaceCertificate`, which publishes an orbit id and three counts. But
  `certify_actual_embedded_graph` **already builds the whole embedded topology and face walk**
  (calling the same `build_embedded_graph_topology` the plan calls) and then publishes counts only.
  `proves_cellularity()` is extended to require the map to be total with ids drawn from the certificate's own
  faces. **The decision stands. Its justification — "a publication decision, not a new computation" — was
  WITHDRAWN at `M3-CP4c-3-TB24-REV`:** the face walk's darts are darts of *network and cut arcs*, so a source face
  has a directly readable orbit only if it is arc-incident or trace-crossed. Every other face — including most of
  component 0's 191 — still needs its owner **propagated**, which is the seeding algorithm R3.2 set out to delete.
  CB27 duly re-implemented that propagation inside the certifier and reproduced `[0,1,3]` at `(0,1,2)` exactly.
  `M3-CP4c3-TB24-REV-CAND-02`, `LESSONS.md` 121.
- **DEFN-R3.2 — ownership is read, not seeded.** With a total map, `componentBarriers`, the unlabeled-face
  partition, `seedOrbits` and the per-edge seed rule are **replaced by a lookup**.
  `UncutFaceComponentOrbitSeedNotUnique` is **relocated**, not weakened, into a consistency check that names the
  component and the conflicting owners.
- **DEFN-R3.3 — a derived partition must be at least as fine as the one it adjudicates**; any retained projection
  must use the full `mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges`.
- **DEFN-R3.4 — the fragment-count prohibition is LIFTED, with reasons.** `|owners| = k+1` is false on a certified
  cellular complex containing a bridge, which TB18 measured (arc 15, `forwardOrbit = reverseOrbit = 0`). CB21
  stands and is not reverted. The `proves_cellularity()` and seed-guard prohibitions remain in force.
- **DEFN-R3.5 — the discriminator was a lookup, and it was defeated by its own precondition.** TB24 reported
  **0 observed / 191 unavailable** because publication was gated on the derivation succeeding. Its replacement,
  TB24-REV's CH8 conflict census, was defeated the *same way* — it reads only established owners, and on the
  component under investigation nothing is established. **Two measurement designs in a row failed on the
  precondition, not on the geometry.** `LESSONS.md` 120 and 122.
- **DEFN-R3.6 / R3.7 — ordinal 397 must be FIXED** (relaxing its expectation is prohibited) and **ordinal 393's
  assertions are REPLACED in place**, retained and gating, because its seed-relative expectation becomes
  meaningless once the seed ceases to exist.

Stable accounting is **44 / 14 / 30**, produced-witness debt **5**, semantic M3 packages **93**. Sphere 368,
saturation 369, ordinal 370, folded-cone 374, the finalize/contact fall-through and the vertex-30 evidence contract
remain deferred under their own owners. **Vertex 30 is still not reached.**

## 4. The three witnesses — the fastest way to understand the problem

| witness | source | A2a result | current state |
|---|---|---|---|
| **torus** | fixture, closed genus 1, `χ=0`, V/E/F = 72/216/144 | 48 `HardFeature` mandatory edges, 0 singularities, 48 nodes, **0 traces**, 0 events | **A2a′ and A2b both work end to end through the production path.** 28 cut edges; actual embedded graph `V/E/F = 72/76/4`, `χ=0`; 4 regions with disc proofs. Producer and independent oracle agree term for term (`76 − 48 = 28`). Criteria C1/C6 green at ordinals 356/357. Fails later, downstream of A2b, at `tracing` (out of CP4c-2 scope) |
| **prescribed sphere** | fixture, closed genus 0, `χ=2`, V/E/F = 98/288/192, zero mandatory edges | 24 traces / 56 events | A2a′ remains deferred. TB6 report-only ordinal 368 localizes the current producer stop to `TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable`. This is localization only; no sphere semantic fix is authorized. |
| **two-ring** | constructed, disc, `χ=1`, V/E/F = 11/25/15 | 3 traces / 8 events | actual embedded graph `V/E/F = 9/11/3`; the accepted invariance witness, and the **only** witness on which the A2a′ semantic/provenance split is runtime-proved |
| **mechanical feature** | fixture, 152 V / 450 E / 300 F, closed, `chi=2`, 0 boundary edges | clears all A1, the vertex-11 transit (CB10), the whole of A2a since CB12, every vertex locus since CB16, the entire edge-locus rotation frontier since CB18, and the region source-port branch since CB19 | **Current owner of the critical path, in region construction.** The actual embedded complex is certified cellular. The plan **fails closed** on its `EmptyFragmentOrbits` component **0** — **191** faces, seeds **`[0,1,3]`** distributed **81/1/1** over 83 attributed boundary edges — publishing all three owners rather than choosing. The certifier's `NotTraceCut` component 0 is a **different object**: **214** faces, 76 boundary rows, **4 interior trace arcs of which 2 separate** (arc 14 `(0,1)`, arc 22 `(0,3)`), 53 vertex transits, 46 seed attributions. `matchesFailingComponent=false`. Vertex **30** is **still not reached**. See §7 item 1. |

## 5. The central theorem of CP4c-2

For a graph embedded in a closed surface with every complement component an open disc, Euler gives
`V − E + F = χ`. The torus network has `V = 48`, `E = 48`, `χ = 0`, so `F = 0` — impossible, since the
complement is non-empty. **At least one component is not a disc.**

Stronger and more useful: a disjoint union of closed curves always has `E = V`, so **no disjoint union of closed
curves can ever be a cut graph of the torus.** This is not a defect of the committed fixture and cannot be fixed
by choosing better feature curves. A cut graph of a genus-`g` surface needs vertices of degree ≥ 3 and must
realize a homology basis; a feature/singularity-derived network guarantees neither.

That is why A2a′ exists. `UncutFaceComponentOrbitSeedNotUnique` at `GlobalTopologyPlan.cpp:1741` was **correct
behaviour reporting a missing input** — there was never a bug at that line.

## 6. The normative complex — read this before touching A2a′

Frozen by **DEFN-R1 Amendment 13**. The complex in which cellularity is certified is the **actual embedded
graph** of `FieldAlignedCurveNetwork ∪ cutEdges`:

- **vertices** = network nodes + nodes created by cuts
- **edges** = network arcs + cut arcs
- **faces** = **dart orbits** under the node rotation system

The machinery already exists and must be reused, never reimplemented:

| concept | where |
|---|---|
| arc, dart | `GlobalTopologyArc`, `GlobalTopologyOrientedArc` — `include/directional/geometry/GlobalTopologyPlan.h:33-47` |
| rotation | `GlobalTopologyNodeRotation.counterClockwise` |
| face walk | `walk_graph_faces(arcs, rotations)` → `FaceWalkResult{orbits, orbitByDart}` — `src/geometry/GlobalTopologyPlan.cpp:1168-1260` |
| fragment | `fragmentOrbits[SourceFaceTopologyKey] → {orbit}` — `:1534-1660` |
| shared authority | `src/geometry/EmbeddedGraphTopology.{h,cpp}` — created by CB4, the single owner |

**Two conventions decide correctness and must be derived, not guessed:**

1. **Exterior-orbit exclusion** on surfaces with boundary. The two-ring walks 4 orbits, exactly one exterior →
   `F = 3`. On a closed surface there is no exterior orbit.
2. **Disconnected-graph correction.** The torus's 48 arcs over 48 degree-2 nodes form **four components**;
   unqualified `V − E + F = χ` is false there *before* any cut is considered. Mistaking that for
   non-cellularity is right for the wrong reason.

**Withdrawn:** the whole-source-face / source-edge-barrier partition is **not** cellularity authority. It
survives only as a cut-proposal heuristic and diagnostic provenance, and any publication of it must say so.
Two complexes exist for the two-ring and both satisfy Euler — actual `9/11/3` and proxy `10/11/2` — which is
precisely why self-consistency proves nothing about *which* object was measured.

**Cut admissibility — revised by Amendment 14 (DEFN-R2); the old rule below it is withdrawn.** A cut is a source
edge promoted to a graph arc, and **every source edge that is not already a graph arc is admissible, including one
a trace crosses at an interior point.** Promoting a crossed edge adds one arc per sub-interval between consecutive
crossings and one cut-created node per crossing, and splits the trace arc **in the derived arrangement only**.

The old rule — "a trace-crossed source edge is inadmissible because promoting it would subdivide an immutable
trace" — rested on a premise that is false about this codebase. `build_arcs` already emits **one trace arc per
event**, so a trace is many arcs, not one; it already splits a mandatory source edge at a trace terminal; and the
crossing point is already published exactly by the network as `segments[i].entryPoint`, at a segment position the
subdivision machinery already keys on. Nothing upstream is mutated either way. Amendment 12 forbids A2a′ *repairing*
an upstream product; it never forbade A2a′'s own arrangement from placing a node where the network already says two
curves meet.

**Completeness is therefore proved outright.** The complement of the source 1-skeleton is the open triangles, each
a disc; trace sub-arcs cut those discs into discs; so `network ∪ (source 1-skeleton)` is cellular, a sufficient cut
set always exists, and at most `|E_source|` promotions are ever needed. `NoAdmissibleCutForNonDiscComponent` can no
longer describe a real configuration and is retired; a distinct code reports "the search heuristic made no
progress", and saturation — promoting the component's remaining admissible edges — is the defined, *published*
last resort. It must never fire silently, and is predicted never to fire on the three witnesses.

**The one real gap this opens:** at an edge-locus node, `build_rotation_system` handles only `Mandatory` (at exactly
degree three) and `Trace` rays — a `Cut` ray there is an unhandled shape. A crossing node is two collinear `Cut`
rays plus two `Trace` rays, degree four, and the existing four-sector model generalizes to it. CB7 implemented that
generalization; ordinal 364 would prove it and **has not yet executed**.

**Building an A2a′ witness by hand — the trap that produced R8's red.** The production feature authority is a
**chain of four products**, and it is acyclic:

```
featureMap → build_authoritative_surface_cell_rails → authoritativeRails
           → hard_feature_edge_keys_from_rails      → hardFeatureEdges
           → SourceTopologyRegions(hardFeatureEdges, componentByFace, localSheetByFace, authoritativeRails)
           → FieldTransportAtlas::make(…, hardFeatureEdges, …)
```

The test helper `rails_from_atlas` reads rails **back out** of an atlas, keeping only `SourceBoundary` and
`HardFeature` non-traversable edges. That is correct only if the atlas was built with the hard features already.
On a **closed** witness built with `hardFeatureEdges = {}` it returns **nothing**: no boundary, no declared
features, and uniform component/sheet labels leave no `NonTraversable` edges either. The result is an empty rail
set, an empty network, and a red that looks like a cut-graph failure. `make_source_authority(mesh)` supplies none
of the four products — it zeroes components and sheets and passes no rails. Two call sites already do this right:
`observe_cp4c_witness` (all four production inputs) and `build_cp4c_trace_crossed_cut_fixture` (computes hard
features first, then threads them through source authority *and* atlas). Copy one of those; never call
`rails_from_atlas` on an atlas that was not told about the features.

## 7. Open problems, in priority order

1. **Certified-face ownership — the correction is FROZEN; what is missing is a trustworthy gate.**

   - **The correction, decided and not to be re-opened.** *The separating-arc barrier rule*: every arc with
     `orbitByDart[forwardDart] != orbitByDart[reverseDart]` contributes its source edges to `barriers`, and every
     source face it crosses becomes trace-cut. Derived from certified data, non-circular, and it does not over-cut
     — arcs 20 and 24 have equal orbits and are untouched, so the `terminalSlit` skip is superseded **only for
     separating arcs**. TB27-R1 measured that this is not hypothetical: arcs **14** `(0,1)` and **22** `(0,3)`
     separate.
   - **Accepted-prefix safety must be demonstrated by construction**, not argued — the rule must be shown a no-op
     wherever the current code already inserts the same barrier, with the remainder enumerated.
   - **The blocker is the instrument.** TB28-R2 reported a full green on a byte-for-byte unchanged ownership path.
     Until a gate reproduces the known REDs, no correction can be confirmed and none should be applied.
   - **Order:** CB33 harness repair reusing the package unchanged → TB28-R3 control (credible only if 366/367/398
     are RED) → CB34 applies the frozen correction. The review in between confirms the harness and **may not
     re-open the correction**.

2. **Two partitions of one mesh, and the diagnostic runs on the one that does not fail.** Confirmed at runtime by
   ordinal 406. The barrier families are identical; only the domain predicate differs, and the plan's domain
   excludes exactly the faces carrying a direct certified read (`GlobalTopologyPlan.cpp:702`, `:750`) — the seeds it
   then cannot find. `M3-CP4c3-DEFN-R3-CAND-01` is now **gating**. **Unification is a definition decision** and
   belongs to a `DEFN` turn once the mechanism is known; CB32 publishes the subset relation and unifies nothing.

3. **Production transit audit projection — ACTIVE; AY7 was delivered producer-side only.** Three defects on one
   path: the `VertexStarTransitAudit` is constructed **after** all five seed guards, so every seed failure publishes
   `std::nullopt`; `VertexStarTransitState::SeedUnavailable` is therefore **dead by construction**; and the 26 AX8
   fields CB9 added to `SurfaceCellFailureLocusDiagnostics` have **no reader** — `append_cp4c_failure_locus`, the
   only renderer the CP4c identities use, prints none of them and `vertexTransitStates` has no projection at all.
   Third consecutive turn in which an ordered measurement was built and discarded at a stage boundary. Owned by
   **AZ4–AZ5**, with the consumer set found **by search against a predicate**.

4. **Minimal transit witness / selector governance — ACTIVE, still conditional.** Selector 374 stays byte-immutable.
   The gate covers only `FoldedConeArrivalRayElectsOneOwnerAndFalsifiesCandidateLocalElection`; the boundary-ray and
   radial-arrival companion instances are **ungated**, and the radial one was written in `EdgeTransit` mode
   specifically because CB9's guards block `FaceInterior` — so no gated identity covers the case production actually
   produces. **AZ6** must derive that witness from the mechanical vertex-11 star (coordinates already committed,
   arrival already proved exact), instantiate **both** radial orientations, and show it failing under CB9 and
   passing under the correction. Ordinal **375** is appended only then.

5. **Ordinal 370 empty closed network — ACTIVE, measured independent A2a′ product red.** TB7 reproduces
   `CellularityNotEstablished` (4) where `EmptyNetworkOnClosedSurface` (6) is required, with the `sourceFace` locus
   absent. Independent owner; deferred until the mechanical path clears; must not be combined with vertex transit.

6. **Prescribed sphere — ACTIVE / deferred.** Report-only 368 reproduces `NoCarrierMatch / SourceEdgeUnavailable` at
   trace 2 / event 30. Preserve AL4: no sphere semantic correction while the mechanical gate owns the critical path.

7. **Ordinary trace-crossed proposal quality — ACTIVE / deferred.** Report-only 369 still publishes
   `certificate.saturationUsed=true`. Amendment-14 representation is proved; ordinary-proposal coverage is debt.

8. **Mechanical zero-unbound singularity proof — PARTIAL.** Ordinal 373 is green only on its synthetic barrier-arc
   witness. `M3-CP4c3-DEFN-R1-CAND-01` stays open until production publishes `unboundSingularityCount=0`.

9. **Report-only 367, 371, 372 — UNMEASURED, and 371/372 are blocked by a fixture helper rather than by their own
   contracts.** All three abort inside the shared `cp4c_mechanical_fixture()` constructor, which throws unless *all
   five* of `sourceAuthority`, `atlas`, `network`, `cutGraph` and `plan` are retained — so their TB10 reds are one
   upstream cause, not three. But **371 and 372 read only `fixture.atlas`**, an A1 product that is available and
   built successfully in the same run: their contracts are independently reachable today and are held hostage three
   stages downstream. Amendment 15's barrier-cycle and Euler-cut contracts have therefore been "unmeasured, not
   falsified" from TB2 through TB10 for a reason unrelated to either. Ordinal 367 genuinely needs `plan` and is
   legitimately blocked. Recorded as `M3-CP4c3-TB10-REV-CAND-01` with a test-only corrective and **deliberately
   deferred**: clearing ordinal 366 unblocks 371/372 automatically, so the candidate exists to make the coupling's
   cost visible if it does not.

10. **CB9 static audit debt — ACTIVE, static.** `M3-CP4c3-CB9-AUDIT-01` (`build_boundary_pairing` computes `u/v` in
    `double` and exactifies them before the flow classification reads their signs) and `M3-CP4c3-CB9-AUDIT-02`
    (`integer_sqrt_floor` has no published bit-width budget). Worth knowing: AUDIT-01 is the mechanism that produced
    the exact zero item 1 turns on, and on that witness it produced the **right** answer — the field genuinely is
    tangent to edge `(10,11)` — so it is **not** the cause of ordinal 366 and must not be repaired as if it were.

## 8. Recurring defect patterns — the highest-value section

**A status change with no behaviour change is a harness result, not a product result.** A gate that had reported
7 RED reported 407 PASS one turn later, on a package whose only source change read the ownership state and never
wrote it. Before recording a status change, name the behaviour change that caused it; if none exists, the instrument
moved. `LESSONS.md` §4 129.

**"Exit 0 is PASS" needs proof that something ran.** GoogleTest exits 0 when a filter matches no tests. Route 407
identities spread across five binaries to one binary and four-fifths of them exit 0 unmatched. Require a per-row
selection count and treat "zero tests selected" as a failure. `LESSONS.md` §4 130.

**A per-segment property cannot decide a per-arc or per-face classification.** A trace's last segment being a
terminal slit was used to exclude that segment's *face* from the trace-cut set and its carriers from the barrier
set — and a review then inferred from the same flag that the whole *arc* must be a bridge. Runtime found two of four
such arcs separating. State the quantifier before classifying the larger object. `LESSONS.md` §4 127.

**When a measurement chain reaches its third turn, freeze the stop rule and pre-name the corrections.** Six
successive turns measured one ownership frontier, each correctly explaining why the last could not answer. Every
step was justified; the sequence was the larger risk. Write the exhaustive outcome list, the correction each outcome
selects, and the default on ambiguity, so "insufficient evidence" stops being available. `LESSONS.md` §4 128.

**An incidence count is not a separation — publish the field that carries the distinction.** The frozen
discriminator asked whether a *separating* arc meets a component's interior; the runtime reported `interiorArcs=4`
and the turn read that as the horn selected. An arc separates only if its two darts lie in different orbits, and the
census stored both orbits per row while printing the count. The same report admitted it could not name the four
arcs. `LESSONS.md` §4 125.

**A diagnostic must be computed on the object that failed.** Two partitions of one mesh exist — the plan's over
faces with no fragment orbits, the certifier's over faces not crossed by a trace — and the entire CJ6 census was
computed on the second while the RED is raised on the first. Their boundary counts differ, 97 versus 76, precisely
because they are different objects. `LESSONS.md` §4 126.

**A census over "established" values is vacuous exactly where nothing is established.** The CH8 conflict census
emitted a row only when both faces of an edge had an established singleton owner; all 191 faces of the component
under investigation were `Unavailable`, so `rowCount=0` was structural. Third structural zero in this checkpoint,
after `projectionFaithfulnessResidual` and the seed-aliased certificate columns. Checking that a measurement runs on
the failure path is not enough — check that its **inputs** survive the failure. `LESSONS.md` §4 122.

**A required-green assertion must never encode a hypothesis still under investigation.** Ordinal 390's
`ASSERT_GT(distinctCount, 1U)` was authored when the count was 3 and the component was believed to span several
certified faces. When the count came back 0, the gate failed on the hypothesis rather than on the contract the
identity owns, and its RED said nothing about the product. `LESSONS.md` §4 123.

**A diagnostic must not be gated on the success of the thing it diagnoses.** D3 was defined to read the published
owner map; the same definition made publication conditional on the ownership derivation succeeding. The only runs in
which D3 could report were the runs with nothing to decide — on the failing case it returned "unavailable" for all
191 faces. The same ordering defect cost four more surfaces: the producer's typed error replaced the certificate, so
five witnesses built to observe the consumer's failure never got a subject, and the consumer's complete, correct
evidence census sat one stage below a return statement. Ask which path runs when the measured thing is broken, and
put the measurement there. `LESSONS.md` §4 120.

**Moving a computation to the correct authority does not give it more information.** DEFN-R3 correctly ruled that
the certifier, not the consumer, owns source-face ownership — but justified it as "publication, not computation".
The certifier holds a dart only for arc-incident and trace-crossed faces; every other face still needs the same
propagation. The relocated code reproduced the original ambiguity at the identical locus with the identical orbit
ids `[0,1,3]`. Check that the destination can derive the value from data the source lacked. `LESSONS.md` §4 121.

**A consumer must never re-derive a partition its producer already computed.** The cut-graph certifier builds the
entire embedded topology and its face walk, then publishes four scalars per face; the plan rebuilds the identical
structure and tries to reconstruct ownership from fragments of it. Four turns of diagnostics failed on that
reconstruction — an unsatisfiable residual, columns aliased to the seed, a projection coarser than the partition it
adjudicated. When a value is hard to measure downstream, check whether the producer discarded it. `LESSONS.md` §4
118.

**A prohibition inherits the premise of the finding that motivated it.** "Do not weaken the fragment-count
invariant" was written when the only observed instance was the torus, where non-cellularity was independently
proved. On a certified cellular witness containing a bridge the invariant is simply false, so the prohibition could
not be honoured as written — it had to be lifted with reasons by the definition authority, not quietly worked
around. Re-check a prohibition's premise before treating it as binding on a new witness. `LESSONS.md` §4 119.

**If three independent measurement attempts collapse the same way, stop measuring and check whether the datum
exists.** The residual was unsatisfiable, the certificate columns were aliased, and the certified-face projection
re-derived the seed — all because the certificate publishes an orbit id and three counts and no source-face
membership. The question was never measurable; each contract was a new way of reconstructing an answer the system
does not record. `LESSONS.md` §4 115.

**A falsifiability witness earns its keep by splitting "can" from "does".** The unit witness proving the pair
measurement *can* report a non-zero differing count passes, while the production witness proving it *does not*
here reds. Without that pair, `differing=0` would have been reported as a clean result — exactly as CB24's
structural zero was. `LESSONS.md` §4 116.

**A derived partition must be at least as fine as the one whose property it is testing.** The certified-face
projection united faces across everything except mandatory and cut edges, omitting `traceTouchedEdges`, so its
components were strictly coarser than the seed guard's — guaranteeing multi-owner sets and `unavailable` for every
face. `LESSONS.md` §4 117.

**A resolver for a required precondition must fail closed.** `test_data_root()` checks two candidate fixture
locations and, when neither exists, returns one of them anyway. A harness slip that should have produced one typed
stop instead produced a complete 397-process ledger with 38 accepted-prefix failures that then had to be argued
away as non-semantic. A helper that resolves a precondition must report when it cannot. `LESSONS.md` §4 112.

**A preflight must check the path the consumer resolves, not a path that merely holds the same bytes.** The TB23
harness verified fixtures in the extracted source workspace while the packaged binaries resolve `test-data`
relative to their own executable directory. Both locations held the same files, so the check looked correct and
proved nothing. Verify preconditions **through the consumer's own resolution rule**. `LESSONS.md` §4 113.

**When several turns pass on an arrangement no artifact records, that arrangement is an undocumented dependency.**
TB18–TB22 worked because their harnesses staged fixtures into an executable-relative view; nothing in the package,
the reusable compile workflow, or any durable document said that staging was required, so the first harness that
omitted it had no way to know. Write the required runtime layout into the frozen plan. `LESSONS.md` §4 114.

**A diagnostic measure must name its source of truth, not just its output field.** "Attribute each edge's sides
to certificate faces" was implemented by a helper called `certificate_side_orbit` that reads `edgeOrbitEvidence`
and `fragmentOrbits` — the seed machinery — and never touches the certificate. The field name matched the request;
the value answered a different question, and three columns of a report turned out to be one number printed three
times. Specify **which authority** a diagnostic reads from, and make the witness prove it read from there.
`LESSONS.md` §4 109.

**A measurement that cannot vary is not evidence — state what would falsify it.** The faithfulness residual
quantifies over a set intersected with the complement of one of its own supersets, so it is `0` on every mesh
forever; its required-green witness passes because the field is *published*, never because it could have been
non-zero. Every diagnostic contract should state the condition under which it would report a different value, and
the witness should exercise that condition. `LESSONS.md` §4 110.

**Two mechanisms for one quantity means the reachable one is probably the wrong one.** `GlobalTopologyPlan.cpp`
computes certificate side orbits twice: once genuinely from `walk.orbitByDart` on mandatory/cut arcs, once from the
seed lookups. The genuine one is consulted only inside unreachable code; the circular one feeds every published
row. When a value has two producers, check which one the shipped path actually calls. `LESSONS.md` §4 111.

**Bounded evidence must be retained by distinctness, not by position.** A first-N window preserves the majority
and can drop exactly the outliers a "not unique" failure exists to report. Component 0's boundary census is
**81 / 1 / 1** across three orbits; the two rows that decide the defect are single rows among 97, and both survived
only by luck of ordering. When capping evidence for a uniqueness failure, retain at least one row per distinct
value **before** filling the remaining budget in order. `LESSONS.md` §4 106.

**A cross-witness diagnostic identity inherits the blockers of every witness it spans.** Requiring one census
witness to cover mechanical, torus and prescribed sphere turned the known-red sphere surface into a new RED in an
otherwise clean diagnostic turn. Scope a diagnostic per witness, or make each half report independently.
`LESSONS.md` §4 107.

**Carry the premise, not just the conclusion.** A frozen finding of the form "X implies Y" gets cited as "Y" once
it is a turn or two old. TB20-REV applied Part I §3's conclusion — "the network is not a cut graph" — to a witness
whose antecedent it had not checked, and the census it ordered in the same breath disproved the antecedent. When
citing a frozen finding, restate its premise and verify it holds for the witness in hand. `LESSONS.md` §4 108.

**Check the frozen definitions' prohibited list before authorizing a correction, not after.** TB18-REV proved a
real mathematical fact — `|owners| = k+1` is not a universal invariant — and authorized relaxing the check that
asserts it. Two frozen definition revisions explicitly prohibit relaxing that invariant, and a third section
explains why: the guard **detects a missing input** rather than asserting a theorem. Correct mathematics about a
check says nothing about whether the check is load-bearing. `LESSONS.md` §4 103.

**When a frontier "advances" without the underlying condition changing, the previous turn removed a detector
rather than a defect.** Ordinal 366 moved from `TraceCutFaceFragmentCountMismatch` to
`UncutFaceComponentOrbitSeedNotUnique`; both are downstream detectors of the same missing cut graph. Frontier
movement is progress only when the thing being detected changed. `LESSONS.md` §4 104.

**An architectural theorem proved on one witness bounds its own scope.** Part I's torus proof turns on `χ = 0` and
on cycles having `E = V`; it says nothing about a closed genus-0 surface. The mechanical witness reaches the same
conclusion by a route the theorem does not describe — new information, not a repetition. `LESSONS.md` §4 105.

**An error code plus a source locus that two unrelated witnesses both produce is a symptom, not an identity.**
The torus (0 traces, 72/216/144) and the mechanical witness (12 traces, 152/450/300) both report
`UncutFaceComponentOrbitSeedNotUnique` at face `(0,1,2)` — because `(0,1,2)` is row 0 of both meshes and the emitter
reports the first unlabeled face in `std::map` order. The torus case is provably the zero-seed branch (no traces, so
no labeled face can seed anything); the mechanical case has 70 labeled faces and 6 orbits. Before merging two
failures by name and locus, ask whether the locus is a property of the defect or of the iteration.
`LESSONS.md` §4 100.

**A guard that reports "not exactly one" must say which side it fell off.** `seeds == end()` and `size() > 1` are
opposite defects with opposite corrections, and the emitter distinguishes them internally and then discards the
distinction. `LESSONS.md` §4 101.

**A witness that exercises none of the disputed behaviour cannot settle it.** All 70 retained mechanical face
arrangements are non-crossing, which says nothing about crossing arrangements — and `SurfaceCellTracing.cpp` builds
`TraceIntersection` contact nodes bound to a source face, so crossings are a modelled case in which `k` chords make
`k + 1 + c` local fragments, not `k+1`. `LESSONS.md` §4 102.

**A diagnostic is reachable only when both its position and its enabling condition hold on the failing path.**
TB17-REV found the `fragment_reconciliation` record sitting thirty lines *below* the early return that needed it.
CB20 moved it above the return — and it still never appeared, because it stays behind
`getenv("DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS") == "1"`, which the frozen artifact-only gate runner never sets and
is forbidden from setting. Position was fixed; reachability was not. `LESSONS.md` §4 97.

**The two ends of a curve are asymmetric in the code and symmetric in the topology.** `is_terminal_slit` correctly
removes a trace's last segment from the chord count — that segment materializes no chord. But what a free end
actually establishes is a property of the **whole trace**: a dangling path separates nothing globally, so *every*
chord that trace cuts also fails to produce a second owner. The exclusion fixes the last segment and leaves the
preceding ones counted as if they separated. Fifth instance of the class. `LESSONS.md` §4 99.

**A diagnostic that is unreachable on the failing path is not a diagnostic.** `build_regions` computes the actual
fragment count, the piece count and the expected count for **every** face, and formats all three into a
`fragment_reconciliation` record — thirty lines below a `return failure;` that fires precisely when those three
numbers are the question. The instrumentation was written for this failure and cannot be reached by it. Place
diagnostics where errors are **raised**, not where the successful path ends. `LESSONS.md` §4 95.

**Counting a local quantity with a global identifier silently assumes injectivity.** "k chords make k+1 fragments"
is a statement about one triangle; `|set of orbit ids|` is a statement about the whole surface. Equating them
assumes distinct local pieces never share a global owner — true often enough to ship, false on a closed surface,
and invisible until a face carries two chords. When a check compares a count to a set's cardinality, name the map
between them and say why it is injective. `LESSONS.md` §4 96.

**A predicate copied into a second consumer inherits the original's defect and then diverges — and the divergence,
not the inherited defect, decides which copy fires.** `build_regions` and `build_fragment_corner_incidence` hold
the same carrier-less trace-segment predicate on the same trace-global datum, so both carry the same wrong binding.
Only the region loop lacks the terminal-slit skip, and that is the sole reason TB16 shows
`RegionTraceSourcePortCarrierNotAdmissible` rather than `TraceSourcePortCarrierNotAdmissible`. Diagnosing the
shared defect alone would have produced a correction scoped to the symptom, leaving the region loop still consuming
a carrier its sibling calls hypothetical. **When two consumers share a predicate, diff what each one *skips* before
concluding anything from which one failed.**

**An earlier identical check that passed is evidence about the input, not noise.** The whole reconstruction of the
TB16 incidence rests on a negative: the fragment-corner loop ran first, over the same arcs and the same segment
ranges, with a byte-identical predicate, and accepted the segment. Since the predicates cannot disagree on
identical inputs, the only escape is the one `continue` that loop has and the other does not — which pins the
failing segment to a terminal slit without any datum the run failed to retain. Order of execution across functions
is usable evidence in the same way order across turns is (lesson 89).

**The fourth instance of a class is a signal about the audit, not about the code.** `trace.sourceVertex` bound to a
per-segment decision has now been found in the vertex-locus helper (CB16), the edge-locus fallback (CB17/CB18), the
rotation fallback, and now the region builder — each found and fixed at its own site, one turn at a time. The
scoping error is not in any of the fixes; it is that no measure ever ran the search *"a per-segment decision bound
to a datum owned by the whole trace"* across the codebase. A class that recurs is owed a predicate-scoped sweep,
not a fifth point fix.

**An absent optional means whatever its producer's last branch chose to leave unset.**
`FieldAlignedCandidateTraceSegment::incomingCarrier` is `nullopt` for two entirely different reasons — a port
origin, and a vertex transit — because `proposal.nextIncomingCarrier` is assigned only on the edge-exit
continuation and the `VertexHit` branch simply returns without it. Consumers then read one absence as the other,
which is exactly how the edge-locus fallback came to ask about a trace's origin singularity. When an optional is
set on some producer paths and skipped on others, the skip carries meaning and belongs in the type: a named
alternative, not a hole. `LESSONS.md` §4 93.

**A rank derived relative to a locus must be derived relative to it in every branch.** In
`edge_locus_secondary_rank` the carrier branch measures from `contactIndex` and the fallback measures from the
face's absolute corner numbering. They agree on exactly one of three possible contact indices — so the
disagreement is invisible two thirds of the time, and entirely invisible on the very witness that exposed the
neighbouring defect. When two branches feed one ordering, check that they share an **origin**, not merely a range.
`LESSONS.md` §4 94.

**Third instance of one class, and the reason to stop fixing instances.** `port->ordinal` at the vertex locus
(TB12-REV), the missing vertex-exit case (TB13-REV), and `trace.sourceVertex` at the edge locus (TB15-REV) are the
same defect: a value correct in the scope that produced it, used in a scope that does not make it unique. Each was
found only when a preceding correction made its code newly reachable. The standing check is cheap — at every
locus-relative computation, ask which scope guarantees the datum, and whether it is the scope being ordered.

**Clearing a stage exposes the next stage's untested contract.** CB16 fixed the last vertex-locus defect and the
very next node the rotation reached was the **first contact node ever processed on this witness** — whose
edge-locus rank helper had never run here. Neither the helper nor its diagnostics were wrong for the inputs they
had previously seen; they had simply never been exercised. When a correction unblocks a traversal, expect the newly
reachable code to carry the diagnostic maturity of code that has never failed, and budget a diagnostic turn for it
rather than reading the first red as a regression. `LESSONS.md` §4 91.

**A typed-reason split is a pattern, not a patch.** CB16 correctly applied BL3 to the vertex helper and left the
structurally identical edge helper with five untyped `return std::nullopt` statements — so the next failure was
again unattributable, for the same reason, one helper over. When a turn fixes a diagnostic-collapse defect, the
measure should name the **class** — every helper that funnels multiple conditions into one bare `nullopt` behind a
single typed reason — not the single instance the current red exposed. `LESSONS.md` §4 92.

**A turn that mints a typed reason must audit the reasons it reuses.** CB15 correctly created
`RotationVertexTraceRaysExactlyCoincident` for its fail-close case, then routed its *other* new failure into the
pre-existing `VertexTracePortOrdinalInvalid` — recreating, in the same commit, the collapsed-reason ambiguity that
lessons 79, 82 and 84 already record, and costing a full review turn to undo. The authoring control: when a change
adds a condition, ask not only "does this need a name" but "does the name I am reusing still mean one thing".
`LESSONS.md` §4 88.

**Execution order across turns is usable evidence.** The legacy emitter at v10 was excluded without reading its
logic: CB15 touched no file upstream of the rotation system, so the network was byte-identical to TB12's; node ids
are monotone in vertex index and the incidence map is keyed by node id, so v10 is processed *before* v47 — and
TB12 reached v47. The same code had therefore already passed that vertex on those exact inputs. When a successor
changes one layer and the failure moves, the untouched layers' **prior successes** are a proof instrument.
`LESSONS.md` §4 89.

**A fallback chain owes coverage, not arithmetic.** `vertex_locus_secondary_parameter`'s projection and guards are
correct; the defect is that `vertex_trace_ray_second_point` enumerates four ways to locate a ray's second point and
omits a fifth the producer can emit — the `VertexHit` exit, which this project documented as Amendment 3 back at
TB7-REV. When a function's body is a lookup chain, review the chain against the **producer's case list**, not the
mathematics after it. `LESSONS.md` §4 90.

**One field, two branches, one of them already right.** The vertex locus and the edge locus fill the same
`RayOrderKey::secondary` slot. The edge branch computes a locus-relative, exact, geometry-free rank and says so in
a comment; the vertex branch substitutes the ray's **origin** port ordinal. The correct design was already
implemented forty lines away in the same function. Before designing a rank, a key, or a tiebreak, diff the sibling
implementations of the same field — the convention may already exist. `LESSONS.md` §4 86.

**A quantity that is only incidentally correct is wrong the first time it matters.** `port->ordinal` was consistent
for a singularity's own emanating rays — and the v47 census shows `primary` already separated those, so it never
did any work there. It became load-bearing only for rays arriving from **other** vertices, which is exactly where
it is meaningless. Before trusting a tiebreak, ask which inputs actually reach it. `LESSONS.md` §4 87.

**A fail-closed uniqueness assertion that compares less than the key it asserts on.** `RayOrderKey` sorts on six
members and is checked for collisions on two. That is defensible only if the other four are known-irrelevant to the
invariant — and if so, the guard should say so and the key should not carry them. As written the predicate cannot
tell "the key is under-determined" from "the input is duplicated", which is exactly the ambiguity that blocked the
TB11 review. The authoring control: when a guard asserts injectivity, state which projection of the key is supposed
to be injective and why the remaining members are irrelevant. `LESSONS.md` §4 84.

**An identifier used as an ordering key outside the scope that makes it unique.** `port->ordinal` is injective over
the ports of **one** singularity. `build_rotation_system` uses it as the within-sector tiebreak at an arbitrary
vertex, with no check that the port's source vertex is the locus vertex — so rays that merely arrive at or pass
through the vertex contribute ordinals minted elsewhere. Before borrowing an id as a sort key, check that the scope
guaranteeing its uniqueness is the scope you are ordering within. `LESSONS.md` §4 85.

**A default rendered as an observation — third recurrence.** `nonDiscComponentCount` and
`remainingAdmissibleEdgeCount` are assigned **only** on the `CutSearchExhaustedBeforeCellularity` returns
(`SurfaceCutGraph.cpp:365`, `:367`); the certification-failure return at `:345` assigns neither, yet
`RemeshPipeline.cpp:6877-6878` projects them unconditionally. So TB11's `nonDiscComponentCount=0;
remainingAdmissibleEdgeCount=0` are **struct defaults, not measurements**. This follows `publishedFaces` (TB8-REV)
and the trace-scoped group (TB9-REV). The durable fix is not another one-off: **a locus field should be printed
only where the path that produced it assigns it.** `LESSONS.md` §4 80.

**A discriminator added only to the sites that already had a locus discriminates nothing new.** Nine of
`EmbeddedGraphTopology.cpp`'s forty-six `RotationSystemInconsistent` sites gained a
`RotationSystemInconsistencyReason` — and all nine already published a `sourceEdge` or a `sourceFace`. The cases
that were already localisable became more legible; the twenty-eight that published nothing stayed silent, and one
of those is the current gating red. When resolving a collapsed error code, **enumerate the sites that publish
nothing and start there** — the ones you can already localise are the ones that least need a name. This is the
counterpart of `LESSONS.md` 57/64: it is not enough to add a reason, the reason has to reach the *silent* sites.

**Count the losses before repairing one.** The TB10 report localised a real projection loss — `cut_graph_failure_locus`
publishes only two of the ten fields `SurfaceCutGraphError` carries — and named it the cause. There were **three**
losses of the same datum in series (silent producers → a mapper with no `sourceVertex` field → the projection), and
the reported one was the **last**. Repairing it alone would have bought a whole turn of identical evidence. Before
proposing a diagnostic fix, walk the datum from producer to reader and count every boundary that drops it; then fix
the earliest.

**Two identities observing the same stage can have very different eyesight, and the idiom decides.** The prescribed
sphere's cut-graph failure is fully legible at ordinal 368 because it uses `observe_cp4c_witness`, which calls
`SurfaceCutGraph::make` directly and holds the typed error. The mechanical failure is opaque at ordinal 366 because
it uses `build_cp4c_production_fixture`, which throws a string assembled from the lossy pipeline locus. Same stage,
same error family, same test file — different observation idiom. When one witness is legible and another is not,
compare the observation idioms before concluding anything about the witnesses.

**A shared fixture helper's precondition is a coupling that can silence contracts for many turns.** Ordinals 371 and
372 assert only about the A1 atlas, which has been available and correct throughout, yet they have been unmeasurable
since TB2 because the helper that hands them the atlas also demands four downstream products. A helper that returns
*all or nothing* converts every downstream failure into a blackout over every upstream contract that shares it.

**Shared error strings are not shared causes.** Ordinals 366 and 370 both render `CellularityNotEstablished`. One
arrives through `topology_error` carrying `origin=RotationSystemInconsistent`; the other is a direct `cut_error`
with no origin. Check the producer before merging two reds that read alike.

**An origin credential used as an arrival credential.** A singularity **port** records where a trace may
*start*; a singularity **node** records what a trace may *end at*. The product allocates the node
**unconditionally** and the port **conditionally** (`portPolicy == BarrierAbsorbed` emits none), then asks the port
a question only the node can answer — so the very policy whose purpose is to suppress ports made a legitimate
arrival unrepresentable. The authoring control: when two tables model the same entity at different cardinalities,
name which one the question is about before writing the lookup. A lookup that reaches its real target *through* an
optional table (`terminalPort->node`) is the smell. `LESSONS.md` §4 81.

**A reachability witness proves the name, not the branch.** CB11's BB5 measure demanded a witness for each
surviving emission site, and its witness for the port-ownership condition is valid — but it fires the *third*
disjunct (a port exists owning a different vertex), which TB9-REV proves the production path **cannot reach**. The
production path always fires the *second* (no port at all). A condition that is a disjunction owes a witness **per
disjunct**; "reachable by some route" is not "reachable by the route production takes". `LESSONS.md` §4 82.

**Geometry locates a failure; only the source predicate adjudicates it.** Every edge of TB9's traced chain has an
exactly 90° dihedral, and the natural inference — sharp implies barrier — is **false on this witness**: v47 is
equally sharp and provably emits ports. The barrier set is region-restricted at `FieldTransportAtlas.cpp:962`
(both incident faces must lie inside the region), so a hard feature edge that *bounds* a region is not a barrier
while one *interior* to it is. Reconstructing a fixture is the right way to find where a trace went and the wrong
way to decide whether the product was correct. `LESSONS.md` §4 83.

**A guarantee is scoped by its call graph, not by its name.** Accepted ordinal 329,
`NetworkDiagnosticsPublishEveryRequiredLocusLosslessly`, has passed every gate since it was written — while the
production projection silently discards fifteen fields of `FieldAlignedCurveNetworkError`. The identity constructs
errors by hand and asserts tokens against `network_error_locus`, a **test-local** renderer. The path every CP4c
production witness reports through — `network_failure_locus` → `SurfaceCellFailureLocusDiagnostics` →
`append_cp4c_failure_locus` — is never touched. The authoring control: an identity whose name asserts a property of
*the system* must be routed through the entry point the system actually uses; if it constructs the DTO itself, its
name may only claim a property of the DTO. `LESSONS.md` §4 78.

**One typed name over many emission conditions is an untyped failure.**
`FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership` is emitted at **twelve** distinct sites for
twelve distinct conditions. When it fired at ordinal 366, static proof could eliminate ten and no further. CB10's
AZ3 rule — one typed name per condition — was applied to the three vertex-star seed conditions and nowhere else.
The generalization has a catch worth remembering: **splitting the enum is often unavailable**, because an accepted
identity may assert the name (ordinal 328 asserts this one). The discriminator then belongs in an **added field**,
which is additive and cannot break an accepted assertion. `LESSONS.md` §4 79.

**A measurement produced and then discarded at a stage boundary — the fourth consecutive instance.** AS1, AU1/AU3,
AY7, and now the trace-scoped group (`traceSeedVertex`, `traceSeedSingularity`, `traceHistory`, `traceSteps`, …).
Each fix corrected the instance that turn's red exposed and left the class intact. AZ5 even required the consumer
set to be found *by search against a predicate* — and it was, for the fields AY7 named. The predicate was scoped to
the wrong set: it must be **every field of the error DTO that has no projected counterpart**, not every field this
turn added. A related smell in the same family: `FieldAlignedCurveNetworkError::publishedFaces` is **declared and
never assigned anywhere**, so `publishedFaceCount=0` renders as an observation on every network error and means
nothing. A dead diagnostic field is worse than a missing one.

**A convention that makes a choice unique is not a precondition on one of the alternatives.** The half-open sector
rule `next > 0 ∧ prev ≥ 0` exists so that exactly one sector of a fan owns each ray — its asymmetry is deliberate
and correct. CB9 asked it a different question: *is this one face the owner of the ray I arrived on?* Asked that
way, the deliberate exclusion of the `previous` ray becomes an arbitrary, orientation-dependent rejection of a
perfectly ordinary arrival, and the answer depends on which side of a shared edge the mesh happened to number
first. The family is familiar — two authorities for one datum, two classifications never proved to coincide — but
this instance is new and sharper: **one correct rule, reused for a question it was not written to answer.** The
authoring control is cheap: when a predicate's name or comment says *partition*, *elect*, *own*, or *choose*, it
answers a question about a **set**; a question about a **single member** needs its own predicate, and the two must
not share a call. `LESSONS.md` §4 77.

**A fixture helper's silent precondition surfaces the first time a witness stops being degenerate.**
`make_zero_transport_field` declares `effort ≡ 0` and no singularities, which is consistent **only** on a mesh that
is intrinsically flat at every interior vertex — because `exactLift = 4K/2π` is `0` only when the angle defect `K`
is. Every consumer before AY5 satisfied that by accident: `make_four_triangle_fan` is entirely planar. AY5 needed
the project's *first* non-flat star — `DEFN-R2` §7.2 asked for a non-coplanar hinge precisely because vertex 30 is
flat and cannot separate `β = α + Θ/2` from `β = α + π` — and inherited the flat-only helper unchanged, producing a
witness the atlas correctly refuses. This is the degenerate-fixture family arriving from the opposite direction:
not a witness too degenerate to exercise the code, but a helper too degenerate to describe the witness. The
counter-control is the one CP3a demonstrated: **make the helper assert its own precondition at runtime**, so the
next author cannot inherit it silently. `LESSONS.md` §2 22r.

**A witness written around an implementation's restriction cannot falsify that restriction.** `DEFN-R2` §7.2 item 5
required a seed "placed exactly on a radial ray". CB9's guards make that unreachable in `FaceInterior` mode, so its
third AY5 instance was written in `EdgeTransit` mode with the comment *"EdgeTransit is the admissible arrival mode
for that exact radial seed"* — encoding the invented restriction into the witness that existed to test it. The
production defect then survived its own falsifier. When a witness must choose a mode, a flag, or a path to make an
assertion pass, ask whether the thing being avoided is the contract or the implementation.

**A measure that orders a projection must name the consumer that renders it, not only the struct it fills.** AY7
said "extend the `RemeshDiagnostics` projection in the same change so the rows have a reader", and CB9 implemented
that exactly: 26 new fields on `SurfaceCellFailureLocusDiagnostics`, all populated in `network_failure_locus`, and
not one of them printed by `append_cp4c_failure_locus`, which is the only renderer the gate identities use. The
field set grew and no reader appeared, because "the projection" named the producer-side artefact. Third consecutive
turn for this pattern (AS1, AU1/AU3, AY7), each one layer further out. Related and equally cheap: **"record the
diagnostic before the guard" means the whole diagnostic, including its container** — AY4 was honoured for the rows
and missed for the audit object, which left `VertexStarTransitState::SeedUnavailable` reachable by no execution at
all. `LESSONS.md` §4 75.

**A representation gap can reveal that the semantic operation itself was never defined.** CB8 first looked like a
missing exact transport type: branch lift is exact, arbitrary-ray transport is not. CB8-REV found the deeper gap:
for a general non-flat vertex star the design has never stated what "straight through the vertex" means when an
intrinsic development has a gap or overlap. Choosing an algebraic type, moving an owner upstream, or adding a
certificate before that semantic choice would only encode an undefined operation more carefully. **Define the
reference geometry and all typed non-owner states before choosing its representation.** This is `LESSONS.md` 74a.

**A definition gap can hide behind a *cost* — and the cost is a first-class architectural fact.** Having frozen
what continuation *means* (Amendment 22), DEFN-R2 found the next layer: electing a developed sector is the sign of a
signed sum of arccosines, and composing the fan's rotations exactly lands in a tower of degree up to `4^k` in fan
length. There is no bounded algebraic representation as valence grows. The wrong responses are all tempting and all
familiar — carry the value through `double` and exactify (the CB6 defect), pick a tolerance, or let "the filter was
inconclusive" become an answer. The right response is to **publish the budget**: a certified filter that returns the
correct answer or defers, an exact fallback that is actually implemented (here it is the *only* path that can decide
a continuation lying exactly on a radial ray, so it is load-bearing rather than ceremonial), and a declared limit
with a typed fail-closed state above it. An unbounded computation with no declared limit is Amendment 19's
unreportable exit wearing a performance costume. Worth recording alongside it: the *worst* case need not be the
*measured* case — at vertex 30 every sign test collapsed to rational identities, and an exactly-recognizable
rational short-circuit is a legitimate optimization as long as it is an exact identity and the general path stays
reachable. `DESIGN.md` Amendment 23, `LESSONS.md` 76.

**A measurement is evidence only if some identity or projection carries it.** `vertexTransitStates` was built at the
failure site by CB6, extended exactly and correctly by CB7, attached to the typed error — and read zero times,
because it has no projection out of the producer. Three consecutive measures (AS1, AU1, AU3) ordered it; three
consecutive reviews observed its absence; every turn complied exactly. The two authoring-time controls cost nothing:
**a measure that orders a measurement must name the identity or projection that will carry it**, and **a diagnostic
added to a typed error for operational reporting must have its projection extended in the same change**. A
diagnostic built and destroyed at a stage boundary is unexecuted authority (`LESSONS.md` 56) wearing a diagnostic's
costume. `LESSONS.md` 75.

**Exact representation can still carry the wrong semantic authority.** TB6-REV adds a sharper instance to the
single-authority family. CB7 correctly removed the CB6 float round-trip and made every value reaching the sector
predicate exact, but the transition step then renamed each target face's `nextPairing->direction` as
`incomingDirection`. Exactness was restored while Amendment 17's one-datum invariant was lost: a branch
**correspondence** (`signedLift`) is not an exact continuous transport of an arbitrary geometric ray, and a local
field representative is not a projection of the original datum merely because it has the corresponding branch
label. **Audit the writer of the semantic datum after every representation correction, not only its numeric type.**
This is also a diagnostic-funnel instance: the resolver owns the exact state rows but the production DTO drops them,
so the most important evidence disappears at a stage boundary.


Four families account for nearly every CP4c-2 turn that went sideways. Check against these *before* writing a
plan or a fix.

**`RP-01 / AUTHORITY_DOMAIN_CONFLATION` — two authorities for one datum.** Rails from `rails_from_atlas` versus
the pipeline's `authoritativeRails` has now bitten **five** times, most recently as R8's gating red at ordinal 359.
A number and the expectation it is compared against must come from the same authority, and every published record
should name the authority it used. Two refinements the fifth instance taught: the production authority is a **chain
of four products** (rails, hard-feature edges, component labels, sheet labels), so naming one of them is not naming
the authority; and a **corrective measure can introduce the very pattern it was written to prevent** — R7-REV's AF3
narrowed "the production torus authority" to "the field" in a parenthetical, and CB7 implemented that exactly.
`LESSONS.md` 59.

**Two classifications of the same datum that were never proved to coincide — the sixth instance, and the first
that is not about rails.** A1's cycle-basis machinery assumes region **boundaries** and **non-traversable** edges
are the same set. That holds for source boundaries and for *separating* feature curves, and is false for a feature
that does not separate — which is exactly the mechanical witness (§7 item 1). Neither classifier is wrong on its
own terms; nobody ever wrote down that they agree, and the code depends on it. When two subsystems partition the
same set of edges/faces for different purposes, state the coincidence as an invariant and test it, or make one
derive from the other.

**`RP-05 / REPRESENTATION_DEPENDENT_IDENTITY` — one digest, two domains.** Semantic identity contaminated with
gauge-dependent provenance. Stabilized at CP2b, fixed for the network at CP3a, and reintroduced by A2a′ now.
Semantic and provenance are **two digests**, always.

**A representation change breaks its consumers in two ways, and only one of them tells you.** Amendment 14 gave a
promoted source edge several derived arcs. A2b read that in two places: a binding check demanding exactly one arc,
which failed **loudly** with a typed code and was localized in one runtime; and a `boundaryVertices` insertion that
assumed a whole-edge arc and therefore **over-inserts into a skip list**, suppressing an ownership check with no
error and no symptom. Fixing only the loud one converts a red gate into a quiet weakening. After changing a
representation, grep every consumer and classify each **by failure mode**, not by whether it compiles — a
permissive consumer is the dangerous one precisely because nothing will report it. `LESSONS.md` 62.

**Two paths that reconcile the same obligation, and only one fails closed.** The sharpest form of the pattern
above, found while deriving Amendment 15. `FieldTransportAtlas` splits prescribed singularities into an interior
map and a boundary map, then reconciles them in two loops written years apart in spirit: the boundary loop
demands an owner and raises `SingularityMismatch` without one; the interior loop looks the owner up, and on a miss
leaves two `std::optional` fields empty and carries on. Both loops "handle" a missing owner. Only one reports it.
A change that moves items from one path to the other — which is exactly what cutting a region does — silently
converts a verified fact into an unverified one. **When one obligation is discharged by two paths, diff their
failure behaviour, not their success behaviour**, and be most suspicious when the split key belongs to a
*different* object than the thing being reconciled (here: the **global** mesh's boundary flag deciding how a
**local** mesh's cycle is checked). `LESSONS.md` 65.

**Wrong-representation, right-arithmetic.** A computation can be internally flawless and describe the wrong
object. Self-consistency is never evidence that the complex is the right one. `LESSONS.md` 22d/22e: check that
the representation can *express* the answer before debugging the algorithm, and convert every consumer of a
representation or none.

**Product property applied to the representation — the same family, one level up.** DEFN-R1 excluded trace-crossed
cut edges by reasoning "the trace is an immutable product, therefore the arrangement may not subdivide it." True
premise, invalid conclusion: `build_arcs` already emits one trace arc per event, and already splits a mandatory
source edge at a trace terminal, without touching the product. An immutability guarantee constrains the *writer*,
not the *derived view*. Before ruling a representation out on an upstream guarantee, read what the existing
consumers of that representation already do — the same control (`LESSONS.md` 22e) that the R2 error missed.

**A green gate proves exactly what it enumerates, and its silence is the finding.** CP4c-2 closed at 365/365 with
one of its three witnesses — the prescribed sphere — unable to reach A2b at all, and with Amendment 14's ordinary
proposal path unexercised. Both were outside the gate by recorded decision, and both are real. A closure record that
lists only what went green is a misleading record: say what the gate did **not** cover, in the same breath. The
converse discipline matters equally — once a gate is frozen and its evidence arrives, do not add conditions to it,
whether the new information favours strictness (`PR8-R044` at R7-REV) or leniency (`AH6` at R10-REV).

**One typed name over many mechanisms — the pattern that has cost the most.** It has now been found twice, in two
different stages, and both times it was believed. `SurfaceCutGraph::topology_error` collapses 36
`GlobalTopologyPlanErrorCode` values into `CellularityNotEstablished`, and the sphere's eight-turn misdiagnosis was
the cost. `FieldTransportAtlas`'s `IncompleteCycleBasis` collapses **seven distinct conditions across eight sites**,
five of which publish only a region id, and the mechanical witness has never been diagnosed at all. **Before
planning around any typed failure that crossed a stage boundary or aggregated several checks, find the translation
site and count how many conditions share the name.** The fix is cheap and additive both times: carry the originating
reason as provenance (AF0 for A2a′, AK1 for A1) without touching the mapping. `LESSONS.md` 57.

**…and the reason you add may itself be a collapse.** The sphere has now been resolved three times, one layer per
turn: `topology_error` collapsed 36 codes → AF0 gave `RotationSystemInconsistent`; nine sites shared that name →
AK3 gave `TraceEventPositionInvalid`; that name covers **two** conditions with opposite fixes. Every layer was
worth resolving and none was wasted, but each was declared "the cause" one turn too early. The rule that falls out:
**when instrumenting a collapsed error, check whether the reason you are adding is itself a collapse before
declaring the layer done** — read the site that sets it and count the distinct conditions that reach it. A one-line
check at authoring time replaces a whole turn. `LESSONS.md` 64.

**Gated observation — the measurement suppressed by its own harness.** Publications gated behind a call that
fails; one error code collapsing several mechanisms with no locus; one witness's failure aborting the loop
before the others publish; a typed error flattened to a bare string. **The witness the design reasoned about is
not the witness that exercises the code** — this bit at ordinal 13, at the C5 torus, and at the sphere. Its most
expensive instance to date is §7 item 1: a `default:` case that assigned a semantic-sounding name to 36 distinct
errors and was believed for eight turns. Related and equally cheap to avoid: an assertion that discards a typed
error it already holds (`ASSERT_TRUE(atlasBuild)` where `atlasBuild.error()` and
`field_atlas_build_error_code_name()` both exist); a diagnostic loop whose per-witness rows are collected and then
summarized down to one row; and a frozen non-gating selector a plan silently declines to run.

**An audit scoped by symbol is not an audit scoped by assumption — and the search can be done perfectly and still
miss.** The sharpest form of the enumeration family, and the first where the discipline was honoured. AM2 told the
implementer that `globalVertexByLocal` becomes many-to-one and that **every consumer of it** must be found *by
search, not by copying the measure's list*. That search was correct, and correctly returned nothing about
`build_singularity_attachments` — which touches neither that map, nor the local mesh, nor the cut, and which holds
the exact assumption Amendment 15 invalidated: *the transport neighbourhood is fully traversable*. It broke the
moment the cut let execution reach it. **Write the audit predicate as the invalidated assumption, in words, and
name at least one consumer that does not touch the changed data structure** — that last item is the evidence the
predicate was not silently reduced to a symbol search. `LESSONS.md` 66.

**A diagnostic channel rebuilt once per stage is a funnel defect wearing three costumes — and the scope of a
measure should come from its reasoning, not from the code you read.** These are one pattern seen from two sides,
and together they account for the last three turns. On the diagnostics side: `fail_surface_cells` takes only
`(code, stage)` and every caller drops the typed error it holds, so TB1, TB2 and TB3-R1 each recovered a locus by
elimination, and each was answered with a bespoke per-code channel — one site had already grown a hand-rolled one
by string-concatenating stage and code. **When the same information is lost at the same boundary twice, give the
boundary a typed payload and convert every call site at once.** On the measures side: AM2 scoped a consumer audit
by **symbol**, AN1 scoped instrumentation by **enum**, and Amendment 16 was written for **A1** — each narrower
than the reasoning that produced it, and each invisible because the implementer complied exactly. **Write the
scope from the argument, and prefer a predicate a reader can apply to code you have not read over an enumeration
of the code you have.** `LESSONS.md` 68 and 69.

**A witness set built to isolate contracts is guaranteed to be silent about degeneracy, so its silence carries no
information.** Every witness this project has run is near-uniform and sliver-free: measured area ratios 2.05–3.17,
maximum aspect ratios 1.72–2.67, valences 4–6, ≤ 152 vertices, all singularities `+1`, genus ≤ 1, every input field
admissible by construction. Production inputs carry area ratios of `10⁶`+ and aspect ratios in the hundreds. Five
architecture proposals were rejected as *unnecessary* on the strength of measurements from that base, and five were
reversed once the base itself was measured. **A rejection of the form "unnecessary, no such case is observed" is
invalid when the evidence cannot produce the case** — the correct disposition is **"unmeasured, witness owed."**
Always separate *"wrong as a diagnosis of what we measured"* from *"wrong as an architecture"*; the first almost
never implies the second. `LESSONS.md` 74.

**Exactness is a property of the derivation chain, not of the final comparison — and a measure that names an
operator will be satisfied by changing the operand.** Amendment 17 required an election to test one datum; AS9
prohibited any tolerance *in the predicate*. CB6 complied with both and still broke the guarantee: it left the
predicate exact and carried the datum through **world-space `double`** — exact barycentric → `to_double()` →
normalized vector → transported in doubles → `from_double_exact()` → exact comparison. An exact comparison on a
float-derived operand is a floating-point decision with an exact final rounding step, and the conversions brought
three silent failure modes into the least observable place in the pipeline. Where speed demands it, only a
**certified filter** is admissible: it returns the provably-correct answer or defers to exact, never an
approximation. `DESIGN.md` Amendment 18, `LESSONS.md` 72.

**A producer with an unreportable exit will eventually report a name that is false.** Four paths in
`resolve_field_vertex_transit` skip a state *before* the per-state diagnostic is recorded, so when the seed itself
dropped, the function returned `VertexTransitSectorUnresolved` with zero candidates **and zero diagnostic rows** —
a typed name asserting an election that never ran. Record the diagnostic **before** any conditional that can skip
the state, and make an empty diagnostic set its own named condition: *"we examined nothing"* and *"we examined
everything and none qualified"* are opposite findings and must never share a code. `DESIGN.md` Amendment 19,
`LESSONS.md` 73.

**An enumeration of candidate *mechanisms* is as dangerous as an enumeration of candidate *consumers*, and a
partition test needs one point, not one point per cell.** At TB3-R1-REV three mechanisms were enumerated for the
vertex-transit red — barrier truncation, singular-vertex holonomy, and a port-policy consumer mismatch — and one
run falsified **all three**: cardinality 2 rather than 0, a vertex that is neither barrier-incident nor
barrier-absorbed, and — proved from the fixture — a **regular** vertex with trivial holonomy. The frozen plan had
listed "exact sector predicate/election defect" among five options and the review's own enumeration dropped it.
**Enumerate mechanisms to design the measurement, never to bound the answer**, and say which observation would fall
outside every listed mechanism. The measurement design was the part that worked: one published field discriminated
all three at once. The technical residue is reusable: the sector predicate is an **exact** half-open partition of
the turn, so a single direction elects at most one wedge — two elections **prove** two distinct directions were
tested, because the routine feeds each cell its own representative. **When an election looks ambiguous, check
whether every candidate is tested against the same datum before touching the partition; when the predicate is
already exact, ambiguity is evidence about the inputs, never a reason to add a tolerance.** `LESSONS.md` 70 and 71.

**Instrument the stage's error surface, not the site that is failing.** AK1/AK2 resolved `IncompleteCycleBasis`
into an enumerated reason plus a full locus row, and did it well — scoped to that one code. One turn later the same
producer failed on the neighbouring code, whose typed error already carries `sourceEdge`, `sourceFace`,
`sourceVertex` and `topologyRegion`, and the harness published only `code/stage`, so the locus had to be recovered
by elimination instead of read. A per-site instrumentation measure buys exactly one turn of visibility.
`LESSONS.md` 67.

**An enumeration inside a measure is read as exhaustive.** Twice in consecutive turns a corrective measure listed
items next to a universal instruction and the list was taken for the instruction's scope. AF3 named "the production
torus authority" then narrowed it in a parenthetical to *the field*, leaving three of four products unconverted;
DEFN-R2 §4 itemized five Amendment-14 changes under "convert every consumer" and omitted A2b's cut-arc binding. Both
were implemented exactly as written and both went red on the omitted part. Put the enumeration in the measure,
produced by search — or say explicitly that the implementer owes it, and require the search rather than a copy.
`LESSONS.md` 59 and 61.

**Transcribed constants and abbreviated digests.** A hash copied from prose is not evidence; a hash written as
`PREFIX…SUFFIX` in a table where values belong invites a later reader to reconstruct the middle, and the
reconstruction looks plausible. Four such values reached an executor and one was not even 64 characters.
Recompute from the named file, and validate any expected digest as exactly 64 lowercase hex at authoring time.
**This has now happened three times** — `R7-ORCH-01`, and again in a rejected TB1 control that transcribed a
packaged-source SHA-256 as a **63-hex** value, despite `LESSONS.md` 22n and measure AE4 existing to prevent
precisely it. A rule that has failed to prevent its own defect twice needs a **mechanism**: AL8 moves the 64-hex
validation into the orchestration payload authoring path, so the check runs where the value is written rather than
depending on an author remembering it.

A sixth, meta-level: **a result that discharges a premise must be reported as a finding, not left as a field
value.** The torus's `pipelinePlanAvailable=true` — the fact that A2a′ works end to end — sat unremarked in an
evidence table under a "semantic red" verdict.

**Artifact bytes are not the whole package contract.** Executable permission is semantic runtime metadata for packaged binaries. A transport can preserve every file hash while silently destroying executability. If a package crosses Actions artifact download/upload boundaries, carry permission-sensitive trees inside a mode-preserving archive and verify modes after a clean round trip. Never make TB repair package permissions: that hides a packaging defect and invalidates immutable-artifact authority.

## 9. Where to look

- `.agents/Directional/tools/` — read-only review helpers: `review_check.py` (authority +
  boundary), `selector_probe.py` (selector hashes, ordinal ↔ identity, test-line → ordinal), and
  `fixture_probe.py` (fixture topology, dihedrals, vertex fans). See `tools/README.md` for the caveats.

**Architecture and plan:** `DESIGN.md` (§4.5 grazing, §4.6 motorcycle graph, §7.2 region derivation with
Amendments 12 and 13), `ROADMAP.md`, `REORIENTATION_PLAN.md`.

**Current state:** `TODO.md` current-focus block; `Future_Chat_Session_Handoff.md` next-turn block;
`Regression_Root_Cause_Tracker.md` for every open defect; `CHANGELOG.md` newest-first for how we got here.

**Durable knowledge:** `LESSONS.md` — organized in eight sections; §2 fixtures/witnesses, §4 single authority,
§5 cross-field conventions and §6 gate authoring carry the most reusable content.

**CP4c history:** `M3_CP4c_Consolidated_Record.md` holds the retired per-turn records with their evidence,
review arcs and withdrawn predictions. Closure records: `M1_`, `M2_`, `M3_CP2_`, `M3_CP2b_`, `M3_CP3_`,
`M3_CP4ab_`, `M3_CP4c1_Closure_Record.md`.

**Key source:**

| what | where |
|---|---|
| tracing, grazing transit, termination | `src/geometry/SurfaceCellTracing.cpp`, `include/directional/geometry/SurfaceCellTracing.h` |
| cut graph (A2a′) | `src/geometry/SurfaceCutGraph.cpp`, `include/directional/geometry/SurfaceCutGraph.h` |
| shared embedded-graph authority | `src/geometry/EmbeddedGraphTopology.{h,cpp}` |
| region derivation (A2b) | `src/geometry/GlobalTopologyPlan.cpp` |
| pipeline wiring, product snapshots | `src/pipeline/RemeshPipeline.cpp` (~6560-6640) |
| exact arithmetic | `include/directional/numerics/BigInteger.h`, `ENumberGMP.h`, `authority/FieldTransportAtlas.h` |
| the whole test suite | `tests/FieldAlignedCurveNetworkTests.cpp` |

**Witness fixtures:** `benchmarks/fixtures/milestone-g/{torus,sphere_prescribed,mechanical_feature}.{obj,rawfield}`.
The two-ring is constructed in the test file, not a fixture.

## 10. Facts worth not re-deriving

- Sphere: 98 V / 192 F / 288 E, `χ=2`, 8 index-¼ singularities at cube corners, 24 ports, 24 traces, 56 events,
  **zero mandatory edges**. Its pre-cut actual embedded graph is `V/E/F = 18/30/18`, one component, `χ=6` — excess
  4 over `sourceChi=2`, hence non-cellular.
  Of 48 directed trace ends, 42 terminate at singularities; the remaining 6 once circulated forever and are now
  terminated by crash-on-contact.
- Torus: 72 V / 144 F / 216 E, `χ=0`, zero singularities, 48 hard-feature mandatory edges forming (inferred,
  and consistent with the measurements) four loops of twelve edges; four annular complement components. Those
  loops **separate** the torus into the four annuli, which is precisely why its hard-feature edges land on region
  boundaries and never enter a local mesh's inner adjacency set.
- Mechanical feature: 152 V / 300 F, and **one** topology region covering all 300 faces —
  `V/E/F = 152/450/300`, `χ=2`, `genus=0`, `boundaryLoops=0`, 152 interior local vertices, 152 expected cycles,
  450 inner adjacencies, `globalEF = localEF = 1,158` at edge `0-3`. Its hard features therefore do **not**
  separate, and since every closed curve on a sphere separates, the feature set must contain at least one **open
  arc**. This is the whole of criterion C2's difficulty.
- Two-ring: actual embedded graph `V/E/F = 9/11/3`; source-edge-barrier proxy `10/11/2`. Both satisfy Euler.
- Torus actual embedded graph **after** cuts: `V/E/F = 72/76/4`, `χ = 0 = sourceChi` — i.e. cuts added 24 vertices
  and 28 edges to the 48/48 pre-cut network.
- `SurfaceCutGraphErrorCode::CellularityNotEstablished` is **not** always a cellularity finding. Via
  `topology_error`'s `default:` it is the bucket for 36 distinct `GlobalTopologyPlanErrorCode` values. Check
  whether the error carries a `sourceFace`: only `topology_error` sets one, so a populated `sourceFace` means the
  failure came from `EmbeddedGraphTopology`, upstream of any cellularity decision. On the prescribed sphere the
  full resolved chain is now `CellularityNotEstablished → RotationSystemInconsistent → TraceEventPositionInvalid`,
  and the last of those is still two conditions wide.
- Cutting a surface along a subgraph `B` of its 1-skeleton: duplicate each vertex into one copy per connected
  component of `star(v) ∖ B` — `copies(v) = d_B(v)` interior, `d_B(v) + 1` on the boundary, so a degree-1 **tip is
  not duplicated**. Then `ΔV = (2|B| − |V(B)|) + ∂`, `ΔE = |B|`, `ΔF = 0`, giving
  **`χ(cut) = χ − χ(B) + ∂`** where `χ(B) = |V(B)| − |B|` and `∂` counts `B`'s vertices already on the boundary.
  Verified against: sphere + one arc → disc; torus + one non-separating loop → annulus; disc + arc to the
  boundary → disc; disc + arc between two boundary points → two discs.
- `dual_cycles` (`geometry/MeshTopology.h:55-74`) emits `#V − #b` inner-vertex cycles **in vertex order**, then
  `#b` boundary cycles, then `2g` generators, with columns indexed into **inner edges only**. That column rule is
  why making an edge a boundary edge removes it from the cycle basis entirely — the mechanism Amendment 15 relies
  on. The row count exceeds the dual cycle space dimension by exactly **1** (one linear dependency), on both the
  uncut and the cut mesh.
- `TriMesh::set_mesh` (`core/TriMesh.h:202-241`) derives `EV`, `EF`, `isBoundaryVertex`, `isBoundaryEdge` and
  `boundaryLoops` from V/F, and `gaussian_curvature` consumes `isBoundaryVertex`. So a cut expressed purely as a
  rewritten face array propagates to every count and curvature with no further bookkeeping.
- `build_source_topology_regions` requires **every** region-boundary vertex to have exactly two boundary
  neighbours (`SurfaceCellTracing.cpp:6905`) and fails the whole `SourceTopologyRegions` product otherwise. An
  open slit is therefore inexpressible at the region level — its tip would have one — which is why Amendment 15
  puts the cut in A1's derived local mesh instead.
- `trace_event_position` (`EmbeddedGraphTopology.cpp:138-173`) returns `std::nullopt` from a single
  `if (positions.size() != 1U)`, so "no carrier matched" and "several carriers matched" are indistinguishable at
  the call site. It also runs **two** passes — segments whose `sourceFace` matches the event's, then, only if that
  found nothing, all segments ignoring the face — so the widening pass can report an *ambiguous* failure for an
  event whose precise pass was *empty*.
- Terminal event kinds: `SingularityPortOrigin(0)`, `FirstContact(1)`, `TraceIntersection(2)`,
  `MandatoryBarrierTermination(3)`, `SingularityTermination(4)`, `SingularityPortJunction(5)`,
  `TraceSelfClosure(6)`. The observed terminal union across witnesses is exactly `{2, 3, 4}`.
- `direction_in_vertex_sector` (`FieldTransportAtlas.cpp:1623-1653` → `direction_in_incident_vertex_sector`
  `:404-426`) is exactly `direction[next] > 0 && direction[previous] >= 0`, indexed **by vertex identity** —
  `SourceFaceTopologyKey::make` **sorts** its three vertices, so canonical-key order is not the mesh row's corner
  order, and `next`/`previous` come from `F(row, (c+1)%3)` / `F(row, (c+2)%3)`. It includes the `next` radial ray
  and excludes the `previous` one. It is an **ownership partition of a fan**, not a membership test for one face.
- A `VertexHit` arrives with **two** possible shapes. `|M| = 2` is the ordinary T2 transit: `d[hit] > 0` and both
  other coordinates negative, so the reversed arrival ray is strictly inside the wedge. `|M| = 1` with a vertex
  landing is Amendment 3: some `d[k] = 0` **exactly** and `p[k] = 0`, meaning the trace runs along the mesh edge
  opposite `v_k` and stops at its far endpoint — and then the reversed arrival ray lies exactly **on** a radial ray.
  Both publish `arrivalMode = FaceInterior`.
- On the mechanical witness, face `(8,10,11)` is mesh row 8 with corner order `[8,10,11]`, and its branch-1
  direction is `(0, −2.77777777777777857, +2.77777777777777857)` over `(v8, v10, v11)` — an exact IEEE zero at
  `v8`. Vertex **10** is one of the four port-emitting singularities (10, 35, 47, 71), so the first segment of that
  port trace is the mesh edge `10 → 11`.
- `FieldTransportAtlas::make` derives a cycle's lift as `exactLift = (cycles · effort + 4 · cycleCurvature) / 2π`,
  where `cycleCurvature` for an inner-vertex cycle is *the Gaussian curvature* (angle defect `2π − Θ`) and `effort`
  is read from `CrossFieldEdgeTransition::effort` — **never recomputed**. Branch transport is
  `QuarterTurn::from_integer(raw.matching)`. So a synthetic field that declares `effort ≡ 0` is asserting a flat
  star, and a synthetic field whose matching does not compose to the resulting lift fails `CycleTransportMismatch`
  before anything else looks at it.
- Vertex-star transit only ever runs at a **regular** vertex: both call sites check
  `field_aligned_singularity_at` first and terminate the trace with `SingularityTermination` when a singularity
  fact exists there. So a witness for vertex-star continuation may not put its interesting geometry on a singular
  vertex — a non-flat center must carry `Σ_cycle effort = −4K` so that its lift is `0`.
- `EmbeddedGraphTopology.cpp` emits `GlobalTopologyPlanErrorCode::RotationSystemInconsistent` from **46 sites**,
  all reachable from `SurfaceCutGraph::make` via `build_embedded_graph_topology` (`build_cut_node_bindings`,
  `build_arcs`, `build_rotation_system`, `walk_graph_faces`) and `exterior_boundary_orbits`. Only **9** publish a
  `RotationSystemInconsistencyReason`, and all 9 also set `sourceEdge` and/or `sourceFace`. Per function —
  `build_arcs` 4 sites / 2 reasons, `build_node_loci` 5 / 3, `build_rotation_system` 27 / 4, `walk_graph_faces`
  9 / 0, `exterior_boundary_orbits` 1 / 0. `GlobalTopologyPlan.cpp` emits the same code from a further 8 sites.
- The `RotationSystemInconsistent` datum is dropped at **three** boundaries in series: the silent producer sites;
  `SurfaceCutGraph::topology_error`, whose `SurfaceCutGraphError` has **no `sourceVertex` field**; and
  `RemeshPipeline::cut_graph_failure_locus`, which publishes only `sourceEdge`/`sourceFace` out of the ten fields
  the error carries.
- `SurfaceCellDiagnosticProductSnapshots` retains `fieldTransportAtlasError` but has **no** `surfaceCutGraphError`
  and no `globalTopologyPlanError`; `productSnapshots.surfaceCutGraph` is assigned only on success. So a cut-graph
  failure leaves no typed object behind.
- The two CP4c witness-observation idioms differ in what they can see. `build_cp4c_production_fixture` **throws**
  unless all five of `sourceAuthority`, `atlas`, `network`, `cutGraph`, `plan` are retained, rendering only
  `terminalFailureLocus` through `append_cp4c_failure_locus`. `observe_cp4c_witness` re-invokes each stage directly
  from the four production inputs and therefore holds each typed error, rendering the cut-graph reason, trace,
  event and position diagnostics. Ordinals 366 and 368 differ by exactly this choice.
- `SurfaceCutGraph::make` certifies inside a `while(true)` cut-proposal loop and returns the **first**
  `certify_actual_embedded_graph` failure, so a published cut-graph error does not say whether it came from the
  initial uncut certification or from a later proposal.
- Grazing is **edge transit**, not termination — decided on a continuity argument, not on cost data.
- Trace termination is **crash-on-contact** (motorcycle graph), on an exact predicate, with mutual termination
  on a tie; the production arrival priority is `ArcLengthFiltered` with a certified forward error bound.
- GMP/GMPXX linkage is mandatory for every compile; fallback exact arithmetic is not authoritative build
  evidence.
- `FieldAlignedCurveNetworkError` carries far more than the locus can render. The projection
  `RemeshPipeline.cpp::network_failure_locus` → `SurfaceCellFailureLocusDiagnostics` carries `sourceVertex`,
  `sourceEdge`, `sourceFace`, `branch`, `topologyRegion`, `vertexArrivalMode`, `vertexTransitStates`,
  `vertexStarTransit` and `publishedFaces` — **and nothing else**. `traceSeedVertex`, `traceSeedSingularity`,
  `traceHistory`, `traceSteps`, `traceStepBudget`, `traceCombinatorialVisits`, `traceCombinatorialVisitAllowance`,
  `singularity`, `rail`, `relatedSourceFace`, `relatedBranch`, `signedLift`, `parameter`, `exactValues` and
  `publishedEdges` have **no projected field at all**. Their only readers are the test-local renderer
  `network_error_locus` (`tests/FieldAlignedCurveNetworkTests.cpp:4808-4834`) and assertions in ordinals 328/329.
- `append_cp4c_failure_locus` prints in a **fixed order**: `sourceVertex`, `sourceEdge`, `sourceFace`, `branch`,
  `topologyRegion`, `arrivalMode`, `publishedFaceCount`, `publishedFaces`, `barrier*`,
  `transportStarComponentCount`, `vertexTransitState[…]`, `vertexStar*`. So a **missing** token proves the
  underlying optional was empty — absence is evidence, not truncation.
- `FieldAlignedCurveNetworkError::publishedFaces` is declared (`SurfaceCellTracing.h:311`) and **never assigned**
  anywhere in `src/` or `include/`. Every network-stage error renders `publishedFaceCount=0` by construction.
- The mechanical fixture is **closed with `χ = 2`** — 152 V / 300 F, 0 boundary edges. Its `x = ±1.4` sides are
  50-face **coplanar** patches, so many interior edges there have an exactly 0° dihedral and can never be hard
  feature edges (and therefore never barriers, and never a `terminalBarrier`). Face row 51 is exactly `(36,38,39)`.
- `terminalContact` is set by `field_aligned_publish_contact` but is **never read in
  `finalize_field_aligned_events`**; that function branches only on `terminalSingularity` and `terminalBarrier`,
  and everything else falls through to a **loop-closure** test. `field_aligned_first_trace_contact` compares trace
  `i` only against indices `< i`, so it can never match trace 0 — and it declares a contact on **mere source-face
  coincidence**, with no crossing test (`field_aligned_segments_properly_cross` feeds the census only).
- A singularity **port** and a singularity **node** are different authorities with different cardinality.
  `nodeVertices.insert(singularity.sourceVertex)` runs for **every** singularity, before and outside the
  `portPolicy` test, and `candidate.nodes` is materialized **before** `candidate.singularityPorts`. The port loop
  then skips `BarrierAbsorbed` entirely, so such a singularity has a node and **zero** ports. Ports constrain a
  trace's **origin** only.
- `FieldSingularityFact::PortPolicy` is `BarrierAbsorbed` iff the vertex is in `slitCycleByGlobalVertex`
  (`FieldTransportAtlas.cpp:2467-2470`), populated at `:2296-2300` iff *not a mesh-boundary vertex* ∧
  *in `local->barrierVertices`* ∧ *singular*. Local-cycle and slit-cycle ownership are an exclusive XOR over all
  singularities (`:2428-2432`). On a closed witness this reduces to **singular ∧ barrier-incident**.
- **Barrier edges are region-restricted, not merely sharp** (`FieldTransportAtlas.cpp:955-966`): a hard feature
  edge becomes a barrier only when **both** incident faces lie in the region being localized. So a sharp edge that
  bounds a region is not a barrier. Do not use dihedral angle as a proxy for `barrierVertices` — v47 has three
  exactly-90° incident edges and is proved `Emit` by TB9's own trace seed.
- `FieldBoundaryPoint::source_support()` (`FieldTransportAtlas.h:601-610`) returns `SourceVertexSupport{edge.first()}`
  at parameter 0, `SourceVertexSupport{edge.second()}` at parameter 1, and `SourceEdgeSupport` strictly between.
  Both `VertexHit` constructions are built to invert exactly that mapping, so on the production path the terminal
  support vertex always equals `decision.sourceVertex`.
- `trace.terminalSingularity` is set at exactly one place — the `VertexHit` branch of
  `field_aligned_advance_trace_proposal` — via `field_aligned_singularity_at(atlas, *decision.sourceVertex, …)`,
  which matches **by vertex**. The `VertexHit` check runs **before** the `mandatoryByEdge` barrier check, so a
  vertex that is both a barrier endpoint and a singularity is adjudicated as a singularity termination.
- Trace history in a production locus is exact: `entryParameter=1/1` on every row means every entry point sat on a
  vertex, i.e. the trace transited vertices rather than edge interiors. `incomingCarrier=none` on a first segment
  is a port origin.
- `RayOrderKey` (`src/geometry/EmbeddedGraphTopology.cpp:811`) lives in an **anonymous namespace** inside
  `directional::geometry::embedded_graph_topology_detail` and appears in no header. Every use is in that one file
  (`:978`, `:995`, `:1117`, `:1206-1207`), so it has **no external consumers** — a change to the key or its
  predicate cannot leak by linkage, only through the rotation that file publishes.
- At a **vertex** locus, `key.primary = 2·faceSlot + 1` for a trace ray and `2·edgeSlot` for a Mandatory/Cut ray,
  so trace rays interleave between edge rays; `key.secondary = port->ordinal` for trace rays and defaults to `0`
  otherwise, which is why the collision predicate additionally requires `kind == Trace` on both sides. At an
  **edge** locus the formulas differ (`sideRank`-based `primary`, `edge_locus_secondary_rank` `secondary`) and the
  collision predicate does not apply, because it tests `locus.vertex.has_value()`.
- The rotation incidence map pushes `Forward` at `arc.firstNode` and `Reverse` at `arc.secondNode`
  **unconditionally**, so a **self-loop arc contributes two darts to the same node**. Both darts share `arc.trace`,
  hence the same origin port and the same `secondary`; only `orientation` (via `trace_ray_face` reading
  `segments[firstSegment]` vs `segments[onePastLastSegment-1]`) can separate them.
- `certificationAttemptIndex` counts **completed non-cellular certifications** (`SurfaceCutGraph.cpp:344-346`): the
  counter increments only after a certification succeeds but fails `proves_cellularity()`. So
  `certificationAttempt=0` with `certificationCutEdges=0` means the failure occurred on the **first certification
  of the uncut graph, before any cut proposal was evaluated**. `cutCandidateCount` **is** a real measurement on
  that path (`result.cutCandidates = evidence`); `nonDiscComponentCount` and `remainingAdmissibleEdgeCount` are
  **not** — they are defaults there.
- `GlobalTopologyPlanError` declares `arc`, `networkEdge`, `trace`, **`secondTrace`**, `sourceEdge`, `sourceFace`,
  **`secondSourceFace`**, `singularity`, `sourceVertex` and the rotation reason — the `second*` fields exist for
  two-sided comparisons. It has **no field for the colliding `primary`/`secondary` values**, so those are
  unrecoverable from any current locus render.
- At a vertex locus `RayOrderKey::secondary` is written at **exactly one** site (`build_rotation_system`, vertex
  branch) as `port->ordinal` — the ordinal of the port the trace **originated** from, with no check that the
  port's source vertex is the locus vertex. At an **edge** locus the same field is written from
  `edge_locus_secondary_rank`, which is locus-relative, exact and explicitly geometry-free. The vertex branch is
  the outlier; the edge branch is the convention to follow.
- `secondary` is the **second** member of a defaulted `operator<=>`, so it is consulted **only when `primary`
  ties**. For two trace rays `primary` ties **iff they share a wedge**. Consequence, useful for any future change:
  in every configuration that certifies today, `secondary` is never consulted for trace rays, so redefining it
  cannot alter a rotation that currently succeeds.
- A singularity's own emanating rays are separated by `primary` alone when each port occupies a different wedge —
  which is the ordinary case. At v47 the three ports (ordinals 0, 1, 2) sit in three of its four wedges, so the
  ordinal tiebreak was never load-bearing there.
- `tools/fixture_probe.py fan <v>` reproduces `build_vertex_fan_slots` and prints both `primary` forms. For v47 it
  independently reproduces the TB12 runtime census exactly: face slots 1, 3, 5, 7 in rows 59, 100, 101, 290 with
  trace-ray primaries 3, 7, 11, 15, and a closed fan.
- `segment.edgeTransitExit` is assigned on exactly two lines (`SurfaceCellTracing.cpp:2399`, `:3061`), both from
  `edgeTransit.exitPoint` — i.e. **only on the edge-transit path. A `VertexHit` exit never sets it.** Any consumer
  that treats it as "the segment's exit" silently excludes every Amendment-3 vertex arrival.
- `vertex_trace_ray_second_point` resolves a ray's second point differently by orientation. **`Reverse` always
  succeeds**: it returns the segment's own `entryPoint`, which lies on an edge of that segment's face by
  construction. **`Forward` can fail**: its chain is `edgeTransitExit` → next segment's entry *expressible in this
  face* → `terminalContact` in this face → `terminalPoint` expressible in this face → `nullopt`.
- `VertexTracePortOrdinalInvalid` is emitted at **two** sites in `build_rotation_system`
  (`EmbeddedGraphTopology.cpp:1204` legacy port lookup / negative ordinal, and `:1217` CB15's
  `vertex_locus_secondary_parameter == nullopt`), both setting only reason + `sourceVertex` + `sourceFace`. The
  rendered locus cannot separate them.
- Network **node ids are monotone in vertex index** — `nodeVertices` is a `std::set<SourceVertexId>` and nodes are
  assigned in that sorted order (`SurfaceCellTracing.cpp:4239-4244`) — and `build_rotation_system` iterates
  `incidences`, a `std::map` keyed by node id. So rotation processing visits vertices in increasing vertex index,
  which makes "an earlier TB reached a later vertex" a proof that every earlier vertex passed.
- Vertex **10** mirrors vertex 47: degree 4, closed fan, angle defect exactly `π/2`, three 90° edges and one 0°
  edge. Face `(8,10,11)` is **mesh row 8** at **fan slot 7**, bounded by edges `10-11` (slot 6) and `8-10`
  (slot 0). Reproduce with `tools/fixture_probe.py fan 10`.
- **Node ids order the rotation, and contact nodes come last.** Vertex nodes are created first by iterating
  `nodeVertices` (a `std::set<SourceVertexId>`); `field_aligned_append_contact_node` then takes
  `nodeIndex = candidate.nodes.size()`. `build_rotation_system` iterates `incidences`, a `std::map` keyed by node
  id, so **every vertex locus is processed before every edge locus**. This makes "an earlier TB failed at a vertex
  locus" a proof that no edge locus had been reached.
- **An edge locus is not only a cut crossing.** `build_node_loci` assigns `NodeLocus.edge` from
  `cutNodes.syntheticCrossings` *and*, in its events loop, to **any node with no vertex locus whose event carries a
  `sourceEdge`**. Vertex loci come only from singularity ports and mandatory-edge endpoints, so the remainder are
  **contact nodes** — which is why an edge locus can appear with `certificationCutEdges = 0`.
- `edge_locus_secondary_rank` has **five** `return std::nullopt` sites and no typed reason: ray-face unavailable,
  source-face record missing, contact edge not in the face, opposite carrier missing or coincident with the contact
  index, and the source-vertex fallback failing to bind. Its single emitter
  (`EmbeddedGraphTopology.cpp:1440`) retains only `sourceEdge`, `sourceFace` and the reason — no arc, trace,
  orientation, segment interval or carriers.
- The helper's two rank families are indexed differently: carrier-to-carrier ranks are
  `2·((otherIndex + 3 − contactIndex) mod 3)`, indexed by **edge** order, while the source-vertex fallback returns
  `1 + 2·corner`, indexed by **corner** order. Any change must show they stay mutually consistent and
  collision-free.
- Face `(25,30,31)` is **mesh row 41** — the row `DEFN-R2` proved unreachable **as a vertex-30 continuation
  owner**. That proof is about continuation ownership at vertex 30 and is *not* contradicted by a trace holding a
  segment in row 41 reached through ordinary transits. Vertex 30's fan is degree 6 and closed: rows 43, 218, 209,
  208, 41, 40 at slots 1, 3, 5, 7, 9, 11.
- `proposal.nextIncomingCarrier` is assigned at exactly **one** site (`SurfaceCellTracing.cpp:3122`), on the
  **edge-exit** continuation. The `VertexHit` continuation returns having set only `nextFace`, `nextBranch`,
  `nextEntryPoint` and `endArrival`. So **a segment entered by a vertex transit carries
  `incomingCarrier == std::nullopt`**, indistinguishable by type from a port-origin first segment — the two are
  separated only by whether the segment is the trace's first.
- `SourceFaceRecord::edges[i] = (vertices[i], vertices[i+1 mod 3])` — the convention `face_orients_edge_forward`
  walks. So edge `i` joins corners `i` and `i+1`, and is opposite corner `i+2`. TB15's retained
  `contactIndex = 2` for locus `25-31` in face `(25,30,31)` reproduces from this exactly, which is a free
  cross-check on any retained edge-locus evidence.
- `edge_locus_secondary_rank` ranks a ray by its **far end inside the face** — the end opposite the contact edge:
  the entry side for `Reverse`, the exit side for `Forward`. Carrier far ends take even ranks
  `2·((otherIndex + 3 − contactIndex) mod 3) ∈ {2,4}`; corner far ends take odd ranks. Walking the boundary from
  contact edge `c` gives the order `corner c+1, edge c+1, corner c+2, edge c+2, corner c`, so the corner rank must
  be `1 + 2·((corner + 2 − contactIndex) mod 3)` — the shipped `1 + 2·corner` coincides **only at
  `contactIndex = 2`**.
- The four port-emitting singularities of the mechanical fixture are **v10, v35, v47, v71**. `trace.sourceVertex`
  always names one of them and says nothing about which face a later segment is in — it is trace-global
  provenance, not a face-local datum.
- `GlobalTopologyPlan.cpp` fragment accounting: per non-terminal-slit segment the region loop does
  `++tracePieceCount[face]` **once** and `add_fragment_orbit(face, forwardOrbit)` / `(face, reverseOrbit)` —
  **two** insertions into a `std::set<std::size_t>` of global orbit ids. `add_fragment_orbit` silently **skips**
  any orbit in `exteriorOrbits`. The validation at `:779` then asserts `set.size() == tracePieceCount + 1`.
- A **terminal slit** contributes zero to `k`: the loop `continue`s on `is_terminal_slit` before touching either
  `tracePieceCount` or the orbit set, so slits are excluded from **both** sides consistently. The mechanical
  witness has **10** terminal slits.
- `build_regions` publishes a full `fragment_reconciliation` diagnostic — `source_face`, `fragment_orbit_count`,
  `trace_piece_count`, `expected_fragment_count` — for every face after all validation passes, and since CB20 also
  for the first failing face immediately before its early return. **Both are gated on
  `fragment_diagnostics_enabled()`** (`GlobalTopologyPlan.cpp:81–84`), which reads
  `DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS`; when unset, `diagnostics` is `nullptr` at `:1814–1816` and every
  `M3_CP4AB_FRAGMENT_DIAG` record is suppressed. The artifact-only gate runner never sets it.
- Face `(0,1,102)` is **mesh row 259**, stored corner order `(102,1,0)`. Vertex 0 is a chamfered box corner:
  degree 4, angle defect **1.767801150**, edge `0-1` a **90 degree** sharp edge shared by rows 0 and 259.
- **CP4c document layout since 2026-09-03:** `M3_CP4c_Current_And_Forward.md` holds current state, the frozen
  successor and the candidate index; `M3_CP4c_Consolidated_Record.md` holds history and carries a **folded
  document index** that resolves all 35 folded per-turn plans/reports/records (their full text stays in git
  history). The six frozen-definition documents were merged **verbatim** into `M3_CP4c_Frozen_Definitions.md`
  (Parts I–VI, with a citation map from the former filenames; operative definitions are Part III for CP4c-2 and
  Part VI for CP4c-3). Every `Required_Green_Selector_*.txt` is untouched. All former `Architecture_M3_CP4ab_*`
  references now resolve to `M3_CP4ab_Closure_Record.md`, which carries their index. Since 2026-09-03 every
  REVIEW turn folds its own superseded per-turn documents into that index under `CLEAN_UP_POLICY.md`.
- The face walk at `EmbeddedGraphTopology.cpp:1698–1775` is the canonical rotation-system face permutation:
  `successor[dart(reversed(inc))] = dart(rotation.counterClockwise[(index + count - 1) % count])`. It is validated
  total before use — each dart has incidence count exactly 1, every successor is assigned, each orbit closes within
  the dart budget, and `FaceWalkOrbitReenteredAtDifferentStart` rejects a foreign re-entry. **Its orbits are the
  cycles of a permutation, so it cannot merge darts that a valid rotation system separates.**
- Two darts of one arc share a face orbit exactly when the arc lies on no cycle (a bridge) or is non-separating in
  the embedding. A pendant end anywhere on a trace makes every arc of that trace's path a bridge. The mechanical
  witness has **10 terminal slits**, i.e. 10 pendant ends.
- After validation, `fragmentOrbits[face]` is consumed only at `GlobalTopologyPlan.cpp:925–945`, to register the
  face with the region draft of each owning orbit. A face whose two sides share one owner is registered once — the
  correct membership under shared ownership — so loosening the count check introduces no downstream inconsistency.
- Mechanical fixture, **vertex 1**: degree 6, angle defect **−0.000000000** (regular), edges `0-1` and `1-4` both
  **90°** sharp; `0-1` shared by rows 0/259, `1-102` shared by rows 258/259. It is the corner the failing
  carrier-less incidence binds to.
- `kFragmentFailureEvidenceLimit = 8` bounds every retained fragment-failure evidence list.
- The unlabeled-face seeding block is `GlobalTopologyPlan.cpp:1102–1165`. `unlabeledFaces` is built by iterating
  `topology.faces` (a `std::map`, so **key order**) and keeping every face with no `fragmentOrbits` entry, so the
  first unlabeled face is normally the lexicographically minimal face key. **`(0,1,2)` is row 0 of the mechanical
  fixture and row 0 of the torus fixture.**
- The seeding skip at `:1136–1139` is silent: when a two-owner labeled face has no unique
  `edgeOrbitEvidence[(face, edge)]` row, the edge contributes no seed and leaves **no trace at all**.
- `SurfaceCellTracing.cpp` constructs contact nodes at trace intersections bound to a source face
  (`field_aligned_append_contact_node(candidate, *nextFace)`, `FieldAlignedNetworkEventKind::TraceIntersection`,
  `contact->sourceFace`). **Chord crossings inside a face are a modelled case**, so `localFragments = k + 1 + c`
  for `c` interior crossings — `k+1` is only the non-crossing special case.
- TB19 mechanical census: **70** face rows (all evaluated, all `chordsCrossInside=false`, 18 with `ownerDeficit=1`,
  none above 1), **26** arc rows, **12** trace rows, all untruncated; total face-walk orbits **6**, exterior **0**,
  non-exterior **6**; arc 15 `sharesOrbit=true`; trace 1 `terminalSlit=false`.
- CB21's `TraceFragmentOwnerEvidenceDiagnostic` (`include/directional/geometry/GlobalTopologyPlan.h:299–319`,
  projected through `RemeshDiagnostics.h:162–180`) is the established production-path census channel; extend it
  rather than adding a parallel one.
- **`M3_CP4c_Frozen_Definitions.md` Part I §3 is the normative adjudication of
  `UncutFaceComponentOrbitSeedNotUnique`:** the guard is correct, the producer is behaving correctly, there is no
  bug at that line, and multiple seeds report a missing input — the network is not a cut graph. **Parts IV and V**
  prohibit relaxing `proves_cellularity()`, the fragment-count invariant, or that guard. **Part VI** is scoped to
  vertex-star continuation and lifts none of them.
- Cellularity test for any witness: `V − E + F = χ(S)` per connected component of the embedded graph. Part I
  settled the torus with `V = E = 48`, `χ = 0` ⇒ `F = 0`, a contradiction. The mechanical witness has `χ = 2` and
  `F = 6`; its `V`, `E` and component count are **not retained**, which is the entire missing datum.
- TB19's "26 arcs" is the **fragment-owner** census over trace arcs, not the embedded graph's `E` — the graph also
  carries cut-graph arcs. Do not substitute one for the other.
- TB20 component census: **9** components, untruncated. Component 0 has **191** faces and **97** boundary edges;
  64 rows of each are retained and explicitly truncated. Owner counts in the window split 47×1 / 17×2; barrier
  classes 46 `none` / 18 `traceTouched`; seeds 44×orbit 0, 1×orbit 1, 1×orbit 3.
- **Selector naming and the chain:** `Required_Green_Selector_Manifest.md` is the derived index of all 19
  selector files — identity count, LF SHA-256, prefix parent, appended identities, role. **A selector filename is
  not an identity count:** files 357–384 are named by their count, but
  `Architecture_M3_CP4c3_Required_Green_Selector_385.txt` holds **388** identities. Its bytes are frozen and
  correct; future files are named by their resulting count. **357 and 358 are off-chain** — 357 is not a prefix of
  358 and 358 is not a prefix of 361 — so they hold unique bytes; 361 through the current gate form one strict
  prefix chain. Regenerate the manifest with `tools/selector_manifest.py`.
- **The mechanical actual embedded complex is cellular:** `V=22, E=26, F=6, componentCount=1, sourceChi=2,
  residual=0`. `SurfaceCutGraphCellularityCertificate::proves_cellularity()`
  (`src/geometry/SurfaceCutGraph.cpp:478`) additionally requires `graphComponentCount == sourceComponentCount`,
  `eulerCharacteristic == sourceEulerCharacteristic`, balanced boundary-orbit accounting, and **every face to
  satisfy `proves_disc_topology()`**. `canonical_candidate` returns a cut graph only after it holds.
- **Part I §3 is an implication with a premise.** It licenses "the network is not a cut graph" only where the
  complex is independently shown non-cellular — as on the torus, via `V = E = 48`, `chi = 0`, so `F = 0`. It says
  nothing about the source-face projection, and nothing about a witness whose complex certifies cellular.
- **The certificate and the seed guard test different objects.** Certificate faces are regions of the surface
  bounded by arcs through triangle interiors; the seed guard's components are sets of whole source triangles joined
  across non-barrier source edges. The projection is faithful only if every pair of adjacent uncut triangles in
  different certificate faces is separated by a `componentBarriers` edge - stated and checked by neither.
- **Component 0 boundary attribution (complete, untruncated):** orbit 0 -> **81** edges, orbit 1 -> **1**, orbit 3
  -> **1**, plus **14** barrier/no-seed, totalling 97. TB20's first-64 window showed 44/1/1, so **both minority
  rows lie inside the retained window** in both runs.
- Ordinals **371 and 372 pass** as of TB21, reaching their own assertions for the first time. Their fixture
  accessor is **test-only** and is never product authority.
- **`projectionFaithfulnessResidual` is a structural zero.** `GlobalTopologyPlan.cpp:1362–1389` requires an edge
  to be in `certificateSeparatingSourceEdges` **and not** in `componentBarriers`. The first set is populated only
  from Mandatory and Cut arcs (`:1191–1200`); those source edges are exactly `mandatoryEdges` (`:674`) and
  `cutEdges` (`:649`), and `componentBarriers = mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges` (`:1114–1116`).
  **The conjunction is empty. The loop body never executes.**
- **`certificate_side_orbit` (`:1172–1184`) is not the certificate.** It returns
  `edgeOrbitEvidence[(face,edge)]` when unique, else `fragmentOrbits[face]` when size 1 — the same two lookups the
  seed rule uses (`:1284–1299`). The row's component-side value is then **assigned equal** to the labeled side
  whenever `barrierClass == None` (`:1272–1278`).
- **`certificateSideOrbitsByEdge` (`:1204–1212`) *is* certificate-derived** — it reads `walk.orbitByDart` for the
  arc on a mandatory or cut edge — but it is consulted only inside the unreachable residual loop.
- TB22 minority rows: edge `10-79` seed **3**, faces `10,79,151` ↔ `10,11,79`; edge `29-35` seed **1**, faces
  `28,29,35` ↔ `29,35,91`. Both `seedRule=edgeOrbitEvidence`, `labeledFaceOwnerCount=2`, `barrierClass=none`.
  Their reported certificate-face agreement is a **tautology**, not corroboration.
- Torus census at TB22: `V=72, E=76, F=4, componentCount=1, sourceChi=0, residual=0` — `72 − 76 + 4 = 0 = χ`, so
  the torus complex is cellular once its cut edges are present.
- **The immutable package never contains a `test-data` tree.** `.github/workflows/agent-compile-reusable.yml`
  copies only the eight compiled targets into `$OUT/bin` and the two static libraries into `$OUT/lib`, plus the
  source archive and metadata. No workflow in the repository references `test-data`. Fixtures reach the binaries
  only because the **execution harness stages them**.
- **`tests/TestFixturePaths.h:51–64` resolves fixtures** as (1) `executableDirectory.parent_path()/test-data` when
  `…/benchmarks/fixtures` exists, else (2) `executableDirectory/test-data` — the layout
  `cmake/DirectionalTests.cmake`'s `directional_copy_manifest_fixture` builds under `$<TARGET_FILE_DIR>` — else
  **(3) it returns the sibling path regardless of existence**. Branch 3 is the fail-open.
- **`GlobalTopologyCertificateDiagnostics.h` is CB25's certificate authority.** `certifiedFaceBySourceFace` is
  built from `directCertifiedFaces` plus per-component certified-face sets and assigns a face's owner only when
  that set has exactly one element (`:135–137`). `certificate_side_orbit` no longer exists.
- **CB25's CA3 pair measurement is satisfiable** (`:181–200`): it quantifies over edges with two incident faces,
  not in `componentBarriers`, **both sides uncut**, incrementing `examinedPairCount` for each and
  `differingPairCount` only when both certified faces are known and differ. There is no
  `certificateSeparatingSourceEdges` intersection, so CB24's structural zero cannot recur in this form.
- TB23-EXEC raw invalid-attempt fields, **audit-only**: 342 PASS / 55 RED, accepted 327/365, ledger
  `839e95fe…7ffc76e85e8d`, ordinals 394–397 `PASS,PASS,PASS,RED`, CA2/CA3/CA4 row counts `0/0/0`.
- **`SurfaceCutGraphFaceCertificate` (`include/directional/geometry/SurfaceCutGraph.h:53–63`) publishes `orbit`,
  `boundaryWalkCount`, `boundaryArcCount`, `discTopologyEstablished` — and nothing else.** No source-face
  membership, no boundary arc list. `certificateFaceOrbits` is only the *set of those orbit ids*, used as a
  membership filter.
- **CB25's edge-side certified faces are the seed by another route.**
  `add_direct(segment.sourceFace, thirdEdge, sideOrbit)` and the carrier-less
  `add_direct(…, forwardEdge/reverseEdge, forwardOrbit/reverseOrbit)` write `walk.orbitByDart[dart]` — the same
  quantity `edgeOrbitEvidence` records — filtered only by `certificateFaceOrbits`. Hence every available labeled
  certified face **equals its seed**.
- **`resolve_certificate_face_projection` unites across every edge not in `embeddedGraphSourceEdges`**, which holds
  only mandatory and cut source edges (`GlobalTopologyPlan.cpp:427`). It therefore merges across trace-crossed
  edges and is **coarser** than `componentBarriers`.
- TB23-R1 mechanical evidence: `m3Cp4c3CA3;examined=273;differing=0;witnessCount=64;truncated=true`;
  `m3Cp4c3CA4;observed=0;unavailable=191;distinct=0;multiset=;truncated=false`; minority rows `10-79` seed 3 and
  `29-35` seed 1, both with `componentCertifiedFace=unavailable` and `labeledCertifiedFace` equal to the seed.
- Ordinal 397's exact difference: expected `;sourceFace=2,4,6`, received `;sourceFace=2,4,6;cutCandidateCount=0`.
- **`certify_actual_embedded_graph` (`src/geometry/SurfaceCutGraph.cpp:356–380`) calls the same
  `build_embedded_graph_topology(sourceFaces, sourceVertexCount, sourceAuthority, network, cutEdges)` the plan
  calls at `GlobalTopologyPlan.cpp:2364`**, derives `embedded.faceWalk` from it, and then publishes only counts.
  The two invocations are independent — one object, two constructions (`M3-CP4c3-DEFN-R3-CAND-01`).
- **Part VII (DEFN-R3) is the operative CP4c-3 definition alongside Part VI**, and supersedes Parts IV–VI where
  they conflict. It lifts the fragment-count prohibition with reasons, strengthens `proves_cellularity()`, and
  relocates `UncutFaceComponentOrbitSeedNotUnique` into a map-consistency check.
- **The branch discriminator is a lookup, not a measurement:** certified owners of component 0's 191 faces — not
  all equal ⇒ missing barrier; all equal ⇒ mis-read seed.
