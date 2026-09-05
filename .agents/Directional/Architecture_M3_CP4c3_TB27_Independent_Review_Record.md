# M3-CP4c-3-TB27 Independent Review Record

## Status

**COMPLETE / STATIC / NO RUNTIME / NO COMPILE / NON-STABLE / SUCCESSOR FROZEN.**

`M3-CP4c-3-TB27-REV` is independent REVIEW + PLAN only. It executed no Directional runtime, no compile, no package
operation, and mutated no product, test, fixture, benchmark, build or selector byte. Accepted authority remains
**365/365**; runtime authority is `M3-CP4c-3-TB27-R1` (**399 PASS / 7 RED** on selector 406). CP4c-3 remains
**OPEN**. Measures **CL0–CL9** freeze the exact successor **`M3-CP4c-3-CB32`**.

`review_check.py authority eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc` — **ALL CHECKS PASSED**. Static review of the
working tree is valid evidence about immutable package `9961564041`.

---

## 1. CL0 — my prediction was refuted, and I am recording that first

At TB26-REV I predicted, from a static derivation, that **all four interior-arc rows would show
`forwardOrbit == reverseOrbit`** — that every arc reaching an uncut component's interior does so through a terminal
slit, ends at a degree-1 node, and is therefore a bridge separating nothing.

TB27-R1 measured:

| Arc | Kind | forwardOrbit | reverseOrbit | relation |
|---:|---|---:|---:|---|
| 14 | Trace | 0 | **1** | **separating** |
| 20 | Trace | 0 | 0 | equal |
| 22 | Trace | 0 | **3** | **separating** |
| 24 | Trace | 0 | 0 | equal |

**Two of four separate. The prediction is refuted for the certifier component.** The derivation's hidden premise
was the one I flagged as a hedge — that the arc's end node has degree 1. An arc is built between *consecutive*
`TraceCut` nodes and may contain a terminal-slit **segment** while still running between two genuine graph nodes.
A per-segment property was used to infer a per-arc one. That is the same class of error as `LESSONS.md` 125, which
I wrote last turn: I reasoned about the wrong granularity.

The load-bearing claims of that review — that an incidence count is not a separation (§1) and that the census
described a different object than the failure (§2) — are both **confirmed** below. The prediction was explicitly
labelled non-load-bearing and no measure depended on it. That is what kept the turn productive despite being
wrong, and it is the design property to keep.

### 1.1 The stop rule I set last turn did not trigger

At TB26-REV I wrote that if CB31's report still could not name the arcs, the pattern would no longer be
distinguishable from the four failed measurement attempts before it. **CB31 named them.** Ordinal 404 publishes
all four rows with both orbits, all truncation flags false, and a validated face-set digest; ordinal 406 publishes
both partition identities and digests. The serialization diagnosis was correct and the fix was exactly as cheap as
predicted. `M3-CP4c3-TB26-REV-CAND-01` and `-CAND-03` are discharged.

---

## 2. CL1 — CK9 runtime-proves the partition mismatch

Ordinal 406 publishes:

```
failingComponent=0; failingDomain=EmptyFragmentOrbits; failingFaceSetDigest=17919102493633069558;
censusComponent=0;  censusDomain=NotTraceCut;          censusFaceSetDigest=7937364815223192706;
matchesFailingComponent=false
```

**191 faces versus 214, different digests, and the product itself reports false correspondence.** This is the
central result of the turn and it confirms `M3-CP4c3-TB26-REV-CAND-04` and `M3-CP4c3-DEFN-R3-CAND-01` at runtime.

The immediate consequence is a prohibition: **the two separating arcs measured by ordinal 404 are properties of
the 214-face certifier component and may not be promoted into evidence about the 191-face failing component.**
TB27-R1 states this correctly and does not overreach — a marked improvement on TB26-R1's §1.

### 2.1 What is provable statically about the relationship between the two partitions

The two are not arbitrary. Both facts below follow from the source at
`eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc`:

- **The barrier families are the same three.** CB31's own typed publication names them
  `mandatoryEdges / traceTouchedEdges / cutEdges` on the plan side and cut edges, mandatory/cut arc source edges,
  and non-terminal trace carriers on the certifier side. `traceTouchedEdges` is built from
  `segment.outgoingCarrier` and `segment.incomingCarrier` with the same `is_terminal_slit` skip
  (`GlobalTopologyPlan.cpp:830–843`) that the certifier applies (`SurfaceCutGraph.cpp:523–530`).
- **The plan's domain is contained in the certifier's.** A non-slit trace segment calls `add_fragment_orbit` on its
  face, so every trace-cut face has a non-empty `fragmentOrbits` entry and is excluded from `unlabeledFaces`.
  Contrapositive: a face in the plan's domain is not trace-cut, hence is in the certifier's domain.

Same barriers plus a contained domain gives **plan component ⊆ certifier component**. The 23-face difference is
consistent with the faces the plan excludes and the certifier keeps: those given a `fragmentOrbits` entry by the
mandatory/cut arc interior rule at `GlobalTopologyPlan.cpp:702` and `:750` — which are precisely the faces carrying
a **direct certified read**. The plan excludes its own best seeds from the component it then fails to seed.

**This is not proof that the 191-set is inside the 214-set**, because digests are not containment-checkable, and I
am not asserting it. It is the shape the next measurement must confirm.

---

## 3. CL2 — the question the evidence now poses, precisely

Everything reduces to one unmeasured fact:

> **Which source faces do arcs 14, 20, 22 and 24 cross, and which component of each partition contains those
> faces?**

Two exhaustive branches, both with a correction already named:

- **A separating arc (14 or 22) crosses the 191-face failing component** ⇒ that component genuinely spans certified
  faces, its three seeds `[0,1,3]` are the true geometry rather than two attribution errors, and **the seed guard
  is right to fail.** The defect is then the **barrier set**: an arc that separates certified faces must induce
  barriers, and these do not.
- **Neither separating arc crosses it** ⇒ the failing component meets no separating arc, so by the CJ2 dichotomy it
  lies in exactly one certified face, and its minority seeds are **attribution errors**. The defect is then the
  **attribution rule**, and the 46 published seed-attribution rows already name the offending edges.

### 3.1 A conjecture, labelled as one

The reverse orbits of the two separating arcs are **1** and **3**. The failing component's three seeds are
**`[0,1,3]`**, distributed 81/1/1 across its 83 attributed boundary edges — one lone edge voting orbit 1 and one
voting orbit 3.

**That correspondence is striking and it is not evidence.** The arcs were measured on a different component. This
project has repeatedly paid for identifying two loci because their numbers matched (`LESSONS.md` 57, 64), and
`ORIENTATION.md` already records that identical values across witnesses do not establish identical cause. I record
the conjecture only so CL6 can confirm or refute it, and no measure below assumes it.

### 3.2 Why the terminal-slit rule is the mechanism to look at

`GlobalTopologyPlan.cpp:830–836` justifies skipping a terminal slit with: *"a terminal slit contributes zero to k,
touches no source edge, and publishes no orbit evidence."* The first clause is about fragment counts and is sound.
**The third is now measurably false in general**: arcs containing a terminal-slit segment do publish orbit
evidence, and for arcs 14 and 22 that evidence says the arc separates. The rule decides a **per-face** trace-cut
status and a **per-edge** barrier status from a **per-segment** property, which is the granularity error of §1.

I am not authorizing a change to it. CL6 measures which faces those arcs cross; the review that reads TB28 decides.

---

## 4. CL3 — classification of the 7 RED ordinals

| Ordinal | Cause |
|---|---|
| 366, 367 | **The open frontier**, correctly failing closed on three conflicting owners. No correction authorized until CL6 reports. |
| 398 | **The honest gate.** `proves_cellularity()` is false because ownership genuinely is incomplete. Untouched, and it must stay that way. |
| 368, 369, 370, 374 | **Unchanged carried surfaces**, separate owners, untouched. TB27-R1 correctly infers no cross-cause merge. |

**Recovered this turn: 393.** It now checks distinct-source-face coverage and untruncated publication, PASSes, and
still prints the full conflict population `certifiedOwners=0:191,1:191,3:191;allEqual=false`. The repair removed a
false rejection without hiding anything or choosing a winner — exactly what CK8 required.

The RED set is now **the smallest it has been in this checkpoint**: one product frontier, one honest gate, four
independently owned carried surfaces. Every ordinal that was collateral to the diagnostic scaffolding has been
returned to green without weakening a contract.

---

## 5. CL4 — stable accounting

**No stable event, category, or recurrence is added.** Totals remain **44 events / 14 categories / 30
recurrences**, produced-witness debt **5**, semantic M3 package count **92**.

1. accepted **1–365 = 365/365** with no accepted RED ordinal and no accepted-green loss;
2. **393 recovered**; recovery is not an event;
3. 366/367/398 are already-counted open-frontier surfaces; 368/369/370/374 are already-counted carried surfaces;
4. the orchestration-invalid attempt `33946019995` stopped with `runtime_started=false` and carries no semantic
   credit; the correction changed only the harness's census comparison, retaining artifact-digest and internal
   `SHA256SUMS` authority.

---

## 6. CL5 — candidates

**Discharged.**

- `M3-CP4c3-TB26-REV-CAND-01` — aggregate-only serialization. **CLOSED / RUNTIME PROVED.** All four rows published
  with both orbits, untruncated, digest validated.
- `M3-CP4c3-TB26-REV-CAND-03` — ordinal 393's stale arity. **CLOSED / RUNTIME PROVED.** 393 PASSes on the coverage
  contract with the conflict population still fully published.

**Confirmed at runtime and now gating.**

- `M3-CP4c3-TB26-REV-CAND-04` — census partition ≠ failure partition. **CONFIRMED**, `matchesFailingComponent=false`
  with 214 versus 191 faces and differing digests. **ACTIVE / GATING.** Owner: **CL6/CL7**.
- `M3-CP4c3-DEFN-R3-CAND-01` — two independent constructions of one topology. **CONFIRMED / GATING.** The
  duplication now demonstrably produces two different partition objects. Owner: **CL7**, and a definition turn
  thereafter if unification is chosen.

**Still undecided, and now precisely posed.**

- `M3-CP4c3-TB25-REV-CAND-02` — *is the failing component contained in a single certified face?* **ACTIVE /
  GATING.** TB27 measured separating arcs on the wrong component. Owner: **CL6**, §3.

**New.**

- `M3-CP4c3-TB27-REV-CAND-01` — **NEW / ACTIVE / GATING / PRODUCT.** The certifier's 214-face component contains
  two separating trace arcs, so **that partition merges source faces lying in different certified faces**. Any
  ownership propagated across it would be unsound; it is currently masked only because the component has no unique
  seed. Owner: **CL6**, then the TB28 review.
- `M3-CP4c3-TB27-REV-CAND-02` — **NEW / ACTIVE / ARCHITECTURAL / NON-GATING.** The plan excludes from its component
  domain exactly the faces that carry a direct certified read (`GlobalTopologyPlan.cpp:702`, `:750`), then fails to
  seed that component. Owner: **CL7**.

**Unchanged with separate owners.** `M3-CP4c3-TB24-REV-CAND-02`, `M3-CP4c3-TB22-REV-CAND-01`,
`M3-CP4c3-TB18-REV-CAND-01`, `M3-CP4c3-TB7-CAND-02`, `M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`,
`M3-CP4c2-TB-X2-CAND-04`, `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, finalize/contact
fall-through.

---

## 7. CL6–CL9 — frozen successor: `M3-CP4c-3-CB32`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`. No acceptance evidence.

### CL6 — the arc-locus census, and the closing measurement on this frontier

For **every** interior-arc row already published, add the locus that makes it attributable:

1. the arc's **crossed source faces** — `arc.sourceFaces`, untruncated;
2. for each crossed face, its component id in **both** partitions, or an explicit `absent` when the face is in
   neither domain;
3. the reason each crossed face is **not** in `traceCutFaces` — typed, one of `TerminalSlit`,
   `SegmentRangeInvalid`, `TraceNotFound`, `DartOutOfRange`, `FaceNotFound`, or `Other`. The certifier's own loop
   has every one of those exits (`SurfaceCutGraph.cpp:497–530`); which one fired is the mechanism, and guessing it from source is
   forbidden.

Publish the same three fields for the **failing plan component's** interior arcs, computed over the plan's
partition, so the question in §3 is answered about the object that fails.

**Falsification, stated before the measurement is built.** Exactly one of these holds and each names its own
correction:

- **a separating arc crosses the failing component** ⇒ the component genuinely spans certified faces; the seed
  guard is correct; the **barrier set** is the defect and the arc is named;
- **no separating arc crosses it** ⇒ the component lies in one certified face; the **attribution rule** is the
  defect and the offending edges are already named in the 46 seed-attribution rows;
- **the failing component's faces are not a subset of the certifier component's** ⇒ §2.1's static containment
  argument is wrong and the two partitions diverge more deeply than a domain predicate.

### CL7 — publish the containment relation, do not unify

The plan locus additionally publishes whether its failing component's face set is a **subset** of the named
certifier component's, alongside the existing equality boolean. Subset is the relation §2.1 predicts and equality
is the one CK9 already refuted; publishing only the refuted one leaves the useful fact unstated.

**No partition is unified in CB32.** Choosing which partition is authoritative is a definition decision — it
belongs to a `DEFN` turn once the mechanism is known, and `M3-CP4c3-DEFN-R3-CAND-01` is its owner.

### CL8 — hard stop rule on this frontier

**`M3-CP4c-3-CB32` is the last diagnostic turn authorized on source-face ownership.** The review that reads TB28
**must freeze a product correction**, whichever branch CL6 measures. Both corrections are pre-named in §3 and
CL6's outcomes are exhaustive, so "insufficient evidence" will not be an available finding. If CL6's censuses come
back incomplete or ambiguous, that is itself the finding, and the correction defaults to the barrier-set branch,
which is the sound-by-construction one: **an arc whose two darts lie in different face-walk orbits must induce a
barrier.**

This rule exists because the count of diagnostic turns on this frontier is now the project's largest risk, ahead of
any single defect. `LESSONS.md` 115 and 127.

### CL9 — witnesses and selector

Selector **407**, with selector 406 as its exact 406-line prefix and 405/403/401/397/365 the frozen prefixes of
that. One gating identity:

- **407** `SurfaceCutGraph.InteriorArcCensusNamesCrossedFacesAndTheirComponentsInBothPartitions` — on the
  mechanical production fixture, every interior-arc row publishes its crossed faces untruncated, each face's
  component id in both partitions, and the typed reason the face is not trace-cut. Asserts **publication and
  completeness only, never a value**, and must not require any owner to be established.

Ordinal **404** is strengthened in place to require the new per-row fields; ordinal, name and the first 406 selector
lines are unchanged.

### Prohibited in CB32

1. Changing any accepted identity 1–365, or any byte of selector 397/401/403/405/406 or the first 406 lines of
   selector 407.
2. Weakening `proves_cellularity()` or ordinals 397–406. **Ordinal 398 is untouched.**
3. Any product behaviour change: no barrier added or removed, no attribution rule changed, no seed winner chosen,
   no partition unified, no `terminalSlit` handling altered.
4. Asserting a value in ordinal 404 or 407. Both assert publication and completeness only.
5. Gating any CL6 census on an established owner, or inferring a `traceCutFaces` exit reason from static source
   instead of publishing it.
6. Executing any Directional runtime.

---

## 8. Predictions

I predict CL6 will find that **a separating arc crosses the failing component**, making the seed guard correct and
the barrier set the defect. I hold this loosely: my last prediction on this frontier was refuted, the one before it
was refuted, and TB25-REV's was upheld. The conjecture in §3.1 is the reason for it and it is explicitly not
evidence.

Per CL8 this prediction cannot delay anything: CL6's outcomes are exhaustive, both corrections are named, and the
default on ambiguity is the barrier-set branch.

## 9. Consolidation performed

Per `CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW turn". Durable facts were verified present in this
record, `Architecture_M3_CP4c3_TB27_R1_Artifact_Only_Test_Benchmark_Report.md`,
`Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` before
any fold.

Folded: `Architecture_M3_CP4c3_TB26_Independent_Review_Record.md` (superseded review authority, CK0–CK9 — CK8/CK9
runtime-proved, its §1.2 prediction refuted), `Architecture_M3_CP4c3_TB26_R1_Artifact_Only_Test_Benchmark_Report.md`
(superseded runtime authority), `Architecture_M3_CP4c3_TB25_R1_Artifact_Only_Test_Benchmark_Report.md` (superseded
runtime authority, retained one turn longer than usual as the 226-unavailable baseline, now carried here).

Retained as current authority: `Architecture_M3_CP4c3_TB27_R1_Artifact_Only_Test_Benchmark_Report.md`,
`Architecture_M3_CP4c3_CB31_Code_Build_Report.md` (the package under review), this record,
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`,
`M3_CP4c_Consolidated_Record.md`, and every `Required_Green_Selector_*.txt`.

## 10. Lessons added

`LESSONS.md` **127** — a per-segment property cannot decide a per-arc or per-face classification.
`LESSONS.md` **128** — when a measurement chain reaches its third turn, freeze the stop rule with the corrections
pre-named.

## 11. Exact successor

**`M3-CP4c-3-CB32`** under **CL6–CL9**, Code + Build, runtime-free, GMP/GMPXX linked. The **last diagnostic turn
authorized on this frontier**. No product correction, no barrier change, no partition unification, no winner
selected, no accepted-prefix change.
