# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-04** at `M3-CP4c-3-TB26-INDEPENDENT-REVIEW` closeout.

---

## 1. Where the checkpoint stands

**TB26-R1 is the latest semantic runtime authority:** **397 PASS / 8 RED**, accepted **365/365**, on package `9957324848` / source `e045bf7147afc02bd90eff4822e4b609edbaba66` / selector405. Result artifact `9958722468`; run/job `33931380325 / 101210520053`. CP4c-3 remains OPEN. Stable accounting **44 / 14 / 30**, debt **5**, packages **91**.

389/390 recovered to PASS; 404/405 PASS. Remaining RED: `366,367,368,369,370,374,393,398`.

## 2. Current frontier — the discriminator is measured, unreadable, and computed on the wrong object

**What worked.** CJ7's restored seed rule returns component 0's `[0,1,3]` — identical to the pre-CB27 rule — and
the plan **fails closed without choosing a winner**. CJ8 recovered **389 and 390**; 390 publishes
`certifiedOwnerCount=3` without asserting a winner. CJ9's 404/405 PASS. **398 is untouched.**

**The separating-arc horn is NOT selected.** CJ6 defined the horn as a *separating* arc, and an arc separates iff
its two darts lie in **different** face-walk orbits. `interiorArcs=4` is an incidence count. The deciding fields —
`forwardOrbit`/`reverseOrbit` per row, and the 46 seed attributions with their `rule` — are **computed and stored**
(`SurfaceCutGraph.h:138–170`, `SurfaceCutGraph.cpp:689–708`) and serialized only as counts. TB26-R1's own §3 admits
it cannot name the four arcs; a horn nobody can name is not selected.

**The census describes a different object than the failure.** Two partitions exist — the plan's over
`unlabeledFaces` with `mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges` (`GlobalTopologyPlan.cpp:1103–1115`) and the
certifier's over `uncutFaces` with a narrower barrier set (`SurfaceCutGraph.cpp:596–601`). An arc-incident face is
in the second and not the first, **by construction**. The RED is raised on the plan's partition; every CJ6 census
is computed on the certifier's, and nothing published establishes that their component 0s are the same faces.
**Until that correspondence exists, no CJ6 number is admissible about the failing component.**

**76 versus 97 is that lawful domain difference**, not 21 omitted rows — and it is itself evidence for the finding
above.

**Static argument, to be tested by printing one integer pair per row.** A trace arc reaches an uncut component's
interior **only** through a terminal-slit segment; that arc ends at a degree-1 free end, so it is a **bridge**, and
both darts of a bridge share an orbit — the case DEFN-R3.4 already measured (arc 15,
`forwardOrbit = reverseOrbit = 0`). **Predicted: all four rows are bridges, the horn is refuted, and the two
minority seeds among 81/1/1 are attribution errors the unprinted rows already name.**

## 3. Exact next turn — `M3-CP4c-3-CB31`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`, under **CK8–CK9** of
`Architecture_M3_CP4c3_TB26_Independent_Review_Record.md`.

- **CK8 — print what CB30 already measured.** One line per census row for the failing component, untruncated:
  interior arcs with **both dart orbits**; seed attributions with edge, both faces, orbit and **rule**; boundary
  edges with barrier class and side-owner presence; vertex transits. Plus the component's face count and a stable
  face-set digest. Ordinal **404** strengthened in place to require untruncated rows and both orbit fields.
  Ordinal **393**'s assertion replaced in place by **coverage of distinct source faces**, never a row count.
  Selector 405 unchanged.
- **CK9 — establish which partition the census describes.** Both sides publish their partition identity (domain
  rule and barrier composition) and face-set digest, and the failure locus states **whether they match**. One
  gating identity at selector **406** with 405 as its exact prefix, asserting **publication of the correspondence,
  not equality**.

**CB31 corrects no product behaviour.** No barrier added or removed, no attribution rule changed, no seed winner
chosen, no partition unified, no `terminalSlit` handling altered.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB26-REV-CAND-01` | **UPHELD / ACTIVE / GATING / EVIDENCE SURFACE** — the deciding census fields are computed and stored but serialized as counts. Owner: CK8. |
| `M3-CP4c3-TB26-REV-CAND-02` | **RESOLVED / LAWFUL DOMAIN DIFFERENCE** — 76 and 97 are boundaries of two different partitions; no row was omitted. |
| `M3-CP4c3-TB26-REV-CAND-03` | **UPHELD / ACTIVE / TEST AUTHORITY** — ordinal 393 asserts one observation per face against deliberate multi-owner publication. Owner: CK8. |
| `M3-CP4c3-TB26-REV-CAND-04` | **NEW / ACTIVE / GATING / ARCHITECTURAL** — the censuses are computed on the certifier's partition; the RED is raised on the plan's. Owner: CK9. |
| `M3-CP4c3-TB25-REV-CAND-02` | **ACTIVE / GATING / UNDECIDED** — *is the failing component contained in a single certified face?* TB26 did not decide it. Owner: CK8/CK9. |
| `M3-CP4c3-DEFN-R3-CAND-01` | **PROMOTED to GATING** — the duplicated construction has produced two partitions, and the diagnostic runs on the one that does not fail. Owner: CK9. |
| `M3-CP4c3-TB24-REV-CAND-02` | **ACTIVE / ARCHITECTURAL** — ownership of non-arc-incident faces is a derivation, not a read. |
| `M3-CP4c3-TB22-REV-CAND-01` | **ACTIVE / EVIDENCE INTEGRITY** — 393's contract is still not exercised as intended. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED**; `localFragmentCount` stays non-fatal. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared input-size bound. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **There is still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — ordinal 370. **No correction authorized.** |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; separate owner. |

**Closed at this review, runtime-proved:** `M3-CP4c3-TB25-REV-CAND-01` (starved seed rule — restored, reproduces
`[0,1,3]`), `M3-CP4c3-TB25-REV-CAND-03` (389/390 foreign assertions — both PASS). **Previously closed:**
`M3-CP4c3-TB21-CAND-01` (ill-formed), `M3-CP4c3-TB19-CAND-01`, `M3-CP4c3-TB24-REV-CAND-01`,
`M3-CP4c3-TB25-ORCH-01`, `M3-CP4c3-TB23-REV-CAND-01/02`, `M3-CP4c3-TB23-R1-REV-CAND-01`,
`M3-CP4c3-TB21-CAND-02`, `M3-CP4c3-TB10-REV-CAND-01`, `M3-CP4c3-TB19-REV-CAND-02`, `M3-CP4c3-TB17-CAND-01`.

---

## 5. Settled facts a successor must not reopen

- **`projectionFaithfulnessResidual = 0` is a structural zero** — the predicate is unsatisfiable by construction.
  It never ruled anything out and must not be cited as evidence.
- **The minority rows' certificate-face columns are the seed value re-printed.** Their agreement is a tautology.
- **Both branches of `M3-CP4c3-TB21-CAND-01` are REFUTED, and the question is closed as ill-formed.** Do not re-pose it. The successor question is whether component 0 lies in a single certified face — asked about the object, not about a rule.
- **The mechanical actual embedded complex is cellular** — `22 − 26 + 6 − 2 = 0`, all faces certified discs.
- **Part I §3 is an implication with a premise**; it says nothing about the source-face projection.
- **The certificate and the seed guard test different objects**; neither validates the other.
- **CB21 is not reverted**; only the formal Parts IV/V gap remains, owned by a DEFN turn.
- **371/372 and ordinal 391 are closed**; the atlas accessor is test-only and never product authority.
- **A universal chord non-crossing invariant is refuted**; `localFragmentCount` must not become a fatal oracle.
- The face walk is a validated total permutation; shared orbit ownership by the two sides of one arc is legitimate
  topology. **BS9-5 remains retired.**
- Identical typed error names across witnesses do not establish identical root cause.
- **Accepted ordinals 1–365** are the load-bearing boundary. A correction that changes any behaviour those
  identities exercise must demonstrate safety, not argue it.
- **A diagnostic gated on the success of the thing it diagnoses can never fire on the case it was built for.**
  D3 proved this at a cost of one full turn.
- **Relocating a derivation adds no information.** CB27 moved ownership into the certifier — the right authority —
  and got `[0,1,3]` at `(0,1,2)`, the same answer as before.
- **384/385 recovered at TB25-R1; 389/390 recovered at TB26-R1 after their contracts were narrowed to identity-owned evidence.** No accepted behaviour was lost.
- **An incidence count is not a separation.** `interiorArcs=4` says four arcs touch the component; it says nothing
  about whether any of them separates certified faces. Only the per-arc dart-orbit pair does.
- **There are two partitions, not one.** The plan's is over faces with no fragment orbits; the certifier's is over
  faces not crossed by a trace. Never quote a number from one as evidence about the other.
- **A census over established values is vacuous where nothing is established.** CH8's `rowCount=0` proved this at a cost of one turn.
- **Only arcs separate certified faces.** An uncut component whose interior no arc meets lies in exactly one certified face. This is a proof, not a measurement.
- 368/369/370/374 are unchanged carried surfaces with separate owners. Vertex 30 and finalize/contact remain
  separate and untouched.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load only the minimum current authority:

1. `ORIENTATION.md` — read first.
2. **this file** — current frontier and candidate ownership.
3. `Architecture_M3_CP4c3_TB26_Independent_Review_Record.md` — **CK0–CK9**, the adjudication and the frozen CB31 scope.
4. `Architecture_M3_CP4c3_TB26_R1_Artifact_Only_Test_Benchmark_Report.md` — current semantic runtime authority and package provenance.
5. `M3_CP4c_Frozen_Definitions.md`, `Regression_Root_Cause_Tracker.md`, `Required_Green_Selector_Manifest.md`.
6. `M3_CP4c_Consolidated_Record.md` — folded-document resolver.

Exact next is `M3-CP4c-3-CB31` under CK8–CK9. **CB31 prints what CB30 already measured and publishes the partition
identity on both sides; it corrects no product behaviour.**
