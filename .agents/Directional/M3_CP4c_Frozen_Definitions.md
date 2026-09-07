# M3 CP4c — Frozen Definitions

**Purpose — DURABLE, DO NOT DELETE.** This is the single normative definitions document for the `M3-CP4c` family.
It carries the **complete, unaltered text** of the six frozen-definition documents, consolidated on **2026-09-03**
at `M3-CP4c-3-TB17-REV`. Nothing was summarized, shortened or reworded: each part below is its source document
verbatim, with heading levels demoted by two so the parts nest under one hierarchy.

**Supersession.** Within each checkpoint the revisions supersede in order — `DEFN` → `DEFN-R1` → `DEFN-R2`. The
earlier revisions are retained because `DESIGN.md` and the regression tracker cite the amendment lineage directly,
and because an amendment's provenance is part of its authority. **The operative definitions for CP4c-2 are Part
III; for CP4c-3 they are Part VI together with Parts VII and VIII, each superseding the earlier where they
conflict.** Where an earlier part conflicts with a later revision of the same checkpoint,
the later revision governs.

This file is normative authority, not history. History lives in `M3_CP4c_Consolidated_Record.md`; current state and
the forward plan live in `M3_CP4c_Current_And_Forward.md`.

## Citation map

Citations written against the former filenames resolve here:

| Former document | Now |
|---|---|
| `Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md` | Part I — M3-CP4c-2 DEFN |
| `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` | Part II — M3-CP4c-2 DEFN-R1 |
| `Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md` | Part III — M3-CP4c-2 DEFN-R2 |
| `Architecture_M3_CP4c3_DEFN_Frozen_Definitions.md` | Part IV — M3-CP4c-3 DEFN |
| `Architecture_M3_CP4c3_DEFN_R1_Frozen_Definitions.md` | Part V — M3-CP4c-3 DEFN-R1 |
| `Architecture_M3_CP4c3_DEFN_R2_Frozen_Definitions.md` | Part VI — M3-CP4c-3 DEFN-R2 |
| *(no prior file — authored in place)* | **Part VII — M3-CP4c-3 DEFN-R3** |
| *(no prior file — authored in place)* | **Part VIII — M3-CP4c-3 DEFN-R4** |

Section numbering inside each part is unchanged, so a citation such as "`…_DEFN_R2_…` §Amendment 22" reads as "Part VI §Amendment 22". Full text of the originals also remains in git history.

---

## Part I — M3-CP4c-2 DEFN

*Source document: `Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md`, consolidated verbatim.*

### M3-CP4c-2 DEFN — Frozen Definitions: closed-surface cut-graph authority for A2b

> ## SUPERSEDED IN PART — read this first
>
> **`M3-CP4c-2-DEFN-R1` (2026-08-29) withdraws §5.4's construction guidance.** The whole-source-face /
> source-edge-barrier partition is **no longer cellularity authority**; it survives only as a cut-proposal
> heuristic and diagnostic provenance, and every publication of it must say so. The normative complex is the
> **actual embedded graph** of `FieldAlignedCurveNetwork ∪ cutEdges`, represented by the arc / dart / rotation /
> face-orbit machinery A2b already contains. See `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md`,
> **Amendment 13**.
>
> **§§5.1–5.3 remain binding and unchanged**, as do §§1–4 and **Amendment 12**, whose precondition-versus-repair
> boundary is unaffected. §3's torus theorem stands and was independently reconfirmed by R4.
>
> Cause: §5.4 step 1 directed the implementation to compute complement components over whole source faces
> separated by source edges — resurrecting the representation class CP4ab had already rejected in
> `PR8-R042 / M3-CP4b-R001` and recorded in `LESSONS.md` 22d/22e. That produced the stable regression
> `PR8-R043 / M3-CP4c2-R001` at accepted ordinal 305.

#### 0. Turn type and verdict

`M3-CP4c-2-DEFN` is **COMPLETE / DEFINITION-ONLY**.

No Directional runtime, build, compile, package, benchmark, product, test, fixture, or selector change was made
or is authorized by this turn. This document freezes the contract that `M3-CP4c-2-CB1` will implement.

**The decision.** CP4c-2 introduces one new authority product, **`SurfaceCutGraph` (stage A2a′)**, produced
after A2a and consumed by A2b, whose sole obligation is to guarantee that the curve network's complement is a
disjoint union of open discs. `DESIGN.md` §7.2 is amended (**Amendment 12**) because its claim that region-disc
topology "holds by construction" is **provably false on closed surfaces**, and because its stop condition, read
literally, forbids the only viable fix.

**The scope decision.** CP4c-2 owns **C1 and C6** (the torus and the disc/mandatory-preservation contract).
**C3 is deferred** out of this checkpoint pending a measurement, for reasons given in §6. This is a
recommendation with a precise trigger, not a unilateral re-allocation: §6.3 states exactly what evidence would
move C3 back in.

#### 1. Predecessor verification — CP4c-1 closure independently checked

CP4c-1's closure claim was verified before this definition was written, from the repository rather than from
the report:

| Check | Expected | Independently computed | Result |
|---|---|---|---|
| 355 required selector | `e9d88f11…5afeaa` | identical | **PASS** |
| first-316 prefix | `601ce2b6…00193c` | identical | **PASS** |
| first-346 prefix | `20d3b0b1…3e46a` | identical | **PASS** |
| first-353 prefix | `51ff96d7…ac6a5` | identical | **PASS** |
| non-gating selector | 3 entries, `537a8010…ffcd6a` | identical | **PASS** |
| W0 — `src/` and `include/` frozen across CB4 | zero changes | zero changes; only `tests/FieldAlignedCurveNetworkTests.cpp` | **PASS** |
| W1 — witness productivity precondition removed | deleted, no weaker assert/skip/special case | deleted; per-trace loop intact | **PASS** |
| W2 — cardinality replaced | `ASSERT_FALSE(producedTerminalKinds.empty())` | present; both named checks survive | **PASS** |
| W5 — two inverted identities | retired, per-identity rationale | absent from source and selector; rationale in tracker | **PASS** |

The accepted prefixes are byte-identical to their accepted ancestors, so accepted authority is carried **in
order** and `first_red_ordinal` remains comparable across the whole CP4c arc. **The closure claim is upheld.**

One documentation defect was found and is recorded in §9: the tracker's `CAND-03` entry cites
`Architecture_M3_CP4c1_CB4_Code_Build_Report.md` for the "full rationale", but that document was retired in the
fifth consolidation. No information is lost — the per-identity rationale is reproduced in the tracker entry
itself — but the citation dangles.

#### 2. The measured state of A2b — DURABLE

All three production witnesses currently fail to produce a `GlobalTopologyPlan`, with **three different**
causes. This is the single most important fact for the implementation agent, because it means "A2b is broken"
is not one problem:

| Witness | A2a result | A2b result | Failure code | Stage |
|---|---|---|---|---|
| torus | network published: 48 `HardFeature` mandatory edges, **0** singularities, 48 structural nodes, **0** traces, **0** events | fails | `UncutFaceComponentOrbitSeedNotUnique` | A2b |
| prescribed sphere | network published: **24** traces, **56** events | fails | `RotationSystemInconsistent` | A2b |
| mechanical feature | **no atlas** | never reached | `IncompleteCycleBasis` | **A1** |

The mechanical witness never reaches A2b at all; it stops in A1. It belongs to CP4c-3 with C2 and is **out of
scope for CP4c-2** — do not attempt to fix it here.

#### 3. Theorem — the torus network provably cannot bound discs

This is not a conjecture and it does not require new measurement.

Let `S` be a closed orientable surface of genus `g`, and let `G` be a graph embedded in `S` with `V` vertices
and `E` edges. If every component of `S \ G` is an open disc, the embedding is **cellular**, and Euler's formula
gives

```
V − E + F = χ(S) = 2 − 2g,     so     F = E − V + 2 − 2g.
```

For the torus, `g = 1` and `χ = 0`, so `F = E − V`. The complement is non-empty — the torus publishes zero
traces, so almost every source face is untouched by the network — hence `F ≥ 1` is required, which forces

```
E ≥ V + 1.
```

**The measured torus network has `V = 48` and `E = 48`, so `F = 0`.** Contradiction. At least one component of
the complement is therefore **not** a disc.

The result is stronger and more useful than the arithmetic coincidence suggests. A graph with `E = V` in which
every vertex has even degree is a disjoint union of cycles, and **any** disjoint union of cycles has `E = V`
exactly. Therefore:

> **No disjoint union of closed curves can ever be a cut graph of the torus.**

Cutting a torus along disjoint loops yields cylinders or a torus-with-holes, never a disc — regardless of
*which* loops they are. So this is not a defect of the particular committed fixture, and it cannot be fixed by
choosing better feature curves. **A cut graph of a genus-`g` surface must contain vertices of degree ≥ 3 and
must realize a homology basis; a feature/singularity-derived network has no mechanism that guarantees either.**

This is exactly what the production code detects. `src/geometry/GlobalTopologyPlan.cpp:1694-1746` unions
untouched faces across edges that are neither mandatory nor trace-touched, then requires each resulting
component to receive **exactly one** orbit seed from its labeled neighbours. A cylindrical component touches
labeled faces on both of its boundary circles, collects two distinct seeds, and fails at line 1741 with
`UncutFaceComponentOrbitSeedNotUnique`. **The error code is correct and the producer is behaving correctly.
There is no bug at that line.** It is reporting a missing input.

#### 4. The `DESIGN.md` §7.2 defect

§7.2 states nine normative derivation steps and eight invariants. Two of them are wrong or ill-defined on closed
surfaces:

- **Invariant 7** — "every resulting region has disc topology unless explicitly typed otherwise" — and the
  closing claim that "**because tracing is combinatorial and terminates on contact, invariants 3 and 7 hold by
  construction.**" §3 proves invariant 7 does **not** hold by construction. Termination-on-contact makes traces
  well-defined; it says nothing about whether the resulting graph is a cut graph. The two properties are
  independent, and the design conflates them.
- **Step 8** — "extract the faces of the embedded graph." For a **non-cellular** embedding the "faces of the
  embedded graph" are not discs, and the phrase has no well-defined meaning as an instruction. The step
  presupposes cellularity that step 1–7 never establish.

And the closing sentence creates the trap:

> "The architecture contains no limit-cycle detection, tiny-region collapse, or **non-disc repair step, and
> adding one is a stop condition**: such a step would be a repair of an immutable upstream product."

**Read literally, the design forbids the only viable fix.** Amendment 12 resolves this, and the resolution turns
on a distinction the implementation agent must understand exactly, because getting it wrong produces an
architecture violation that will pass a naive gate:

> **Establishing a precondition before a product is derived is not the same as repairing that product after it
> is derived.** The stop condition exists to prevent A2b from *observing* a non-disc region and then patching,
> collapsing, or re-cutting it — a mutation of an immutable upstream product, which would destroy
> single-writer authority and make the disc certificate self-fulfilling. It does **not** forbid a separate,
> earlier authority from *supplying additional cuts as an input*, so that region derivation has a cellular
> embedding to work with in the first place.

The practical test the implementation agent must apply to its own design: **if the cut decision can be made
without ever looking at a produced `GlobalTopologyPlan` region, it is a precondition; if it needs to see one, it
is a repair and is a stop.**

##### Amendment 12 — normative, replaces the quoted text in §7.2

1. Invariant 7 is **not** claimed to hold by construction. It holds **conditionally**, on the curve network
   together with the cut graph forming a cellular embedding of the source surface. Invariant 3 continues to hold
   by construction from termination-on-contact and is unaffected.
2. Step 8 is amended to read: *extract the faces of the cellular embedding formed by the curve network together
   with the published `SurfaceCutGraph`.* Face extraction on a non-cellular embedding is undefined and must
   fail closed with a typed error, never produce a region.
3. A new normative step is inserted between steps 7 and 8: *complete the network to a cellular embedding by
   consuming the `SurfaceCutGraph` product, which is derived from the source topology and the immutable curve
   network and is produced before any region exists.*
4. The stop condition is narrowed to its intent and restated: **repairing, collapsing, re-cutting, or
   re-typing a region after `GlobalTopologyPlan` has derived it remains a stop condition.** Supplying cuts as a
   typed input, before derivation, from a separate single-writer authority, is explicitly permitted and is the
   only sanctioned route.
5. §4.6's motorcycle-graph region-decomposition guarantee is amended to name its condition: it supplies the
   decomposition guarantee **only when the field has at least one singularity or the surface has a boundary**.
   On a closed surface carrying an index-free field the motorcycle graph is empty, and the decomposition
   guarantee comes from the cut graph instead.

#### 5. The frozen contract for `SurfaceCutGraph` (stage A2a′)

##### 5.1 Position and authority

- **Produced after** A2a (`FieldAlignedCurveNetwork`) and **before** A2b (`GlobalTopologyPlan`).
- **Single writer.** Nothing else may create, extend, or amend cut edges. A2b consumes it `const` and may not
  add to it.
- **Inputs, all immutable:** `SourceAuthoritySnapshot`, `FieldTransportAtlas`, `FieldAlignedCurveNetwork`.
- **It may not read, construct, or depend on any `GlobalTopologyPlan` or any region.** This is the §4
  precondition-versus-repair boundary and it is a hard architectural constraint, not a style preference.

##### 5.2 Output

A typed product carrying, at minimum:

1. an ordered, deterministic set of **cut edges**, each identified by an existing `SourceEdgeTopologyKey` — cuts
   run along existing source mesh edges only; **no new geometry, no subdivision, no vertex insertion**;
2. a **cellularity certificate** recording `V`, `E`, `F`, the computed `χ`, the source surface's `χ`, and their
   equality;
3. per-component evidence sufficient to show each complementary component is a disc, in the shape the existing
   region certificate already uses — `boundaryWalkCount == 1`, `sourceFacesConnected == true`,
   `eulerCharacteristic == 1`;
4. provenance binding it to the exact `FieldAlignedCurveNetwork` semantic digest and source digest it was
   derived from, so a mismatched pairing fails closed.

##### 5.3 Required guarantees

- **Cellularity.** `network ∪ cutGraph` is a cellular embedding of the source surface. This is the product's
  reason to exist and must be certified, not assumed.
- **Mandatory preservation.** Every mandatory edge — hard feature and boundary — remains in the combined graph.
  Cuts may be added; nothing may be removed, merged, or reclassified.
- **Exactness and determinism.** No tolerance, no floating-point threshold, no iteration limit that can alter
  the result. The same input produces the same cut set byte-for-byte, independent of container iteration order
  and of source face/edge ordering.
- **Idempotence.** When the network is already cellular — which is the expected case for any witness with
  singularities — the product must publish an **empty** cut set and a passing certificate. It must not add
  gratuitous cuts.
- **Fail closed.** If cellularity cannot be achieved, publish a typed error. Never publish a partial cut graph
  and never let A2b proceed on an uncertified embedding.

##### 5.4 Construction guidance — explicit, because the implementation agent must not have to guess

The recommended construction is a **tree–cotree decomposition** (Eppstein; Erickson–Whittlesey), applied per
complementary component:

1. Compute the complementary components exactly as the existing producer already does at
   `GlobalTopologyPlan.cpp:1694-1704` — union faces across edges that are neither mandatory nor trace-touched.
   **Reuse that traversal rather than writing a second one**, so the two cannot diverge; if it must be moved to
   be shared, move it, do not copy it.
2. For each component, compute `χ` and its boundary-cycle count from the source mesh restricted to it. It is a
   disc **iff** `χ == 1` **and** boundary-cycle count `== 1`. Both conditions are required: an annulus has
   `χ == 0`, and a sphere-with-two-holes and a disc are distinguished only by the second.
3. For each non-disc component, build a spanning tree of its dual (face-adjacency) graph and a spanning tree of
   its primal graph; the edges in neither tree are the generators. Add the corresponding primal edges to the cut
   set. Each added generator strictly reduces the component's first Betti number, so the process terminates.
4. Re-verify from scratch. **Do not infer cellularity from the construction argument** — recompute `V`, `E`,
   `F` on the combined graph and check `V − E + F == χ(S)`, then check every component's disc certificate. The
   project's standing rule applies: an oracle built on the mechanism it tests is not yet a test.

Ties in generator selection must be broken by a **total order on typed IDs**, never by container order, never by
geometry, and never by a floating-point quantity.

##### 5.4.1 R5-REV corrective override — whole-source-face barrier components are not cellularity authority

**Status: binding correction recorded by `M3-CP4c-2-TB-X2-R5-REV`; exact redesign belongs to
`M3-CP4c-2-DEFN-R1`.**

R5 independently proved that §5.4 step 1's whole-source-face/source-edge-barrier construction is **not an exact
representation of the complement of `FieldAlignedCurveNetwork` when trace arcs cross source-face interiors**.
On the accepted two-ring witness, retained CP4ab fragment/orbit authority has three interior embedded-graph
faces while the source-edge-barrier proxy has two whole-face components. The proxy may be arithmetically
self-consistent and still describe a different complex.

Therefore, until DEFN-R1 freezes the replacement:

1. **§§5.1–5.3 remain binding.** `SurfaceCutGraph` must certify the actual immutable network plus its added cuts,
   preserve idempotence, determinism, and fail-closed behavior, and may not repair a produced A2b region.
2. **§5.4 step 1 is withdrawn as cellularity authority.** A whole-source-face `SourceFaceComponentPartition`
   separated by trace carrier edges may be used only as proposal/provenance/diagnostic data. It may not define
   the actual complement, its face count, or its per-component disc proof.
3. **§5.4 steps 2–4 are non-authoritative wherever they depend on that proxy representation.** Final `V/E/F`,
   boundary walks, and disc certificates must all be recomputed in one exact representation of the actual
   embedded `network ∪ cutEdges`.
4. **Do not repair this by changing only the Euler terms.** On the accepted two-ring, using proxy `10/11/2`
   would make the equation green while certifying the wrong object. The representation and every consumer of
   it must move together, per LESSONS 22d/22e.
5. **No product mutation is authorized by this note.** DEFN-R1 must first freeze a pre-region
   face-fragment/orbit (or equivalent exact arrangement) authority, candidate-cut update rule, termination proof,
   and independent same-semantic-complex oracle.

**A note on quality, and its limit for this checkpoint.** A cut graph is not unique, and the choice affects
downstream quad quality: cuts ideally follow the field and lie where a seam is least visible. **CP4c-2 does not
optimize that.** Its obligation is a correct, deterministic, certified cut graph. Choosing a *good* cut graph is
a quality concern, and the frozen requirement here is only that the interface make a future policy swap possible
— the selection rule must be one named, replaceable strategy, not scattered inline decisions. Do not build the
alternatives harness in this checkpoint.

#### 6. Scope — what CP4c-2 owns, and the C3 deferral

##### 6.1 In scope

- **C1** `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath` — the torus derives regions
  through the production entry path. This is the checkpoint's anchor and its non-vacuity guarantee.
- **C6** `GlobalTopologyPlan.ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation` — produced regions
  carry the disc proof and preserve mandatory topology.
- `DESIGN.md` Amendment 12 and the `SurfaceCutGraph` product.

##### 6.2 A vacuity trap that must be closed

**C3 and C6 are both quantified over "produced witnesses."** Today no witness produces a plan, so **both would
pass vacuously** on a suite where nothing reaches A2b. That is the same defect class as CP4c-1's C5 — a
criterion whose truth value does not depend on the thing it is supposed to certify.

**Binding requirement:** CP4c-2 may not close on a vacuous C6. C1 is the non-vacuity anchor — the torus must
actually produce a plan with at least one region, and C6 must be shown to have examined at least that many
regions. Measure **X7** makes this reportable rather than assumed.

##### 6.3 Why C3 is deferred, and what would bring it back

**C3** `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` is currently failing on the
prescribed sphere with `RotationSystemInconsistent`. That failure is **not** the cut-graph gap:

- the sphere has `χ = 2`, 24 traces and 56 events — a network with real structure, unlike the torus;
- its failure code is different and is raised from a different part of A2b (many sites in
  `GlobalTopologyPlan.cpp`, including 412-564 and 790-839);
- nothing measured so far localizes it.

Designing a fix for an unmeasured failure is how CP4c-0 acquired a false premise once already. **The cause of
`RotationSystemInconsistent` on the sphere must be measured before it is designed for.** Bundling it into
CP4c-2 would repeat the CP4c-0 / CP4c-0b dependency inversion that cost this project a checkpoint split.

**Trigger to bring C3 back into CP4c-2:** if the CP4c-2 diagnostic required by measure **X2** shows that the
sphere's `RotationSystemInconsistent` is *caused by* non-cellularity — that is, it disappears once the sphere's
embedding is certified cellular — then C3 is in scope and CP4c-2's gate becomes **358 = 355 + C1 + C3 + C6**.
If X2 shows the sphere is already cellular and still fails, C3 belongs to its own checkpoint, and CP4c-2's gate
is **357 = 355 + C1 + C6**. **The selector count is not frozen by this document**; X2 decides it, and the CB
turn freezes it.

##### 6.4 Out of scope — do not touch

The mechanical witness and its A1 `IncompleteCycleBasis`; C2; CP4c-3; any change to accepted ordinals 1-355;
quad quality or seam aesthetics; the alternatives harness.

#### 7. Measures **X0–X9** for `M3-CP4c-2-CB1`

- **X0 — preconditions.** Start from accepted CP4c-1 authority: 355 selector `e9d88f11…5afeaa` with prefixes
  `601ce2b6…`, `20d3b0b1…`, `51ff96d7…`. Re-verify all four before and after; **all four must be byte-identical
  afterward.** Compile under `GMP_COMPILE_POLICY.md` with GMP/GMPXX linked. `runtimeExecution=false`.
- **X1 — re-derive the theorem from the product, not from this document.** Publish the torus network's `V`, `E`
  and the source `χ`, and show `F = E − V + χ` is not a possible positive face count. **If the published
  numbers disagree with §3's `V = 48, E = 48`, stop and report** — that would mean this definition rests on a
  stale measurement, and it must be re-adjudicated rather than worked around.
- **X2 — the C3 scope decision, measured.** Publish, for the prescribed sphere, whether `network` alone is
  already a cellular embedding (`V − E + F == χ == 2`), and whether `RotationSystemInconsistent` still occurs
  once a certified cellular embedding is supplied. Report the exact failing site. This measurement, and only
  this measurement, decides whether the CP4c-2 gate is 357 or 358 per §6.3.
- **X3 — the product.** Implement `SurfaceCutGraph` to the §5 contract: single writer, source-edge cuts only,
  cellularity certificate, mandatory preservation, exact and deterministic, idempotent on already-cellular
  input, fail-closed. **It may not read a `GlobalTopologyPlan`.**
- **X4 — A2b consumes it.** Amend region derivation to consume the cut graph and to fail closed with a typed
  error on an uncertified embedding. **Do not** add any non-disc repair, region collapse, or re-cut inside A2b —
  that is the §4 stop condition and it is unchanged.
- **X5 — determinism proof.** Show the cut set is invariant to source face and edge ordering, and to container
  iteration order, by an identity that permutes input ordering and compares published cut sets exactly. A cut
  graph that depends on iteration order is not a product, it is a coincidence.
- **X6 — idempotence proof.** Show that a witness whose network is already cellular receives an **empty** cut
  set and a passing certificate.
- **X7 — non-vacuity, per §6.2.** Publish the torus's region count and the number of regions C6 actually
  examined. **A green C6 over zero regions is a red result**, and must be reported as such rather than counted.
- **X8 — documentation.** Apply Amendment 12 to `DESIGN.md` §7.2 and §4.6 exactly as §4 above states. Add the
  new stage to the pipeline stage list wherever A0-A9 are enumerated, so the stage map does not silently
  disagree with the code.
- **X9 — prohibited.** Editing any accepted identity or ordinal 1-355; changing the 355 selector or its
  prefixes; adding a non-disc repair, collapse, or re-cut in A2b; introducing any tolerance, threshold, or
  iteration cap that can change the cut set; inserting geometry, subdividing edges, or moving vertices;
  reading a `GlobalTopologyPlan` from A2a′; touching the mechanical witness, C2, or CP4c-3; optimizing seam
  quality; building the alternatives harness.

#### 8. Falsifiable predictions

Stated so the CB and its TB can prove this definition wrong rather than merely comply with it:

1. The torus network's published `V` and `E` are **48 and 48**, and the source `χ` is **0**. *(X1)*
2. The torus's non-disc complementary components are **annuli** — `χ == 0` with boundary-cycle count `== 2` —
   not higher-genus pieces. Anything else means the mandatory-edge set is not a disjoint union of cycles and §3's
   second argument needs revisiting.
3. **At least 2** cut edges are required for the torus, because a genus-1 surface needs two independent
   non-separating cuts to become a disc. Fewer means the certificate is wrong.
4. With cuts supplied, the torus produces a plan whose every region certificate has
   `eulerCharacteristic == 1` and `boundaryWalkCount == 1`, and C1 and C6 both go green **non-vacuously**.
5. The prescribed sphere's network is **already cellular** and its `RotationSystemInconsistent` persists —
   making C3 a separate defect and the gate **357**. *This is the prediction most likely to be wrong, and X2
   exists precisely to test it; if it is wrong, that is a good outcome and C3 rejoins CP4c-2 at 358.*

Any deviation from 1-4 is material and routes to review. A deviation from 5 changes the gate count and is
handled by §6.3 without a review, because X2 was designed to decide it.

#### 9. Defects recorded by this turn

1. **Dangling citation.** `Regression_Root_Cause_Tracker.md`'s `M3-CP4c1-TB-R4-CAND-03` entry cites
   `Architecture_M3_CP4c1_CB4_Code_Build_Report.md`, retired in the fifth consolidation. The substantive
   rationale is reproduced in the tracker entry itself, so nothing is lost; the pointer is corrected by this
   turn to name the consolidated record instead.
2. **`DESIGN.md` §7.2's "by construction" claim is false** on closed surfaces, and has been since the document
   was written. Amendment 12 corrects it. Recorded as a design defect, not a product regression: no code ever
   relied on the false claim — A2b fails closed instead, correctly.

#### 10. Stop / successor

The exact next turn is **`M3-CP4c-2-CB1`**, Code + Build, runtime-free, under measures **X0-X9**.

Its successor is `M3-CP4c-2-TB`, the full gate at **357 or 358** as decided by X2. **CP4c-2 closes on that gate
green with §8's predictions 1-4 met and X7's non-vacuity report showing a non-zero region count.** Anything less
routes to independent review, not to a retry.

---

## Part II — M3-CP4c-2 DEFN-R1

*Source document: `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md`, consolidated verbatim.*

### M3-CP4c-2 DEFN-R1 — Frozen Definitions: the actual embedded-graph complex for A2a′

> **SUPERSEDED IN PART by `Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md` (2026-08-29). Never read this
> document alone.**
>
> - **§6 case 2 is withdrawn.** Amendment 14 makes a trace-crossed source edge an **admissible** cut. The stated
>   ground — that promoting one would subdivide an immutable trace — is false about this codebase: `build_arcs`
>   already emits one trace arc per network event and already splits a mandatory source edge at a trace terminal,
>   and the crossing point is already published exactly. §6 cases 1 and 3 stand.
> - **§8 is superseded.** Completeness is **proved** for all cases, not split: `network ∪ (source 1-skeleton)` is a
>   cellular embedding, so a sufficient cut set always exists. §8.2's typed stop
>   (`NoAdmissibleCutForNonDiscComponent`) is retired as an outcome, and §8.3's conditional trigger is void.
> - **§10 Option B is withdrawn**, its single trigger having been proved impossible; Option A stands and is now
>   unconditional.
> - **Everything else stands unchanged and binding** — Amendment 13, §§4, 5, 7, 9, and Amendment 12.
> - `DESIGN.md` §7.2.1 carries the normative record of Amendments 12, 13 and 14.

#### 0. Turn type and verdict

`M3-CP4c-2-DEFN-R1` is **COMPLETE / DEFINITION-ONLY**.

No Directional runtime, build, compile, package, benchmark, product, test, fixture, or selector change was made
or is authorized by this turn. This document supersedes the withdrawn parts of
`Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md` §5.4 and freezes the contract that `M3-CP4c-2-CB4` will
implement, under measures **AC0–AC9**.

**The decision.** The normative complex for A2a′ is the **actual embedded graph of
`FieldAlignedCurveNetwork ∪ cutEdges`**, represented by the **arc / dart / rotation / face-orbit machinery that
A2b already contains** — `GlobalTopologyArc`, `GlobalTopologyOrientedArc`, `GlobalTopologyNodeRotation`,
`walk_graph_faces` — lifted into a shared pre-region authority that A2a′ and A2b both consume. Nothing new is
invented; the correct representation already exists one stage downstream and is duplicated badly one stage up.

**Amendment 13** to `DESIGN.md` §7.2 records this. **Amendment 12 stands unchanged** — its precondition-versus-
repair boundary is unaffected and remains binding.

#### 1. A reviewer error, owned precisely

`M3-CP4c-2-TB-X2-R2-REVIEW-PLAN` §5 declared the **source-mesh barrier complex** normative, on three stated
grounds. R5 has falsified it and the withdrawal is accepted in full. The failure is worth stating exactly,
because the same reasoning will be available to the next agent and must not be repeated.

I gave three reasons. Each was individually true and collectively wrong:

1. *"It is what A2b actually consumes"* — at `GlobalTopologyPlan.cpp:1694-1704`. **True, and irrelevant.** That
   code path is the *whole-source-face seeding fallback*, not A2b's region authority. A2b's actual region
   authority is `walk_graph_faces` over arcs and rotations, and it produces graph-face orbits. I read one
   traversal, matched it to the symptom, and never asked whether A2b had a second, primary representation.
2. *"The frozen DEFN §5.2 committed to source-edge-only cuts"* — **true, and a non-sequitur.** That cuts are
   drawn from source edges says nothing about which complex certifies them. A source edge added to the graph
   becomes an arc; it does not make whole source faces the unit of complement accounting.
3. *"In it, `V − E + F = χ` is a genuine identity"* — **true, and the trap.** The barrier complex is internally
   self-consistent. That is exactly why it was seductive and exactly why self-consistency is not evidence: a
   coherent computation over the wrong object is still the wrong object. R5 §6 states this correctly.

**The control that would have caught it existed and I did not apply it.** `LESSONS.md` **22d** — "check that
the product's representation can express the answer before debugging the algorithm that computes it" — and
**22e** — "converting a representation converts every consumer of it, or none" — were both written for
`PR8-R042 / M3-CP4b-R001`, the *same* `RP-01 / AUTHORITY_DOMAIN_CONFLATION` pattern, on the *same* two-ring
witness. 22d says in terms that a source face cannot be the atomic unit when trace arcs cross its interior.
Reading `LESSONS.md` in full is mandatory start-of-turn step 5. I did not consult it before freezing a
representation decision, and I froze the representation CP4ab had already rejected.

**Recorded for the next agent:** a review that names a normative representation must cite the accepted
architecture that settles it, not the code path that exhibits the symptom. Where an earlier checkpoint has
already adjudicated a representation, that adjudication is the authority.

#### 2. Independent verification of R5's arithmetic

Recomputed rather than accepted:

| Complex, accepted two-ring | `V` | `E` | `F` | `V − E + F` | source `χ` |
|---|---:|---:|---:|---:|---:|
| actual embedded graph (CP4ab authority) | 9 | 11 | 3 | **1** | 1 |
| source-edge-barrier proxy (R4 D1) | 10 | 11 | 2 | **1** | 1 |
| what `SurfaceCutGraph` actually computes | 9 | 11 | **2** | **0** | 1 |

Both complexes are self-consistent; the producer is a mixture of the two, and `0 ≠ 1` is precisely what
`proves_cellularity()` rejects at `SurfaceCutGraph.cpp:473-474`. R5's localization is confirmed.

The actual-graph `F = 3` is independently corroborated: retained CP4ab evidence records
`walk.orbits.size() = 4` with exactly one exterior orbit, and `drafts.size() = 3` — one draft per interior
orbit. **`F = 3` is a measured product quantity, not a reconstruction.**

#### 3. Amendment 13 — normative, supersedes DEFN §5.4 step 1

1. The complex in which A2a′ certifies cellularity is the **actual embedded graph** of the immutable
   `FieldAlignedCurveNetwork` together with the candidate `cutEdges`. Its vertices are network nodes plus any
   node created by a cut; its edges are network arcs plus cut arcs; its faces are the **dart orbits** of that
   graph under the node rotation system.
2. **Source-edge carrier provenance is not graph-edge authority.** A source edge that a trace merely crosses is
   support/provenance. It becomes a graph edge only when it is itself a mandatory edge or a selected cut edge.
3. The whole-source-face / source-edge-barrier partition is **withdrawn as cellularity authority**. It may be
   retained **only** as a cut-*proposal* heuristic and as diagnostic provenance, and every publication of it
   must carry an explicit label saying it is not a cellularity oracle.
4. `DEFN` §§5.1–5.3 — the product's position, single-writer authority, output shape and guarantees — remain
   **binding and unchanged**. §5.4's construction guidance is replaced by §§4–8 of this document.
5. **Amendment 12 is unaffected.** Establishing a precondition before a product is derived is still not
   repairing it afterward, and A2a′ still may not read a `GlobalTopologyPlan`.

#### 4. The representation, named concretely

The implementation agent must not invent a representation. **All four pieces exist today in
`src/geometry/GlobalTopologyPlan.cpp` and `include/directional/geometry/GlobalTopologyPlan.h`:**

| Concept | Existing type / function | Meaning |
|---|---|---|
| arc | `GlobalTopologyArc` — `id`, `kind`, `firstNode`, `secondNode`, optional `mandatoryEdge`, optional `trace` | one exact arc of the embedded graph |
| dart | `GlobalTopologyOrientedArc` — `arc` + `orientation` | one directed side of an arc |
| rotation | `GlobalTopologyNodeRotation.counterClockwise` | the cyclic dart order at a node |
| face | `walk_graph_faces(arcs, rotations)` → `FaceWalkResult{orbits, orbitByDart}` | each orbit is one face boundary walk |
| fragment | `fragmentOrbits[SourceFaceTopologyKey] → {orbit}` | the CP4ab ownership unit: a source face split by the orbits crossing it |

**The corrective is a lift, not a rewrite.** A2a′ must consume this machinery rather than its own
`network_barriers` / `build_components` / `certify_component` triple. Move the arc-and-rotation construction and
`walk_graph_faces` into a shared pre-region authority — a new header under `src/geometry/` or an equivalent —
that both A2a′ and A2b include. **Do not copy it.** A second implementation is how this checkpoint arrived
here; `LESSONS.md` 22e requires one conversion covering every consumer.

#### 5. Conventions that must be made exact, not assumed

These are the places where a plausible guess produces a wrong certificate. Each must be **written down in the
CB report with the reasoning**, not inferred from a passing witness.

- **5.1 Boundary orbits on a surface with boundary.** The accepted two-ring is a disc, `χ = 1`, and its walk
  yields **4 orbits of which exactly one is exterior**; `F = 3` counts interior orbits only. Freeze the rule
  that identifies the exterior orbit(s) and excludes them, and state how it generalizes to a surface with
  several boundary loops. For a **closed** surface — torus, sphere — there is no exterior orbit and every
  orbit is a face.
- **5.2 Disconnected graphs.** The torus's network is 48 arcs over 48 nodes with every node of degree 2 —
  a disjoint union of closed curves, so the graph is **not connected**. The Euler identity for a cellular
  embedding assumes connectivity; with `c` components it acquires a correction term. **Derive that term
  explicitly, state it, and verify it on the torus.** Do not adopt `V − E + F = χ` unqualified: on the torus it
  is false even before any cut is considered, and mistaking that for non-cellularity would be right for the
  wrong reason.
- **5.3 Nodes of degree 0, 1 and 2.** The rotation system must be well defined at every node, including the
  degree-2 nodes that dominate the torus and any isolated node. State the convention.
- **5.4 What counts as `V` and `E` when a cut shares an endpoint with the network.** A cut edge whose endpoint
  is already a network node adds an arc but no vertex; one whose endpoint is a bare source vertex adds both.
  The existing producer already attempts this at `SurfaceCutGraph.cpp:449-456` and must be re-derived in the
  new complex rather than carried over.

#### 6. Cut semantics in the actual complex

This is the substantive new constraint, and it is where the previous design was silently unsound.

**A cut edge is a source edge promoted to a graph arc.** Adding it changes the arrangement. Three cases, and
all three must be handled explicitly:

1. **The source edge is untouched by any trace.** It becomes one arc between its two endpoints. Straightforward.
2. **The source edge is a carrier that a trace crosses at an interior point.** Promoting it creates an
   **intersection with an immutable trace arc**. That would subdivide the trace — mutating an immutable
   upstream product, which Amendment 12 forbids. **Such an edge is therefore not an admissible cut.**
3. **The source edge already is a mandatory edge.** It is already an arc; it cannot be "added" and must not be
   double-counted.

**Frozen rule: the admissible cut set is exactly those source edges that are neither mandatory edges nor
crossed by any trace at an interior point.** Admissibility must be decided exactly, from published trace
segment carriers, with no tolerance.

#### 7. Certification, in one complex

Both certificates are recomputed from the actual combined graph. **No proxy quantity may appear in either.**

- **Per-face:** every orbit that is not an excluded boundary orbit must bound a disc. Publish, per orbit, the
  evidence used.
- **Global:** the Euler identity in the form fixed by §5.2, over `V` = graph vertices, `E` = graph arcs,
  `F` = counted orbits, against source `χ`.
- **Provenance:** each certificate carries the digests already required by DEFN §5.2 plus a **complex label**
  naming the actual-embedded-graph complex, so a future reader can never again mistake which object was
  certified.

**Prohibited:** mixing any barrier-partition count into either certificate; relaxing `proves_cellularity()` to
accommodate a count; and — restating R5 §5, which is correct — changing the global certificate to the proxy's
`10/11/2`, which would make the two-ring green while certifying the wrong object.

#### 8. Cut-selection completeness — proved where it can be, typed stop where it cannot

Measure AB7 required a completeness proof or an explicit definition stop. **The honest answer is that
completeness is provable for one case and not yet for the other, and this definition freezes that split rather
than papering over it.**

- **8.1 Trace-free non-disc components — PROVABLE, and this is the torus.** Where no trace crosses the
  component, every source edge in it is admissible under §6, so a tree–cotree construction over the component's
  own primal and dual spanning trees yields generators whose promotion strictly reduces its first Betti number.
  The process terminates. **The torus is entirely in this case: it has 0 traces.** CP4c-2's own witness is
  therefore fully served.
- **8.2 Trace-crossed non-disc components — NOT PROVED.** With §6 removing every trace-crossed source edge from
  the admissible set, a component may have no admissible cut that reduces its genus. **No completeness claim is
  made.** The producer must, in that situation, **fail closed with a distinct typed error** — a new code such as
  `NoAdmissibleCutForNonDiscComponent`, carrying the component locus — and must never fall back to an
  inadmissible cut, a tolerance, or a partial cut set.
- **8.3 Why this is not a blocker in practice, and the condition on that claim.** The case in 8.2 arises only
  for a witness that is **both** non-cellular **and** trace-crossed. The torus is non-cellular and trace-free;
  the prescribed sphere is trace-dense and, on the standing prediction, already cellular and needing no cuts at
  all. **If the sphere turns out to be non-cellular, 8.2 becomes live and CP4c-2 must return to definition** —
  measure AC7 makes that an explicit stop rather than a surprise.

#### 9. The independent oracle

AB8's independence bar is raised and made concrete. The oracle must:

1. build arcs, rotations and orbits **by its own construction**, not by calling the shared authority of §4 and
   not by calling `SurfaceCutGraph`;
2. publish actual graph `V`, `E`, total orbits, excluded boundary orbits, counted `F`, component count `c`,
   the §5.2 identity and its result;
3. publish per-source-face fragment/orbit structure, so the CP4ab representation is directly visible;
4. publish cut provenance — for each cut, its admissibility class under §6;
5. compare **term by term** against the producer's published certificate and report each difference
   individually;
6. carry `complex=actualEmbeddedGraph` on every record.

**Explicitly insufficient, and named because it was accepted once already:** a different implementation over
the source-edge-barrier partition. Self-consistency inside the wrong complex is not independence.

The retained `sourceEdgeBarrier` oracle is **not deleted**. It is relabelled diagnostic-only, keeps
`complex=sourceEdgeBarrier`, and must carry a field stating it is not a cellularity oracle. It remains useful
for measuring the proposal heuristic.

#### 10. Sequencing, and the accepted regression

`PR8-R043 / M3-CP4c2-R001` — accepted ordinal 305 red — is the highest-priority item, and there are two ways to
clear it.

- **Option A — fix the certificate in the actual complex (RECOMMENDED).** Ordinal 305 fails because the
  certificate is wrong. Fixing it restores accepted behavior *and* delivers the checkpoint. The accepted
  identity is doing its job: it detected a real defect the moment CP4c-2 wired A2a′ into its path.
- **Option B — decouple A2a′ from the accepted path until the certificate is correct.** Cheaper and faster to
  green, but it restores the prefix by removing the check that caught the defect, and it re-opens the torus gap
  that CP4c-2 exists to close.

**Option A is frozen as the plan.** Option B is retained as a **contingency with one trigger**: if §8.2 goes
live — the sphere proves non-cellular and no admissible cut set exists — then CP4c-2 returns to definition, and
the accepted prefix must not be held hostage to that redesign. In that case, and only then, decoupling is
authorized so accepted authority is restored while the definition work proceeds.

#### 11. Measures **AC0–AC9** for `M3-CP4c-2-CB4`

- **AC0 — preconditions.** Accepted historical authority remains CP4c-1 **355/355**. Preserve all six frozen
  selector files and hashes: 316 `601ce2b6…0193c`, 346 `20d3b0b1…3e46a`, 353 `51ff96d7…ac6a5`, 355
  `e9d88f11…5afeaa`, 357 `b896d0db…64dc70`, 358 `6eda3aad…b64fbe62`. Compile under `GMP_COMPILE_POLICY.md`
  with GMP/GMPXX; `runtimeExecution=false`. Keep `selected_r2_branch=NONE`, `selected_gate=NONE`,
  `gate_execution_authorized=false`.
- **AC1 — lift, do not duplicate.** Move the arc/rotation/face-walk construction of §4 into one shared
  pre-region authority consumed by **both** A2a′ and A2b. **A second implementation is prohibited** — that is
  `LESSONS.md` 22e. Report the exact file and symbol that now owns it and every call site converted.
- **AC2 — convert every consumer in one package.** A2a′'s per-face certificate, its global certificate,
  `GlobalTopologyPlan`'s consumption of the cut graph, and every diagnostic that reads either must move to the
  actual complex **together**. Enumerate them in the CB report and state, for each, that it was converted.
  **A partial conversion is the defect this checkpoint is correcting; it must not be the fix.**
- **AC3 — write the conventions down.** Publish §5.1–5.4's four conventions as prose plus code, with the
  derivation of §5.2's disconnected-graph correction term shown, not asserted.
- **AC4 — admissible cuts.** Implement §6 exactly: admissible = source edge that is neither a mandatory edge
  nor crossed by a trace at an interior point, decided exactly with no tolerance. Publish, per candidate cut,
  which class it fell into.
- **AC5 — the typed stop.** Add the §8.2 error code (`NoAdmissibleCutForNonDiscComponent` or an equally
  explicit name) with a component locus. **Never** fall back to an inadmissible cut, a tolerance, or a partial
  cut set. This code existing is not a failure of the design; it is the design refusing to certify what it
  cannot.
- **AC6 — derive the witnesses, never encode them.** The two-ring's `9 / 11 / 3 / χ=1` must fall out of the
  representation. **No witness-name branch, expected-value table, or constant.** If the representation cannot
  reproduce it without witness-specific logic, **stop and report** — §5's conventions are then wrong.
- **AC7 — the §8.2 trigger is a stop, not a judgement call.** If any witness reaches a non-disc component with
  no admissible cut, the CB **stops and returns to definition**. It does not widen admissibility, does not
  subdivide a trace, and does not proceed with a partial cut set.
- **AC8 — the oracle.** Implement §9's independent oracle as a **non-gating** identity, and relabel the
  retained `sourceEdgeBarrier` oracle diagnostic-only with the explicit not-a-cellularity-oracle field.
- **AC9 — prohibited.** Mixing any barrier-partition quantity into a cellularity certificate; relaxing
  `proves_cellularity()`; changing the global certificate to the proxy's `10/11/2`; subdividing or otherwise
  mutating an immutable trace; A2a′ reading a `GlobalTopologyPlan`; a second implementation of the arc/orbit
  machinery; encoding any witness's expected values; changing or inventing selectors; running a cumulative
  gate, R6, 357/358, `CB4`'s own acceptance, mechanical/C2, or CP4c-3; reverting AA1, whose innocence R5 §9
  establishes; and executing Option B of §10 outside its single stated trigger.

#### 12. Falsifiable predictions

1. Under the actual complex the accepted two-ring yields `V = 9`, `E = 11`, counted `F = 3`, identity result
   `1 = χ`, **derived from authority**. Accepted ordinal 305 returns green.
2. The torus yields `V = 48`, `E = 48`, `c = 4` connected components, and — under §5.2's corrected identity —
   **non-cellular**, matching the frozen theorem. Its four complement components are annuli.
3. Every torus cut candidate is **admissible** under §6, because the torus has zero traces; §8.1 applies and
   the cut selection terminates.
4. The prescribed sphere, once measurable, is **already cellular** in the actual complex, needs zero cuts, and
   `CellularityNotEstablished` disappears for it. *(This is the standing prediction from DEFN §8.5, the X2 plan,
   and R4 — still unadjudicated across six turns. It is the load-bearing uncertainty.)*
5. `NoAdmissibleCutForNonDiscComponent` is defined but **never fires** on any of the three witnesses.
6. No accepted identity other than 305 changes state.

Prediction 4 is the one that decides whether §8.2 goes live. Prediction 2's correction term is the one most
likely to be got wrong on the first attempt.

#### 13. Stop / successor

The exact next turn is **`M3-CP4c-2-CB4`**, Code + Build, runtime-free, under measures **AC0–AC9**.

Its successor is a fresh artifact-only **`M3-CP4c-2-TB-X2-R6`** — **not** a cumulative gate — which must re-prove
accepted prefixes 316/346/353/355 including ordinal 305, then publish the §9 oracle and the term-by-term
comparison, then attempt D2. `R5-ORCH-01` must be fixed in the runtime harness before R6: postflight must run
from an unconditional finalization or trap path so a red process cannot suppress it.

`selected_r2_branch` remains **NONE**, `selected_gate` remains **NONE**, `gate_execution_authorized` remains
**false**.

---

## Part III — M3-CP4c-2 DEFN-R2

*Source document: `Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md`, consolidated verbatim.*

### M3-CP4c-2 DEFN-R2 — Frozen Definitions: trace-crossed cut admissibility, and CP4c-2 gate membership

#### 0. Turn type and verdict

`M3-CP4c-2-DEFN-R2` is **COMPLETE / DEFINITION AND PLANNING ONLY**.

No Directional runtime, build, compile, package, benchmark, product, test, or fixture change was made or is
authorized by this turn. One **selector authority file was created**, which is this turn type's proper output and
was explicitly deferred to it by measure **AF5**; no existing selector byte was modified.

This document supersedes `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` **§6 case 2** and **§8** only.
Everything else in DEFN-R1 — Amendment 13, §§4, 5, 7, 9 — **stands unchanged and remains binding**, as does
Amendment 12.

**Two decisions.**

1. **Amendment 14.** A source edge crossed by a trace at an interior point **is an admissible cut.** DEFN-R1 §6
   case 2 excluded it on the ground that promoting it would subdivide an immutable trace. That ground is
   **factually wrong about the product**: the producer already subdivides every trace into one arc per event, and
   already subdivides a mandatory source edge at a trace terminal. Arcs are a derived representation; the
   `FieldAlignedCurveNetwork` is untouched either way. With the exclusion removed, **cut-set completeness is
   proved outright** (§5) and DEFN-R1 §8.2's open case closes.
2. **AF5 gate membership is resolved per identity** (§7). Candidate **357 is superseded** and candidate **358 is
   withdrawn**; the CP4c-2 required-green gate is the newly frozen **selector 361**, whose 355- and 357-prefixes
   are byte-identical to the accepted and previously frozen authorities.

Measures issued here are **AG0–AG9**.

---

#### 1. Why DEFN-R1 §8.2 is live, stated exactly

DEFN-R1 §8.3 made the trace-crossed case conditional: *"The case in 8.2 arises only for a witness that is both
non-cellular and trace-crossed… the prescribed sphere is trace-dense and, on the standing prediction, already
cellular and needing no cuts at all. If the sphere turns out to be non-cellular, 8.2 becomes live."*

**The trigger has now fired on measured evidence.** `M3-CP4c-2-CB6` obeyed measure `AF1` — extract the sphere's
independent oracle row from retained result artifact `9721564203` before planning any new runtime — and read:

```
m3Cp4c2ActualGraphOracle  witness=prescribed-sphere  complex=actualEmbeddedGraph
V=18  E=30  F=18  c=1  chi=6  sourceChi=2  excludedBoundaryOrbits=0
surfaceCutGraphCallsInsideOracle=0     producerStatus=error / CellularityNotEstablished
```

`18 − 30 + 18 = 6 ≠ 2`. For any embedded graph `V − E + F ≥ χ`, with equality exactly when the embedding is
cellular, so **the prescribed sphere's pre-cut network graph is not a cellular embedding**, independently of the
producer. The standing prediction — carried unadjudicated since DEFN §8.5 — is **REFUTED**, and the sphere carries
24 traces. That is precisely DEFN-R1 §8.3's stated condition, so §8.2 is live on evidence rather than on an
argument about evidence, and CB6 correctly stopped before implementing anything.

**Two facts that must not be conflated, because they are both true.** R7-REV established that the *producer's*
`CellularityNotEstablished` is `topology_error`'s `default:` bucket for 36 distinct `GlobalTopologyPlanErrorCode`
values, raised at `SurfaceCutGraph.cpp:240/243` **with the cut set still empty** — upstream of any cut proposal and
upstream of any cellularity decision. CB6's oracle bypasses the producer entirely
(`surfaceCutGraphCallsInsideOracle=0`) and measures the graph directly. So the sphere has **two independent
problems**: a producer that fails early through a lossy error translation, *and* a network that genuinely needs
cuts. Neither finding weakens the other, and fixing one does not fix the other.

**A derived reading, offered as such and not as measurement.** The excess `6 − 2 = 4` is the standard defect term:
a sphere has no genus, so every non-disc complement component contributes one unit per boundary walk beyond its
first. Four excess units therefore indicate roughly four extra boundary circles — for example four annular
components, or one component with five boundary circles. **AG3 should verify this against the per-component
records rather than adopting it**; it is a prediction about what the cut search will face, not a result.

DEFN-R1 §8.3 also carried a second cost that only became visible once the trigger fired: it made the checkpoint's
**contingency** (§10 Option B, decoupling A2a′ from the accepted path) fire on the same condition. A contract and
its rollback plan hinging on one fact is a single point of failure. DEFN-R2 therefore resolves the contract
**unconditionally**, so that no further measurement of any witness can reopen the definition.

**What this turn does not claim.** It does not solve the sphere's *producer* failure. That failure occurs with zero
cuts, before cut selection runs at all, and nothing in Amendment 14 touches that path. `AF0`'s printed code remains
the prerequisite for any product fix there, and DEFN-R2 changes neither `M3-CP4c2-TB-X2-CAND-04` nor its ownership.
What DEFN-R2 does supply is the contract under which the sphere's *measured* non-cellularity can be resolved once
the producer reaches cut selection at all — and §5 proves a sufficient cut set exists for it.

---

#### 2. The finding that resolves the contract

DEFN-R1 §6 case 2 reads:

> *"The source edge is a carrier that a trace crosses at an interior point. Promoting it creates an intersection
> with an immutable trace arc. That would subdivide the trace — mutating an immutable upstream product, which
> Amendment 12 forbids. Such an edge is therefore not an admissible cut."*

Three verified facts falsify the premise. All are in `src/geometry/EmbeddedGraphTopology.cpp`, at source bytes
identical to the packaged semantic source `755485865a7cf9c485d754f22b82a41ee151824b`.

**2.1 There is no "immutable trace arc". A trace is already many arcs.** `build_arcs` (`:344-408`) collects, for
each trace, every network event incident on it, keyed by **segment position**, then emits one `Trace` arc per
consecutive pair. A trace with `k` interior events becomes `k + 1` arcs, each carrying `trace.id`, `firstSegment`,
`onePastLastSegment` and its own `sourceFaces` span. **Subdividing a trace in the derived arrangement is the
established, accepted representation**, and it is how the accepted 355 gate has been green for the whole arc.

**2.2 The producer already subdivides a source edge at a trace contact.** `build_arcs` (`:281-329`) splits a
`Mandatory` source edge into `ArcDraft(firstNode, terminal)` and `ArcDraft(terminal, secondNode)` when a trace
terminates on it. One `NetworkEdgeId`, two arcs, a shared node interior to the source edge. The immutable
mandatory edge is unchanged; only the arrangement has two arcs.

**2.3 The crossing point is already published exactly, and already indexed.** A
`FieldAlignedCandidateTraceSegment` (`include/directional/geometry/SurfaceCellTracing.h:246-269`) is one source-face
traversal carrying `incomingCarrier`, `outgoingCarrier`, and an exact `entryPoint` of type
`authority::FieldBoundaryPoint`. Segment `i`'s exit through its outgoing carrier **is** segment `i+1`'s entry, at
`segments[i+1].entryPoint` — an exact point on that source edge, with no tolerance. `trace_crossed_source_edges`
(`SurfaceCutGraph.cpp:78-120`) already reads exactly these points and already tests strict interiority exactly
(`exact_interior_parameter`).

**Conclusion.** A trace crossing a source edge is a point that the network itself publishes exactly, at a segment
boundary the arc-subdivision machinery already keys on. Promoting that edge requires no new geometry, no
tolerance, no predicate, and no mutation of any upstream product. Amendment 12 forbids A2a′ **repairing** an
upstream product; it does not forbid A2a′'s own arrangement from placing a node where the network already says two
curves meet.

**The reviewer error this repeats, named so it is not repeated a third time.** DEFN-R1 §6 reasoned from a property
of the *product* ("the trace is immutable") to a constraint on the *representation* ("therefore it cannot be
subdivided"), without checking what the representation already did. That is the same shape as the R2 error owned in
DEFN-R1 §1 — a true statement about one authority applied to a different one. The control is `LESSONS.md` 22e:
before ruling a representation out, read what the existing consumers of that representation actually do.

---

#### 3. Amendment 14 — normative, supersedes DEFN-R1 §6 case 2 and §8

Recorded against `DESIGN.md` §7.2 alongside Amendments 12 and 13.

1. **A source edge crossed by one or more traces at interior points is an admissible cut.** Promoting it adds one
   graph arc per sub-interval between consecutive crossing points, and one graph node per crossing point.
2. **Crossing nodes are cut-created nodes.** Amendment 13 §1 already defines the vertex set as "network nodes plus
   any node created by a cut". A crossing node is such a node. It is **not** a network node, carries no
   `NetworkEdgeId` or event, and must never be published back into the `FieldAlignedCurveNetwork`.
3. **The trace is subdivided in the arrangement, not in the product.** The trace arc spanning the crossing is split
   at the same segment position the crossing occupies. `trace.id`, its segments, its events and its digests are
   unchanged. This is exactly what §2.1 shows the producer already does at every event.
4. **The admissible cut set is exactly those source edges that are not already graph arcs** — that is, every source
   edge that is neither a mandatory edge nor an already-selected cut. `SurfaceCutCandidateClass::TraceInteriorCrossing`
   is **retained as published provenance** and **removed as an exclusion**: it now records *how* an edge was
   promoted, not *whether* it may be.
5. **All admissibility and ordering decisions remain exact.** Crossing positions come from published
   `FieldBoundaryPoint` parameters; interiority uses the existing exact predicate; ordering along an edge uses
   exact comparison. **No tolerance may be introduced anywhere in this path**, and no crossing may be inferred from
   geometry rather than read from the network.
6. **DEFN-R1 §6 cases 1 and 3 stand unchanged.** An untouched source edge becomes one arc; a source edge that is
   already a mandatory edge is already an arc and must not be double-counted.
7. **DEFN-R1 §§4, 5, 7 and 9 stand unchanged.** The complex, the four conventions, the certification rules and the
   independent-oracle bar are unaffected. The oracle must now additionally reconstruct crossing nodes by its own
   construction (§9 measure **AG6**).

---

#### 4. What must actually be built, itemized

This is the real cost of Amendment 14. It is bounded, and every piece has an existing template in the codebase.
**None of it may be invented where a template exists** — `LESSONS.md` 22e.

**4.1 An edge-interior synthetic node kind.** `CutNodeBindings`
(`src/geometry/EmbeddedGraphTopology.h:44-48`) today maps `SourceVertexId → NetworkNodeId` plus a reverse map and a
`combinedNodeExtent`. It must gain a second synthetic-node kind keyed by the crossing's exact identity. **The key
must be semantic, not positional:** the crossing of trace `t` at segment position `p` on source edge `e` is
identified by `(SourceEdgeTopologyKey e, TraceId t, std::size_t p)`. Two traces crossing the same edge at the same
exact parameter is a distinct case and must be rejected with a typed error, not merged — coincident crossings are
a network-level fact A2a′ has no authority to adjudicate.

**4.2 Exact ordering along a promoted edge.** Multiple traces may cross one source edge. The promoted edge becomes
`n + 1` arcs for `n` crossings, and they must be emitted in order along the edge. **Freeze the orientation
convention**: order by the `FieldBoundaryPoint` parameter measured along the canonical
`SourceEdgeTopologyKey::first() → second()` direction, compared exactly. State the convention in the CB report with
its derivation; do not infer it from a passing witness.

**4.3 Trace-arc subdivision at crossings.** `build_arcs` builds each trace's `TraceCut` set exclusively from
`network.events()` (`:357-378`). It must additionally admit crossing cuts, at the segment position of the crossing,
bound to the §4.1 synthetic node. The existing `cuts.emplace(position, node)` structure already expresses this;
what changes is the source of the entries, and the conflict check (`inserted.first->second != event.node`) must be
extended to cover an event and a crossing claiming the same position.

**4.4 The degree-four edge-locus rotation — the one genuine gap.** At an edge-locus node,
`build_rotation_system` (`:833-935`) handles exactly two arc kinds: `Mandatory`, gated by
`mandatoryRayCount == 2 && outgoing.size() == 3`, and everything else, which is **required** to be a `Trace`
(`if (!arc.trace.has_value()) → RotationSystemInconsistent`). **A `Cut` arc incident to an edge-locus node is an
unhandled shape today**, and a crossing node is exactly that: two collinear `Cut` rays plus two `Trace` rays,
degree four.

The template is already there and is the correct one. The mandatory branch uses a four-sector cyclic model around
the canonical edge direction: `key.primary = towardSecond ? 0 : 2` for the two collinear rays, with trace rays
placed in the complementary odd sectors by the `sideRank` of the source face they enter (`:846-855`). The extension
is to admit `Cut` rays into the collinear slots on the same rule, by the same
`mandatory_ray_points_to_second_endpoint` logic (`EmbeddedGraphTopology.cpp:651`, called at `:897`) generalized to a
cut arc's endpoints. **Generalize that function; do not write a second one.**

Note also `LESSONS.md` 53: the existing degree-three edge-locus rotation was written for a trace ending inside a
mandatory edge and *has never once executed*. Extending unexecuted code is not a reason to rewrite it, but it **is**
a reason to require an identity that executes both the degree-three and the degree-four shape (§7.4).

**4.5 The proposal layer must stop excluding trace-crossed edges.** Two places, both in
`src/geometry/SurfaceCutGraph.cpp:324-326`: `barriers` is built as `mandatory ∪ traceCrossed ∪ cuts`, and proposed
edges are filtered by `if (mandatory.count(edge) || traceCrossed.count(edge)) continue;`. Under Amendment 14 the
filter is simply wrong — it removes exactly the edges that are now admissible, and it is the mechanism by which a
false `NoAdmissibleCutForNonDiscComponent` would be produced.

The `barriers` set is a subtler matter and must be reasoned about, not patched. A trace crossing source edge `e`
does **not** separate `e`'s two incident triangles — the trace passes through both. Treating `e` as a barrier is a
**conservative over-approximation** that over-separates the proposal partition. Because the authoritative verdict
is always the actual-complex certificate (Amendment 13 §3: the barrier partition is a proposal heuristic and
diagnostic provenance only), over-separation costs extra cuts, never correctness. **CB may keep the conservative
`barriers` set, but must state that it is conservative and publish the resulting over-separation count**; it may not
keep the proposal *filter*.

---

#### 5. Cut-set completeness — PROVED

DEFN-R1 §8 split completeness into a provable trace-free case and an unproved trace-crossed case. With Amendment 14
the split disappears.

**5.1 Theorem (cellularity of the saturated graph).** Let `S` be the source surface with triangulation `M` and
1-skeleton `M¹`, and let `N` be the embedded arc set of the `FieldAlignedCurveNetwork`. Then `N ∪ M¹` is a
cellular embedding in `S`.

*Proof.* The complement of `M¹` in `S` is the disjoint union of the open source triangles, each an open disc.
Fix one triangle `T`. The arcs of `N` meeting `T`'s interior are trace sub-arcs. Each such arc has both endpoints
on the already-cut structure of `T`: a crossing point on `∂T` (a carrier edge, by the definition of
`incomingCarrier` / `outgoingCarrier`), a corner of `T` at a singularity port, or a node interior to `T` lying on
another trace sub-arc that itself reaches `∂T`. Cutting an open disc along a finite family of embedded arcs whose
endpoints lie on the boundary or on previously added arcs yields open discs. Hence every complement component of
`N ∪ M¹` is an open disc. ∎

**5.2 The two conditions, stated rather than assumed.** The proof needs (a) every trace sub-arc's endpoints attach
to the boundary or to already-attached structure, and (b) no node of the graph has degree 0. Both are properties
the producer already enforces or can check: crash-on-contact termination gives (a) — every trace ends at a
singularity, a mandatory barrier, or another trace — and `build_rotation_system` already rejects degree 0 outright
(`:737-741`). **AG3 requires both to be verified and published, not assumed.** A trace terminating at an
unattached interior point would leave a slit rather than a subdivision; a slit disc still satisfies
`boundaryWalkCount == 1` and `χ == 1`, so it is admitted, but it must be *observed* if it occurs.

**5.3 Corollary (existence and termination bound).** For any cut set `C ⊆ M¹`, `N ∪ C` can always be extended to a
cellular embedding by promoting further source edges, since promoting all of them yields `N ∪ M¹`, cellular by
§5.1. **A sufficient cut set therefore always exists, and at most `|E(M)|` promotions are ever required.**
DEFN-R1 §8.2's open case is closed.

**5.4 What the theorem does not give, and the error-code split it forces.** §5.3 proves a cut set *exists*. It does
not prove the greedy tree–cotree proposal *finds* one. These are different failures and the current single code
`NoAdmissibleCutForNonDiscComponent` conflates them — which is precisely the `LESSONS.md` 57 defect this
checkpoint just paid eight turns for. Frozen:

- **`NoAdmissibleCutForNonDiscComponent` is retired as a possible outcome.** Under Amendment 14 it can only fire
  when every source edge of a non-disc component is already a graph arc, and §5.1 shows that configuration is
  cellular. If it fires, the producer's own admissibility classification disagrees with the theorem — a **defect**,
  and it must be reported as one under a distinct code, not as a definition gap.
- **`CutSearchExhaustedBeforeCellularity` (new, name may be improved but must be equally explicit)** is the honest
  code for "the proposal heuristic made no progress". It carries the component locus and the counts.
- **Saturation is the defined last resort, and it is reported, never silent.** On search exhaustion the producer
  promotes the remaining admissible source edges of the offending component and re-certifies. §5.1 guarantees this
  succeeds. It **must** publish `saturationUsed=true` with the component locus and the number of edges promoted.
  A2a′ does not assign a disposition — A8 does — so this is a published fact, not a self-declared degradation.
- **Saturation firing on any of the three witnesses is a red flag, not an outcome.** AG4 predicts it never fires;
  if it does, the proposal heuristic is inadequate and that is a finding to report, not to absorb.

**5.5 DEFN-R1 §10's contingency loses its trigger.** Option B — decoupling A2a′ from the accepted path — was
retained with exactly one trigger: "if §8.2 goes live — the sphere proves non-cellular and no admissible cut set
exists". §5.3 proves the second clause can never hold. **Option B is therefore withdrawn**, and the accepted path
stays wired to A2a′. This is a strengthening: the accepted 355 keeps its detector, which is what caught `PR8-R043`
in the first place. Nothing else in DEFN-R1 §10 changes; Option A remains the plan and is now unconditional.

---

#### 6. Prohibited — things that will look like solutions

- **Introducing any tolerance** into crossing detection, interiority, or ordering along an edge. Every quantity in
  this path is published exactly by the network. An epsilon here is a design defect, not a tuning problem.
- **Inferring a crossing from geometry** rather than reading it from `segments[i].entryPoint` /
  `edgeTransitExit` / `terminalPoint`. A recomputed intersection is a second authority for a datum the network
  already owns — `RP-01`.
- **Publishing a crossing node back into `FieldAlignedCurveNetwork`**, or altering any trace's segments, events, or
  digests. Amendment 12 stands.
- **Writing a second rotation-ordering routine** for degree four instead of generalizing the existing edge-locus
  four-sector model. A second implementation is how this checkpoint arrived here.
- **Merging two coincident crossings** on one edge instead of rejecting them with a typed error.
- **Keeping `NoAdmissibleCutForNonDiscComponent` as a live outcome** with its current meaning, or letting
  saturation fire silently.
- **Relaxing `proves_cellularity()`**, mixing any barrier-partition quantity into a certificate, or changing the
  global certificate to the proxy's `10/11/2`. DEFN-R1 §7 and AC9 stand in full.
- **Treating Amendment 14 as an explanation of the prescribed sphere's failure.** The sphere fails with zero cuts,
  upstream of every line of this. Conflating them would be exactly the mistake §1 exists to prevent.

---

#### 7. AF5 — gate membership, decided per identity

The `AF5` hole was that **no `SurfaceCutGraph.*` identity appeared in the accepted 355, in candidate 357, or in
candidate 358** — CP4c-2 would have accepted a new pipeline stage while requiring none of that stage's own
witnesses. This section closes it. "It was never added" is not a rationale, and neither is "it passes today".

##### 7.1 The four existing A2a′ identities

| identity | contract it holds | decision | rationale |
|---|---|---|---|
| `SurfaceCutGraph.AlreadyCellularNetworkPublishesEmptyCertifiedCutSet` | **idempotence** — an already-cellular network receives zero cuts, and the certificate carries `complex = ActualEmbeddedGraph` with one face and one boundary walk | **GATING** | It is CP4c-2's most basic contract and the only identity asserting the complex *label* Amendment 13 §3 requires. Its witness is `make_square_mesh` — planar, 4 vertices, 2 faces, no interior vertex — so its zero-transport atlas lift is trivially integral and it carries none of the risk in §7.2. |
| `SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration` | **representation-independent identity** under source face/edge reordering | **GATING** | It is the **only** falsifier of live measure `AD3`, which currently defends hashing the raw `face.orbit` index into a *semantic* digest with a comment rather than a test. `RP-05` is a stable regression pattern with two prior events; leaving its guard ungated is not acceptable. Enters the gate red until `AF3`/`AF4` give it a viable witness. |
| `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTwoRingWitness` | **semantic/provenance separation at the A2a′ boundary** | **GATING** | This is what measure `AD5` was for: check the split where it lives, not two stages downstream at ordinal 310. Green in R7-2. |
| `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTorusWitness` | the same contract on a **closed genus-1** witness | **GATING** | `PR8-R044` is runtime-proved on one witness only. A closed-surface witness is not redundant with a disc. Enters the gate red until `AF3` rebuilds it on the production `torus.rawfield` authority. |

**Two of the four enter the gate red. That is correct.** A required-green selector states what must be true for the
checkpoint to close; it is not a record of what happens to pass today. `gate_execution_authorized` remains `false`,
so nothing is executed on this basis yet.

##### 7.2 Candidate 357 — superseded

357 = accepted 355 + `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath` +
`GlobalTopologyPlan.ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation`. Both identities are correct, both
bind the torus through the production entry path, and both are **retained**. 357 is superseded only because it is
incomplete, not because anything in it is wrong. Its 357 bytes are a byte-exact prefix of the new gate.

##### 7.3 Candidate 358 — withdrawn

358's sole addition is `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses`, which binds the
torus **and** `cp4c_mechanical_fixture()`. `build_cp4c_production_fixture` throws when the pipeline did not retain
atlas/network/cut-graph/plan, and the mechanical witness has no atlas — it stops in A1 at `IncompleteCycleBasis`
and is explicitly owned by CP4c-3 / C2. **A gate may not bind a witness its own checkpoint declares out of scope.**

358 is withdrawn as a gate candidate. Its file is retained as historical authority and must not be deleted.

**Criterion C3 is not withdrawn with it.** Rotation-system / face-walk agreement is a real CP4c-2 criterion and has
now been deferred six times. §7.4 splits it so the in-scope half enters the gate and the out-of-scope half moves to
the checkpoint that owns it.

##### 7.4 New identities that must be created and appended

These do not exist yet, so they are not in the frozen selector below. **AG7 makes their append mandatory and
named**, rather than leaving them to be silently omitted the way the four in §7.1 were.

| identity to create | contract | owner |
|---|---|---|
| `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnTorusProducedWitness` | criterion **C3**, torus half only — the mechanical half moves to CP4c-3 / C2 | CB6 |
| `SurfaceCutGraph.TraceCrossedSourceEdgeIsAdmissibleAndSubdividesBothArcs` | Amendment 14 §§3.1–3.3: promotion yields `n+1` cut arcs and `n` crossing nodes, trace arcs split at the same segment positions, network digests unchanged | CB7 |
| `SurfaceCutGraph.CutCrossingNodeRotationIsDerivedAtDegreeFour` | §4.4: the four-sector edge-locus rotation admits `Cut` rays; **must execute the degree-three shape too**, which `LESSONS.md` 53 records has never run | CB7 |
| `SurfaceCutGraph.CutSetSaturationProvesCellularityWhenSearchIsExhausted` | §5.4: saturation terminates in cellularity and publishes `saturationUsed` with locus and count | CB7 |

The resulting gate is **365**. Its bytes are frozen by the turn that creates the identities, under AG7.

##### 7.5 The frozen CP4c-2 gate — selector 361

Created this turn as `.agents/Directional/Architecture_M3_CP4c2_Required_Green_Selector_361.txt`. It is candidate
357 with the four §7.1 identities appended in the order listed.

| authority | source file | derivation | SHA-256 |
|---|---|---|---|
| accepted 355 prefix | `Architecture_M3_CP4c2_Required_Green_Selector_361.txt` | `head -n 355 <file> \| sha256sum` | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| candidate 357 prefix | `Architecture_M3_CP4c2_Required_Green_Selector_361.txt` | `head -n 357 <file> \| sha256sum` | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| **CP4c-2 gate 361** | `Architecture_M3_CP4c2_Required_Green_Selector_361.txt` | whole file: `sha256sum <file>` | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` |

Verified at authoring, per `AE4` and `AE5`: every value is exactly 64 lowercase hex; each was **computed from the
committed bytes**, not transcribed; the 355-prefix hash equals the accepted authority in `ORIENTATION.md` §3 and the
357-prefix hash equals the previously frozen candidate 357, so **prefix comparability of `first_red_ordinal` across
the whole CP4c arc is preserved**. All 361 lines are unique, and each of the four appended identities resolves to
exactly one `TEST(...)` definition in `tests/FieldAlignedCurveNetworkTests.cpp`.

`selected_gate` remains **NONE** and `gate_execution_authorized` remains **false**. Freezing a gate's bytes is not
selecting it; selection happens at a TB with an explicit authorization.

---

#### 8. Falsifiable predictions

1. Every source edge in the torus is admissible under Amendment 14 — the torus has zero traces, so §4.1–§4.4 add
   **no** crossing nodes there, and the torus's `V/E/F = 72/76/4`, `χ = 0` is **unchanged** by this amendment.
2. The two-ring's actual embedded graph `9 / 11 / 3`, `χ = 1` is likewise unchanged; it has three traces but no
   promoted trace-crossed cut, because it is already cellular and receives zero cuts.
3. Amendment 14 changes no accepted identity's result. If any ordinal in the accepted 355 moves, the change was not
   confined to the arrangement and must stop.
4. `NoAdmissibleCutForNonDiscComponent` never fires again on any witness, because under §5.3 the configuration it
   reports cannot exist.
5. `CutSetSaturationProvesCellularityWhenSearchIsExhausted`'s `saturationUsed` is **false** on all three witnesses.
   If it is true anywhere, the tree–cotree proposal is inadequate and that is a finding.
6. **The prescribed sphere will require cuts, and at least one will be trace-crossed.** CB6 measured its pre-cut
   graph non-cellular with excess 4 and it carries 24 traces over a mesh with zero mandatory edges, so the cut
   search has no trace-free source edges to prefer. This is the production witness Amendment 14 exists for.
7. **It is nevertheless not yet reachable**, because the sphere's producer fails at `SurfaceCutGraph.cpp:240/243`
   before cut selection. So the degree-four edge-locus rotation is first exercised only by a **constructed**
   witness — the torus promotes cuts but has zero traces, and the two-ring needs none. **AG5 therefore requires a
   purpose-built witness even though the sphere is the eventual real one**; without it the amendment can ship
   unexecuted, which is the `AF5` failure repeating one level down.
8. The excess-4 reading of §1 resolves into per-component records showing roughly four extra boundary circles. If
   the components instead show something else, §1's derived reading was wrong and only the reading — not the
   non-cellularity, and not Amendment 14 — is affected.

Prediction 7 is the load-bearing one. Prediction 3 is the one that must be checked first and hardest.

---

#### 9. Measures **AG0–AG9**

**AG0 — selector and gate authority.** The CP4c-2 required-green gate is **361**, whole-file SHA-256
`61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`, with 355- and 357-prefix hashes as in §7.5.
Candidate 357 is superseded and candidate 358 is withdrawn; **both files are retained** as historical authority and
must not be deleted. Recompute all three 361 values from committed bytes at every preflight; never transcribe.
`selected_gate=NONE`, `gate_execution_authorized=false`, `selected_r2_branch=NONE` remain unchanged.

**AG1 — implement Amendment 14 as one conversion.** §4.1 through §4.5 land **together**. A partial conversion —
crossing nodes without the rotation extension, or the proposal filter removed without the arc subdivision — is the
defect this checkpoint has already corrected twice. Enumerate every touched site in the CB report and state, for
each, that it was converted.

**AG2 — generalize, do not duplicate.** The degree-four edge-locus rotation extends the existing four-sector model
and generalizes `mandatory_ray_points_to_second_endpoint` to cut arcs. A second ordering routine is prohibited.
Report the exact symbol that now owns it and every call site.

**AG3 — publish the theorem's conditions, and the sphere's component structure.** Verify and publish, per witness: that every trace sub-arc's endpoints
attach to the boundary or to already-attached structure, and that no graph node has degree 0. State §5.1's proof
and §4.2's edge-orientation convention as prose plus code, with derivations shown, not asserted. Additionally
publish the prescribed sphere's per-component records behind its `chi=6` excess and check them against §1's derived
excess-4 reading, adopting or refuting it explicitly.

**AG4 — the error-code split.** Replace `NoAdmissibleCutForNonDiscComponent`'s meaning per §5.4: add
`CutSearchExhaustedBeforeCellularity` with component locus and counts, implement saturation as the defined last
resort, and publish `saturationUsed`, its locus, and the promoted-edge count on every run. Saturation may never be
silent. **Verified in this review: `NoAdmissibleCutForNonDiscComponent` is consumed by no test in the repository**
— its only occurrences are the raise site (`SurfaceCutGraph.cpp:326`), the name function (`:339`) and the enum
declaration (`SurfaceCutGraph.h:86`) — so no accepted identity depends on it and the enum value may be repurposed
or retired freely. Re-verify before editing rather than trusting this line.

**AG5 — a witness that actually exercises the crossing.** Predictions 6-7: the prescribed sphere is the eventual
real witness but is unreachable behind its producer failure, and no *reachable* committed witness promotes a
trace-crossed edge. Construct one — a small closed or bounded fixture with a trace crossing a source edge that a
tree–cotree cut must promote — and assert its precondition **at runtime inside the fixture**, in the CP3a style
`LESSONS.md` §2 requires. Without this, Amendment 14 ships unexecuted.

**AG6 — extend the independent oracle.** DEFN-R1 §9 stands, plus: the oracle reconstructs crossing nodes by its own
construction and publishes, per promoted edge, its crossing count and the resulting arc count, compared term by
term against the producer.

**AG7 — the four new identities enter the gate, by name.** §7.4's four identities are created and **appended** to
selector 361 in the listed order, producing gate **365**. The turn that creates them recomputes and records the
365 whole-file hash and re-verifies the 355 / 357 / 361 prefix hashes. Omitting any of them requires an explicit
written rationale in that turn's report — silence is not a decision.

**AG8 — sequencing, and the one condition under which it collapses.** `M3-CP4c-2-CB6` under **AF0–AF4** remains the
exact next turn and is **not** widened by this document. Reason: AF0 makes the sphere's collapsed error readable and
AF1 may change what is needed, and building Amendment 14 on an unreadable failure is how R2 went wrong. AG1–AG6
belong to **`M3-CP4c-2-CB7`**. **Single merge condition:** if AF0's printed code localizes the sphere's
`RotationSystemInconsistent` to `build_rotation_system`'s edge-locus branch (`EmbeddedGraphTopology.cpp:833-935`),
then it and §4.4 are the same code and CB6 may absorb AG2 — and only AG2. Any other locus keeps the split.

**AG9 — prohibited.** Everything in §6, plus: changing any byte of selectors 316/346/353/355/357/358; changing
selector 361 other than by the AG7 append; selecting a gate or setting `gate_execution_authorized=true`; executing
any gate, cumulative gate, or benchmark; reverting AA1; executing DEFN-R1 §10 Option B, whose trigger §5.5
withdraws; treating Amendment 14 as an account of the sphere's failure; and compiling without GMP/GMPXX per
`GMP_COMPILE_POLICY.md`.

---

#### 10. Stop / successor

The exact next turn is **`M3-CP4c-2-CB6`**, Code + Build, runtime-free, under **AF0–AF4** with the **AF9**
prohibitions — unchanged by this document except for AG8's single merge condition. Its successor TB carries
**AF6**, **AF7** and **AF8**. `M3-CP4c-2-CB7` then implements Amendment 14 under **AG1–AG6**, and the turn that
creates §7.4's identities carries **AG7**.

CP4c-2's required-green gate is **selector 361**, frozen. `selected_r2_branch` remains **NONE**, `selected_gate`
remains **NONE**, `gate_execution_authorized` remains **false**. CP4c-2 is open and runtime-unaccepted; CP4c-3
remains blocked.

---

## Part IV — M3-CP4c-3 DEFN

*Source document: `Architecture_M3_CP4c3_DEFN_Frozen_Definitions.md`, consolidated verbatim.*

### M3-CP4c-3 DEFN — Frozen Definitions, Review and Plan

#### 0. Turn type and verdict

`M3-CP4c-3-DEFN` is **COMPLETE / DEFINITION + REVIEW/PLAN, COMBINED**.

No Directional runtime, build, compile, package, benchmark, product, test or fixture change was made or is
authorized. One **selector authority file was created** — this turn type's proper output — and no existing selector
byte was modified.

**Cadence change, by user authorization (2026-08-30):** *"combine DEFN step with REVIEW/PLAN step going forward when
DEFN is the next step in the chain."* From this turn on, a `DEFN` turn **is** the review-and-plan turn for its
checkpoint: it freezes definitions, adjudicates inherited candidates, decides gate membership, and issues the
successor's measures in one turn. A separate `REVIEW/PLAN` turn is no longer scheduled ahead of a `DEFN`. The
existing `CB → TB → green? → close / red → REVIEW+PLAN → CB` cadence is otherwise unchanged, and this collapses only
the `REVIEW+PLAN → DEFN` edge. Recorded additively in the durable turn-workflow sections of `TODO.md` and
`Future_Chat_Session_Handoff.md`.

**Four decisions.**

1. **`IncompleteCycleBasis` is a seven-way collapse** (§3), and no evidence has ever identified which of its seven
   conditions the mechanical witness hits. That is `LESSONS.md` 57 recurring in A1, and the checkpoint must
   instrument before it designs.
2. **The prescribed sphere is IN CP4c-3's gate** (§4), after two checkpoints outside one.
3. **CP4c-3 runs in two phases** (§5) with one frozen gate, **selector 367** (§6), extended by append.
4. Measures **AK0–AK9** are issued for `M3-CP4c-3-CB1`.

Amendments 12, 13 and 14 are **unchanged and remain binding**. Accepted selector 365 is unchanged.

---

#### 1. What CP4c-3 owns

**Parent responsibility** (`ROADMAP.md` §1): the closed-surface missing field-transport adjacency in A1, then the
mechanical witness — criterion **C2**, `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`.

**Inherited from CP4c-2** by R10-REV measure AJ9:

| record | substance |
|---|---|
| `M3-CP4c2-TB-X2-CAND-04` | the prescribed sphere: (a) producer `RotationSystemInconsistent` at source face `25-27-28`, `producerCutEdgeCount=0`, **before** cut selection; (b) independently, a non-cellular pre-cut graph `V/E/F = 18/30/18`, `χ=6` vs `sourceChi=2` |
| `M3-CP4c2-TB-X2-R10-CAND-01` | Amendment 14's **ordinary** trace-crossed proposal path is structurally unreachable; only saturation promotes such an edge |
| `M3-CP4c2-TB-X2-R8-CAND-02` | zero-node / zero-arc closed-surface cut-graph behaviour is undefined |

**Not CP4c-3's:** the torus post-A2b `tracing` failure (downstream of A2b, tracked separately), and anything from
A3 onward.

---

#### 2. Review of the inherited items

##### 2.1 `R10-CAND-01` — cause established, corrective is narrow and heuristic-only

R10-REV localized this fully and the mechanism is in the committed loop:

```cpp
barriers   = mandatory ∪ traceCrossed ∪ cuts;
components = proposal_components(topology, barriers);
proposed   = proposal_tree_cotree_cut_edges(topology, component, barriers);
for (edge : proposed) { if (mandatory.count(edge)) continue;  cuts.insert(edge); }
```

DEFN-R2 §4.5's **filter** was correctly removed — only `mandatory` is skipped. The **barrier set** still contains
`traceCrossed`, so a trace-crossed edge *bounds* a proposal component instead of lying inside one, and a
tree–cotree generator search draws from a component's interior edges. The ordinary path therefore has no
trace-crossed edge available to propose, and saturation is the only route.

**This is a proposal-heuristic defect, not a certification defect.** Amendment 13 §3 already denies the
source-edge-barrier partition any certification authority; the authoritative verdict is always the actual-embedded-graph
certificate, which R10 proved green. So the corrective touches the heuristic only and **does not reopen
Amendment 14**. Frozen corrective: model a trace crossing as a **per-face chord**, matching the fragment machinery
A2b already uses, so a trace-crossed edge is interior to its component. Owned by **AK4**.

##### 2.2 `R8-CAND-02` — decided here rather than deferred a third time

Question: what should A2a′ do when the network is empty (zero nodes, zero arcs) on a closed surface?

**Decision: reject with a typed error naming the empty network.** Rationale: A2a′'s contract is to *add cuts that
make an existing network's complement cellular*. An empty network has no complement structure to complete — cutting
"from scratch" would make A2a′ the producer of the entire embedded graph, which is A2a's single-writer authority
(`ORIENTATION.md` §1). Silently succeeding would also mean a witness with no field-aligned content could produce a
"certified" plan, which is the vacuous-green shape `LESSONS.md` 64r warns about. A typed rejection keeps
single-writer authority intact and fails closed with a locus, per the architecture's own commitment.

The new code must be **additive** — a new `SurfaceCutGraphErrorCode` value, appended, with no renumbering of
existing values, since accepted identities consume them. Owned by **AK5**.

##### 2.3 `CAND-04` — the sphere's two problems, and why (a) comes first

(a) and (b) are independent and (a) blocks observation of (b) through the producer. Until the producer reaches cut
selection, the sphere's cut set cannot be examined at all. So (a) is sequenced first, and it is the same shape as
the A1 problem in §3 — a typed error whose exact origin site has never been printed, at a finer grain than
"`RotationSystemInconsistent`, one of nine sites in `EmbeddedGraphTopology.cpp`".

---

#### 3. The finding — `IncompleteCycleBasis` is a seven-way collapse, and nobody has printed which one

The mechanical witness has been out of scope for the entire CP4c arc, and **no diagnostic has ever been run on it**.
`ORIENTATION.md` §4 records only "no atlas — stops in **A1** at `IncompleteCycleBasis`". Read at source, that code
is not one condition:

| site in `src/authority/FieldTransportAtlas.cpp` | condition | locus published |
|---|---|---|
| `:1597` | `PCFaceTangentBundle::init(local->mesh)` threw | region only |
| `:1613` | `cycles.rows()`, `cycleCurvatures.size()` or `cycles.cols()` disagrees with `interiorVertices + boundaryLoops + 2·genus` | region only |
| `:1673` | a cycle coefficient is neither ≈0 nor ≈±1, or a column index is out of range | region only |
| **`:1682`** | **no `FieldTransportAdjacency` exists for a cycle's edge** | region + **edge** |
| `:1688` | a local edge has a negative incident face | region + edge |
| `:1700` | `order_cycle_steps` could not order the directed cycle | region only |
| `:1751` | per-kind cycle partition counts disagree with expected local/boundary/handle counts | region only |
| `:1818` | boundary-cycle count ≠ `local->mesh.boundaryLoops.size()` | region only |

**Seven distinct mechanisms, one name, and five of them publish nothing but a region id.** Site `:1682` is
literally "missing field-transport adjacency" — the phrase `ROADMAP.md` uses for CP4c-3's parent responsibility — so
the roadmap's framing points at one specific site among seven that has never been confirmed.

This is `LESSONS.md` **57** recurring in A1: *a `default:`-shaped collapse assigns a name that will be believed*.
CP4c-2 paid **eight turns** for exactly this at `topology_error`, and the fix that ended it — AF0's additive
`originatingTopologyError` provenance field — is a directly reusable template. **CP4c-3 must not design a fix for
the mechanical witness before the discriminator is printed.** That is **AK1**, and it is the first measure for the
same reason AF1 was first at CB6.

**A second, related gap:** these checks all read `local->mesh`, built by `make_local_region_mesh`
(`:850-895`) from a region's faces plus **all** their vertices. Whether a region's local mesh is a manifold disc, or
pinches at a vertex where several feature curves meet — common in mechanical parts — determines
`isBoundaryVertex`, `boundaryLoops` and hence the expected counts at `:1613`, `:1751` and `:1818`. **AK2** requires
the local-region-mesh shape published alongside the failing site, because the site alone will not explain the count.

**No mechanism is promoted here.** The candidate readings above are hypotheses; AK1/AK2 exist so the next turn
reports a measurement rather than adopting one. This is the R2 discipline, and the last three checkpoints have all
been shortened by honouring it.

---

#### 4. Scope decision — the prescribed sphere IS in CP4c-3's gate

R10-REV measure AJ2 required this decided explicitly and in writing. **Decision: the sphere is gated.**

**Why.** It has now sat outside two consecutive frozen gates. `LESSONS.md` 64w and the `AF5` finding record that a
witness outside every gate is how a defect survives indefinitely — the sphere's own eight-turn misdiagnosis is the
project's proof of that. A third silent pass would make the pattern a habit. It is also the only remaining witness
that cannot reach A2b at all, and A2b's region authority is what M4 builds on: deferring it pushes an unknown of
unknown size into the next milestone. And its problem (b) is **directly coupled** to `R10-CAND-01`, which CP4c-3
already owns — a sphere that needs trace-crossed cuts is precisely the production witness the ordinary proposal path
must be able to serve.

**Scope boundary this does not cross.** Adding the sphere as a gated **witness** is not reallocating a **criterion**:
`ROADMAP.md` §1 allocates C1/C3/C6 to CP4c-2 and C2 to CP4c-3, and that allocation is untouched. Which witnesses a
checkpoint's identities bind is a DEFN decision, and `ROADMAP.md` §1 states the successor selector is not frozen
until the definition turn. The sphere enters through §5's phase 2, gated by a new identity named in §6.2 — not by
widening C2.

---

#### 5. Phase structure

CP4c-3 has two product problems in two different stages, plus two carried defects. One undifferentiated CB would
repeat the partial-conversion failure this project has now corrected three times, so the checkpoint runs in two
phases against **one** frozen gate. Phase 1 is diagnostic and non-mutating of product semantics; phase 2 fixes.

**Phase 1 — make both failures legible (`M3-CP4c-3-CB1`, measures AK1–AK3).** Instrument A1's
`IncompleteCycleBasis` collapse and the sphere's `RotationSystemInconsistent` at site granularity, publish the
local-region-mesh shape, and run the result through a TB. **No product fix.** Phase 1 exists because both problems
are currently named by a code that does not identify their mechanism, and because CP4c-2's own record shows what
designing across that gap costs.

**Phase 2 — fix, on measured causes (`M3-CP4c-3-CB2+`, measures AK4–AK6).** The mechanical witness's A1 defect, the
sphere's A2a′ defect, `R10-CAND-01`'s proposal-heuristic correction and `R8-CAND-02`'s typed rejection. Ordering
within phase 2 is a phase-1-review decision, not fixed here, because the measured causes may share a locus — as the
torus and sphere did.

---

#### 6. The gate

##### 6.1 Frozen now — selector 367

Created as `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_367.txt`: accepted **365** plus the
two identities that exist today and that CP4c-3 owns by prior commitment.

| ordinal | identity | why gated |
|---|---|---|
| 366 | `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` | criterion **C2**, CP4c-3's parent responsibility |
| 367 | `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` | criterion **C3**'s full form, binding torus **and** mechanical. DEFN-R2 §7.3 split C3 and committed the mechanical half to CP4c-3; this honours that commitment. The torus-only variant at ordinal 362 stays in the accepted prefix and is not removed. |

| authority | source file | derivation | SHA-256 |
|---|---|---|---|
| accepted 355 prefix | `…_Selector_367.txt` | `head -n 355 \| sha256sum` | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| 357 prefix | `…_Selector_367.txt` | `head -n 357 \| sha256sum` | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| 361 prefix | `…_Selector_367.txt` | `head -n 361 \| sha256sum` | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` |
| **accepted 365 prefix** | `…_Selector_367.txt` | `head -n 365 \| sha256sum` | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **CP4c-3 gate 367** | `…_Selector_367.txt` | whole file: `sha256sum` | `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf` |

Verified at authoring per `AE4`/`AE5`: every value computed from the created bytes, each exactly 64 lowercase hex;
all 367 lines unique; each appended identity resolves to exactly one `TEST(...)`; and **all four earlier prefixes
reproduce their frozen hashes**, so `first_red_ordinal` stays comparable across the entire CP4c arc. Both appended
identities are **red today** — the mechanical fixture throws — and that is correct: a required-green selector states
what must hold for the checkpoint to close, not what passes today.

`selected_gate=NONE`; `gate_execution_authorized=false`. Freezing bytes is not selecting.

##### 6.2 To be appended — named now so they cannot be silently omitted

These identities do not exist yet, so they are not in the frozen file. **AK7** makes their append mandatory and
named, producing gate **370**.

| identity to create | contract | phase |
|---|---|---|
| `GlobalTopologyPlan.PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath` | §4's decision: the sphere reaches A2b through the production path and publishes disc-proved regions | 2 |
| `SurfaceCutGraph.OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation` | `R10-CAND-01`: the ordinary tree–cotree path selects a trace-crossed edge with `saturationUsed=false`; the AG5 witness is retained as the positive saturation case | 2 |
| `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` | `R8-CAND-02`: §2.2's decision, with the new appended error code and a locus | 2 |

The turn that creates them recomputes and records the 370 whole-file hash and re-verifies the 355 / 357 / 361 /
365 / 367 prefixes. Omitting any requires an explicit written rationale in that turn's report — silence is not a
decision (`LESSONS.md` 64w).

---

#### 7. Prohibited

- **Designing a fix for the mechanical witness or the sphere before AK1/AK2 print the site.** Both are currently
  named by a collapsed code. CP4c-2 spent eight turns on exactly that mistake.
- **Renumbering or removing any existing `FieldAtlasBuildErrorCode` or `SurfaceCutGraphErrorCode` value**, or
  changing any existing error mapping. New provenance and new codes are **appended and additive** only — accepted
  identities consume the current values.
- **Reopening Amendments 12, 13 or 14**, or relaxing `proves_cellularity()`, the fragment-count invariant,
  `UncutFaceComponentOrbitSeedNotUnique`, or the actual-embedded-graph complex.
- **Changing accepted selector 365's bytes**, or any byte of 357 / 358 / 361, or 367 other than by AK7's append.
- **Treating `R10-CAND-01`'s corrective as a certification change.** It is a proposal-heuristic change; the
  certificate is untouched.
- **Introducing any tolerance** into a topological decision, or inferring a quantity the producers already publish
  exactly.
- Removing CP4c-2's diagnostic surface — `originatingTopologyError`, the AI2 fragment/orbit publication, the
  actual-embedded-graph oracle, the repaired D2 harness. They belong to the product now.
- A `DEFN` turn compiling, packaging, executing runtime, running a gate, or benchmarking.

---

#### 8. Falsifiable predictions

1. The mechanical witness's `IncompleteCycleBasis` resolves to **one** of §3's eight sites, and it is **not**
   `:1597` (a `PCFaceTangentBundle::init` throw), because a throw would more likely have surfaced as a crash in the
   many turns this fixture has been loaded.
2. If it is `:1613`, `:1751` or `:1818`, the local-region-mesh shape published by AK2 will show a region whose
   boundary is not a disjoint union of simple loops — the count checks all derive from `boundaryLoops` and
   `isBoundaryVertex`.
3. The sphere's `RotationSystemInconsistent` resolves to one of the nine `sourceFace`-carrying sites in
   `EmbeddedGraphTopology.cpp` and involves source face `25-27-28`.
4. Fixing the sphere's producer failure does **not** make it cellular: its pre-cut `χ=6` against `sourceChi=2` is an
   independent measurement, so it will still need cuts, and they will be trace-crossed.
5. `R10-CAND-01`'s corrective changes **no** accepted identity's result, because the proposal heuristic has no
   certification authority. If any of ordinals 1–365 moves, the change was not confined to the heuristic and must
   stop.
6. The torus's accepted numbers are unchanged by everything in this checkpoint: `cutEdgeCount=28`,
   `torusRegionCount=4`, actual graph `V/E/F = 72/76/4`.

Prediction 5 is the one to check first and hardest. Prediction 1 is the one most likely to be wrong.

---

#### 9. Measures **AK0–AK9**

The next turn is **`M3-CP4c-3-CB1`**, a phase-1 Code + Build that instruments and does not fix.

**AK0 — preconditions and frozen authority.** Accepted runtime predecessor is CP4c-2 at **365/365**, source
`57444781af7bdc460e38cc68930a9a8c8199eeea`, package `9736088354`. CP4c-3's gate is **367**, whole-file
`ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf`; recompute it and all four prefixes from
committed bytes at authoring and preflight, validate each as exactly 64 lowercase hex, and never transcribe. No
existing selector byte may change. Compile under `GMP_COMPILE_POLICY.md` with GMP/GMPXX, `runtimeExecution=false`.
`selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.

**AK1 — print the A1 discriminator. Additive only.** Add an optional provenance field to `FieldAtlasBuildError`
identifying **which** of §3's conditions fired — an enumerated reason, not a line number (`LESSONS.md` 62's stale
`419/437/474` labels are the counter-example). Populate it at all eight sites. Print it wherever
`field_atlas_build_error_code_name` is printed today. **Prohibited:** changing which condition maps to
`IncompleteCycleBasis`, renumbering the enum, or adding a new `FieldAtlasBuildErrorCode` value in this CB. This is
AF0's template applied to A1; follow it exactly.

**AK2 — publish the local-region-mesh shape with the failure.** For the failing region, publish `V`, `E`, `F`, the
computed `eulerCharacteristic`, `boundaryLoopCount`, `genus`, `interiorLocalVertices.size()`, the resulting
`expectedCycleCount`, and the actual `bundle.cycles.rows()` / `cycleCurvatures.size()` / `innerAdjacencies.size()`.
The site alone will not explain a count mismatch; the counts will. Publish for **every** region of the mechanical
witness, not only the first failing one — a per-region row set, in the AG3 idiom.

**AK3 — print the sphere's site at nine-way granularity.** AF0 gave the sphere
`originatingTopologyError=RotationSystemInconsistent`; that is one code across nine `sourceFace`-carrying sites in
`EmbeddedGraphTopology.cpp`. Add the same enumerated-reason provenance so the site is identified, and publish it
through the existing frozen non-gating sphere diagnostic. **No product fix for the sphere in phase 1.**

**AK4 — `R10-CAND-01`, phase 2.** Model a trace crossing as a **per-face chord** in the proposal heuristic, matching
the fragment machinery, so a trace-crossed edge is interior to its component and reachable by the ordinary
tree–cotree search. Heuristic only: the certificate, the complex and Amendment 14 are untouched. Publish, per
witness, whether the ordinary path or saturation selected each trace-crossed edge. Keep the AG5 witness as the
positive saturation case and add the §6.2 identity for the ordinary case.

**AK5 — `R8-CAND-02`, phase 2.** Implement §2.2's decision: an empty network on a closed surface is rejected with a
**new, appended** typed error naming the empty network, with a locus. Do not renumber existing values. Add the
§6.2 identity.

**AK6 — the two product fixes, phase 2, on measured causes only.** The mechanical witness's A1 defect and the
sphere's A2a′ defect. Each CB states, in its report, the measured site from AK1/AK3 that it is fixing. **A fix whose
report cannot name the measured cause is not authorized.**

**AK7 — the three new identities enter the gate, by name.** §6.2's identities are created and **appended** to
selector 367 in the listed order, producing gate **370**. That turn recomputes and records the 370 whole-file hash
and re-verifies the 355 / 357 / 361 / 365 / 367 prefixes. Omission requires a written rationale.

**AK8 — enumerations.** Every measure in CP4c-3 that says "every consumer", "every site" or "every region" must
either contain the enumeration, produced by search, or require the implementer to produce and publish it by
**search** rather than by copying this document's tables. §3's eight-site table is a cross-check to compare against
*after* the implementer has produced their own — `LESSONS.md` 59 and 61 exist because a copied enumeration inherits
the author's omissions.

**AK9 — bookkeeping and prohibitions.** §7's prohibitions bind every CP4c-3 turn. Carry
`M3-CP4c2-TB-X2-CAND-04`, `M3-CP4c2-TB-X2-R10-CAND-01` and `M3-CP4c2-TB-X2-R8-CAND-02` as CP4c-3-owned with the
dispositions in §2 and §4. **Stable accounting remains 44 / 14 / 30**, produced-witness debt **5**, authoritative M3
packages **67**. Every TB continues to run the frozen non-gating selector in full or justify skips per identity
(`AF6`).

---

#### 10. Stop / successor

The exact next turn is **`M3-CP4c-3-CB1`**, Code + Build, runtime-free, under **AK0–AK3** with §7's prohibitions.
Its successor is an artifact-only TB that executes gate **367** from ordinal 1 and publishes the AK1–AK3 evidence;
that TB's review then orders phase 2.

CP4c-2 remains **CLOSED / ACCEPTED at 365/365**. CP4c-3 is **open**; its gate is frozen at **367** and unselected.

---

## Part V — M3-CP4c-3 DEFN-R1

*Source document: `Architecture_M3_CP4c3_DEFN_R1_Frozen_Definitions.md`, consolidated verbatim.*

### M3-CP4c-3 DEFN-R1 — Frozen Definitions, Review and Plan

#### Status

**DEFINITION + REVIEW COMPLETE / AL2 SETTLED / OPTION A ADOPTED IN ITS DERIVED-VIEW FORM (A′) /
AMENDMENT 15 DECLARED / MEASURES AM0–AM9 ISSUED**

This turn discharges **AL2** under the standing cadence in which `DEFN` *is* the review-and-plan turn. Definition,
review and planning only: nothing was executed, compiled, packaged, relinked or benchmarked, no gate was selected
or run, and **no product, test, fixture, selector or build-logic byte changed**. The only source read was read.

Measures issued here are **AM0–AM9**. Gate **367** remains frozen and unselected.

---

#### 0. What this turn verified independently

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

#### 1. The question, stated exactly

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

#### 2. Theorem 1 — the defect class is *exactly* `HardFeature` edges interior to a region

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

#### 3. Theorem 2 — cutting along `B(R)` can never disconnect `R`

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

#### 4. The endpoint rule — AL2 item 2, derived

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

#### 5. Arithmetic consistency — AL2 item 3, shown

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

#### 6. Decision — Amendment 15, option **A′**

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

#### 7. What the decision costs — three consequences, each with a required control

A′ is not free, and none of these is visible from the failing line. Each is a **required** part of the change; an
implementation that lands the fix without them converts a loud red into a quiet weakening, which is exactly the
pattern `LESSONS.md` 62 records.

##### 7.1 The `CanonicalBindingMismatch` cross-check must be **replaced**, not deleted

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

##### 7.2 The region's certificate changes kind, from a closed identity to a boundary-corrected one

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

##### 7.3 The quiet one: a prescribed singularity on a barrier arc silently loses its verification

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

##### 7.4 The frozen fallback, with its trigger

If **AM5**'s implementation cannot deliver §7.1–§7.3 within CP4c-3, the fallback is **option D**: retain today's
behaviour but name it precisely with a **new, appended** `IncompleteCycleBasisReason` — "a non-separating barrier
edge remains interior to its region" — replacing the misleading `CycleTransportAdjacencyMissing` for this
condition only. **The trigger is explicit and must be declared in the CB report, not decided silently:** D is taken
if and only if §7.3's binding control cannot be made to fail closed without changing an accepted A1 contract. If D
is taken, **CP4c-3 cannot close on criterion C2**, and the gate expectations must be revisited by a further DEFN
before any TB. D is a stop, not a fix, and must be reported as one.

---

#### 8. Measures **AM0–AM9**

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

#### 9. Falsifiable predictions

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

#### 10. Gate membership and accounting

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

#### 11. Exact next turn

**`M3-CP4c-3-CB2`** — Code + Build under **AM0–AM9**, runtime-free, GMP/GMPXX linked. It implements Amendment 15
(AM2–AM6), carries AL3's sphere instrumentation (AM7), and freezes the **373** gate append (AM8). A red TB after it
routes to `REVIEW + PLAN` as usual.

CP4c-2 remains **CLOSED / ACCEPTED at 365/365**. CP4c-3 is **open**.

---

## Part VI — M3-CP4c-3 DEFN-R2

*Source document: `Architecture_M3_CP4c3_DEFN_R2_Frozen_Definitions.md`, consolidated verbatim.*

### M3-CP4c-3 DEFN-R2 — Frozen Vertex-Star Continuation Definitions

**Turn:** `M3-CP4c-3-DEFN-R2`
**Type:** Definition + Review/Plan only
**Governing plan:** `Architecture_M3_CP4c3_CB8_Independent_Review_Record.md` §7, measures **AX0–AX9**
**Verdict:** **AX1–AX8 DISCHARGED / AMENDMENTS 22 AND 23 DECLARED / VERTEX 30 PROVED EXACTLY AND THE OLD ELECTION
FALSIFIED BY GEOMETRY, NOT ONLY BY CARDINALITY / ONE BOUNDED SUCCESSOR AUTHORIZED UNDER AY0–AY9**

No Directional runtime, compile, link, package, benchmark, product, test, fixture or selector byte was executed or
mutated. Selector **373** remains byte-frozen at
`b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`; **selector 374 still does not exist** and is
authorized only conditionally (AY7). Accepted authority remains **365**. Stable accounting remains
**44 / 14 / 30**, produced-witness debt **5**, semantic M3 packages **73**.

---

#### 0. AX0 — frozen preconditions, restated

Accepted selector 365, frozen selector 373, TB6/package-75 runtime evidence, CB8's architectural stop, and the
deferred ordinal-370 / prescribed-sphere / saturation authority are all carried forward unchanged. Ordinal 370, the
sphere and saturation are **not touched by this turn**. Amendments 17, 18 and 21 are not weakened anywhere below;
Amendments 22 and 23 are additive and are written to *serve* 17 and 18 rather than to soften them.

**Analysis performed:** static reconstruction from the committed fixture
`benchmarks/fixtures/milestone-g/mechanical_feature.obj` using exact rational arithmetic. Every numeric claim marked
**EXACT** below is a rational identity over the committed coordinates — no floating point, no factorization, and no
tolerance is used to establish it. Floating values appear only as *labels* for quantities that are irrational, and
they are never load-bearing.

---

#### 1. AX1 — the datum, its writer, and its lifetime

> **The primitive datum is one exact incoming geometric ray, anchored once at the vertex-arrival event, expressed
> in the arrival face's own chart, and never re-expressed by any candidate.**

Contract (names descriptive, not an implementation mandate):

| field | meaning |
|---|---|
| `sourceVertex` | the vertex being transited |
| `arrivalFace` | the source face the trace was inside when it reached the vertex |
| `arrivalBranch` | the A1 branch label the trace was following **in `arrivalFace`** |
| `arrivalRay` | the exact direction, in `arrivalFace`'s chart, of the ray **from the vertex back along the incoming trace** |
| `arrivalMode` | `FaceInterior` / edge-locus, as today |

**Orientation and sign are fixed here** so no consumer may choose: `arrivalRay` points **away from the vertex,
back along the direction the trace came from**. It is the reversed direction of travel. This convention is chosen
because it makes the seed a ray of the star itself — an object the fan can contain — rather than a velocity that
must be negated by each reader.

**Writer.** A2a branch continuation writes exactly one seed per vertex-arrival event. There is no seed per
candidate, no seed per face, and no seed per branch label.

**Lifetime.** The seed is immutable for the duration of the transit decision and is consumed by exactly one
authority (AX5). It is not re-derived, re-normalized, re-projected, or replaced downstream.

**Diagnostic-only, and explicitly demoted:** every candidate face's own
`FieldBranchBoundaryPairing::direction`, every per-face `representativeDirection`, and the branch label obtained by
applying `signedLift` in a target face. These may be published as audit rows (AX8). **None of them may enter the
decision.** They are what the current code decides on, and that is the defect.

---

#### 2. AX2 — vertex-star geometry and what "straight continuation" means

##### 2.1 The reference semantics

> **Amendment 22 — a curve continues through a source vertex along the *straightest geodesic* of the intrinsic
> vertex star, decided in one arrival-anchored development, and the outcome is one typed certificate.**

Definition, in six steps, stated independently of any numeric kernel:

1. **Fan.** Take the admissible incident-face fan of `sourceVertex`, ordered by source topology, truncated by the
   barrier policy exactly as A1 already truncates it, and terminated by source boundary where present. Barrier and
   boundary truncation are inherited, not redefined.
2. **Anchor.** Place `arrivalFace` first, with `arrivalRay` at developed angle `α`, measured from the fan-first
   radial edge of `arrivalFace`, `α ∈ [0, θ(arrivalFace))`.
3. **Develop.** Unfold each subsequent face sector isometrically about its shared radial edge into one developed
   chart. The developed position of the `k`-th radial ray is the cumulative sum `A_k = Σ_{i<k} θ_i` of the intrinsic
   face angles at the vertex.
4. **Continue.** The **cone angle** is `Θ = Σ_i θ_i` over the fan. The straightest continuation leaves the vertex at
   developed angle `β = α + Θ/2`, taken modulo `Θ` on a closed star. This is the Polthier–Schmies straightest
   geodesic: the intrinsic angle on one side of the continuation equals the intrinsic angle on the other.
5. **Elect.** Apply the **existing, unchanged** exact half-open sector convention to the developed sectors
   `[A_k, A_{k+1})`. The convention is not widened, narrowed, or re-oriented.
6. **Certify.** Return exactly one `VertexTransitOwnerCertificate`, or exactly one typed non-owner state from §3.

##### 2.2 Why straightest geodesic and not "the developed straight line"

This is the load-bearing choice of the turn, and it is what dissolves AX3's problem rather than managing it.

"Developed straight line" means `β = α + π`. On a star with `Θ ≠ 2π` that angle can exceed `Θ` (a **gap**: the
continuation points into no face) or the development can wrap past itself (an **overlap**: two developed sectors
claim it). Those are the two pathologies CB8-REV correctly refused to let a CB guess at.

`β = α + Θ/2` has neither. For any `Θ > 0` and any `α ∈ [0, Θ)`, `β mod Θ ∈ [0, Θ)` — it always lands in exactly one
half-open developed sector, because the sectors partition `[0, Θ)`. **Gap and overlap cannot arise.** The two
definitions coincide exactly when `Θ = 2π`, i.e. at every intrinsically flat vertex, which is the case the pipeline
overwhelmingly meets and the only case in which "straight" is unambiguous anyway.

So the amendment does not *resolve* the non-flat ambiguity by policy; it **chooses a semantics in which the
ambiguity does not exist**, and pays for that with the single, stated commitment that continuation at a cone point
bisects the cone. That commitment is visible, testable and reversible; a seam, an ordering or a tolerance would be
none of those.

##### 2.3 What is *not* redefined

A1 remains the authority on branch identity and edge transport. **`signedLift` maps a branch label; it is not, and
may not be described as, a transport of an arbitrary geometric ray.** The development above uses A0 source geometry
plus A1 fan topology. It does not consult, and may not consult, any per-face cross representative.

---

#### 3. AX3 — the residual typed states

Under §2 the gap and overlap cases are gone. Four states remain, and each is named rather than resolved silently.

| state | condition | disposition |
|---|---|---|
| `VertexTransitOwnerCertificate` | `β mod Θ` lies strictly inside one developed sector | the normal result |
| **boundary ray** | `β mod Θ` equals a developed radial position `A_k` **exactly** | **not a degeneracy.** The existing exact half-open convention already owns this: the ray belongs to the sector where it is `next`. It is recorded in the certificate as `onRadialRay = true` with the ray's identity, because it is the case a later regression must be able to find. |
| `VertexStarTruncatedBeforeContinuation` | the fan is **open** (barrier or source boundary) and `β` falls outside the admissible arc | **typed fail-closed.** The continuation leaves the admissible domain; A2a must terminate the trace or report, exactly as it already does at a barrier. Amendment 16 forbids restoring uniqueness by crossing a barrier, and this state is how that prohibition is reported rather than hidden. |
| `VertexStarDegenerateSector` | some `θ_i` is exactly `0` or exactly `π`, i.e. a degenerate incident triangle at this vertex | **typed fail-closed here, `RegularizableDegeneracy` only at the conditioning stage.** Amendment 20 already rules that value-changing repair of input geometry happens once, at the boundary, and is recorded. A degenerate sector discovered at A2a is an *input* defect surfacing late; A2a reports it with its locus and does not repair it. |

**Prohibited for every one of these:** candidate ordering, nearest-angle selection, a seam placed to break a tie, a
tolerance, and inventing a port or a face that source geometry does not supply (Amendment 21).

---

#### 4. AX4 — the exact kernel, and the honest cost

##### 4.1 The predicate class, named precisely

Electing a sector is deciding, for the cumulative sums `A_k`, the sign of

```
    (α + Θ/2)  −  A_k        =  ½·( Σ_{i≥k} θ_i  −  Σ_{i<k} θ_i )  +  α
```

Each `θ_i` is a face angle at the vertex with

```
    cos θ_i = D_i / √P_i ,    sin θ_i = √Q_i / √P_i ,
    D_i = u·w ,   P_i = (u·u)(w·w) ,   Q_i = P_i − D_i²        — all three EXACT rationals
```

so the decision is the **sign of a signed sum of arccosines of algebraic numbers**. Composing the rotations exactly
places the result in a tower `ℚ(√Q_1, √P_1, …, √Q_k, √P_k)` of degree up to `4^k` in the fan length `k`.

> **Amendment 23 — where an exact decision has no bounded algebraic representation, the architecture must state the
> budget, not hide it.** A topological decision whose exact evaluation grows with an input parameter is admissible
> only if the producer (a) publishes a certified filter that returns the provably-correct answer or defers, (b)
> names an exact fallback that always terminates and is actually implemented, and (c) declares an explicit budget on
> the parameter together with a **typed fail-closed state** for inputs that exceed it. "The filter was
> inconclusive" is never an answer, and a budget that is not published is not a budget — it is an undiscovered
> failure mode. This is the exactness counterpart of Amendment 19: an unbounded computation with no declared limit
> is an unreportable exit wearing a performance costume.

##### 4.2 The chosen route

**Certified filter + specified exact fallback**, of AR2's three families. Concretely:

- **Filter.** Interval arithmetic over the same composition. It resolves every configuration in which `β` is not
  *exactly* on a radial ray, in time linear in the fan length, and it defers otherwise. It is certified in the
  Amendment 18 sense: it returns the provably-correct sector or it defers. It may never return an approximation.
- **Exact fallback.** Sign determination by successive elimination of radicals (repeated isolation-and-squaring),
  which is `O(2^k)` exact rational operations for a fan of length `k` and always terminates. This is the *only*
  path that decides the boundary-ray case of §3, so it is load-bearing, not decorative.
- **Budget.** The producer publishes a fan-length budget and raises a typed
  `VertexStarExactBudgetExceeded` above it. The budget must be **at least 16**, which covers every valence in every
  committed fixture with room to spare, and the constant must appear in the certificate — not in a comment.

The three inadmissible routes are restated so a later turn cannot rediscover them as ideas: plain
`FieldExactRational` hinge rotation (the field is not closed under the construction), floating transport followed by
`from_double_exact` (Amendment 18, and the CB6 defect verbatim), and "filter inconclusive ⇒ reject" (which silently
converts the boundary-ray case into a failure).

##### 4.3 A structural exemption worth stating

The general cost above is the *worst* case, and it is worth recording that the real fixture does not pay it. At the
measured locus every sign test reduced to **rational identities alone** (§5). A producer may therefore short-circuit
on exactly-recognizable rational relations — a right angle is `u·w = 0`; two angles are complementary iff
`D₁D₂ ≥ 0` and `(D₁D₂)² = Q₁Q₂`; supplementary iff `D₁D₂ ≤ 0` and `(D₁D₂)² = Q₁Q₂` — provided each short-circuit is
an exact identity and the general path remains reachable. This is an optimization, never a semantics.

---

#### 5. AX6 — the mechanical proof at vertex 30

All of the following are **EXACT** rational facts computed from the committed
`mechanical_feature.obj`. No factorization and no floating point is used in any of them.

##### 5.1 The star

Vertex 30 has one closed, consistently oriented six-face fan. Anchored at the arrival face and walked in fan order:

| fan step | source row | canonical face | radial ray reached | face angle `θ` |
|---:|---:|---|---:|---|
| 0 | **43** | `(24,30,32)` | 32 | **exactly `π/2`** (`u·w = 0`) |
| 1 | 218 | `(30,32,123)` | 123 | **exactly `π/2`** (`u·w = 0`) |
| 2 | 209 | `(30,119,123)` | 119 | `θ₂₀₉` ≈ 0.500840763396 |
| 3 | **208** | `(30,31,119)` | 31 | `θ₂₀₈` ≈ 1.069955563399 |
| 4 | **41** | `(25,30,31)` | 25 | `θ₄₁` ≈ 0.865430437682 |
| 5 | 40 | `(24,25,30)` | 24 (closes) | `θ₄₀` ≈ 0.705365889113 |

Every `θ_i` satisfies `Q_i > 0`, so every angle is strictly in `(0, π)`: no degenerate sector, `VertexStarDegenerateSector`
does not apply. The vertex is regular, not barrier-absorbed and not barrier-incident, so the fan is **closed** and
`VertexStarTruncatedBeforeContinuation` does not apply.

##### 5.2 The cone angle is exactly `2π` — proved, not observed

CB8-REV recorded a float angle-sum consistent with `2π` and explicitly declined to accept it as proof. It is now
proved, by four rational identities and nothing else:

```
  θ(43)  = π/2                          EXACT:  u·w = 0
  θ(218) = π/2                          EXACT:  u·w = 0
  θ(209) + θ(208) = π/2                 EXACT:  D₂₀₉·D₂₀₈ ≥ 0  and  (D₂₀₉·D₂₀₈)² = Q₂₀₉·Q₂₀₈
  θ(41)  + θ(40)  = π/2                 EXACT:  D₄₁ ·D₄₀  ≥ 0  and  (D₄₁ ·D₄₀ )² = Q₄₁ ·Q₄₀
  ────────────────────────────────────────────────────────────────────────────────────────
  Θ(v30) = 4 · π/2 = 2π                 EXACT
```

The complementarity test is the rational form of `cos(θ₁+θ₂) = 0`. The two relations are **not** an artifact of
looking for them: the same test over all six other pairings of the four non-right angles returns false in every
case, so the decomposition is the fixture's actual structure — a CAD surface whose quads are split into triangle
pairs — and not a coincidence fitted after the fact.

**Consequence:** vertex 30 is intrinsically flat, so Amendment 22's `β = α + Θ/2` coincides exactly with `α + π`
here. The proof does not depend on that coincidence; it is recorded because it means the mechanical witness cannot
distinguish the two semantics, which is a limitation of the witness and the reason AX7 exists.

The star is genuinely **non-coplanar**: the hinges `43|218` and `208|41` have non-parallel face normals, so this is
a folded fan, not a flat patch drawn in 3D.

##### 5.3 The developed chart, and the finding

With the chart anchored at face 43 and ray 24 at angle 0, the developed radial positions are

```
   ray  24 :  0
   ray  32 :  π/2                    EXACT
   ray 123 :  π                      EXACT
   ray 119 :  π + θ₂₀₉
   ray  31 :  3π/2                   EXACT   (because θ₂₀₉ + θ₂₀₈ = π/2)
   ray  25 :  3π/2 + θ₄₁
   ray  24 :  2π                     EXACT   (because θ₄₁ + θ₄₀ = π/2)
```

giving the developed sectors

```
   row  43 = [0,        π/2)      arrival face, excluded by FaceInterior
   row 218 = [π/2,      π)
   row 209 = [π,        π + θ₂₀₉)
   row 208 = [π + θ₂₀₉, 3π/2)
   row  41 = [3π/2,     3π/2 + θ₄₁)
   row  40 = [3π/2 + θ₄₁, 2π)
```

The seed is anchored in face 43, so `α ∈ [0, π/2)` — and `α ≠ 0` because `arrivalMode = FaceInterior` excludes the
radial ray. The continuation therefore lies at

```
   β = α + π  ∈  (π, 3π/2)  =  sector(209) ∪ sector(208)      EXACT
```

because `sector(209) ∪ sector(208) = [π, 3π/2)` is exactly the rational relation `θ₂₀₉ + θ₂₀₈ = π/2` proved above.

**One seed yields one certificate, and the split point is exact:**

- `α < θ₂₀₉` ⇒ owner is **row 209 `(30,119,123)`**;
- `α > θ₂₀₉` ⇒ owner is **row 208 `(30,31,119)`**;
- `α = θ₂₀₉` ⇒ `β` is exactly on radial ray **119**, and the unchanged half-open convention assigns it to the sector
  where that ray is `next` — the boundary-ray case of §3, decided by the exact fallback, never by a tolerance.

##### 5.4 What this falsifies

TB4 and TB6 both published **two** candidates: row 41 `(25,30,31)` and row 208 `(30,31,119)`.

> **Row 41 is not reachable by any continuation from arrival face 43.** Its developed sector is
> `[3π/2, 3π/2 + θ₄₁)`, and `β < 3π/2` for every admissible `α`. This is an EXACT consequence of
> `θ₂₀₉ + θ₂₀₈ = π/2`, which is a rational identity over the committed coordinates.

That is a **stronger** falsification than the cardinality argument the checkpoint has been running on since TB4.
TB4-REV proved that two elections imply two distinct data were tested. This proves *which* of the two elections is
geometrically impossible: not "the election is ill-posed", but "one of the two answers it produced is wrong about
the surface". The current mechanism elected a face that the intrinsic geometry cannot reach, because it asked face
41's own cross representative whether face 41's own wedge would accept it — a question every face can answer yes to.

It also means the corrected producer has a **known expected answer** at the measured locus for the first time in the
checkpoint: row 209 or row 208, split at `α = θ₂₀₉`, never row 41. AX6 is discharged, and the answer was not
overwritten to match the current expectation — it contradicts it.

---

#### 6. AX5 — the owning contract

- **A0** continues to own exact source support, coordinates and topology.
- **A1 `FieldTransportAtlas`** continues to own cross-branch identity and edge transport/lift, and is **not**
  redefined as a ray transport.
- **A2a branch continuation** writes exactly one `VertexStarRaySeed` per vertex-arrival event (AX1).
- **A2a vertex-star transit authority** — a derived, A2a-local single-writer object, not a new pipeline stage —
  consumes A0 geometry, immutable A1 fan topology and that one seed, and writes exactly one
  `VertexTransitOwnerCertificate` or one typed non-owner state from §3.

**Consumers.** `resolve_field_vertex_transit` is the only function that may consume the new authority, and its
result becomes the certificate. Candidate enumeration survives **only** as the set being tested; it writes nothing.
The following move to diagnostic-only and leave the decision path entirely:

```cpp
  incomingDirection = nextPairing->direction;     // the CB7/CB8 defect — removed from the decision
```

together with every per-candidate `representativeDirection` test and every use of `signedLift` as a ray transform.
The exact half-open predicate `direction_in_vertex_sector` is **kept unchanged** and is applied to developed
sectors instead of to per-face representatives — the predicate was never the defect, and TB4-REV's partition proof
remains valid and is now the reason the developed election is single-valued.

---

#### 7. AX7 — the regression identity and its witness

##### 7.1 Why vertex 30 cannot be the only witness

Vertex 30 is intrinsically flat (§5.2), so it cannot distinguish `β = α + Θ/2` from `β = α + π`. It is an excellent
falsifier of the **old** mechanism and a poor discriminator of the **new** semantics.

##### 7.2 The witness to derive

An exact **non-coplanar folded fan** with:

1. exact rational vertex coordinates;
2. a closed fan whose per-face angles are certified by the rational tests of §4.3, so the cone angle is known
   exactly and the expected owner is derivable by hand;
3. **at least one non-coplanar hinge**, so it is a genuine development and not a flat patch;
4. per-face cross representatives deliberately chosen so that **more than one** candidate face would accept its own
   representative — this is the property that makes it falsify `incomingDirection = nextPairing->direction`;
5. a seed placed strictly inside its arrival sector, plus a second instance placed exactly on a radial ray, so the
   boundary-ray case and the exact fallback are both exercised.

The extracted vertex-30 star is the recommended starting geometry for (1)–(3): seven vertices, six faces, exact
coordinates already committed, flatness already proved, non-coplanarity already checked. Property (4) is a
*field* choice, not a mesh choice, and must be constructed and published with the fixture. A second witness with
`Θ ≠ 2π` is required to discriminate the semantics of §2.2, and its expected owner must be derived from
Amendment 22 before the code is written, never read off the implementation.

##### 7.3 Selector governance

Selector **373** stays byte-identical. Ordinal **374** may be appended — exactly one line, nothing above it moving,
respelled or removed — **only after** the witness of §7.2 is shown to **fail** under
`incomingDirection = nextPairing->direction` and to **pass** under the frozen authority. Compiling it is not
sufficient; CB8-REV was right about that and this record does not relax it. The current minimal identity
`ResolvedBranchCorrection.MinimalExactVertexTransitWitnessPublishesKnownFanState` is a channel test: it proves exact
state is published and proves nothing about which datum was tested, so it may be strengthened in place or replaced,
but it may not be admitted as-is.

---

#### 8. AX8 — the audit contract

Frozen fields, in decision order. This is the contract the later projection repair must publish; it deliberately
describes the **new** datum, because publishing richer evidence for the invalid per-cell datum would only make the
wrong decision better documented.

| group | fields |
|---|---|
| **seed** | `sourceVertex`, `arrivalFace`, `arrivalBranch`, exact `arrivalRay`, `arrivalMode`, and the seed's provenance (the trace/event that anchored it) |
| **kernel** | which route decided it — `Filter`, `ExactFallback`, or `RationalShortCircuit` — and, when the exact fallback ran, the fan length and the budget in force |
| **development** | the ordered fan, each face's exact `(D_i, P_i, Q_i)`, the truncation reason where the fan is open, and the exact cone angle or the certified relations that determine it |
| **election** | per developed sector: its identity and the exact sector-membership outcome; then `ownerCardinality`, the elected owner, and `onRadialRay` with the ray's identity when the continuation is exactly on one |
| **failure** | the typed non-owner state from §3 with its locus, and `VertexStarExactBudgetExceeded` with the fan length that exceeded the budget |

`M3-CP4c3-TB6-CAND-01` is closed by publishing **this** contract at the projection boundary
(`RemeshPipeline.cpp::network_failure_locus` plus the `RemeshDiagnostics` DTO), not by publishing today's rows.

**The authoring rule that this turn also owes the record**, because the same loss will otherwise recur at the next
new diagnostic shape: a measure that orders a measurement must name the identity or the projection that will carry
it, and a diagnostic added to a typed error for operational reporting must have its projection extended **in the
same change**. `vertexTransitStates` was built correctly three times and read zero times because three consecutive
measures each ordered rows that nothing was obliged to carry. `LESSONS.md` 75.

---

#### 9. AX9 — successor gate

AX1–AX8 are internally complete and one exact implementation route is feasible (§4.2), with the measured locus
decidable by rational identities alone (§5.2). **One bounded Code + Build successor is authorized**, under a new
measure prefix as AX9 requires.

##### `M3-CP4c-3-CB9` — measures **AY0–AY9**, Code + Build, runtime-free, GMP/GMPXX linked

**AY0 — preconditions.** Selector 373 byte-frozen and recomputed at authoring and preflight; accepted 365
untouched; `selected_gate=NONE`; `gate_execution_authorized=false`; no runtime, no gate, no benchmark.

**AY1 — the seed.** Implement `VertexStarRaySeed` per §1, written once by A2a branch continuation, with the sign and
chart conventions exactly as frozen. One seed per arrival event.

**AY2 — the development and the election.** Implement §2 with the **unchanged** `direction_in_vertex_sector`
predicate applied to developed sectors. Remove `incomingDirection = nextPairing->direction` and every per-candidate
representative from the decision path; retain them as audit rows only.

**AY3 — the kernel.** Implement the certified filter, the exact fallback, and the published budget of §4.2, in that
dependency order. The fallback must be implemented and reachable, not stubbed: it is the only path that decides the
boundary-ray case. Publish the budget constant in the certificate.

**AY4 — typed states.** Implement the four outcomes of §3, each with its locus, and record the diagnostic **before**
any conditional that can skip a state (Amendment 19).

**AY5 — the witness.** Derive and commit the folded-fan fixture of §7.2 with its exact coordinates, its exact
expected owner derived from Amendment 22, its boundary-ray instance, and its field construction. **Prove in the
report that it fails under the old mechanism**, quoting the old and new results side by side.

**AY6 — selector 374.** Append exactly one ordinal only if AY5's falsification is demonstrated. Selector 373 keeps
every byte. If AY5 does not falsify, **do not create selector 374** — report and stop.

**AY7 — the audit contract.** Implement §8's fields on the typed error, **and extend the `RemeshDiagnostics`
projection in the same change** so the rows have a reader. This is the closure of `M3-CP4c3-TB6-CAND-01`.

**AY8 — audit by assumption.** Two predicates, findings listed, each with a site named **outside** the ones this
record names: *"a value reaching a topological decision was re-expressed by its consumer"* and *"an exact
computation has no declared bound on its input size."*

**AY9 — prohibited.** Restoring any floating-point step in the decision chain, including
`from_double_exact` of a transported value (Amendment 18). Treating `signedLift` as a ray transform. Deciding from a
candidate's own representative. Candidate ordering, nearest-angle, seams, or **any** tolerance. Changing the
half-open sector convention, the `FaceInterior` rule, or barrier/boundary truncation. Inventing a port or a face
(Amendment 21). Repairing degenerate input geometry at A2a rather than reporting it (Amendment 20). Publishing an
owner without its certificate. Stubbing the exact fallback, or shipping an unpublished budget. Touching ordinal 370,
the prescribed sphere or saturation. Reopening Amendments 12–23. Changing any selector byte other than the single
authorized ordinal-374 append. Executing Directional runtime, running a gate, or benchmarking in a CB turn.

**Stop rule.** If the exact fallback cannot be implemented within the frozen semantics, CB9 stops and reports, as
CB8 correctly did. A second architectural stop is a valid outcome; a tolerance is not.

---

#### 10. Falsifiable predictions

1. **The corrected producer elects row 209 or row 208 at vertex 30 — never row 41.** Anything else contradicts
   §5.3, which is a rational identity over committed coordinates.
2. **Owner cardinality becomes exactly 1** at that locus, without any tie-break, because the developed sectors
   partition `[0, Θ)`.
3. **The filter decides vertex 30 without invoking the exact fallback**, since `α = θ₂₀₉` exactly is a measure-zero
   coincidence; the fallback will first be exercised by AY5's deliberate boundary-ray instance.
4. **Ordinals 1–365 stay green.** Every change is confined to the A2a vertex-transit decision and to additive
   diagnostics.
5. **A non-flat witness will separate `β = α + Θ/2` from `β = α + π`.** If it does not, the fixture is
   intrinsically flat and is not the discriminator §7.2 requires.

#### 11. Accounting and dispositions

Accepted 365 green in the last authoritative run; every finding on an unaccepted or definition-level surface.
**44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, semantic packages **73**,
**+0 events / +0 recurrences**.

- **`M3-CP4c3-TB3-R1-CAND-01`** — **ACTIVE / SEMANTICS FROZEN**. The definition gap CB8-REV named is closed by
  Amendments 22 and 23, and the expected answer at the measured locus is now known exactly. Owned by AY1–AY3.
- **`M3-CP4c3-TB6-CAND-01`** — **ACTIVE / CONTRACT FROZEN**. §8 fixes what the projection must publish; AY7 closes
  it at the projection boundary.
- **`M3-CP4c2-TB-X2-R8-CAND-02`**, **`M3-CP4c2-TB-X2-CAND-04`**, **`M3-CP4c2-TB-X2-R10-CAND-01`**,
  **`M3-CP4c3-DEFN-R1-CAND-01`** — all unchanged and deferred; untouched by this turn by AX0.
- **New: `M3-CP4c3-DEFN-R2-CAND-01`** — *an exact computation with no declared bound on its input size.* Amendment
  24 requires a published budget and a typed state; AY8's second predicate sweeps for other instances.

#### 12. Exact next turn

**`M3-CP4c-3-CB9`** — Code + Build, runtime-free, GMP/GMPXX linked, under **AY0–AY9**. Selector 373 stays frozen;
selector 374 is conditional on AY5. CP4c-2 remains **CLOSED / ACCEPTED at 365/365**; CP4c-3 remains **OPEN**.

---

## Part VII — M3-CP4c-3 DEFN-R3

*Authored in place on 2026-09-04 at `M3-CP4c-3-DEFN-R3`. This part is a **DEFN turn**, and under the project's turn
workflow **`DEFN` absorbs `REVIEW + PLAN`**: it freezes definitions, adjudicates the inherited candidates, and
issues its successor's measures in one turn. It supersedes Parts IV–VI where they conflict, and only there.*

**Boundary.** No Directional runtime, configure, compile, link, package, or product/test/fixture/selector mutation
occurred in this turn. Accepted selector **365** is untouched; selector **397** is byte-frozen. Measures
**CF0–CF9**, frozen by `Architecture_M3_CP4c3_TB23_R1_Independent_Review_Record.md` §8 (folded into
`M3_CP4c_Consolidated_Record.md` at `M3-CP4c-3-TB24-REV`).

---

### 1. CF0 — the state this part inherits

Current runtime authority is `M3-CP4c-3-TB23-R1` on selector 397: **389 PASS / 8 RED**, accepted **1–365 =
365/365**, reds `{366, 367, 368, 369, 370, 374, 393, 397}`. The mechanical actual embedded complex is **certified
cellular** — `V=22, E=26, F=6, componentCount=1, χ=2, residual=0`, every face proving disc topology.

Ordinal 366 has stopped at `UncutFaceComponentOrbitSeedNotUnique` since TB19: source-face component **0**, **191**
faces, `seedState=Multiple`, seed orbits `[0,1,3]`, boundary attribution **81 / 1 / 1** over 97 edges. Four
successive turns tried to determine whether that is a missing barrier or a mis-read seed. **None succeeded**, and
`M3-CP4c3-TB21-CAND-01`'s two branches have never been discriminated.

---

### 2. CF1 — what a certified face must publish

#### 2.1 The finding that decides it

`SurfaceCutGraphFaceCertificate` publishes exactly four fields per certified face:

```cpp
std::size_t orbit; std::size_t boundaryWalkCount;
std::size_t boundaryArcCount; bool discTopologyEstablished;
```

There is **no source-face membership and no boundary arc list**. The question every recent diagnostic has tried to
answer — *which certified face contains this source triangle* — is therefore not answerable by reading the
certificate. Each attempt had to **reconstruct** it from `walk.orbitByDart`, which is the seed quantity, and each
collapsed identically:

| Turn | Intended measurement | Why it reported nothing |
|---|---|---|
| CB24 | projection faithfulness residual | predicate **unsatisfiable by construction** |
| CB24 | per-side certificate faces | **aliased to the seed** |
| CB25 | certified-face ownership | edge-side path **re-derives the seed's dart orbit**; whole-face path collapses on "exactly one element" over a **coarser** partition |

#### 2.2 The certifier already computes the answer and discards it

`certify_actual_embedded_graph` (`src/geometry/SurfaceCutGraph.cpp:356–380`) begins by calling
**`build_embedded_graph_topology(sourceFaces, sourceVertexCount, sourceAuthority, network, cutEdges)`** — the
identical function `GlobalTopologyPlan` calls at `:2364` — and derives `embedded.faceWalk` from it. The certifier
holds the complete embedded topology, its arcs, its source topology and its face walk. It then publishes **counts
only**, and the plan rebuilds the identical structure to re-derive what the certifier already had.

**This is therefore a publication decision, not a new computation.**

> **AMENDMENT — WITHDRAWN AT `M3-CP4c-3-TB24-REV`.** The sentence immediately above is **false for the faces that
> matter** and is withdrawn. It is retained, struck, so a reader can see what was believed and why the successor
> failed. The face walk's darts are darts of *network and cut arcs*: a source face has a directly readable
> certified orbit **only if it is incident to an arc or crossed by a trace**. Every other source face — including
> most of component 0's 191 — has no dart of its own, and its owner must still be **propagated** across
> non-barrier edges from a face that does. That propagation is exactly the seeding algorithm DEFN-R3.2 set out to
> delete. CB27 implemented DEFN-R3.1 faithfully, re-implemented the propagation inside the certifier because it
> had to, and reproduced the identical failure — component 0, owner orbits `[0,1,3]`, locus `(0,1,2)`.
>
> **The normative decision of DEFN-R3.1 below is UNCHANGED and remains in force.** The certifier is the right
> authority. What is withdrawn is only the claim that it already knows the answer. See
> `Architecture_M3_CP4c3_TB24_Independent_Review_Record.md` §4 (folded into `M3_CP4c_Consolidated_Record.md` at
> `M3-CP4c-3-TB25-REV`), `M3-CP4c3-TB24-REV-CAND-02` and `LESSONS.md` 121.

#### 2.3 Normative decision — DEFN-R3.1

> **The owner map of a certified complex is a property of certification, and must be produced by the certifier.**
> `SurfaceCutGraphCellularityCertificate` **must publish a total source-face owner map**:
>
> - for a source face the network does **not** cross: the **single** certified-face id whose interior contains it;
> - for a source face the network **does** cross: the **set** of certified-face ids owning its local fragments,
>   keyed so that a consumer can attribute each fragment side without re-deriving it;
> - every published id must be one of that same certificate's `faces[].orbit` values;
> - the map must be **total** over the source faces of the certified complex.
>
> **Proof obligation.** `proves_cellularity()` is extended to require the map to be total and its ids to be drawn
> from the certificate's own faces. A certificate that cannot produce a total map does **not** prove cellularity —
> it reports a typed failure naming the first unowned source face.

**Rationale.** A consumer must never re-derive a partition its producer already computed. Re-derivation from
partial evidence is precisely what produced the aliasing, the unsatisfiable predicate and the coarse projection.

**What this does not decide.** Whether the two `build_embedded_graph_topology` invocations are unified into one is
an implementation question, not a definition. It is recorded as `M3-CP4c3-DEFN-R3-CAND-01` and left to the
successor's judgement; **two sources of truth for one object is a standing hazard**, and any unification must keep
the certifier's result authoritative.

---

### 3. CF2 — is the seed guard's premise checkable, and what replaces it

**Today: no.** The guard requires each connected component of uncut source faces to receive exactly one orbit seed
from its labeled neighbours. Whether that holds is a statement about **certified faces**, and certified faces do
not say which source faces they contain. The premise is unverifiable as the system publishes today, which is why
`seedState=Multiple` has been neither confirmed nor refuted for four turns.

**Under DEFN-R3.1: yes, and the guard's present form becomes unnecessary.**

> **DEFN-R3.2 — ownership is read, not seeded.** With a total owner map published, a source face's certified owner
> is a **lookup**. The seeding construction — `componentBarriers`, the unlabeled-face component partition,
> `seedOrbits`, and the per-edge seed rule with its `SingleFaceOwner` / `edgeOrbitEvidence` disjunction — is
> **replaced** by that lookup. `UncutFaceComponentOrbitSeedNotUnique` is **not weakened and not deleted**: it is
> **relocated** into a consistency check on the published map, failing closed when a component's faces do not all
> carry the same certified owner, and naming the component and the conflicting owners.

**This satisfies Parts IV and V.** Those parts prohibit *weakening* `UncutFaceComponentOrbitSeedNotUnique`. The
replacement is **strictly stronger**: it decides the same property from an authoritative total map instead of
reconstructing it from partial neighbour evidence, and it can name its own failure. A prohibition on weakening is
not a prohibition on replacing with something that decides more.

---

### 4. CF3 — the barrier set for any retained projection

`resolve_certificate_face_projection` unites source faces across every edge **not** in `embeddedGraphSourceEdges`,
which holds **mandatory and cut source edges only**. It therefore merges across trace-crossed edges, making its
components strictly coarser than the seed construction's — and a coarser component necessarily collects owners
from several certified faces, which is why all 191 faces reported `unavailable`.

> **DEFN-R3.3 — a derived partition must be at least as fine as the partition whose property it adjudicates.** Any
> source-face projection used to reason about certified ownership **must** use the full barrier set
> `mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges`. A projection over a strict subset of that set is **not**
> admissible evidence about ownership and may not be published as such.

Under DEFN-R3.2 no such projection is required at all. This clause binds any projection that is nevertheless
retained for cross-checking, so the omission cannot recur.

---

### 5. CF4 — adjudication of `M3-CP4c3-TB20-REV-CAND-02`

Parts IV and V each prohibit *"relaxing / weakening `proves_cellularity()`, the fragment-count invariant, or
`UncutFaceComponentOrbitSeedNotUnique`."* `M3-CP4c-3-CB21` made the fragment-count invariant's **low side**
non-fatal, and `M3-CP4c-3-TB18-REV` authorized that without consulting those lists.

**Both facts are accepted, and the substantive question has since been settled against the prohibition.**

- `|owners| = k + 1` equates a **local** fragment count with the cardinality of a set of **global** face-walk orbit
  owners. Equality requires the local-fragment → global-owner map to be injective.
- TB18 **measured** a counterexample on a witness whose complex is **certified cellular**: arc 15 with
  `forwardOrbit = reverseOrbit = 0`. On a cellular complex containing a bridge, the two sides of an arc genuinely
  share a face. The invariant is therefore **false**, not merely unproven.
- Part I §3's reasoning — which is what made the sibling guard "correct" — turns on a premise (**non-cellularity**)
  that TB21 measured false for the mechanical witness. The prohibition was authored when the only observed
  instance was the torus, where non-cellularity was independently proved.

> **DEFN-R3.4 — the prohibition on the fragment-count invariant is LIFTED, for stated reasons, and only for it.**
> `|owners| = k + 1` is not an invariant of a valid cellular complex, so a check asserting it cannot be preserved
> as written. `M3-CP4c-3-CB21`'s one-sided relaxation **stands and is not reverted**: its accepted-boundary safety
> was proved by construction — the validation loop is pure, and `>` holds on a strict subset of `!=`, so the
> failing set only shrinks and no previously-passing input changes.
>
> **The prohibitions on `proves_cellularity()` and `UncutFaceComponentOrbitSeedNotUnique` remain in force**, and
> DEFN-R3.1 *strengthens* the former while DEFN-R3.2 *relocates* rather than weakens the latter.

`M3-CP4c3-TB20-REV-CAND-02` is therefore **CLOSED — prohibition lifted with reasons**. Recorded so no successor
re-opens it by citing Parts IV/V alone: **Part VII governs where it conflicts with Parts IV–VI.**

---

### 6. CF5 — carried forward unweakened

`proves_cellularity()` (strengthened by DEFN-R3.1, never relaxed); the accepted **1–365** boundary; the certified
cellularity evidence `V=22, E=26, F=6, componentCount=1, χ=2, residual=0`; **CB21's correction**; the closure of
ordinals 371/372/391/392; and the separate ownership of **367/368/369/370/374**, vertex-30 and the
finalize/contact fall-through. **There is still no vertex-30 discriminator.**

Also carried: Part I §3 is an **implication with a premise** and licenses "the network is not a cut graph" only
where non-cellularity is independently established; the face walk is a validated total permutation; shared orbit
ownership by the two sides of one arc is legitimate topology.

---

### 7. CF6 — the undiscriminated branches, and what would discriminate them

**Recorded plainly: neither branch of `M3-CP4c3-TB21-CAND-01` has ever been discriminated.** The two readings of
component 0's `[0,1,3]` remain:

- **(a) missing barrier** — two boundary edges genuinely separate certified faces and are absent from
  `componentBarriers`;
- **(b) mis-read seed** — the edges are ordinary and the seed rule reported an orbit that does not face the
  component.

> **DEFN-R3.5 — the discriminator.** Under DEFN-R3.1 the question is decided by **one lookup, not a measurement**:
> take the certified owners of the 191 member faces of component 0 from the published map.
> **If they are not all equal, reading (a) holds** — the component spans certified faces, and the barrier set is
> missing the separations between them, which the differing pairs name directly.
> **If they are all equal, reading (b) holds** — the component lies in one certified face and the two minority
> seeds were mis-reads.
>
> No further diagnostic instrumentation is authorized to answer this. If the published map cannot be produced,
> that is a DEFN-R3.1 failure and is reported as one.

---

### 8. CF7 — disposition of ordinals 393 and 397

**Ordinal 397 — `UnrelatedTopologyErrorLocusRemainsByteIdenticalAfterCertificateDiagnostics` — must be FIXED.**
CB25 appended `;cutCandidateCount=0` to the rendered locus of an **unrelated** topology error; the witness expected
`;sourceFace=2,4,6` and received `;sourceFace=2,4,6;cutCandidateCount=0`. The defect is in the product's locus
rendering, not in the expectation.

> **DEFN-R3.6.** Restore byte-identical rendering for errors the diagnostic work does not own. **Relaxing or
> re-scoping ordinal 397's expectation is prohibited.** A byte-identical regression witness that is edited to
> match a regression has been converted into its opposite.

**Ordinal 393 — `MechanicalProjectionEvidencePublishesMinorityRowsAndFaithfulnessResidual` — is SUPERSEDED, and its
assertions are REPLACED in place.** Its expectations (`differing > 0`, `certifiedFaceDiffersFromSeed`) were written
to falsify a *reconstruction*. Under DEFN-R3.2 the reconstruction and its seed both cease to exist, so those
expectations are not merely unsatisfiable but **meaningless** — there is no seed for a certified face to differ
from.

> **DEFN-R3.7.** The successor Code + Build **replaces ordinal 393's assertions** with the DEFN-R3.1 contract: the
> published owner map is total, its ids are drawn from the certificate's own faces, and the certified owners of a
> named component are reported. **The ordinal is retained and stays gating**; the identity name may be updated to
> match its new contract. It is **not** deleted, **not** reordered, and **not** made non-gating.
>
> This is the correct route rather than a permanent non-gating carve-out: the identity's *purpose* — falsifiable
> evidence about certified ownership — is preserved, while only the obsolete mechanism it referenced is replaced.
> The change must be recorded in the successor's report with the before and after assertions.

**Selector governance.** Selector 397 stays byte-frozen through the successor; identities are appended only, never
removed or reordered. Replacing an identity's assertions is a test-source change, not a selector change.

---

### 9. CF8 — successor gate

#### `M3-CP4c-3-CB27` — Code + Build, measures **CG0–CG9**, runtime-free, GMP/GMPXX linked

- **CG0** — accepted 365 untouched; selector **397** byte-frozen and republished unchanged; the eight standard
  compile targets with **mandatory GMP/GMPXX linkage**; **no runtime**; no acceptance claimed.
- **CG1** — implement **DEFN-R3.1**: publish the total source-face owner map on
  `SurfaceCutGraphCellularityCertificate`, produced by the certifier from the topology it already builds, with ids
  drawn from its own `faces[].orbit`.
- **CG2** — extend `proves_cellularity()` with DEFN-R3.1's proof obligation: the map is total over source faces and
  its ids are certificate face ids. A certificate that cannot produce it reports a typed failure naming the first
  unowned source face.
- **CG3** — implement **DEFN-R3.2**: replace the seeding construction with a lookup, and relocate
  `UncutFaceComponentOrbitSeedNotUnique` into a consistency check over the published map that names the component
  and the conflicting owners on failure.
- **CG4** — implement **DEFN-R3.6**: restore byte-identical locus rendering for unrelated errors.
- **CG5** — implement **DEFN-R3.7**: replace ordinal 393's assertions with the new contract, recording before and
  after; keep the ordinal gating.
- **CG6** — discharge the two carried debts, both of which require source changes and so belong here:
  `M3-CP4c3-TB23-REV-CAND-01` — make `tests/TestFixturePaths.h`'s `test_data_root()` **fail closed** rather than
  return a non-existent path; and `M3-CP4c3-TB23-R1-REV-CAND-01`, which CG4 covers.
- **CG7** — witnesses: one per new published field through the **production** path; a witness that the owner map is
  total on all three fixtures; a witness that the relocated guard **names its component and conflicting owners**;
  and — per the standing rule that a diagnostic must be falsifiable — a **unit** witness proving the consistency
  check *can* fail and a **production** witness proving whether it *does*. Append the next selector **named by its
  resulting identity count**; 397 stays an exact prefix; regenerate
  `Required_Green_Selector_Manifest.md` with `tools/selector_manifest.py`.
- **CG8** — audit by assumption; prove accepted ordinals **1–365** unaffected by construction, and that
  `proves_cellularity()` is only strengthened.
- **CG9** — publish the `M3-CP4c-3-TB24` discriminators: **(1)** 1–365 stay 365/365; **(2)** the owner map is
  published and total on the mechanical witness; **(3)** **the certified owners of component 0's 191 faces are
  reported — all-equal or not, which decides `M3-CP4c3-TB21-CAND-01` per DEFN-R3.5**; **(4)** ordinal 366 either
  clears or fails with the relocated guard naming its component and conflicting owners; **(5)** ordinals **393 and
  397 are green**; **(6)** carried surfaces 367/368/369/370/374 unchanged and 371/372/391/392 still PASS.

---

### 10. CF9 — prohibited

Inventing a certificate field without naming its producer and its proof obligation. Weakening
`proves_cellularity()` or `UncutFaceComponentOrbitSeedNotUnique` — DEFN-R3.1 strengthens the first and DEFN-R3.2
relocates the second; neither may be softened. Relaxing or re-scoping **ordinal 397's** expectation. Deleting,
reordering or de-gating **ordinal 393**. Publishing a source-face projection built on a strict subset of
`mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges` as ownership evidence. Any further **diagnostic-only** turn on the
ownership surface — DEFN-R3.5 makes it a lookup. Any fixture-specific branch, tolerance, float-derived topological
decision, or accepted-boundary relaxation. Reverting `M3-CP4c-3-CB21`. Any sphere / saturation / ordinal-370 /
folded-cone / vertex-30 / finalize-contact work.

---

### 11. Falsifiable predictions

1. The owner map is producible from what the certifier already computes, without a new traversal — CG1 lands
   without adding a face walk.
2. `proves_cellularity()` continues to hold on all three fixtures after CG2 strengthens it; if it does not, the
   certificate was over-claiming and the failure names the first unowned source face.
3. Component 0's 191 certified owners are **not all equal**, making reading (a) — missing barrier — the live
   branch. *This is a prediction, not an authorization*: CG9-3 reports the fact either way, and a correction is
   frozen only by the review that reads it.
4. Ordinals 393 and 397 both go green under CG4/CG5; 397 going green requires no expectation change.

---

### 12. Accounting and exact next turn

`M3-CP4c3-TB20-REV-CAND-02` **CLOSES** (prohibition lifted with reasons, §5). New `M3-CP4c3-DEFN-R3-CAND-01` —
`build_embedded_graph_topology` is invoked independently by both the certifier and the plan, giving two sources of
truth for one object; **ACTIVE / ARCHITECTURAL / NON-GATING**, owner CG1's judgement.
`M3-CP4c3-TB21-CAND-01` remains **ACTIVE / GATING**, now with a stated discriminator (§7).
`M3-CP4c3-TB23-REV-CAND-01` and `M3-CP4c3-TB23-R1-REV-CAND-01` are assigned to **CG6/CG4**.
`M3-CP4c3-TB23-R1-REV-CAND-02` is assigned to **CG5**.

This is a definition turn: no runtime, no gate, **+0 stable events / +0 recurrences**. Totals remain **44 events /
14 categories / 30 recurrences**; produced-witness debt **5**; semantic M3 package count **88**. Accepted authority
remains **365/365**; CP4c-3 remains **OPEN**.

**Exact next turn: `M3-CP4c-3-CB27` — Code + Build, runtime-free, GMP/GMPXX linked, under CG0–CG9.**

---

## Part VIII — M3-CP4c-3 DEFN-R4

**Turn:** `M3-CP4c-3-DEFN-R4` — definition turn (absorbs REVIEW + PLAN).
**Frozen owner:** CR6–CR8 of `Architecture_M3_CP4c3_TB31_Independent_Review_Record.md` (folded into `M3_CP4c_Consolidated_Record.md` at `M3-CP4c-3-TB32-REV`).
**Status:** STATIC / NO RUNTIME / NO COMPILE / NON-STABLE.

Runtime authority entering this turn: `M3-CP4c-3-TB31`, selector 408, **397 PASS / 11 RED**, accepted
**1–365 = 365/365**, certified source-face ownership **300 established / 0 unavailable / 0 conflicting**, plan
component 0 at **189 faces / seedCount 1 / `Unique` / `[0]`**. Stable accounting **44 / 14 / 30**, debt **5**,
packages **96**.

### 1. CR8 — why the guard became reachable, established from source

TB31-REV recorded that it could not determine this statically and required transcription from the retained log.
**It is determinable from source, and the transcription is unnecessary.**

- `build_regions` is defined at `GlobalTopologyPlan.cpp:629` and called at `:2212`. It contains
  `UncutFaceComponentOrbitSeedNotUnique`.
- `build_fragment_corner_incidence` is defined at `:405` and called at `:2014`, **from
  `build_region_certificates`** (`:1988`), which takes the already-built `regions` as a parameter.
- `build_region_certificates` therefore runs **after** `build_regions`.

**`TraceArcDoesNotSeparateItsSides` is strictly downstream of `UncutFaceComponentOrbitSeedNotUnique`.** It was
unreachable for as long as the seed guard fired. CB36 cleared the seed guard, the mechanical fixture reached region
certificate construction for the first time, and the next guard on that path fired.

**This corrects TB31-REV §2.2**, which inferred from line numbers that the guard sat *upstream* of the seed guard
and treated its reachability as unexplained. It is downstream, and its reachability is fully explained by the
pipeline advancing. **CB36 did not change the walk this function observes**, which removes the risk TB31-REV
flagged as the reason the transcription mattered.

`M3-CP4c3-TB31-REV-CAND-03`'s evidence-attachment concern is unaffected and is decided at §5 below.

### 2. What `FragmentCornerIncidence` actually is — DEFN-R4.1

TB31-REV called `(face, orbit)` a **fragment identity** and concluded the key was not injective. That description
is withdrawn. The structure is not a fragment index.

> **DEFN-R4.1 — normative.** `FragmentCornerIncidence`, `map<SourceFaceTopologyKey, map<orbit, set<SourceVertexId>>>`
> (`GlobalTopologyPlan.cpp:399–401`), is an **ownership map**: `fragmentCorners[face][orbit]` is the set of `face`'s
> corner vertices owned by **certified face `orbit`**. It is keyed by owning region, not by fragment, and it is not
> required to distinguish two fragments that share an owner.

Both consumers use it exactly that way:

- `:1893–1906` — `cutFace->second.find(owningOrbit)`: *"which of this face's corners belong to **my** region?"*,
  failing with `RegionSourceFaceOwningFragmentMissing` when the region owns none.
- `:1927–1945` — iterating `(orbit, corners)` to classify a vertex as `ownedByRegion` when `orbit == owningOrbit`
  and `ownedByOtherRegion` otherwise: *"mine, or another region's?"*

Neither asks how many fragments a face has, nor which geometric fragment a corner lies in. The `FragmentKey` used
for region interior connectivity (`:1693–1699`) carries `owningOrbit` as a **constant tag** for every face of the
region, so it too is region-scoped rather than fragment-scoped.

### 3. A bridge chord — DEFN-R4.2

> **DEFN-R4.2 — normative.** When a trace arc's two darts lie in the **same** face-walk orbit, both sides of its
> chord are owned by that one certified face. The correct value of `fragmentCorners[face]` is then a **single entry
> containing every corner of the face**. This is the correct answer under DEFN-R4.1, not a key collision.

The full-chord branch already produces it: `result[face][cornerOrbit].insert(sharedCorner)` (`:541–543`) and
`result[face][sideOrbit].insert(other corners)` (`:544–548`) merge into one entry when
`cornerOrbit == sideOrbit`, yielding all three corners under the single owning orbit. Both consumers then answer
correctly — the region owns all three, and no vertex is misattributed to another region.

### 4. `TraceArcDoesNotSeparateItsSides` is RETIRED — DEFN-R4.3

> **DEFN-R4.3 — normative.** `GlobalTopologyPlanErrorCode::TraceArcDoesNotSeparateItsSides` is **retired from the
> emission path**. `build_fragment_corner_incidence` must not reject a trace segment because its arc's two darts
> share a face-walk orbit. The enum entry remains declared so the typed-error surface and ledger history stay
> stable; it becomes unreachable.

Three reasons, each independently sufficient and all checkable:

1. **Its premise is refuted by a settled fact.** *"Shared orbit ownership by the two sides of one arc is legitimate
   topology; BS9-5 remains retired"* has stood since TB18, and DEFN-R3.4 measured exactly that on **arc 15**,
   `forwardOrbit = reverseOrbit = 0`, on a certified cellular complex.
2. **It contradicts the correction this checkpoint just proved.** The separating-arc barrier rule keys on
   `forwardOrbit != reverseOrbit` precisely because equal orbits mean *does not separate*, and deliberately leaves
   arcs 20 and 24 (`0/0`) alone. A guard that then rejects those arcs asserts the opposite of the rule that
   depends on them.
3. **The same function already accepts equal orbits on its other path.** The ray branch writes
   `result[face][ray.forwardOrbit]` and `result[face][ray.reverseOrbit]` (`:608–615`) with no guard, merging
   silently and correctly when they coincide. **The rejection is an internal inconsistency within one function, not
   a protection of the representation.**

This retirement is **a consequence of DEFN-R4.1 and R4.2, not a relaxation**. TB31-REV's caution — that deleting
the guard would merge two distinct fragments — was correct about the mechanism and wrong about the consequence:
the merge is what DEFN-R4.1 requires. The successor must record the merge as intended behaviour at the site, so a
later reader does not reintroduce the guard.

**Prohibited:** removing the guard without recording DEFN-R4.1's contract in the code, and re-deriving fragment
identity from the orbit anywhere downstream.

### 5. Frontier evidence must not hang off one failure code — DEFN-R4.4

> **DEFN-R4.4 — normative.** The plan-side failing-component **face-set digest**, the certifier census identity and
> the `censusCorrespondence` / subset relation are properties of the plan's state, not of any particular typed
> failure. They must be published on the failure locus **whenever the plan terminates during region construction or
> region certification**, independently of which typed code terminates it.

They vanished at TB31 solely because the terminal code changed, which is the defect
`M3-CP4c3-TB31-REV-CAND-03` names.

### 6. Witnesses must not name the failure — DEFN-R4.5

> **DEFN-R4.5 — normative.** A witness whose contract is *"this evidence is published when the production path
> fails"* must assert the **evidence**, not **which** typed failure produced it. Ordinals **390, 393, 406 and 407**
> have their assertions **replaced in place**: each keeps every contract it legitimately owns, and each stops
> asserting `terminalFailureDetailCode == "UncutFaceComponentOrbitSeedNotUnique"`. Ordinals, names and selector
> bytes are unchanged; all four remain **gating**.

Where an identity genuinely needs a typed failure to exist, it asserts that the failure **carries the required
evidence fields**, not its name. This is the disposition CB35 applied to ordinals 390 and 404 and TB30 proved
correct, generalized.

**This is a restoration, not a weakening.** Six identities across two forward steps have redded because they pinned
the failure the product used to make; the two that survived both steps — **404 and 408** — assert publication and
completeness instead. That is the standard.

### 7. What DEFN-R4 does not decide

1. **Source-face ownership is CLOSED** — 300/300 certified, component 0 unique at `[0]`. The separating-arc barrier
   rule stands **at both sites** and is not re-opened.
2. **Ordinal 398 is untouched.** It fails on the prescribed sphere
   (`NotProductionReady/CellularityNotEstablished`), owned by `M3-CP4c2-TB-X2-CAND-04`. It is **not** an ownership
   gate and must not be re-scoped to exclude the sphere.
3. **Ordinals 368, 369, 370 and 374** keep their separate owners and are untouched.
4. **The two partitions are not unified.** `M3-CP4c3-TB26-REV-CAND-04` / `M3-CP4c3-DEFN-R3-CAND-01` stay open; the
   plan's partition now yields a unique owner, so the divergence does not hold the frontier and its resolution is
   not required here.
5. **No new diagnostic contract** on ownership or on fragments. Everything above is decided from source.

### 8. Successor — CS0–CS6, `M3-CP4c-3-CB37`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`.

- **CS1** — retire the `TraceArcDoesNotSeparateItsSides` emission in `build_fragment_corner_incidence`
  (`:474–479`), per DEFN-R4.3. Record DEFN-R4.1's ownership contract at the site so the merge reads as intended.
  The enum entry stays declared.
- **CS2** — publish the plan-side failing-component digest, the certifier census identity and the
  `censusCorrespondence` / subset relation on every region-construction and region-certification failure locus, per
  DEFN-R4.4.
- **CS3** — replace in place the assertions of ordinals **390, 393, 406, 407** per DEFN-R4.5. Ordinals, names and
  selector bytes unchanged; all remain gating. **Nothing any of them legitimately owns may be relaxed.**
- **CS4** — **accepted-prefix safety by construction.** CS1's only reachable behaviour change is on a trace segment
  whose arc has equal dart orbits; enumerate what differs there and show every other path is identical.
- **CS5** — selector **408 unchanged**. If the ownership contract needs a witness, it appends as **409** with 408 as
  an exact 408-line prefix, asserting **publication and completeness** — that a face crossed by a bridge chord
  publishes exactly one owning-orbit entry containing all of its corners — and **never** a predicted owner value.
- **CS6** — `M3-CP4c-3-TB32` re-executes. **Credibility gate: 368, 369, 370, 374 and 398 must remain RED**, since
  none is touched. **Required outcome: 390, 393, 406 and 407 return to PASS.** For 366/367, either the plan
  proceeds past region certification or it stops at a **further** guard; a stop at
  `TraceArcDoesNotSeparateItsSides` falsifies DEFN-R4.3, and a stop reproducing
  `UncutFaceComponentOrbitSeedNotUnique` with component 0 at 189/1/`[0]` would falsify DEFN-R4.1.

### 9. Accounting

Definition turn: no runtime, no compile, no gate. **+0 events / +0 recurrences.** Totals remain **44 events / 14
categories / 30 recurrences**, produced-witness debt **5**, semantic M3 package count **96**. Accepted authority
remains **365/365**; CP4c-3 remains **OPEN**.

**Exact next turn: `M3-CP4c-3-CB37` — Code + Build, runtime-free, GMP/GMPXX linked, under CS1–CS6.**

---
