# M3-CP4c-3-TB26 Independent Review Record

## Status

**COMPLETE / STATIC / NO RUNTIME / NO COMPILE / NON-STABLE / SUCCESSOR FROZEN.**

`M3-CP4c-3-TB26-INDEPENDENT-REVIEW` is REVIEW + PLAN only, outside the orchestration loop. It executed no
Directional runtime, no compile, no package operation, and mutated no product, test, fixture, benchmark, build or
selector byte. Accepted authority remains **365/365**; runtime authority remains `M3-CP4c-3-TB26-R1`
(**397 PASS / 8 RED** on selector 405). CP4c-3 remains **OPEN**. Measures **CK0–CK9** freeze the exact successor
**`M3-CP4c-3-CB31`**.

`review_check.py authority e045bf7147afc02bd90eff4822e4b609edbaba66` — **ALL CHECKS PASSED**. Static review of the
working tree is valid evidence about immutable package `9957324848`.

---

## 1. CK0 — the intake's first premise is declined

The intake asks me to *"accept that `interiorArcs=4` selects the separating-arc horn"*. **I decline, and the rest of
this review turns on why.**

CJ6 did not define the horn as *an arc is incident to the component*. It defined the interior arc-incidence census
as **"every arc whose dart lies on a face of the component, with the arc kind and the orbit at each of its two
darts"**, and the horn as *a **separating** arc meets the interior*. An arc separates two certified faces **iff its
two darts lie in different face-walk orbits**. That is the entire content of the word "separating", and it is
exactly the field the runtime did not publish.

`interiorArcs=4` is a count of incidences. **Four arcs with `forwardOrbit == reverseOrbit` separate nothing.**
The report's §1 and §3 are mutually inconsistent on this point: §1 declares the horn selected, §3 states that TB26
"cannot independently name which four arcs constitute the decisive incidence set from runtime evidence alone." A
horn that cannot be named cannot be known to be selected.

This is `LESSONS.md` 108 — carry the premise, not just the conclusion — and it is the third time in this
checkpoint that an aggregate has been read as though it were the discriminating field.

### 1.1 The datum exists in memory; only the print is missing

`SurfaceCutGraphUncutComponentArcIncidenceCensus`
(`include/directional/geometry/SurfaceCutGraph.h:138–146`) carries `arc`, `kind`, **`forwardOrbit`** and
**`reverseOrbit`**, and `SurfaceCutGraph.cpp:689–708` populates all four from
`embedded.faceWalk.orbitByDart[forwardDart]` and `[reverseDart]`. The same is true of
`SurfaceCutGraphUncutComponentSeedAttribution` (`:161–170`), which carries the edge, both faces, the orbit and the
**rule** (`SingleFaceOwner` / `EdgeSideOwner`) for each of the 46 attributions.

**Nothing needs to be computed. CB30 computed and stored the deciding fields and serialized only counts.** That is
a categorically cheaper defect than the four that preceded it, and it is why CK6 below is a small measure rather
than another investigation.

### 1.2 A static argument that the horn is probably NOT selected

This is an argument, not a measurement, and CK6 exists to test it.

- `arc.sourceFaces` is exactly the source faces of the arc's segments `[firstSegment, onePastLastSegment)`
  (`EmbeddedGraphTopology.cpp:549–554`).
- `traceCutFaces` receives `segment.sourceFace` for **every** segment in that same range **except** a terminal slit
  — `!trace->terminalBarrier.has_value() && segmentIndex + 1 == trace->segments.size()`
  (`SurfaceCutGraph.cpp:523–530`).
- A component's faces are, by construction, the faces **not** in `traceCutFaces`.

**Therefore a trace arc can meet an uncut component's interior only through a terminal-slit segment.** An arc whose
range covers the terminal slit ends at the trace's free end; a free end is a degree-1 node; an arc incident to a
degree-1 node is a **bridge**; and both darts of a bridge lie in the **same** face orbit. This project has already
measured exactly that case — DEFN-R3.4 records TB18's arc 15 with `forwardOrbit = reverseOrbit = 0`.

**Prediction, falsifiable by printing one pair of integers per row: all four interior-arc rows have
`forwardOrbit == reverseOrbit`.** If so the separating-arc horn is **refuted**, the component lies in exactly one
certified face, and the three seeds `[0,1,3]` contain two attribution errors — which the 46 unserialized
`seedAttributions` rows already name. If any row differs, the horn is selected and I am wrong; the arc is then
named and the partition, not the attribution rule, is what must change.

Note the corollary either way: the terminal-slit exclusion is what puts an arc inside an "uncut" component at all.
Whether that is benign (bridge) or a genuine defect (separator) is precisely what the orbit pair decides.

---

## 2. CK1 — the load-bearing finding: the census describes a different object than the failure

This is independent of §1 and, in my judgement, the more important of the two.

**There are two partitions in this system, built from different domains and different barrier sets.**

| | domain | barriers | site |
|---|---|---|---|
| **plan** | `unlabeledFaces` — faces whose `fragmentOrbits` entry is empty | `mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges` | `GlobalTopologyPlan.cpp:1103–1115` |
| **certifier** | `uncutFaces` — faces **not** in `traceCutFaces` | `cutEdges ∪ mandatory/cut arc source edges ∪ non-slit trace carriers` | `SurfaceCutGraph.cpp:596–601` |

The domains are **not** the same set. `fragmentOrbits` is populated for mandatory/cut arc interiors at
`GlobalTopologyPlan.cpp:702` and `:750`, so **a face incident to a mandatory or cut edge is excluded from the
plan's domain while remaining in the certifier's.** The two partitions therefore have different members, different
components, and different boundaries — by construction, not by accident.

**The RED is raised on the plan's partition. The CJ6 censuses are computed on the certifier's partition.**
`boundaryEdges=76`, `interiorArcs=4`, `vertexTransits=53` and `seedAttributions=46` are properties of the
certifier's component 0. `uncutFaceComponentFaceCount=191` and the seeds `[0,1,3]` are properties of the plan's
component 0. **TB26 published no evidence that these are the same set of faces**, and the census's own face count
is not serialized either.

Until that correspondence is established, **none of the CJ6 evidence is admissible about the failing component.**
That includes `interiorArcs=4`, which §1 already declines on separate grounds.

This is `M3-CP4c3-DEFN-R3-CAND-01` — "one embedded topology, two independent constructions" — resurfacing one level
down, and it is the same shape as the fact `ORIENTATION.md` §5 has recorded since TB21: *the certificate and the
seed guard test different objects; neither validates the other.* The diagnostic built to adjudicate the guard was
built on the certificate's side of that divide.

### 2.1 CK2 — this resolves the 76-versus-97 discrepancy

The intake asks whether the domains differ lawfully or CJ6 omitted 21 rows. **They differ lawfully.**

The 97-edge baseline is the *plan's* component-0 boundary, measured through
`UncutFaceComponentOrbitSeedNotUnique`'s attribution evidence (83 attributed — orbit 0 → 81, orbit 1 → 1, orbit 3 →
1 — plus 14 barrier/no-seed). The 76 is the *certifier's* component-0 boundary
(`SurfaceCutGraph.cpp:637–686`: every edge with at least one side in the component and not both sides in it, one
row per component-side face). Different domain, different barrier set, different boundary.

**No row was omitted, and 76 must not be treated as equivalent to 97.** Neither may the difference be waved
through: the two counts are evidence that the partitions differ, which is exactly §2's finding. What TB26 cannot
say — because it is unpublished — is whether the certifier's component 0 even has 191 faces.

---

## 3. CK3 — what TB26 does establish

Independent of §1 and §2, the turn made real progress and it should be stated plainly.

- **CJ8 worked. 389 and 390 recover RED → PASS.** 389's Euler census is green with the coupling removed; 390
  publishes `certifiedOwnerCount=3` **without asserting a winner**, exactly as the replaced-in-place contract
  required. `M3-CP4c3-TB25-REV-CAND-03` **CLOSES / RUNTIME PROVED**.
- **CJ7 worked, and fail-closed behaviour is correct.** Component 0 has `seedCount=3`, `seedState=Multiple`,
  orbits `[0,1,3]`; the plan fails at `UncutFaceComponentOrbitSeedNotUnique` rather than choosing a winner.
  `M3-CP4c3-TB25-REV-CAND-01` — the starved seed rule — is **CLOSED / RUNTIME PROVED**: the restored rule produces
  seeds again, and it produces the *same* `[0,1,3]` the pre-CB27 rule produced, confirming the restoration is
  faithful.
- **CJ9 worked.** Ordinals 404 and 405 PASS; the constructed vertex-transit falsifiability witness holds.
- **398 remains the correct strong gate** and was not touched.
- **Accepted 365/365**, no accepted RED ordinal, no accepted-green loss, no package/source/execution-view mutation,
  no orchestration failure.

---

## 4. CK4 — classification of the 8 RED ordinals

| Ordinal | Cause |
|---|---|
| 366, 367 | **The open frontier**, correctly fail-closed. The plan cannot consume a component with three conflicting owners, and it must not choose one. No product correction is authorized until §1 and §2 are discharged. |
| 393 | **Stale arity, §4.1.** Test-authority, not product. |
| 398 | **The honest gate.** `proves_cellularity()` is false because ownership genuinely is incomplete. Untouched. |
| 368, 369, 370, 374 | **Unchanged carried surfaces**, separate owners, untouched by this review. The report is right that no evidence merges them into the ownership cause. |

### 4.1 Ordinal 393 — `191 == 573` is a stale arity assumption

`573 = 3 × 191`. The identity asserts one certified-face observation per component face; CJ7 deliberately publishes
the **full conflict multiset**, so every one of the 191 faces now carries all three owners and the observation count
is three times the face count. The identity's own subject succeeds — it prints
`certifiedOwners=0:191,1:191,3:191;allEqual=false`, which is the correct and useful output.

**The assertion, not the product, is wrong**, and it is wrong in the same way `LESSONS.md` 123 describes: it
encodes an arity that a deliberate design decision has superseded. The contract the identity owns is **coverage** —
the set of source faces appearing in the observations equals the component's face set — plus untruncated
publication of the multiset. That is what CK8 replaces it with, in place, ordinal retained and gating. Counting
rows instead of distinct faces is not a contract; it was an incidental consequence of single-owner publication.

---

## 5. CK5 — the questions the intake asks that I decline to answer yet

**Intake question 3 — how should a component be partitioned when an arc crosses its interior?** Not answerable
until §1 reports whether any interior arc separates. If all four are bridges, no separation exists and the
partition is fine; the attribution rule is what mis-fires. If one separates, the partition must be refined by that
arc and the terminal-slit exclusion is a genuine ownership defect rather than a benign one. **Two opposite
corrections follow from one unprinted pair of integers.** Answering now would repeat the error `LESSONS.md` 64
records — declaring the layer done one turn early.

**Intake question 5 — the minimal product correction for 366/367/398.** Same dependency, plus §2: a correction
aimed at the certifier's component is not obviously a correction to the plan's. **No product correction is
authorized in CB31.** Fail-closed conflict semantics are preserved exactly as the intake requires.

I record explicitly that this is the fifth consecutive diagnostic turn on this frontier, and that
`LESSONS.md` 115 warns against exactly that pattern. The distinction I am relying on is concrete and checkable:
the four earlier turns failed because the datum did not exist, or its input did not survive the failure. **Here the
datum exists, is computed, and is stored in a published struct.** CB31 prints what CB30 already measured and
establishes which partition the numbers belong to. If CB31's report still cannot name the arcs, the pattern is no
longer distinguishable from the previous four and the next review should say so.

---

## 6. CK6 — stable accounting

**No stable event, category, or recurrence is added.** Totals remain **44 events / 14 categories / 30
recurrences**, produced-witness debt **5**, semantic M3 package count **91**.

1. accepted **1–365 = 365/365** with no accepted RED ordinal and no accepted-green loss;
2. 389/390 **recovered**; recovery is not an event;
3. 393's RED is a **test-authority** arity mismatch introduced by a deliberate publication decision, not a
   behaviour loss;
4. 366/367/368/369/370/374/398 are already-counted carried surfaces and open-frontier gates;
5. the missing per-row serialization and the partition mismatch are **evidence-surface defects** on a diagnostic
   contract, adjudicated here as non-stable candidates with named owners.

---

## 7. CK7 — candidates

**Closing, runtime-proved.**

- `M3-CP4c3-TB25-REV-CAND-01` — the starved seed rule. **CLOSED.** CJ7's restoration produces `[0,1,3]` again,
  identical to the pre-CB27 rule, and publishes disagreement instead of choosing.
- `M3-CP4c3-TB25-REV-CAND-03` — 389/390 gating on foreign assertions. **CLOSED.** Both PASS.

**Carried, and now sharpened.**

- `M3-CP4c3-TB25-REV-CAND-02` — *is the failing component contained in a single certified face?* **ACTIVE /
  GATING / UNDECIDED.** TB26 did **not** decide it: the aggregate does not carry the separating field (§1) and was
  measured on a different partition (§2). Owner: **CK8/CK9**.
- `M3-CP4c3-DEFN-R3-CAND-01` — **PROMOTED to GATING.** No longer an architectural note: the duplicated
  construction has produced two partitions, and the diagnostic is computed on the one that does not fail (§2).
  Owner: **CK9**.
- `M3-CP4c3-TB24-REV-CAND-02` — ownership of non-arc-incident faces is a derivation, not a read. **ACTIVE.**
- `M3-CP4c3-TB22-REV-CAND-01` — **ACTIVE**, and 393's evidence contract is still not exercised as intended.
- Unchanged with separate owners: `M3-CP4c3-TB18-REV-CAND-01`, `M3-CP4c3-TB7-CAND-02`,
  `M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`, `M3-CP4c2-TB-X2-CAND-04`,
  `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, finalize/contact fall-through.

**Adjudicated — the three candidates `M3-CP4c-3-TB26-R1` registered.**

- `M3-CP4c3-TB26-REV-CAND-01` — aggregate-only serialization of the CJ6 censuses. **UPHELD / GATING.** §1.1 adds
  that the deciding fields are already computed and stored, so this is a print, not an investigation. Owner:
  **CK8**. Falsified when TB27's log names every interior-arc row with both orbits.
- `M3-CP4c3-TB26-REV-CAND-02` — 76 versus 97 boundary rows. **RESOLVED / LAWFUL DOMAIN DIFFERENCE**, §2.1. No row
  was omitted; the counts belong to two different partitions. It closes as posed, and what it uncovered is carried
  forward as CAND-04 below.
- `M3-CP4c3-TB26-REV-CAND-03` — ordinal 393's `191` versus `573`. **UPHELD / TEST AUTHORITY**, §4.1: a stale arity
  assumption superseded by deliberate multi-owner publication. Owner: **CK8**.

**New.**

- `M3-CP4c3-TB26-REV-CAND-04` — **NEW / ACTIVE / GATING / ARCHITECTURAL.** The CJ6 censuses describe the
  certifier's partition; the RED is raised on the plan's, and the two have different domains and different barrier
  sets by construction (§2). No published evidence establishes that their component 0s are the same faces. Owner:
  **CK9**.

---

## 8. CK8–CK9 — frozen successor: `M3-CP4c-3-CB31`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`. No acceptance evidence. **CB31 prints what
CB30 already measured and establishes which partition it belongs to. It corrects no product behaviour.**

### CK8 — serialize the deciding fields, and fix one stale assertion

1. The diagnostic rendering of every uncut-component census must emit **one line per row**, not aggregates, for
   the failing component, untruncated:
   - **interior arc incidences** — `arc` id, `kind`, **`forwardOrbit`**, **`reverseOrbit`**;
   - **seed attributions** — `sourceEdge`, `componentFace`, `oppositeFace`, `orbit`, **`rule`**;
   - **boundary edges** — `sourceEdge`, `componentFace`, `oppositeFace`, `barrierClass`, `barrierPresent`,
     `oppositeFaceTraceCut`, `sideOwnerExists`;
   - **vertex transits** — `trace`, `segmentIndex`, `sourceVertex`, `adjacentAcrossNonBarrierEdge` and, when set,
     the adjacent edge and face pair.
   Also emit the component's **face count** and a stable digest of its face set.
2. Ordinal **404** is strengthened in place: it must additionally assert, for the failing component, that
   `interiorArcIncidencesTruncated`, `seedAttributionsTruncated`, `boundaryEdgesTruncated` and
   `vertexTransitsTruncated` are all false, and that every interior-arc row exposes both orbit fields. Name and
   ordinal unchanged; it still asserts publication and completeness, **never a value**.
3. Ordinal **393**'s failure-locus assertion is **replaced in place**: assert that the **set of distinct source
   faces** appearing in the certified-owner observations equals the component's face set, and that the owner
   multiset is published untruncated. It must not assert an observation-row count. Ordinal retained, gating, name
   unchanged. Precedent: DEFN-R3.7 for 393, CH9 for 385, CJ8 for 390.

Selector 405 is **unchanged and byte-frozen** by CK8 — no identity is added or removed.

### CK9 — establish which partition the census describes

The failure locus and the census must be comparable as objects.

1. `SurfaceCutGraphUncutComponentCensus` publishes the **partition identity** it was built from: the domain rule
   (`NotTraceCut`) and the barrier-set composition, as typed data rather than prose.
2. `UncutFaceComponentOrbitSeedNotUnique`'s locus publishes the same for the plan's partition
   (`EmptyFragmentOrbits`, `mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges`), plus its component's face-set digest.
3. One new gating identity, selector **406** with 405 as its exact 405-line prefix:
   **`GlobalTopologyPlan.UncutComponentCensusNamesThePartitionItDescribesAndWhetherItMatchesTheFailingComponent`**
   — asserts that both partition identities and both face-set digests are published, and that the locus states
   **whether they match**. It asserts **publication of the correspondence, not equality**, because inequality is a
   live possibility and a gate must not demand a hypothesis be true (`LESSONS.md` 123).

**CK9 does not unify the two partitions.** Unification is a real candidate — `M3-CP4c3-DEFN-R3-CAND-01` — but
choosing which partition is authoritative is a definition decision, not a build decision, and it must not be made
while the arcs are unnamed.

### Prohibited in CB31

1. Changing any accepted identity 1–365, or any byte of selector 397/401/403/405 or the first 405 lines of
   selector 406.
2. Weakening `proves_cellularity()` or ordinals 397–405. **Ordinal 398 is untouched.**
3. Any product behaviour change: no barrier added or removed, no attribution rule changed, no seed winner chosen,
   no partition unified, no `terminalSlit` handling altered.
4. Asserting a value in ordinal 404 or the new 406 identity. Both assert publication and completeness only.
5. Inferring the interior-arc rows from static source in place of publishing them.
6. Executing any Directional runtime.

---

## 9. Predictions — recorded as predictions

All four interior-arc rows will show `forwardOrbit == reverseOrbit`, refuting the separating-arc horn, and the two
minority seed attributions will name their rule as one of the two restored paths. I have been wrong on this
frontier at DEFN-R3 and at TB24-REV and right at TB25-REV; this prediction rests on a static derivation (§1.2)
rather than on intuition, which is why I am willing to state it — but **no measure in §8 depends on it**, and CK8
reports whichever pair it finds.

The load-bearing claims of this review are not the prediction. They are: **an incidence count is not a separation**
(§1), and **the census and the failure describe different partitions** (§2). Both are provable from the source at
`e045bf7147afc02bd90eff4822e4b609edbaba66`.

## 10. Consolidation performed

Per `CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW turn". Durable facts were verified present in this
record, `Architecture_M3_CP4c3_TB26_R1_Artifact_Only_Test_Benchmark_Report.md`,
`Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` before
any fold.

Folded: `Architecture_M3_CP4c3_TB25_Independent_Review_Record.md` (superseded review authority, CJ0–CJ9),
`Architecture_M3_CP4c3_CB28_Code_Build_Report.md` (consumed build report, superseded as package authority by
CB30), `Architecture_M3_CP4c3_TB26_Independent_Review_Intake.md` (consumed task brief for this review).

**Noted, not corrected here:** CB30 has no retained standalone Code + Build report. Its package authority
(`9957324848`) is carried by the TB26-R1 report and the CHANGELOG. A successor CB should restore the per-turn build
report so the package under test has a first-class provenance document.

Retained as current authority: `Architecture_M3_CP4c3_TB26_R1_Artifact_Only_Test_Benchmark_Report.md`, this record,
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`,
`M3_CP4c_Consolidated_Record.md`, and every `Required_Green_Selector_*.txt`.

## 11. Lessons added

`LESSONS.md` **125** — an incidence count is not a separation; publish the field that carries the distinction.
`LESSONS.md` **126** — a diagnostic must be computed on the object that failed.

## 12. Exact successor

**`M3-CP4c-3-CB31`** under **CK8–CK9**, Code + Build, runtime-free, GMP/GMPXX linked. Serialization, one stale
assertion replaced in place, and partition identity. No product correction, no barrier change, no winner selected,
no accepted-prefix change.
