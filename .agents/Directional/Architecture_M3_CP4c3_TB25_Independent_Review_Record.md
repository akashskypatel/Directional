# M3-CP4c-3-TB25 Independent Review Record

## Status

**COMPLETE / STATIC / NO RUNTIME / NO COMPILE / NON-STABLE / SUCCESSOR FROZEN.**

`M3-CP4c-3-TB25-REV` is independent REVIEW + PLAN only. It executed no Directional runtime, no compile, no package
operation, and mutated no product, test, fixture, benchmark, build or selector byte. Accepted authority remains
**365/365**; the current semantic runtime authority is `M3-CP4c-3-TB25-R1` (**393 PASS / 10 RED** on selector 403).
CP4c-3 remains **OPEN**. Measures **CJ0–CJ9** freeze the exact successor **`M3-CP4c-3-CB30`**.

`review_check.py authority 3d7f7f9a3afad3ed37fc615a206801cf6310f4ac` — **ALL CHECKS PASSED**: the semantic source
exists, is an ancestor of HEAD, and no code surface drifted between it and HEAD. Static review of the working tree
is valid evidence about immutable package `9950303110`.

---

## 1. CJ0 — what TB25-R1 settled

**CH6 and CH7 worked.** Ordinals **384 and 385 return to PASS**. The certificate now survives ownership failure,
the plan reaches its own census, and the production ownership publication is readable for the first time in seven
turns:

```
sourceFaceCount=300; established=74; unavailable=226; conflicting=0;
conflictCensusPublished=true; conflictRowCount=0
```

Component 0: `uncutFaceComponentFaceCount=191`, `uncutFaceComponentSeedCount=0`,
`uncutFaceComponentSeedState=None`, `certifiedFaceObservationCount=0`, `certifiedFaceUnavailableCount=191`,
`certifiedFaceDistinctCount=0`, multiset untruncated.

Under the frozen TB25 interpretation contract this is **branch 3: no conflict rows together with
zero/unavailable component ownership — a third mechanism / incomplete ownership establishment.**

### 1.1 Both branches of `M3-CP4c3-TB21-CAND-01` are refuted, and the candidate is ill-formed

Neither the missing-barrier branch nor the mis-read-seed branch is selected. **Both predictions on record were
wrong** — DEFN-R3's (missing barrier) and mine at TB24-REV (mis-attribution). The measured mechanism is neither.

More importantly, the candidate as posed cannot be answered. "Are component 0's certified owners all equal?"
presupposes that the seed rule producing them is a valid reading of certified ownership. **No rule in this codebase
is.** Every rule so far — the pre-CB27 plan rule, CB27's relocation, CB28's certifier rule — is a heuristic over
darts of arcs, and the answer changes with the heuristic: **3 owners under one rule, 0 under another, on the same
fixture and the same certified complex.** A question whose answer is determined by which heuristic ran is a question
about the heuristic, not about the geometry.

`M3-CP4c3-TB21-CAND-01` **CLOSES as ILL-FORMED / SUPERSEDED**, replaced by `M3-CP4c3-TB25-REV-CAND-02` below,
which is posed about the object rather than about the rule.

### 1.2 CH8's conflict census is vacuous on exactly the region under investigation — my error

`build_certified_owner_conflict_census` (`src/geometry/CertifiedOwnerConflictCensus.h:33–38`) emits a row only when
**both** incident faces are `established()` with a singleton owner. Component 0's 191 faces are all `Unavailable`.
**No edge on or inside component 0 can produce a row, whatever the geometry does.** `conflictRowCount=0` is a
structural zero over the region it was built to adjudicate — the same defect as `projectionFaithfulnessResidual`
(`LESSONS.md` 110), which this project has already paid for once.

I wrote CH8 at TB24-REV. I checked that the census publishes on the failure path; I did not check that its **input**
survives the failure. Branch 3 of the contract caught the outcome, so the turn was not wasted — but the census
itself contributed nothing, and the entire diagnosis below comes from `established=74 / unavailable=226` and the
component-0 evidence, neither of which is the census. Recorded as `LESSONS.md` 122.

---

## 2. CJ1 — the diagnosis: the certifier's seed rule is strictly narrower than the rule it replaced

This is provable from the two code sites and two measurements of the same component.

**Pre-CB27 plan rule** (`GlobalTopologyPlan.cpp` at `63aae440:1259–1289`). For each non-barrier source edge with an
unlabeled face on one side and a labeled face on the other, a seed is admitted if **either**

- (P) the labeled face has exactly one fragment orbit — `labeled->second.size() == 1U` — **or**
- (F) per-edge evidence `edgeOrbitEvidence[(labeledFace, edge)]` is unique.

**CB28 certifier rule** (`SurfaceCutGraph.cpp:604–637`). A seed is admitted only if the neighbour is a **trace-cut**
face **and** `directOwnersByEdgeSide[{other, edge}]` has exactly one element — an analogue of (F) alone. **Path (P)
has no counterpart.**

**The measured consequence on the identical component:**

| rule | component 0 boundary edges | attributed | result |
|---|---|---|---|
| pre-CB27 plan | 97 | **83** — orbit 0 → **81**, orbit 1 → **1**, orbit 3 → **1**; 14 barrier/no-seed | `seedState=Multiple`, seeds `[0,1,3]` |
| CB28 certifier | 97 | **0** | `seedState=None`, seeds `[]` |

Same fixture, same certified complex, same barrier set membership question — **83 attributions against 0**. The
narrowing is the whole difference, and it is the "third mechanism" the frozen contract named.

**This does not mean the old rule was right.** It means neither rule is derived from the certificate: one guesses
generously and one refuses to guess, and nothing in between has been checked against the object.

---

## 3. CJ2 — what the certificate actually determines, and the one dichotomy left

Certified faces are orbits of the face walk on the embedded graph. The **only** things that can separate two points
of the surface into different certified faces are arcs — mandatory arcs, cut arcs and trace arcs. Therefore:

> **If no arc meets the interior of an uncut component `C`, then `C` lies in exactly one certified face.**

Component 0 is 191 uncut source faces joined across non-barrier edges. If the barrier set faithfully marks every
separating arc, no arc meets its interior, and **its certified owner is a single orbit — necessarily.** Then `3` is
wrong, `0` is starved, and the 81/1/1 distribution names the answer as orbit **0** with two attribution errors.

The alternative is that the barrier set does **not** faithfully mark every separating arc. That gives an exhaustive
dichotomy, and the second horn has exactly one identified mechanism:

**A trace that transits a source vertex separates faces that no source-edge barrier can separate.**
In `build_source_face_ownership` a segment contributes `barriers.insert(segment.outgoingCarrier)` and, only when it
exists, `barriers.insert(*segment.incomingCarrier)` (`SurfaceCutGraph.cpp:528–530`). The vertex-entry branch
(`:564–586`) handles precisely the segments with **no incoming carrier**: the trace enters the face at a
`SourceVertexSupport`. Around that vertex the trace passes between two faces **through the shared vertex, not
across a shared edge**, so the two faces can lie in different certified faces while every source edge between them
is a non-barrier. **A partition of source faces over source edges cannot represent that separation.** This is
`LESSONS.md` 117 one level deeper: the partition is not merely coarser than the one it adjudicates — for a
vertex-transit locus it is not expressible in the same category at all.

That mechanism is a **hypothesis about the mechanical witness**, not a proved fact: it is proved that the code
admits it, and unproved that it occurs here. CJ6 measures it with a stated falsification condition.

It also explains the historical 81/1/1 without appeal to a missing edge: two dissenting edges out of 83 is the
shape of two local attribution errors, not the shape of a 191-face component genuinely spanning three of six
certified faces.

---

## 4. CJ3 — classification of the 10 RED ordinals

Four distinct causes, not ten.

| Ordinal | Cause |
|---|---|
| 366, 367 | **The open frontier.** `UncutFaceComponentOrbitSeedNotUnique`, component 0, `seedCount=0`, `seedState=None`. This is the one product problem, and §2/§3 diagnose it. Euler census complete, `V=22,E=26,F=6,componentCount=1`, residual `0`. |
| 398 | **The honest gate.** `proves_cellularity()==false` because ownership is genuinely incomplete. Correct behaviour of a correct contract. Stays gating, stays RED until the derivation is right. |
| 389, 390, 393 | **Collateral assertions**, §4.1. Each identity is *about* something else and additionally asserts `proves_cellularity()`, which DEFN-R3.1 coupled to ownership totality. Their own subjects are green. |
| 368, 369, 370, 374 | **Unchanged carried surfaces**, separate owners, untouched by this review. |

### 4.1 Two gates now encode assertions their identities do not own — and one encodes a refuted hypothesis

**Ordinal 389** — `EmbeddedGraphEulerCensusPublishesThroughMechanicalProductionFailure`
(`tests/FieldAlignedCurveNetworkTests.cpp:11441–11479`). Every census assertion it owns **passes**; TB25-R1
confirms `V=22;E=26;F=6;componentCount=1;sourceChi=2;residual=0` is published and matches the certificate. It REDs
solely on `EXPECT_TRUE(certificate.proves_cellularity())` at `:11448`, written when `proves_cellularity()` meant
embedded cellularity alone. CB28 introduced **`proves_embedded_cellularity()`** as exactly that predicate. The
identity should assert the predicate it is named for.

**Ordinal 390** — `UncutFaceComponentBoundaryOrbitAttributionPublishesThroughMechanicalProductionFailure`
(`:11482–11513`). It REDs on `ASSERT_GT(*locus.uncutFaceComponentCertifiedFaceDistinctCount, 1U)` at `:11499`,
observed `0`. **That assertion encodes the missing-barrier hypothesis as a required-green gate.** It was authored
when the count was 3. It is now a gate demanding that a hypothesis under investigation be true — and the same
turn's measurement says it is false. A witness must assert its contract (the attribution census is published,
complete and untruncated, and agrees with the component census), never the value a live hypothesis predicts.
Recorded as `LESSONS.md` 123.

**Ordinal 393** carries the same `proves_cellularity()` coupling; its replacement contract from CG5 is still
untested, so `M3-CP4c3-TB23-R1-REV-CAND-02` and `M3-CP4c3-TB22-REV-CAND-01` stay open.

**Nothing is weakened by fixing these.** Ordinal **398** is the dedicated gate for the ownership contract and
remains gating and RED. Splitting one contract per gate is the correction; removing the contract is not.

### 4.2 A correction to my own CH7 falsification condition

At TB24-REV I wrote that CH6/CH7 are falsified unless "**384, 389, 390** return to PASS". 384 and 385 returned;
389 and 390 did not. **The condition was wrong, not the candidate.** Their subject *was* restored — TB25-R1 records
the Euler census and the attribution evidence as published — but each carries an independent second assertion
(§4.1) that the ordering fix could not have addressed. Bundling several witnesses into one falsification condition
makes it fail whenever any one of them has a second cause. `M3-CP4c3-TB24-REV-CAND-01` is **CONFIRMED and CLOSED**
on the evidence that matters: the failure is no longer upstream of the evidence. `LESSONS.md` 124.

---

## 5. CJ4 — stable accounting

**No stable event, category, or recurrence is added.** Totals remain **44 events / 14 categories / 30 recurrences**,
produced-witness debt **5**, semantic M3 package count **90**.

1. accepted identities **1–365 are 365/365 PASS**; no accepted-green loss, and no accepted RED ordinal;
2. 384 and 385 **recovered**; recovery is not an event;
3. 389/390/393/398 are CP4c-3 witnesses over an open frontier, RED for reasons this review names, none of which is
   a loss of accepted behaviour;
4. 366/367/368/369/370/374 are already-counted carried surfaces;
5. `M3-CP4c3-TB25-ORCH-01` is an orchestration correction proved at runtime by CB29 + TB25-R1; per the standing
   rule it carries no semantic credit and adds no stable event. **CLOSED.**

---

## 6. CJ5 — candidates

**Closing.**

- `M3-CP4c3-TB21-CAND-01` — **CLOSED / ILL-FORMED / SUPERSEDED** by `M3-CP4c3-TB25-REV-CAND-02`, §1.1.
- `M3-CP4c3-TB24-REV-CAND-01` — **CLOSED / RUNTIME PROVED**, §4.2. 384/385 recovered; the failure no longer sits
  upstream of the evidence.
- `M3-CP4c3-TB25-ORCH-01` — **CLOSED / CONTROL FIX RUNTIME PROVED / NON-STABLE.** CB29's corrected control ran all
  403 identities; the first attempt executed 0/403 and stays invalid provenance.

**Confirmed and carried.**

- `M3-CP4c3-TB24-REV-CAND-02` — **CONFIRMED / ACTIVE.** Ownership of non-arc-incident faces is a derivation, not a
  read, and TB25-R1 shows the derivation is what is broken. Sharpened by §3.

**New.**

- `M3-CP4c3-TB25-REV-CAND-01` — **NEW / ACTIVE / GATING / PRODUCT.** The certifier's seed rule admits one seed
  source where the rule it replaced admitted two; component 0 goes from 83 attributed boundary edges to 0, §2.
  Owner: **CJ6/CJ7**.
- `M3-CP4c3-TB25-REV-CAND-02` — **NEW / ACTIVE / GATING / ARCHITECTURAL.** *Is component 0 contained in a single
  certified face?* Posed about the object, not about a rule. By §3 the answer is **yes unless a separating arc
  meets its interior**, and the only mechanism that can hide such an arc from a source-edge barrier set is a trace
  transiting a **vertex**. Owner: **CJ6**. Exhaustive and falsifiable.
- `M3-CP4c3-TB25-REV-CAND-03` — **NEW / ACTIVE / TEST AUTHORITY / GATING.** Ordinals 389 and 390 gate on
  assertions their identities do not own, and 390's `ASSERT_GT(..., 1U)` encodes a refuted hypothesis, §4.1.
  Owner: **CJ8**.

**Unchanged, separate owners.** `M3-CP4c3-TB22-REV-CAND-01`, `M3-CP4c3-TB23-R1-REV-CAND-02`,
`M3-CP4c3-DEFN-R3-CAND-01`, `M3-CP4c3-TB18-REV-CAND-01`, `M3-CP4c3-TB7-CAND-02`, `M3-CP4c3-DEFN-R2-CAND-01`,
`M3-CP4c3-TB6-CAND-01`, `M3-CP4c2-TB-X2-CAND-04`, `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`,
finalize/contact fall-through. `M3-CP4c3-TB19-CAND-01` follows `M3-CP4c3-TB21-CAND-01` into closure as a symptom
record of an ill-formed question.

---

## 7. CJ6–CJ9 — frozen successor: `M3-CP4c-3-CB30`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`. No acceptance evidence.

### CJ6 — the arc-incidence census, and the last measurement this frontier gets

For **every** uncut component the certifier publishes, on the failure path and independently of whether any owner
was established:

1. **boundary census** — every boundary edge, its independently derived barrier class, whether the opposite face is
   trace-cut, and whether a side owner exists there. Component 0's 97 edges must be published untruncated.
2. **interior arc-incidence** — every arc of `embedded.arcs` whose dart lies on a face of the component, with the
   arc kind and the orbit at each of its two darts.
3. **vertex-transit census** — every source vertex at which a trace segment enters through a `SourceVertexSupport`,
   together with the faces incident to that vertex that belong to an uncut component, and whether any pair of them
   is adjacent across a non-barrier edge.

**Falsification, stated before the measurement is built:**

- **(2) is empty and (3) names no such vertex on component 0** ⇒ no arc meets component 0's interior, so by §3 it
  lies in **exactly one** certified face; `M3-CP4c3-TB25-REV-CAND-02` resolves to *single owner*, the seed rule is
  the only defect, and the answer is the orbit named by (1)'s majority.
- **(2) is non-empty** ⇒ a separating arc does meet the interior; the component genuinely spans certified faces and
  the arc is named.
- **(3) names a vertex whose incident uncut faces are adjacent across a non-barrier edge** ⇒ the missing separator
  is a **vertex transit**, the barrier set cannot represent it, and the partition model must change rather than the
  barrier set be patched.

These are mutually exclusive on the evidence and jointly exhaustive. Each publishes a **named locus**, not a count.

**None of the three censuses may be gated on an owner being established.** That is the CH8 defect and it must not
recur: the census must be computable from `embedded.arcs`, `faceWalk.orbitByDart`, `sourceTopology.incidentFaces`,
the barrier set and the partition alone.

### CJ7 — restore the seed path, without inventing a new one

The certifier's component seeding must admit the same two sources the pre-CB27 rule admitted, §2: a neighbour with
a **single** established owner, and unique per-edge side evidence. This is a **restoration**, not a new heuristic —
CB28 narrowed it without a recorded decision, and the narrowing is what starved component 0.

**It remains a heuristic, and CB30 must not present it as certified ownership.** A component seeded this way
publishes status `Established` only when its seed set is a singleton; a multi-seed component publishes
`Conflicting` with the full seed multiset and its per-edge attribution, and `proves_cellularity()` stays false.
**CB30 does not choose a winner among disagreeing seeds**, and does not add or remove a barrier.

### CJ8 — one contract per gate

- Ordinal **389**: `EXPECT_TRUE(certificate.proves_cellularity())` at `:11448` becomes
  `proves_embedded_cellularity()`. Every other assertion is unchanged. The identity is about the Euler census.
- Ordinal **390**: `ASSERT_GT(*locus.uncutFaceComponentCertifiedFaceDistinctCount, 1U)` at `:11499` is **replaced
  in place** by the contract the identity owns — the attribution census is published, complete and untruncated, and
  its distinct count equals the component's seed count, **whatever that count is**. Its `proves_cellularity()`
  assertion becomes `proves_embedded_cellularity()`. Ordinal retained, gating, name unchanged.
- Ordinal **393**: same `proves_cellularity()` → `proves_embedded_cellularity()` substitution, leaving its CG5
  replacement contract otherwise intact, so `M3-CP4c3-TB22-REV-CAND-01` can finally be tested.
- Ordinal **398** is untouched, gating, and the sole gate on ownership totality.

Precedent: DEFN-R3.7 for 393 and CH9 for 385 both replaced assertions in place while retaining the ordinal.

### CJ9 — selector 405

Selector 403 must be its exact 403-line prefix, 401 the exact prefix of that, 397 byte-frozen. Two gating
identities:

- **404** `SurfaceCutGraph.UncutComponentArcIncidenceCensusPublishesOnOwnershipFailure` — on the mechanical
  production fixture the three CJ6 censuses are published, untruncated for component 0, and computable with no
  established owner. Asserts **publication and completeness**, never a value.
- **405** `SurfaceCutGraph.VertexTransitCensusNamesAFaceSeparationNoSourceEdgeBarrierCanCarry` — the independent
  falsifiability witness on a constructed fixture with a known vertex-transit trace. Splits *can* from *does*, as
  399/400/403 did.

### Prohibited in CB30

1. Changing any accepted identity 1–365, or any byte of selector 397, 401 or the first 403 lines of selector 405.
2. Weakening `proves_cellularity()` or ordinals 397/398/399/400/401/402/403.
3. Adding or removing a barrier, changing the attribution rule beyond the CJ7 restoration, or choosing a winner
   among disagreeing seeds, before CJ6 reports.
4. Gating any CJ6 census on an established owner.
5. Reverting CB21, CB25, CB26, CB27, CB28 or CB29.
6. Executing any Directional runtime.

---

## 8. Predictions — recorded as predictions

I expect CJ6 to find **(2) empty and (3) naming at least one vertex on component 0's boundary** — a vertex-transit
separation, with the seed rule starved *and* the partition model unable to express the true boundary. I have been
wrong on this frontier twice, at DEFN-R3 and at TB24-REV, and I am recording this one with lower confidence than
either. **No measure below §7 depends on it**, and CJ6's three outcomes are exhaustive regardless.

The load-bearing claim of this review is not the prediction. It is §3: **either component 0 has exactly one
certified owner, or a separating arc meets its interior.** That is a dichotomy about the object, provable from what
a certified face is, and it does not depend on any seed rule.

## 9. Consolidation performed

Per `CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW turn". Durable facts were verified present in this
record, `Architecture_M3_CP4c3_TB25_R1_Artifact_Only_Test_Benchmark_Report.md`,
`Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` before
any fold.

Folded now: `Architecture_M3_CP4c3_TB24_Independent_Review_Record.md`,
`Architecture_M3_CP4c3_CB27_Code_Build_Report.md`. Indexed retrospectively under clause 3, having been retired by
`M3-CP4c-3-TB25-R1`'s stale-evidence cleanup: the TB24 runtime report, the consumed TB25 plan and the CB29 report.

Retained as current authority: `Architecture_M3_CP4c3_TB25_R1_Artifact_Only_Test_Benchmark_Report.md`,
`Architecture_M3_CP4c3_CB28_Code_Build_Report.md`, this record, `M3_CP4c_Current_And_Forward.md`,
`M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, `M3_CP4c_Consolidated_Record.md`, and every
`Required_Green_Selector_*.txt`.

## 10. Lessons added

`LESSONS.md` **122** — a census over established values is vacuous where nothing is established.
`LESSONS.md` **123** — a required-green assertion must never encode a hypothesis still under investigation.
`LESSONS.md` **124** — a falsification condition that bundles several witnesses fails on the first one with a
second cause.

## 11. Exact successor

**`M3-CP4c-3-CB30`** under **CJ6–CJ9**, Code + Build, runtime-free, GMP/GMPXX linked. No runtime, no package
repair, no barrier change, no winner chosen among seeds, no accepted-prefix change.
