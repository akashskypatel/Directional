# M3-CP4c-3-TB31 Independent Review Record

## Status

**COMPLETE / STATIC / NO RUNTIME / NO COMPILE / NON-STABLE / THE SEED FRONTIER IS CLOSED.**

`M3-CP4c-3-TB31-REV` is evidence-only review. It executed no Directional runtime, no compile, no package operation,
and mutated no product, test, fixture, benchmark, build or selector byte.

**TB31 is promoted to current valid semantic runtime authority**: selector **408**, **397 PASS / 11 RED**, accepted
**1–365 = 365/365**, RED `[366, 367, 368, 369, 370, 374, 390, 393, 398, 406, 407]`. All 408 rows selected exactly
one test, `timeout_count=0`, and all three byte+mode censuses are equal pre/post.

**The seed-uniqueness frontier that has blocked this checkpoint since TB19 is CLOSED.** Component 0 went from
**191 faces / seedCount 3 / `Multiple` / `[0,1,3]`** to **189 faces / seedCount 1 / `Unique` / `[0]`**.

The pipeline now stops at a **new and different frontier**: `TraceArcDoesNotSeparateItsSides`, arc **15**,
`sourceFace=8,10,151`. That guard protects a representation — **fragments are identified by `(face, orbit)`** —
which a settled fact of this checkpoint says is not injective. That is a **definition** question, and §7 freezes a
`DEFN` turn rather than guessing at a refactor.

`review_check.py authority 90bf8430f54c8b81fb90a6bda820cf8edebce6e9` — **ALL CHECKS PASSED**.

---

## 1. CR0 — `M3-CP4c3-TB30-REV-CAND-01` is confirmed and closed

The falsification I stated before the build was: *if 366/367 still fail with component 0, 191 faces and seeds
`[0,1,3]`, the candidate is falsified.* **It did not reproduce.** The published fragment-owner component 0 is now:

| | faces | seedCount | seedState | seedOrbits |
|---|---:|---:|---|---|
| TB30 | 191 | 3 | `Multiple` | `[0,1,3]` |
| **TB31** | **189** | **1** | **`Unique`** | **`[0]`** |

Two faces left the component — the terminal-slit faces of the two separating arcs — and the three-way seed
ambiguity collapsed to the single orbit the 81/1/1 majority always pointed at. **`M3-CP4c3-TB30-REV-CAND-01` is
CLOSED / runtime-proved.**

**The second falsifier also held.** I wrote that if `TraceCutFaceFragmentCountMismatch` appeared, the
`tracePieceCount` premise was wrong and the change would narrow to the `traceTouchedEdges` insertion alone. EXEC
reports **no `TraceCutFaceFragmentCountMismatch` in any of the 408 per-ordinal raw logs**. The by-construction
argument — that a separating terminal slit contributes a real chord, so `expected = k + 1 = 2` matches its two
published fragment orbits — is confirmed.

**CB36 implemented CQ7 exactly**: the diff over `src include tests` is the guard at `GlobalTopologyPlan.cpp:830`
plus a comment correction, and nothing else.

### 1.1 What this closes

Certified source-face ownership is total (**300 / 0 / 0**, unchanged from TB30) **and** the consumer's own
partition now yields a unique owner for its largest component. The chain that began at TB19 — *can certified
source-face ownership be established, and can the plan consume it?* — is answered on both halves.

---

## 2. CR1 — the new frontier, and what its guard actually protects

366 and 367 now terminate at typed detail **`TraceArcDoesNotSeparateItsSides`**, `arc=15`,
`sourceFace=8,10,151`. The guard is at `GlobalTopologyPlan.cpp:474–479`, inside
`build_fragment_corner_incidence`:

```cpp
if (forwardOrbit == reverseOrbit) {
  … TraceArcDoesNotSeparateItsSides …
}
```

**It is pre-existing.** CB36 did not add it and did not touch its site — that site carries its own unconditional
`is_terminal_slit` skip at `:467`, which is untouched. Whatever made the guard reachable is upstream of it, not at
it.

**And the guard is not gratuitous.** Twenty lines later the function does:

```cpp
const std::size_t sideOrbit   = turn == 1U ? forwardOrbit : reverseOrbit;
const std::size_t cornerOrbit = sideOrbit == forwardOrbit ? reverseOrbit : forwardOrbit;
result[segment.sourceFace][cornerOrbit].insert(face.vertices[*sharedCorner]);
```

`FragmentCornerIncidence` is `map<SourceFace, map<orbit, set<SourceVertexId>>>` (`:399–401`), and its consumer
keys fragments the same way — `FragmentKey = pair<SourceFaceTopologyKey, std::size_t /*orbit*/>` with an
`owningOrbit` parameter (`:1675`, `:1693–1699`).

**So a fragment is identified, throughout region disc certification, by `(face, orbit)`.** When an arc's two darts
share an orbit that key is **not injective**: the two sides of the chord collapse onto one entry and their corner
sets merge. The guard refuses rather than silently merging, which is the right instinct.

### 2.1 The guard's premise contradicts a settled fact

`M3_CP4c_Current_And_Forward.md` §5 has carried this since TB18: *"the face walk is a validated total permutation;
**shared orbit ownership by the two sides of one arc is legitimate topology**. BS9-5 remains retired."*
DEFN-R3.4 measured exactly that — **arc 15**, `forwardOrbit = reverseOrbit = 0`, on a certified cellular complex.
And the correction this checkpoint just proved rests on the same fact: arcs 20 and 24 (`0 / 0`) are deliberately
left alone precisely because equal orbits mean *does not separate*, and that is legitimate.

So `TraceArcDoesNotSeparateItsSides` asserts the negation of a fact this checkpoint has established twice.

**But the defect is the representation, not the guard.** Deleting the guard would merge two distinct fragments
under one key — strictly worse than refusing. The fix is to stop identifying fragments by an orbit that does not
distinguish them.

This is the same shape as `LESSONS.md` 134 (*never match two partitions by index*) one level down: **a key chosen
because it happened to be injective on every witness seen so far.**

### 2.2 What I do not know, and will not guess

The guard sits upstream of the seed guard in the failure order the runtime now reports, yet the mechanical fixture
previously terminated at the seed guard. **I cannot establish from static source why it became reachable** — the
build order, the region set and the walk it observes all interact, and `build_fragment_corner_incidence`'s result
is consumed inside region disc certification (`:2014–2020`, with `regions` already in scope at `:2013`).

The retained per-ordinal logs in artifact `9982618174` contain the answer. **CR8 requires it to be recorded from
that evidence rather than inferred**, and no measure below depends on it.

---

## 3. CR2 — the four newly-RED ordinals are pinned witnesses, for the third time

**390, 393, 406 and 407** all fail for one reason, stated plainly by EXEC: they *"fail assertions that expected
`UncutFaceComponentOrbitSeedNotUnique` but received `TraceArcDoesNotSeparateItsSides`."*

They are **witnesses that hard-code which failure the product is currently making**. When the product stops making
that failure — which is the goal — they red. None of them observed a behaviour loss; the behaviour they observed
improved.

**Ordinals 404 and 408 stayed PASS.** Those are the two identities written to assert *publication and
completeness* rather than a particular outcome. **The identities written to assert contracts survived the frontier
moving; the ones pinned to a specific failure did not.** That is now measurable rather than arguable, and it is the
single most useful thing this turn says about test authority.

Counting the pattern honestly: 404 and 390 at TB29, and 390, 393, 406, 407 here — **six identities across two
forward steps**, each red because the product got better. `LESSONS.md` 137.

None of these is a weakening question. Re-pointing a witness away from a superseded terminal failure code, while
keeping every contract it legitimately owns, restores it rather than relaxing it — the same disposition as CB35's
repair of 390 and 404, which TB30 proved correct.

---

## 4. CR3 — classification of the 11 RED ordinals

| Ordinal | Classification |
|---|---|
| 366, 367 | **The new frontier.** `TraceArcDoesNotSeparateItsSides`, arc 15. The seed frontier they carried since TB19 is closed; this is a different and later stop. Owner: **DEFN-R4**. |
| 390, 393, 406, 407 | **Pinned witnesses**, §3. Test authority; each expected a superseded terminal failure code. Owner: **DEFN-R4** measures. |
| 398 | **Carried sphere surface** — `prescribed sphere: NotProductionReady/CellularityNotEstablished`, ordinal 368's surface. **Not an ownership gate.** Owner: `M3-CP4c2-TB-X2-CAND-04`. Untouched. |
| 368, 369, 370, 374 | **Unchanged carried surfaces** with separate owners. Untouched. |

Accepted **1–365 = 365/365**, no accepted RED ordinal. Ordinals **404 and 408 remain PASS**, and the certified-owner
census remains **300 established / 0 unavailable / 0 conflicting**.

---

## 5. CR4 — stable accounting

**No stable event, category, or recurrence is added.** Totals remain **44 events / 14 categories / 30
recurrences**, produced-witness debt **5**, semantic M3 package count **96** (CB36).

1. accepted **365/365** with no accepted RED ordinal and **no accepted-green loss** — the second product correction
   on this frontier, and the load-bearing boundary held again;
2. **390, 393, 406 and 407 are evidence-contract failures, not behaviour losses.** Each expected a failure the
   product no longer makes. Precedent: the identical disposition at TB24-REV and TB29-REV, both later confirmed at
   runtime;
3. 366/367 did not regress — they **advanced**, from a seed-ambiguity stop to a later representation stop;
4. 368/369/370/374/398 are already-counted carried surfaces;
5. the first TB31 trigger failed on a caller permission ceiling before semantic runtime and carries no ledger.

---

## 6. CR5 — candidates

**Closing, runtime-proved.**

- `M3-CP4c3-TB30-REV-CAND-01` — the frozen rule unapplied at its second site. **CLOSED.** Applying it collapsed
  component 0 to a unique seed and neither stated falsifier reproduced.

**Carried, and now re-scoped.**

- `M3-CP4c3-TB26-REV-CAND-04` / `M3-CP4c3-DEFN-R3-CAND-01` — two partitions from two independent constructions.
  **ACTIVE**, and no longer the blocking cause: the plan's partition now yields a unique owner. Whether to unify
  remains open and belongs to a `DEFN`.
- `M3-CP4c3-TB30-REV-CAND-02` — the plan-side interior-arc census is a projection of the certifier's rows.
  **ACTIVE / NON-GATING.**
- `M3-CP4c3-TB27-REV-CAND-02`, `M3-CP4c3-TB22-REV-CAND-01`, `M3-CP4c3-TB18-REV-CAND-01`, `M3-CP4c3-TB7-CAND-02`,
  `M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`, `M3-CP4c2-TB-X2-CAND-04` (also the owner of 398),
  `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, finalize/contact fall-through — unchanged.

**New.**

- `M3-CP4c3-TB31-REV-CAND-01` — **NEW / ACTIVE / GATING / ARCHITECTURAL.** Fragment identity is `(face, orbit)`
  across `build_fragment_corner_incidence` and region disc certification, and that key is **not injective when an
  arc's two darts share an orbit** — which this checkpoint has twice established is legitimate topology.
  `TraceArcDoesNotSeparateItsSides` is the guard protecting the non-injective key. Owner: **DEFN-R4**.
- `M3-CP4c3-TB31-REV-CAND-02` — **NEW / ACTIVE / GATING / TEST AUTHORITY.** Ordinals 390, 393, 406 and 407 pin a
  specific terminal failure code and red on any forward step. Owner: **DEFN-R4** measures.
- `M3-CP4c3-TB31-REV-CAND-03` — **NEW / ACTIVE / EVIDENCE SURFACE / NON-GATING.** The plan-side face-set digest and
  `censusCorrespondence` fields are emitted only on the seed-guard failure path, so they vanished when the
  terminal failure changed. Frontier evidence should not be attached to one failure code. Owner: **DEFN-R4**.

---

## 7. CR6–CR8 — frozen successor: `M3-CP4c-3-DEFN-R4`

**A definition turn, not a Code + Build turn**, and this is a deliberate choice rather than caution.

`(face, orbit)` is not an implementation detail of one function: it is the **identity of a fragment** across
`FragmentCornerIncidence` and region disc certification, including the `owningOrbit` parameter and the
`FragmentKey` pairs the certifier builds. Changing it decides what a fragment *is*. Part VII's chain is where this
project freezes such decisions, and `DEFN` absorbs REVIEW + PLAN, so the turn can also freeze the test measures and
the successor CB.

**CL8 does not bind here.** It forbade further diagnostic turns on **source-face ownership**, and ownership is
closed — 300/300 certified, unique seed on the consumer side. This is a different frontier, and a definition
decision is not a diagnostic.

### CR6 — what DEFN-R4 must decide

1. **What identifies a fragment**, given that two sides of one arc may legitimately share a face-walk orbit. The
   answer must be injective on a bridge. Carrying the orbit as *data* alongside an injective key is one candidate;
   the decision is DEFN-R4's.
2. **The disposition of `TraceArcDoesNotSeparateItsSides`.** It must not simply be deleted — deleting it merges two
   distinct fragments under one key, which is worse than refusing. It is retired **only as a consequence** of an
   injective identity, and DEFN-R4 must say so explicitly.
3. **The in-place repair of ordinals 390, 393, 406 and 407** — each keeps every contract it legitimately owns and
   stops asserting which terminal failure code the product produces. Ordinals retained and gating; selector 408
   unchanged.
4. **Where frontier evidence is attached** (`M3-CP4c3-TB31-REV-CAND-03`): the plan-side digest and
   `censusCorrespondence` must not be emitted only on one failure path.

### CR7 — what DEFN-R4 must not do

1. **Re-open source-face ownership.** It is closed: 300/300 certified, component 0 unique at `[0]`. The
   separating-arc barrier rule stands at both sites and is not to be revisited.
2. **Weaken or re-scope ordinal 398.** It fails on the prescribed sphere and belongs to
   `M3-CP4c2-TB-X2-CAND-04`.
3. **Touch ordinals 368, 369, 370 or 374.**
4. **Unify the two partitions.** Still open, still a separate decision, and not required by this frontier.
5. Change any accepted identity 1–365 or any byte of selector 397–408.

### CR8 — one evidence obligation, no new measurement

DEFN-R4 must record, **from the retained TB31 logs in artifact `9982618174`**, why
`TraceArcDoesNotSeparateItsSides` became reachable — which stage's output changed between the CB35 and CB36
packages. This is transcription of existing evidence, not a new diagnostic, and §2.2 states plainly that I could
not establish it from static source. It matters because it distinguishes *"the guard was always going to be hit
once the seed stop cleared"* from *"CB36 changed the walk this function observes"*, and those imply different risk
for the fragment-identity change.

---

## 8. A note on what this turn is

Two product corrections, seven lines and one line, have closed a frontier that eleven turns of diagnostics could
not. Both were frozen with their falsification conditions written before the build, and **both falsifiers were
checked and neither reproduced** — the seed fingerprint did not return, and `TraceCutFaceFragmentCountMismatch`
appears nowhere in 408 raw logs.

The cost was six witnesses reddening because they were pinned to the failure the product used to make. That is
worth naming as the recurring tax of forward progress here, and it is why the two identities that assert
*publication and completeness* — 404 and 408 — are the ones still standing.

## 9. Consolidation performed

Per `CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW turn". Durable facts were verified present in this
record, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md`
before any fold. **The certified-owner census `300 / 0 / 0` and the new component-0 fingerprint
`189 / 1 / Unique / [0]` are preserved in §§1–2 above** before their source documents are folded.

Folded: `Architecture_M3_CP4c3_TB30_EXEC_Report.md` (superseded runtime authority),
`Architecture_M3_CP4c3_TB30_Artifact_Only_Test_Benchmark_Plan.md` (consumed contract),
`Architecture_M3_CP4c3_TB30_Independent_Review_Record.md` (superseded review authority, CQ0–CQ8 — its
`M3-CP4c3-TB30-REV-CAND-01` is runtime-proved and both its falsifiers held),
`Architecture_M3_CP4c3_CB36_Code_Build_Report.md` (consumed build report — **the second application of the frozen
rule, runtime-proved**).

Retained as current authority: `Architecture_M3_CP4c3_TB31_EXEC_Report.md` (**the valid semantic runtime
authority**), `Architecture_M3_CP4c3_TB31_Artifact_Only_Test_Benchmark_Plan.md`, this record,
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`,
`M3_CP4c_Consolidated_Record.md`, and every `Required_Green_Selector_*.txt`. **Never folded:** the artifact-only
harness scripts are the instrument, not documents.

## 10. Lessons added

`LESSONS.md` **137** — a witness that hard-codes which failure the product currently makes reds on every forward
step.
`LESSONS.md` **138** — a key that has been injective on every witness so far is not an identity.

## 11. Exact successor

**`M3-CP4c-3-DEFN-R4`** under **CR6–CR8**. A definition turn: decide what identifies a fragment, dispose of
`TraceArcDoesNotSeparateItsSides` as a consequence of that decision, freeze the in-place repair of four pinned
witnesses, and record from retained evidence why the guard became reachable.
