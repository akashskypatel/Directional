# M3-CP4c-3 DEFN-R1 — Frozen Definitions, Review and Plan

## Status

**DEFINITION + REVIEW COMPLETE / AL2 SETTLED / OPTION A ADOPTED IN ITS DERIVED-VIEW FORM (A′) /
AMENDMENT 15 DECLARED / MEASURES AM0–AM9 ISSUED**

This turn discharges **AL2** under the standing cadence in which `DEFN` *is* the review-and-plan turn. Definition,
review and planning only: nothing was executed, compiled, packaged, relinked or benchmarked, no gate was selected
or run, and **no product, test, fixture, selector or build-logic byte changed**. The only source read was read.

Measures issued here are **AM0–AM9**. Gate **367** remains frozen and unselected.

---

## 0. What this turn verified independently

The working tree is byte-identical to the semantic source TB1 executed:

```
git diff --stat 48dd011c4aa689a245b74527ed9df0900ada9bf3 HEAD -- tests/ src/ include/   →  empty
```

so every source claim below describes exactly the code that produced ordinal 366's red. Every line reference was
read at HEAD, not carried forward from a prior record.

This document does not re-derive TB1's adjudication; that is
`Architecture_M3_CP4c3_TB1_Independent_Review_Record.md` (AL0–AL9). It answers the one normative question that
record deliberately refused to answer by implementation.

---

## 1. The question, stated exactly

`M3-CP4c-3-TB1` measured `IncompleteCycleBasis → CycleTransportAdjacencyMissing` at region `0`, source edge `0-3`,
and the review established the mechanism: a `HardFeature` **barrier** edge remained **interior** to its topology
region's local mesh, so the cycle basis spanned an edge for which the atlas deliberately created no transport
adjacency. Region decomposition and traversability classification disagree about the same edge.

AL2 requires this turn to settle, normatively:

1. what a topology region **is** when a barrier does not separate — option **A** (cut) versus **D** (fail closed),
   with **C** (give the barrier an adjacency) prohibited;
2. if A, the exact treatment of an **open arc's endpoints**, where the cut surface touches itself, **with its
   derivation**;
3. that `χ`, `boundaryLoops` and `expectedCycleCount` stay consistent for a slit region — **shown, not asserted**;
4. recorded as a `DESIGN.md` §7.2.1 amendment.

§§2–5 derive the answers. §6 decides. §7 states what the decision costs. §8 is the plan.

---

## 2. Theorem 1 — the defect class is *exactly* `HardFeature` edges interior to a region

This bounds the whole problem, and it is provable from the two classification sites rather than observed on one
witness.

`FieldTransportAtlas::make` (`src/authority/FieldTransportAtlas.cpp:1456-1491`) routes every source edge through
four buckets **in this order**:

| order | bucket | condition |
|---|---|---|
| 1 | `SourceBoundary` | `secondRaw < 0` — one incident face |
| 2 | `HardFeature` | `hardFeatureEdges.count(edge) != 0` |
| 3 | `NonTraversable` | `rowRegions[first] != rowRegions[second]` **or** `rowComponents` differ |
| 4 | `adjacencies` | otherwise — a transport adjacency is created |

`make_local_region_mesh` (`:850-902`) builds a region's local mesh from **that region's faces only**. Therefore:

- a **bucket-1** edge has one incident face, so at most one of its faces is in any region → it is a **boundary**
  edge of the local mesh, never interior;
- a **bucket-3** edge has its two faces in **different regions** (or components), so exactly one lies in each
  region's face set → again a **local boundary edge**, never interior;
- a **bucket-4** edge has an adjacency, so it cannot raise `CycleTransportAdjacencyMissing` at all.

**Only bucket 2 can be interior to a local region mesh while carrying no adjacency.** Note the ordering matters:
`hardFeatureEdges` is tested *before* the region/component test, so a hard-feature edge whose two faces sit in one
region is classified `HardFeature`, not `adjacencies`.

**Corollary — isolation seams are not affected.** `scratch_internal_isolation_seam`
(`src/geometry/SurfaceCellTracing.cpp:6837-6851`) marks an edge whose faces are in the **same** region and **same**
component but different *sheets*, and which is **not** a hard feature. In A1 such an edge fails bucket 2 and fails
bucket 3, so it lands in bucket 4 and **does** get a transport adjacency. Isolation seams are interior to a region
by design and are traversable by design; they are not part of this defect class and must not be swept into the
fix.

**Definition (frozen).** For a topology region `R`,

```
B(R) = { e ∈ hardFeatureEdges : both faces incident to e belong to R }
```

`B(R)` is the region's **non-separating barrier set**. It is exactly the set of edges that are non-traversable in
A1 and interior in A1's local mesh. Everything below is stated about `B(R)`.

---

## 3. Theorem 2 — cutting along `B(R)` can never disconnect `R`

This is what makes the operation safe, and it is forced by how regions are built, not by luck.

`build_source_topology_regions` (`src/geometry/SurfaceCellTracing.cpp:6715-6741`) builds the face-adjacency graph
by skipping (a) edges whose faces are in different raw components and (b) every edge in
`options.hardFeatureEdges`, then flood-fills. A region `R` is a connected component of *that* graph. Since all
faces of `R` share one raw component (`:6824-6827`), the only edges of `R` skipped during its own flood fill are
exactly `B(R)`.

**Therefore the face-adjacency graph of `R` using only non-barrier edges is connected by construction.** Cutting
along `B(R)` removes exactly those barrier adjacencies and leaves that graph untouched, so the cut mesh's face
graph is connected, and a triangulated surface with a connected face graph is connected.

**The cut mesh is always connected, for every region and every barrier set.** Consequently `χ = 2 − 2g − b` applies
to it with one component and `genus` stays well defined — the assumption `:1652-1660` already makes.

**Corollary.** No subset of `B(R)` separates `R`: if one did, `R`'s non-barrier face graph would be disconnected,
contradicting the construction. In particular, on a region with `χ = 2` and `b = 0` — a sphere, where **every**
closed curve separates — `B(R)` contains **no cycles at all**: every component of `B(R)` is a **tree**. The
mechanical witness's `B(R)` is a forest.

---

## 4. The endpoint rule — AL2 item 2, derived

Cutting is a purely combinatorial rewrite of the local face array: duplicate the vertices of `B(R)` according to
how the barrier divides their stars, re-index the faces, and hand the result to `TriMesh::set_mesh`. No geometry
moves; both copies of a duplicated vertex keep the same position.

**Rule (frozen).** For a vertex `v` incident to `B(R)`, let `d(v)` be its degree **in `B(R)`**. The number of
copies of `v` in the cut mesh is the number of connected components of `star(v) ∖ B(R)`:

```
copies(v)  =  d(v)                    if v is interior to R's local mesh
           =  d(v) + 1                if v lies on R's local-mesh boundary
copies(v)  =  1                       if v ∉ B(R)
```

**Derivation.** The star of an interior vertex is a disc whose link is a cycle; `d(v)` radial barrier rays cut that
disc into exactly `d(v)` sectors — including `d(v) = 1`, where a single ray does **not** disconnect the disc and
leaves one sector. The star of a boundary vertex is a half-disc whose link is a path; `d(v)` interior rays cut a
path into `d(v) + 1` pieces. Each sector becomes one copy, and the faces of that sector are re-indexed to it.

**This settles the endpoint question, and the answer is that an open arc's tip is not duplicated.** A tip has
`d = 1`, hence exactly one copy: the cut surface genuinely touches itself there, and that is representable. The tip
is nevertheless *incident to* the slit, so it becomes a **boundary vertex** of the cut mesh, appearing exactly once
on the slit's boundary loop, with one incoming and one outgoing boundary edge (the two copies of the arc's terminal
edge). Its link is a single fan.

**The cut mesh is therefore a manifold with boundary**, which is what `PCFaceTangentBundle::init` requires and what
`make_local_region_mesh`'s `set_mesh` will accept. `TriMesh::set_mesh` derives `EV`, `EF`, `isBoundaryVertex`,
`isBoundaryEdge` and `boundaryLoops` from V/F (`include/directional/core/TriMesh.h:202-241`), so **every downstream
count follows automatically from the rewritten face array**. Nothing else in `make_local_region_mesh` needs new
bookkeeping except the `globalVertexByLocal` map, which becomes many-to-one.

**Degenerate shapes the rule already covers, and which AM1 must report rather than assume away:** a branch vertex
(`d ≥ 3`) yields `d` copies; a barrier component that is a closed loop yields `copies = d = 2` everywhere and no
tip; a barrier vertex on the region's own boundary yields `d + 1`. Theorem 2 forbids closed loops only when `R` is
a sphere, so the loop case is real on other regions and must not be special-cased away.

---

## 5. Arithmetic consistency — AL2 item 3, shown

Let `R` have `V, E, F`, `χ = V − E + F`, boundary loops `b`, and let `B = B(R)` have `n = |V(B)|` vertices and
`m = |B|` edges, with `∂` = the number of `B`'s vertices lying on `R`'s local-mesh boundary.

The rewrite changes counts by `ΔF = 0`, `ΔE = m` (each cut edge becomes two), and

```
ΔV = Σ_{v ∈ V(B)} (copies(v) − 1) = (2m − n) + ∂
```

using `Σ d(v) = 2m` and §4's rule. Hence the **cut identity**:

```
χ(R_cut) = χ(R) + ΔV − m = χ(R) − (n − m) + ∂ = χ(R) − χ(B) + ∂
```

*Cutting along `B` lowers the Euler characteristic by the Euler characteristic of `B`, plus one for each of `B`'s
vertices already on the boundary.* Four checks, all correct:

| case | `χ(B)` | `∂` | predicted `χ'` | truth |
|---|---|---|---|---|
| sphere, one open arc | 1 | 0 | `2 − 1 = 1` | sphere with a slit **is** a disc ✓ |
| torus, one non-separating closed loop | 0 | 0 | `0 − 0 = 0` | torus cut along a generator **is** an annulus ✓ |
| disc, arc from an interior tip to the boundary | 1 | 1 | `1 − 1 + 1 = 1` | still a disc ✓ |
| disc, arc between two boundary points | 1 | 2 | `1 − 1 + 2 = 2` | **two** discs, `χ = 1 + 1` ✓ |

**Now the mechanical witness, fully determined without measuring it.** Region 0 has `V/E/F = 152/450/300`,
`χ = 2`, `b = 0`, `genus = 0`. By Theorem 2's corollary every component of `B` is a tree, so `χ(B) = c` where `c`
is the number of barrier components, and `∂ = 0`. Therefore

```
χ' = 2 − c        b' = c        genusNumerator = 2 − b' − χ' = 2 − c − (2 − c) = 0   →   genus' = 0
```

`genusNumerator` is `0`, hence non-negative and even, for **every** `c`. The region is a sphere with `c` holes.
Boundary vertices of the cut are exactly the copies of `B`'s vertices, `Σ copies(v) = 2m`, so

```
interiorVertices' = V + ΔV − 2m = 152 + (2m − n) − 2m = 152 − n
expectedCycleCount' = interiorVertices' + b' + 2·genus' = (152 − n) + c
```

**The independent cross-check that makes this "shown" rather than "asserted".** `dual_cycles`
(`include/directional/geometry/MeshTopology.h:55-74`) is documented to emit `#V − #b` inner-vertex cycles **in
vertex order**, then `#b` boundary cycles, then `2g` generator cycles, with columns **indexed into inner edges
alone**. Its row count must equal the dual cycle space dimension plus the one known dependency. Inner edges after
the cut are `E' − 2m = (450 + m) − 2m = 450 − m`, faces `300`, one component, so

```
dim(dual cycle space) = (450 − m) − 300 + 1 = 151 − m
rows − dim = [(152 − n) + c] − [151 − m] = 1 + (m − n) + c = 1 − χ(B) + c = 1 − c + c = 1
```

**The rank deficiency is exactly 1, the same value it has on the uncut mesh** (152 rows vs. 151 dimensions today).
The slit does not change the dependency structure, so nothing downstream that tolerates today's single dependency
becomes newly broken. The three count guards `CycleDimensionCountMismatch`, `CycleKindPartitionMismatch` and
`BoundaryCycleCountMismatch` remain satisfiable, and `innerAdjacencies` drops from `450` to `450 − m` — **exactly
the barrier edges leave**, which is the entire point of the change.

**And the failure becomes structurally impossible, not merely avoided.** `dual_cycles`' columns are inner edges
only; a barrier edge is a boundary edge of the cut mesh; therefore it can never appear as a column, so
`:1751-1761`'s `find_adjacency_in(adjacencies, edge)` is never called for it. `CycleTransportAdjacencyMissing`
cannot fire for a barrier after the change — it survives, correctly, only for a genuinely missing adjacency on a
traversable edge.

---

## 6. Decision — Amendment 15, option **A′**

**Adopted: option A, in its derived-view form.** The cut belongs to **A1's derived local mesh**, and **not** to the
`SurfaceTopologyRegion` product.

> **A topology region's face set, its published `euler_characteristic()` and its published `boundary_loop_count()`
> are unchanged. What changes is that A1's *transport domain* for a region is the region **cut along its
> non-separating barrier set `B(R)`**, and every tangent-bundle, cycle-basis and index quantity A1 derives is
> derived from that cut mesh.**

Three reasons, in order of weight.

**6.1 The region product cannot express an open slit, and forcing it to would break an accepted product.**
`build_source_topology_regions` derives `boundaryLoopCount` by walking `boundaryAdjacency`, and `:6905` **requires
every boundary vertex to have exactly two boundary neighbours**, returning `std::nullopt` — failing the entire
`SourceTopologyRegions` product — otherwise. At the region level there is no vertex duplication: an open arc's tip
would have exactly **one** boundary neighbour, so simply adding `B(R)` to `region.boundaryEdges` does not produce a
slit, it produces a **hard failure of A0/A2's region authority for every witness with an open feature arc**. The
slit is only representable where vertices can be duplicated, and that is the local mesh.

**6.2 It is the Amendment 14 precedent, applied to the same class of question.** Amendment 14 established that an
immutability guarantee constrains the **writer**, not a **derived view**: A2a′ may place a node where the network
already says two curves meet without mutating the network. The identical shape holds here. The region product's
face set and its Euler data are facts about the *uncut source complex* and stay true. A1's cut mesh is a derived
view built for transport, and building it does not repair, contradict or rewrite the region.

**6.3 It makes the two classifications agree by derivation instead of by assumption.** The root cause is that A1's
cycle machinery assumed region boundaries and non-traversable edges coincide. Under A′ that assumption becomes a
**construction**: the transport domain's boundary is, by definition, the region boundary **together with** its
non-traversable interior edges. The corrective form `RP-01` prescribes — make one derive from the other rather
than maintaining two authorities that happen to agree — is satisfied exactly.

**Rejected: C**, prohibited as AL9 already froze — it would let transport cross a feature and destroys the barrier
semantics hard features exist to express.
**Rejected: B** — `PCFaceTangentBundle::init` takes a mesh, not a barrier set, so it converges on A′ anyway.
**D is retained as the frozen fallback**, with an explicit trigger; see §7.4.

---

## 7. What the decision costs — three consequences, each with a required control

A′ is not free, and none of these is visible from the failing line. Each is a **required** part of the change; an
implementation that lands the fix without them converts a loud red into a quiet weakening, which is exactly the
pattern `LESSONS.md` 62 records.

### 7.1 The `CanonicalBindingMismatch` cross-check must be **replaced**, not deleted

`:1654-1658` currently rejects a region unless the local mesh's `χ` and `boundaryLoopCount` equal the region's own
published `euler_characteristic()` and `boundary_loop_count()`. Under A′ the cut mesh's values **deliberately
differ**, so this check will fire on every witness with a non-separating barrier. Deleting it removes a real
guard — it is the only place the local mesh is tied to the region authority at all.

**Required replacement.** Keep the comparison against the region's published values for the **uncut** local mesh,
then assert the **cut identity of §5** relating the two:

```
χ(cut) == region.euler_characteristic() − χ(B) + ∂        and        b(cut) == b(uncut) + (new slit loops)
```

with `χ(B) = |V(B)| − |B|` computed from the barrier set the cut actually used. This is **strictly stronger** than
today's check: it constrains three independently derived quantities instead of two, and it fails closed if the cut
and the region ever disagree about which edges were barriers. A distinct appended error code must name that
condition; it may not reuse `CanonicalBindingMismatch`, which would re-collapse a typed error one turn after this
project resolved two such collapses.

### 7.2 The region's certificate changes kind, from a closed identity to a boundary-corrected one

`:1857-1898` branches on `boundaryLoopCount`. Today the mechanical region has `b = 0` and takes the closed branch:
`FieldQuadrangulabilityWitnessKind::ClosedShenSufficient`, with the **equality** `interiorIndexSum ==
requiredIndexSum == 4χ` enforced at `:1872`. After the cut, `b' = c ≥ 1`, so it takes the `RelativeBoundary` branch
at `:1878`, where `correction = requiredIndexSum − interiorIndexSum − boundaryIndexSum` is **absorbed into the
first boundary cycle** (`:1892`) provided only that `correction % 4 == 0`.

That is correct mathematics — Gauss–Bonnet with boundary — but it replaces an equality test with a congruence test
plus an absorption. **The cut therefore weakens the index check for exactly the regions it is applied to.** This is
a genuine, accepted cost of A′ and must be stated in the CB report rather than discovered later; §8's AM6 requires
the published witness kind and the absorbed `correction` value to be reported per region, so the weakening is
visible in evidence instead of implicit.

### 7.3 The quiet one: a prescribed singularity on a barrier arc silently loses its verification

This is the most dangerous consequence and it is invisible at every failing line.

Every vertex incident to `B(R)` becomes a **boundary** vertex of the cut mesh, so it is no longer in
`interiorLocalVertices` and **no `LocalVertex` cycle is emitted for it**. Two things follow:

- `:1843-1851`'s agreement check — that the atlas's computed `turningLift` equals the **prescribed** raw singularity
  index at that vertex — **no longer runs** for it;
- and the global reconciliation does not catch the gap. `rawSingularity` versus `rawBoundarySingularity` is
  partitioned at `:1557` by **`sourceMesh.isBoundaryVertex`** — the *global* mesh — so a slit vertex is still
  classified as an *interior* singularity. The boundary reconciliation at `:1960-1976` fails closed when an owner
  is missing, but the interior path at `:1980-1990` does **not**: `localCycleByGlobalVertex.find(rawVertex)` simply
  leaves `region` and `cycle` as `std::nullopt` and the loop continues. The result is a `FieldSingularityFact`
  with **no region and no cycle binding, and no error**.

So a prescribed singularity sitting on a feature arc goes from *verified against the field's own holonomy* to
*unverified and unbound*, with a green build. This is a **pre-existing latent gap** — the asymmetry between
`:1960` and `:1980` exists at HEAD — that A′ makes reachable for the first time.

**Required control.** The interior path must be made to fail closed in the same shape as the boundary path: every
`rawSingularity` entry must bind to exactly one cycle — a `LocalVertex` cycle, or, when its vertex was consumed by
a slit, the boundary cycle of the slit loop that carries it — and a prescribed singularity with no owner is a typed
failure, not a `nullopt` field. This is not scope creep: without it the fix trades a red gate for an unverifiable
certificate, which the project has twice recorded as the worse outcome.

### 7.4 The frozen fallback, with its trigger

If **AM5**'s implementation cannot deliver §7.1–§7.3 within CP4c-3, the fallback is **option D**: retain today's
behaviour but name it precisely with a **new, appended** `IncompleteCycleBasisReason` — "a non-separating barrier
edge remains interior to its region" — replacing the misleading `CycleTransportAdjacencyMissing` for this
condition only. **The trigger is explicit and must be declared in the CB report, not decided silently:** D is taken
if and only if §7.3's binding control cannot be made to fail closed without changing an accepted A1 contract. If D
is taken, **CP4c-3 cannot close on criterion C2**, and the gate expectations must be revisited by a further DEFN
before any TB. D is a stop, not a fix, and must be reported as one.

---

## 8. Measures **AM0–AM9**

The next turn is **`M3-CP4c-3-CB2`** — Code + Build, instrumentation and correction, runtime-free.

**AM0 — preconditions and frozen authority.** Accepted runtime predecessor remains CP4c-2 at **365/365**, source
`57444781af7bdc460e38cc68930a9a8c8199eeea`, package `9736088354`. CP4c-3's gate is **367**, whole-file
`ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf`; recompute it and **all four** predecessor
prefixes from committed bytes at authoring and at preflight, and validate each as exactly 64 lowercase hex. Never
transcribe a digest. No existing selector byte may change. `selected_r2_branch=NONE`, `selected_gate=NONE`,
`gate_execution_authorized=false`. GMP/GMPXX linkage is mandatory for the compile.

**AM1 — publish the barrier set before cutting anything.** For the mechanical witness publish: `|hardFeatureEdges|`;
whether edge `0-3` is a member; and the connected-component decomposition of `B(R)` per region — for each
component, its vertex count, edge count, `χ`, whether it is a tree or contains a cycle, its degree-1 tip vertices,
its degree-≥3 branch vertices, and how many of its vertices lie on the region's local-mesh boundary. Publish the
totals `n = |V(B)|`, `m = |B|`, `c`, `χ(B)` and `∂` that §5's identity consumes. This confirms §2's elimination
directly, sizes the change, and **falsifies §5 if the numbers disagree**.

**AM2 — implement the cut as a face-array rewrite in `make_local_region_mesh`.** Duplicate vertices by §4's rule,
re-index faces per sector, hand the result to `set_mesh`, and let `EV/EF/isBoundaryVertex/boundaryLoops` derive
themselves. `globalVertexByLocal` becomes **many-to-one**; every consumer of it must be audited by search, not by
copying this document's list. Two are known and must be handled: `global_edge_key` (`:1694`, `:1753`) — safe,
because both copies of a duplicated vertex carry the same global vertex and cut edges never appear as inner edges —
and `:1795`'s positional `interiorLocalVertices[row] → globalVertexByLocal[...]` mapping, which stays injective
because **every copy of a cut vertex is a boundary vertex** and so is never in `interiorLocalVertices`. State in
the CB report which consumers the search found and how each was classified.

**AM3 — replace the `:1654` cross-check per §7.1** with the cut identity, under a **new appended** error code. Do
not delete the check and do not reuse `CanonicalBindingMismatch`.

**AM4 — make the interior singularity binding fail closed per §7.3.** Every `rawSingularity` must bind to exactly
one cycle; an unbound prescribed singularity is a typed failure. Publish, per witness, the count of prescribed
singularities, how many bound to a `LocalVertex` cycle, how many to a slit boundary cycle, and how many bound to
nothing — the last must be zero.

**AM5 — the correction itself.** Land AM2–AM4 together. They are one change: AM2 without AM3 fails closed on every
barrier witness, and AM2 without AM4 is a silent weakening. State explicitly in the CB report whether option A′ or
the §7.4 fallback D was taken, and if D, which of §7.1–§7.3 could not be delivered and why.

**AM6 — report the certificate-kind change per §7.2.** Per region publish the witness kind
(`ClosedShenSufficient` / `RelativeBoundary`), `requiredIndexSum`, `interiorIndexSum`, `boundaryIndexSum` and the
absorbed `correction`. A region that changed kind because of the cut must be named as such.

**AM7 — the sphere is untouched by this turn, and AL3/AL4 still govern it.** AL3's `NoCarrierMatch` versus
`AmbiguousCarrierMatch` sub-reason, with the trace/event/`sourceEdge`/`sourceFace` row, every candidate position in
the ambiguous case, and **which pass** produced the result, is carried into CB2 unchanged. **AL4 stands: do not
design the sphere's fix until AL3 reports.** The two causes share no locus, so shipping AL3's instrumentation in
the same CB as AM5's correction is permitted; *designing* the sphere's correction is not.

**AM8 — gate append.** AL7's three identities still append to **367**, producing **370**. Amendment 15 adds three
more, producing **373**:
`FieldTransportAtlas.NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis`,
`FieldTransportAtlas.CutTransportDomainSatisfiesTheEulerCutIdentity`,
`FieldTransportAtlas.PrescribedSingularityOnABarrierArcRemainsBoundToACycle`.
All **five** predecessor prefixes (355, 357, 361, 365, 367) must be re-verified byte-identical at the freeze, and
370's prefix must reproduce inside 373. Omitting any identity requires a written rationale in the CB report.

**AM9 — prohibited.** Giving a barrier edge a transport adjacency (option C). Adding `B(R)` to
`region.boundaryEdges` or otherwise changing `SurfaceTopologyRegion`'s published `euler_characteristic()` /
`boundary_loop_count()` — §6.1 shows it fails the product outright. Deleting the `:1654` check rather than
replacing it. Landing AM2 without AM4. Treating an isolation seam as a barrier (§2 corollary). Renumbering or
removing any existing error-enum value or changing any existing mapping — new reasons and codes are **appended**
only. Reopening Amendments 12, 13 or 14. Changing accepted selector 365's bytes, or 357 / 358 / 361, or 367 other
than by AM8's append. Weakening `proves_cellularity()`, the fragment-count invariant, or
`UncutFaceComponentOrbitSeedNotUnique`. Introducing any tolerance into a topological decision. Removing CP4c-2's,
CB1's or this turn's diagnostic surface. Executing Directional runtime, running a gate, or benchmarking in a CB
turn.

---

## 9. Falsifiable predictions

Recorded so the next turn can be judged against them rather than around them.

1. **AM1 will report `c ≥ 1` open-arc (tree) components for the mechanical witness, and zero cycles in `B(R)`.**
   Theorem 2's corollary forces it on a `χ=2, b=0` region. A measured cycle in `B(R)` **falsifies Theorem 2** and
   this whole amendment must be reopened.
2. **Edge `0-3` will be reported a member of `hardFeatureEdges`.** §2's elimination predicts it; a negative result
   falsifies the review's mechanical cause and CB2 must stop rather than proceed.
3. **After the cut, region 0 will publish `χ' = 2 − c`, `b' = c`, `genus' = 0`, `interiorVertices' = 152 − n`,
   `expectedCycleCount' = 152 − n + c`, and `innerAdjacencies = 450 − m`.** Any deviation falsifies §5.
4. **`CycleTransportAdjacencyMissing` will not fire for a barrier edge again**, because barrier edges are no longer
   columns of `dual_cycles`. If it does, the cut did not take effect where it was needed.
5. **Region 0's witness kind will change from `ClosedShenSufficient` to `RelativeBoundary`.** Predicted by §7.2. It
   is expected, not a defect, but it must appear in evidence.
6. **AM4 will report a non-zero number of prescribed singularities bound to a slit boundary cycle** only if the
   witness actually places singularities on feature arcs; zero is an acceptable outcome. What is **not** acceptable
   is a non-zero "bound to nothing" count.

---

## 10. Gate membership and accounting

Gate **367** stays frozen and unselected; freezing bytes is not selecting them. The append point is defined by
**AM8** (367 → 370 → 373) and is executed at CB2's freeze, not here. `selected_gate=NONE`,
`gate_execution_authorized=false`, `selected_r2_branch=NONE`.

Nothing in this turn touches runtime, so accounting is unchanged: **44 events / 14 categories / 30 recurrences**,
produced-witness debt **5**, authoritative M3 packages **68**. **+0 events / +0 recurrences.**

Tracker dispositions this turn sets:

- `M3-CP4c3-DEFN-CAND-01` — **CAUSE ESTABLISHED / CORRECTIVE DEFINED**. Amendment 15 fixes the corrective as option
  A′ with the §7.1–§7.3 controls; AM5 owns implementation. Closure condition unchanged: ordinal 366 green in a run
  reaching at least 366.
- `M3-CP4c2-TB-X2-CAND-04` — unchanged, **ACTIVE / ONE LEVEL SHORT**; AL3/AL4 carried forward as AM7.
- `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02` — unchanged, phase-2, no shared locus.
- **New: `M3-CP4c3-DEFN-R1-CAND-01`** — the unreconciled interior-singularity binding at `:1980-1990`. A
  pre-existing latent gap, not introduced here, made reachable by A′. Owned by **AM4**.

## 11. Exact next turn

**`M3-CP4c-3-CB2`** — Code + Build under **AM0–AM9**, runtime-free, GMP/GMPXX linked. It implements Amendment 15
(AM2–AM6), carries AL3's sphere instrumentation (AM7), and freezes the **373** gate append (AM8). A red TB after it
routes to `REVIEW + PLAN` as usual.

CP4c-2 remains **CLOSED / ACCEPTED at 365/365**. CP4c-3 is **open**.
