# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-05** at `M3-CP4c-3-TB28-R3-EXEC` closeout; semantic adjudication is deliberately pending R3-REV.

---

## 1. Where the checkpoint stands

**The latest valid semantic runtime authority is `M3-CP4c-3-TB27-R1`**, unchanged: selector **406**, **399 PASS /
7 RED**, accepted **365/365**, RED `[366,367,368,369,370,374,398]`, on immutable CB31 package `9961564041` /
source `eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc`, ledger
`8da2002701437c5d0c4a57d613e24195f4f690d1ae4494da1234d58bb9a24da5`.

**`M3-CP4c-3-TB28-R2` is REJECTED as orchestration-invalid and produced no runtime authority.** Its
`407 PASS / 0 RED` on CB32 artifact `9975737868` / source `098ac7d93ea203222dd0ac50cdb68667744f0fd4` is retained
only as invalid-attempt provenance (run `33990951740`; result/log `9976662518 / 9976662690`). R1 `33990315861` was
already orchestration-invalid.

CP4c-3 remains **OPEN**. Stable accounting stays **44 / 14 / 30**, debt **5**, packages **93** (CB32, compile-green
and semantically unaccepted). **The accepted-prefix count is unestablished for TB28** — neither 365/365 nor a
regression; the last established result is TB27-R1's 365/365.

## 2. Why TB28-R2 is rejected

**A status change with no behaviour change is a harness result, not a product result.**

- Selector 407 is selector **406 plus one identity**, with 406 as its exact 406-line prefix, so ordinals **366**,
  **367** and **398** are present unchanged. TB27-R1 reported all three RED.
- CB32's entire source diff is diagnostic. Every added reference to `traceCutFaces` is a `.count()` read; nothing
  writes `barriers`, `directOwners`, the seed rule, the component partition or `proves_cellularity()`. Ordinal 398
  fails exactly when the owner map is not total, and the mechanical component still carried three conflicting
  owners. **No behaviour change can account for the status change.**
- The report publishes none of the artifacts its frozen plan §4 requires — no ledger or its SHA-256, no identity
  map, no RED ordinal list, no accepted-prefix count, no censuses, no resource evidence — and records **one**
  runtime binary hash where the package holds five test executables. Routed to one binary, an unmatched
  `--gtest_filter` **exits 0**, and "exit 0 is PASS" manufactures the green. The plan's per-row `selected` column
  exists to prevent exactly this and is absent. `LESSONS.md` 129, 130.
- Its CL6 census was also **off-object for the fourth consecutive turn**: `ReliefTopologyBuildFailed` at
  `quadPatchIndex=0`, component **1**, **27** candidate faces, **101** interior arcs, `censusFailureCount=0` — where
  the frontier is component 0 with **191** faces and **4** interior arcs. The `subset=true` row compares neither of
  the sets CL7 asked about and cannot be credited.

## 3. Exact next turns — TB28-R3-REV → CB34

**CL8 is discharged: the product correction is FROZEN and may not be re-opened.**

> **The separating-arc barrier rule.** In `build_source_face_ownership`, for every arc whose two darts satisfy
> `orbitByDart[forwardDart] != orbitByDart[reverseDart]`, the arc's source edges enter `barriers` and every source
> face the arc crosses is treated as trace-cut.

Derived from certified data and therefore non-circular; the invariant a partition of certified ownership must
satisfy; and it does **not** over-cut — arcs 20 and 24 have equal orbits and are untouched, so the `terminalSlit`
skip is superseded **only for separating arcs**. **Accepted-prefix safety must be demonstrated by construction, not
argued.**

Only the *application order* is sequenced, because the one instrument that could confirm the correction currently
reports green on a product that provably fails:

1. **`M3-CP4c-3-CB33` — COMPLETE / preflight GREEN** (CM7). Static per-identity routing, per-row selection proof,
   full ledger/resource/census contract and invalid-attempt provenance are installed. No Directional runtime or
   product correction occurred.
2. **`M3-CP4c-3-TB28-R3-EXEC` — COMPLETE / mechanically valid.** Run/job `33995961030 / 101386467115`
   executed all 407 rows with `selected=1`, no timeout/orchestration failure and immutable pre/post censuses. The raw
   ledger labels 366/367/398 RED, but EXEC does not promote semantic authority.
3. **`M3-CP4c-3-TB28-R3-REV` — EXACT NEXT.** Review the existing R3 evidence only; apply the credibility gate,
   classify regressions and adjudicate the 191-face census without new runtime or re-opening the frozen correction.
4. **`M3-CP4c-3-CB34`** (CM9) — only if R3-REV authorizes it, implement the frozen correction and nothing else.

**TB28-R2's `407 PASS / 0 RED` may not be quoted as a gate result, an accepted-prefix result, or evidence that any
candidate is discharged.**

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB28-REV-CAND-01` | **ACTIVE / GATING / ORCHESTRATION — R3-EXEC mechanically reproduced RED controls 366/367/398 with `selected=1`.** Semantic discharge is reserved to R3-REV after full integrity review. |
| `M3-CP4c3-TB28-REV-CAND-02` | **ACTIVE / EVIDENCE INTEGRITY.** The CL6 block must be re-adjudicated from the 191-face ownership frontier in TB28-R3; CB33 changed only harness evidence plumbing. Owner: TB28-R3-REV. |
| `M3-CP4c3-TB27-REV-CAND-01` | **ACTIVE / GATING / PRODUCT — THE CORRECTION IS FROZEN** — the certifier's 214-face component contains two separating arcs, so that partition merges faces lying in different certified faces. Corrected by the frozen separating-arc barrier rule at **CM9 / CB34**. |
| `M3-CP4c3-TB26-REV-CAND-02` | **RESOLVED / LAWFUL DOMAIN DIFFERENCE** — 76 and 97 belong to different partitions; TB27 additionally exposes 214-vs-191 faces and distinct digests. |
| `M3-CP4c3-TB27-REV-CAND-02` | **ACTIVE / ARCHITECTURAL / NON-GATING** — the plan excludes from its component domain exactly the faces carrying a direct certified read (`GlobalTopologyPlan.cpp:702`, `:750`), then fails to seed that component. **Not** confirmed by TB28-R2, whose subset row compares a 27-face relief-topology candidate set. |
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
  rejected and may never be quoted as a gate result.
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
3. `Architecture_M3_CP4c3_TB28_Independent_Review_Record.md` — **CM0–CM9**, the rejection, the frozen correction and the CB33/TB28-R3/CB34 sequence.
4. `Architecture_M3_CP4c3_TB27_R1_Artifact_Only_Test_Benchmark_Report.md` — **the current valid semantic runtime authority**.
5. `Architecture_M3_CP4c3_CB32_Code_Build_Report.md` — package under test.
6. `Architecture_M3_CP4c3_TB28_R3_EXEC_Report.md` — current immutable execution evidence index.
7. `Architecture_M3_CP4c3_TB28_R3_Artifact_Only_Test_Benchmark_Plan.md` — exact REV contract.
8. `Architecture_M3_CP4c3_CB33_Code_Build_Report.md` — CB33 harness/preflight evidence.
9. `Architecture_M3_CP4c3_TB28_R2_Artifact_Only_Test_Benchmark_Report.md` — **invalid-attempt provenance only**.
10. `M3_CP4c_Frozen_Definitions.md`, `Regression_Root_Cause_Tracker.md`, `Required_Green_Selector_Manifest.md`.
11. `M3_CP4c_Consolidated_Record.md` — folded-document resolver.

R3-EXEC is mechanically complete on immutable package `9975737868`; accepted semantic authority remains TB27-R1 until review. Exact next is **`M3-CP4c-3-TB28-R3-REV`**, evidence-only with no new runtime. The product correction is already frozen and must not be re-opened.
