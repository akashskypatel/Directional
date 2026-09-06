# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-05** at `M3-CP4c-3-TB30-REV` closeout.

---

## 1. Where the checkpoint stands

**`M3-CP4c-3-TB30` is the current valid semantic runtime authority.** Selector **408**, **401 PASS / 7 RED**,
accepted **1–365 = 365/365**, RED `[366,367,368,369,370,374,398]`, on immutable CB35 package `9980764888` / source
`ab86747bdfdb94c7c383bf5d2893ced4207eb555`. Run/job `34008104497 / 101418934144`; result/log
`9981641004 / 9981641260`; ledger `974fed9db1958ee7eb07df77097544199deeb61d663b1d366a37b54d64feeab0`; every row
`selected=1`; all three byte+mode censuses equal pre/post.

CP4c-3 remains **OPEN**. Stable accounting **44 / 14 / 30**, debt **5**, packages **95**.

## 2. Ownership is total; the remaining frontier is the plan's partition

**The certifier half is closed.**

```
sourceFaceCount=300; established=300; unavailable=0; conflicting=0; conflictRowCount=0
```

Against TB25-R1's **74 established / 226 unavailable**. The post-correction uncut census contains **only arcs 20
and 24** (`0/0`) — arcs 14 and 22 are gone. **The question opened at TB19 is answered: certified source-face
ownership can be established, and it is established for every face.**

**The frozen rule was applied at one of its two sites.** 366/367 fail *identically* to pre-correction —
`sourceFace=10,79,151`, `uncutFaceComponent=0`, `faceCount=191`, `seedOrbits=[0,1,3]`, failing face-set digest
still **`17919102493633069558`**. `SurfaceCutGraph.cpp:549` now reads
`if (terminalSlit && !separatesCertifiedFaces)`; **`GlobalTopologyPlan.cpp:830` still reads
`if (is_terminal_slit(...))` unconditionally**, and that file contains no occurrence of `separatesCertifiedFaces`.
That skip governs `tracePieceCount`, `add_fragment_orbit` **and `traceTouchedEdges.insert(...)` for both
carriers** — and `traceTouchedEdges` is one of the three families in `componentBarriers`. **This is the correction
applied to one of two sites carrying the same guard, not a defect in the correction.**

**The divergence is measurable.** Corrected ordinal 390 emits **`censusCorrespondence=none`** and asserts the
published subset flag is false: the failing component was a strict subset of a certifier census component before
the correction and is a subset of none now. The two partitions **diverged further, not converged**.

**Ordinal 398 is no longer an ownership gate.** It fails at `fixture.cutGraph.has_value()` with
`prescribed sphere: NotProductionReady/CellularityNotEstablished` — ordinal 368's surface, owned by
`M3-CP4c2-TB-X2-CAND-04` and deferred. **The ownership frontier is 366 and 367 only.** 398 stays gating and must
not be re-scoped to exclude the sphere.

**CO6/CO8 discharged.** 390 and 404 returned to PASS with selector 408 unchanged, and the transcribed failing text
confirmed both TB29-REV diagnoses verbatim: 404 failed on `(Established) != (owner->status), actual: <00> vs <00>`
— the owners *were* established — and 390 failed comparing `3` against `1` across two partitions matched by index.

## 3. Exact next turn — `M3-CP4c-3-CB36`

Code + Build, runtime-free, GMP/GMPXX linked. **One change: the same frozen rule, at its second site.**

At `GlobalTopologyPlan.cpp:830`:

```cpp
const bool separatesCertifiedFaces = forwardOrbit != reverseOrbit;   // both in scope at :805–806
if (is_terminal_slit(*trace, segmentIndex) && !separatesCertifiedFaces) { … continue; }
```

**Not a new correction and not a re-opening** — the rule frozen at `M3-CP4c-3-TB28-INDEPENDENT-REVIEW` §4 and
runtime-proved at TB29, applied where the first application did not reach.

All three consequences are correct for a separating arc: the carriers become **barriers**; the face is labelled
with its two distinct orbits and leaves `unlabeledFaces`, matching the certifier already treating it as trace-cut;
and **`tracePieceCount` +1** keeps `expected = k + 1 = 2` consistent with two published fragment orbits. The
comment's premise — *"a terminal slit contributes zero to k"* — is true for a non-separating slit and false for a
separating one, which is exactly the distinction the guard draws. Arcs 20 and 24 are untouched.

**Accepted-prefix safety demonstrated by construction, not argued.**

**Falsification, stated before the build.** If 366/367 still fail with component 0, 191 faces and seeds `[0,1,3]`,
`M3-CP4c3-TB30-REV-CAND-01` is falsified. If `TraceCutFaceFragmentCountMismatch` appears, the `tracePieceCount`
premise is wrong and the change narrows to the `traceTouchedEdges` insertion alone.

**Prohibited:** partition unification (a `DEFN` question); re-scoping ordinal 398; touching 368/369/370/374; any new
ownership diagnostic; any accepted-identity or selector byte change.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB30-REV-CAND-01` | **NEW / ACTIVE / GATING / PRODUCT** — the frozen separating-arc rule is unapplied at `GlobalTopologyPlan.cpp:830`, so `traceTouchedEdges` still omits arcs 14 and 22's carriers and the plan's partition is unchanged. Owner: CQ7. |
| `M3-CP4c3-TB30-REV-CAND-02` | **NEW / ACTIVE / EVIDENCE SURFACE / NON-GATING** — the plan-side interior-arc census is a projection of the certifier's rows, so an arc that still cuts the plan's component but has left the certifier's uncut census is invisible to it. Not blocking CQ7. |
| `M3-CP4c3-TB27-REV-CAND-01` | **CORRECTED / RUNTIME-PROVED** — CB34's separating-arc barrier rule excludes the crossed faces and preserves equal-orbit slits; ordinal 408 passes on all three properties. |
| `M3-CP4c3-TB26-REV-CAND-02` | **RESOLVED / LAWFUL DOMAIN DIFFERENCE** — 76 and 97 belong to different partitions; TB27 additionally exposes 214-vs-191 faces and distinct digests. |
| `M3-CP4c3-TB27-REV-CAND-02` | **ACTIVE / ARCHITECTURAL / NON-GATING** — the plan excludes from its component domain exactly the faces carrying a direct certified read (`GlobalTopologyPlan.cpp:702`, `:750`), then fails to seed that component. |
| `M3-CP4c3-TB26-REV-CAND-04` | **PROMOTED / GATING / ACTIVE BLOCKING CAUSE** — the certifier partition moved with the correction and the plan's did not; ordinal 390 now reports `censusCorrespondence=none` and the failing component is a subset of no census component. Unification remains a **`DEFN`** question. |
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
- **Certified source-face ownership is TOTAL: 300 established / 0 unavailable / 0 conflicting.** The question
  opened at TB19 is answered.
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
3. `Architecture_M3_CP4c3_TB30_Independent_Review_Record.md` — **CQ0–CQ8**, the adjudication and the frozen CB36 scope.
4. `Architecture_M3_CP4c3_TB30_EXEC_Report.md` — **the current valid semantic runtime authority**.
5. `Architecture_M3_CP4c3_TB30_Artifact_Only_Test_Benchmark_Plan.md` — the contract it executed.
6. `tools/` artifact-only harness — the instrument; read it rather than a summary of it.
7. `M3_CP4c_Frozen_Definitions.md`, `Regression_Root_Cause_Tracker.md`, `Required_Green_Selector_Manifest.md`.
8. `M3_CP4c_Consolidated_Record.md` — folded-document resolver, including the CN7/CO7 census transcriptions.

Exact next is **`M3-CP4c-3-CB36`** — the same frozen guard at `GlobalTopologyPlan.cpp:830`, its second site.
**One change only**; no partition unification, no re-scoping of ordinal 398, no new ownership diagnostic.
