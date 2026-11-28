# Adversarial Architecture Review — Re-evaluation Under a Production Lens

## Status

**RE-EVALUATION COMPLETE / FIVE OF SIX REJECTIONS PARTIALLY OR WHOLLY REVERSED / AMENDMENTS 20 AND 21 DECLARED /
ROADMAP WITNESS-COVERAGE GAP OPENED / CP4c-3 WORK UNCHANGED**

`M3-CP4c-3-TB5-REV` §9 adjudicated a user-supplied adversarial architecture review and rejected five of its eight
items. The user's challenge to that adjudication is **correct**, and this record re-opens it.

The challenge: those rejections were grounded in *measurements of specific fixtures*, and the fixtures are simple,
non-degenerate meshes that cannot expose the edge cases the proposals exist to solve. The goal is a **generalized
production-ready implementation**, not a fixture-specific one.

Review and planning only: nothing executed, compiled, packaged or benchmarked, and **no product, test, fixture,
selector or build-logic byte changed**. **CP4c-3's measures AU0–AU9 are unchanged** and nothing here is pulled into
that work.

---

## 1. The measurement that changes the assessment

Computed directly from the committed fixtures:

| fixture | V / F | min area | max area | **area ratio** | **max aspect ratio** | **valence range** |
|---|---|---|---|---|---|---|
| `mechanical_feature` | 152 / 300 | 0.0431 | 0.1027 | **2.38** | **2.67** | 4–6 |
| `sphere_prescribed` | 98 / 192 | 0.0333 | 0.1054 | **3.17** | **1.72** | 4–6 |
| `torus` | 72 / 144 | 0.1482 | 0.3035 | **2.05** | **2.14** | **6 only** |

For comparison, production inputs — CAD tessellations, scan reconstructions, decimated assets — routinely carry
area ratios of `10⁶`+ and aspect ratios in the hundreds or thousands, with valences from 3 to 20+.

**Every witness this project has ever run is a near-uniform, sliver-free, low-valence mesh of at most 152
vertices.** Add what the records establish about their fields and topology:

- **No negative-index singularity has ever been exercised.** The mechanical witness has 8 prescribed `+1`
  singularities (CB3 census); the prescribed sphere has 8 index-¼ singularities at cube corners, all `+1`; the torus
  has **zero**. A `-1` singularity has different valence, a different port count and a different fan structure, and
  the pipeline has never seen one.
- **Genus ≤ 1.** Handle generators exercised only at genus 1.
- **Fields are synthetic or pre-solved and always admissible.** No witness has ever presented a field the atlas
  should reject for global inconsistency, and the one deliberately synthetic field (`make_zero_transport_field`) was
  itself found inadmissible at ordinal 370.
- **No boundary-truncated separatrix.** The only bounded witness is the two-ring disc, and no index deficit arising
  from a separatrix hitting a boundary has ever been produced.

**This is not a criticism of the fixtures** — they were built to isolate specific contracts and they did that well.
It is a statement about what conclusions they can support. A rejection of the form *"this proposal is unnecessary
because the measured evidence shows no such case"* is invalid when the evidence base is structurally incapable of
producing that case.

## 2. The error in the original adjudication, named

I conflated two claims:

- **Claim A — "this proposal is wrong as a diagnosis of the *currently measured* failure."**
- **Claim B — "this proposal is wrong as a *general architectural* solution for production."**

Claim A was sound in every instance and remains so: the review did diagnose several specific failures from their
names rather than their causes, and TB4-REV's partition proof does refute the vertex-30 ambiguity reading. But I
extended each A into a B, and **B does not follow from A on this evidence base.** That is the sixth instance of the
scope-narrowing pattern this project has recorded against my own measures — by symbol, by enum, by stage, by
mechanism enumeration, by operand, and now **by witness domain**. Recorded as `LESSONS.md` **74**.

## 3. Re-adjudication under a production lens

### 3.1 #2 Repair / "delta authority" — **REVERSED IN SUBSTANCE, RELOCATED IN MECHANISM**

*Original rejection:* the premise misreads the sphere's pre-cut `χ = 6`, and composing `(stage output + later-stage
delta)` creates two authorities for one datum (`RP-01`, five instances).

*What survives:* the `RP-01` objection is about **mechanism**, not about **need**, and I used it to dismiss the
need. In production the pipeline will receive slivers, near-duplicate vertices, T-junctions, tiny disconnected
components and self-intersections. A pipeline that aborts globally on one localized degeneracy is not
production-ready — and the project **already agrees**, because `DESIGN.md` §6.7's disposition ladder D0–D4 exists
precisely to express graded degradation. The ladder has never had a producer that can put a run on it.

*Corrected position:* **the need is real and the mechanism belongs before A0, not between stages.** A
**conditioning stage** takes the raw input and either emits a **new immutable source product** — carrying its own
digest and a certified correspondence back to the raw input — or fails with a typed inadmissibility reason. Every
downstream exactness guarantee is then *relative to the conditioned product*. That gives production the healing the
review asks for, with **one writer per product**, a complete audit trail, and no composed working state. Declared as
**Amendment 20**.

### 3.2 #3 Bifurcated taxonomy and regularization policy — **REVERSED IN GENERAL, HELD AT THE ONE LOCUS**

*Original rejection:* TB4-REV *proves* the vertex sectors are an exact partition, so the vertex-30 multiplicity is
an artifact of testing one representative per cell, not a geometric ambiguity; a lexicographic tie-break would
hard-code a wrong continuation.

*What survives:* that proof, exactly, and only for that locus. **It says nothing about whether genuine exact ties
occur in production — and the fixture evidence is actively misleading here.** These meshes are irregular, so exact
ties are measure-zero. Production inputs are frequently the opposite: CAD tessellations, grid-aligned and extruded
geometry, and mirror-symmetric models produce **exact** ties routinely. The project already implements deterministic
tie-breaking where ties are real — `field_aligned_compare_arrivals` and mutual termination on an exact tie
(CP4c-0b) — but has **never stated it as architecture**: there is no taxonomy, no interface, no enumeration of which
degeneracies are regularizable, and no requirement that a regularization be recorded in the certificate.

*Corrected position:* **adopt the bifurcation and the policy interface**, with three constraints that the original
proposal lacks: a regularization must be **deterministic and exact**; it must be **recorded in the certificate** and
mapped to a disposition tier, so a regularized run is never silently indistinguishable from a clean one; and it is
**prohibited where a partition already decides** — the vertex-sector election keeps its prohibition, because a tie
there is not a tie. Declared as **Amendment 21**.

### 3.3 #4 Input noise and "thickened" predicates — **CONCERN ADOPTED, MECHANISM STILL REJECTED, AND A THIRD CASE CONCEDED**

*Original rejection:* an epsilon tube relocates the discontinuity to the tube boundary and reintroduces a tuning
constant. **That objection stands** — a predicate that can return a different answer than the exact one is not a
filter, and TB5 is the empirical case against relaxing exactness mid-pipeline.

*What I missed:* two things, both invisible on these fixtures.

1. **Sliver geometry makes an exact predicate exactly answer a meaningless question.** A vertex sector of angular
   width `1e-12` is exactly a sector; the exact predicate will correctly place a direction inside it; and no trace
   should meaningfully continue there. With max aspect ratio 2.67 across every witness, this project has never seen
   one. This is a real production failure mode and neither exactness nor a tube addresses it — **conditioning
   does**, by refusing or repairing the sliver at the boundary (Amendment 20).
2. **The pipeline has no contract for input uncertainty.** The field comes from a floating-point solver, so the
   *premise* of every exact decision carries noise. The sound answer is not a tube but an explicit contract: certify
   that the topological output is stable within the input's declared uncertainty, or emit a typed
   `InputConditioningRequired`. That is stronger and more auditable than a tube, and it is genuinely responsive.

*Corrected position:* certified interval/adaptive filters remain the only admissible speed mechanism (Amendment
18); sliver handling and uncertainty declaration move to the conditioning stage; the perturbation witness (S6) is
promoted from "stability measurement" to **the acceptance evidence for the conditioning contract**.

### 3.4 #6 Index-versus-geometry reconciliation — **REVERSED IN GENERAL, "PHANTOM PORTS" STILL REJECTED**

*Original rejection:* `MissingSingularityBranchTransport` was a barrier-transport demand, not a missing branch; the
census found all 8 singularities; Amendment 16/P2 already answers the real phenomenon.

*What survives:* the diagnosis rejection, fully. **What does not:** my supporting argument was *"Poincaré–Hopf
closes with 8 × (+1), so no others can exist"* — which is a fact about **the mechanical witness** that I used to
dismiss a claim about **production**. That is the fixture-specific reasoning the challenge identifies, in its
purest form.

P2 answers the **barrier** case. It says nothing about a separatrix truncated by a **boundary**, two separatrices
that **merge**, or a **negative-index** singularity — and the pipeline has exercised none of them, because no
witness has a boundary-truncated separatrix and **not one witness has a negative-index singularity**.

*Corrected position:* injecting fictitious topology ("phantom ports") stays **prohibited** — it violates *derived,
not assumed*. But the pipeline needs a **typed index-deficit reconciliation contract**: when discovery yields fewer
branches than the index requires, fail closed with a typed error naming the deficit and its cause, and define which
disposition tier the run lands on. Scheduled under Amendment 21's taxonomy, with witnesses in §4.

### 3.5 #8 Holonomy ILP — **MECHANISM STILL OUT OF SCOPE, CONSEQUENCE ADOPTED**

*Original rejection:* the atlas does not choose branch transitions greedily — it ingests them from the input field's
`matching`/`effort` and **verifies** global consistency (cycle basis, exact lifts, `interiorIndexSum == 4χ`,
per-cycle `CycleTransportMismatch`). The ILP the review describes is field *generation*, upstream of this pipeline.

*That remains correct*, and I would not move the solver inside. **But the consequence I failed to draw is the
review's real point:** because the pipeline only verifies, it will **reject** any input field whose matching is
globally inconsistent — and production fields from floating-point solvers frequently are, especially at higher
genus. Today that rejection has no defined contract, no repair path, and no conditioning. Same gap as §3.1, §3.3
and §3.4, reached from a fourth direction.

## 4. The synthesis — five rejections, one missing stage

Every reversal above converges on the same absence:

> **The pipeline has no input admissibility, conditioning or degradation contract — because every witness has been
> hand-built to be admissible.**

`remesh_from_raw_cross_field` receives `(V, F, rawField)` and proceeds directly to source authority. There is no
producer that certifies the input is admissible, no product that records what was repaired, and no path that puts a
degraded-but-usable run on the D0–D4 ladder that `DESIGN.md` §6.7 already defines. The gap was invisible for four
milestones because the witnesses are pre-conditioned by construction — and the measurements in §1 show *how*
pre-conditioned.

This is the strongest form of the adversarial review's thesis, and on this point it is **right**. Where it and I
differ is only *where the mechanism lives*: not as deltas composed between stages, not as tolerances inside
predicates, not as fictitious ports — but as **one conditioning stage at the boundary, producing an immutable
product with a certified correspondence**, after which the strict exact, single-writer, fail-closed architecture
continues unchanged and gains rather than loses force.

## 5. Amendments declared

Recorded normatively in `DESIGN.md` §7.2.1. Both are **frame-setting**: they fix the obligation and the
prohibitions and leave mechanism to the checkpoints that will measure it. Neither is in CP4c-3 scope.

**Amendment 20 — input admissibility and conditioning is a stage, not an assumption.** A0 has a predecessor. The
conditioning stage consumes the raw input and either (a) emits a **conditioned source product** — immutable, with
its own semantic digest and a **certified correspondence** to the raw input recording every repair applied — or
(b) fails with a typed inadmissibility reason. All downstream exactness and topology guarantees are stated
**relative to the conditioned product**, and the correspondence is what makes that honest rather than a loophole.
This is the *only* place where value-changing operations on input geometry or fields are permitted: quantization
onto a bounded rational lattice, sliver repair or refusal, near-duplicate merging, and field-matching
admissibility repair all belong here, applied **once, at the boundary, and recorded**. Applying any of them
mid-pipeline remains prohibited (Amendment 18) — a value silently changed between stages corrupts every downstream
guarantee, whereas a value changed once at the boundary and published is a product like any other.

**Amendment 21 — degeneracy is a typed product state, not only a failure.** The error surface bifurcates:
`FatalInadmissible` (corrupted or contradictory input that no policy can resolve) versus `RegularizableDegeneracy`
(a discrete-mesh condition with a defined, deterministic resolution). A regularization must be **exact and
deterministic**, must be **recorded in the certificate** with its locus and the policy that resolved it, and must
map the run to a **disposition tier** (`DESIGN.md` §6.7) so a regularized result is never silently
indistinguishable from a clean one. Two prohibitions: regularization may **not** be applied where a partition or
an exact predicate already decides — an apparent ambiguity there is evidence of a representation defect, and the
vertex-sector election keeps its Amendment 17 prohibition; and a regularization may never **invent** topology
("phantom ports"), only resolve a choice among admissible alternatives or fail closed with a typed deficit.

## 6. What remains rejected, and why

Held on the merits rather than on fixture evidence:

- **Lattice snapping mid-pipeline** — still prohibited, but the review's *goal* is now fully adopted with the
  operation **relocated** to the conditioning stage (Amendment 20). Quantize the input once, publish it, and
  everything downstream is exact on the conditioned product. Snapping between stages silently invalidates
  guarantees already published; snapping at the boundary is a product.
- **Composed `(stage output + later-stage delta)` working state** — still prohibited; it creates two authorities
  for one datum and makes every digest ambiguous about which composition it attests. Conditioning-before-A0
  delivers the healing without that cost.
- **A tie-break at the vertex-sector election specifically** — still prohibited. TB4-REV proves the sectors are an
  exact partition, so a "tie" there is a representation defect, not a degeneracy. Amendment 21 excludes it
  explicitly.
- **Predicates that change their answer** (epsilon tubes) — still prohibited; certified filters only (Amendment 18).
- **Phantom ports as invented topology** — still prohibited; a typed index-deficit contract replaces it.
- **Moving field generation (the holonomy ILP) inside this pipeline** — still out of scope; the pipeline verifies
  an input product it does not own.

## 7. Roadmap effect — witness coverage is now a first-class gap

The re-evaluation's operative consequence is that **the witness set, not the architecture, is the binding
constraint on production readiness**. `ROADMAP.md` gains a coverage matrix and the conditioning checkpoints; the
short form:

| gap | never exercised | scheduled |
|---|---|---|
| sliver / anisotropic geometry | max aspect 2.67 across all witnesses | conditioning witness set, M4 |
| high valence | max valence 6 | conditioning witness set, M4 |
| scale | ≤ 152 vertices | M4 scale checkpoint (with S1 swell measurement) |
| negative-index singularity | all 8 are `+1`; torus has none | M4 |
| boundary-truncated separatrix | only bounded witness is the two-ring disc | M4 |
| inadmissible input field | every field has been admissible or synthetic | conditioning contract, M4 |
| genus ≥ 2 | genus ≤ 1 | M4 (already scheduled as S5) |
| exact ties from symmetric input | fixtures are irregular; ties are measure-zero | Amendment 21 witnesses, M5 |

**None of this is CP4c-3 work.** CP4c-3 closes on the mechanical witness under **AU0–AU9** unchanged.

## 8. What this changes about how the project judges evidence

The durable lesson is not about any one proposal. It is that **"measured on the witnesses" and "true in general"
are different claims, and the fixtures' regularity is itself a measurable property that bounds which of the two a
result can support.** Every rejection in §9 of the TB5 review carried the first claim and was written as the
second.

Recorded as `LESSONS.md` **74**, with a standing requirement: a review that rejects a proposal as *unnecessary*
must state which witness would exhibit the case, and if no witness can, the correct disposition is **"unmeasured,
witness owed"** — never "rejected".
