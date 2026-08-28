# M3-CP4c-2 DEFN — Frozen Definitions: closed-surface cut-graph authority for A2b

## 0. Turn type and verdict

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

## 1. Predecessor verification — CP4c-1 closure independently checked

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

## 2. The measured state of A2b — DURABLE

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

## 3. Theorem — the torus network provably cannot bound discs

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

## 4. The `DESIGN.md` §7.2 defect

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

### Amendment 12 — normative, replaces the quoted text in §7.2

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

## 5. The frozen contract for `SurfaceCutGraph` (stage A2a′)

### 5.1 Position and authority

- **Produced after** A2a (`FieldAlignedCurveNetwork`) and **before** A2b (`GlobalTopologyPlan`).
- **Single writer.** Nothing else may create, extend, or amend cut edges. A2b consumes it `const` and may not
  add to it.
- **Inputs, all immutable:** `SourceAuthoritySnapshot`, `FieldTransportAtlas`, `FieldAlignedCurveNetwork`.
- **It may not read, construct, or depend on any `GlobalTopologyPlan` or any region.** This is the §4
  precondition-versus-repair boundary and it is a hard architectural constraint, not a style preference.

### 5.2 Output

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

### 5.3 Required guarantees

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

### 5.4 Construction guidance — explicit, because the implementation agent must not have to guess

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

**A note on quality, and its limit for this checkpoint.** A cut graph is not unique, and the choice affects
downstream quad quality: cuts ideally follow the field and lie where a seam is least visible. **CP4c-2 does not
optimize that.** Its obligation is a correct, deterministic, certified cut graph. Choosing a *good* cut graph is
a quality concern, and the frozen requirement here is only that the interface make a future policy swap possible
— the selection rule must be one named, replaceable strategy, not scattered inline decisions. Do not build the
alternatives harness in this checkpoint.

## 6. Scope — what CP4c-2 owns, and the C3 deferral

### 6.1 In scope

- **C1** `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath` — the torus derives regions
  through the production entry path. This is the checkpoint's anchor and its non-vacuity guarantee.
- **C6** `GlobalTopologyPlan.ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation` — produced regions
  carry the disc proof and preserve mandatory topology.
- `DESIGN.md` Amendment 12 and the `SurfaceCutGraph` product.

### 6.2 A vacuity trap that must be closed

**C3 and C6 are both quantified over "produced witnesses."** Today no witness produces a plan, so **both would
pass vacuously** on a suite where nothing reaches A2b. That is the same defect class as CP4c-1's C5 — a
criterion whose truth value does not depend on the thing it is supposed to certify.

**Binding requirement:** CP4c-2 may not close on a vacuous C6. C1 is the non-vacuity anchor — the torus must
actually produce a plan with at least one region, and C6 must be shown to have examined at least that many
regions. Measure **X7** makes this reportable rather than assumed.

### 6.3 Why C3 is deferred, and what would bring it back

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

### 6.4 Out of scope — do not touch

The mechanical witness and its A1 `IncompleteCycleBasis`; C2; CP4c-3; any change to accepted ordinals 1-355;
quad quality or seam aesthetics; the alternatives harness.

## 7. Measures **X0–X9** for `M3-CP4c-2-CB1`

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

## 8. Falsifiable predictions

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

## 9. Defects recorded by this turn

1. **Dangling citation.** `Regression_Root_Cause_Tracker.md`'s `M3-CP4c1-TB-R4-CAND-03` entry cites
   `Architecture_M3_CP4c1_CB4_Code_Build_Report.md`, retired in the fifth consolidation. The substantive
   rationale is reproduced in the tracker entry itself, so nothing is lost; the pointer is corrected by this
   turn to name the consolidated record instead.
2. **`DESIGN.md` §7.2's "by construction" claim is false** on closed surfaces, and has been since the document
   was written. Amendment 12 corrects it. Recorded as a design defect, not a product regression: no code ever
   relied on the false claim — A2b fails closed instead, correctly.

## 10. Stop / successor

The exact next turn is **`M3-CP4c-2-CB1`**, Code + Build, runtime-free, under measures **X0-X9**.

Its successor is `M3-CP4c-2-TB`, the full gate at **357 or 358** as decided by X2. **CP4c-2 closes on that gate
green with §8's predictions 1-4 met and X7's non-vacuity report showing a non-zero region count.** Anything less
routes to independent review, not to a retry.
