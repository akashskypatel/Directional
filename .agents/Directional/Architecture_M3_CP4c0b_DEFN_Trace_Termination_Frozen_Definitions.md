# Architecture M3 CP4c-0b — Frozen Definitions for Trace Termination

**Turn:** `M3-CP4c-0b-DEFN`
**Type:** Independent definition / review / planning only — no product, test, fixture, selector, build, package, or runtime mutation
**Status:** **FROZEN.** §3–§10 are normative for `M3-CP4c-0b` and may change only by an explicit plan update.
**Origin:** `M3-CP4c-0-TB-R8-REVIEW-PLAN` + `M3-CP4c-0-CB9` §7 — the dependency inversion, resolved here by splitting the checkpoint rather than by reordering or re-scoping alone.
**Incoming accepted authority:** M3-CP4ab **316/316**. CP4c-0 gate **346**, SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`.

---

## 0. What this checkpoint is, and what CP4c-0 keeps

CP4c-0 was carrying two unrelated obligations under one gate: **how a trace continues**, and **how a trace stops**. The first is finished and proved. The second was never scoped, was silently delegated to a citation whose assumptions do not hold here (§2), and is what blocked TB-R8.

They are split.

| | **CP4c-0** — continuation | **CP4c-0b** — termination |
|---|---|---|
| Owns | the exact minimum-ratio continuation rule, the `FieldBoundaryPoint` authority, the grazing classification and edge transit, the vertex dispatch, and the deterministic cost guards | trace/trace contact, the arrival-priority order, the contact node and event, and the retirement of the CB9 stand-in guards |
| Gate | **346**, unchanged | its own selector, frozen by `M3-CP4c-0b-CB1` as `346 + n` |
| Q8 criteria | **1, 4, 5** | **2** (24-trace sphere network) and **3** (terminal `TraceIntersection`) |
| Status | closes on a green TB-R9 | opens now |

**Q8 criteria 2 and 3 are moved, not weakened, and not deleted.** They move together because they are one piece of work: the six circulating traces are simultaneously what blocks criterion 2 and what will satisfy criterion 3 (§1.3). Splitting them across checkpoints is what created the inversion. Amendment 11 to
`Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md` records the move.

**Nothing green is held hostage.** CP4c-0's 346 identities prove the continuation contract and can close on their own evidence. `ResolvedBranchCorrection.GrazingTraceSegmentsPublishExactEndpointSupport`, made non-gating by CB9's N7 because it requires a published sphere network, **becomes gating again in CP4c-0b's selector** — that is its correct home, not a permanent exemption.

---

## 1. The evidence this definition consumes

All of it was re-derived from the committed fixtures with no product code, and it is recorded in
`Architecture_M3_CP4c0_TB_R8_Review_And_CB9_Corrective_Record.md`. Restated here because it decides §4 and §5.

### 1.1 Six traces do not terminate, and it is a limit cycle

Of 48 candidate ports on the prescribed sphere (a superset of production's 24), **42 terminate at a singularity** in ≤32 steps; **6 circulate** a closed 32-state circuit indefinitely. The first-return map around that circuit is **exactly affine and contracting**, `a = 0.9999999999999996` constant across every lap, with an exact fixed point at `p* ≈ 0.970180376877834` inside the interval. The trace spirals asymptotically onto a closed orbit. It never arrives and never repeats.

### 1.2 Self-contact cannot be the stopping rule

Measured over 420 steps: **2,548 co-face segment pairs, zero proper crossings, zero endpoint touches, zero collinear overlaps.**

That is structural, not incidental. A1 publishes **one constant direction per `(face, branch)`**, so two visits to the same face on the same branch lay down **parallel** segments, which cannot cross. The runaway's circuit is 32 states on **32 distinct faces, each on exactly one branch** — there is no opportunity for self-contact anywhere in it.

Self-contact is still included in the contact predicate (§3.2) because it costs nothing and the motorcycle model requires it. It is not expected to fire.

### 1.3 Cross-trace contact fires immediately

Every circulating trace, tested against every other trace with proper transversal crossings only and shared singularity origins excluded:

| runaway seed | proper crossings with other traces (first ~100 steps) | first crossing |
|---|---:|---|
| v0 | 140 | **own step 0** |
| v8 | 139 | **own step 0** |
| v21 | 142 | **own step 0** |
| v34 | 140 | **own step 0** |
| v45 | 141 | **own step 0** |
| v49 | 146 | **own step 0** |

Every crossing is between **perpendicular** branch pairs — `(0,1)`, `(0,3)`, `(1,2)`, `(2,3)` — and never `(0,2)` or `(1,3)`. That is exactly right: `b` and `b+2` are the same line traversed oppositely and cannot cross transversally; `b` and `b±1` are the two families whose crossings *are* the quad structure.

**Consequence for the design:** termination is robust to the priority order. With more than one available crossing per step and the first available at step 0, **every** arrival order terminates every circulating trace inside its first lap. The priority metric decides *which* partition, never *whether* one exists. §5 rests on this.

### 1.4 A length budget cannot separate the populations

| | arc length | × bbox diagonal (3.4641) |
|---|---:|---:|
| shortest legitimate trace | 1.2296 | 0.355 |
| **longest legitimate trace** | **5.0175** | **1.448** |
| **one lap of a circulating trace** | **5.0175** | **1.448** |

Separation ratio **1.000** — zero margin. The longest correctly-terminating trace and one lap of a never-terminating trace are the same length to four decimal places, because they follow the same route; one lands on a singular vertex and the other does not. **Length carries no information about whether a trace will terminate.** A mesh-derived length cutoff is therefore excluded as a termination rule, and separately excluded because a bounding box is not rotation-invariant, because arc length is not exactly comparable, and because truncation leaves a dangling end that bounds no region (§7.2 disc validity).

Length remains legitimate as a **published diagnostic** and as a **disposition/quadrangulability signal** (§8).

---

## 2. A correction to `DESIGN.md` §4.6's justification

§4.6 cites Eppstein et al. for the claim that crash-on-contact removes non-terminating traces *structurally*, and concludes the architecture needs no limit-cycle handling.

**That guarantee is inherited from a setting we are not in.** The motorcycle graph takes an **existing quadrilateral mesh**; motorcycles travel along quad-mesh **edge chains**, straight through regular vertices. That is a walk on a finite graph where every step consumes an edge, so non-termination is impossible by counting. A2a is one stage earlier: it traces on a **triangle** mesh through a piecewise-constant field, and its state carries an **exact position on an edge**. That is a one-dimensional dynamical system, and §1.1 exhibits the limit cycle the finite-graph argument says cannot exist.

The conclusion still holds here — §1.3 shows the perpendicular family crosses every runaway at step 0 — but it holds for a **different reason** than §4.6 states, and the reason is a property of the *field*, not of the algorithm. §9 amends the text accordingly, and §8 records what happens on a field where it does not hold.

---

## 3. The contact contract, frozen

### 3.1 What a trace is, geometrically

An ordered sequence of straight segments in barycentric coordinates, one per visited `(face, branch)`, plus the edge transits introduced by DEFN-2, which lie on an edge. Endpoints are exact `FieldBoundaryPoint`s. Nothing here changes that representation.

### 3.2 The contact predicate — fixed, and not a design choice

Two segments in the same face are in contact iff they **properly cross**: the four orientation determinants are all non-zero and the two sign pairs disagree. Evaluated in **exact rational barycentric arithmetic**, using two of the three coordinates as an affine chart. This is the same arithmetic class as the continuation rule; **no new number type and no tolerance**.

The tested set for a trace's current segment is every segment already laid in that face by **any trace, including the trace itself**.

**Excluded, each for a stated reason:**

| Configuration | Treatment |
|---|---|
| Two segments sharing their origin at a singularity port | **Not contact.** All ports at a cone emanate from one vertex; that shared vertex is already a network node. |
| Endpoint touch that is not a proper crossing | **Not contact** in the frozen rule, but **published as a typed observation** with its locus. Measured incidence on the sphere: **zero**. If a witness produces one, that is review evidence, not a licence to widen the predicate. |
| Collinear overlap (only possible between branches `b` and `b+2`, which are the same line) | Same as above — typed observation, fail-closed, measured incidence **zero**. |

The last two rows exist because the frozen predicate is deliberately the *narrow* one. Widening it later requires evidence that a witness needs it.

### 3.3 What contact produces

The crashing trace terminates at the crossing point. That point becomes a **network 0-cell** (`NetworkNodeId`, allocated by A2a exactly as CP4ab Amendment 11 froze) carrying a `FieldAlignedNetworkEventKind::TraceIntersection` event, with the crashing trace incident as `Terminal` and the struck trace incident as `Interior`.

**The struck trace is not split.** Its segment sequence is unchanged; the node records an interior incidence on it. A2b's arc derivation already consumes node incidences and needs no new datum beyond the node.

`FieldAlignedCandidateTrace` gains `terminalContact` — the `FieldBoundaryPoint`-equivalent interior point plus the struck trace and segment index — alongside the existing `terminalSingularity` and `terminalBarrier`. **Exactly one of the three terminal kinds is set on a completed trace**, and that exhaustivity must be an authored identity.

### 3.4 Termination is now total, and that is the checkpoint's claim

A completed trace ends in exactly one of: a singularity (T3), a hard rail (mandatory edge), a boundary, or a trace contact. **A trace that ends any other way is a typed rejection.** The CB9 stand-in guards remain as fail-closed backstops (§6) but must never fire on a witness that reaches A2a.

---

## 4. The arrival-priority decision

### 4.1 Why this is a choice at all

When two traces would cross, the one that arrives **later** crashes. That requires a total order on arrivals. The order does not affect validity — §1.3 — only which valid partition results. Gunpinar, Moriguchi, Suzuki and Ohtake (*Feature-aware partitions from the motorcycle graph*, CAD 47, 2014) vary the particle speed deliberately to steer partition boundaries, which is published precedent that the priority function is a design parameter rather than a fixed part of the algorithm.

### 4.2 The candidates, assessed

| Option | Exactly comparable | Intrinsic | Quality | Cost |
|---|---|---|---|---|
| **Arc length, exact** | **No** — comparing two sums of *k* distinct radicals is exponential in *k*, and *k* is the segment count (32 on this witness) | yes | canonical | infeasible |
| **`ArcLengthFiltered`** — double arc length with a certified running error bound; inconclusive comparisons resolve to mutual termination (§4.4) | effectively; deterministic under fixed-order IEEE | yes | canonical in every case the bound resolves | **cheap — comparisons happen per event, not per step** |
| **`StepCount`** — faces crossed | yes, integer | rotation- and scale-invariant | **poor**: mesh-density dependent, so a trace through a finely tessellated region loses for reasons unrelated to geometry; also very coarse, so ties dominate | trivial |
| **`BarycentricTime`** — accumulated exact `t` | yes, already computed | **no**: `t`'s rate depends on the per-face direction magnitude, which carries no semantics, so re-normalising the input field changes the topology | free |
| **`TraceSeniority`** — sequential tracing in port order | yes | no | **worst**: the first trace runs its full length and later ones are chopped, visibly breaking symmetry on symmetric input | trivial |

### 4.3 Frozen default: `ArcLengthFiltered`

**Recommended and frozen as the production default**, on the following grounds:

- it is the canonical unit-speed motorcycle graph, which is what `DESIGN.md` §4.6 already commits the architecture to;
- it is the only candidate that is intrinsic — invariant to mesh density, to field normalisation, and to rigid motion;
- the cost objection was **overstated in earlier turns and is withdrawn**: arc-length comparison happens at *events*, not at every step, and with crash-on-contact each trace crashes once. On the sphere that is tens of comparisons, not thousands;
- exact comparison is excluded on **complexity**, not on cost, so a certified filter is the realistic exact-enough form.

### 4.4 The error bound, stated precisely so it is not a tolerance

Accumulated arc length is computed in `double`. Each segment length carries at most half an ulp from the square root plus the rounding of the squared-difference sum; the running total of `n` segments therefore carries a **derived** bound `B(L, n)`, computed forward alongside the value. Two arrivals `L₁ ± B₁` and `L₂ ± B₂` compare **conclusively** iff `|L₁ − L₂| > B₁ + B₂`.

- **Conclusive** → the earlier arrival passes, the later crashes.
- **Inconclusive** → **neither has priority, so both terminate at the crossing point**, producing one node with two terminal incidences.

**This is a derived bound, never a tuned epsilon**, and it decides only *whether the order is knowable*, never *what the order is*. The inconclusive branch has a canonical answer that requires no arbitrary choice. Three requirements make it auditable:

1. `B` must be **computed**, not chosen; a literal epsilon anywhere in this path is a stop condition.
2. The **inconclusive rate per witness** must be published in a non-gating census every TB.
3. If the rate is material on any witness, the design returns to review rather than the bound being widened.

### 4.5 Ties, and why they are common rather than rare

Exact ties are **systematic on symmetric inputs**. The prescribed sphere's singularities are the eight corners of an inscribed cube (measured: `(±1, ±1, ±1)/√3`), so many traces have exactly equal arc lengths by symmetry. A tie-break chosen arbitrarily would therefore decide the whole partition on precisely the inputs used to judge quality.

Ties split into two cases and **neither needs an arbitrary rule**:

- **Same arrival, different points** — the two events do not interact, so processing order between them cannot change the result. No rule required. This is most of what looks like a tie-break problem.
- **Same arrival, same point** — **both traces terminate there**, one node, symmetric outcome. Canonical: independent of vertex numbering, coordinate frame, and iteration order.

**Explicitly rejected tie-breaks, each with its defect:** port or trace ID order (depends on vertex numbering, so re-exporting the same mesh changes the partition); lexicographic world coordinates (frame-dependent, so rotating the model flips it); branch index (meaningless across faces — `FieldBranch` is per-face gauged, Amendment 7); typed rejection on tie (rejects symmetric models, including this checkpoint's own primary witness).

### 4.6 The alternatives harness — how future comparison is preserved without a knob

```
enum class FieldTraceArrivalPriority { ArcLengthFiltered, StepCount, BarycentricTime, TraceSeniority };
```

**`ArcLengthFiltered` is the production default and the only value the production entry path can produce.** The alternatives exist so performance and quality can be compared on future inputs, and they are constrained so they can never become a second authority:

1. The production path — `remesh_from_raw_cross_field` through `FieldAlignedCurveNetwork::make` — **takes no priority argument**. It is a fixed call to the default.
2. Alternatives are reachable only through a separately named diagnostic entry point that the production pipeline never calls, used by non-gating census identities and by an offline render harness.
3. An authored identity asserts that the production path yields the default's result, so a future edit that plumbs a priority argument into production fails a test rather than shipping.
4. The selected priority is bound into the semantic digest, so a change of default is visible in every downstream digest rather than silent.

**Stop condition:** if any production-reachable call site can select a non-default priority, that is a second writer of network topology and the turn stops.

**Changing the default is a plan update, not a code change.** It requires a review turn consuming the render comparison, with reasons recorded — the same discipline as any other frozen contract.

---

## 5. Simultaneity — how arrivals are actually ordered

Advance all traces in **global priority order**, not one trace at a time.

- Each live trace has a next event: either its next face crossing (from the frozen continuation rule) or its earliest contact with a wall already laid in its current face.
- A global priority queue holds pending events keyed by arrival priority (§4.3).
- Pop the earliest, re-verify it is still valid against walls laid since it was queued, then apply it.
- A contact counts only if the struck segment reached the crossing point at a **strictly earlier** arrival than the crashing trace reaches it. Because events are applied in priority order, everything already recorded was laid earlier, so the test is local.

**Sequential tracing is not acceptable as the production algorithm** — it is `TraceSeniority` under another name, and §4.2 records why. It remains available in the harness as the baseline that shows what the priority metric buys.

---

## 6. Retiring the CB9 stand-in guards

N1 (position-free combinatorial recurrence, allowance 2), N2 (exact-magnitude policy) and N4 (envelope step budget) were fail-closed stand-ins for a termination guarantee that did not exist. They stay, and their status changes:

- **They must not fire on any witness that reaches A2a.** An identity asserts this per witness. A firing is a semantic red, not a guard doing its job.
- **N1's allowance is calibrated on one witness** — every terminating sphere trace enters each `(face, branch, incoming carrier)` exactly once, and the allowance is twice that. **A mesh where a legitimate separatrix winds several times before reaching a singularity would trip it.** That is the known false-positive risk and it is why N1 cannot be the termination rule.
- **N1 is retired only when** an identity proves no witness in the matrix reaches it, and the retirement is a plan update recording the evidence. Until then it stays as a backstop with its own non-gating incidence census.

---

## 7. Re-proof surface

| Checkpoint | Affected | Kind | Action |
|---|---|---|---|
| **M3-CP1 / CP2 / CP2b** | nothing — A1 is untouched | no-op | re-run; expect green |
| **M3-CP3a** | `FieldAlignedCandidateTrace` gains `terminalContact` | shape + digest | re-run; accepted traces terminate at singularities or rails and gain no contact, so content is unchanged |
| **M3-CP3b** | `TraceIntersection` **becomes producible** for the first time | shape + digest | **Every accepted identity asserting terminal-kind or event-kind exhaustivity must be re-read.** A newly producible kind invalidates a closed-world assumption — the same hazard DEFN-1 §6.4 recorded for `SingularityTermination`. |
| **M3-CP4ab** | `network_digest`; node count on witnesses that now produce contacts | digest, plus **genuine node-count change on the sphere** | the sphere is not in the accepted 316; accepted witnesses gain no contacts and must stay byte-identical |
| **M3-CP4c-0 (346)** | continuation identities untouched; N1/N2 incidence identities gain a "must not fire" assertion | additive | re-run; expect green |

**The claim that makes this safe:** accepted witnesses are a disc (two-ring) and a fan, whose traces terminate on hard rails or singularities and were measured never to reach a grazing edge. If an accepted trace acquires a contact terminus, §7's assumption is false and the turn **stops** rather than the expectation being edited.

---

## 8. When the field itself is the problem

§1.3 shows the perpendicular family saves us on this witness. It is not a theorem. On a field with a **minimal component** — an irrational winding region — two leaves of the same family never meet, and a trace could circulate without ever contacting anything.

`DESIGN.md` §4.10 and §7.5 already own this: **field quadrangulability is a checkable precondition**, and §2.2's disposition ladder is graded rather than binary. Frozen consequence:

- a trace that reaches N1 or N2 **after** crash-on-contact exists is evidence that the field is not quadrangulable in that region;
- that evidence feeds a **disposition degradation**, never a topological decision;
- arc length relative to an intrinsic mesh scale is a legitimate input to that judgement, and is published per trace as a diagnostic (§1.4).

This is the correct home for the length-budget instinct, and it is the only one.

---

## 9. Amendments

> **AMENDMENT 11 to `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md` §11 — Q8 is split with the checkpoint.**
> Criteria **1, 4 and 5** remain binding on CP4c-0 and are unchanged. Criteria **2** (the prescribed sphere publishes a 24-trace network) and **3** (at least one terminal `TraceIntersection`) **move to `M3-CP4c-0b`**, together, because they are one piece of work: the circulating traces are simultaneously what blocks 2 and what satisfies 3. Neither criterion is weakened, relabelled, or satisfied by anything other than the outcome it names. CP4c-0 closes on its own 346 identities and criteria 1, 4, 5.

> **AMENDMENT to `DESIGN.md` §4.6 — the termination guarantee is conditional and its condition is now named.**
> The motorcycle graph's structural termination argument assumes motorcycles walking edge chains of an existing quad mesh, where every step consumes an edge. A2a traces a piecewise-constant field on a triangle mesh with exact positions in face interiors, which is a one-dimensional dynamical system and admits limit cycles — one is exhibited on the prescribed sphere with an exactly contracting first-return map. Crash-on-contact still terminates every trace on that witness, but because the **perpendicular branch family** crosses every circulating trace, not because the state space is finite. On a field with a minimal component that argument fails, and the outcome is a quadrangulability judgement under §4.10 and §7.5, never a silent truncation.

---

## 10. The bounded next Code + Build turn — measures **P**

**`M3-CP4c-0b-CB1`.** Code + Build only; **runtime forbidden**; compile all eight standard targets.

**Operator prerequisite, outside the turn:** GMP is linkable in the current CMake configuration but is not fetched automatically on Linux. Installing it and passing the library root to CMake makes every exact path here substantially cheaper and would have prevented the 853-second TB-R8. **The turn must record which backend the package was built against**, because it changes the cost profile of every measurement below and must not be silently different between CB and TB.

### P0 — binding preconditions

Stop and return to review if any fails.

- **P0.1** CP4c-0 is green at **346** with hash `20d3b0b1...`, or the split is premature.
- **P0.2** `FieldAlignedCandidateTrace` still has exactly two terminal kinds (`terminalSingularity`, `terminalBarrier`) and no contact datum.
- **P0.3** `FieldAlignedNetworkEventKind::TraceIntersection` is still declared and produced by nothing.
- **P0.4** N1, N2 and N4 are present and unmodified.
- **P0.5** The exact-arithmetic backend in use is recorded (GMP or the fallback `BigInteger`).

### P1 — the contact predicate

Implement §3.2 in exact barycentric arithmetic. Author its falsifiers: a proper crossing detected; a shared singularity origin **not** detected; an endpoint touch and a collinear overlap each published as typed observations rather than contacts.

### P2 — arrival priority and the certified bound

Implement `ArcLengthFiltered` with the §4.4 forward error bound **computed alongside the value**. A literal epsilon anywhere in this path is a stop condition. Publish the bound and the conclusive/inconclusive verdict in the diagnostic.

### P3 — the priority harness

Implement the §4.6 enum with `ArcLengthFiltered` as the production default, the alternatives reachable only from the diagnostic entry point, and the identity asserting the production path cannot select another value.

### P4 — simultaneity

Implement §5's global priority queue. **Do not implement sequential tracing as the production path.**

### P5 — the contact terminus

Implement §3.3: the node, the `TraceIntersection` event with its two incidence roles, `terminalContact` on the trace, and the identity asserting exactly one terminal kind is set on every completed trace.

### P6 — guard demotion

Add the per-witness identity asserting N1, N2 and N4 do not fire on any witness reaching A2a, plus the non-gating incidence census.

### P7 — censuses, all non-gating

Per witness, publish: per-trace terminal kind, step count, arc length, maximum exact magnitude; contact count and first-contact locus; the priority-comparison conclusive/inconclusive rate; N1/N2/N4 incidence; and, under the harness, the same per-trace summary for each alternative priority so the render comparison has data.

### P8 — migration

Re-run the accepted **316** and CP4c-0's **346** unchanged. §7 predicts both green with no expectation edited. Report any red with its identity and first typed rejection and **stop**.

### P9 — prohibited

No A1 change. No new tolerance. No length-based termination. No sequential tracing in production. No priority argument on any production entry point. No change to the CP4c-1 **318** selector. No runtime execution.

### Falsifiable predictions for `M3-CP4c-0b-TB`

1. Accepted **316/316** and CP4c-0 **346/346**, zero expectation edits.
2. The prescribed sphere publishes a network of **24 traces** — Q8 criterion 2.
3. At least one trace terminates on a `TraceIntersection` — Q8 criterion 3. Predicted strongly: all six circulating traces have a crossing available at **step 0**.
4. **42 of the 48 candidate ports still terminate at a singularity**, unchanged from the pre-contact measurement; only the 6 circulating ones acquire a contact terminus. A different split is evidence about the port-selection reconstruction and routes to review.
5. **N1, N2 and N4 do not fire on any witness.**
6. Two-ring and fan traces acquire **no** contact terminus and their digests are byte-identical.

Prediction 5 is the one that matters. **If a guard still fires after crash-on-contact exists, the termination contract is incomplete and the turn returns to review** — it does not get the allowance raised.

---

## 11. Stop conditions

- a tolerance, a literal epsilon, or a tuned constant enters the contact predicate or the priority comparison;
- a production-reachable call site can select a non-default priority;
- sequential tracing is used as the production algorithm;
- an accepted witness acquires a contact terminus;
- an accepted identity requires an expectation edit;
- N1, N2 or N4 fires on a witness that reaches A2a and the response proposed is to widen it;
- the priority comparison's inconclusive rate is material on any witness and the response proposed is to widen the bound;
- trace length is used to terminate a trace rather than to inform a disposition.

---

## 12. Accounting and exact successor

- accepted runtime authority: **M3 CP4ab 316/316**
- CP4c-0 gate: **346**, `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`; closes on a green `M3-CP4c-0-TB-R9` against criteria 1, 4, 5
- CP4c-0b gate: frozen by `M3-CP4c-0b-CB1` as `346 + n`; owns Q8 criteria 2 and 3
- CP4c-1 required selector: **318**, unchanged; it no longer owns re-homed criterion 3, which belongs to CP4c-0b
- stable regression accounting: **42 / 14 / 28**; produced-witness debt **5**
- `M3-CP4c0-TB-R8-CAND-01` transfers to **CP4c-0b** and is resolved by a green prediction 5

**Exact next: `M3-CP4c-0-TB-R9`** on the 346 selector to close CP4c-0, then **`M3-CP4c-0b-CB1`** under P0–P9. The two are independent and TB-R9 does not block CB1's authoring.
