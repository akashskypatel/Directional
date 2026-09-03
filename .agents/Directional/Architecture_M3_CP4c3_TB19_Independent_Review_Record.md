# M3 CP4c-3 TB19 — Independent Review + Plan Record

Date: 2026-09-03 UTC
Turn: `M3-CP4c-3-TB19-REV`
Type: **independent REVIEW + PLAN — STATIC ONLY**
Status: **COMPLETE / CB21 CONFIRMED / NEW FRONTIER LOCUS PROVED NON-DISCRIMINATING / SEED CARDINALITY UNOBSERVABLE / DIAGNOSTIC-ONLY SUCCESSOR FROZEN / NON-STABLE**

No Directional runtime, configure, compile, link, package, benchmark, or product/test/fixture/selector mutation
occurred in this turn. Every claim is derived from committed bytes, from the immutable TB19 evidence, or from a
stated construction the code performs.

Measures discharged: **CR0–CR8** per `Architecture_M3_CP4c3_TB19_Independent_Review_Plan.md`. Successor frozen:
exactly one — **`M3-CP4c-3-CB22`** under **BV0–BV9**, diagnostic-only.

---

## 1. CR0 — authority and immutability

| Check | Result |
|---|---|
| Semantic source `b00efbd53d3da8caa2bcac0d66594e06e44d2cb2` exists | **PASS** — `fix: correct CB21 compile errors`, 2026-09-03 19:03:47 +0000 |
| Source is an ancestor of branch HEAD | **PASS** |
| No code drift `source..HEAD` | **PASS** — static review of the working tree is valid evidence about the package |
| Selector 384 recomputes to `c9425b9309415d43d49e5791cc43fd5e5e3bf3ae50d02c329c65d3e632a05564` | **PASS**, 384 identities |
| Selector 383 is an exact 383-line prefix of 384 | **PASS**, prefix digest `a7fe57cc…6f3a4b2c` |
| Selector 384 appends exactly one identity | **PASS** — ordinal 384 `GlobalTopologyPlan.FragmentOwnerDeficitPublishesCorrectionEvidenceThroughProductionPath`, which is exactly the BU5/BU6 identity |
| Accepted 365-prefix authority | **PASS** — `6b5b6555…cfc14b8a1`, unchanged |
| 384-row ledger arithmetic | **PASS** — 376 PASS + 8 RED = 384 |
| Pre/post package byte+mode census | **IDENTICAL**, `c2386681…275e133d` |
| Execution boundary | **PASS** — `runtimeExecution=true` with every mutation, repair, rebuild, discovery and benchmark flag false |

Verified with `.agents/Directional/tools/review_check.py authority` and `selector_probe.py {hash,prefix,ordinal}`
against LF-normalized bytes. **No rerun is authorized by this review.**

**CB21 is confirmed against BU0–BU9.** Ordinals 1–365 remain **365/365**; ordinal 366 no longer reds at
`TraceCutFaceFragmentCountMismatch` (BU9-2, the load-bearing discriminator); 367/371/372 moved with it (BU9-3); the
deficit at `(0,1,102)` is retained as **1** with the shared-owner chord named (BU9-4); the census is published and
untruncated (BU9-5); carried surfaces are unchanged (BU9-6). The accepted-boundary safety proof that TB18-REV made
by construction is now runtime-visible. **`M3-CP4c3-TB17-CAND-01` closes.**

---

## 2. CR1 — what the new terminal predicate means, and what its locus does not mean

The sole emitter is `GlobalTopologyPlan.cpp:1151–1163`, in the unlabeled-face seeding block:

```cpp
for (std::size_t index = 0U; index < unlabeledFaces.size(); ++index) {
  const auto component = componentPartition.componentByFace.find(unlabeledFaces[index]);
  …
  const auto seeds = seedOrbits.find(component->second);
  if (seeds == seedOrbits.end() || seeds->second.size() != 1U) {
    GlobalTopologyPlanError failure = error(GlobalTopologyPlanErrorCode::UncutFaceComponentOrbitSeedNotUnique);
    failure.sourceFace = unlabeledFaces[index];
    return failure;
  }
  fragmentOrbits[unlabeledFaces[index]].insert(*seeds->second.begin());
}
```

`unlabeledFaces` is filled by iterating `topology.faces` — a `std::map`, so **key order** — and keeping every face
with no `fragmentOrbits` entry. `componentBarriers` is `mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges`, and
`seedOrbits[component]` is the union, over every non-barrier edge with one unlabeled and one labeled side, of the
labeled side's orbit — taken directly when that face has exactly one owner, otherwise from
`edgeOrbitEvidence[(labeledFace, edge)]` when *that* is unique, and **silently skipped when neither is unique**.

### The reported locus is an ordering artifact, and this is proved

`failure.sourceFace` is the **first unlabeled face in map order whose component fails** — not the face, edge,
component or seed that caused the failure. Two independent facts prove the locus carries essentially no
information:

1. **`(0,1,2)` is mesh row 0 of the mechanical fixture** (`fixture_probe face 0 1 2` → `row 0 = (0, 1, 2)`), and
   `(0,1,2)` is the lexicographically minimal possible face key. It is the first candidate the loop can ever
   report.
2. **The historical torus stop reported the identical face.** `CHANGELOG.md` line 361, `M3-CP4c-1-TB-R2`: *"Torus is
   unchanged (A2a, **0 traces/events**, A2b `UncutFaceComponentOrbitSeedNotUnique` at `0-1-2`)"*. The torus fixture
   is 72/216/144 and its row 0 is also `(0, 1, 2)`.

Two fixtures of different size, different genus and different producer state report the **same error code at the
same face key**. The locus is a property of `std::map` ordering, not of the defect.

### The mechanical seed cardinality is NOT derivable from committed bytes

The failing branch fires on `seeds == end()` (**zero** seeds) or `size() != 1` with the entry present
(**two or more**). Distinguishing them requires the component's membership and its seed set, neither of which is
retained. Static analysis narrows but does not close it:

- **Zero is not excluded.** A component every one of whose boundary edges is a barrier, or whose only labeled
  neighbours are two-owner faces across edges with no `edgeOrbitEvidence` row, contributes nothing to `seedOrbits`.
  The `seed.has_value()` skip is silent, so this failure mode leaves no trace at all.
- **Two-or-more is not excluded, and there is partial evidence for it.** Face `(0,1,2)` is row 0, whose edges
  include `0-1`, shared with **row 259 = `(0,1,102)`** — the face TB18 examined, which TB19 confirms is labeled with
  **exactly one** owner (`ownerCount=1`). That chord's carriers were `incomingCarrier=none` and
  `outgoingCarrier=0-102`, so **`0-1` was never inserted into `traceTouchedEdges`**. If `0-1` is also outside
  `mandatoryEdges ∪ cutEdges`, it is a valid seeding edge and the component containing `(0,1,2)` receives at least
  one seed — which would force the failure into the **two-or-more** branch. Whether `0-1` is a cut or mandatory
  edge is a product decision not recoverable from committed bytes; geometric sharpness is not the barrier set.

**Verdict: still unobservable.** The bounded evidence that decides it is specified in BV1–BV3 below. This is CR1's
explicitly permitted third answer, and it is reached on evidence rather than by declining to look.

### The deciding numbers are discarded, again

At the moment of failure the function holds the component id, `componentPartition.componentByFace`, the full
`seedOrbits` entry and `unlabeledFaces.size()`. It retains **only `sourceFace`** — and, as proved above, the one
field it retains is the one that cannot discriminate. This is the **sixth** instance of the class (lessons 95, 97):
*the measurement that decides the failure is computed and then dropped at the boundary that reports it.*

---

## 3. CR2 — the historical torus stop is the same guard, a different mechanism

Compared without assuming recurrence, as CR2 requires.

| | Torus, `M3-CP4c-1-TB-R2` | Mechanical, TB19 |
|---|---|---|
| Producer state | **0 traces / 0 events** | **12 traces**, 26 arcs, 70 cut faces |
| Labeled faces | none can exist — no chord labels any face | 70 with chord evidence, plus mandatory/boundary faces |
| Face-walk orbits | — | **6 total, 0 exterior, 6 non-exterior** |
| Seed set | necessarily **empty** — no labeled side exists for any edge | at least one seed is available unless `0-1` is a barrier |
| Reported face | `0-1-2` = row 0 | `(0,1,2)` = row 0 |

**The torus case is provably the zero-seed branch.** With zero traces, no face acquires a chord label, so no edge
can have a labeled side, so `seedOrbits` is empty for every component and the first unlabeled face in map order
fails. Its root cause was an empty producer, upstream of this guard entirely.

**The mechanical case cannot be that.** Seventy labeled faces and six non-exterior orbits exist. Whatever fires
here is a different condition reached through a fully populated producer.

**Same guard, different mechanism, identical name and identical locus.** The candidates must not be merged.
Recorded as a lesson: an error code plus a source locus that two unrelated witnesses both produce is not an
identity — it is a shared *symptom*.

---

## 4. CR3 — the non-crossing candidate is refuted as a universal theorem

TB19 retains 70 face rows, all `localArrangementEvaluated=true`, all `chordsCrossInside=false`, untruncated. The
question is what that proves.

**It proves witness-local sufficiency only, and a universal non-crossing invariant is not merely unproved — it is
refuted by the product's own model.** `SurfaceCellTracing.cpp` constructs contact nodes at trace intersections
bound to a source face: `field_aligned_append_contact_node(candidate, *nextFace)`, emitting
`FieldAlignedNetworkEventKind::TraceIntersection` with `contact->sourceFace`. The pipeline therefore explicitly
represents two traces meeting **inside** a source face. On any face where that happens, `k` chords do **not** make
`k+1` local fragments: by Euler's formula on the triangle, `c` interior crossings give `k + 1 + c`.

Consequences:

- `M3-CP4c3-TB18-REV-CAND-01` is **NOT closed** and **must not be promoted to a fatal oracle**. CB21 correctly kept
  `localFragmentCount` non-fatal, and CB22 must keep it non-fatal.
- Its correct closure is a **derivation**, `localFragments = k + 1 + interiorCrossings`, validated against a
  witness that actually contains a crossing — not an assumption extrapolated from a witness that contains none.
- The mechanical witness's uniform `chordsCrossInside=false` is exactly why it cannot settle this: it is the case
  that exercises none of the disputed behaviour.

The candidate transitions from **EVIDENCE** to **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED**, with a concrete
closure condition rather than an open question.

---

## 5. CR4 — 366 / 367 / 371 / 372 ownership after the frontier moved

All four cleared `TraceCutFaceFragmentCountMismatch` and now terminate at the same later typed stop. Ownership
separates as follows:

- **366** — the primary mechanical production witness. It owns the component-seed frontier.
- **367** — genuinely consumes `plan`; it is a real second reader of the same production path, not a duplicate.
- **371 / 372** — read only `fixture.atlas`, but still abort in the shared `cp4c_mechanical_fixture()` constructor,
  which throws unless all five downstream products are retained.

**Decision on `M3-CP4c3-TB10-REV-CAND-01`: remain DEFERRED. Not retired, not authorized.**

The already-specified test-only atlas-scoped accessor would decouple 371/372 so their Amendment-15 contracts are
finally measured. The reason to keep deferring is concrete rather than cautious: **371/372 abort in a fixture
constructor that will stop throwing as soon as the production plan builds.** The frontier moved four ordinals in one
turn. Building a test-only accessor now risks landing a new test surface that the next product correction makes
immediately redundant, and it would be fixture work inside a turn whose job is diagnostics.

**Standing trigger, recorded so this does not drift indefinitely:** authorize the decoupling at the first review
that either (a) closes the mechanical production frontier, or (b) finds the frontier has not advanced across two
consecutive TB turns. Neither condition holds today; (a) is the expected near-term outcome.

No assertion and no selector membership is changed by this review.

---

## 6. CR5 — carried surfaces frozen

Confirmed semantically unchanged from TB18, each under its existing owner, and explicitly **not** merged into the
component-seed correction merely for being red in the same gate:

- **368** — prescribed sphere, `surface-cut-graph/CellularityNotEstablished` originating
  `RotationSystemInconsistent / TraceEventPositionInvalid`, trace 2 / event 30,
  `NoCarrierMatch / SourceEdgeUnavailable`. `M3-CP4c2-TB-X2-CAND-04`.
- **369** — `certificate.saturationUsed == true` where the identity expects false.
  `M3-CP4c2-TB-X2-R10-CAND-01`.
- **370** — cut-graph error object `<04>` instead of `EmptyNetworkOnClosedSurface` `<06>`, with
  `sourceFace.has_value() == false`. `M3-CP4c2-TB-X2-R8-CAND-02`. **No correction authorized.**
- **374** — folded-cone `atlasBuild=false`. `M3-CP4c3-TB7-CAND-02`. **No atlas invariant may be weakened for it.**

Only source line numbers and wall-clock timings moved. **Vertex 30 is still not reached** and the
finalize/contact fall-through (`terminalContact` never read in `finalize_field_aligned_events`) remains untouched
under its own owner.

---

## 7. CR6 — candidates and accounting

| Candidate | Transition |
|---|---|
| `M3-CP4c3-TB17-CAND-01` | **CLOSED at TB19.** Its runtime condition was that ordinal 366 move past the fragment-owner low-side mismatch; 366/367/371/372 all do, with accepted 365/365 preserved and ordinal 384 passing. Not to be reopened without new immutable evidence. |
| `M3-CP4c3-TB19-CAND-01` | **ACTIVE / GATING / MECHANISM UNOBSERVABLE.** The component-seed frontier. Owner class is the seeding block at `GlobalTopologyPlan.cpp:1117–1163`; zero-versus-multiple is undetermined and the reported locus is proved non-discriminating. Owner: BV1–BV4, then TB20-REV. |
| `M3-CP4c3-TB19-REV-CAND-02` | **NEW / ACTIVE / EVIDENCE CONTRACT.** `UncutFaceComponentOrbitSeedNotUnique` retains only `sourceFace`, which is the first unlabeled face in `std::map` order and is provably reported identically by two unrelated witnesses. The error's evidence contract cannot identify its own cause. Owner: BV4. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED** (was EVIDENCE). A universal non-crossing invariant is refuted by the product's own `TraceIntersection` contact nodes; closure requires `localFragments = k + 1 + interiorCrossings` validated on a crossing witness. **Must not be promoted to fatal.** |
| `M3-CP4c3-TB10-REV-CAND-01` | **ACTIVE / TEST-COUPLING / DEFERRED with a standing trigger** (§5). |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone, ordinal 374. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared bound on its input size. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **Still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` / `-R10-CAND-01` / `-R8-CAND-02` | **ACTIVE**, unchanged, §6. |
| finalize/contact fall-through | **ACTIVE** — separate owner. |
| Historical torus `UncutFaceComponentOrbitSeedNotUnique` | **NOT merged** with `M3-CP4c3-TB19-CAND-01`; proved a different mechanism in §3. |

**Accounting.** Static turn on an unaccepted surface; no accepted-green loss; the red ordinal set did not expand and
the only new terminal site is a newly exposed downstream candidate. **+0 events / +0 recurrences.** Totals remain
**44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; semantic M3 package count **85**.
Accepted authority remains **365/365**. CP4c-3 remains **OPEN**.

---

## 8. Lessons recorded

- **100.** *An error code plus a source locus that two unrelated witnesses both produce is a symptom, not an
  identity.* The torus (0 traces, 72/216/144) and the mechanical witness (12 traces, 152/450/300) both report
  `UncutFaceComponentOrbitSeedNotUnique` at face `(0,1,2)` — because `(0,1,2)` is row 0 of both meshes and the
  emitter reports the first unlabeled face in `std::map` order. Before merging two failures by name and locus, check
  whether the locus is a property of the defect or of the iteration.
- **101.** *A guard that reports "not exactly one" must say which side it fell off.* `seeds == end()` and
  `size() > 1` are opposite defects with opposite corrections — an under-seeded component versus a component
  straddling two regions — and the emitter distinguishes them internally and discards the distinction. Sixth
  instance of computing the deciding number and dropping it at the reporting boundary (lessons 95, 97).
- **102.** *A witness that exercises none of the disputed behaviour cannot settle it.* Seventy of seventy retained
  face arrangements are non-crossing, which says nothing about crossing arrangements — and the pipeline explicitly
  builds `TraceIntersection` contact nodes inside a source face, so crossings are a modelled case. Uniform evidence
  from one witness is evidence about that witness.

---

## 9. CR8 — document consolidation

Second application of the standing REVIEW-turn rule (`CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW
turn"). Durable facts verified present in this record, the tracker, `ORIENTATION.md`, `LESSONS.md` and
`CHANGELOG.md` before folding:

- `Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Report.md` — superseded runtime authority;
- `Architecture_M3_CP4c3_TB18_Independent_Review_Record.md` — superseded review authority, whose BU0–BU9 scope
  CB21 discharged and TB19 confirmed;
- `Architecture_M3_CP4c3_CB21_Code_Build_Report.md` — consumed build report;
- `Architecture_M3_CP4c3_TB19_Artifact_Only_Test_Benchmark_Plan.md` — consumed evidence contract, D1–D6 dispositions
  carried by the TB19 report;
- `Architecture_M3_CP4c3_TB19_Independent_Review_Plan.md` — this turn's consumed binding plan, CR0–CR8 discharged
  above.

Retained as current authority: `Architecture_M3_CP4c3_TB19_Artifact_Only_Test_Benchmark_Report.md` and this record,
plus the durable set and every byte-frozen selector file. **No selector file, normative definition, policy, lesson,
stable ID, artifact identity or unresolved blocker was removed or weakened.**

---

## 10. CR7 — frozen successor: `M3-CP4c-3-CB22`, Code + Build, DIAGNOSTIC-ONLY, `BV0–BV9`

Owner: `src/geometry/GlobalTopologyPlan.cpp`, the unlabeled-face component-seeding block at `:1102–1165` and the
error it emits.

**Why diagnostic-only, and why that is not barred here.** CR7's first branch requires a proved product defect *and*
its bounded correction. §2 proves the evidence contract is defective but leaves the seed cardinality undetermined,
and zero-versus-multiple imply **opposite** corrections — seed an under-seeded component, versus separate a
component that straddles two regions. Correcting under either assumption would be guessing. TB18-REV's prohibition
on further diagnostic-only turns was scoped explicitly to the fragment-count surface, which CB21 corrected and TB19
closed; **it does not reach this new surface.** This is the first diagnostic turn on the seeding block, not a third
on the old one.

- **BV0** — accepted 365 untouched; selector **384 byte-frozen** at `c9425b93…632a05564` and republished unchanged;
  the eight standard compile targets with **mandatory GMP/GMPXX linkage**; no runtime; no acceptance claimed.
- **BV1** — put the deciding cardinality on the error: the component id, its **seed count**, and an explicit
  **`seedState ∈ {None, Multiple}`** discriminator so zero and two-or-more are never again conflated.
- **BV2** — retain the failing component's **membership**: face count and a bounded list of its faces with a
  truncation marker. `(0,1,2)` alone is not a component.
- **BV3** — retain the component's **boundary edge rows**, bounded: per edge the edge key, whether the other side is
  labeled, that face's owner count, the edge's barrier class (`mandatory` / `cut` / `traceTouched` / `none`), and
  the seed contributed or the exact reason none was — **including the currently silent
  `edgeOrbitEvidence`-not-unique skip at `:1136–1139`**, which today leaves no trace whatsoever.
- **BV4** — make the locus honest. Keep `sourceFace` for continuity, but publish alongside it that it is the first
  unlabeled face in iteration order, and add the component identity as the discriminating locus. This discharges
  `M3-CP4c3-TB19-REV-CAND-02`.
- **BV5** — extend the existing `TraceFragmentOwnerEvidenceDiagnostic` census rather than inventing a parallel
  channel: a component census — per component the face count, seed count, `seedState`, and seed orbit ids — bounded
  and untruncated-flagged, on the same production path CB21 established and ordinal 384 already pins.
- **BV6** — one witness per new field through the **production** path, plus a byte-identical regression witness for
  an unrelated error's projection. Append **selector 385** with only those identities; no reordering; 384 stays an
  exact prefix.
- **BV7** — **no semantic change whatsoever.** The seeding predicate, `componentBarriers`, the component partition,
  `seedOrbits` construction, the `size() != 1U` test, `edgeOrbitEvidence`, `add_fragment_orbit`, the
  `exteriorOrbits` filter, `is_terminal_slit`, the face walk, the rotation system, region drafts and CB21's
  one-sided fragment comparison all stay untouched. **`localFragmentCount` stays non-fatal** (§4). No fixture
  mutation, tolerance, float-derived decision or accepted-boundary relaxation. No sphere / saturation /
  ordinal-370 / folded-cone / vertex-30 / finalize-contact work. **No 371/372 test decoupling** (§5).
- **BV8** — audit by assumption: prove every addition observational and ordinals 1–365 unaffected by construction.
- **BV9** — six `M3-CP4c-3-TB20` discriminators:
  1. ordinals **1–365 stay 365/365**;
  2. ordinal 366 **still** reds at `UncutFaceComponentOrbitSeedNotUnique` — any movement falsifies BV7;
  3. the failure publishes **`seedState`**, so zero-versus-multiple is finally decided;
  4. the failing component's face count, bounded membership and bounded boundary-edge rows are retained, including
     every skip reason;
  5. the component census is present and its truncation flags are false, or the truncation is explicit;
  6. carried surfaces **368, 369, 370, 374** and the 367/371/372 co-reachers are unchanged.

The successor after TB20 is an independent **`M3-CP4c-3-TB20-REV`**, which owns the correction once `seedState` is
known. **One diagnostic turn only:** TB20 must supply the discriminator, and the review after it is expected to
authorize a product correction rather than a further observation turn.

---

## 11. What a successor must not reopen

- **CB21's correction is runtime-proved** and must not be reverted; `M3-CP4c3-TB17-CAND-01` stays closed.
- **The reported `sourceFace` of `UncutFaceComponentOrbitSeedNotUnique` is an iteration artifact** (§2), and the
  torus stop of the same name is a **different mechanism** (§3). Do not merge them.
- **A universal non-crossing invariant is refuted** (§4); `localFragmentCount` must not become a fatal oracle
  without the crossing derivation and a crossing witness.
- **371/372 stay coupled** until the standing trigger in §5 fires.
- The face walk is a validated total permutation; shared orbit ownership by two sides of one arc is legitimate
  topology. BS9-5 remains retired.
- Accepted ordinals **1–365** remain the load-bearing boundary. Any change those identities exercise must
  demonstrate safety, not argue it.
