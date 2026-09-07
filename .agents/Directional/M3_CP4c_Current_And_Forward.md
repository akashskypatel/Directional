# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-07** at `M3-CP4c-3-TB37-EXEC` closeout.

---

## 1. Where the checkpoint stands

**`M3-CP4c-3-TB36` is the current valid semantic runtime authority**, promoted at TB36-REV. Selector **409**,
**402 PASS / 7 RED**, **accepted 1–365 = 365/365**, RED `[366,367,368,369,370,374,398]`, on immutable CB41 package
`10029250324` / source `14aa1368523580444929bc65cab0b65449240ec2`. Run `34153857590`; 409 rows, every row
`selected=1`, zero timeouts, all three censuses identical pre/post, failure-detail digest table published,
`SHA256SUMS` 28/28, executables `0755`.

Certified ownership remains **300 / 0 / 0**. CP4c-3 remains **OPEN**. Stable accounting **45 events / 14 categories
/ 31 recurrences** — **no new event**, because no accepted green was lost — debt **5**, packages **102**.

**CB42 is compile-green / runtime-free.** Package102 artifact `10032277517` was built from exact semantic source
`89cbf1ff5e2b064a0a4652c6cdb9e32b6f4b001d` in run/job `34159743881 / 101858898702`; result SHA-256
`ca33be401dba11b1007258bd127948e03168cf2cd42231307d54d506028dc5ee`. It adds only the CY6 source-submesh
measurement fields. TB37-EXEC has now executed that immutable package and is mechanically valid; independent review is next.

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

## 3.1 What TB36 settled — the provenance contract works, in both directions

Ordinals 366/367 **advanced past** `ClosedBeforeEnd`, publishing `regionBoundaryProvenance=FaceWalkOrbit`. CX8's
falsifier was that a stop there would refute DEFN-R5.2/R5.3; it did not stop there, so **the derived provenance
relation is runtime confirmed**.

The complementary negative held too. Ordinals **312 and 409 stayed PASS**, and both build their boundary by taking
`plan.validation_candidate()` — a **copy of a real plan region** — and then mutating it
(`tests/FieldAlignedCurveNetworkTests.cpp:3247–3253`, `:3276–3279`). The mutated boundary matches no authoritative
orbit, resolves to `Unguaranteed`, and is still rejected. **A stored construction-time flag would have survived
that copy and suppressed both rejections** — so this is the runtime disproof of the competing DEFN-R5 draft, exactly
as Part IX-A §A.1 predicted. `M3-CP4c3-TB35-REV-CAND-01` is **CLOSED / RUNTIME PROVED**.

## 3.2 What TB36 did not settle, and why the frozen measurement could not

DEFN-R5.5 froze a census to test the premise at `GlobalTopologyPlan.cpp:2099–2100` — that the boundary terms cancel
from χ. **The census was implemented in the wrong domain.**

- χ counts a **sub-mesh of whole source triangles**: faces are partitioned one-per-region (`:1400–1433`),
  `edgeCount` counts **source edges** (`:1847–1860`), `interiorVertices` holds **source vertices** (`:2048–2094`).
- CX5 counts the **network graph**: `std::set<authority::NetworkArcId>` and `std::set<authority::NetworkNodeId>`
  (`:2122–2123`), and a network arc may be a **trace segment** — a chord through face interiors that is not a
  source edge at all (`:1905`, `:1934`, `:1951`).

So `regionBoundaryDistinctArcCount = regionBoundaryDistinctNodeCount = 22` is a fact about a **different curve**,
and it is not evidence that `V_boundary == E_boundary`. Two further caveats: `regionBoundaryNodeOccurrenceCount` is
assigned the same expression as `regionBoundaryArcOccurrenceCount` (`:2142` vs `:2120`), so eight fields carry at
most six independent values; and 366/367 share one failure-detail digest on `regionBoundaryOrbit=0` — **one datum,
two witnesses**. `LESSONS.md` 150.

## 3.3 The identity that decides the frontier

Two things do follow from the census.

**The boundary's shape is now measured.** 40 arc occurrences over 22 distinct arcs with 22 distinct nodes gives
`V − E = 0`, so the network boundary is connected with exactly one independent cycle: a **4-arc cycle carrying an
18-arc tree** (`18·2 + 4·1 = 40`), matching `regionBoundaryRepeatedNodeOccurrenceCount=18`. That is the bridge and
terminal-slit structure Part IX predicted, now measured.

**And the open question reduces to one integer.** Every source face is a triangle
(`EmbeddedGraphTopology.h:25–32`), so 250 faces give exactly **750 face-edge incidences**. With `B_int` = barrier
edges having **both** incident faces in the region (skipped at `:1848–1850`) and `X` = sub-mesh vertices excluded
from `interiorVertices`:

> **χ_true = X + B_int − 47.**

The published `χ = 100 − 353 + 250 = −3` follows from `X + B_int = 44`, in which case the cancellation premise
holds and **the region is genuinely not a disc**. A disc requires `X + B_int = 48`, in which case **the premise is
false by exactly 4**. **These are mutually exclusive: the certificate cannot both cancel its boundary terms and
certify discs.** Neither term is published, and both sit in loops that already exist.

The first place to look is `B_int`: a barrier edge with both faces inside the region is **interior** to the
sub-mesh, yet `:1848–1850` drops it from `E_int` and `:1919`/`:1925`/`:1947` push its endpoints into
`boundaryVertices`, which `:2048–2051` then excludes from `V_int`. A terminal slit is exactly such an edge, and
this fixture publishes ten. **This review names that suspicion; it does not conclude it.**

## 3.4 TB37 measures D=48; independent review owns the certificate frontier

TB37 executed package102 artifact-only and reproduced TB36 exactly: **402 PASS / 7 RED**, accepted **365/365**,
RED `[366,367,368,369,370,374,398]`, protected 312/390/393/404/406/407/408/409 PASS, ownership **300/0/0**, zero
timeouts, and identical package/source/execution-view censuses. Because EXEC does not promote semantic authority,
TB36 remains current valid runtime authority until independent review.

The source-submesh measure is complete and internally consistent on byte-identical 366/367:

> `X = 36 = 0 + 20 + 16`
>
> `B_int = 12`
>
> `V_total - E_total + F = 136 - 385 + 250 = 1`
>
> `X + B_int - 47 = 36 + 12 - 47 = 1`
>
> **`D = X + B_int = 48`.**

The old reduced certificate still publishes `100 - 353 + 250 = -3`. Under the discriminator frozen before
execution, **D=48 selects the certificate-arithmetic/cancellation frontier**; it does not authorize a fix.
`M3-CP4c-3-TB37-REV` must independently adjudicate the evidence and decide package102 promotion before any Code +
Build correction is planned.

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
| `M3-CP4c3-TB34-REV-CAND-03` | **ACTIVE / RE-SCOPED** — the CX5 census was taken over the network graph, not the source sub-mesh χ counts, so it does not bear on the cancellation premise. Superseded as the owning question by `M3-CP4c3-TB36-REV-CAND-01`. |
| `M3-CP4c3-TB35-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — TB36 advanced 366/367 past `ClosedBeforeEnd` on `FaceWalkOrbit` while 312/409, which mutate a **copy** of a real region, stayed PASS on `Unguaranteed`. Part IX's derived relation is confirmed in both directions. |
| `M3-CP4c3-TB36-REV-CAND-01` | **ACTIVE / GATING / D=48 RAW-MEASURED** — TB37 publishes `X=36`, `B_int=12`, `chiFull=1`; the frozen discriminator selects the certificate-arithmetic/cancellation frontier. Independent TB37-REV owns adjudication and correction remains unassigned until review. |
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

After the durable start-of-turn checklist, independent TB37-REV loads only the minimum authority:

1. `ORIENTATION.md` — read first and update during REVIEW.
2. `Architecture_M3_CP4c3_TB37_EXEC_Report.md` — exact raw package102 execution evidence.
3. `Architecture_M3_CP4c3_TB37_Artifact_Only_Test_Benchmark_Plan.md` — frozen D discriminator.
4. `Architecture_M3_CP4c3_TB36_Independent_Review_Record.md` — source-domain derivation under review.
5. **this file** — §3.2–§3.4 preserve the frontier history and D=48 result.
6. `Regression_Root_Cause_Tracker.md`, selector manifest, `TODO.md`, `CHANGELOG.md`, `LESSONS.md` 148/150.
7. `CLEAN_UP_POLICY.md` — REVIEW document consolidation is mandatory.

Exact next is **`M3-CP4c-3-TB37-REV`**, independent/static. It may adjudicate and plan only; it must not execute
runtime/benchmarks, configure/compile, mutate implementation/tests/fixtures/selector, or implement the correction.
