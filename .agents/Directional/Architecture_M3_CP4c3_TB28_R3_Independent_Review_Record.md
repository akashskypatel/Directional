# M3-CP4c-3-TB28-R3 Independent Review Record

## Status

**COMPLETE / STATIC / NO RUNTIME / NO COMPILE / NON-STABLE / CONTROL PASSED / CB34 AUTHORIZED.**

`M3-CP4c-3-TB28-R3-REV` is evidence-only review. It executed no Directional runtime, no compile, no package
operation, and mutated no product, test, fixture, benchmark, build or selector byte.

**The control passed.** `M3-CP4c-3-TB28-R3` reproduced the known-red baseline on the unchanged package, so the
harness is fit and **TB28-R3 is promoted to current valid semantic runtime authority**: selector **407**,
**400 PASS / 7 RED**, accepted **1–365 = 365/365**, RED `[366, 367, 368, 369, 370, 374, 398]`. The accepted-prefix
count, which TB28-REV recorded as *unestablished*, is **restored to 365/365**.

**The frozen CM9 sequence may proceed to `M3-CP4c-3-CB34`.** The separating-arc barrier correction stands verbatim
and is not re-opened here.

`review_check.py authority 098ac7d93ea203222dd0ac50cdb68667744f0fd4` — **ALL CHECKS PASSED**.

---

## 1. CN0 — the control, and why it is credible

The credibility gate CM8 set was: *the run is credible only if ordinals 366, 367 and 398 are RED*, because the
product had not changed since TB27-R1 and they were RED then.

**All three are RED.** More than that, the whole ledger reproduces the baseline exactly:

| | selector | PASS | RED | RED ordinals |
|---|---|---|---|---|
| TB27-R1 | 406 | 399 | 7 | 366, 367, 368, 369, 370, 374, 398 |
| **TB28-R3** | **407** | **400** | **7** | **366, 367, 368, 369, 370, 374, 398** |

Selector 407 is selector 406 plus exactly one identity, and ordinal 407 PASSes. **The delta between the two runs is
exactly the appended identity and nothing else.** That is a stronger result than the gate required: not only did
the three control ordinals reappear, the entire 406-row prefix is unchanged in outcome.

By contrast TB28-R2, on the *same package*, reported 407 PASS / 0 RED. Two runs of one immutable artifact differing
by seven ordinals settles which of them was measuring the product.

### 1.1 The control was genuinely a control

- **No product change.** `git diff b580e203..HEAD -- src include tests` is **empty**. CB33 touched only the harness
  and the plan.
- **Same package, same source.** Artifact `9975737868`, source `098ac7d93ea203222dd0ac50cdb68667744f0fd4`,
  provider digest unchanged.
- **CB33 deliberately did not recompile**, and its report states why: a replacement compile would have created a
  new package/source authority and defeated the control experiment. That is the right call and it is the reason
  this comparison means anything.

---

## 2. CN1 — the harness now proves selection, verified in source rather than taken on trust

The repaired harness is committed at `.agents/Directional/tools/m3_cp4c3_tb28_r3_harness.sh`, so this review
checked the mechanism itself rather than the report's summary of it:

- **Exactly one binary owner per identity is enforced, not assumed.** The owner map is built by parsing the
  selector, the CMake test targets and the `TEST*` declarations, and it **raises** when an identity's owner count is
  not exactly one (`:311–314`).
- **Every mapped binary must exist and be executable in the package** (`:326–327`), and each staged executable must
  match the package by **digest and mode** (`:336–337`).
- **GoogleTest is told to fail on an empty selection** — `GTEST_FAIL_IF_NO_TEST_SELECTED=1` (`:415`).
- **The selection count is measured independently of the exit code**, by counting `[ RUN      ]` lines in the raw
  log (`:421`).
- **`result=PASS` requires `selected == 1` **and** `exit == 0`** (`:423–424`); anything else is RED. A row that
  selects zero tests can no longer pass.
- The summary computes `accepted_red` over ordinals ≤ 365 (`:460`) and emits
  `control_known_red_reproduced` over {366, 367, 398} (`:472`) — **the CM8 gate implemented inside the instrument**.

Every ledger row records `selected=1`, `selection_integrity=true`, and there are 407 rows, 407 raw logs and 407
resource records with `timeout_count=0`.

### 2.1 Independent confirmation that single-binary routing was the fault

I reconstructed the owner map locally from the repository: all **407** selector identities resolve, none
unmapped, and they are spread across **15 distinct test source files** — 120 in
`FieldAlignedCurveNetworkTests.cpp`, 93 in `SurfaceCellsPhase10Tests.cpp`, 48 in
`PureQuadCompletionPhase18Tests.cpp`, and so on. Those compile into several distinct test executables.

So routing every row to one binary leaves the large majority unmatched, and with `exit 0` read as PASS that
manufactures precisely the green TB28-R2 reported. **`M3-CP4c3-TB28-REV-CAND-01`'s named mechanism is confirmed**,
and the repair addresses it directly.

---

## 3. CN2 — plan obligation 6 is **not** discharged, and I am not pretending otherwise

The frozen R3 plan §6 required the run to *"publish/adjudicate the census for the **191-face failing component**"*,
including the component/domain/face-set identities needed to compare that object. Review obligation 6 is to
evaluate it.

**The EXEC report does not contain it.** It records that ordinals 404, 406 and 407 are PASS and defers "the 191-face
ownership-census assessment" to this review without carrying the values. There is nothing in the retained record to
evaluate.

This is a **report-completeness** gap, not a measurement gap: 404/406/407 passing means the census *was* published
at runtime, into the raw logs inside immutable artifact `9978114502`. The data exists; no retained document holds
it.

**It does not block CB34, and I want to be explicit about why that is a judgement and not an oversight.** The
census would tell us *which* branch of the CL6 dichotomy is true. The frozen correction was written to be
sound-by-construction on **both** branches — that was the entire purpose of pre-naming a default at CL8. So the
missing census changes nothing about what CB34 must do. What it does change is the project's evidence trail, and
that is worth one transcription, which CN7 requires.

I note the pattern without inflating it: this is the third consecutive turn in which a required datum existed in the
system and was absent from the record a reviewer reads. TB26 computed the orbits and printed counts; TB28-R2
published nothing; TB28-R3 published to an artifact and not to a document. `LESSONS.md` 131.

---

## 4. CN3 — classification of the 7 RED ordinals

Unchanged from TB27-R1 in every case; no new regression is observed and none is invented.

| Ordinal | Classification |
|---|---|
| 366, 367 | **The open frontier**, correctly failing closed on three conflicting owners. This is what CB34 corrects. |
| 398 | **The honest gate.** `proves_cellularity()` is false because ownership genuinely is incomplete. Untouched. |
| 368, 369, 370, 374 | **Unchanged carried surfaces** with separate owners — prescribed sphere, saturation, typed-error locus, folded cone. Untouched. |

**Accepted prefix 1–365: 365/365 PASS**, no accepted RED ordinal, no accepted-green loss. New ordinal **407**
PASSes; **404** and **406** PASS.

---

## 5. CN4 — stable accounting

**No stable event, category, or recurrence is added.** Totals remain **44 events / 14 categories / 30
recurrences**, produced-witness debt **5**, semantic M3 package count **93** — CB33 compiled nothing, so the count
does not advance.

1. accepted **365/365** with no accepted RED ordinal;
2. the 7 RED ordinals are the already-counted carried set and the open frontier;
3. TB28-R1 and TB28-R2 remain orchestration-invalid provenance with no semantic credit; an invalid gate produces no
   regression to classify;
4. **the accepted-prefix count is restored from *unestablished* to 365/365** — a restoration of a statement, not a
   change in behaviour.

---

## 6. CN5 — candidates

**Closing, runtime-proved.**

- `M3-CP4c3-TB28-REV-CAND-01` — the false green. **CLOSED.** Its falsification condition was *"falsified when
  TB28-R3 reproduces the known REDs with a per-row `selected` column"*, and that is exactly what happened: 7/7 REDs
  reproduced, every row `selected=1`, and the mechanism verified in the harness source.

**Carried, narrowed.**

- `M3-CP4c3-TB28-REV-CAND-02` — the off-object census. **ACTIVE / EVIDENCE INTEGRITY**, narrowed from "published
  from the wrong path" to "**published at runtime but not transcribed into any retained record**". Owner: **CN7**.

**Unchanged, and none of them discharged by this turn.** `M3-CP4c3-TB27-REV-CAND-01` (**the correction is frozen
for it**), `M3-CP4c3-TB27-REV-CAND-02`, `M3-CP4c3-TB26-REV-CAND-04`, `M3-CP4c3-DEFN-R3-CAND-01`,
`M3-CP4c3-TB25-REV-CAND-02`, `M3-CP4c3-TB24-REV-CAND-02`, `M3-CP4c3-TB22-REV-CAND-01`,
`M3-CP4c3-TB18-REV-CAND-01`, `M3-CP4c3-TB7-CAND-02`, `M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`,
`M3-CP4c2-TB-X2-CAND-04`, `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, finalize/contact
fall-through.

---

## 7. CN6–CN7 — the decision, and the one added obligation

### CN6 — proceed to `M3-CP4c-3-CB34`

The only decision this review owns is whether the frozen CM9 sequence proceeds or the harness is replaced. **It
proceeds.** The instrument reproduces the baseline, proves selection per row, and is verifiable in source.

`M3-CP4c-3-CB34` implements **CM9 exactly as frozen at `M3-CP4c-3-TB28-INDEPENDENT-REVIEW` §4**, restated here for
the successor's convenience and **not** amended:

> **The separating-arc barrier rule.** In `build_source_face_ownership`, for every arc of `embedded.arcs` whose two
> darts satisfy `orbitByDart[forwardDart] != orbitByDart[reverseDart]`, the arc's source edges enter `barriers`,
> and every source face the arc crosses is treated as trace-cut and therefore excluded from `uncutFaces`.

with CM9's conditions unchanged: barriers and trace-cut status key on the orbit inequality rather than on
`terminalSlit`; non-separating arcs are untouched; **accepted-prefix safety is demonstrated by construction**, not
argued, by showing the rule is a no-op wherever the current code already inserts the same barrier and enumerating
what changes where it does not; `proves_cellularity()` and ordinals 397–407 keep their contracts and **no ordinal
is weakened to obtain a green**; and any required witness appends as **408** with 407 as an exact prefix, asserting
the rule's effect on the census and never a predicted owner value.

**This review may not, and does not, re-derive, widen or narrow that correction.**

### CN7 — transcribe the census into the record

CB34's closeout, or the TB report that follows it, must transcribe the **191-face failing component's** ownership
census from the immutable evidence into a retained document: component and domain identities, face-set digest,
face count, the interior-arc rows with both dart orbits and crossed faces, and the seed attributions. This is a
transcription of evidence that already exists, **not a new diagnostic**, so CL8 is untouched.

If the transcription shows the correction changed the census in a way CM9 did not anticipate, that is a finding for
the review that reads it — not a licence to re-open the rule before it has been measured.

### Prohibited in CB34

1. Re-deriving, widening, narrowing or deferring the frozen correction.
2. Changing any accepted identity 1–365, or any byte of selector 397/401/403/405/406/407.
3. Weakening `proves_cellularity()` or any ordinal 397–407 to obtain a green.
4. Any second product change — no attribution-rule edit, no seed winner, no partition unification. **One
   correction.**
5. Any new diagnostic contract on source-face ownership. CL8 stands.
6. Executing any Directional runtime.

---

## 8. CN8 — a note on the turn that produced this evidence

CB33 and TB28-R3 did the thing this checkpoint has struggled with for eight turns: they **changed one variable and
measured it against a known baseline**. No compile, no package change, no product edit, one harness repair, and a
result that can be compared line-for-line with its predecessor. The instrument was also committed to the repository
so a reviewer can read it instead of trusting a summary of it.

The EXEC report additionally self-reports a start-of-turn conservation miss — three direct reads before the
snapshot was materialized — and records that it stopped and switched. Recording one's own procedural slip when it
changed no evidence is the behaviour that makes the rest of the report credible, and it is worth saying so.

## 9. Consolidation performed

Per `CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW turn". Durable facts were verified present in this
record, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md`
before any fold.

Folded: `Architecture_M3_CP4c3_TB27_R1_Artifact_Only_Test_Benchmark_Report.md` (superseded runtime authority — it
was retained through TB28 precisely because TB28-R2 was rejected, and TB28-R3 now supersedes it validly),
`Architecture_M3_CP4c3_TB28_R2_Artifact_Only_Test_Benchmark_Report.md` (rejected attempt — its rejection and the
reasons are preserved in `M3_CP4c_Consolidated_Record.md`, the tracker and the TB28 review record),
`Architecture_M3_CP4c3_TB28_Artifact_Only_Test_Benchmark_Plan.md` (consumed contract, superseded by the R3 plan),
`Architecture_M3_CP4c3_TB28_Independent_Review_Record.md` (superseded review authority — **its §4 frozen correction
is restated verbatim in §7 above before folding**).

Retained as current authority: `Architecture_M3_CP4c3_TB28_R3_EXEC_Report.md` (**the valid semantic runtime
authority**), `Architecture_M3_CP4c3_TB28_R3_Artifact_Only_Test_Benchmark_Plan.md` (the contract it executed),
`Architecture_M3_CP4c3_CB33_Code_Build_Report.md` and `Architecture_M3_CP4c3_CB32_Code_Build_Report.md` (the
harness correction and the package under test), `tools/m3_cp4c3_tb28_r3_harness.sh` (**the instrument, and not a
document — it is product-adjacent evidence and must not be folded**), this record,
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`,
`M3_CP4c_Consolidated_Record.md`, and every `Required_Green_Selector_*.txt`.

## 10. Lessons added

`LESSONS.md` **131** — evidence that exists only inside an artifact is not in the record.
`LESSONS.md` **132** — a control run is worth more than a clever measurement: change one variable, compare against
a known baseline.

## 11. Exact successor

**`M3-CP4c-3-CB34`** under **CM9** as frozen, plus **CN7**. Code + Build, runtime-free, GMP/GMPXX linked. One
product correction, demonstrated safe by construction on the accepted prefix, and one transcription of evidence
that already exists.
