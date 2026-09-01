# M3-CP4c-3 DEFN-R2 — Frozen Vertex-Star Continuation Definitions

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

## 0. AX0 — frozen preconditions, restated

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

## 1. AX1 — the datum, its writer, and its lifetime

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

## 2. AX2 — vertex-star geometry and what "straight continuation" means

### 2.1 The reference semantics

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

### 2.2 Why straightest geodesic and not "the developed straight line"

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

### 2.3 What is *not* redefined

A1 remains the authority on branch identity and edge transport. **`signedLift` maps a branch label; it is not, and
may not be described as, a transport of an arbitrary geometric ray.** The development above uses A0 source geometry
plus A1 fan topology. It does not consult, and may not consult, any per-face cross representative.

---

## 3. AX3 — the residual typed states

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

## 4. AX4 — the exact kernel, and the honest cost

### 4.1 The predicate class, named precisely

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

### 4.2 The chosen route

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

### 4.3 A structural exemption worth stating

The general cost above is the *worst* case, and it is worth recording that the real fixture does not pay it. At the
measured locus every sign test reduced to **rational identities alone** (§5). A producer may therefore short-circuit
on exactly-recognizable rational relations — a right angle is `u·w = 0`; two angles are complementary iff
`D₁D₂ ≥ 0` and `(D₁D₂)² = Q₁Q₂`; supplementary iff `D₁D₂ ≤ 0` and `(D₁D₂)² = Q₁Q₂` — provided each short-circuit is
an exact identity and the general path remains reachable. This is an optimization, never a semantics.

---

## 5. AX6 — the mechanical proof at vertex 30

All of the following are **EXACT** rational facts computed from the committed
`mechanical_feature.obj`. No factorization and no floating point is used in any of them.

### 5.1 The star

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

### 5.2 The cone angle is exactly `2π` — proved, not observed

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

### 5.3 The developed chart, and the finding

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

### 5.4 What this falsifies

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

## 6. AX5 — the owning contract

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

## 7. AX7 — the regression identity and its witness

### 7.1 Why vertex 30 cannot be the only witness

Vertex 30 is intrinsically flat (§5.2), so it cannot distinguish `β = α + Θ/2` from `β = α + π`. It is an excellent
falsifier of the **old** mechanism and a poor discriminator of the **new** semantics.

### 7.2 The witness to derive

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

### 7.3 Selector governance

Selector **373** stays byte-identical. Ordinal **374** may be appended — exactly one line, nothing above it moving,
respelled or removed — **only after** the witness of §7.2 is shown to **fail** under
`incomingDirection = nextPairing->direction` and to **pass** under the frozen authority. Compiling it is not
sufficient; CB8-REV was right about that and this record does not relax it. The current minimal identity
`ResolvedBranchCorrection.MinimalExactVertexTransitWitnessPublishesKnownFanState` is a channel test: it proves exact
state is published and proves nothing about which datum was tested, so it may be strengthened in place or replaced,
but it may not be admitted as-is.

---

## 8. AX8 — the audit contract

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

## 9. AX9 — successor gate

AX1–AX8 are internally complete and one exact implementation route is feasible (§4.2), with the measured locus
decidable by rational identities alone (§5.2). **One bounded Code + Build successor is authorized**, under a new
measure prefix as AX9 requires.

### `M3-CP4c-3-CB9` — measures **AY0–AY9**, Code + Build, runtime-free, GMP/GMPXX linked

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

## 10. Falsifiable predictions

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

## 11. Accounting and dispositions

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

## 12. Exact next turn

**`M3-CP4c-3-CB9`** — Code + Build, runtime-free, GMP/GMPXX linked, under **AY0–AY9**. Selector 373 stays frozen;
selector 374 is conditional on AY5. CP4c-2 remains **CLOSED / ACCEPTED at 365/365**; CP4c-3 remains **OPEN**.
