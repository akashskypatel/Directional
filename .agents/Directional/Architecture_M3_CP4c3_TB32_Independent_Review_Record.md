# M3-CP4c-3-TB32 Independent Review Record

## Status

**COMPLETE / STATIC / NO RUNTIME / NO COMPILE / NON-STABLE / BOTH DEFN-R4 FALSIFIERS HELD / CS3 UNMET.**

`M3-CP4c-3-TB32-REV` is evidence-only review. It executed no Directional runtime, no compile, no package operation,
and mutated no product, test, fixture, benchmark, build or selector byte.

**TB32 is promoted to current valid semantic runtime authority**: selector **408**, **397 PASS / 11 RED**, accepted
**1–365 = 365/365**, RED `[366, 367, 368, 369, 370, 374, 390, 393, 398, 406, 407]`. All 408 rows selected exactly
one test, `timeout_count=0`, and all three byte+mode censuses are equal pre/post.

Four findings:

1. **Both DEFN-R4 falsifiers were checked and neither fired.** No `TraceArcDoesNotSeparateItsSides` and no
   `UncutFaceComponentOrbitSeedNotUnique` appear in **any** of the 408 raw logs. **R4.1 and R4.3 are upheld**, and
   366/367 advanced again — to `RegionBoundaryNotSingleWalk`, a **further** stage, which CS6 expressly allowed.
2. **CS3 is unmet.** 390, 393, 406 and 407 were required to return to PASS and did not. **DEFN-R4.5 was
   under-specified, and that is mine.**
3. **CB37 back-fills seed-stage locus fields onto failures from a later stage** — beyond what DEFN-R4.4 asked for,
   and an evidence-integrity hazard.
4. **TB32's ledger SHA-256 is byte-identical to TB31's**, on a run whose failure reasons differ entirely. The
   ledger digest is not a semantic fingerprint, and it was being read as one.

`review_check.py authority 7f63b5f41a0ca72f0b984ec4ee42d11f74775719` — **ALL CHECKS PASSED**.

---

## 1. CT0 — what CB37 landed, verified in source

- **CS1 landed.** The guard at the former `:474–479` is gone and replaced by a comment recording DEFN-R4.1/R4.2:
  *"FragmentCornerIncidence is an ownership map keyed by certified face orbit, not a fragment identity … the
  full-chord writes below intentionally merge all face corners into that single owner's entry."* That is exactly
  what CS1 required, including the instruction to record the contract so the guard is not reintroduced.
- **CS2 landed.** `RegionFrontierEvidence` is threaded through region construction, and
  `annotate_region_frontier_evidence` is applied both inside `build_regions` (`:1337–1342`) **and to the
  region-certification failure** at `:2310–2313`, with `regionSuccess.frontier` and `&candidate.regions`. The
  frontier evidence is no longer attached to one failure code.
- **CS3's letter landed.** The four `ASSERT_EQ("UncutFaceComponentOrbitSeedNotUnique", …)` lines were removed from
  ordinals 390, 393, 406 and 407 and nothing else in the test file changed.
- **CS5 landed.** Selector 408 is byte-unchanged, LF SHA-256
  `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`, and no identity was added.

### 1.1 Both falsifiers held, and the product advanced again

DEFN-R4 stated two falsifiers before the build. A complete search of all 408 raw logs finds **zero** emissions of
`TraceArcDoesNotSeparateItsSides` — **R4.3 upheld**, the retirement is correct and the merge it authorized causes
no downstream failure — and **zero** emissions of `UncutFaceComponentOrbitSeedNotUnique` — **R4.1 upheld**.

366/367 now terminate at **`RegionBoundaryNotSingleWalk`**. `validate_single_boundary_walk` is called from
`build_region_certificates`, which runs after `build_regions` and after `build_fragment_corner_incidence`, so this
is **strictly further along than the retired guard**. CS6 named this outcome explicitly as permitted.

**Two guards cleared in two turns**, each with its falsifier stated first and checked afterwards. Certified
ownership is retained at `sourceFaceCount=300; established=300; unavailable=0; conflicting=0`.

---

## 2. CT1 — CS3 is unmet, and DEFN-R4.5 was under-specified

**390, 393, 406 and 407 remain RED.** CS6 required them to return to PASS.

DEFN-R4.5 said a witness *"must assert the **evidence**, not **which** typed failure produced it"*, and CB37
implemented that literally: it deleted the four code assertions. But each identity's very next lines are

```cpp
ASSERT_TRUE(locus.uncutFaceComponent.has_value());
ASSERT_TRUE(locus.uncutFaceComponentCertifiedFaceDistinctCount.has_value());
```

and the assertions after them are about the **uncut-component seed stage** — a stage the plan **no longer fails
at**. Removing the code assertion does not help when the evidence the identity demands is itself the product of the
eliminated failure path.

**That gap is in my definition, not in CB37's implementation.** DEFN-R4.5 fixed *how* an identity names a failure
and said nothing about an identity whose whole subject is a stage that has been cleared. The precedent existed and
I did not apply it: **DEFN-R3.7** retired ordinal 385's seed-relative expectation on exactly this reasoning — *"its
expectation becomes meaningless once the seed ceases to exist"* — and ordinal 390 already carries a
`status=guard-cleared` early return for the case where the stage is passed. That early return's condition,
`mechanical.plan.has_value()`, is simply **too strong**: it fires only when the *whole plan* succeeds, not when
*this stage* is cleared and a later one fails.

**The repair is to make "this stage was cleared" a first-class, justified outcome**, not the absence of evidence.
CT4 freezes it.

### 2.1 What I cannot determine, and why that is now the blocking gap

The four identities carry many assertions each. **Which one fails is not in the report.** The frozen TB32 plan
required a focused raw index containing exactly these ordinals, and the logs contain the answer, but the report
publishes only the row states.

This is the **third consecutive turn** in which the failing assertion text for the plan's own focused ordinals was
not transcribed. At TB29 the review had to infer it and CB35's later transcription confirmed the inference; at
TB31 the review deferred it and DEFN-R4 resolved it from source instead; here neither route closes it, because the
answer depends on runtime values.

I am not going to guess between "the locus fields are absent" and "a later assertion disagrees" — the two imply
different corrections. **CT5 makes the transcription a hard condition of TB acceptance rather than a request.**

---

## 3. CT2 — CB37 back-fills seed-stage evidence onto later failures

`region_frontier_component` (`:656–…`) resolves the component to annotate by, in order: `failure.uncutFaceComponent`
if already set; else `failure.sourceFace` looked up in `frontier.partition.componentByFace`; else `failure.region`
matched against the region list. `annotate_region_frontier_evidence` then populates the `uncutFaceComponent*`
fields.

So on a `RegionBoundaryNotSingleWalk` failure — where **no uncut component failed** — the locus can still report
`uncutFaceComponent`, its face count, its seed count and its seed state, resolved from an *associated* face or
region.

**DEFN-R4.4 did not authorize this.** It required the failing-component **face-set digest**, the certifier census
identity and the `censusCorrespondence` / subset relation to publish on every region failure locus. It did not ask
for the seed guard's own diagnostic fields to be synthesized onto failures the seed guard did not raise.

The hazard is the one this checkpoint keeps paying for: a future reader — or a witness — sees
`uncutFaceComponent=0, seedCount=1, seedState=Unique` on a failure and concludes the seed stage is implicated. It
is not. **Evidence must say which stage it describes.** CT3 requires that label.

I record this as a defect in my own measure's precision rather than in CB37's judgement: the implementation is a
reasonable reading of "publish the frontier evidence on every failure locus".

---

## 4. CT3 — the ledger digest is not a semantic fingerprint

**TB32's ledger SHA-256 is `6632f428…d563250b` — byte-identical to TB31's.**

This is not an error, and TB32 is genuinely a new execution: distinct run/job `34024893763 / 101464028080`,
distinct package `9983643195` and source `7f63b5f4…`, distinct result/log artifacts `9986786215 / 9986786399`, and
**distinct package, packaged-source and execution-view censuses**. The failure reasons changed completely.

The ledger's columns are `ordinal, identity, binary, exit, selected, result, raw_log`. None encodes *why* a row
failed. Two runs whose per-row pass/fail is identical therefore hash identically **even when every failure reason
differs** — which is exactly what happened.

That matters because the ledger digest has been quoted turn after turn as the run's semantic identity. It is a
**pass/fail fingerprint**, nothing more. Combined with §5's label defect, TB32's provenance rests on the artifact
digests and censuses, not on the ledger hash. `LESSONS.md` 141.

---

## 5. CT4 — the provenance label defect

`baseline-authority.txt` records `TB32 run=34011402843`, which is **TB31's** run id, because the deterministic
harness was materialized from the preserved TB31 harness blob and *"renamed historical TB31 orchestration labels
globally"*.

**Adjudication: cosmetic, and the run's identity is not in doubt.** Every independent identifier — workflow
run/job, result and log artifacts and their digests, package artifact and digest, source SHA, three censuses,
harness SHA — is distinct from TB31 and internally consistent. EXEC disclosed the defect itself and preserved the
raw artifact unchanged, which is the right handling.

**But it must not recur.** A harness that produces its identity by search-and-replace over a previous turn's labels
will eventually mislabel something that is not cosmetic, and a reviewer who trusted `baseline-authority.txt` would
have compared TB32 against itself. CT6 fixes the materialization.

---

## 6. CT5 — classification of the 11 RED ordinals

| Ordinal | Classification |
|---|---|
| 366, 367 | **The frontier, advanced again.** `RegionBoundaryNotSingleWalk`, strictly later than the retired guard. Not a regression — the previous stop no longer occurs anywhere in 408 logs. |
| 390, 393, 406, 407 | **Pinned witnesses, still unmet**, §2. Their subject is a stage the plan no longer fails at. Test authority; owner **CT4**. |
| 398 | **Carried sphere surface**, `prescribed sphere: NotProductionReady/CellularityNotEstablished`. **Not an ownership gate.** Owner: `M3-CP4c2-TB-X2-CAND-04`. Untouched. |
| 368, 369, 370, 374 | **Unchanged carried surfaces** with separate owners. Untouched. |

**The credibility rows behaved as required:** 368, 369, 370, 374 and 398 all stayed RED, none being touched by
CB37. Accepted **1–365 = 365/365**, no accepted RED ordinal. Ordinals **404 and 408 remain PASS** — the two
identities that assert publication and completeness rather than an outcome have now survived **three** consecutive
forward steps.

---

## 7. CT6 — stable accounting

**No stable event, category, or recurrence is added.** Totals remain **44 events / 14 categories / 30
recurrences**, produced-witness debt **5**, semantic M3 package count **97** (CB37).

1. accepted **365/365** with no accepted RED ordinal and **no accepted-green loss** — the third product change on
   this frontier and the boundary held again;
2. **390/393/406/407 are unchanged from TB31**, not new REDs. They are evidence-contract failures whose subject was
   eliminated by progress;
3. **366/367 advanced**; the prior stop appears nowhere in the run;
4. 368/369/370/374/398 are already-counted carried surfaces;
5. the `baseline-authority.txt` label defect is a control-plane labelling error with no semantic ledger effect,
   §5.

---

## 8. CT7 — candidates

**Closing.**

- `M3-CP4c3-TB31-REV-CAND-01` — the fragment-ownership question. **CLOSED / runtime-proved.** The guard is retired,
  the merge causes no downstream failure, and `TraceArcDoesNotSeparateItsSides` appears nowhere in 408 logs.
- `M3-CP4c3-TB31-REV-CAND-03` — frontier evidence attached to one failure path. **CLOSED / IMPLEMENTED.** CS2 is in
  source at two annotation sites. Its *over*-reach is carried forward as CAND-02 below rather than left inside a
  closed candidate.

**Carried.**

- `M3-CP4c3-TB31-REV-CAND-02` — the four pinned witnesses. **ACTIVE / GATING**, and **re-scoped**: the defect is
  not that they name a failure code — that was removed — but that their subject is a stage the plan no longer fails
  at. Owner: **CT4**.
- `M3-CP4c3-TB26-REV-CAND-04` / `M3-CP4c3-DEFN-R3-CAND-01` (two partitions), `M3-CP4c3-TB30-REV-CAND-02`,
  `M3-CP4c3-TB27-REV-CAND-02`, `M3-CP4c3-TB22-REV-CAND-01`, `M3-CP4c3-TB18-REV-CAND-01`, `M3-CP4c3-TB7-CAND-02`,
  `M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`, `M3-CP4c2-TB-X2-CAND-04` (also 398),
  `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, finalize/contact fall-through — unchanged.

**New.**

- `M3-CP4c3-TB32-REV-CAND-01` — **NEW / ACTIVE / GATING / EVIDENCE INTEGRITY.** Seed-stage `uncutFaceComponent*`
  fields are back-filled onto failures the seed guard did not raise, resolved from an associated face or region.
  Owner: **CT3**.
- `M3-CP4c3-TB32-REV-CAND-02` — **NEW / ACTIVE / EVIDENCE SURFACE.** The ledger digest encodes pass/fail only and
  was byte-identical across two runs with entirely different failure reasons. Owner: **CT5**.
- `M3-CP4c3-TB32-REV-CAND-03` — **NEW / ACTIVE / ORCHESTRATION.** Harness materialization by global relabelling of
  a previous turn's identity produced `TB32 run=<TB31 run>` in `baseline-authority.txt`. Owner: **CT6**.

---

## 9. CT3–CT7 — frozen successor: `M3-CP4c-3-CB38`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`. **No change to product topology, barriers,
ownership, or the retired guard.**

### CT3 — evidence must say which stage it describes

Frontier evidence published on a failure locus carries a **typed stage label** identifying the stage that raised
it. The `uncutFaceComponent*` fields are populated **only** when the uncut-component stage is the raising stage;
on a later-stage failure they are absent, and the DEFN-R4.4 fields — failing-component face-set digest, certifier
census identity, `censusCorrespondence` / subset relation — publish with the label saying so.

**This narrows DEFN-R4.4 rather than extending it**, and it is a correction to my own measure's precision, not to
CB37's reading of it.

### CT4 — the four witnesses get a justified cleared-stage outcome

Ordinals **390, 393, 406, 407** are replaced **in place**; ordinals, names and selector bytes unchanged; all remain
**gating**. Each must assert:

- **if the uncut-component stage raised the failure** — its stage label is present — every evidence field the
  identity owns is published, complete and untruncated, exactly as today; **or**
- **if a later stage raised it** — the plan cleared the uncut-component stage — the identity passes **only when the
  later failure publishes the DEFN-R4.4 frontier evidence with its stage label**. Absence alone is not a pass.

This is `guard-cleared` generalized from *"the whole plan succeeded"* to *"this stage was cleared"*, and it follows
the DEFN-R3.7 precedent for ordinal 385. **It is a restoration, not a weakening:** each identity still fails if its
stage fails without publishing, and still fails if a later stage fails without frontier evidence.

### CT5 — a digest that distinguishes failure reasons

The TB ledger gains a per-row **failure-detail digest** — or a separate diagnostic digest is published alongside it
— so that two runs differing only in *why* rows failed cannot produce the same fingerprint. The existing ledger
columns are unchanged so historical hashes stay comparable.

### CT6 — harness materialization must not relabel

The artifact-only harness must be parameterised by turn identity rather than produced by search-and-replace over a
previous turn's labels, and `baseline-authority.txt` must record **the executing run**. TB32's raw artifact stays
unchanged as provenance.

### CT7 — the next TB report must transcribe failing assertions

**Hard requirement, not a request.** `M3-CP4c-3-TB33`'s report must include, for **every** RED ordinal in the
plan's focused index, the failing assertion text or exception detail from the retained logs. A report that omits it
is **incomplete**, and the review that reads it must say so rather than infer. Three consecutive turns have lost a
turn to this.

### Falsification, stated before the build

- If 390/393/406/407 still fail after CT4 **with their stage-labelled evidence published**, then
  `M3-CP4c3-TB31-REV-CAND-02`'s re-scoping is wrong and the defect is in the evidence contract, not the stage
  premise.
- If any of `TraceArcDoesNotSeparateItsSides` or `UncutFaceComponentOrbitSeedNotUnique` reappears, CB38 changed
  product behaviour it was forbidden to touch.
- If 366/367 move to a **stage earlier** than `RegionBoundaryNotSingleWalk`, CB38 regressed the pipeline.

### Prohibited in CB38

1. Any change to product topology, barriers, ownership, the retired guard, or the separating-arc rule.
2. Weakening or re-scoping **ordinal 398** (prescribed sphere), or touching 368/369/370/374.
3. Relaxing any assertion 390/393/406/407 legitimately own; absence of evidence may never be a pass on its own.
4. Changing any accepted identity 1–365, or any byte of selector 397–408. **Selector 408 stays unchanged**; if a
   witness is required it appends as **409** with 408 as an exact prefix.
5. Any new diagnostic contract on source-face ownership. It is closed.
6. Executing any Directional runtime.

---

## 10. Consolidation performed

Per `CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW turn". Durable facts were verified present in this
record, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md`
before any fold. **The retained ownership census `300 / 0 / 0`, the component-0 fingerprint `189 / 1 / Unique /
[0]`, and the fact that neither retired failure code appears in 408 logs are preserved in §§1–2 above.**

Folded: `Architecture_M3_CP4c3_TB31_EXEC_Report.md` (superseded runtime authority),
`Architecture_M3_CP4c3_TB31_Artifact_Only_Test_Benchmark_Plan.md` (consumed contract),
`Architecture_M3_CP4c3_TB31_Independent_Review_Record.md` (superseded review authority, CR0–CR8 — its §2.2
inference was corrected by DEFN-R4 and its CAND-01 is now closed),
`Architecture_M3_CP4c3_CB37_Code_Build_Report.md` (consumed build report — CS1/CS2/CS3/CS5 verified in source
above).

Retained as current authority: `Architecture_M3_CP4c3_TB32_EXEC_Report.md` (**the valid semantic runtime
authority**), `Architecture_M3_CP4c3_TB32_Artifact_Only_Test_Benchmark_Plan.md`, this record,
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md` (**Part VIII is the operative definition**),
`Required_Green_Selector_Manifest.md`, `M3_CP4c_Consolidated_Record.md`, and every
`Required_Green_Selector_*.txt`. **Never folded:** the artifact-only harness scripts are the instrument, not
documents.

## 11. Lessons added

`LESSONS.md` **141** — a pass/fail ledger digest is not a semantic fingerprint.
`LESSONS.md` **142** — when a stage stops failing, a witness of that stage needs a *justified cleared* outcome, not
a deleted assertion.

## 12. Exact successor

**`M3-CP4c-3-CB38`** under **CT3–CT7**, Code + Build, runtime-free. Stage-labelled evidence, four witnesses given a
justified cleared-stage outcome, a digest that distinguishes failure reasons, a harness that does not relabel, and a
TB report obligation that closes a three-turn evidence gap.
