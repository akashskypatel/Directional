# M3-CP4c-3-TB30 Independent Review Record

## Status

**COMPLETE / STATIC / NO RUNTIME / NO COMPILE / NON-STABLE / THE CERTIFIER HALF OF THE FRONTIER IS CLOSED.**

`M3-CP4c-3-TB30-REV` is evidence-only review. It executed no Directional runtime, no compile, no package operation,
and mutated no product, test, fixture, benchmark, build or selector byte.

**TB30 is promoted to current valid semantic runtime authority**: selector **408**, **401 PASS / 7 RED**, accepted
**1–365 = 365/365**, RED `[366, 367, 368, 369, 370, 374, 398]`. The credibility gate holds, every row records
`selected=1`, and all three byte+mode censuses are equal pre/post.

Three findings, in order of consequence:

1. **Source-face ownership is now total: `established=300 / unavailable=0 / conflicting=0`.** The certifier half of
   the frontier is **closed**.
2. **The frozen rule was applied at one of its two sites.** `GlobalTopologyPlan.cpp:830` still carries the
   unconditional terminal-slit skip, so the plan's partition is byte-identically unchanged and 366/367 fail exactly
   as before.
3. **Ordinal 398 is no longer an ownership gate.** It fails on the **prescribed sphere**, which has its own owner.

`review_check.py authority ab86747bdfdb94c7c383bf5d2893ced4207eb555` — **ALL CHECKS PASSED**.

---

## 1. CQ0 — CO6 and CO8 are discharged; every TB29-REV inference is confirmed verbatim

**390 and 404 return to PASS**, which was CO8's required outcome. Selector 408 is unchanged, no assertion either
identity legitimately owns was relaxed, and `git diff` over `src include` for CB35 is **empty** — test authority
only, exactly as CO6 scoped it.

CB35's CO7 transcription confirms both TB29-REV diagnoses **in the failing assertion text**, which is worth
recording because both were inferences at the time:

- **Ordinal 404** failed at `tests/FieldAlignedCurveNetworkTests.cpp:14350` with
  `Expected: (Established) != (owner->status), actual: <00> vs <00>` — **the owners were `Established`**. The
  regression was the correction working, exactly as inferred, and the loop was the out-of-contract clause.
- **Ordinal 390** failed at `:11575` with `3` versus `1`: the plan locus reported 3 distinct certified faces while
  the certifier census it matched **by index** reported a single seed orbit. Two different objects, compared
  because their integers agreed.

CB35's repair matches the census by **face-set digest**, falls back to the published census digest when the failing
component is a recorded subset, compares seed-orbit counts **only on an exact match**, and otherwise asserts the
published subset flag is false. That is CO6's requirement met in the strong form: match by identity, and **degrade
honestly** when no correspondence exists.

`M3-CP4c3-TB29-REV-CAND-01` and `M3-CP4c3-TB29-REV-CAND-02` are **CLOSED / runtime-proved** on their own stated
falsification conditions.

---

## 2. CQ1 — ownership is total; the certifier half of the frontier is closed

From CB35's CO7 transcription of TB29 log artifact `9980019636`:

```
m3Cp4c3CertifiedOwnerPublication;sourceFaceCount=300;established=300;unavailable=0;conflicting=0;
conflictCensusPublished=true;conflictRowCount=0
```

**300 of 300 source faces have established, singleton ownership. Zero unavailable. Zero conflicting.**

Set against the history this checkpoint has been carrying:

| turn | established | unavailable | conflicting |
|---|---:|---:|---:|
| TB25-R1 | 74 | 226 | 0 |
| **TB29 (post-correction)** | **300** | **0** | **0** |

The post-correction uncut census contains **only arcs 20 and 24**, both `0 / 0`; **arcs 14 and 22 are absent** —
the separating arcs no longer meet any uncut component's interior. That is ordinal 408's contract, now visible in
the census rather than only in a PASS.

**The question this checkpoint opened at TB19 — can certified source-face ownership be established? — is
answered: yes, and it is established for every face.** The seven-turn diagnostic chain, the frozen dichotomy and
the barrier rule it selected all land on this line.

---

## 3. CQ2 — the frozen rule was applied at one of its two sites

**366 and 367 fail identically to their pre-correction state.** From the transcribed exception:

```
UncutFaceComponentOrbitSeedNotUnique; sourceFace=10,79,151;
uncutFaceComponent=0; uncutFaceComponentSeedCount=3; uncutFaceComponentSeedState=Multiple;
uncutFaceComponentFaceCount=191; seedOrbits=[0,1,3]
```

Same component, same 191 faces, same three seeds, and the locus source face **`10,79,151`** is arc 22's
terminal-slit face. The reason is visible in the source and is not subtle:

- `SurfaceCutGraph.cpp:549` now reads `if (terminalSlit && !separatesCertifiedFaces)`;
- **`GlobalTopologyPlan.cpp:830` still reads `if (is_terminal_slit(*trace, segmentIndex))`**, unconditionally, and
  a search of that file for `separatesCertifiedFaces` or `forwardOrbit != reverseOrbit` returns **nothing**.

That skip governs three things at once — `tracePieceCount`, `add_fragment_orbit`, and
**`traceTouchedEdges.insert(...)` for both carriers**. `traceTouchedEdges` is one of the three families in
`componentBarriers`, so the plan's barrier set still omits arcs 14 and 22's carriers, its `EmptyFragmentOrbits`
partition is unchanged, and its component 0 is still the same 191 faces — the failing face-set digest is still
**`17919102493633069558`**, byte-identical to CB34's pre-correction transcription.

**This is not a defect in the correction. It is the correction applied to one of the two sites that carry the same
rule.** CB34's change was scoped exactly as frozen; the freeze named `build_source_face_ownership`, and the second
site was not named because at the time the plan's partition was not known to be governed by an independent copy of
the same guard.

### 3.1 The divergence is now measurable, and ordinal 390 measures it

The corrected ordinal 390 emits **`censusCorrespondence=none`** and takes its else-branch, which asserts that the
published subset flag is **false**. Before the correction the failing component was a strict subset of a certifier
census component; now it is a subset of none.

**The two partitions have diverged further, not converged.** The certifier removed the separating arcs' crossed
faces from `uncutFaces`; the plan kept them. `M3-CP4c3-TB26-REV-CAND-04` and `M3-CP4c3-DEFN-R3-CAND-01` — two
independent constructions of one topology — are no longer background architecture debt; they are **the reason the
frontier is still open**, and the second application of the rule is what re-converges them.

---

## 4. CQ3 — ordinal 398 is no longer an ownership gate

For many turns this record has described 398 as *"the honest gate on ownership totality"*. That description is now
**wrong**, and it would mislead the next reader if left standing.

Ownership totality is satisfied — 300/300. 398's transcribed failure is:

```
tests/FieldAlignedCurveNetworkTests.cpp:14146: Failure
Value of: fixture.cutGraph.has_value()  Actual: false  Expected: true
prescribed sphere: NotProductionReady/CellularityNotEstablished
```

**It fails on the prescribed sphere**, whose surface is ordinal 368's `RotationSystemInconsistent →
TraceEventPositionInvalid`, trace 2 / event 30, owned by `M3-CP4c2-TB-X2-CAND-04` and explicitly deferred.

Consequences the successor must not get wrong:

- **The ownership frontier is 366 and 367 only.** 398 will not go green from any ownership correction and must not
  be used to judge one.
- **398 is still not to be weakened or re-scoped.** It legitimately asserts totality across production fixtures,
  and the sphere is a production fixture. It goes green when the sphere does.

---

## 5. CQ4 — classification of the 7 RED ordinals

| Ordinal | Classification |
|---|---|
| 366, 367 | **The ownership frontier, and now the only ordinals on it.** Identical failure to pre-correction, because the plan-side terminal-slit skip is unchanged. Corrected by CQ6. |
| 398 | **Carried sphere surface**, §4 — reclassified from "ownership gate". Owner: `M3-CP4c2-TB-X2-CAND-04`. Untouched. |
| 368 | `RotationSystemInconsistent / TraceEventPositionInvalid`, trace 2 / event 30. Unchanged, separately owned. |
| 369 | `saturationUsed=true` where the identity expects false. Unchanged, separately owned. |
| 370 | Wrong typed error code and missing source-face locus. Unchanged; **no correction authorized**. |
| 374 | Folded-cone `atlasBuild=false`. Unchanged, deferred. |

Nothing in this set is new, and **the RED set is the same seven carried surfaces as TB27-R1 and TB28-R3** — with
the whole diagnostic scaffolding now returned to green and one identity added.

---

## 6. CQ5 — stable accounting

**No stable event, category, or recurrence is added.** Totals remain **44 events / 14 categories / 30
recurrences**, produced-witness debt **5**, semantic M3 package count **95** (CB35).

1. accepted **1–365 = 365/365** with no accepted RED ordinal and no accepted-green loss;
2. **390 and 404 recovered**; recovery is not an event, and their earlier RED was already classified as an
   evidence-contract failure rather than a behaviour loss;
3. the seven RED ordinals are all already-counted carried surfaces;
4. selector 408 is unchanged and no identity was added, removed, weakened or re-scoped.

**Arithmetic check:** TB28-R3 was 400 PASS / 7 RED on selector 407; TB30 is 401 PASS / 7 RED on selector 408 =
407 + 1, and ordinal 408 PASSes. The delta is exactly the appended identity.

---

## 7. CQ6 — candidates

**Closing, runtime-proved.**

- `M3-CP4c3-TB29-REV-CAND-01` — ordinal 404's out-of-contract value assertion. **CLOSED.** 404 PASSes; the failing
  text confirmed the owners were `Established`.
- `M3-CP4c3-TB29-REV-CAND-02` — ordinal 390's index matching. **CLOSED.** 390 PASSes and now matches by face-set
  digest, degrading honestly to `censusCorrespondence=none`.
- `M3-CP4c3-TB24-REV-CAND-02` — *ownership of non-arc-incident faces is a derivation, not a read.* **CLOSED /
  SATISFIED.** The derivation now succeeds for all 300 faces.

**Promoted.**

- `M3-CP4c3-TB26-REV-CAND-04` and `M3-CP4c3-DEFN-R3-CAND-01` — two partitions from two independent constructions.
  **PROMOTED to the active blocking cause.** They are no longer architectural background: the plan's partition is
  the only thing keeping 366/367 red, and `censusCorrespondence=none` measures the divergence. Owner: **CQ7**, with
  unification still a `DEFN` question.

**New.**

- `M3-CP4c3-TB30-REV-CAND-01` — **NEW / ACTIVE / GATING / PRODUCT.** The frozen separating-arc barrier rule is
  applied in `SurfaceCutGraph.cpp` but not at the second site that carries the same guard,
  `GlobalTopologyPlan.cpp:830`, so the plan's `traceTouchedEdges` still omits the separating arcs' carriers. Owner:
  **CQ7**. Falsified if applying it there leaves 366/367 failing with the same component and seeds.
- `M3-CP4c3-TB30-REV-CAND-02` — **NEW / ACTIVE / EVIDENCE SURFACE / NON-GATING.** The plan-side interior-arc census
  is a projection of the certifier's rows, so an arc that still cuts the **plan's** component but has left the
  certifier's uncut census is invisible to it. Arcs 14 and 22 vanished from both censuses while still splitting the
  plan's component. Owner: a later turn; **not** blocking CQ7.

**Carried, unchanged.** `M3-CP4c3-TB27-REV-CAND-02`, `M3-CP4c3-TB22-REV-CAND-01`, `M3-CP4c3-TB18-REV-CAND-01`,
`M3-CP4c3-TB7-CAND-02`, `M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`, `M3-CP4c2-TB-X2-CAND-04` (**now also
the owner of 398**), `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, finalize/contact fall-through.

---

## 8. CQ7–CQ8 — frozen successor: `M3-CP4c-3-CB36`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`. **One change: the same frozen rule, at its
second site.**

### CQ7 — apply the separating-arc barrier rule in `GlobalTopologyPlan`

At `GlobalTopologyPlan.cpp:830`, replace

```cpp
if (is_terminal_slit(*trace, segmentIndex)) { … continue; }
```

with the guard CB34 already uses, in the identical shape:

```cpp
const bool separatesCertifiedFaces = forwardOrbit != reverseOrbit;   // both already in scope at :805–806
if (is_terminal_slit(*trace, segmentIndex) && !separatesCertifiedFaces) { … continue; }
```

**This is not a new correction and it is not a re-opening.** It is the rule frozen at
`M3-CP4c-3-TB28-INDEPENDENT-REVIEW` §4, restated at CN6 and runtime-proved at TB29, applied at the second site that
implements the same guard. Nothing about the rule changes.

**Why the three consequences are all correct for a separating arc**, and why this is safe by construction:

- **`traceTouchedEdges`** gains both carriers — the defect, and the whole point;
- **`add_fragment_orbit`** labels the face with the two distinct orbits, matching the certifier already treating it
  as trace-cut, so the face leaves `unlabeledFaces` and the plan's component splits along the carriers;
- **`tracePieceCount` +1** keeps the fragment-count relation consistent: `expected = k + 1 = 2` against two
  published fragment orbits. The comment's premise — *"a terminal slit contributes zero to k"* — is true for a
  non-separating slit and false for a separating one, which is precisely the distinction the guard now draws.
- **Non-separating arcs are untouched.** Arcs 20 and 24 (`0 / 0`) keep the exclusion exactly as today, so the
  no-over-cut property CB34 established holds here too.

**Accepted-prefix safety must be demonstrated by construction, not argued** — as at CB34: show the change is
reachable only on the terminal segment of an arc whose two darts lie in different face-walk orbits, and enumerate
what differs there.

**Falsification, stated before the build.** If TB31 shows 366/367 still failing with `uncutFaceComponent=0`,
`faceCount=191` and `seedOrbits=[0,1,3]`, then `M3-CP4c3-TB30-REV-CAND-01` is falsified and the plan's partition is
governed by something other than this skip. If `TraceCutFaceFragmentCountMismatch` appears, the `tracePieceCount`
premise above is wrong and the correction must be narrowed to the `traceTouchedEdges` insertion alone.

### CQ8 — what TB31 must report, and what it must not conclude

- credibility gate: **366/367 are the ownership frontier**; a run that reports them green must also show the plan's
  component and seed state changed;
- the plan-side failing component after the correction — id, domain, face count, **face-set digest**, seed
  count/state/orbits — and whether `censusCorrespondence` is restored;
- the `established` / `unavailable` / `conflicting` counts, which must remain **300 / 0 / 0**;
- **ordinal 398 must not be read as an ownership signal.** It fails on the prescribed sphere and will stay RED
  until ordinal 368's surface is addressed by its own owner.

### Prohibited in CB36

1. Any change other than the guard at `GlobalTopologyPlan.cpp:830` and whatever is strictly required to keep it
   compiling. **No partition unification** — that remains a `DEFN` question.
2. Changing any accepted identity 1–365, or any byte of selector 397/401/403/405/406/407/408.
3. Weakening `proves_cellularity()` or any ordinal 397–408; **re-scoping ordinal 398 to exclude the sphere is
   expressly forbidden**.
4. Touching ordinals 368, 369, 370, 374 or their owners.
5. Any new diagnostic contract on source-face ownership. CL8 stands, and the census already publishes what is
   needed.
6. Executing any Directional runtime.

---

## 9. Consolidation performed

Per `CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW turn". Durable facts were verified present in this
record, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md`
before any fold. **CB35's CO7 census transcription and its per-ordinal failing-assertion text are preserved in §§1–4
of this record**, including the three numbers that matter — `300 / 0 / 0` — and 398's sphere locus, before its
source document is folded.

Folded: `Architecture_M3_CP4c3_TB29_EXEC_Report.md` (superseded runtime authority),
`Architecture_M3_CP4c3_TB29_Artifact_Only_Test_Benchmark_Plan.md` (consumed contract),
`Architecture_M3_CP4c3_TB29_Independent_Review_Record.md` (superseded review authority, CO0–CO8 — both its
test-authority diagnoses are runtime-confirmed), `Architecture_M3_CP4c3_CB34_Code_Build_Report.md` (consumed build
report — **the correction it carried is runtime-proved and its CN7 transcription is preserved above**),
`Architecture_M3_CP4c3_CB35_Code_Build_Report.md` (consumed build report — **its CO7 transcription is preserved
above**).

Retained as current authority: `Architecture_M3_CP4c3_TB30_EXEC_Report.md` (**the valid semantic runtime
authority**), `Architecture_M3_CP4c3_TB30_Artifact_Only_Test_Benchmark_Plan.md`, this record,
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`,
`M3_CP4c_Consolidated_Record.md`, and every `Required_Green_Selector_*.txt`. **Never folded:** the artifact-only
harness scripts are the instrument, not documents.

## 10. Lessons added

`LESSONS.md` **135** — when a rule is frozen, name every site that implements it.
`LESSONS.md` **136** — a gate's name outlives the reason it was red; re-read what it actually asserts before citing
it as evidence.

## 11. Exact successor

**`M3-CP4c-3-CB36`** under **CQ7–CQ8**, Code + Build, runtime-free. One guard, at the second site of a rule already
frozen and runtime-proved, with accepted-prefix safety demonstrated by construction.
