# Directional — Orientation

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

**Currency.** Last updated 2026-08-30 at `M3-CP4c-3-DEFN-R1`, which settled AL2 by declaring **Amendment 15** — a
topology region's *transport domain* is the region cut along its non-separating barrier set — and issued measures
**AM0–AM9**. Exact next is `M3-CP4c-3-CB2`, Code + Build, runtime-free. If the head commit is far ahead, trust
`TODO.md`'s current-focus block and `Future_Chat_Session_Handoff.md`'s next-turn block over this file's
"where we are" section; the architecture and recurring-defect sections age much more slowly.

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

**Accepted authority: CP4c-2 at 365/365.** CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are CLOSED / ACCEPTED. The
accepted selector is cumulative and each checkpoint's prefix is byte-identical to its predecessor, so
`first_red_ordinal` is comparable across the whole arc.

| selector | SHA-256 |
|---|---|
| accepted 316 prefix | `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` |
| accepted 346 prefix | `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` |
| accepted 353 prefix | `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5` |
| accepted 355 | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| CP4c-2 357 prefix (superseded as a gate; retained) | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| CP4c-2 358 (**withdrawn** as a gate; retained) | `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62` |
| CP4c-2 361 prefix (superseded by accepted 365; retained) | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` |
| **accepted 365 (CP4c-2, closed at R10)** | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **CP4c-3 gate 367 (frozen at DEFN, unselected)** | `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf` |

**All nine values are authority**, each recomputed from committed bytes; the first eight were re-verified at
`R10-REV` and 367 was computed at `M3-CP4c-3-DEFN` when its file was created. The CP4c-3 gate file's `head -355`,
`head -357`, `head -361` and `head -365` all reproduce their frozen hashes. `Architecture_M3_CP4c1_Required_Green_Selector.txt` was retired in a cleanup and **no longer exists**; that is by
design, because every accepted hash survives as a **prefix of its successor gate file**. Derive them from the
current CP4c-3 gate file: `head -316`, `head -346`, `head -353`, `head -355`, `head -357`, `head -361`,
`head -365`. 358 has its own retained file. **Every gate file reproduces all of its predecessor prefixes exactly**, which is what keeps
`first_red_ordinal` comparable across the whole arc. **Recompute rather than copy**, validate every expected digest as exactly 64
lowercase hex at authoring, and never write one as `PREFIX…SUFFIX` where a value is expected: `PR8` orchestration
defect `R7-ORCH-01` was four hashes expanded back to full length from abbreviations, one of them only 63 characters
long.


**CP4c-2 CLOSED / ACCEPTED at 365/365.** R10 (run/job `33331453506 / 99310594268`) executed the frozen gate from
ordinal 1 against immutable CB9 package `9736088354`, one identity per fresh process, with green immutable
pre/postflight and every mutation and benchmark flag false. Accepted source
`57444781af7bdc460e38cc68930a9a8c8199eeea`; package SHA-256 `78f542c7…0490ebdf`. Criteria **C1**, **C3** and **C6**
are green.

**What CP4c-2 did not deliver**, so the closure is not read as more than it is: the **prescribed sphere** still
fails before cut selection and was outside the gate by recorded decision, so CP4c-2 closed with one of its three
witnesses unable to reach A2b at all (§7 item 2); Amendment 14's **ordinary** trace-crossed proposal path is
unexercised (§7 item 3); and the zero-node/zero-arc question was undecided (§7 item 4). All three passed to CP4c-3,
which has now **gated the sphere** and **decided** the zero-node question.

**The torus is done, and this is the checkpoint's headline result.** Ordinal 356 publishes `networkV=48`,
`networkE=48`, `cutEdgeCount=28`, `torusRegionCount=4`; the independent oracle publishes actual graph
`V/E/F = 72/76/4`. `72 − 48 = 24` added vertices and `76 − 48 = 28` added edges — **28 is exactly the producer's
cut-edge count**, so producer and oracle agree term for term. A2a′ takes a closed genus-1 surface from a
non-cellular network to a certified cellular embedding and A2b derives four regions. Criteria **C1**, **C3** and
**C6** all hold on the produced torus (ordinals 356, 357, 362).

Stable regression accounting **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**;
authoritative M3 packages **68**. `selected_r2_branch=NONE`; selector **365** is now accepted authority;
`gate_execution_authorized=false`. TB1 added **+0 events / +0 recurrences**: ordinal 366 belongs to a gate that has
never been accepted, and the accepted 365 prefix went green in that very run.

**CP4c-3 is open, and its gate is frozen at 367** — accepted 365 plus criterion **C2**
(`MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`, ordinal 366) and criterion **C3**'s full
torus-and-mechanical form (ordinal 367). Both are red today, which is correct for a required-green selector.
`M3-CP4c-3-DEFN` also put the **prescribed sphere in the gate** after two checkpoints outside one, and decided
`R8-CAND-02`. Three further identities are named for append under AK7, producing gate **370**. CP4c-3 runs in two
phases: instrument (AK1–AK3), then fix on measured causes (AK4–AK6).

**Phase 1 is done and its answers are in.** `M3-CP4c-3-TB1` (run/job `33340448381 / 99335020672`, immutable CB1
package `9739919234`, semantic source `48dd011c4aa689a245b74527ed9df0900ada9bf3`) re-proved the **accepted 365
prefix green on package 68** and hard-stopped at ordinal **366** — a valid semantic red, with every immutability
flag green and every configure/compile/relink/repair/benchmark/mutation flag false. Selector 367 is byte-identical
to its freeze.

- **Mechanical witness — cause ESTABLISHED, and it is an architectural disagreement, not a bug at a line.**
  `IncompleteCycleBasis → CycleTransportAdjacencyMissing`, region `0`, source edge `0-3`,
  `fieldTransportAdjacencyExists=false`. Edge `0-3` is a `HardFeature` **barrier**, established by elimination over
  `FieldTransportAtlas::make`'s four adjacency buckets: `SourceBoundary` is excluded by `globalEF=1,158` (two
  incident faces), `NonTraversable` by a region count of 1 over all 300 faces, and `adjacencies` by the measurement
  itself. **The region decomposition and the traversability classification disagree about the same edge.** Regions
  skip hard-feature edges when flood-filling, but skipping an adjacency **disconnects nothing unless the removed
  edges actually separate**; here region 0 is all 300 faces with `boundaryLoops=0`, so the edge stays *interior* to
  the local mesh (`localEF=1,158`), enters `innerAdjacencies` (450 = E), is spanned by the cycle basis, and the
  transport walk demands the adjacency the atlas deliberately withheld. §7 item 1 carries the corrective options.
- **Prescribed sphere — the measurement is one level short.** `RotationSystemInconsistent →
  TraceEventPositionInvalid`, reached with source topology, atlas and network all available (24 traces / 56 events).
  AK3 did exactly what it was asked, but `TraceEventPositionInvalid` is **itself a two-way collapse** whose two
  branches need opposite fixes. AL3 resolves it; AL4 forbids designing across it. §7 item 2.
- **The two causes do not share a locus** — A1 `FieldTransportAtlas` versus A2a′ `EmbeddedGraphTopology`, no shared
  code and no shared datum — so they may be worked independently. That is what unblocked phase 2 for the mechanical
  witness alone.
- Frozen non-gating diagnostics ran in full: **0 PASS / 3 RED**, report-only. Three workflow controls failed in
  preflight and executed no Directional runtime; one of them is the **third** occurrence of the `R7-ORCH-01`
  malformed-digest defect, escalated from a reminder to a mechanism by AL8.

**`M3-CP4c-3-DEFN-R1` settled the normative question with Amendment 15 (`DESIGN.md` §7.2.1).** A region's face set
and its published `euler_characteristic()` / `boundary_loop_count()` are facts about the **uncut** source complex
and are unchanged; A1 instead derives its tangent bundle, cycle basis and index quantities from the region's
**transport domain** — the region **cut along** `B(R) = { e ∈ hardFeatureEdges : both incident faces ∈ R }`. The
cut lives in A1's derived local mesh, **not** in the region product, for three reasons: the region product
literally cannot express an open slit (§7 item 1); it is the Amendment 14 precedent — an immutability guarantee
constrains the writer, not a derived view; and it makes the two classifications agree **by construction** instead
of by an unwritten assumption. The corrective is now defined; **`M3-CP4c-3-CB2` implements it under AM0–AM9**.

**The gate is selector 365**, frozen by CB7 under AG7: selector 361 plus criterion C3's torus identity and the
three Amendment-14 identities. Every prefix is byte-identical to its predecessor — 355, 357, 361 — so
`first_red_ordinal` is comparable across the whole CP4c arc.

- **361 is superseded** by 365 and retained for lineage; **357 is superseded**, not wrong — its two
  `GlobalTopologyPlan` torus identities are retained in both.
- **358 is withdrawn.** Its sole addition, `RotationSystemAndFaceWalkAgreeOnProducedWitnesses`, binds
  `cp4c_mechanical_fixture()`, and the mechanical witness has no atlas and is out of CP4c-2 scope — a gate may not
  bind a witness its own checkpoint excludes. Criterion **C3** survives: its torus half becomes its own identity
  and enters the gate; the mechanical half moves to CP4c-3.
- **Two of the four appended identities enter the gate red.** That is correct — a required-green selector says what
  must be true for the checkpoint to close, not what happens to pass today.

`selected_gate` is still **NONE** and `gate_execution_authorized` is still **false**: freezing a gate's bytes is not
selecting it.

## 4. The three witnesses — the fastest way to understand the problem

| witness | source | A2a result | current state |
|---|---|---|---|
| **torus** | fixture, closed genus 1, `χ=0`, V/E/F = 72/216/144 | 48 `HardFeature` mandatory edges, 0 singularities, 48 nodes, **0 traces**, 0 events | **A2a′ and A2b both work end to end through the production path.** 28 cut edges; actual embedded graph `V/E/F = 72/76/4`, `χ=0`; 4 regions with disc proofs. Producer and independent oracle agree term for term (`76 − 48 = 28`). Criteria C1/C6 green at ordinals 356/357. Fails later, downstream of A2b, at `tracing` (out of CP4c-2 scope) |
| **prescribed sphere** | fixture, closed genus 0, `χ=2`, V/E/F = 98/288/192, **zero mandatory edges** | **24 traces / 56 events** | **two independent problems.** (a) Its pre-cut actual embedded graph is measured **non-cellular**: `V/E/F = 18/30/18`, `χ=6` against `sourceChi=2`, one component, no excluded boundary orbits — so it genuinely needs cuts, and they will be trace-crossed. (b) The producer never gets there: it fails at A2a′ reporting `CellularityNotEstablished` at source face `25-27-28`, which is a `default:` bucket, **not a cellularity verdict**. TB1 resolved that bucket two levels further — `RotationSystemInconsistent → TraceEventPositionInvalid` — with source topology, atlas and network all available; one level short of actionable (§7 item 2) |
| **two-ring** | constructed, disc, `χ=1`, V/E/F = 11/25/15 | 3 traces / 8 events | actual embedded graph `V/E/F = 9/11/3`; the accepted invariance witness, and the **only** witness on which the A2a′ semantic/provenance split is runtime-proved |
| **mechanical feature** | fixture, 152 V / 300 F | no atlas — stops in **A1** at `IncompleteCycleBasis` | **criterion C2, gated at ordinal 366, cause ESTABLISHED at TB1.** Resolved to `CycleTransportAdjacencyMissing`, region `0`, source edge `0-3`. Its sole region is `V/E/F = 152/450/300`, `χ=2`, `boundaryLoops=0`, `genus=0` — a **sphere** — with 152 interior vertices, 152 expected cycles / rows / curvatures and 450 inner adjacencies. A non-separating `HardFeature` barrier stayed interior to its own region. **Corrective defined** by Amendment 15; cut, it becomes a sphere with `c` holes — `χ' = 2 − c`, `b' = c`, genus 0. See §7 item 1 |

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

CP4c-3 owns all of these. Its gate is **367**, frozen; items 2–4 came from CP4c-2.

1. **Criterion C2 — the mechanical witness: cause ESTABLISHED, and it is a definition question.** TB1 resolved the
   eight-site `IncompleteCycleBasis` collapse to `CycleTransportAdjacencyMissing` at region `0`, source edge `0-3`,
   `fieldTransportAdjacencyExists=false`. Edge `0-3` is a `HardFeature` **barrier** — by elimination over
   `FieldTransportAtlas::make`'s four buckets, not by guess — and the atlas deliberately created no adjacency for
   it. It nevertheless entered the cycle basis because `build_source_topology_regions`
   (`src/geometry/SurfaceCellTracing.cpp:6655-6737`) skips hard-feature edges when flood-filling regions, and
   **skipping an adjacency disconnects nothing unless the removed edges separate**. They did not: region 0 is all
   300 faces with `boundaryLoops=0`, so `make_local_region_mesh` (`src/authority/FieldTransportAtlas.cpp:850-895`)
   sees the edge as *interior*, `PCFaceTangentBundle` counts it among the 450 inner adjacencies, and the transport
   walk asks `find_adjacency_in(adjacencies, edge)` for an adjacency that by design does not exist.

   **Why this is forced, not exotic.** Region 0 has `χ=2`, `genus=0`, `boundaryLoops=0` — a sphere — and **every
   closed curve on a sphere separates it**. Since the features demonstrably did not separate, the mechanical
   witness's feature set **necessarily contains at least one open arc**. The torus succeeds only because its 48
   hard-feature edges form four closed loops that **do** separate it into four annuli, putting them on region
   *boundaries* where they never enter a local mesh's inner set. The first witness with an open feature arc was
   always going to hit this.

   **DECIDED at `M3-CP4c-3-DEFN-R1` — Amendment 15, option A in its derived-view form.** A1 cuts its **local
   mesh** along `B(R)`; the region product is untouched. Two theorems make it safe, and both are forced rather
   than observed. *(i)* `B(R)` is the entire defect class: a source-boundary edge and a region- or
   component-crossing edge each have at most one incident face in `R`, so they are already local boundary edges,
   and a traversable edge has an adjacency — only a hard feature can be non-traversable **and** interior.
   Isolation seams (same region, same component, different sheet) are traversable by design and are **not**
   barriers. *(ii)* The cut never disconnects: a region *is* a connected component of the face graph built
   without barrier edges, so cutting along `B(R)` leaves that graph untouched — from which it also follows that
   no subset of `B(R)` separates `R`, and hence that on a `χ=2, b=0` region every barrier component is a **tree**.

   **The endpoint rule** — the part AL2 flagged as hard: `v` incident to `B(R)` is duplicated into one copy per
   connected component of `star(v) ∖ B(R)`, i.e. `copies(v) = d_B(v)` for interior `v` and `d_B(v) + 1` for `v` on
   the region's boundary. An open arc's **tip** has `d = 1`, so it is **not** duplicated — the cut surface really
   does touch itself there — but it becomes a boundary vertex with a single fan. The result is a manifold with
   boundary; no geometry moves; `set_mesh` re-derives every count.

   **The arithmetic is an identity:** `χ(R_cut) = χ(R) − χ(B) + ∂`, checked against four independent cases. For
   the mechanical witness `χ' = 2 − c`, `b' = c`, `genus' = 0`, `interiorVertices' = 152 − |V(B)|`,
   `innerAdjacencies = 450 − |B|`, and the cycle matrix's **rank deficiency stays exactly 1** — the same value it
   has today — so nothing downstream that tolerates today's single dependency newly breaks.

   **Three costs, all required work, none visible at the failing line.** The local-mesh-vs-region cross-check must
   be **replaced** by the identity above, not deleted. A slit region moves from the closed `ClosedShenSufficient`
   index **equality** to the boundary-corrected `RelativeBoundary` branch, which absorbs any multiple of 4 — a
   real weakening that must appear in evidence. And every vertex on a barrier loses its inner-vertex cycle, so a
   prescribed singularity there must be re-bound and **fail closed**; see §8's new pattern and §7 item 6.
   **Option C stays prohibited. Option D** — fail closed with a precise typed error — is the frozen fallback, with
   an explicit trigger, at the stated cost that C2 cannot then close.
2. **`M3-CP4c2-TB-X2-CAND-04` — the prescribed sphere, IN the gate, and one resolution short.** Two independent
   problems; fixing either does not fix the other. (a) The producer fails at A2a′ at source face `25-27-28`,
   `producerCutEdgeCount=0` — **before** cut selection, so Amendment 14 is not an account of it. AK3 resolved the
   nine-site `RotationSystemInconsistent` collapse to **`TraceEventPositionInvalid`** — but that name is *itself* a
   two-way collapse in `trace_event_position` (`src/geometry/EmbeddedGraphTopology.cpp:138-173`), where
   `positions.empty()` and `positions.size() > 1` both fall out of one `if (positions.size() != 1U)`.
   `empty` is a network/event **binding** defect; `> 1` is an **ambiguity** — the position is not determined by
   `sourceEdge` alone — and **the two need opposite fixes**. Note also the two-pass structure: a face-restricted
   pass, then a widening fallback over all segments ignoring the face, which can turn "no match in the right face"
   into "several matches across the trace" and so *manufacture* the ambiguous case. Ambiguity is the live
   **suspicion** — 24 traces, 56 events, 10 terminal trace intersections, and a trace crossing one source edge twice
   yields exactly `size() == 2` — but it is **not** a finding and must not be designed against: AL3 measures it,
   AL4 forbids fixing across it. If ambiguous, the stronger key already exists and is free to consult:
   `segment.entryPoint` / `edgeTransitExit` publish the exact crossing point. (b) Independently, its pre-cut actual
   embedded graph is **non-cellular** — `V/E/F = 18/30/18`, `c=1`, `χ=6` against `sourceChi=2` — so it needs cuts,
   and with 24 traces and zero mandatory edges they will be trace-crossed, which is exactly what item 3 governs.
3. **`M3-CP4c2-TB-X2-R10-CAND-01` — Amendment 14's *ordinary* proposal path is structurally unreachable.**
   `barriers = mandatory ∪ traceCrossed ∪ cuts`, so a trace-crossed edge **bounds** a proposal component instead of
   lying inside one, and a tree–cotree search draws from a component's interior edges; only saturation can promote
   one. DEFN-R2 §4.5 removed the *filter* but permitted the conservative *barrier set*, on the reasoning that
   over-separation "costs extra cuts, never correctness" — true about correctness, wrong about coverage.
   Amendment 14's **representation** is fully proved regardless; what is at stake is cut-graph **quality**.
   Corrective: model a trace crossing as a **per-face chord**, matching the fragment machinery. Heuristic only —
   Amendment 13 §3 already denies it certification authority — so Amendment 14 is not reopened.
4. **`M3-CP4c2-TB-X2-R8-CAND-02` — decided at CP4c-3's DEFN, awaiting implementation.** An empty network on a
   closed surface is **rejected with a typed error**: A2a′ adds cuts to an existing network, and cutting from
   scratch would make it the producer of the whole embedded graph, which is A2a's single-writer authority. The new
   code is **appended**, never renumbered.
5. **Torus post-A2b `tracing` failure** — downstream of A2b, tracked, and out of CP4c-3's scope by decision.
6. **`M3-CP4c3-DEFN-R1-CAND-01` — the interior-singularity binding does not fail closed.** A latent gap found
   while deriving Amendment 15, pre-existing at HEAD and **not** introduced by it, but made reachable by it.
   `FieldTransportAtlas.cpp:1557` partitions prescribed singularities by **`sourceMesh.isBoundaryVertex`** — the
   *global* mesh. The boundary path reconciles and fails closed when an owner is missing (`:1960-1976`); the
   interior path does **not** (`:1980-1990`) — `localCycleByGlobalVertex.find(...)` simply leaves `region` and
   `cycle` as `std::nullopt` and continues. A vertex consumed by a slit is still *globally* interior, so it takes
   the unchecked path: its prescribed index goes from verified against the field's own holonomy to unverified and
   unbound, with a green build. Owned by **AM4**; landing the cut without it trades a red gate for an
   unverifiable certificate.

**Closed in CP4c-2, do not re-open:** `PR8-R043`, `PR8-R044` (proved on a bounded *and* a closed witness),
`R7-ORCH-01`, `R7-CAND-01`, `R7-CAND-03`, `R8-CAND-01`, `R8-ORCH-01`, `R9-CAND-01`, `R9-ORCH-01`; measure **AD3**
(ordinal 359 — the raw `face.orbit` index in a semantic digest is proved by test, and the falsifier is cited beside
the claim in the source); criteria **C1**, **C3** (torus form) and **C6**.

## 8. Recurring defect patterns — the highest-value section

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

## 9. Where to look

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
- Grazing is **edge transit**, not termination — decided on a continuity argument, not on cost data.
- Trace termination is **crash-on-contact** (motorcycle graph), on an exact predicate, with mutual termination
  on a tie; the production arrival priority is `ArcLengthFiltered` with a certified forward error bound.
- GMP/GMPXX linkage is mandatory for every compile; fallback exact arithmetic is not authoritative build
  evidence.
