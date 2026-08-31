# M3-CP4c-3 TB4 Independent Review Record

## Status

**REVIEW COMPLETE / TB4 EXECUTION VALID / M1, M2 AND M3 ALL FALSIFIED — INCLUDING THIS REVIEWER'S LEADING
SUSPICION / CAUSE FAMILY ESTABLISHED BY PROOF / AMENDMENT 17 DECLARED / MEASURES AS0–AS9**

This record executes `Architecture_M3_CP4c3_TB4_Independent_Review_Plan.md` (**AQ0–AQ8**) against `M3-CP4c-3-TB4`
(run/job `33436492493 / 99634138202`, immutable package **73** artifact `9773591345`, semantic source
`2d22ef293363058cfdca96d01158a93d2c0200f8`, frozen gate selector **373**).

Review, definition and planning only: nothing executed, compiled, packaged or benchmarked, no gate selected or run,
and **no product, test, fixture, selector or build-logic byte changed**. Measures issued here are **AS0–AS9**.

---

## AQ0 — the evidence boundary, re-verified

Working tree byte-identical to the packaged semantic source:

```
git diff --stat 2d22ef293363058cfdca96d01158a93d2c0200f8 HEAD -- src/ include/ tests/ benchmarks/ cmake/   →  empty
```

Selector **373** recomputed from committed bytes — 373 lines, 373 unique identities,
`b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834` — with all six predecessor prefixes (355, 357,
361, 365, 367, 370) reproducing exactly.

Execution: 57-entry manifest PASS, 27 package-relative fixtures, six executables at mode `0755` **without repair**,
one identity per fresh process from ordinal 1, first-red hard stop, accepted **365 prefix green**, immutable
postflight with every mutation/build flag false. The AP6 pass ran **after** the gate verdict was fixed and carried
**zero gate credit**.

`M3-CP4c3-TB4-ORCH-01` — the first attempt's `package73-envelope-missing` sidecar-name mismatch — executed **no
Directional runtime** and is correctly closed as orchestration-only. The corrective touched a filename lookup, not
semantic bytes.

**CB5 honoured AP3 exactly.** Its entire change to `resolve_field_vertex_transit` is two additive lines populating
`error.topologyRegion` and `error.vertexArrivalMode`. **No transit behaviour changed**, which is what makes TB4's
locus comparable to TB3-R1's.

**TB4 is admissible semantic evidence and a valid semantic red at ordinal 366.**

---

## 1. AP4 did its job, and it saved a wrong fix

Stated first because it is the most important process result of the turn. At TB3-R1-REV I named **M3** — the P2
consumer mismatch at a `BarrierAbsorbed` vertex — as the leading suspicion, and wrote AP4 to forbid designing
against it until measured. TB4 measured it: the failing vertex is **30**, `barrierAbsorbed=false`,
`barrierIncident=false`.

**My leading suspicion was wrong.** So was M1. And §AQ1–AQ2 below falsify **M2** as well. All three mechanisms I
enumerated are dead, and had AP4 not existed the obvious move — reconciling A2a's port-keyed paths with A1's
singularity facts — would have been implemented against a locus where it has no purchase.

That is the fourth consecutive turn in which a "do not design before you measure" control has been the highest-value
item on the list. It is also the fourth consecutive turn in which a scope of mine turned out too narrow (§7).

---

## AQ1 — source vertex 30 is a **regular interior vertex**

Reproduced directly from the committed fixture `benchmarks/fixtures/milestone-g/mechanical_feature.obj`
(152 V / 300 F, matching the region row TB1 measured). Vertex 30 has **six** incident faces, and they form a single
**closed, consistently oriented fan**:

| step | mesh row | winding | canonical key | next | prev |
|---:|---:|---|---|---:|---:|
| 0 | 43 | `(24,32,30)` | `(24,30,32)` | 24 | 32 | ← **arrival face**, excluded on `FaceInterior` |
| 1 | 40 | `(25,24,30)` | `(24,25,30)` | 25 | 24 |
| 2 | 41 | `(25,30,31)` | `(25,30,31)` | 31 | 25 | ← **candidate A** |
| 3 | 208 | `(119,31,30)` | `(30,31,119)` | 119 | 31 | ← **candidate B** |
| 4 | 209 | `(119,30,123)` | `(30,119,123)` | 123 | 119 |
| 5 | 218 | `(123,30,32)` | `(30,32,123)` | 32 | 123 |

Each face's `prev` is the next face's `next`, and step 5 closes back on step 0 — a proper 6-face cycle with
consistent winding, no boundary and no barrier.

**Vertex 30 is not a prescribed singularity.** The four port-emitting singularities are vertices **10, 35, 47, 71**;
the other four are the `BarrierAbsorbed` set, and vertex 30 is measured `barrierAbsorbed=false` /
`barrierIncident=false`, so it is in neither group. That the census is *complete* is independently checkable:
Poincaré–Hopf requires the index numerators to sum to `4χ = 8` on this `χ = 2` witness, and eight index-`+1`
singularities account for all of it, so no further singularities of either sign can exist. Independently, A1 would
have rejected the atlas with `SingularityMismatch` at `FieldTransportAtlas.cpp:1843-1851` if any interior vertex's
computed `turningLift` disagreed with the prescribed set — and the atlas built. **Vertex 30 therefore carries
turning lift 0 and trivial branch holonomy.**

**Do not infer singularity from multiplicity** — AQ1's explicit warning — and this review does not: the
classification comes from the fixture and from Poincaré–Hopf, and it points the opposite way.

---

## AQ2 — why the cardinality is 2, proved rather than restated

### 2.1 The predicate is an exact partition of the turn

`direction_in_incident_vertex_sector` (`FieldTransportAtlas.cpp:404-426`) is
`direction[next] > 0 && direction[previous] >= 0` over `FieldExactRational`. Read as geometry, for the corner at `v`
of face `(v, next, prev)` this is exactly **the closed angular wedge between ray(v→next) and ray(v→prev), minus the
ray(v→prev)**:

- strictly interior: both components positive → passes;
- exactly on ray(v→next): `comp[next] > 0`, `comp[prev] = 0` → passes;
- exactly on ray(v→prev): `comp[next] = 0` → **fails**;
- outside: one component negative → fails.

Two fan-adjacent faces share exactly one ray, and the half-open rule assigns it to the face where it is `next`. The
six wedges therefore **tile the full turn around vertex 30 with no overlap and no gap.** There is no tolerance
anywhere in this decision.

### 2.2 The two candidates are fan-adjacent and share the ray one of them owns

Candidate A is row 41 (`next = 31`, `prev = 25`); candidate B is row 208 (`next = 119`, `prev = 31`). They are
**consecutive** in the fan and share ray(30→31), which **A owns** and **B excludes**. Both lie opposite the arrival
face — steps 2 and 3 of 6 from step 0 — which is precisely where a continuation across the vertex should land.

### 2.3 The proof

The wedges are disjoint (§2.1). A single geometric direction therefore lies in **at most one** of them, and the
boundary case is already resolved by the half-open rule in A's favour. Two candidates were nevertheless elected.

> **Therefore the two elected states were tested against two *geometrically distinct* direction vectors.**

This is a proof, not a hypothesis. It disposes of the "direction landed exactly on the shared ray" explanation
outright, and it disposes of any account that assumes one direction is being tested.

### 2.4 Distinct continuations, or one continuation aliased? — **aliased**

AQ2's sharpest question. The trace arrives at vertex 30 along one exact direction and continues along one exact
direction; there is one semantic continuation. What the algorithm elects is not that direction but, for **each**
reachable `(face, branch)` state, *that face's own representative* of the transported branch, tested against *that
face's* wedge. With trivial holonomy the six states are one per face, and their directions are the field's per-face
cross rays — which are **related by transport, not equal as vectors**, because the field is discrete and per-face.

So near a wedge boundary, face A's representative can fall inside wedge A while face B's slightly different
representative falls inside wedge B. Both elect. **The two candidates are two representations of one continuation,
not two continuations.**

### 2.5 The mechanism, named

> **M4 — election by per-cell representative.** The routine asks, for every candidate cell, *"is this cell's own
> representative of the datum admissible in this cell?"* That is not a partition test. A partition disambiguates
> **one** point among cells; it cannot disambiguate **one point per cell**. Refining the cells, tightening the
> half-open convention, or ordering the faces cannot make such a test unique, because the non-uniqueness is not in
> the cells.

M4 explains every measured fact: multiplicity at a **regular** vertex; exactly **two** candidates rather than many;
their **adjacency** in the fan; their position **opposite the arrival**; and the absence of any tolerance or
barrier involvement. It is stated as the surviving family and is **not** promoted to a finding — §AS1 measures the
two direction vectors, and if they are equal, M4 is falsified and this whole reconstruction is wrong.

A second, weaker possibility is retained rather than dismissed: **M5 — the transported branch representative is not
the trace's continuation at all.** The election never compares a candidate against the incoming direction; it only
asks whether *some* ray of that face's cross is in-sector. On that reading multiplicity is not an accident of
proximity to a boundary but the generic case, and single-candidate outcomes elsewhere have been luck. AS1's
publication distinguishes M4 from M5 as cleanly as it distinguishes both from "the directions are equal".

---

## AQ3 — M1/M2/M3 disposition, and causality relative to P2

| mechanism | disposition | basis |
|---|---|---|
| **M1** barrier truncation → zero candidates | **FALSIFIED** | measured cardinality is 2 |
| **M3** P2 consumer mismatch at a `BarrierAbsorbed` vertex | **FALSIFIED at this locus** | `barrierAbsorbed=false`, `barrierIncident=false` |
| **M2** multiplicity from singular-vertex holonomy | **FALSIFIED** | §AQ1: vertex 30 is regular, turning lift 0, trivial branch holonomy; the multiplicity has nothing to do with singularity |

**Causality relative to P2 — the defect is P2-independent; its reachability may not be.** `resolve_field_vertex_transit`
is untouched by CB3 (whose only tracing hunks are inside `canonical_field_aligned_candidate`) and untouched in
behaviour by CB5 (two additive diagnostic lines). The M4 mechanism involves no barrier, no port and no singularity,
so it would fire for any trace that reaches a vertex where two adjacent faces' representatives are both in-sector.
**But `barrierAbsorbed=false` does not prove causal independence from CB3**, exactly as AQ3 warns: P2 removed four
singularities' ports and therefore changed which traces exist and where they start, so it may well be what caused a
trace to arrive at vertex 30 at all. The correct statement is: **a pre-existing, P2-independent defect, reached by a
trace set that P2 may have changed.** Nothing in the evidence separates those, and nothing needs to — the
correction is the same either way.

---

## AQ4 — the `FaceInterior` exclusion is not implicated

On `FaceInterior` arrival the candidacy test requires `state.first != currentFace`, so the arrival face cannot be
elected. Re-derived from the producer contract this is right: a trace already *inside* face `(24,30,32)` that
reaches vertex 30 must leave that face; electing it would be a null continuation. Both published candidates are
non-arrival faces two and three steps around the fan, so the rule neither caused nor masked the multiplicity, and
**it must not be changed to alter cardinality** — AQ4's explicit prohibition, restated as AS9.

The real question AQ4 raises is the one this review hands forward: **who owns "the continuation" at a vertex?**
Today the answer is implicit and split — the fan walk owns reachability, each face owns its own direction
representative, and nothing owns the incoming ray's actual exit. That is a single-writer question, and §5 fixes the
frame without choosing the mechanism.

---

## AQ5 — the AP6 report-only pass, adjudicated with zero gate credit

**AP6 paid for itself immediately.** Three identities appended at CB2 had never executed in any run; two of them
turn out to be red for reasons nobody had measured, and one passes only in a weaker sense than its name suggests.
That is exactly the three-turn information blackout AP6 was written to end.

- **367 / 371 / 372 — RED, blocked upstream by the same vertex-30 failure.** No independent downstream cause may be
  inferred, and in particular **Amendment 15's arithmetic is *not* falsified**: ordinals 371 and 372 never reached
  their own assertions. The Euler-cut identity and barrier-exclusion contracts remain **unmeasured**, as they have
  been since they were frozen. This must not be recorded as "Amendment 15 failed".
- **368 — sphere reproduces `RotationSystemInconsistent → TraceEventPositionInvalid` at trace 2 / event 30.**
  **AL4 remains binding**; no sphere correction is designed here. One gap worth naming: AL3/AM7 required the
  sub-reason distinguishing **`NoCarrierMatch` from `AmbiguousCarrierMatch`**, plus which pass produced it, and the
  TB4 report publishes neither. Either CB2's instrumentation is not reaching the report or it was not exercised on
  this path. **AS6** requires it, because without it the sphere is still exactly where TB1 left it — one level
  short — despite having been measured three times.
- **369 — `saturationUsed == true`, reaching its intended assertion.** This is the first **runtime** confirmation of
  `M3-CP4c2-TB-X2-R10-CAND-01`, which until now rested on my static derivation at R10-REV. The finding is
  corroborated, not changed. It stays **deferred behind the mechanical gate**: it is a cut-graph *quality* matter,
  Amendment 14's representation is unaffected, and folding AK4 into the current successor would widen a bounded
  diagnostic turn into a heuristic redesign.
- **370 — fails at `ASSERT_TRUE(atlasBuild)` before its intended contract, and the cause is unreadable for a reason
  this project has now paid for four times.** The assertion **discards `atlasBuild.error()`**, which is in hand and
  for which `field_atlas_build_error_code_name()` exists — the exact `ORIENTATION.md` §8 anti-pattern, at the *test*
  boundary rather than the pipeline funnel AP1 just fixed. Classification is therefore **not** yet possible between
  the three options AQ5 lists, and this review declines to guess. What can be said: the witness is built by
  `make_source_authority(mesh)` plus a **globally constant ambient** `make_zero_transport_field` (`UnitX`/`UnitY`
  per face) on the closed torus, and the empty rail set here is **intentional** — the test wants an empty network —
  so this is *not* the R8 `rails_from_atlas` trap. It is also an identity that was **appended at CB2 and has never
  executed until now**, so an original authoring defect is at least as likely as an interaction with the
  fail-closed checks CB2/CB3/CB5 added to the same `make` path. **AS3** publishes the code; classification follows.
- **373 — PASS, but on a synthetic contract.** `PrescribedSingularityOnABarrierArcRemainsBoundToACycle` is green on
  its **synthetic** barrier-arc binding fixture. `M3-CP4c3-DEFN-R1-CAND-01`'s closure condition also requires the
  **mechanical witness's** zero-unbound count, which is still blocked at 366. A synthetic green is not a produced
  green — the same distinction the project already tracks as produced-witness debt — so the candidate stays open
  and **AS7** records the residual explicitly rather than letting a green tick close it.

---

## AQ6 — frozen architecture and accepted behaviour preserved

Ordinals **1–365** are green and untouched by every measure below. Selector **373** stays byte-identical and
unselected. Amendment 15, Amendment 16 and the P2 decision stand — nothing measured falsifies their premises.
Barrier non-traversability stands. The sector predicate stays **exact**. Error-enum numbering is append-only.
First-red semantics are unchanged, and the AP6 pass remains zero-credit. No `pick first`, tolerance, face-order or
barrier-crossing shortcut is admissible (AS9).

---

## 5. Amendment 17 — one direction, not one direction per candidate

Recorded normatively in `DESIGN.md` §7.2.1. It fixes the **frame and the prohibitions**; it deliberately does not
choose the mechanism.

> **Amendment 17 — an election among candidate cells is decided from a single datum, not from one representative
> per cell.** Where a producer chooses among candidate faces, sectors or cells by asking *"is this cell's own
> representative of the datum admissible in this cell?"*, the question is not a partition test and its
> non-uniqueness cannot be removed by refining the cells, tightening a half-open convention, ordering the
> candidates, or introducing a tolerance. Vertex continuation in particular is a property of **one** incoming ray:
> it must be decided from that ray, expressed once and tested against the fan, or equivalently from where that ray
> exits the vertex star. A cross field's per-face branch representatives are related by transport, **not equal as
> vectors**, so testing each face against its own representative is testing a different point in every cell.

**Prohibited under Amendment 17, all three being ways of making the symptom go away:** electing the first candidate
or ordering faces to force uniqueness; widening or narrowing the sector convention; introducing any tolerance into
the predicate, which is exact today and must stay exact. Changing the `FaceInterior` exclusion to alter cardinality
is prohibited for the same reason (AQ4).

**Left open, pending AS1:** whether the single datum is the incoming direction transported into each candidate face
and tested there, or the geometric exit of the incoming ray from the vertex star, or a continuation owner published
upstream by A1. The three differ in which product owns vertex continuation — a single-writer question — and the
choice must be made on the measured direction vectors, not on this reconstruction.

---

## AQ7 / AQ8 — dispositions, then one bounded successor

**Candidates.**

- **`M3-CP4c3-TB3-R1-CAND-01`** — **ACTIVE / GATING / CAUSE FAMILY ESTABLISHED**. Narrowed from "unknown
  cardinality" to a proved two-distinct-direction election at a regular vertex; M1/M2/M3 all falsified; M4 named
  and M5 retained. Owner: **AS1** to confirm, **AS4** to correct.
- **`M3-CP4c3-TB3-R1-REV-CAND-01`** — **RESOLVED / RUNTIME PROVED.** CB5's typed locus channel published the
  failing locus directly; no review had to recover it by elimination. Exactly what AP1 was written to do.
- **`M3-CP4c3-TB4-DIAG-CAND-01`** — **ACTIVE / UNCLASSIFIABLE UNTIL THE ERROR IS PUBLISHED** (ordinal 370). Owner:
  **AS3**.
- **`M3-CP4c3-TB4-ORCH-01`** — **RESOLVED / PRE-RUNTIME / NON-STABLE**; zero Directional execution in the failed
  attempt.
- **`M3-CP4c2-TB-X2-R10-CAND-01`** — **runtime-confirmed** at ordinal 369 (`saturationUsed=true`); disposition
  unchanged, deferred behind the mechanical gate.
- **`M3-CP4c2-TB-X2-CAND-04`** — unchanged, **ACTIVE / ONE LEVEL SHORT**; AL4 binding; **AS6** requires the
  sub-reason that three measurements have not yet published.
- **`M3-CP4c3-DEFN-R1-CAND-01`** — **partially discharged**: ordinal 373 green on a synthetic contract; the
  mechanical zero-unbound count remains owed (**AS7**).
- **`M3-CP4c2-TB-X2-R8-CAND-02`** — unchanged; ordinal 370 never reached its contract.

**Accounting.** The accepted 365 prefix is green in this very run, CP4c-3 was already open, and every new or
reproduced finding is on an unaccepted or report-only surface: **44 events / 14 categories / 30 recurrences**,
produced-witness debt **5**, semantic M3 packages **71**, **+0 events / +0 recurrences**.

### Measures **AS0–AS9** — next turn `M3-CP4c-3-CB6`, Code + Build, runtime-free

**AS0 — preconditions.** Accepted predecessor CP4c-2 at **365/365**. Gate **373**,
`b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`; recompute it and all six predecessor prefixes
from committed bytes at authoring and preflight, validating each as exactly 64 lowercase hex. No selector byte may
change. `selected_gate=NONE`, `gate_execution_authorized=false`. GMP/GMPXX linkage mandatory.

**AS1 — publish the two directions, and stop if they are equal.** For the ordinal-366 election publish, per
candidate: the **transported branch label**, the **exact barycentric direction vector** tested, the
transport-adjacency path and composed quarter-turn used to reach it, and the incoming direction at the arrival
face. Publish the same for **every** reachable state, not only the electing two, so the fan is auditable.
**Falsifier:** if the two elected directions are identical vectors, §AQ2's proof is contradicted, M4 and M5 both
fail, and CB6 must stop and route to review rather than proceed.

**AS2 — implement Amendment 17 only if AS1 confirms.** The correction must make the election test **one** datum.
State in the CB report which mechanism was chosen (transport the incoming direction into each candidate and test
it there; or compute the ray's geometric exit from the star; or consume a continuation owner published upstream),
**and which measured fact chose it**. If AS1 shows M5 rather than M4 — representatives unrelated to the incoming
ray in general, not merely near a boundary — say so, because that makes the third option the only sound one.

**AS3 — publish ordinal 370's atlas error.** Change `ASSERT_TRUE(atlasBuild)` to carry
`field_atlas_build_error_code_name(atlasBuild.error().code)` and its locus, then classify
`M3-CP4c3-TB4-DIAG-CAND-01` as witness defect, changed product contract, or legitimate fail-closed behaviour. **Do
not "fix" the witness before the code is published** — that is the same rule as AK6/AL4/AN4/AP4 and it has been
right every time. Sweep the test file for the same anti-pattern while there: an `ASSERT_TRUE` on a typed result
whose error is discarded.

**AS4 — the correction is bounded to the election.** Amendment 17 changes how a continuation is chosen. It does not
authorize touching the transport set, the barrier semantics, the sector predicate's exactness, the `FaceInterior`
exclusion, or A1.

**AS5 — audit by assumption, and prove the predicate was not a symbol search.** The predicate is *"this code
elects among candidates by testing each candidate against its own representative of a shared datum."* Search for
it, list what was found, and name at least one site that satisfies it **without** touching
`resolve_field_vertex_transit` — that last item is the evidence the predicate was applied as an assumption.
`LESSONS.md` 68.

**AS6 — publish the sphere sub-reason at last.** Ordinal 368 has now reproduced `TraceEventPositionInvalid` three
times without ever publishing AL3/AM7's `NoCarrierMatch` versus `AmbiguousCarrierMatch` or which pass produced it.
Determine whether the instrumentation exists and is not reaching the report, or was never wired on this path, and
publish it. **AL4 still forbids designing the sphere's fix.**

**AS7 — record 373's residual as debt, not closure.** `M3-CP4c3-DEFN-R1-CAND-01` closes only when the **mechanical
witness** reports zero unbound prescribed singularities. State that explicitly in the CB report so a later turn
cannot read the synthetic green as closure.

**AS8 — keep the AP6 pass.** The report-only pass over ordinals 367–373 is retained in the next TB plan, zero gate
credit, written rationale. It converted a three-turn blackout into four distinct findings in a single run;
withdrawing it requires a written rationale.

**AS9 — prohibited.** Making `candidates.size() == 1` by picking the first candidate, ordering faces, widening or
narrowing the sector convention, changing the `FaceInterior` exclusion, or introducing **any** tolerance into the
exact predicate. Crossing or closing a barrier (Amendments 15/16). Designing the correction before AS1 reports, or
proceeding if AS1 falsifies it. Correcting ordinal 370's witness before AS3 publishes its error. Designing the
sphere's fix (AL4). Folding AK4's proposal-heuristic redesign into this turn. Reopening Amendments 12–17 or the P2
decision. Renumbering or removing any error-enum value; new codes and fields are appended only. Changing accepted
selector 365's bytes, or 357 / 358 / 361 / 367 / 370 / 373. Treating AP6 results as gate credit. Executing
Directional runtime, running a gate, or benchmarking in a CB turn.

---

## 6. Falsifiable predictions

1. **AS1 will report two geometrically distinct direction vectors.** Proved in §AQ2.3; equality falsifies the
   entire reconstruction and stops CB6.
2. **Both directions will lie near ray(30→31)** — candidate A's just inside wedge 41, candidate B's just inside
   wedge 208 — if M4 is right. Directions far from the shared ray point to M5 instead.
3. **The two candidates will carry different transported branch labels**, since with trivial holonomy each face
   holds one state and the labels are related by the composed quarter-turns across the fan.
4. **Ordinal 370's published atlas error will name a specific typed code**, and the review will then be able to
   classify it; a second unreadable failure there would mean AS3 was implemented too narrowly.
5. **Ordinals 1–365 will remain green** through Amendment 17's correction, which touches election only.
6. **371 and 372 will stay red until 366 is green**, and their own contracts will remain unmeasured — they are
   blocked, not failing.

## 7. What this turn owes its own record

**Four consecutive turns, four scopes of mine that were too narrow.** AM2 scoped a consumer audit by **symbol**;
AN1 scoped instrumentation by **enum**; Amendment 16 was written for **one stage**; and now the M1/M2/M3
enumeration at TB3-R1-REV was presented as the space of mechanisms and **every one of them is falsified**. The
frozen plan I was working from listed five possibilities including "exact sector predicate/election defect" — which
is where the answer now appears to live — and my own enumeration dropped it.

The general form, recorded as `LESSONS.md` **70**: **an enumeration of candidate *mechanisms* is exactly as
dangerous as an enumeration of candidate *consumers*, and for the same reason** — it is a snapshot of the
reviewer's imagination, and the next failure is by definition somewhere they did not look. Enumerate mechanisms to
*design the measurement*, never to bound the answer, and say in the record which observation would fall outside
every listed mechanism. The measurement here was well designed — `publishedFaces` discriminated all three at once,
which is why one run could kill them all — and that is the part worth keeping.

`LESSONS.md` **71** records the reusable technical form: **a partition test disambiguates one point among cells; it
cannot disambiguate one point per cell.**

## 8. Exact next turn

**`M3-CP4c-3-CB6`** — Code + Build, runtime-free, GMP/GMPXX linked, under **AS0–AS9**. It publishes the two
direction vectors and the full fan (AS1), implements Amendment 17 only if that confirms (AS2), publishes ordinal
370's atlas error (AS3), and wires the sphere sub-reason (AS6).

CP4c-2 remains **CLOSED / ACCEPTED at 365/365**. CP4c-3 is **open**; gate **373** stays frozen and unselected.
