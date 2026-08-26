# M3-CP4c-0-TB-R6 — Independent Review and Corrective Plan

Turn: `M3-CP4c-0-TB-R6-REVIEW-PLAN`. Review and planning only.
**No Directional runtime, build, benchmark, or mutation of product/test/fixture/selector/build logic
occurred.** Evidence, source and committed fixtures were *read*, and arithmetic was performed on their
contents; nothing was executed and nothing was modified.

Brief: `Architecture_M3_CP4c0_TB_R6_Review_Plan.md`.
Evidence: `Architecture_M3_CP4c0_TB_R6_Artifact_Only_Test_Benchmark_Report.md`, run
`33006282429 / 98300813772`.
Contract: `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md` (Amendments 1–8).

---

## 0. Verdict, stated first

**Every published datum at the live failure is correct. The invariant that rejects it is wrong.**

I reproduced the sphere's census independently from the committed fixture — mesh and rawfield only, no
product code — and obtained **exactly 144 directed disagreements**, matching TB-R6's runtime figure. That
reproduction also shows *why*, and the answer is not any of H-A, H-B, H-C, gauge composition, or flow
classification.

1. **At the live locus every term verifies correct**, each independently computed from the fixture:
   `matching = 0` is geometrically right with a wide margin (nearest target raw index at **23.7°**, next
   at 66.3°); `0 + 1 − 3 ≡ 2` reproduces the published `signedLift = 2` exactly; both gauges map their
   semantic branch to **raw index 0**; and **both published `dbary` triples reproduce to 10 decimal
   places**. §3.
2. **The disagreements are a near-tangency discretization phenomenon.** The tangency ratio
   `min(|d_opp| / max|d|)` has median **0.0218** across all 144 disagreeing pairs and median **0.9233**
   across the 1008 agreeing ones — a factor of 42. **Every disagreement lies at ≤ 0.2004.** §5.
3. **Amendment 4 / measure E5's invariant is too strong, and that is my error.** It asserts a *continuum*
   property — a direction exiting `X` must enter `Y` — which a **piecewise-constant** field on a
   triangulation does not satisfy near tangency: the perpendicular component at the shared edge is small,
   and the field's own rotation across that edge (≈ 20–25° here) flips its sign. Both faces then compute
   "outflow" correctly. §4, §6.
4. **My TB-R4 claim that this is "geometrically impossible" was wrong**, and so was the reasoning that
   supported it. I argued `|d| = 1.0035` is "three orders of magnitude above any epsilon" and therefore
   not near-tangency. Tangency is a **ratio**, not a magnitude: `1.0035` is the *smallest* of that face's
   three coordinates `{4.00, 5.01, 1.00}`. §4.
5. **J3 cannot test H-B, and that is also my error.** `independent_edge_measurement` re-implements
   **principal matching** — the very algorithm H-B suspects. Its 524/524 is an implementation check, not
   an aliasing test. H-B was *untested*, not excluded — though it is now separately excluded **at the
   live locus** by direct measurement. §7.
6. **The report's routing to `build_branch_transports` is unsupported.** The composition is arithmetically
   correct at the live locus. §3.
7. **There are not two classes.** The unequal-gauge and equal-gauge/lift-0 populations share one
   signature: near-tangency. That is the "lowest common invariant" the TB report asked for. §5.

**The real open question is a tracing-model question for `DESIGN.md` §4.5, not a bookkeeping fix:** what
does a trace do when it reaches an edge that the neighbouring face's direction also exits? Amendment 9
(§8) corrects the contract; measures **K0–K7** (§9) are diagnostic and definitional, not corrective.
**No production change is authorized.**

---

## 1. Independent verification of the evidence — CONFIRMED

| Claim | Verified |
|---|---|
| run `33006282429`, control SHA `a9ae307590b0cc23080452c4a5013674efc48fc2` | ✅ (API) |
| result artifact `9620769314` SHA-256 `fe6a7317…ee4936684` | ✅ exact |
| diagnostic artifact `9620770049` SHA-256 `ce87da5a…7cb691cb` | ✅ exact |
| CB6 package `9619352525`, semantic source `8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6` | ✅ as recorded |
| selector 338 `d588cae0…`, 316-prefix `601ce2b6…`, 328-prefix `cf93622e…` | ✅ **recomputed locally**, unchanged |
| gate 338/338, F3 2/2, G5/H1/J3 PASS non-gating, Q8 creditable/RED criterion 2 | ✅ as reported |
| H1 legitimate totals **388 directed / 194 distinct**; fan **2/1** excluded | ✅ — **exactly the TB-R5 review's P4 prediction** |
| J3 fan mismatch is edge `1-4`, declared `1` vs geometry `0` | ✅ — **exactly the TB-R5 review's P1 prediction** |

**The prior review's two headline predictions were confirmed to the digit.** The fan-artifact analysis
and the doubling correction both held.

**Orchestration.** Attempt `33006048971 / 98300014224` is correctly excluded: Python `zipfile.extractall`
dropped executable mode bits, so the first binary launch failed with `PermissionError` before any
Directional binary ran. The retry replaced only the extraction mechanism with `unzip`; it did **not**
chmod or repair package contents. **Accepted** — and note this is the second consecutive cycle lost to a
staged-payload transport defect (TB-R5: line-ending normalization). See K6.

---

## 2. What I did, so the reasoning can be checked

Everything below is derived from two committed files —
`benchmarks/fixtures/milestone-g/sphere_prescribed.obj` and `…/sphere_prescribed.rawfield` — plus the
published census output. No product code was executed. The arithmetic is reproducible in a few lines.

For every interior edge of the sphere and every raw index of the source face, I:

1. computed the dihedral connection about the shared edge from the two mesh-row normals;
2. transported the source raw direction and selected the nearest target raw index by absolute angle
   (geometric principal matching);
3. computed each face's barycentric derivative `dbary = {−u−v, u, v}` in canonical vertex order;
4. tested the E5 invariant: `d_source[opp] < 0` and **not** `d_target[opp] > 0`.

**Result: 144 directed disagreements — exactly the runtime figure.** The reproduction is faithful.

---

## 3. The live locus, term by term — every published datum is correct

Sphere edge `6-8`, source face `6-8-9` branch `3`, target face `6-8-97` branch `1`, published
`matching = 0`, `rawGaugeSource = 1`, `rawGaugeTarget = 3`, `signedLift = 2`.

| Term | Independent check | Verdict |
|---|---|---|
| lift composition | `matching + g_src − g_tgt = 0 + 1 − 3 = −2 ≡ 2 (mod 4)` | ✅ **published value exactly** |
| semantic → raw | source `(1+3) mod 4 = 0`; target `(3+1) mod 4 = 0` | ✅ **both raw index 0** |
| matching correctness | transported source raw0 · target raw *j*: `j=0: +0.9155 (23.7°)`, `j=3: +0.4024 (66.3°)`, `j=1: −0.4024`, `j=2: −0.9155` | ✅ **principal matching = 0, wide margin — not an aliasing case** |
| source `dbary` | computed `[−4.0035357904, +5.0070715807, −1.0035357904]` | ✅ **matches published to 10 dp** |
| target `dbary` | computed `[−3.2246869293, +3.8016833692, −0.5769964399]` | ✅ **matches published to 10 dp** |
| mesh adjacency | outward normals of the two third-vertices: dot `−0.9394` | ✅ **properly opposite; no fold.** All 288 interior edges are normal adjacency, zero folded |

**Every single published term is correct.** The lift is right, the matching is right, the gauges are
right, both directions are right, and the mesh is sound.

**Therefore the report's conclusion that the live locus "selects the frozen decision-table row for A1
gauge composition in `build_branch_transports`" does not follow.** My TB-R5 decision table said
"`matching = 0` + unequal gauges ⇒ the gauge term is wrong". At this locus the gauge term composes
*correctly*; the row is satisfied by coincidence, not by fault. **That row must be withdrawn as a
diagnosis.**

---

## 4. Why "geometrically impossible" was wrong — my TB-R4 error, corrected

In the TB-R4 review I wrote that both faces calling a shared edge `Outflow` is *"geometrically
impossible for a single continuous direction"*, and that `|d| = 1.0035` and `0.5770` being "three orders
of magnitude above any epsilon" excluded near-tangency.

**Both statements are wrong.**

- **Tangency is a ratio, not a magnitude.** In the source face the three coordinates are
  `{4.0035, 5.0071, 1.0035}` — the edge-`6-8` coordinate is the **smallest**, at `1.0035 / 5.0071 =
  0.2004`. In the target face `{3.2247, 3.8017, 0.5770}` gives `0.1518`. The direction is the
  *closest-to-tangent* of the three in **both** faces. Distance from an epsilon says nothing about it.
- **The impossibility argument assumed a continuous field.** For a piecewise-constant field the direction
  **jumps** at the edge by the field's own rotation. Measured here: the two faces' raw-0 vectors are
  **23.4°** apart. Their perpendicular components relative to the shared edge are `+0.243` and `+0.168`
  in each face's own outward sense — small, and of opposite sign in a common frame, because both vectors
  lie within ~14° of the edge direction and straddle it. Two vectors 23° apart, both nearly parallel to
  the edge, can each have an outward component on their own side. **Nothing is impossible here.**

I record the refutation explicitly because it was stated with high confidence in a durable review and
propagated into three subsequent documents.

---

## 5. The unified explanation, measured

For each source-outflow pair I computed the **tangency ratio** `min(|d_opp| / max|d|)` over the two
faces — how close to edge-tangent the direction is in the more tangent of them.

| Population | n | median | extreme |
|---|---:|---:|---|
| **disagreeing** (E5 fires) | 144 | **0.0218** | max **0.2004** |
| agreeing (E5 satisfied) | 1008 | **0.9233** | min 0.0128 |

A separation of **42×** in the median, with every disagreement at or below `0.2004`. The two
distributions overlap slightly at the bottom — which is exactly right, because this is a **geometric
regime, not a threshold**. Introducing a cutoff would be a tolerance deciding ownership, which
`DESIGN.md` §6.3 forbids and which this project has already paid to remove twice.

This single mechanism explains every previously puzzling feature of the census:

| Observation | Explained by near-tangency |
|---|---|
| rate is sparse (2.5–13.9 %), not ~50 % | only near-tangent configurations qualify |
| torus (13.9 %) > sphere (6.25 %) | different field/mesh anisotropy, more near-tangent edges |
| only 52/388 singular-incident | tangency is unrelated to singularities |
| `matching = 0` dominates | most edges have matching 0; tangency is independent of matching |
| the largest class is equal-gauge/lift-0 | identity transport; tangency is independent of gauge |
| J3 finds 524/524 agreement | the matching genuinely **is** correct; it was never the problem |
| the live locus sits at `0.1518–0.2004` | the **least** tangent of the disagreements — the first one a trace happened to reach |

**Answer to the TB report's question — "prove the lowest common invariant or split them explicitly":
there is one class, not two.** The unequal-gauge (86/43) and equal-gauge/lift-0 (254/127) populations are
the same phenomenon seen through different bookkeeping. Splitting them would chase two shadows of one
object.

---

## 6. What is actually broken

Nothing in A1's bookkeeping. What is broken is **the frozen contract**, in two places:

1. **Amendment 4 / measure E5's invariant is unsound for a piecewise-constant field.** It is a continuum
   statement applied to a discrete one. It will fire on any mesh+field with near-tangent edges — which,
   measured here, is **6–14 % of all `(edge, branch)` pairs on ordinary witnesses**.
2. **`DESIGN.md` §4.5's tracing model does not say what happens at a grazing edge.** That is the real
   gap. A trace travelling nearly parallel to an edge reaches it, and the neighbouring face's direction
   also exits through it. The trace is *grazing*, and the model is silent.

The second is the substantive question CP4c-0 must now answer, and it is a **`-DEFN` question**, not a
patch. Framing the options without choosing (that is the DEFN's job, and it needs evidence K1–K3 supply):

- **Tangential continuation** — treat the edge as a carrier the trace follows, adding an edge-following
  state to the tracing model. Most faithful to the continuum limit; largest model change.
- **Typed grazing terminus** — stop the trace with a new typed network event. Smallest change, fail-closed,
  honest; costs trace completeness and may make Q8's 24 traces unreachable on this witness.
- **Refinement precondition** — declare near-tangency an admissibility condition on the input field/mesh
  and require preprocessing. Pushes the problem to A0/A1 admissibility; needs a criterion that is not a
  tolerance-as-ownership.
- **Exact-arithmetic reformulation** — reconsider whether the continuation should consult the *pair* of
  faces jointly at the edge rather than each face independently, so the grazing case is decided once.

**None of these may be chosen on current evidence.** K1–K3 measure what each would cost.

---

## 7. J3 cannot test H-B — my specification's fault

`cp4c_matching_geometry_census` delegates to
`directional::test_support::independent_edge_measurement`
(`tests/support/SkewSingularFieldWitness.h`), whose core is:

```cpp
for (int branch = 0; branch < 4; ++branch) {
  const double rotation = independent_signed_angle(transported[0], targetBranches[branch], targetNormal);
  if (std::abs(rotation) < std::abs(smallestRotation)) { smallestRotation = rotation; principalBranch = branch; }
}
```

That is **principal matching** — "nearest target branch by absolute rotation". H-B is the hypothesis that
**principal matching alone can alias field topology** (`DESIGN.md` §4.1, Vaxman et al.). J3 therefore
compares the declared matching against *the algorithm under suspicion*.

**What J3 does establish:** production's principal-matching implementation agrees with an independent
implementation of principal matching, on 524/524 legitimate transitions. That is a real and useful
implementation check.

**What it cannot establish:** that principal matching is the *correct* correspondence. Aliasing is
precisely the case where principal matching is self-consistent and wrong.

**The report's conclusion — "the current H-B field-matching/edge-aliasing hypothesis is not supported on
any legitimate witness in this census" — is therefore unfounded as stated.** H-B was untested.

My J3 specification caused this. I wrote: *"unfold the two triangles about the shared edge, find which
target raw index the source raw direction actually maps to."* That **is** principal matching, and I
specified the suspect as its own oracle without noticing.

**However, H-B is now separately excluded at the live locus** by direct measurement (§3): the nearest
target index is at 23.7° with the next at 66.3° — a 42° margin, nowhere near the 45° degeneracy where
aliasing occurs. And §5 shows H-B is not needed to explain anything. **H-B is excluded on the evidence,
not on J3's authority.**

---

## 8. Normative amendment 9 to `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md`

**Amendment 4 is corrected. Measure E5's rejection is downgraded from an invariant violation to a typed
observation, and the tracing model acquires an explicit gap.**

> **AMENDMENT 9 — the cross-edge flow invariant is a continuum statement and does not hold for a
> piecewise-constant field near edge tangency.**
>
> Amendment 4 required that an edge outflowing in `X` for branch `b` must inflow in `Y` for the
> transported branch. Measured on the prescribed sphere: **144 of 1152 directed source-outflow pairs
> violate it**, and every one is a near-tangency configuration — tangency ratio median **0.0218** against
> **0.9233** for satisfying pairs. At the live locus every published term (matching, both gauges, the
> lift composition, both barycentric directions) is **independently verified correct**.
>
> **Normative consequences:**
>
> 1. **`BranchTransportFlowDisagreement` is not an invariant violation.** It is a **typed observation
>    that the discrete field grazes the shared edge**. It must not be read as an A1 defect, and no
>    production correction to matching, gauge, or flow classification may be authorized from it.
> 2. **`DESIGN.md` §4.5's tracing model is incomplete.** It does not define the continuation of a trace
>    that reaches an edge the neighbouring face's direction also exits. Closing that gap is a **`-DEFN`
>    obligation**, not a patch, and it must be closed before CP4c-0 can publish a sphere network.
> 3. **No tolerance may be introduced to classify grazing.** The tangency distributions overlap; any
>    cutoff would be a tolerance deciding topological ownership, which `DESIGN.md` §6.3 forbids. The
>    grazing case must be decided by an **exact predicate** on published authority, or by an
>    admissibility precondition that is itself exactly stated.
> 4. **A cross-stage invariant asserted on a discrete field must state its discretization
>    assumptions.** Amendment 4 did not, and asserted a continuum property. Every future invariant of
>    this shape must record whether it holds for piecewise-constant data and in what regime it degrades.
>
> **Amendment 8 stands and is reinforced**: the flow check audits inputs as well as composition. Amendment
> 9 adds that it also audits the *discretization*, and that this third failure mode is the dominant one.

---

## 9. Corrective measures — series **K**, one Code + Build turn (`M3-CP4c-0-CB7`)

**K0 — binding preconditions.**
Branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Code + Build only; compile all eight standard
targets; **execute nothing**. **No production semantics change is authorized** — §3 shows every published
term at the live locus is correct, so there is nothing in A1 to fix. Do not weaken T6 or Q8, do not edit
the sphere fixture, do not retune `kBranchTopologyTolerance`, do not introduce a tangency threshold. Do
not enter CP4c-1/2/3. The frozen 338 selector and its three hashes stay unchanged.

**K1 — publish the tangency decomposition (the measure that matters).**
Extend H1's violation record with, per disagreement: `|d_opp| / max|d|` for **both** faces as exact
rationals, the exact angle proxy between the two faces' transported directions, and the rank of the
`opp` coordinate within its face (smallest / middle / largest by magnitude). Report per witness the full
distribution for **both** the disagreeing and the agreeing populations, so the separation in §5 is
runtime-established rather than review-established. Amendment 6 applies (named `*_locus` formatters,
printable ASCII, lossless rationals). Non-gating, no credit, written rationale.

**K2 — measure what each §6 option costs.**
For the prescribed sphere, publish: how many of the 24 required traces would reach a grazing edge; at
what step; and — for the *tangential continuation* option — how many consecutive grazing edges a trace
would follow. This is the evidence the `-DEFN` needs to choose, and it is pure measurement over existing
authority.

**K3 — a genuinely independent matching oracle (retire J3's claim).**
J3 must stop being described as an aliasing test. Either (a) relabel it explicitly as a
*principal-matching implementation cross-check* and state in its own output that it cannot detect
aliasing, or (b) add a second oracle that does not minimize rotation — for example accumulating the
field's rotation around each vertex fan and comparing the total against the declared singularity index
(a **holonomy** check, which is sensitive to exactly the period-jump errors principal matching aliases).
**(b) is preferred**; (a) is the minimum.

**K4 — correct the classification strings.**
H1's decision-table classes `matching = 0 + unequal gauges` and `matching = 0 + equal gauges + lift 0`
must no longer be labelled with owners (`build_branch_transports`, `build_boundary_pairing`). §3 and §5
show both are the same near-tangency phenomenon and neither indicts those functions. Emit the tangency
class instead. A classifier string that names an innocent owner is worse than none — it routed this
cycle's report to a wrong conclusion.

**K5 — record the discretization assumption on every cross-stage invariant.**
Per Amendment 9 clause 4, annotate `BranchTransportFlowDisagreement` and any similar check with the
regime in which it holds. This is a source-comment and DEFN-table change, not behaviour.

**K6 — control-plane: fix the staged-payload transport properly.**
Two consecutive cycles have lost a run to it — TB-R5 to line-ending normalization, TB-R6 to
`zipfile.extractall` dropping mode bits. `.gitattributes` (added for K5's predecessor) addressed the
first. Now make extraction preserve modes (use `unzip`, or restore modes explicitly after `extractall`)
and state the requirement in the TB plan template so it stops recurring.

**K7 — successor turn.**
**The successor is not a CB→TB cycle that expects Q8 to close.** After CB7/TB-R7 delivers K1–K3, the next
turn is **`M3-CP4c-0-DEFN-2`** — a definition turn that closes the `DESIGN.md` §4.5 grazing gap on the
evidence K2 supplies, and amends Q8 if and only if the chosen model makes 24 traces unreachable. Freeze
that ordering now so the next cycle is not planned as a fix.

---

## 10. Falsifiable predictions

- **P1.** K1's runtime tangency distributions reproduce §5: disagreeing median ≈ **0.02**, agreeing median
  ≈ **0.92**, every disagreement below ≈ **0.21**, on the sphere. If the distributions overlap heavily,
  near-tangency is *not* the mechanism and §5 is wrong — decisive either way.
- **P2.** The same separation appears on the **torus** and **two-ring**. The torus's higher rate (13.9 %)
  corresponds to a larger near-tangent fraction, not to a different cause.
- **P3.** K2 shows the sphere's very first trace reaches a grazing edge within its first ten steps —
  G5 already reports **seven** steps to `6-8`.
- **P4.** K3(b)'s holonomy check passes on all legitimate witnesses. If it *fails* anywhere, that is a
  genuine matching defect that J3 could never have seen, and it takes priority.
- **P5.** The 338 gate, F3 and G5 stay green through K1–K6; they touch no production semantics.
- **P6.** **Q8 stays red at criterion 2**, and will remain red until the §6 model question is settled by
  a `-DEFN`. Fourth consecutive cycle in which this must be said explicitly — but for the first time the
  reason is a known contract gap rather than an unknown defect.

---

## 11. Risk register

| # | Risk | Mitigation |
|---|---|---|
| 1 | A tangency **threshold** is introduced to suppress the disagreements | **K0 prohibits it.** §5 shows the distributions overlap; a cutoff would be tolerance-as-ownership, forbidden by `DESIGN.md` §6.3 and removed twice already at cost |
| 2 | `build_branch_transports` or `build_boundary_pairing` is "fixed" | §3 verifies every term correct at the live locus. **K0 forbids production change**; K4 removes the misleading labels that invited it |
| 3 | J3's 524/524 continues to be cited as excluding H-B | §7 and **K3** correct the record. H-B is excluded on direct measurement, not on J3 |
| 4 | The grazing question is patched in a CB turn instead of settled in a `-DEFN` | **K7** freezes the ordering: measure (K1–K3), then define, then implement |
| 5 | §5 is wrong and near-tangency is not the mechanism | **P1** is the falsifier and it is cheap. The review's reproduction already matched 144 exactly, so the prior is strong |
| 6 | Q8's 24 traces prove unreachable under the chosen model | Then Q8 is amended **by the `-DEFN`, with reasons recorded** — not weakened silently in a TB turn |

---

## 12. Review record

- **R1 (evidence):** verified independently; all digests match, all three selector hashes recomputed
  locally. Both TB-R5-review predictions (fan artifact 2/1; corrected population 388/194) confirmed to
  the digit.
- **R2 (live-Q8 owner):** **not** `build_branch_transports`. Every published term — matching, both
  gauges, the lift composition, both barycentric directions — independently verified **correct** from the
  fixture. The decision-table row it satisfied is withdrawn as a diagnosis.
- **R3 (lowest common invariant):** **one class, not two.** The unequal-gauge and equal-gauge/lift-0
  populations are the same **near-tangency** phenomenon. Established by an independent reproduction that
  matched the runtime's 144 exactly, with a 42× median separation in tangency ratio.
- **R4 (contract):** **Amendment 4 / measure E5 is unsound for a piecewise-constant field.** Amendment 9
  corrects it and records that `DESIGN.md` §4.5's tracing model does not define a grazing continuation.
- **Reviewer errors owned:** the TB-R4 "geometrically impossible" claim and its magnitude-versus-ratio
  reasoning (§4); the J3 specification, which named principal matching as its own oracle (§7); and the
  TB-R5 decision-table rows that attached owners to what is really one geometric regime (§3, K4).
- **H-B:** excluded **at the live locus** by direct measurement (23.7° vs 66.3°), and unnecessary as an
  explanation — but **not** excluded by J3, whose method cannot see aliasing.
- **Successor:** `M3-CP4c-0-CB7`, measures **K0–K7**, Code + Build, **diagnostic-only**; then
  `M3-CP4c-0-DEFN-2` to close the §4.5 grazing gap.
- **Stable accounting:** unchanged at **42 events / 14 categories / 28 recurrences**; produced-witness
  debt **5**. `M3-CP4c0-TB-R4-CAND-01`'s root cause is now **identified**: a contract/model gap, not an
  implementation defect.
- **Mutation statement:** this review executed no runtime, build or benchmark, and changed no product
  source, test source, fixture, selector, or build configuration. Fixtures and test source were read and
  arithmetic performed on their contents; nothing was modified. Its only writes are to durable
  documentation under `.agents/Directional/`.
