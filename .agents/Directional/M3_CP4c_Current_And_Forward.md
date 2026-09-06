# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-06** at `M3-CP4c-3-TB31-REV` closeout.

---

## 1. Where the checkpoint stands

**`M3-CP4c-3-TB31` is the current valid semantic runtime authority.** Selector **408**, **397 PASS / 11 RED**,
accepted **1–365 = 365/365**, RED `[366,367,368,369,370,374,390,393,398,406,407]`, on immutable CB36 package
`9982174864` / source `90bf8430f54c8b81fb90a6bda820cf8edebce6e9`. Run/job `34011402843 / 101427791582`; result/log
`9982618043 / 9982618174`; ledger `6632f428243788c98c816571f47ef0cf98df25a57274b2df75612674d563250b`; every row
`selected=1`; `timeout_count=0`; all three byte+mode censuses equal pre/post.

CP4c-3 remains **OPEN**. Stable accounting **44 / 14 / 30**, debt **5**, packages **96**.

## 2. The seed frontier is closed; the frontier moved to fragment identity

**Closed.** Component 0 moved from **191 faces / seedCount 3 / `Multiple` / `[0,1,3]`** to
**189 / 1 / `Unique` / `[0]`**. Certified ownership remains **300 established / 0 unavailable / 0 conflicting**.
The chain opened at TB19 — *can certified source-face ownership be established, and can the plan consume it?* — is
answered on both halves.

**Both falsifiers stated before the build were checked and neither reproduced.** The old
`191 / 3 / [0,1,3]` fingerprint did not return, and **no `TraceCutFaceFragmentCountMismatch` appears in any of the
408 raw logs** — confirming the `tracePieceCount` by-construction argument. CB36's diff is the guard at
`GlobalTopologyPlan.cpp:830` plus a comment correction and nothing else.

**The new frontier.** 366/367 now stop at **`TraceArcDoesNotSeparateItsSides`**, **arc 15**,
`sourceFace=8,10,151`, guarded at `GlobalTopologyPlan.cpp:474–479` in `build_fragment_corner_incidence`. The guard
is **pre-existing** — CB36 did not touch its site, which carries its own untouched `is_terminal_slit` skip at
`:467`.

**It is not gratuitous.** The function writes `result[sourceFace][cornerOrbit]`, `FragmentCornerIncidence` is
`map<SourceFace, map<orbit, set<SourceVertexId>>>` (`:399–401`), and its consumer keys fragments the same way —
`FragmentKey = pair<SourceFaceTopologyKey, std::size_t /*orbit*/>` with an `owningOrbit` parameter (`:1675`,
`:1693–1699`). **A fragment is identified by `(face, orbit)` throughout region disc certification, and that key is
not injective when an arc's two darts share an orbit**: the two sides collapse onto one entry and their corner sets
merge. The guard refuses rather than merging silently.

**Its premise contradicts §5**, which has held since TB18: shared orbit ownership by the two sides of one arc is
**legitimate topology**, measured on arc 15 at DEFN-R3.4, and relied on by the very correction that closed the seed
frontier — arcs 20 and 24 (`0/0`) are deliberately left alone. **The defect is the key, not the check.**

**Four ordinals are pinned witnesses.** 390, 393, 406 and 407 each expected
`UncutFaceComponentOrbitSeedNotUnique` and received the new code. **404 and 408 stayed PASS** — the two identities
written to assert *publication and completeness* rather than an outcome. Six identities across two forward steps
have now redded for this reason.

**Not established:** why the guard became reachable. Static source does not settle it; the retained logs in artifact
`9982618174` do, and CR8 requires it transcribed rather than inferred.

## 3. Exact next turn — `M3-CP4c-3-DEFN-R4`

**A definition turn, not a Code + Build turn.** `(face, orbit)` is the identity of a fragment across
`FragmentCornerIncidence` and region disc certification, so changing it decides what a fragment *is*. Part VII's
chain is where this project freezes such decisions, and `DEFN` absorbs REVIEW + PLAN.

**CL8 does not bind here.** It forbade further diagnostic turns on **source-face ownership**, which is now closed,
and a definition decision is not a diagnostic.

- **CR6 — decide:** what identifies a fragment, so the key is **injective on a bridge**; the disposition of
  `TraceArcDoesNotSeparateItsSides`, retired **only as a consequence** of that decision and never merely deleted;
  the **in-place** repair of ordinals 390/393/406/407, each keeping every contract it legitimately owns and no
  longer asserting *which* terminal failure code the product produces; and where frontier evidence attaches, since
  the plan-side digest and `censusCorrespondence` are emitted only on the seed-guard path.
- **CR7 — must not:** re-open source-face ownership (closed at 300/300 with a unique seed); weaken or re-scope
  ordinal **398** (prescribed sphere, owned by `M3-CP4c2-TB-X2-CAND-04`); touch 368/369/370/374; unify the two
  partitions; change any accepted identity 1–365 or any byte of selector 397–408.
- **CR8 — transcribe** from artifact `9982618174` why the guard became reachable. Existing evidence, not a new
  measurement.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB31-REV-CAND-01` | **NEW / ACTIVE / GATING / ARCHITECTURAL** — fragment identity is `(face, orbit)` across `FragmentCornerIncidence` and region disc certification, and that key is **not injective when an arc's two darts share an orbit**. `TraceArcDoesNotSeparateItsSides` is the guard defending it. Owner: **DEFN-R4**. |
| `M3-CP4c3-TB31-REV-CAND-02` | **NEW / ACTIVE / GATING / TEST AUTHORITY** — ordinals 390, 393, 406 and 407 pin a specific terminal failure code and red on any forward step. Owner: **DEFN-R4** measures. |
| `M3-CP4c3-TB31-REV-CAND-03` | **NEW / ACTIVE / EVIDENCE SURFACE / NON-GATING** — the plan-side face-set digest and `censusCorrespondence` are emitted only on the seed-guard failure path and vanished when the terminal failure changed. Owner: **DEFN-R4**. |
| `M3-CP4c3-TB30-REV-CAND-02` | **NEW / ACTIVE / EVIDENCE SURFACE / NON-GATING** — the plan-side interior-arc census is a projection of the certifier's rows, so an arc that still cuts the plan's component but has left the certifier's uncut census is invisible to it. Not blocking CQ7. |
| `M3-CP4c3-TB27-REV-CAND-01` | **CORRECTED / RUNTIME-PROVED** — CB34's separating-arc barrier rule excludes the crossed faces and preserves equal-orbit slits; ordinal 408 passes on all three properties. |
| `M3-CP4c3-TB26-REV-CAND-02` | **RESOLVED / LAWFUL DOMAIN DIFFERENCE** — 76 and 97 belong to different partitions; TB27 additionally exposes 214-vs-191 faces and distinct digests. |
| `M3-CP4c3-TB27-REV-CAND-02` | **ACTIVE / ARCHITECTURAL / NON-GATING** — the plan excludes from its component domain exactly the faces carrying a direct certified read (`GlobalTopologyPlan.cpp:702`, `:750`), then fails to seed that component. |
| `M3-CP4c3-TB26-REV-CAND-04` | **ACTIVE / NO LONGER THE BLOCKING CAUSE** — the plan's partition now yields a unique owner, so the divergence does not hold the frontier. Unification remains a **`DEFN`** question. |
| `M3-CP4c3-TB25-REV-CAND-02` | **ACTIVE / GATING / UNDECIDED FOR THE FAILING OBJECT** — the certifier component contains two separating arcs, but it is not the 191-face failing plan component. **TB28-R2 supplied no admissible evidence about it.** CL8 is nonetheless discharged: the correction is frozen and does not depend on this being decided first. |
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

**Nothing is discharged by TB28-R2** — an invalid gate discharges nothing, and every candidate keeps the status it
held at TB27-REV. **Closed at TB27-REV, runtime-proved:** `M3-CP4c3-TB26-REV-CAND-01` and
`M3-CP4c3-TB26-REV-CAND-03`. `M3-CP4c3-TB26-REV-CAND-02` remains RESOLVED as a lawful domain difference.
`M3-CP4c3-TB26-REV-CAND-04` and `M3-CP4c3-DEFN-R3-CAND-01` are **confirmed at runtime and gating**.

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
- **Certified source-face ownership is TOTAL: 300 established / 0 unavailable / 0 conflicting**, and the plan's
  component 0 has a **unique** seed `[0]` over 189 faces. **The seed frontier opened at TB19 is CLOSED.** Do not
  re-open it.
- **A bridge arc's two darts legitimately share an orbit**, and a key of the form `(face, orbit)` is therefore not
  a fragment identity. A guard that rejects bridges is defending a broken key.
- **A witness pinned to a terminal failure code reds on every forward step.** 404 and 408 survived two corrections
  because they assert publication and completeness instead.
- **Ordinal 398 is not an ownership gate.** It fails on the prescribed sphere. **366 and 367 are the frontier.**
- **The 191-face component genuinely spans certified faces 0, 1 and 3.** Arcs 14 `(0/1)` and 22 `(0/3)` cross it.
  The seeds `[0,1,3]` at 81/1/1 are the true geometry, and **the seed guard was right to fail**. Do not re-pose
  this as an attribution defect.
- **TB22's minority edges `10-79` and `29-35` are edges of those two arcs' terminal-slit faces.** The thread from
  TB20 is closed.
- **A witness that asserts a defect is still present will pass vacuously and then block the fix.** Ordinal 404
  proved this at a cost of one turn.
- **Never match two partitions by component index.** Ordinal 390 proved this at a cost of one turn.
- **A green gate that contradicts an unchanged product is invalid evidence.** TB28-R2's `407 PASS / 0 RED` is
  rejected and may never be quoted as a gate result. TB28-R3 settled it by reproducing the baseline exactly on the
  same artifact.
- **A control run beats a clever measurement.** Change one variable, compare against a known baseline, and do not
  recompile — a new package is a second changed variable.
- **The product correction is FROZEN** — the separating-arc barrier rule. It is not to be re-derived, re-opened,
  widened or narrowed by any successor review.
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
3. `Architecture_M3_CP4c3_TB31_Independent_Review_Record.md` — **CR0–CR8**, the adjudication and the frozen DEFN-R4 scope.
4. `Architecture_M3_CP4c3_TB31_EXEC_Report.md` — **the current valid semantic runtime authority**.
5. `Architecture_M3_CP4c3_TB31_Artifact_Only_Test_Benchmark_Plan.md` — the contract it executed.
6. `M3_CP4c_Frozen_Definitions.md` — Part VII and its amendments; **DEFN-R4 appends here**.
7. `Regression_Root_Cause_Tracker.md`, `Required_Green_Selector_Manifest.md`, `TODO.md`, `CHANGELOG.md`.
8. `M3_CP4c_Consolidated_Record.md` — folded-document resolver.

Exact next is **`M3-CP4c-3-DEFN-R4`**, a definition turn: decide what identifies a fragment, dispose of
`TraceArcDoesNotSeparateItsSides` as a consequence, freeze the in-place repair of the four pinned witnesses, and
transcribe why the guard became reachable. **Source-face ownership is closed and must not be re-opened.**
