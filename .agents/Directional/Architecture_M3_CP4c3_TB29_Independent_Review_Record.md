# M3-CP4c-3-TB29 Independent Review Record

## Status

**COMPLETE / STATIC / NO RUNTIME / NO COMPILE / NON-STABLE / THE CORRECTION IS RUNTIME-PROVED.**

`M3-CP4c-3-TB29-REV` is evidence-only review. It executed no Directional runtime, no compile, no package operation,
and mutated no product, test, fixture, benchmark, build or selector byte.

**TB29 is promoted to current valid semantic runtime authority**: selector **408**, **399 PASS / 9 RED**, accepted
**1–365 = 365/365**, RED `[366, 367, 368, 369, 370, 374, 390, 398, 404]`. The credibility gate holds — 366, 367 and
398 are RED — selection integrity is `true` with every row `selected=1`, and all three byte+mode censuses are equal
pre/post.

**The frozen separating-arc barrier correction landed and works.** Ordinal 408 PASSes on all three of its
properties. **And the frontier question this checkpoint has carried since TB20 is now decided.**

The two new REDs — **390 and 404** — are **test-authority defects provable from the test source**, not product
regressions. Neither is caused by the correction being wrong; **404's failure is positive evidence that the
correction works.**

`review_check.py authority 25ab3d55697598bde436d1ac811d71e6cf911f2e` — **ALL CHECKS PASSED**. Selector 408 is
verified here as selector 407 plus exactly one identity, with 407 as its exact 407-line prefix.

---

## 1. CO0 — the correction landed, and ordinal 408 proves it on the right properties

CB34's product change is seven lines in `src/geometry/SurfaceCutGraph.cpp:538–549`:

```cpp
const bool separatesCertifiedFaces = forwardOrbit != reverseOrbit;
...
if (terminalSlit && !separatesCertifiedFaces) {   // was: if (terminalSlit)
```

That is the frozen rule implemented as a **guard relaxation on one existing path**. For a separating arc the
pre-existing body runs unchanged — `traceCutFaces.insert(segment.sourceFace)` plus both carrier insertions into
`barriers` — which is exactly *"the arc's source edges enter `barriers`, and every source face the arc crosses is
treated as trace-cut"*. For an equal-orbit arc nothing changes at all.

**Accepted-prefix safety is demonstrated rather than argued**, and the demonstration is structural: the only
behaviour reachable by the change is the terminal segment of an arc whose two darts lie in different face-walk
orbits. Everything else takes the identical path it took before. Accepted **365/365** confirms it at runtime.

Ordinal **408** — `SurfaceCutGraph.SeparatingArcBarrierRuleExcludesCrossedFacesFromUncutCensus` — asserts three
things and PASSes all of them (`tests/FieldAlignedCurveNetworkTests.cpp:14751–14764`):

1. **every remaining interior-arc row has `forwardOrbit == reverseOrbit`** — no separating arc is interior to any
   uncut component any more;
2. **every face crossed by a separating arc is absent from the uncut census**;
3. **every equal-orbit terminal-slit face is still present** — the rule does not over-cut.

Property 3 is the one worth dwelling on: it is the falsification of over-cutting, asserted positively rather than
assumed, and it is why "supersede `terminalSlit` **only for separating arcs**" was written into the frozen rule.

---

## 2. CO1 — the question open since TB20 is decided: a separating arc crosses the failing component

CB34 discharged CN7 by transcribing the TB28-R3 census from immutable log artifact `9978114502` into its report
§4.2. The decisive rows:

| Arc | Dart orbits | Terminal crossed face | certifier | **plan** | reason |
|---:|---|---|---:|---:|---|
| **14** | `0 / 1` **separating** | `28,29,35` | 0 | **0** | `TerminalSlit` |
| 20 | `0 / 0` | `36,38,39` | 0 | 0 | `TerminalSlit` |
| **22** | `0 / 3` **separating** | `10,79,151` | 0 | **0** | `TerminalSlit` |
| 24 | `0 / 0` | `66,67,120` | 0 | 0 | `TerminalSlit` |

**Both separating arcs cross faces whose plan component is 0 — the 191-face failing component.** The census also
records `failing component is a subset of census component: true`, confirming the containment argued statically at
TB27-REV.

Under the CL6 dichotomy this selects the first branch, unambiguously:

> **The 191-face component genuinely spans certified faces 0, 1 and 3. Its three seeds `[0,1,3]` are the true
> geometry, not attribution errors. The seed guard was right to fail. The defect was the barrier set.**

`M3-CP4c3-TB25-REV-CAND-02` — *is the failing component contained in a single certified face?* — is **DECIDED: NO**,
and **CLOSED**. `M3-CP4c3-TB27-REV-CAND-01` is **CORRECTED / RUNTIME-PROVED** by ordinal 408.

### 2.1 The thread from TB20 closes

TB22 localized the two minority boundary edges of the 81/1/1 attribution as **`10-79`** and **`29-35`**. Arc 22's
terminal crossed face is **`(10,79,151)`** and arc 14's is **`(28,29,35)`**. **The two minority edges are edges of
exactly the two terminal-slit faces of the two separating arcs**, and the minority orbits — 1 from arc 14, 3 from
arc 22 — are those arcs' reverse orbits.

At TB27-REV I recorded this correspondence as *"striking and not evidence"*, because it compared quantities measured
on different partitions. It is evidence now, measured on the failing partition, and it is exact. The 81/1/1
distribution was never an attribution defect: 81 boundary edges face certified face 0, and two face the two other
certified faces the component genuinely reaches.

---

## 3. CO2 — the two new REDs are test-authority, and both are provable from source

### 3.1 Ordinal 404 — an out-of-contract value assertion, latent until the product improved

`SurfaceCutGraph.UncutComponentArcIncidenceCensusPublishesOnOwnershipFailure` ends with
(`tests/FieldAlignedCurveNetworkTests.cpp:14347–14352`):

```cpp
for (const auto &face : component->faces) {
  const auto *owner = certificate.find_source_face_owner(face);
  ASSERT_NE(nullptr, owner);
  EXPECT_NE(SurfaceCutGraphSourceFaceOwnershipStatus::Established, owner->status);
}
```

**It requires that no face of certifier component 0 has established ownership** — a required-green assertion that
the defect under repair is still present.

Its own frozen contract forbids this. CK9 and CL9 both specify that ordinal 404 *"asserts **publication and
completeness only, never a value**, and must not require any owner to be established"*. Requiring owners to be
**un**established is the same kind of value assertion, pointed the other way.

The clause was introduced by **CB31**, not CB34 — it is present at `eaa0ea54:14338`, before the correction existed.
It passed for four turns because ownership genuinely was failing, which made it **vacuously true**, and a vacuously
true assertion is indistinguishable from a correct one until the product changes. `LESSONS.md` 133.

**Its firing is positive evidence.** `EXPECT_NE(Established, …)` can only fail if **at least one face of that
component is now `Established`** — ownership that did not exist before the correction. The regression is the
correction working, observed through a gate that was written to forbid it.

*(I mark this as the probable failing assertion rather than the certain one: 404 carries several `EXPECT`s, though
the others are structural equalities and a digest check that hold by construction. CO5 requires the failing
assertion text to be transcribed so the next review does not have to infer it.)*

### 3.2 Ordinal 390 — it matches two partitions by index

`GlobalTopologyPlan.UncutFaceComponentBoundaryOrbitAttributionPublishesThroughMechanicalProductionFailure` locates
the certifier census by (`:11564–11567`):

```cpp
[&](const auto &row) { return row.component == *locus.uncutFaceComponent; }
```

then asserts (`:11575`):

```cpp
EXPECT_EQ(*locus.uncutFaceComponentCertifiedFaceDistinctCount, attribution->seedOrbits.size());
```

`locus.uncutFaceComponent` is an index in the **plan's `EmptyFragmentOrbits`** partition; `row.component` is an
index in the **certifier's `NotTraceCut`** partition. **The witness matches them by integer.**

That is precisely the conflation ordinal 406 proved invalid — `matchesFailingComponent=false`, 214 faces against
191, different digests — and which CB34's own report warns about in as many words: *"The two component ids are both
numerically zero but belong to different partition domains and different face sets. They must not be conflated."*

It passed while both indices were 0 and both counts were 3. The correction changes the two partitions differently,
the coincidence breaks, and the witness fails — **on its own defect, not the product's**. `LESSONS.md` 134.

### 3.3 Neither is a weakening question

Removing an assertion a frozen contract explicitly excluded is not weakening the identity; it is restoring the
identity to the contract it was given. Both fixes are **replace-in-place**, ordinals retained and gating, names and
selector bytes unchanged. **Ordinal 398 is untouched and stays the sole gate on ownership totality.**

---

## 4. CO3 — what is still RED, and what is not authorized

| Ordinal | Classification |
|---|---|
| 366, 367 | **The open frontier.** Still failing closed. The correction split the partition but ownership is not yet total; nothing here is authorized to be corrected in the successor. |
| 398 | **The honest gate.** `proves_cellularity()` remains false. Untouched, and it must stay that way until ownership is genuinely total. |
| 390, 404 | **Test authority**, §3. Corrected in place by CO5. |
| 368, 369, 370, 374 | **Unchanged carried surfaces** with separate owners. Untouched. |

**No second product correction is authorized.** CB34 made one change; whether that change is sufficient to make
ownership total is a question for the next runtime, and the evidence that will answer it — the post-correction
census — is already being published and merely needs transcribing. **CL8 stands: no new diagnostic contract on
source-face ownership.** CO5 transcribes what exists; it measures nothing new.

---

## 5. CO4 — stable accounting

**No stable event, category, or recurrence is added.** Totals remain **44 events / 14 categories / 30
recurrences**, produced-witness debt **5**, semantic M3 package count **94** (CB34).

1. accepted **1–365 = 365/365** with no accepted RED ordinal and **no accepted-green loss** — the load-bearing
   boundary survived the first product correction on this frontier since CB27;
2. **390 and 404 are evidence-contract failures, not behaviour losses.** Each fails on an assertion that encodes
   the pre-correction state; no product property they legitimately own was lost. Precedent: the 384/385/389/390
   disposition at TB24-REV;
3. 366/367/368/369/370/374/398 are already-counted carried surfaces and open-frontier gates;
4. ordinal 408 is a new witness whose first execution PASSes.

---

## 6. CO5 — candidates

**Closing.**

- `M3-CP4c3-TB25-REV-CAND-02` — **CLOSED / DECIDED**, §2. A separating arc crosses the failing component; it is not
  contained in a single certified face.
- `M3-CP4c3-TB27-REV-CAND-01` — **CORRECTED / RUNTIME-PROVED**, §1. Ordinal 408 proves separating-arc faces are
  excluded and equal-orbit slits are preserved.
- `M3-CP4c3-TB28-REV-CAND-02` — **CLOSED.** CN7 was discharged: CB34 transcribed the 191-face census from the
  immutable log into a retained document.

**New.**

- `M3-CP4c3-TB29-REV-CAND-01` — **NEW / ACTIVE / GATING / TEST AUTHORITY.** Ordinal 404 asserts that no face of the
  component has established ownership, contrary to its own frozen publication-and-completeness contract; it passed
  vacuously for four turns and fires now that ownership exists. Owner: **CO6**.
- `M3-CP4c3-TB29-REV-CAND-02` — **NEW / ACTIVE / GATING / TEST AUTHORITY.** Ordinal 390 matches the plan and
  certifier partitions **by component index**, the conflation ordinal 406 proved invalid. Owner: **CO6**.

**Carried, unchanged.** `M3-CP4c3-TB26-REV-CAND-04` and `M3-CP4c3-DEFN-R3-CAND-01` (two partitions — **still
gating**, and now the more prominent architectural debt, since §3.2 shows a witness silently depending on their
indices coinciding), `M3-CP4c3-TB27-REV-CAND-02`, `M3-CP4c3-TB24-REV-CAND-02`, `M3-CP4c3-TB22-REV-CAND-01`,
`M3-CP4c3-TB18-REV-CAND-01`, `M3-CP4c3-TB7-CAND-02`, `M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`,
`M3-CP4c2-TB-X2-CAND-04`, `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, finalize/contact
fall-through.

---

## 7. CO6–CO8 — frozen successor: `M3-CP4c-3-CB35`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`. **Test authority and transcription only.
No product change.**

### CO6 — restore two witnesses to their own contracts

Both are **replace-in-place**; ordinals, names and selector bytes unchanged, both retained and gating.

1. **Ordinal 404** — delete the ownership-status loop at `tests/FieldAlignedCurveNetworkTests.cpp:14347–14352`.
   Every other assertion stays. The identity asserts publication, completeness, non-truncation, the face-set digest
   and per-row field presence — **and no ownership value, in either direction**, exactly as CK9/CL9 specified.
2. **Ordinal 390** — stop matching partitions by index. Locate the comparison census by the **face-set digest**
   published under CK9, or by the published subset relation; if no census corresponds to the failing component,
   the identity must say so and assert only plan-side quantities. It must never assume the two `component` integers
   denote the same object.

**Prohibited in both:** relaxing any assertion that the identity legitimately owns, changing ordinal 398, or
touching 366/367.

### CO7 — transcribe the post-correction census

CB35's closeout must transcribe from the TB29 immutable log artifact `9980019636`, for the mechanical fixture:

- the **failing plan component** after the correction — id, domain, face count, face-set digest, seed count/state
  and seed orbits;
- every **uncut component census** row's interior-arc incidences with both dart orbits — expected empty of
  separating arcs, per ordinal 408;
- the **ownership status counts** — `established` / `unavailable` / `conflicting` over the 300 source faces;
- **the failing assertion text for every RED ordinal**, including 390 and 404.

This is transcription of evidence the runtime already publishes. **It is not a new diagnostic and CL8 is
untouched.** The `established` count is the number that will say whether one more product correction is needed or
whether the frontier is closing; recording it costs nothing and guessing it costs a turn.

### CO8 — the next runtime

`M3-CP4c-3-TB30` re-executes selector 408 on the CB35 package. **Credibility gate: ordinals 366, 367 and 398 must
be RED**, since CB35 changes no product behaviour. **Required outcome: 390 and 404 return to PASS** with no
assertion they legitimately own relaxed; if they do not, `M3-CP4c3-TB29-REV-CAND-01`/`-02` are falsified and the
cause is elsewhere.

### Prohibited in CB35

1. Any product behaviour change. **One product correction has landed; the next is not authorized until TB30's
   census is read.**
2. Changing any accepted identity 1–365, or any byte of selector 397/401/403/405/406/407/408.
3. Weakening `proves_cellularity()` or ordinals 397–408, or relaxing any assertion 390 and 404 legitimately own.
4. Any new diagnostic contract on source-face ownership. CL8 stands.
5. Executing any Directional runtime.

---

## 8. A note on the shape of this turn

This is the first turn in this checkpoint where a product correction was applied and measured, and the result is
worth stating plainly: **seven lines of product change, the accepted prefix intact at 365/365, the new witness
green on all three of its properties, and the question open since TB20 decided.** The two regressions it produced
are both witnesses asserting that the defect was still there.

That is what a correct fix looks like when the surrounding gates encode the broken state. The lesson is not that
the gates were badly written — 404's clause was a reasonable-looking strengthening — but that **a gate asserting
the presence of a defect cannot distinguish "still broken" from "correctly asserted", and only the fix reveals
which it was.**

## 9. Consolidation performed

Per `CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW turn". Durable facts were verified present in this
record, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md`
before any fold. **CB34's §4 CN7 transcription is preserved in §2 of this record before its source document is
folded.**

Folded: `Architecture_M3_CP4c3_TB28_R3_EXEC_Report.md` (superseded runtime authority — the control run that
restored the accepted-prefix statement), `Architecture_M3_CP4c3_TB28_R3_Artifact_Only_Test_Benchmark_Plan.md`
(consumed contract), `Architecture_M3_CP4c3_TB28_R3_Independent_Review_Record.md` (superseded review authority,
CN0–CN8 — its restated frozen correction is now implemented and runtime-proved),
`Architecture_M3_CP4c3_CB32_Code_Build_Report.md` and `Architecture_M3_CP4c3_CB33_Code_Build_Report.md` (consumed
build reports, superseded as package authority by CB34).

Retained as current authority: `Architecture_M3_CP4c3_TB29_EXEC_Report.md` (**the valid semantic runtime
authority**), `Architecture_M3_CP4c3_TB29_Artifact_Only_Test_Benchmark_Plan.md` (the contract it executed),
`Architecture_M3_CP4c3_CB34_Code_Build_Report.md` (**the package under test, and the retained CN7 transcription**),
this record, `M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`,
`Required_Green_Selector_Manifest.md`, `M3_CP4c_Consolidated_Record.md`, and every
`Required_Green_Selector_*.txt`. **Never folded:** `tools/m3_cp4c3_tb28_r3_harness.sh` and its TB29 successor are
the instrument, not documents.

## 10. Lessons added

`LESSONS.md` **133** — a witness that asserts a defect is still present cannot be distinguished from a correct one
until the defect is fixed, and then it blocks the fix.
`LESSONS.md` **134** — never match two partitions by index.

## 11. Exact successor

**`M3-CP4c-3-CB35`** under **CO6–CO8**, Code + Build, runtime-free. Two witnesses restored to their own contracts,
one transcription of evidence that already exists, and **no product change**.
