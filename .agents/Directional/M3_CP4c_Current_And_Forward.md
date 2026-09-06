# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-06** at `M3-CP4c-3-CB37` closeout.

---

## 1. Where the checkpoint stands

**`M3-CP4c-3-TB31` remains the current valid semantic runtime authority.** Selector **408**, **397 PASS / 11 RED**,
accepted **1–365 = 365/365**, RED `[366,367,368,369,370,374,390,393,398,406,407]`. CB37 has not executed
runtime. Certified ownership therefore remains last-runtime **300 established / 0 unavailable / 0 conflicting**.

**CB37 is compile-green.** Exact evidence source `7f63b5f41a0ca72f0b984ec4ee42d11f74775719`; compile run
`34014992328`; owner precompile job `101437131130` SUCCESS; package job `101437310546` SUCCESS; immutable package
artifact `9983643195`, provider digest `75fcebb299c02b3a10525d935973a8cfca5bf119e3cfc4e54b5591f3cf8f699f`;
packaged source SHA-256 `cae8e29946c5e9dfea1a49070e0d8721bc17fb53dba54bb6c66188347560d3fa`; GMP/GMPXX linked;
root checksums PASS; source status clean; `runtimeExecution=false`. Selector 408 stayed byte-identical.

CP4c-3 remains **OPEN**. Stable accounting **44 / 14 / 30**, debt **5**, reported semantic packages **97**.

## 2. Part VIII implementation is complete; runtime proof is pending

CB37 implements DEFN-R4 CS1-CS5:

- `FragmentCornerIncidence` remains an ownership map; equal-orbit full-chord sides now intentionally accumulate
  into one owning-orbit entry instead of emitting `TraceArcDoesNotSeparateItsSides`. Enum/string declaration stays.
- existing frontier fields are now populated on region-construction/certification failures through a shared private
  annotation path. Correspondence between the plan and certifier partitions is derived by face-set relation, never
  by equal numeric component index.
- ordinals 390/393/406/407 retain all evidence they legitimately own but no longer pin the incidental terminal
  detail code. Names, fixtures, ordinals, gating membership and selector bytes are unchanged.
- source-face ownership was not reopened; 368/369/370/374/398 are untouched; the two partitions remain separate;
  no new diagnostic contract was added.

Accepted-prefix safety is by construction: terminal-slit handling and unequal-orbit behavior are unchanged; the
only removed stop was the contradictory equal-orbit full-chord rejection; the same function's ray path already
accepts that ownership relation.

## 3. Exact next subturn — `M3-CP4c-3-TB32-EXEC`

Execute immutable package `9983643195` under
`Architecture_M3_CP4c3_TB32_Artifact_Only_Test_Benchmark_Plan.md`. No rebuild, repair, source/test/fixture/selector
mutation, generated discovery or benchmark.

Required outcome/evidence:

- selector 408 executes exactly once per identity; accepted 1–365 remain 365/365;
- 390/393/406/407 return PASS;
- 368/369/370/374/398 stay RED as credibility rows not owned by CB37;
- 366/367 do not emit `TraceArcDoesNotSeparateItsSides`;
- the old 189/1/`[0]` `UncutFaceComponentOrbitSeedNotUnique` stop does not reproduce;
- complete plan/certifier frontier evidence and ownership census are preserved;
- package/source/execution-view bytes and modes remain unchanged.

TB32-EXEC records raw evidence only. Exact successor after a mechanically valid EXEC is `M3-CP4c-3-TB32-REV`,
which performs evidence-only semantic review and no runtime or implementation mutation. Independent review/planning
is a separate outsourced boundary; stop the implementation loop there.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB31-REV-CAND-01` | **IMPLEMENTED BY CB37 / AWAITING TB32** — ownership-map semantics are implemented; the equal-orbit guard emission is retired. Runtime owner: TB32. |
| `M3-CP4c3-TB31-REV-CAND-02` | **IMPLEMENTED BY CB37 / AWAITING TB32** — 390/393/406/407 assert their durable evidence without pinning one terminal code. Runtime owner: TB32. |
| `M3-CP4c3-TB31-REV-CAND-03` | **IMPLEMENTED BY CB37 / AWAITING TB32** — frontier evidence publication is generalized across region-construction/certification failure loci. Runtime owner: TB32. |
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

After the durable start-of-turn checklist, TB32-EXEC loads only the minimum current authority:

1. `ORIENTATION.md` — read first.
2. `Architecture_M3_CP4c3_TB32_Artifact_Only_Test_Benchmark_Plan.md` — authoritative immutable runtime plan.
3. `Architecture_M3_CP4c3_CB37_Code_Build_Report.md` — exact source/package provenance and static safety argument.
4. **this file** — current frontier and candidate ownership.
5. `M3_CP4c_Frozen_Definitions.md` — Part VIII definition/falsification authority.
6. `Required_Green_Selector_Manifest.md`, `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
7. `LESSONS.md` plus workflow/retention/cleanup policies required by the start checklist.

Exact next is **`M3-CP4c-3-TB32-EXEC`** on immutable artifact `9983643195`. It executes selector 408 exactly as
frozen, preserves raw evidence, performs no rebuild/repair/mutation and executes no benchmark. After mechanically
valid EXEC evidence, exact next is **`M3-CP4c-3-TB32-REV`**. Source-face ownership remains closed and must not be
re-opened.
