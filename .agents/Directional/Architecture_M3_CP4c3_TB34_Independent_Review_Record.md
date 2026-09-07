# M3-CP4c-3-TB34 Independent Review Record

## Status

**COMPLETE / STATIC / NO RUNTIME / NO COMPILE / ACCEPTED-PREFIX REGRESSION / ONE NEW STABLE EVENT / REVERT FROZEN.**

`M3-CP4c-3-TB34-REV` is evidence-only review. It executed no Directional runtime, no compile, no package operation,
and mutated no product, test, fixture, benchmark, build or selector byte.

**TB34 is promoted to current valid semantic runtime authority** — the run is mechanically valid throughout —
**and it carries an accepted-prefix regression**: selector **409**, **400 PASS / 9 RED**, accepted
**1–365 = 364/365**, RED `[312, 366, 367, 368, 369, 370, 374, 398, 409]`.

**Ordinal 312, `GlobalTopologyPlan.RejectsRegionWithMultipleBoundaryWalks`, went PASS → RED.** That is the first
accepted-green loss in this entire sequence, it was caused by the correction I froze at CU4, and **the diagnosis I
gave for it was wrong on its decisive point.** §1 records that; §5 records the resulting stable event.

`review_check.py authority 7711b9c2c20d284823911aa4ca067bd33244f4e6` — **ALL CHECKS PASSED**.

---

## 1. CV0 — the CU4 derivation was wrong, and an accepted identity already said so

TB33-REV §3.2 argued: *"the only case the removed disjunct catches and the chain check does not is two loops
meeting at the start node — which is a walk pinched at a node, exactly the legitimate configuration a slit
produces."*

**Ordinal 312 is an accepted identity named `RejectsRegionWithMultipleBoundaryWalks`.** It has been in the accepted
prefix throughout, and it encodes the opposite contract: a region whose boundary is more than one closed walk
**must be rejected** with `RegionBoundaryNotSingleWalk`. Its retained failure is:

```
Expected: GlobalTopologyPlanErrorCode::RegionBoundaryNotSingleWalk
Actual:   RotationSystemInconsistent
Value of: rejected.error().arc.has_value()   Actual: false   Expected: true
```

With the rejection removed, its fixture is no longer caught at the boundary walk and falls through to an unrelated
later error carrying no arc locus.

**`RegionBoundaryNotSingleWalk` appears exactly twice in the test file** — at ordinal 312 and at the ordinal 409 I
added. A single grep for the error code before freezing CU4 would have found the accepted witness that contradicted
the derivation. That check is now mandatory: **CV5**.

### 1.1 The certificate argument was an authority-domain conflation

TB33-REV §3.1 also argued that the certificate contradicts the rejection, because the same failure publishes
`F=6`, `componentCount=1`, `eulerResidual=0` with all six faces established as discs.

**That was the wrong object.** The certificate establishes disc topology for the **certified faces of the embedded
graph**. A **plan region** is a different object, built by a different construction over a different partition —
the very distinction this checkpoint has carried in its settled facts since TB21 (*"the certificate and the seed
guard test different objects; neither validates the other"*) and re-proved at TB27 with
`matchesFailingComponent=false`. I applied a certified-face property to a plan region anyway.

Primary category `RP-01 / AUTHORITY_DOMAIN_CONFLATION`, and it is the same trap this project has recorded before.

### 1.2 The product independently says the region is not a disc

This is the part that settles it. With the rejection removed, 366/367 did not clear — they advanced to
**`RegionEulerCharacteristicNotOne`**, still at `regionFrontierFailureStage=RegionCertification`, and both publish
`regionBoundaryWalkReason=ClosedBeforeEnd`.

χ(region) = 1 is the disc test. **Two independent checks now say the same thing about the same object**: the walk
closes before consuming its arcs, and the Euler characteristic is not one. The `current == start` disjunct was not
a spurious guard rejecting a legitimate pinch — it was the **earlier and clearer** of two correct statements that
this region is not a disc.

---

## 2. CV1 — what CU5 bought, and why it stays

CU5 is the measure that worked, and it is why this turn is diagnostic rather than merely a failure.

Before it, `arc=3` did not say which disjunct fired and TB33-REV had to derive it. Now 366/367 publish
`regionBoundaryWalkReason=ClosedBeforeEnd` directly, so:

- the branch the mechanical fixture takes is **observed, not inferred** — the derivation of *which* branch was
  right, even though the conclusion drawn from it was wrong;
- the rejection that CV2 restores can carry that reason, turning `RegionBoundaryNotSingleWalk` from an opaque code
  into a named diagnosis;
- ordinal 312's failure text names the substituted code and the missing arc locus, which is what let this review
  attribute the regression in one step.

**The typed reason is kept. Only the removal of the rejection is reverted.**

---

## 3. CV2 — ordinal 409, and what its failure tells us

The constructed negative I froze at CU6 is RED, and **it never reached its oracle**: `disjointRegions.has_value()`
is false, with `constructed negative requires two node-disjoint closed region loops`. The fixture could not build
the shape.

That is informative rather than merely broken. If two **node-disjoint** boundary loops cannot be constructed
through the production entry path, then the only multi-walk shape that is actually reachable is **the pinch** —
two loops sharing a node — which is precisely what ordinal 312 constructs and what CU4 stopped rejecting.

So CU6 asked for a witness of the unreachable case while the reachable case already had an accepted witness. **CV3
re-authors 409 in place** to assert the reachable negative.

---

## 4. CV3 — classification of the 9 RED ordinals

| Ordinal | Classification |
|---|---|
| **312** | **ACCEPTED-PREFIX REGRESSION**, caused by CU4. `RejectsRegionWithMultipleBoundaryWalks` no longer rejects; the fixture falls through to `RotationSystemInconsistent` with no arc locus. **One new stable event**, §5. Reverted by **CV2**. |
| **409** | **Fixture unreachable**, §3. The constructed negative asks for two node-disjoint loops, which the production entry path does not appear to permit. Re-authored in place by **CV3**. |
| 366, 367 | **The frontier, and it is a genuine product problem.** Now `RegionEulerCharacteristicNotOne` with `regionBoundaryWalkReason=ClosedBeforeEnd`: the plan builds a region that is **not a disc**, and two independent checks say so. |
| 398 | **Carried sphere surface.** Not an ownership gate. Owner: `M3-CP4c2-TB-X2-CAND-04`. Untouched. |
| 368, 369, 370, 374 | **Unchanged carried surfaces** with separate owners. Untouched. |

**Held:** 390/393/404/406/407/408 all PASS; zero emissions of either retired code across the raw logs; ownership
`300 established / 0 unavailable / 0 conflicting`; 409 rows, exact ordinal sequence, every row `selected=1`, zero
timeouts; all three byte+mode censuses identical pre/post; `baseline-authority.txt` names the executing run.

---

## 5. CV4 — stable accounting: one new event

**This turn adds one stable event and one recurrence.**

> **44 events / 14 categories / 30 recurrences → 45 events / 14 categories / 31 recurrences.**
> Produced-witness debt remains **5**; semantic M3 package count **99**.

Rationale, against the rule this project has applied throughout — *a stable event requires accepted-green loss*:

1. **Accepted ordinal 312 went PASS → RED.** Accepted-green behaviour was lost. Every prior PASS → RED in this
   sequence was outside 1–365 and was classified as evidence-contract loss; **this one is inside the accepted
   prefix and is behaviour loss.**
2. **Primary category: `RP-01 / AUTHORITY_DOMAIN_CONFLATION`** — a certified-face property was applied to a plan
   region. Existing category, so the category count does not advance.
3. **Detection escape: none.** The accepted prefix caught it on the first runtime after the change, which is
   exactly what that boundary is for. The escape was upstream of the gate, in the freeze: the derivation was
   published without checking the accepted witnesses for the error code it removed.
4. The remaining eight REDs are the carried set plus the unreachable 409 fixture and are not new events.

I record this plainly because the alternative — classifying my own error as non-stable because it was quickly
caught — would corrupt the one number this project uses to measure itself.

---

## 6. CV5 — candidates

**New.**

- `M3-CP4c3-TB34-REV-CAND-01` — **NEW / ACTIVE / GATING / PRODUCT / STABLE-EVENT OWNER.** The `current == start`
  rejection in `validate_single_boundary_walk` is load-bearing: it is the accepted contract of ordinal 312 and the
  earlier of two correct statements that a pinched region is not a disc. Its removal is reverted by **CV2**.
- `M3-CP4c3-TB34-REV-CAND-02` — **NEW / ACTIVE / GATING / TEST AUTHORITY.** Ordinal 409 asserts a fixture the
  production entry path does not appear to permit. Owner: **CV3**.
- `M3-CP4c3-TB34-REV-CAND-03` — **NEW / ACTIVE / GATING / PRODUCT.** The mechanical plan builds a region that is
  not a disc — `ClosedBeforeEnd` and `RegionEulerCharacteristicNotOne` agree. **This is the real frontier**, and it
  is the first one on this path that is not a guard defect. No correction is authorized until it is diagnosed.

**Reopened.**

- `M3-CP4c3-TB33-REV-CAND-01` — **REOPENED and REFUTED.** The `current == start` disjunct does not reject a
  legitimate configuration; ordinal 312 is the accepted witness that it must reject. Superseded by CAND-01 above.

**Carried, unchanged.** `M3-CP4c3-TB26-REV-CAND-04` / `M3-CP4c3-DEFN-R3-CAND-01`, `M3-CP4c3-TB30-REV-CAND-02`,
`M3-CP4c3-TB27-REV-CAND-02`, `M3-CP4c3-TB22-REV-CAND-01`, `M3-CP4c3-TB18-REV-CAND-01`, `M3-CP4c3-TB7-CAND-02`,
`M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`, `M3-CP4c2-TB-X2-CAND-04` (also 398),
`M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, finalize/contact fall-through.

---

## 7. CV1–CV6 — frozen successor: `M3-CP4c-3-CB40`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`. **Restore, then re-aim.** No new product
behaviour is introduced.

### CV2 — revert CU4, keep CU5

Restore the `current == start` rejection in `validate_single_boundary_walk`, and **keep the typed reason**: the
restored rejection publishes `RegionBoundaryNotSingleWalk` with
`regionBoundaryWalkReason = ClosedBeforeEnd`, so the code that ordinal 312 expects is raised *and* names why.

`ArcChainBroken` and `WalkNotClosed` keep their meanings. Nothing else in CB39 is reverted — the reason plumbing,
the observation flag and the diagnostics field all stay.

**Required outcome: ordinal 312 returns to PASS and the accepted prefix returns to 365/365.** That is the gating
condition of the successor runtime.

### CV3 — re-aim ordinal 409 at the reachable negative

Replace ordinal 409's assertions **in place**; ordinal, name and the first 408 selector lines unchanged. It must
construct the negative the production entry path actually permits — **two boundary loops meeting at a shared
node** — and assert rejection with `RegionBoundaryNotSingleWalk` and reason `ClosedBeforeEnd`.

If the fixture also cannot build that shape through the production path, the identity must **say so explicitly**
and assert the property it can reach, rather than depend on a fixture it cannot construct. **An identity may never
be left asserting an unconstructible fixture.**

### CV4 — record the settled distinction

Add to the settled facts, in `ORIENTATION.md` §5 and `M3_CP4c_Current_And_Forward.md`:

> **A certified face of the embedded graph and a plan region are different objects.** The certificate's disc
> topology, `F`, `componentCount` and Euler residual are claims about certified faces. They license **no**
> conclusion about whether a plan region is a disc. `RegionEulerCharacteristicNotOne` and
> `RegionBoundaryNotSingleWalk` are the region-level tests, and they are the authority there.

This is a restatement of a fact this checkpoint already held; it is being made explicit because a review acted
against it.

### CV5 — a mandatory pre-freeze check

**Before any future measure removes, weakens or re-scopes a rejection, the review that freezes it must grep the
test corpus for the error code being removed and name every accepted identity (1–365) that asserts it.** Ordinal
312 was one grep away. This obligation belongs to the review, not to the Code + Build turn that implements it.

### CV6 — falsification, stated before the build

- If ordinal **312** does not return to PASS, the revert is incomplete and the accepted prefix stays broken —
  that is a stop condition, not a finding.
- If **366/367** return to `RegionBoundaryNotSingleWalk` with reason `ClosedBeforeEnd`, §1.2 is confirmed and the
  frontier is `M3-CP4c3-TB34-REV-CAND-03`.
- If they instead report `ArcChainBroken`, the pinch reading is wrong and the boundary genuinely fails to chain.
- If ordinal **409** still cannot construct its fixture, CV3's fallback applies and the identity must state the
  limitation rather than assert an unreachable negative.

### Prohibited in CB40

1. Any change to topology, barriers, ownership, the separating-arc rule, or any previously retired guard.
2. Any attempt to make 366/367 green. **The region-is-not-a-disc finding is not corrected in CB40**; it is
   diagnosed first.
3. Weakening or re-scoping ordinal 398, or touching 368/369/370/374.
4. Relaxing anything ordinals 390/393/404/406/407/408 legitimately own — they are green and must stay green.
5. Changing any accepted identity 1–365. **Ordinal 312 is restored by fixing the product, never by editing the
   witness.**
6. Executing any Directional runtime.

---

## 8. What this turn actually established

The accepted prefix did its job. A correction with a wrong justification reached the runtime and was caught by a
365-identity boundary on the first execution, with a named witness and a transcribed failure — and the evidence
surface built over the last four turns (typed reasons, per-ordinal transcription, failure-detail digests) made the
attribution a single step rather than a turn.

It also ends a run of eight guard retirements. Every previous frontier on this path was a guard that rejected a
legitimate configuration. **This one is not**: the plan builds a region that is not a disc, and the product says so
twice, independently. That is a real defect in region construction, and it is where the next diagnosis goes.

## 9. Consolidation performed

Per `CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW turn". Durable facts were verified present in this
record, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md`
before any fold. **Preserved in §§1–4 above:** ordinal 312's verbatim failure, the `ClosedBeforeEnd` /
`RegionEulerCharacteristicNotOne` pair on 366/367, ordinal 409's unconstructible-fixture message, and the ownership
census `300 / 0 / 0`.

Folded: `Architecture_M3_CP4c3_TB33_EXEC_Report.md` (superseded runtime authority),
`Architecture_M3_CP4c3_TB33_Artifact_Only_Test_Benchmark_Plan.md` (consumed contract),
`Architecture_M3_CP4c3_TB33_Independent_Review_Record.md` (superseded review authority, CU0–CU6 — **its §3.1/§3.2
derivation is refuted here and CU4 is reverted; CU5 is upheld**),
`Architecture_M3_CP4c3_CB39_Code_Build_Report.md` (consumed build report — it implemented CU4/CU5/CU6 faithfully;
the defect was in the frozen measure, not the implementation).

Retained as current authority: `Architecture_M3_CP4c3_TB34_EXEC_Report.md` (**the valid semantic runtime
authority**), `Architecture_M3_CP4c3_TB34_Artifact_Only_Test_Benchmark_Plan.md`, this record,
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md` (**Part VIII operative**),
`Required_Green_Selector_Manifest.md`, `M3_CP4c_Consolidated_Record.md`, and every
`Required_Green_Selector_*.txt`. **Never folded:** `tools/m3_cp4c3_artifact_only_harness.sh`.

## 10. Lessons added

`LESSONS.md` **144** — before removing a rejection, grep the accepted corpus for the code it raises.
`LESSONS.md` **145** — a certificate's claim about one object is not a claim about another object built from it.

## 11. Exact successor

**`M3-CP4c-3-CB40`** under **CV2–CV6**, Code + Build, runtime-free. Restore the rejection with its new typed
reason, re-aim ordinal 409 at the reachable negative, record the settled distinction, and leave the
region-is-not-a-disc frontier to be diagnosed rather than patched.
