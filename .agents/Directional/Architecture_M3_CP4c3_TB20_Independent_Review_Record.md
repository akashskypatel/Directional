# M3 CP4c-3 TB20 — Independent Review + Plan Record

Date: 2026-09-03 UTC
Turn: `M3-CP4c-3-TB20-REV`
Type: **independent REVIEW + PLAN — STATIC ONLY**
Status: **COMPLETE / BRANCH CONFIRMED `Multiple` / NO CORRECTION AUTHORIZED AT THE GUARD / NORMATIVE AUTHORITY ALREADY ADJUDICATES IT / ARCHITECTURAL CLASS EXTENDED TO GENUS 0 / 371–372 DECOUPLING AUTHORIZED / NON-STABLE**

No Directional runtime, configure, compile, link, package, benchmark, or product/test/fixture/selector mutation
occurred in this turn. Measures discharged: **CW0–CW9** per
`Architecture_M3_CP4c3_TB20_Independent_Review_Plan.md`. Successor frozen: exactly one —
**`M3-CP4c-3-CB23`** under **BW0–BW9**.

**The headline finding is that there is nothing to fix at the failing line.** Normative authority already
adjudicated this exact guard, on this exact code line, and ruled it correct. What it detects is a *missing input*,
and CP4c-3 has now reproduced that condition on a **genus-0** witness for the first time.

---

## 1. CW0 — authority and immutability

| Check | Result |
|---|---|
| Semantic source `c5d3c65936e14e1c3e2c8afcffbc4236f37aa131` exists | **PASS** — `build: initialize uncut boundary diagnostic source edge`, 2026-09-03 21:00:30 +0000 |
| Source is an ancestor of branch HEAD | **PASS** |
| No code drift `source..HEAD` | **PASS** — static review of the working tree is valid evidence about the package |
| Selector file hash `164a8b25118a4d00fc9261e4645795ad396130b6d6ea4dd8784158b76e1d0fca` | **PASS** |
| Selector 384 is an exact prefix | **PASS**, prefix digest `c9425b93…632a05564` |
| Accepted 365-prefix authority | **PASS** — `6b5b6555…cfc14b8a1`, unchanged |
| Appended identities | **PASS** — exactly the four CB22 witnesses, ordinals 385–388, no reordering |
| Ledger arithmetic | **PASS** — 380 PASS + 8 RED = 388 |
| Pre/post package byte+mode census | **IDENTICAL**, `f0b1beec…dab653c5b0` |
| Execution boundary | **PASS** — no configure, compile, relink, package repair, mode repair, generated discovery, or source/test/fixture/selector mutation |

**One convention break, recorded because reviewers and tooling depend on it.** Every selector file from 357
through 384 is named by its **identity count**. `Architecture_M3_CP4c3_Required_Green_Selector_385.txt` holds
**388** identities. Nothing semantic is wrong — the file's hash, its 384-prefix relation and its accepted-365
prefix all verify, and TB20's authority chain pins the bytes — but `name == count` no longer holds, and
`selector_probe.py` now reports a mismatch on it.

**The cause is my own prior turn's wording.** BV6 said "append **selector 385** with only those identities" while
BV1–BV5 required four separable witnesses; CB22 correctly produced four and correctly kept the frozen name. The
file must **not** be renamed — it is byte-frozen and hash-pinned in TB20's authority. BW6 below fixes the wording
going forward, and §10 records the exception so no successor re-derives a count from a filename.

**No rerun is authorized by this review.**

---

## 2. CW1 — the discriminator, verified independently of name and locus

Ordinal 366 still terminates at `UncutFaceComponentOrbitSeedNotUnique`, and CB22's retained production evidence
states, without inference from the error name or the source-face locus:

| Field | Value |
|---|---|
| `uncutFaceComponent` | **0** |
| `uncutFaceComponentSeedCount` | **3** |
| `uncutFaceComponentSeedState` | **`Multiple`** |
| `sourceFaceLocusKind` | **`FirstUnlabeledFaceInIterationOrder`** |
| component census row | `component=0, faceCount=191, seedCount=3, seedState=Multiple, seedOrbitCount=3, seedOrbitsTruncated=false, seedOrbits=[0,1,3]` |
| global component census | **9** rows, not truncated |

**TB19-REV's two predictions are both confirmed.** The branch is `Multiple`, not `None` — which is the outcome
TB19-REV's partial static argument favoured — and `sourceFaceLocusKind` now types the locus explicitly as an
iteration artifact, discharging `M3-CP4c3-TB19-REV-CAND-02`.

Arithmetic on the retained boundary window closes exactly: 46 `none`-class rows contributed 46 seeds
(44 × orbit 0, 1 × orbit 1, 1 × orbit 3) and 18 `traceTouched` rows contributed none, totalling the 64 retained
rows. Owner counts split 47 × 1 and 17 × 2. All 64 rows have `otherSideLabeled=true`.

---

## 3. CW2 — normative authority already adjudicates this guard, and rules it correct

CW2 requires that a corrective plan "explain why the desired component must have exactly one semantic seed, **or
revise that requirement from normative authority rather than from a failing test**." The normative authority
exists, it is directly on point, and it answers **against** a correction.

`M3_CP4c_Frozen_Definitions.md` **Part I §3** (M3-CP4c-2 DEFN), on this exact construction and this exact line:

> "…unions untouched faces across edges that are neither mandatory nor trace-touched, then requires each resulting
> component to receive **exactly one** orbit seed from its labeled neighbours. A cylindrical component touches
> labeled faces on both of its boundary circles, collects two distinct seeds, and fails … with
> `UncutFaceComponentOrbitSeedNotUnique`. **The error code is correct and the producer is behaving correctly.
> There is no bug at that line.** It is reporting a missing input."

The missing input is named in the same section: **the network is not a cut graph of the surface.** A component of
the barrier complement that collects two or more distinct seeds is a component that is not contained in one graph
face — it is an annulus or worse, so the complement is not a disjoint union of discs and the embedding is not
cellular.

**Both Part IV (CP4c-3 DEFN) and Part V (CP4c-3 DEFN-R1) additionally prohibit relaxing it**, in their prohibited
lists: *"relaxing `proves_cellularity()`, the fragment-count invariant, `UncutFaceComponentOrbitSeedNotUnique`"* and
*"Weakening `proves_cellularity()`, the fragment-count invariant, or `UncutFaceComponentOrbitSeedNotUnique`."*
Part VI (DEFN-R2) is scoped to vertex-star continuation and does not restate or lift them, so they stand.

### Consequence: what orbits 0, 1 and 3 represent

They are three distinct graph faces of the embedded network that a single 191-face connected component of the
barrier complement touches. Under the normative frame that is not three legitimate seeds fighting over one
component — it is **one component spanning three regions**, which is the definition of a non-cellular complement.
The 44-to-1-to-1 distribution is consistent with a large region-interior that leaks into two others at two places,
and no seeding rule can repair it because there is no correct single answer to give.

### The finding this review must escalate: CB21 relaxed a sibling of this guard

The same two prohibited lists name **the fragment-count invariant** alongside this one. `M3-CP4c-3-CB21` made that
invariant's low side non-fatal, on my authorization at TB18-REV. I record plainly that **TB18-REV did not consult
the frozen definitions' prohibited lists before authorizing it.**

TB18-REV's mathematics was not wrong — `|owners| = k+1` genuinely is not a universal invariant, and the
accepted-boundary safety proof holds. But the interpretation was incomplete. Under Part I's frame, the shared
global owner TB18 measured (`arc 15`, `forwardOrbit = reverseOrbit = 0`) is *itself* a non-cut-graph symptom, so
the fragment-count mismatch was reporting the same missing input this guard now reports. **CB21 did not fix a
defect; it suppressed one detector, and the pipeline advanced to the next detector of the same condition.** That
is exactly what the evidence shows: ordinal 366 moved from one guard to another while the underlying condition
never changed.

CW5 binds this review to preserve CB21's behaviour and the successor does so. The conflict is **not** resolved
here — it is a definition-level question, and §10 routes it to the turn that owns definitions rather than
resolving it inside a review.

---

## 4. CW3 — zero-seed and multiple-seed remain separate candidates, and are now one architectural class

Re-proved, as CW3 requires:

| | Torus (`M3-CP4c-1-TB-R2`) | Mechanical (TB20) |
|---|---|---|
| Producer state | **0 traces / 0 events**, 48 mandatory edges, 48 structural nodes | 12 traces, 26 trace arcs, 70 cut faces |
| Branch | **zero seeds** — no face has a chord label, so no edge can have a labeled side | **three seeds** — `[0,1,3]`, `seedOrbitsTruncated=false` |
| Genus / χ | g = 1, **χ = 0** | closed, **χ = 2** (152 − 450 + 300) |
| Proof available | Part I §3's Euler argument: `E = V = 48 ⇒ F = 0`, contradiction | not yet measured — see §5 |

The candidates are **not merged**: different branches, different producer states, different proofs. They are now
formally linked as **two instances of one architectural class — the field-aligned network is not a cut graph of
its surface.**

**The genuinely new information in CP4c-3 is that this class is not confined to genus ≥ 1.** Part I's theorem
turns on `χ = 0` and "no disjoint union of closed curves can be a cut graph of the torus." The mechanical witness
is a closed genus-0 surface where that particular argument does not apply, and it exhibits the same class anyway.
Whatever produces it here is a different route to the same missing input, and it is not addressed by any existing
finding.

---

## 5. CW4 — the bounded evidence is sufficient for this decision, and the one missing datum is two integers

**The 33 unretained boundary rows are not the blocker, and no further boundary retention is warranted.** The
deciding quantity is already exact and explicitly untruncated: `seedOrbitCount = 3`,
`seedOrbitsTruncated = false`. Additional boundary rows could only ever add orbits to the set, never remove one, so
they cannot change `Multiple` and cannot change the disposition in §3. The absent `edgeOrbitEvidenceNotUnique` row
is likewise not load-bearing: ordinal 386 proves the projection preserves that reason when present, and its
presence or absence would affect only how *completely* the component was seeded, not the fact that three distinct
orbits seeded it.

**What is missing is a different quantity entirely, and it is very small.** Part I settled the torus by arithmetic,
not by more rows. For a graph embedded in a closed surface, the embedding is cellular exactly when

```
V − E + F = χ(S)
```

per connected component of the graph. TB19's census gives `F = 6` face-walk orbits and `26` arcs — but that arc
count is the *fragment-owner* census over trace arcs, and the embedded graph also carries cut-graph arcs, so it is
not necessarily the graph's `E`. **The embedded graph's own `V`, `E` and connected-component count are not
retained anywhere.**

With them, cellularity for the mechanical witness is decided by the same one-line arithmetic that decided the
torus. That is the smallest possible evidence contract for this question — a handful of integers — and it is
categorically cheaper than more boundary rows while being the only evidence that can close the architectural
question rather than the symptom.

**Verdict:** one minimal additional evidence contract is genuinely unavoidable, it is **not** boundary retention,
and it is specified in BW1–BW3.

---

## 6. CW5 — accepted authority and settled CB21 behaviour preserved

The successor preserves, without exception:

- accepted ordinals **1–365** and selector immutability;
- **CB21's non-fatal low-side fragment-owner deficit behaviour** and high-side owner-overcount fatality — flagged
  in §3 but **not** reverted here;
- the settled fact that `localFragmentCount = k + 1` is not universal when interior chord crossings exist
  (`M3-CP4c3-TB18-REV-CAND-01`), and that `localFragmentCount` stays **non-fatal**;
- `UncutFaceComponentOrbitSeedNotUnique` itself — **not relaxed, not weakened, not special-cased**, per Parts IV
  and V.

---

## 7. CW6 — the 371/372 standing trigger has fired; the decoupling is AUTHORIZED

TB19 and TB20 are two consecutive TB turns with ordinals 371 and 372 stopped at the same downstream mechanical
production frontier. The factual condition recorded in `M3-CP4c3-TB10-REV-CAND-01` is met, and the reasoning that
justified deferring it has now inverted: §3 shows the production frontier is **not** about to clear — it is an
architectural condition needing a definition-level decision, so 371/372 would otherwise stay unmeasured across an
architectural turn as well.

**Authorized:** the previously specified **test-only atlas-scoped accessor**, under strict conditions carried into
BW7–BW8:

- both identities' **assertions stay byte-unchanged**; only the fixture accessor they consume changes;
- **selector membership and ordering are unchanged** — 371 and 372 keep their ordinals;
- **no product source is touched** by this change;
- the shared `cp4c_mechanical_fixture()` constructor keeps its existing all-products contract for every other
  consumer; the accessor is additive.

This is combined with a **diagnostic-only** successor, so CW6's prohibition on combining test-coupling cleanup
with an unrelated *product correction* is not engaged — CB23 contains no product correction. The two changes are
independently revertible and are separately witnessed.

---

## 8. CW7 — carried reds separately owned

Reconfirmed unchanged, each under its established owner, and explicitly not broadened into the component-seed
successor:

- **368** — `CellularityNotEstablished` originating `RotationSystemInconsistent / TraceEventPositionInvalid`,
  trace 2 / event 30, `NoCarrierMatch / SourceEdgeUnavailable`. `M3-CP4c2-TB-X2-CAND-04`.
- **369** — saturation used where the witness expects none. `M3-CP4c2-TB-X2-R10-CAND-01`.
- **370** — typed error object `<04>` instead of `<06>`, no source-face locus. `M3-CP4c2-TB-X2-R8-CAND-02`.
  **No correction authorized.**
- **374** — folded-cone `atlasBuild=false`. `M3-CP4c3-TB7-CAND-02`. **No atlas invariant may be weakened for it.**

**Vertex 30 is still not reached**, and the finalize/contact fall-through remains untouched under its own owner.

---

## 9. CW8 — candidates and accounting

| Candidate | Transition |
|---|---|
| `M3-CP4c3-TB19-CAND-01` | **ACTIVE / GATING → RECLASSIFIED ARCHITECTURAL.** Branch is `Multiple`, component 0, seed count 3, orbits `[0,1,3]`. Per Part I §3 the guard is correct and there is **no defect at the line**; the owner is the missing cut graph, not the seeding block. Renamed in substance to a *symptom* record; the owning class is `M3-CP4c3-TB20-REV-CAND-01`. |
| `M3-CP4c3-TB20-REV-CAND-01` | **NEW / ACTIVE / ARCHITECTURAL / GATING** — *the field-aligned network is not a cut graph of its surface, on a **genus-0** witness.* Second instance of the class Part I proved for the torus, by a route Part I's genus-1 argument does not cover. Owner: BW1–BW3 evidence, then a definition-level turn. |
| `M3-CP4c3-TB20-REV-CAND-02` | **NEW / ACTIVE / GOVERNANCE** — CB21 weakened the fragment-count invariant, which Parts IV and V prohibit; TB18-REV authorized it without consulting those lists. Not reverted here (CW5). Owner: the definition-level turn, which must either lift the prohibition with reasons or restore the invariant with an accepted-boundary argument. |
| `M3-CP4c3-TB19-REV-CAND-02` | **CLOSED / SATISFIED.** CB22 retained the discriminator and `sourceFaceLocusKind`; TB20 runtime-proved both. |
| `M3-CP4c3-TB10-REV-CAND-01` | **TRIGGER FIRED / DECOUPLING AUTHORIZED** under BW7–BW8, test-only, assertions and selector membership unchanged. Closes when TB21 measures 371/372's own contracts. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED**, unchanged. `localFragmentCount` stays non-fatal. |
| `M3-CP4c3-TB7-CAND-02`, `M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`, `M3-CP4c2-TB-X2-CAND-04`, `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, finalize/contact | **ACTIVE**, unchanged, §8. |
| `M3-CP4c3-TB17-CAND-01` | **CLOSED**, unchanged. |
| Historical torus occurrence | **NOT merged**; linked to `M3-CP4c3-TB20-REV-CAND-01` as the genus-1 instance of the same class. |

**Accounting.** Static turn on an unaccepted surface; no accepted-green loss; the red ordinal set is unchanged.
**+0 events / +0 recurrences.** Totals remain **44 events / 14 categories / 30 recurrences**; produced-witness debt
**5**; semantic M3 package count **85**. Accepted authority remains **365/365**. CP4c-3 remains **OPEN**.

### Lessons recorded

- **103.** *Check the frozen definitions' prohibited list before authorizing a correction, not after.* TB18-REV
  proved a real mathematical fact about the fragment-count invariant and authorized relaxing it; two frozen
  definition revisions explicitly prohibit relaxing that invariant, and a third section explains why — the guard
  detects a missing input rather than asserting a theorem. Correct mathematics about a check says nothing about
  whether the check is load-bearing.
- **104.** *When a frontier "advances" without the underlying condition changing, the previous turn removed a
  detector rather than a defect.* Ordinal 366 moved from `TraceCutFaceFragmentCountMismatch` to
  `UncutFaceComponentOrbitSeedNotUnique`; both are downstream detectors of the same missing cut graph. Frontier
  movement is progress only when the thing being detected changed.
- **105.** *An architectural theorem proved on one witness bounds its own scope.* Part I's torus proof turns on
  `χ = 0` and on cycles having `E = V`; it does not cover a closed genus-0 surface. The mechanical witness reaches
  the same conclusion by a route the theorem does not describe, and that is new information, not a repetition.

---

## 10. CW9 — frozen successor: `M3-CP4c-3-CB23`, Code + Build, `BW0–BW9`

**Diagnostic-only on the product, plus the CW6-authorized test-only decoupling.** No product semantics change.

This is not "another diagnostic turn for convenience": CB22 measured *seeding*, and BW measures *cellularity* — a
different quantity, by the same arithmetic that settled the torus, and the only evidence that can close the
architectural question rather than its symptom.

- **BW0** — accepted 365 untouched; the current selector file byte-frozen at
  `164a8b25…6e1d0fca` and republished unchanged; the eight standard compile targets with **mandatory GMP/GMPXX
  linkage**; no runtime; no acceptance claimed.
- **BW1** — publish the **embedded graph's own Euler census** on the production path: node count `V`, arc count
  `E`, face-walk orbit count `F`, and the number of connected components of the embedded graph. These are the
  graph's counts, **not** the fragment-owner census's trace-arc subset.
- **BW2** — publish `χ(S)` as the product computes it and the per-component residual `V − E + F − χ`, so
  cellularity is decided by arithmetic rather than by inference, exactly as Part I §3 decided the torus.
- **BW3** — for the failing component, publish which graph faces (orbit ids) its boundary touches and the count of
  boundary edges contributing each — the per-orbit attribution the aggregate rows currently lack. Bounded, with an
  explicit truncation marker. **No increase in boundary-row retention** (§5).
- **BW4** — carry the same census into the torus and prescribed-sphere paths so the class can be compared across
  witnesses without a new turn.
- **BW5** — one witness per new field through the **production** path, plus a byte-identical regression witness
  for an unrelated error's projection.
- **BW6** — append the next selector **named by its resulting identity count**, not by a predicted number, and
  restate that convention in the plan. The current file keeps its frozen name and bytes; §1 records the exception.
- **BW7** — **the test-only 371/372 decoupling**: add the atlas-scoped accessor, leave both identities' assertions
  **byte-unchanged**, leave selector membership and ordering unchanged, touch **no product source**, and keep the
  existing all-products fixture contract intact for every other consumer.
- **BW8** — **no product semantic change whatsoever**: `UncutFaceComponentOrbitSeedNotUnique` and its predicate,
  `componentBarriers`, the component partition, `seedOrbits`, `edgeOrbitEvidence`, `add_fragment_orbit`, the
  `exteriorOrbits` filter, `is_terminal_slit`, the face walk, the rotation system, region drafts, CB21's
  comparison and `proves_cellularity()` are all untouched; `localFragmentCount` stays non-fatal. No fixture
  geometry mutation, tolerance, float-derived decision or accepted-boundary relaxation. No sphere / saturation /
  ordinal-370 / folded-cone / vertex-30 / finalize-contact work.
- **BW9** — six `M3-CP4c-3-TB21` discriminators:
  1. ordinals **1–365 stay 365/365**;
  2. ordinal 366 **still** reds at `UncutFaceComponentOrbitSeedNotUnique` with `seedState=Multiple`, component 0,
     seed orbits `[0,1,3]` — any movement falsifies BW8;
  3. the mechanical embedded graph's `V`, `E`, `F`, component count and `V − E + F − χ` residual are published, so
     **cellularity is decided**;
  4. the failing component's per-orbit boundary attribution is published;
  5. **371 and 372 execute their own assertions for the first time** and report their real result, whatever it is —
     a red there is new information, not a regression;
  6. carried surfaces **368, 369, 370, 374** and co-reacher 367 are unchanged.

### The turn after TB21 is expected to be a definition turn, not a Code + Build turn

If BW2's residual confirms non-cellularity, CP4c-3's contract needs revising rather than patching: the producer
must be required to **construct** a cut graph, which is a definition-level decision Part I already framed for the
torus and which no review or CB turn may make on its own. `M3-CP4c3-TB20-REV-CAND-02` — CB21's weakening of a
prohibited invariant — belongs to that same turn. **Under the project's workflow, `DEFN` absorbs `REVIEW + PLAN`,
so that turn is the review of TB21.**

---

## 11. What a successor must not reopen

- **Part I §3 is normative and directly on point:** the seed-uniqueness guard is correct, the producer is behaving
  correctly, there is no bug at that line, and multiple seeds report a **missing input**.
- **Parts IV and V prohibit relaxing** `proves_cellularity()`, the fragment-count invariant, and
  `UncutFaceComponentOrbitSeedNotUnique`. Part VI is scoped to vertex-star continuation and lifts none of them.
- **The torus and mechanical occurrences are separate candidates**, linked as one architectural class; the
  genus-1 proof does not cover the genus-0 witness.
- **The `sourceFace` locus is an iteration artifact**, now explicitly typed as such by CB22.
- **CB21 is preserved by this review's successor** but its authorization is formally in question under
  `M3-CP4c3-TB20-REV-CAND-02`; only the definition-level turn may resolve it.
- Accepted ordinals **1–365** remain the load-bearing boundary. Any change those identities exercise must
  demonstrate safety, not argue it.
