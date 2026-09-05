# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-05** at `M3-CP4c-3-TB28-R3-REV` closeout.

---

## 1. Where the checkpoint stands

**`M3-CP4c-3-TB28-R3` is the current valid semantic runtime authority.** Selector **407**, **400 PASS / 7 RED**,
accepted **1–365 = 365/365**, RED `[366,367,368,369,370,374,398]`, on immutable CB32 package `9975737868` / source
`098ac7d93ea203222dd0ac50cdb68667744f0fd4`. Run/job `33995961030 / 101386467115`; result/log
`9978114313 / 9978114502`; ledger `fa0626b8a28c0f2758e68e2be712fff024197e445be46e46c9491395cc0609ac`; identity map
`9e726c011f884da55877e6bbca420be530f05325263eddcd86993c1f0a54d3fd`; harness
`b3191b314afa22f72e6f720519cfa2f8ad090dce3de5617612ad64c195489fbf`. All three byte+mode censuses equal pre/post.

**The accepted-prefix count, recorded as unestablished at TB28, is restored to 365/365.** CP4c-3 remains **OPEN**.
Stable accounting **44 / 14 / 30**, debt **5**, packages **93** — CB33 compiled nothing, so the count does not
advance. TB28-R1 and TB28-R2 remain orchestration-invalid provenance with no semantic credit.

## 2. The control passed, and it was a real control

TB27-R1 was 399 PASS / 7 RED on selector **406**; TB28-R3 is 400 PASS / 7 RED on selector **407** = 406 plus one
identity, and that identity PASSes. **The delta between the two runs is exactly the appended identity and nothing
else** — the whole 406-row prefix is unchanged in outcome. On the same artifact, TB28-R2 had reported
`407 PASS / 0 RED`; two runs of one immutable package differing by seven ordinals settle which was measuring the
product.

- **No product change.** `git diff` over `src include tests` between the TB28 review commit and HEAD is **empty**.
- **CB33 deliberately did not recompile**, because a replacement compile would have created a new package/source
  authority and defeated the experiment. One variable changed: the harness.
- **The instrument proves selection.** `tools/m3_cp4c3_tb28_r3_harness.sh` enforces exactly one binary owner per
  identity and raises otherwise, requires each staged executable to match the package by digest **and mode**, sets
  `GTEST_FAIL_IF_NO_TEST_SELECTED=1`, counts `[ RUN      ]` lines independently of the exit code, and sets
  `result=PASS` **only when `selected == 1` and `exit == 0`**. Every ledger row records `selected=1`.
- **The TB28-R2 mechanism is independently confirmed:** the 407 identities span **15 distinct test source files**,
  so single-binary routing leaves the majority unmatched, and `exit 0` read as PASS manufactures the green.

**Not discharged:** the frozen plan required the **191-face component's** ownership census to be published and
adjudicated. The EXEC report records 404/406/407 PASS and defers the assessment without carrying the values. The
census exists inside immutable log artifact `9978114502` and in no retained document. It does **not** block the
correction, which is sound on both branches of the CL6 dichotomy by construction. `LESSONS.md` 131.

## 3. Exact next turn — `M3-CP4c-3-CB34`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`. It implements **CM9 as frozen** plus
**CN7**, and **the correction may not be re-derived, widened, narrowed or deferred**.

> **The separating-arc barrier rule.** In `build_source_face_ownership`, for every arc of `embedded.arcs` whose two
> darts satisfy `orbitByDart[forwardDart] != orbitByDart[reverseDart]`, the arc's source edges enter `barriers`,
> and every source face the arc crosses is treated as trace-cut and therefore excluded from `uncutFaces`.

- Barriers and trace-cut status key on the **orbit inequality**, not on `terminalSlit`. Non-separating arcs — arcs
  20 and 24 have equal orbits — are untouched, so the rule does not over-cut.
- **Accepted-prefix safety is demonstrated by construction, not argued**: show the rule is a no-op wherever the
  current code already inserts the same barrier, and enumerate what changes where it does not.
- `proves_cellularity()` and ordinals 397–407 keep their contracts. **No ordinal is weakened to obtain a green.**
- Any required witness appends as selector **408** with 407 as an exact prefix, asserting the rule's **effect on
  the census**, never a predicted owner value.
- **CN7:** transcribe the 191-face component's census into a retained document — component/domain identities,
  face-set digest, face count, interior-arc rows with both dart orbits and crossed faces, and seed attributions.
  A transcription of existing evidence, **not a new diagnostic**, so CL8 is untouched.

**One correction only.** No attribution-rule edit, no seed winner, no partition unification, no new ownership
diagnostic.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB28-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — TB28-R3 reproduced all seven known REDs with `selected=1` on every row, on the unchanged package, and the harness mechanism was verified in source. Its own falsification condition is met. |
| `M3-CP4c3-TB28-REV-CAND-02` | **ACTIVE / EVIDENCE INTEGRITY — NARROWED** from "published from the wrong path" to "**published at runtime but not transcribed into any retained record**". The census lives in immutable log artifact `9978114502`. Owner: **CN7**, at CB34 closeout. |
| `M3-CP4c3-TB27-REV-CAND-01` | **ACTIVE / GATING / PRODUCT — THE CORRECTION IS FROZEN** — the certifier's 214-face component contains two separating arcs, so that partition merges faces lying in different certified faces. Corrected by the frozen separating-arc barrier rule at **CM9 / CB34**. |
| `M3-CP4c3-TB26-REV-CAND-02` | **RESOLVED / LAWFUL DOMAIN DIFFERENCE** — 76 and 97 belong to different partitions; TB27 additionally exposes 214-vs-191 faces and distinct digests. |
| `M3-CP4c3-TB27-REV-CAND-02` | **ACTIVE / ARCHITECTURAL / NON-GATING** — the plan excludes from its component domain exactly the faces carrying a direct certified read (`GlobalTopologyPlan.cpp:702`, `:750`), then fails to seed that component. Still unconfirmed; TB28-R2's subset row was inadmissible and TB28-R3's census is untranscribed. |
| `M3-CP4c3-TB26-REV-CAND-04` | **RUNTIME-PROVED / GATING / ARCHITECTURAL** — ordinal406 reports `matchesFailingComponent=false`; census and failure partitions differ. |
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
3. `Architecture_M3_CP4c3_TB28_R3_Independent_Review_Record.md` — **CN0–CN8**, the control adjudication, the restated frozen correction and CN7.
4. `Architecture_M3_CP4c3_TB28_R3_EXEC_Report.md` — **the current valid semantic runtime authority**.
5. `Architecture_M3_CP4c3_TB28_R3_Artifact_Only_Test_Benchmark_Plan.md` — the contract it executed.
6. `Architecture_M3_CP4c3_CB33_Code_Build_Report.md` and `Architecture_M3_CP4c3_CB32_Code_Build_Report.md` — the harness correction and the package under test.
7. `tools/m3_cp4c3_tb28_r3_harness.sh` — **the instrument itself; read it rather than a summary of it**.
8. `M3_CP4c_Frozen_Definitions.md`, `Regression_Root_Cause_Tracker.md`, `Required_Green_Selector_Manifest.md`.
9. `M3_CP4c_Consolidated_Record.md` — folded-document resolver.

Exact next is **`M3-CP4c-3-CB34`**, which applies the frozen separating-arc barrier rule and transcribes the
191-face census. **The correction may not be re-opened**, and no second product change or new ownership diagnostic
is authorized.
