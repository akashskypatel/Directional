# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-06** at `M3-CP4c-3-TB32-REV` closeout.

---

## 1. Where the checkpoint stands

**`M3-CP4c-3-TB32` is the current valid semantic runtime authority.** Selector **408**, **397 PASS / 11 RED**,
accepted **1–365 = 365/365**, RED `[366,367,368,369,370,374,390,393,398,406,407]`, on immutable CB37 package
`9983643195` / source `7f63b5f41a0ca72f0b984ec4ee42d11f74775719`. Run/job `34024893763 / 101464028080`; result/log
`9986786215 / 9986786399`; every row `selected=1`; `timeout_count=0`; all three byte+mode censuses equal pre/post.
Certified ownership remains **300 established / 0 unavailable / 0 conflicting**.

CP4c-3 remains **OPEN**. Stable accounting **44 / 14 / 30**, debt **5**, packages **97**.

## 2. Both DEFN-R4 falsifiers held; the frontier advanced; CS3 did not

**Upheld.** A complete search of all 408 raw logs finds **zero** emissions of `TraceArcDoesNotSeparateItsSides`
(**R4.3**) and **zero** of `UncutFaceComponentOrbitSeedNotUnique` (**R4.1**). 366/367 now stop at
**`RegionBoundaryNotSingleWalk`**, raised from `validate_single_boundary_walk` inside
`build_region_certificates` — **strictly later** than the retired guard, the outcome CS6 expressly permitted.
**Two guards cleared in two turns**, each with its falsifier stated before the build.

**CB37 landed CS1/CS2/CS3-letter/CS5**, verified in source: the guard is replaced by a comment recording
DEFN-R4.1/R4.2; `annotate_region_frontier_evidence` is applied inside `build_regions` (`:1337–1342`) **and** to the
region-certification failure (`:2310–2313`); the four failure-code assertions were removed and nothing else in the
test file changed; selector 408 is byte-unchanged.

**CS3 is unmet, and DEFN-R4.5 was under-specified.** 390/393/406/407 did not return to PASS. Removing
`ASSERT_EQ("UncutFaceComponentOrbitSeedNotUnique", …)` does not help when the next lines are
`ASSERT_TRUE(locus.uncutFaceComponent.has_value())` and the remaining assertions are about **the uncut-component
stage the plan no longer fails at**. DEFN-R3.7 set this precedent for ordinal 385 and it was not applied; ordinal
390's existing `guard-cleared` early return is conditioned on `plan.has_value()`, which is **too strong**.

**Which assertion fails is not in the report** — the third consecutive turn on which the failing text for the
plan's own focused ordinals was not transcribed. The two candidate causes imply different corrections, so this
review declines to guess.

**Two evidence findings.**

- **Back-filled stage evidence.** `region_frontier_component` resolves a component from `failure.sourceFace` or
  `failure.region` when `uncutFaceComponent` is unset, and the annotator then populates the `uncutFaceComponent*`
  fields — so a `RegionBoundaryNotSingleWalk` failure can report a component that did **not** fail. DEFN-R4.4 asked
  for the digest and correspondence, not for the seed guard's own fields.
- **The ledger digest is not a semantic fingerprint.** TB32's ledger SHA-256 is **byte-identical to TB31's**
  (`6632f428…d563250b`) although every failure reason differs; the columns encode no failure detail. TB32 is
  genuinely a new run — distinct run/job, package, source, artifacts and **all three censuses** — but its
  provenance rests on those, not on the ledger hash.

**Provenance note, adjudicated as cosmetic:** `baseline-authority.txt` records `TB32 run=<TB31 run>` because the
harness was materialized by globally renaming TB31 labels. Every independent identifier is distinct and consistent,
and EXEC disclosed it. It must not recur.

## 3. Exact next turn — `M3-CP4c-3-CB38`

Code + Build, runtime-free, GMP/GMPXX linked. **No product topology, barrier, ownership or retired-guard change.**

- **CT3 — stage-labelled evidence.** Frontier evidence carries a typed **stage label**; `uncutFaceComponent*`
  publish **only** when the uncut-component stage raised the failure. This **narrows** DEFN-R4.4.
- **CT4 — the four witnesses get a justified cleared-stage outcome.** Ordinals 390/393/406/407, replaced **in
  place**, retained and gating: either the stage failed and published everything the identity owns, **or** the
  stage was cleared **and** the later failure published its labelled DEFN-R4.4 evidence. **Absence alone is never a
  pass.**
- **CT5 — a per-row failure-detail digest**, or one published beside the ledger; existing columns unchanged so
  historical hashes stay comparable.
- **CT6 — the harness is parameterised by turn identity**, not produced by search-and-replace, and
  `baseline-authority.txt` records the executing run.
- **CT7 — hard TB obligation.** `M3-CP4c-3-TB33`'s report **must** transcribe the failing assertion text for every
  RED ordinal in the focused index. A report that omits it is **incomplete**, and the review must say so rather
  than infer.

**Falsifiers, stated before the build.** If the four still fail with stage-labelled evidence published, the
re-scoping of `M3-CP4c3-TB31-REV-CAND-02` is wrong. If either retired code reappears, CB38 changed behaviour it was
forbidden to touch. If 366/367 move to an **earlier** stage, CB38 regressed the pipeline.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB31-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — the guard is retired and the authorized merge causes no downstream failure; `TraceArcDoesNotSeparateItsSides` appears in none of the 408 raw logs. |
| `M3-CP4c3-TB31-REV-CAND-02` | **ACTIVE / GATING / RE-SCOPED** — the defect is not that the four witnesses name a failure code (removed) but that their **subject is a cleared stage**. They need a justified cleared-stage outcome. Owner: CT4. |
| `M3-CP4c3-TB31-REV-CAND-03` | **CLOSED / IMPLEMENTED** — frontier evidence publishes at both annotation sites. Its **over-reach** is carried forward as `M3-CP4c3-TB32-REV-CAND-01` rather than left inside a closed candidate. |
| `M3-CP4c3-TB32-REV-CAND-01` | **NEW / ACTIVE / GATING / EVIDENCE INTEGRITY** — seed-stage `uncutFaceComponent*` fields are back-filled onto failures the seed guard did not raise. Owner: CT3. |
| `M3-CP4c3-TB32-REV-CAND-02` | **NEW / ACTIVE / EVIDENCE SURFACE** — the ledger digest encodes pass/fail only; TB31 and TB32 share a ledger hash despite entirely different failure reasons. Owner: CT5. |
| `M3-CP4c3-TB32-REV-CAND-03` | **NEW / ACTIVE / ORCHESTRATION** — harness materialization by global relabelling produced `TB32 run=<TB31 run>` in `baseline-authority.txt`. Cosmetic here; must not recur. Owner: CT6. |
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
- **A bridge arc's two darts legitimately share an orbit.** `FragmentCornerIncidence` is an **ownership map**, so a
  bridge chord's single merged entry is correct; the guard rejecting it was an internal inconsistency, since the
  same function's ray path already accepts equal orbits.
- **Call order comes from callers, not line numbers.** The retired guard is downstream of the seed guard.
- **Neither `UncutFaceComponentOrbitSeedNotUnique` nor `TraceArcDoesNotSeparateItsSides` occurs anywhere in the
  current run.** Both stages are cleared; do not cite either as a live surface.
- **The ledger digest is a pass/fail fingerprint, not a semantic one.** Two runs with different failure reasons
  produced the same hash. Use artifact digests and censuses to distinguish runs.
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

After the durable start-of-turn checklist, TB32-REV loads only the minimum current authority:

1. `ORIENTATION.md` — read first.
2. **this file** — current frontier and candidate ownership.
3. `Architecture_M3_CP4c3_TB32_Independent_Review_Record.md` — **CT0–CT7**, the adjudication and the frozen CB38 scope.
4. `Architecture_M3_CP4c3_TB32_EXEC_Report.md` — **the current valid semantic runtime authority**.
5. `Architecture_M3_CP4c3_TB32_Artifact_Only_Test_Benchmark_Plan.md` — the contract it executed.
6. `M3_CP4c_Frozen_Definitions.md` — **Part VIII is the operative definition**; CT3 narrows DEFN-R4.4.
7. `Required_Green_Selector_Manifest.md`, `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`, `LESSONS.md`.
8. `M3_CP4c_Consolidated_Record.md` — folded-document resolver.

Exact next is **`M3-CP4c-3-CB38`** under **CT3–CT7**: stage-labelled evidence, a justified cleared-stage outcome for
the four witnesses, a failure-detail digest, a harness that does not relabel, and a hard transcription obligation on
the next TB report. **Source-face ownership is closed; the seed guard and `TraceArcDoesNotSeparateItsSides` occur
nowhere in the current run.**
