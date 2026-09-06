# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-06** at `M3-CP4c-3-CB39` closeout.

---

## 1. Where the checkpoint stands

**`M3-CP4c-3-TB33` is the current valid semantic runtime authority.** Selector **408**, **401 PASS / 7 RED**,
accepted **1–365 = 365/365**, RED `[366,367,368,369,370,374,398]`, on immutable CB38 package `9994997588` / source
`0d03edb07388c56b592a74e2e7fc5f3edde8cea4`. Run/job `34054234216 / 101543088114`; result/log
`9995528719 / 9995529075`; every row `selected=1`; `timeout_count=0`;
`failure-detail-digests.tsv` table SHA-256 `2347c691…57cf479`.

Certified ownership is **300 established / 0 unavailable / 0 conflicting**, and **all nine** plan components
publish `seedCount=1, seedState=Unique`. CP4c-3 remains **OPEN**. Stable accounting **44 / 14 / 30**, debt **5**,
packages **99** (CB39 compile package; TB33 remains runtime authority).

## 2. Every CT measure discharged; the RED set is now clean

| Measure | Outcome |
|---|---|
| **CT3** stage-labelled evidence | 366/367 publish `regionFrontierFailureStage=RegionCertification`; **no legacy `uncutFaceComponent*` fields** remain in their detail bytes. |
| **CT4** justified cleared-stage outcome | **390/393/406/407 PASS**, selector 408 byte-unchanged. |
| **CT5** failure-detail digest | `failure-detail-digests.tsv` covers all 408 rows. |
| **CT6** turn-agnostic harness | `tools/m3_cp4c3_artifact_only_harness.sh`; `baseline-authority.txt` records the executing run exactly. |
| **CT7** transcription | Verbatim failure text for **every** RED focused ordinal, each with a detail SHA-256. |

**Both standing falsifiers held:** zero `TraceArcDoesNotSeparateItsSides` and zero
`UncutFaceComponentOrbitSeedNotUnique` across 408 logs, and no move to an earlier stage.

**CT5 justified itself on the run that introduced it.** TB33's ledger SHA-256 is **byte-identical to TB30's** —
same pass/fail vector, entirely different product, package and failure reasons. Second collision in three turns.
The failure-detail table is what separates them.

**The RED set is now the frontier pair plus four independently owned carried surfaces — no diagnostic scaffolding
remains.** Ordinals 404 and 408 have survived four consecutive forward steps.

## 3. The frontier — a boundary walk pinched at its start node

366/367 publish `RegionBoundaryNotSingleWalk; arc=3; regionFrontierFailureStage=RegionCertification;
V=22;E=26;F=6;componentCount=1;sourceChi=2;eulerResidual=0; regionFrontierComponentCount=6`, every component
`censusCorrespondence=Superset` with `componentSubsetOfCensusComponent=true`.

`validate_single_boundary_walk` rejects in-loop on `current == start || next.first != current`, and `failure.arc`
is set only there — **arc 3 is where the loop rejected**. The second disjunct is the real chain check; **the first
rejects a walk that passes through its own start node**. This fixture reports **`terminalSlits=10`** across twelve
traces, and a slit arc appears **twice** in a face boundary — out and back — so a boundary legitimately revisits the
slit's base node. **The certificate contradicts the rejection**, publishing six faces, componentCount 1 and
**residual 0**, all established as discs.

**Removing the disjunct loses nothing.** Two node-disjoint loops still fail `next.first != current`; the only case
it uniquely caught is two loops meeting at the start node, which is the legitimate pinch. The trailing
`current != start` still requires closure.

This is a **source derivation, not a measurement** — the published `arc=3` does not say which disjunct fired, which
is why CU5 requires a typed reason.

## 3.1 Exact next turn — `M3-CP4c-3-TB34-EXEC`

Artifact-only Test + Benchmark on immutable CB39 artifact **`9997560649`** from exact semantic source
`7711b9c2c20d284823911aa4ca067bd33244f4e6`, selector **409**. Compile run/job
`34061111130 / 101561719362` is green; package ZIP SHA-256
`9a71fe17b789c94f70580116b822b3949dabecda7bf1d736afef10a1e6a9c3d2`; root package checksums verify 28/28;
GMP/GMPXX are linked; `runtimeExecution=false`. CB39 itself makes no runtime claim.

Run `.agents/Directional/Architecture_M3_CP4c3_TB34_Artifact_Only_Test_Benchmark_Plan.md` without rebuilding or
mutating immutable bytes. Required hard controls: accepted prefix 365/365, ordinal 409 PASS, protected greens
390/393/404/406/407/408 PASS, retired-code silence, no earlier-stage movement of 366/367, ownership 300/0/0
whenever published, complete per-row failure details, and package/source/execution-view byte+mode immutability.

If 366/367 remain `RegionBoundaryNotSingleWalk` with `regionBoundaryWalkReason=ArcChainBroken`, the TB33 diagnosis
is falsified and the owner moves upstream to boundary assembly. If 409 fails, CB39 weakened the chain guard. EXEC
preserves raw evidence only; after complete closeout, stop at independent **`M3-CP4c-3-TB34-REV`**.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB31-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — the guard is retired and the authorized merge causes no downstream failure; `TraceArcDoesNotSeparateItsSides` appears in none of the 408 raw logs. |
| `M3-CP4c3-TB31-REV-CAND-02` | **CLOSED / RUNTIME PROVED** — 390/393/406/407 PASS with selector 408 byte-unchanged and nothing they legitimately own relaxed. |
| `M3-CP4c3-TB31-REV-CAND-03` | **CLOSED / IMPLEMENTED** — frontier evidence publishes at both annotation sites. Its **over-reach** is carried forward as `M3-CP4c3-TB32-REV-CAND-01` rather than left inside a closed candidate. |
| `M3-CP4c3-TB32-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — 366/367 publish `regionFrontierFailureStage=RegionCertification` and their detail bytes contain **no legacy `uncutFaceComponent*` fields**. |
| `M3-CP4c3-TB33-REV-CAND-01` | **IMPLEMENTED / COMPILE-PROVED / RUNTIME-UNADJUDICATED** — CB39 removed only the premature `current == start` rejection and published typed boundary-walk reasons. TB34 owns the frozen runtime falsifiers; no semantic closure before independent review. |
| `M3-CP4c3-TB32-REV-CAND-02` | **CLOSED / RUNTIME PROVED and vindicated on the same run** — the failure-detail digest table now separates runs; TB33's ledger hash collided with TB30's. |
| `M3-CP4c3-TB32-REV-CAND-03` | **CLOSED / RUNTIME PROVED** — the harness is turn-agnostic and `baseline-authority.txt` records the executing run. |
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
- **The ledger digest is a pass/fail fingerprint, not a semantic one.** It has now collided twice — TB32 with
  TB31, TB33 with TB30. Use the failure-detail digest table, artifact digests and censuses to distinguish runs.
- **A boundary walk may pass through its own start node.** Ten terminal slits guarantee it here; the certificate
  independently establishes all six faces as discs with residual 0.
- **Ownership is total and unique across all nine plan components.** Do not re-open it.
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

After the durable start-of-turn checklist, independent TB33-REV loads only the minimum current authority:

1. `ORIENTATION.md` — read first and update during this REVIEW turn.
2. **this file** — current frontier and candidate ownership.
3. `Architecture_M3_CP4c3_TB33_EXEC_Report.md` — immutable raw TB33 execution evidence.
4. `Architecture_M3_CP4c3_TB33_Independent_Review_Record.md` — **CU0–CU6**, the adjudication and the frozen CB39 scope.
5. `Architecture_M3_CP4c3_TB33_EXEC_Report.md` — **the current valid semantic runtime authority**, and the first report carrying verbatim failure transcription for every RED focused ordinal.
6. `Architecture_M3_CP4c3_TB33_Artifact_Only_Test_Benchmark_Plan.md` — the contract it executed.
7. `M3_CP4c_Frozen_Definitions.md` — **Part VIII operative**.
8. `Required_Green_Selector_Manifest.md`, `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`, `LESSONS.md`.
9. `M3_CP4c_Consolidated_Record.md` — folded-document resolver.
10. `tools/m3_cp4c3_artifact_only_harness.sh` — the instrument; read it rather than a summary of it.

Exact next is **`M3-CP4c-3-TB34-EXEC`**, artifact-only on immutable CB39 artifact `9997560649` / semantic source
`7711b9c2c20d284823911aa4ca067bd33244f4e6`, selector **409**. Execute the frozen TB34 plan without rebuild or
mutation, preserve raw facts only, then stop at independent **`M3-CP4c-3-TB34-REV`**. **Source-face ownership is
closed and unique across all nine components.**
