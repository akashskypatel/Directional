# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-05** at `M3-CP4c-3-CB35` closeout.

---

## 1. Where the checkpoint stands

**`M3-CP4c-3-TB29` is the current valid semantic runtime authority.** Selector **408**, **399 PASS / 9 RED**,
accepted **1–365 = 365/365**, RED `[366,367,368,369,370,374,390,398,404]`, on immutable CB34 package `9979639398` /
source `25ab3d55697598bde436d1ac811d71e6cf911f2e`. Run/job `34002726062 / 101404386206`; result/log
`9980019423 / 9980019636`; ledger `3199d7117dbed28dd23dd22cefb543ff43f449a5a2aa859075f543a8f6195f51`; every row
`selected=1`; all three byte+mode censuses equal pre/post.

CP4c-3 remains **OPEN**. Stable accounting **44 / 14 / 30**, debt **5**, semantic packages **95**.

`M3-CP4c-3-CB35` is **COMPLETE / COMPILE GREEN / RUNTIME-FREE** at built evidence source
`ab86747bdfdb94c7c383bf5d2893ced4207eb555`. Immutable package `9980764888`
(`m3-cp4c3-cb35-result-34005311571`) has provider ZIP SHA-256
`ebae13c53b7430a256865465cff640b460b45299cd5c17db0ce3582d38cb58e0`; compile run `34005311571` succeeded,
root `SHA256SUMS` verified 28/28, source remained clean, all eight required targets compiled, GMP/GMPXX linkage was
verified, and `runtimeExecution=false`. Selector 408 bytes are unchanged. TB29 therefore remains the current
semantic runtime authority until TB30 is validly reviewed.

## 2. The correction landed, and the frontier question is decided

**CB34's product change is seven lines** (`SurfaceCutGraph.cpp:538,549`):
`separatesCertifiedFaces = forwardOrbit != reverseOrbit`, and the terminal-slit skip becomes
`if (terminalSlit && !separatesCertifiedFaces)`. For a separating arc the **pre-existing** body runs unchanged —
`traceCutFaces.insert(sourceFace)` plus both carrier insertions into `barriers`; for an equal-orbit arc nothing
changes at all. Accepted-prefix safety is **structural**, and 365/365 confirms it.

**Ordinal 408 PASSes all three of its properties:** no separating arc remains interior to any uncut component;
every face crossed by a separating arc is absent from the uncut census; and **every equal-orbit terminal-slit face
is still present** — over-cutting falsified positively rather than assumed away.

**DECIDED — the question open since TB20.** From CB34's CN7 transcription: arc **14** (`0/1`) has terminal crossed
face **`(28,29,35)`** and arc **22** (`0/3`) has **`(10,79,151)`**, **both with `plan=0`** — inside the 191-face
failing component — and the census records **subset = true**. So the component **genuinely spans certified faces 0,
1 and 3**; the seeds `[0,1,3]` are the true geometry; **the seed guard was right to fail**; the barrier set was the
defect, exactly as the frozen rule assumed. TB22's minority edges **`10-79`** and **`29-35`** are edges of precisely
those two arcs' terminal-slit faces, and the minority orbits 1 and 3 are those arcs' reverse orbits. **The 81/1/1
distribution was never an attribution defect.**

**The two new REDs are test authority, not product.**

- **Ordinal 404** ends with a loop requiring `EXPECT_NE(Established, owner->status)` for every face of the
  component (`tests/FieldAlignedCurveNetworkTests.cpp:14347–14352`) — a required-green assertion that the defect
  under repair is still present, contrary to its own frozen contract. Introduced at **CB31**, it passed for four
  turns **vacuously**. **Its firing is positive evidence:** it can only fail if a face is now `Established`.
- **Ordinal 390** locates the certifier census by `row.component == *locus.uncutFaceComponent` (`:11564–11567`) —
  **matching two partitions by index**, the conflation ordinal 406 proved invalid. It agreed while both indices
  were 0 and both counts 3.

**Still open:** 366/367/398 remain RED, so ownership is not yet total. The `established` / `unavailable` /
`conflicting` counts after the correction are what decide whether a second correction is needed, and the runtime
already publishes them.

**CB35 restored the two test witnesses without changing product behavior.** Ordinal 404 no longer requires every
owner to remain non-`Established`. Ordinal 390 now uses face-set digest / published subset correspondence and only
compares cross-partition counts on exact semantic correspondence; numeric component index is never treated as
identity. The post-correction TB29 census was transcribed from immutable artifact `9980019636`: failing plan
component `0 / EmptyFragmentOrbits / 191 faces / digest 17919102493633069558 / seeds [0,1,3]`; comparison census
`0 / NotTraceCut / 212 faces / digest 835099723348023536`, with `matchesFailingComponent=false` and
`failingComponentSubsetOfCensusComponent=false`; only equal-orbit arcs 20 and 24 remain interior; owner publication
is **300 established / 0 unavailable / 0 conflicting**. Exact RED assertion text is retained in
`Architecture_M3_CP4c3_CB35_Code_Build_Report.md`.

## 3. Exact next turn — `M3-CP4c-3-TB30-EXEC`

Artifact-only Test + Benchmark on immutable CB35 package `9980764888` and frozen selector 408. Follow
`Architecture_M3_CP4c3_TB30_Artifact_Only_Test_Benchmark_Plan.md` exactly.

- Verify exact artifact/source/checksum/executable-mode authority before runtime.
- Execute all **408** selector identities in frozen order, one identity per fresh process and fresh working
  directory, through the statically resolved owning packaged test binary.
- Require `selected == 1` for every row and preserve all raw identity logs, ledger/resource evidence, and pre/post
  byte+mode censuses.
- Accepted identities **1–365 must remain 365/365 PASS**.
- Corrected witnesses **390 and 404 must PASS**.
- Credibility controls **366, 367 and 398 must remain RED** because CB35 changed no product behavior. An unexpected
  PASS is evidence-integrity trouble until review, not automatic progress.
- 368/369/370/374 are carried separate-owner surfaces and are recorded exactly without repair or mutation.
- If only the two authorized witness corrections change, the consistent aggregate is **401 PASS / 7 RED** with
  RED `[366,367,368,369,370,374,398]`.

No configure, compile, relink, rebuild, repackaging, package repair/chmod, generated discovery, benchmark,
source/test/fixture/selector mutation, or semantic retry is permitted. TB30-EXEC records raw evidence only and
**stops at `M3-CP4c-3-TB30-REV`**. No second product correction is authorized before that review reads the census.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB29-REV-CAND-01` | **CORRECTED BY CB35 / AWAITING TB30 / GATING / TEST AUTHORITY** — ordinal 404's out-of-contract `EXPECT_NE(Established, …)` loop was removed; all publication/completeness assertions remain. Runtime proof pending TB30. |
| `M3-CP4c3-TB29-REV-CAND-02` | **CORRECTED BY CB35 / AWAITING TB30 / GATING / TEST AUTHORITY** — ordinal 390 now uses face-set digest / published subset correspondence and never component index as cross-partition identity. Runtime proof pending TB30. |
| `M3-CP4c3-TB27-REV-CAND-01` | **CORRECTED / RUNTIME-PROVED** — CB34's separating-arc barrier rule excludes the crossed faces and preserves equal-orbit slits; ordinal 408 passes on all three properties. |
| `M3-CP4c3-TB26-REV-CAND-02` | **RESOLVED / LAWFUL DOMAIN DIFFERENCE** — 76 and 97 belong to different partitions; TB27 additionally exposes 214-vs-191 faces and distinct digests. |
| `M3-CP4c3-TB27-REV-CAND-02` | **ACTIVE / ARCHITECTURAL / NON-GATING** — the plan excludes from its component domain exactly the faces carrying a direct certified read (`GlobalTopologyPlan.cpp:702`, `:750`), then fails to seed that component. |
| `M3-CP4c3-TB26-REV-CAND-04` | **RUNTIME-PROVED / GATING / ARCHITECTURAL** — ordinal406 reports `matchesFailingComponent=false`; census and failure partitions differ. **Now the more prominent debt**: ordinal 390 was silently depending on the two partitions' indices coinciding. |
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
3. `Architecture_M3_CP4c3_CB35_Code_Build_Report.md` — built evidence, exact CO7 census transcription, and CB35
   compile/package authority.
4. `Architecture_M3_CP4c3_TB30_Artifact_Only_Test_Benchmark_Plan.md` — **the exact next executable contract**.
5. `Architecture_M3_CP4c3_TB29_EXEC_Report.md` — current valid semantic runtime authority.
6. `Architecture_M3_CP4c3_TB29_Independent_Review_Record.md` — CO0–CO8 adjudication and frozen CB35/TB30 boundary.
7. `tools/m3_cp4c3_tb28_r3_harness.sh` and its TB29/TB30 successor — the instrument; read it rather than a summary.
8. `M3_CP4c_Frozen_Definitions.md`, `Regression_Root_Cause_Tracker.md`, `Required_Green_Selector_Manifest.md`.
9. `M3_CP4c_Consolidated_Record.md` — folded-document resolver.

Exact next is **`M3-CP4c-3-TB30-EXEC`** on immutable package `9980764888` and selector 408. It is artifact-only,
records raw evidence, and stops at **`M3-CP4c-3-TB30-REV`**. No second product correction is authorized before that
review.
