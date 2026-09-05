# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-05** at `M3-CP4c-3-TB27-INDEPENDENT-REVIEW` closeout.

---

## 1. Where the checkpoint stands

**TB27-R1 is the latest semantic runtime authority:** **399 PASS / 7 RED**, accepted **365/365**, on immutable CB31
package `9961564041` / source `eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc` / selector406. Formal run/job
`33946094875 / 101252363079`; result/log artifacts `9963419649 / 9963419830`; ledger SHA-256
`8da2002701437c5d0c4a57d613e24195f4f690d1ae4494da1234d58bb9a24da5`.

RED ordinals are `[366,367,368,369,370,374,398]`. Ordinal 393 recovered to PASS under the repaired distinct-face
coverage contract; 404 and 406 PASS. Accepted 1–365 is unchanged and 398 remains the strong ownership-totality gate.

CB31 remains the current compile/package authority: package SHA-256
`ca1b69de319fba92e0c6accc580e698f2430505eb811e821c03d44e6629263cf`, compile run/job
`33940038189 / 101235542774`. Semantic M3 package count remains **92**. CP4c-3 remains OPEN. Stable accounting stays
**44 / 14 / 30**, debt **5**.

## 2. Current frontier — runtime proves two different partition objects

TB27 makes the CK8–CK9 publication surfaces semantic evidence.

Ordinal 404's certifier census is component 0 with **214 faces**, domain `NotTraceCut`, face-set digest
`7937364815223192706`, and complete 76 boundary / 4 interior-arc / 53 vertex-transit / 46 seed-attribution rows.
The four trace-arc orbit pairs are 14 `0/1`, 20 `0/0`, 22 `0/3`, 24 `0/0`: **two separating, two equal**. That
refutes the prior static prediction that all four certifier arcs would be bridges.

Ordinal 406 simultaneously proves this census is **not the failing plan component**. The failure object is component
0 of domain `EmptyFragmentOrbits`, face-set digest `17919102493633069558`, and the publication states
`matchesFailingComponent=false`. Thus the 214-face certifier census and 191-face plan failure are different runtime
objects. The two separating certifier arcs cannot be used as evidence about the failing plan partition.

Ordinal 393 PASSes while continuing to publish `componentFaceCount=191;certifiedOwners=0:191,1:191,3:191;
allEqual=false`; the contract repair removed a false arity rejection without choosing an owner.

## 3. Exact next turn — `M3-CP4c-3-CB32`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`, under **CL6–CL9** of
`Architecture_M3_CP4c3_TB27_Independent_Review_Record.md`.

**The frontier reduces to one unmeasured fact:** which source faces do arcs 14/20/22/24 cross, and which component
of each partition contains them?

- **CL6 — the arc-locus census.** Every interior-arc row gains the arc's **crossed source faces** untruncated, each
  face's component id in **both** partitions, and the **typed reason** the face is not trace-cut (`TerminalSlit` /
  `SegmentRangeInvalid` / `TraceNotFound` / `DartOutOfRange` / `FaceNotFound` / `Other`). The same three fields are
  published for the **failing plan component's** interior arcs, so the question is answered about the object that
  fails. Falsification stated first: a separating arc inside the failing component selects the **barrier-set**
  correction with the arc named; its absence selects the **attribution-rule** correction with the edges already
  named among 46 rows; a failing component that is not a subset of the certifier's refutes the static containment
  argument.
- **CL7 — publish the subset relation** alongside the already-refuted equality boolean. **No partition is
  unified**; that is a definition decision owned by `M3-CP4c3-DEFN-R3-CAND-01`.
- **CL9 — selector 407** with 406 as an exact 406-line prefix; one gating publication/completeness identity.
  Ordinal 404 strengthened in place.

**CL8 — HARD STOP RULE.** CB32 is the **last diagnostic turn authorized on source-face ownership**. The review that
reads TB28 **must freeze a product correction** whichever branch CL6 measures; both are pre-named and the outcomes
are exhaustive, so "insufficient evidence" is not an available finding. **If CL6 returns ambiguous, the default is
the barrier-set branch: an arc whose two darts lie in different face-walk orbits must induce a barrier.**

**CB32 corrects no product behaviour** — no barrier added or removed, no attribution rule changed, no seed winner
chosen, no partition unified, no `terminalSlit` handling altered.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB27-REV-CAND-01` | **NEW / ACTIVE / GATING / PRODUCT** — the certifier's 214-face component contains two separating arcs, so that partition **merges faces lying in different certified faces**; any owner propagated across it would be unsound, masked only because the component has no unique seed. Owner: CL6, then the TB28 review. |
| `M3-CP4c3-TB26-REV-CAND-02` | **RESOLVED / LAWFUL DOMAIN DIFFERENCE** — 76 and 97 belong to different partitions; TB27 additionally exposes 214-vs-191 faces and distinct digests. |
| `M3-CP4c3-TB27-REV-CAND-02` | **NEW / ACTIVE / ARCHITECTURAL / NON-GATING** — the plan excludes from its component domain exactly the faces carrying a direct certified read (`GlobalTopologyPlan.cpp:702`, `:750`), then fails to seed that component. Owner: CL7. |
| `M3-CP4c3-TB26-REV-CAND-04` | **RUNTIME-PROVED / GATING / ARCHITECTURAL** — ordinal406 reports `matchesFailingComponent=false`; census and failure partitions differ. |
| `M3-CP4c3-TB25-REV-CAND-02` | **ACTIVE / GATING / UNDECIDED FOR THE FAILING OBJECT** — the certifier component contains two separating arcs, but it is not the 191-face failing plan component. Owner: CL6, and **CL8 forbids it staying open past TB28**. |
| `M3-CP4c3-DEFN-R3-CAND-01` | **RUNTIME-PROVED / GATING / ARCHITECTURAL** — duplicated constructions yield different partition objects on the witness; diagnostic census runs on the non-failing one. |
| `M3-CP4c3-TB24-REV-CAND-02` | **ACTIVE / ARCHITECTURAL** — ownership of non-arc-incident faces is a derivation, not a read. |
| `M3-CP4c3-TB22-REV-CAND-01` | **ACTIVE / EVIDENCE INTEGRITY** — earlier vacuous diagnostic surfaces remain historical architectural debt; ordinal393's current contract itself is runtime-proved. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED**; `localFragmentCount` stays non-fatal. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared input-size bound. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **There is still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — ordinal 370. **No correction authorized.** |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; separate owner. |

**Closed at TB27-REV, runtime-proved:** `M3-CP4c3-TB26-REV-CAND-01` (all four rows published with both dart
orbits, untruncated, digest validated) and `M3-CP4c3-TB26-REV-CAND-03` (ordinal 393 PASSes on distinct-source-face
coverage while preserving every conflicting owner observation). `M3-CP4c3-TB26-REV-CAND-02` remains RESOLVED as a
lawful domain difference. `M3-CP4c3-TB26-REV-CAND-04` and `M3-CP4c3-DEFN-R3-CAND-01` are **confirmed at runtime and
gating** — they stay open because their corrective rule is not yet authorized, not because the evidence is
lacking.

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
- **Two of four certifier interior arcs SEPARATE** — arc 14 `(0,1)`, arc 22 `(0,3)`; arcs 20 and 24 are `(0,0)`.
  An arc separates iff its dart orbits differ. Do not re-derive this from the terminal-slit flag: a per-segment
  property does not classify an arc.
- **`matchesFailingComponent=false` is runtime-proved.** Never quote a certifier-census number as evidence about
  the 191-face failing plan component.
- **The plan's domain is contained in the certifier's**, with the same barrier families; the 23-face difference is
  the faces carrying a direct certified read, which the plan excludes and then cannot find as seeds.
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
- **TB27 runtime refutes the claim that all four certifier interior arcs are bridges:** arcs 14 and 22 have
  different forward/reverse orbits; arcs 20 and 24 have equal orbits. This fact is scoped to the certifier
  `NotTraceCut` partition.
- **The failure and census partitions are runtime-proved different:** ordinal406 publishes
  `matchesFailingComponent=false`. Never transfer certifier component counts/arcs to the failing plan component.
- 368/369/370/374 are unchanged carried surfaces with separate owners. Vertex 30 and finalize/contact remain
  separate and untouched.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load only the minimum current authority:

1. `ORIENTATION.md` — read first.
2. **this file** — current frontier and candidate ownership.
3. `Architecture_M3_CP4c3_TB27_Independent_Review_Record.md` — **CL0–CL9**, the adjudication and the frozen CB32 scope.
4. `Architecture_M3_CP4c3_TB27_R1_Artifact_Only_Test_Benchmark_Report.md` — latest semantic runtime authority.
5. `Architecture_M3_CP4c3_CB31_Code_Build_Report.md` — immutable compile/package authority.
6. `M3_CP4c_Frozen_Definitions.md`, `Regression_Root_Cause_Tracker.md`, `Required_Green_Selector_Manifest.md`.
7. `M3_CP4c_Consolidated_Record.md` — folded-document resolver.

Exact next is `M3-CP4c-3-CB32` under CL6–CL9 — **the last diagnostic turn authorized on this frontier**. It
corrects no product behaviour; the review that reads TB28 must freeze a correction.
