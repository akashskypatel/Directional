# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-07** at `M3-CP4c-3-CB41` closeout.

---

## 1. Where the checkpoint stands

**`M3-CP4c-3-TB35` is the current valid semantic runtime authority.** Selector **409**, **402 PASS / 7 RED**,
**accepted 1–365 = 365/365**, RED `[366,367,368,369,370,374,398]`, on immutable CB40 package `10003613409` /
source `23a753a83f0eda0447172ce96bcd3180bf95ae8a`. Run `34084955954`; 409 rows, every row `selected=1`, zero
timeouts, all three byte+mode censuses identical pre/post.

Certified ownership remains **300 / 0 / 0**. CP4c-3 remains **OPEN**. Stable accounting **45 events / 14 categories
/ 31 recurrences** — the TB34 event stands — debt **5**. CB41 is compile-green and freezes **package101** artifact
`10029250324` from exact source `14aa1368523580444929bc65cab0b65449240ec2`; TB35 remains runtime authority
until TB36 is independently adjudicated.

## 2. The accepted prefix is restored, and both CV measures are discharged

- **CV2 — ordinal 312 PASS, prefix 365/365.** The rejection is restored **with** its typed reason, so the accepted
  witness is satisfied *and* `regionBoundaryWalkReason=ClosedBeforeEnd` is named.
- **CV3 — ordinal 409 PASS.** Its re-aimed body requires `RegionBoundaryNotSingleWalk`, typed `ClosedBeforeEnd`,
  the second-loop first arc locus and the projected reason. Its PASS **proves the shared-start multi-walk shape is
  constructible** — the reachable negative.
- **CV6's falsifier is settled:** 366/367 report `ClosedBeforeEnd`, **not** `ArcChainBroken`.
- 390/393/404/406/407/408 PASS; retired-code silence held; ownership published.

**Repairing the regression does not erase it.** The TB34 stable event stays on the books.

## 3. The frontier, proved from source

`build_regions` creates each draft as `RegionDraft{orbit, walk.orbits[orbit]}` (`GlobalTopologyPlan.cpp:986`),
moves that boundary into the region unmodified (`:1450`), and elsewhere *identifies* a region by
`walk.orbits[orbit] == region.boundary` (`:379`). The orbit itself is built by following `successor[current]` until
it returns to `start`, then `canonicalize_cycle`, which only **rotates**
(`EmbeddedGraphTopology.cpp:1746–1774`).

**So a plan region's boundary is an ordered single closed walk by construction, and may revisit nodes** — which
bridges, cut vertices and this fixture's ten terminal slits routinely produce.

- **On a plan region, `ClosedBeforeEnd` is always a false rejection.**
- **On a synthetic boundary — ordinals 312 and 409 — it is the only check that catches a genuine multi-walk.**
- **The defect is that `validate_single_boundary_walk` cannot see provenance.** `ArcChainBroken` and
  `WalkNotClosed` are unaffected and stay in force for all boundaries.

This **reconciles** TB33-REV and TB34-REV: each was right about the input it read, and nothing recorded which
guarantee a boundary carried.

**Still unknown:** `RegionEulerCharacteristicNotOne`, seen at TB34 once the rejection was bypassed, is a
**separate** question — χ over a walk that may revisit nodes — and this review does not decide it.

## 3.1 CB41 complete; package101 frozen; exact next turn — `M3-CP4c-3-TB36-EXEC`

**Part IX is implemented and compile-proved, but not yet runtime-adjudicated.** CB41 source
`14aa1368523580444929bc65cab0b65449240ec2` derives `FaceWalkOrbit` only from the exact current ordered
`region.boundary == walk.orbits[orbit]` relation, scopes only `ClosedBeforeEnd` to unguaranteed boundaries, keeps
`ArcChainBroken` / `WalkNotClosed` universal, and leaves the missing-orbit rejection after structural validation.

CB41 also publishes the frozen measurement-only Euler evidence on `RegionEulerCharacteristicNotOne`: provenance,
owning orbit, arc occurrence/distinct counts, node occurrence/distinct/repeat counts, start revisits before end,
and existing V/E/F/χ. The Euler formula and disc acceptance are unchanged.

**Protected source audit:** selector409 remains
`eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`; ordinal312 and ordinal409 exact test
blocks are byte-identical to the frozen source (`94724bef...0847` and `ea574dab...004a`).

**Compile/package authority:** run/job `34150409018 / 101831355500` succeeded through the durable GMP/GMPXX
compile workflow against exact source `14aa1368523580444929bc65cab0b65449240ec2`. Preflight `directional_core`
and the complete eight-target compile returned 0; all source-status checks were clean; package `SHA256SUMS` is
28/28 PASS; `runtimeExecution=false`. Immutable package101 artifact `10029250324` / `cb41-result-34150409018`
has provider ZIP SHA-256 `9af49dd6dd0278225e8373b76e68f74c2ec263129f2c18ed2229135d0c6a5c55`; compile-log artifact
`10029250820` has SHA-256 `8611ad75e51b037244f179739559f6cd2d42eb825543d143ebe5a619306f6e80`.

The earlier run `34150366902` is invalid orchestration provenance only: its temporary caller permission ceiling was
too narrow for a statically referenced nested observer job, so it ended `startup_failure` before compile/runtime
evidence. Only the temporary caller ceiling was corrected; no reusable workflow permission or implementation was
changed.

`M3-CP4c3-TB35-REV-CAND-01` is **IMPLEMENTED / GATING / RUNTIME VERDICT OWED**.
`M3-CP4c3-TB34-REV-CAND-03` remains **ACTIVE / GATING / MEASUREMENT ARMED**: CB41 now exposes the exact Euler
multiplicity evidence, but only TB36 plus independent review may adjudicate it.

### Exact next

Run **`M3-CP4c-3-TB36-EXEC`** on immutable artifact `10029250324` under
`Architecture_M3_CP4c3_TB36_Artifact_Only_Test_Benchmark_Plan.md`:

- accepted **1-365 = 365/365 PASS**;
- 312/409 and 390/393/404/406/407/408 PASS;
- 368/369/370/374/398 remain carried RED;
- ownership remains 300/0/0 and retired-code silence holds;
- 366/367 still failing `ClosedBeforeEnd` falsifies Part IX;
- 366/367 advancing to Euler confirms only the provenance correction and must publish every CX5 field.

**Must not:** configure, compile, relink, repair/mutate package/source/tests/fixtures/selector, execute benchmarks,
or implement an Euler correction inside TB36. Preserve raw evidence and stop at independent TB36-REV on semantic
RED.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB31-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — the guard is retired and the authorized merge causes no downstream failure; `TraceArcDoesNotSeparateItsSides` appears in none of the 408 raw logs. |
| `M3-CP4c3-TB31-REV-CAND-02` | **CLOSED / RUNTIME PROVED** — 390/393/406/407 PASS with selector 408 byte-unchanged and nothing they legitimately own relaxed. |
| `M3-CP4c3-TB31-REV-CAND-03` | **CLOSED / IMPLEMENTED** — frontier evidence publishes at both annotation sites. Its **over-reach** is carried forward as `M3-CP4c3-TB32-REV-CAND-01` rather than left inside a closed candidate. |
| `M3-CP4c3-TB32-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — 366/367 publish `regionFrontierFailureStage=RegionCertification` and their detail bytes contain **no legacy `uncutFaceComponent*` fields**. |
| `M3-CP4c3-TB33-REV-CAND-01` | **RECONCILED** — recorded refuted at TB34-REV, which was right about the synthetic region and wrong as a general statement. Superseded by `M3-CP4c3-TB35-REV-CAND-01`. |
| `M3-CP4c3-TB34-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — the rejection is restored; ordinal 312 PASS and the accepted prefix is 365/365. |
| `M3-CP4c3-TB34-REV-CAND-02` | **CLOSED / RUNTIME PROVED** — ordinal 409 re-aimed at the constructible shared-start shape and PASSes its oracle. |
| `M3-CP4c3-TB34-REV-CAND-03` | **ACTIVE / GATING / MEASUREMENT ARMED / RUNTIME VERDICT OWED** — CB41 package101 publishes the frozen Euler multiplicity evidence without changing χ. Owner: TB36-EXEC → TB36-REV. |
| `M3-CP4c3-TB35-REV-CAND-01` | **IMPLEMENTED / GATING / RUNTIME VERDICT OWED** — exact derived `FaceWalkOrbit` provenance and reason scope compile in package101. Owner: TB36-EXEC → TB36-REV. |
| `M3-CP4c3-TB34-EXEC-CAND-01` | **NEW / HARD-FALSIFIER INTAKE / NON-STABLE** — accepted-prefix ordinal 312 regresses to RED: expected `RegionBoundaryNotSingleWalk`, observed `RotationSystemInconsistent`, no arc locus. Review owns product/test classification. |
| `M3-CP4c3-TB34-EXEC-CAND-02` | **NEW / HARD-FALSIFIER INTAKE / NON-STABLE** — new gating ordinal 409 is RED before its intended `ArcChainBroken` oracle because `disjointRegions` construction fails. Review owns fixture/product discrimination; EXEC may not weaken the gate. |
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

- **A certified face of the embedded graph and a plan region are different objects.** The certificate's disc
  topology, `F`, `componentCount`, and Euler residual are claims about certified faces and license **no**
  conclusion about whether a plan region is a disc. `RegionEulerCharacteristicNotOne` and
  `RegionBoundaryNotSingleWalk` are the region-level authorities for that question.
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

After the durable start-of-turn checklist, TB36-EXEC loads only the minimum artifact-only Test + Benchmark authority:

1. `ORIENTATION.md` — read first.
2. **this file** — current runtime/candidate state and exact scope.
3. `Architecture_M3_CP4c3_TB36_Artifact_Only_Test_Benchmark_Plan.md` — **execution authority**.
4. `Architecture_M3_CP4c3_CB41_Code_Build_Report.md` — exact package101 provenance.
5. `M3_CP4c_Frozen_Definitions.md` — Part IX / CX0-CX8 falsifiers.
6. `Architecture_M3_CP4c3_TB35_Independent_Review_Record.md` and `Architecture_M3_CP4c3_TB35_EXEC_Report.md` —
   current semantic runtime background only.
7. `Required_Green_Selector_Manifest.md`, `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`, `LESSONS.md`.
8. `GitHub_Workflow_Policy.md`, `RETENTION_POLICY.md`, `CLEAN_UP_POLICY.md`, `TOOL_USE_CONSERVATION_POLICY.md`.

Exact next is **`M3-CP4c-3-TB36-EXEC`**, artifact-only Test + Benchmark on package101 artifact `10029250324`.
Do not rebuild, repair or mutate source/package/tests/fixtures/selector; do not execute benchmarks. Preserve the full
selector409 raw evidence and stop at independent **`M3-CP4c-3-TB36-REV`** if semantic RED remains.
