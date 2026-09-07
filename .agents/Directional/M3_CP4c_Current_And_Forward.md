# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-07** at `M3-CP4c-3-DEFN-R6` closeout.

---

## 1. Where the checkpoint stands

**`M3-CP4c-3-TB37` is the current valid semantic runtime authority**, promoted at TB37-REV. Selector **409**,
**402 PASS / 7 RED**, **accepted 1–365 = 365/365**, RED `[366,367,368,369,370,374,398]`, on immutable CB42 package
`10032277517` / source `89cbf1ff5e2b064a0a4652c6cdb9e32b6f4b001d`. Run `34161464783`; 409 rows, every row
`selected=1`, zero timeouts, all three censuses identical pre/post, `SHA256SUMS` 28/28, executables `0755`.

Certified ownership remains **300 / 0 / 0**. CP4c-3 remains **OPEN**. Stable accounting **45 events / 14 categories
/ 31 recurrences** — **no new event**, no accepted green was lost — debt **5**, packages **102**.

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

## 3.4 TB37 decided it — the region is a disc and the certificate's arithmetic is wrong by 4

TB36-REV reduced the frontier to one integer. CB42 published the terms; TB37 measured them.

```text
X (excluded vertices)          = 36  =  0 mesh-boundary + 20 boundaryVertices + 16 allOwned
B_int (interior barrier edges) = 12
sub-mesh boundary              = 20 edges / 20 vertices
V_total / E_total / F / chiFull = 136 / 385 / 250 / 1
reduced certificate             = 100 / 353 / 250 / −3
```

**`D = X + B_int = 48`**, so `χ_true = 48 − 47 = 1` — and the direct count agrees, `136 − 385 + 250 = 1`. Every
cross-check closes, **including two TB36-REV predicted before the numbers existed**: `E_one = 44 − 2·B_int = 20`
matches `regionSubmeshBoundaryEdgeCount`, and `2(E_int + B_int) + E_one = 750 = 3F`.

**The region is a genuine triangulated disc, and the certificate rejects it.**

### The diagnosis is sharper than "the premise is false"

> `(V_total − V_int) − (E_total − E_int) = 36 − 32 = (20 − 20) + (16 − 12) = 0 + 4`

**The cancellation premise is correct about the actual boundary** — the sub-mesh boundary proper cancels, 20
against 20, exactly as `GlobalTopologyPlan.cpp:2097–2098` claims. The whole error is the residual: the certificate
additionally drops **12 interior barrier edges** from `E_int` (`:1848–1850`) and **16 further vertices** from
`V_int` via `allOwned`, and those exclusions do not balance.

**A barrier edge with both incident faces in the region is an interior cell**, not a boundary one — a terminal
slit is precisely that, and this fixture publishes ten. The defect is that the certificate's notion of "boundary"
is the **network's barrier set** rather than the sub-mesh's actual boundary. `LESSONS.md` 153.

This closes `M3-CP4c3-TB34-REV-CAND-03`, open since TB34, and decides `M3-CP4c3-TB36-REV-CAND-01`.

### What it does not settle

Both formulas count the **whole-face** sub-mesh (`:2168–2177`), while the region the plan built is bounded by a
network walk that includes **trace chords through face interiors**; a trace-cut face is assigned wholly to one
region (`:1405`, `:1432`). So `chiFull = 1` certifies the **rounding**, not the traced region. The correction is
still bounded — `V_int`, `E_int` and `F` are already whole-face quantities, so it fixes arithmetic over the object
already counted — but that must be stated normatively. New candidate `M3-CP4c3-TB37-REV-CAND-01` (ACTIVE /
ARCHITECTURAL, non-blocking).

## 3.5 What DEFN-R6 froze — Part X

Part X supersedes **Part IX §5 only**; every other Part IX clause and all of Part IX-A stand.

- **R6.1 — the cancellation premise is NOT the defect.** The sub-mesh boundary cancels exactly, 20 edges against
  20 vertices. **Part IX-A §A.2's implication that the premise itself fails is withdrawn**, along with the DEFN-R5
  draft claim that a pinch stops the boundary terms cancelling. A correction aimed at the premise would have been
  aimed at the wrong thing — worth recording, because two turns nearly were.
- **R6.2 — interior barrier edges are interior cells.** A mandatory or cut edge with **both** incident faces in
  the region is an interior cell of the certified complex. Dropping 12 of them from `E_int` (`:1848–1850`) against
  16 vertices from `V_int` via `allOwned` (`:2048–2094`) is the whole 4-point error. A terminal slit is exactly
  such an edge; this fixture has ten.
- **R6.3 — the certified complex is the whole-face source sub-mesh** of `region.sourceFaces` (faces partitioned,
  `:1405`/`:1432`). **`χ = 1` is a claim about that rounding**, not about the traced region, whose boundary
  includes trace chords through face interiors. Non-blocking, stated so it cannot be silently assumed.
- **R6.4 — the criterion is `χ = V_total − E_total + F = 1`**; the reduced form is withdrawn. For a connected
  compact surface with boundary `χ = 2 − 2g − b`, so `χ = 1` with `sourceFacesConnected` and
  `boundaryWalkCount == 1` is a disc. `proves_disc_topology()` keeps its shape.
- **R6.5 — the withdrawn premise has TWO sites.** `GlobalTopologyPlan.cpp:2097–2098` **and**
  `include/directional/geometry/GlobalTopologyPlan.h:91–93`, whose `vertexCount` comment repeats it verbatim.
  TB37-REV named only the first; the header site was found by this turn. Deleting one re-seeds the assumption —
  which is how it survived from TB34 to TB37. `LESSONS.md` 154.
- **R6.6 — do not repurpose `vertexCount`/`edgeCount`.** `edgeCount` is incremented in the loop that builds
  `neighbors` for the connectivity BFS behind `RegionInteriorDisconnected` (`:1847–1860`, BFS `:1862–1873`, check
  `:1874`). The sub-mesh totals are **new fields**, so the published triple explains the published χ.
- **R6.7 — the equivalence carries a proof obligation.** Reduced and full agree iff **`X = E_one + B_int`**; the
  measured region violates it by 4 (`36` vs `20 + 12`). **CB43 may not assume it anywhere.**

## 3.6 Exact next turn — `M3-CP4c-3-CB43`

**Code + Build**, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`, under **CZ7.1–CZ7.7**.

- **CZ7.1** — hoist CB42's `submeshVertices` / `submeshEdges` accumulation **out of the
  `if (certificate.eulerCharacteristic != 1)` failure branch**, where it currently sits, so the criterion can use
  it. Code motion with no behaviour of its own.
- **CZ7.2** — add `V_total` / `E_total` certificate fields per R6.6 and compute `eulerCharacteristic` from them.
- **CZ7.3** — delete **both** premise comments per R6.5, replacing them with what is actually counted.
- **CZ7.4** — **discharge R6.7 per region on every accepted fixture.** Publish `X`, `E_one`, `B_int` and the
  reduced-versus-full difference, and show either the identity or an unchanged verdict. *"Accepted fixtures have
  no slits"* is an explanation, not a discharge.
- **CZ7.5** — state the certificate-ordering and plan-hash decision explicitly. New fields change
  `operator<=>`, and `global_topology_plan_hash` consumes the certificate (`:2386–2400`). **Confirm by grep** that
  no identity pins a hash literal; note the hash changes regardless, since corrected regions publish a different
  `eulerCharacteristic`.
- **CZ7.6** — ordinals **312/409** byte-identical, selector **409** byte-frozen, accepted **1–365** untouched, no
  work on 368/369/370/374/398, and **region construction unchanged**.
- **CZ7.7** — `M3-CP4c-3-TB38` re-executes.

**Falsifiers, stated before the build.** Accepted prefix **365/365** and ordinals **312/409 PASS** are stop
conditions. The risk is **not** a direct assertion — no test asserts `RegionEulerCharacteristicNotOne` — it is that
a region which currently fails Euler now passes and reaches stages never executed on it. If 366/367 clear region
certification, R6.1–R6.4 are confirmed and **a new failure at a later stage is a new frontier, not a regression**.
If 366/367 still fail Euler under the full count, measurement and implementation disagree and the turn halts. If
any accepted-fixture region changes verdict, R6.7 is refuted there. If a region elsewhere newly fails Euler, R6.3's
counted complex becomes the live question.

**Must not:** correct region construction; change ownership or the whole-face rounding; repurpose `vertexCount` or
`edgeCount`; weaken `proves_disc_topology()`, `sourceFacesConnected` or `boundaryWalkCount`; force χ to 1 or
special-case a fixture; delete only one premise comment; change any accepted identity or selector byte.

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
| `M3-CP4c3-TB34-REV-CAND-03` | **CLOSED** — open since TB34, now diagnosed to the cell: the region is a disc (`chiFull=1`) and the certificate drops 12 interior barrier edges against 16 vertices, netting −4. |
| `M3-CP4c3-TB35-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — TB36 advanced 366/367 past `ClosedBeforeEnd` on `FaceWalkOrbit` while 312/409, which mutate a **copy** of a real region, stayed PASS on `Unguaranteed`. Part IX's derived relation is confirmed in both directions. |
| `M3-CP4c3-TB36-REV-CAND-01` | **DECIDED** — `D = X + B_int = 48`, `chiFull = 1`. The two claims were mutually exclusive and the measurement chose: the region is a disc and the certificate's arithmetic is wrong by exactly 4. Correction owned by `M3-CP4c-3-DEFN-R6` (Part X), then `CB43`. |
| `M3-CP4c3-TB37-REV-CAND-01` | **ACTIVE / ARCHITECTURAL / NON-BLOCKING** — the certified object is the region **rounded to whole faces**, not the traced region: both formulas count `region.sourceFaces` while the region's boundary includes trace chords through face interiors. Must be stated in Part X before it is silently assumed. |
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

After the durable start-of-turn checklist, CB43 loads only the minimum authority:

1. `ORIENTATION.md` — read first.
2. **this file** — §3.4 (the measurement and finding), §3.5 (Part X), §3.6 (the frozen measures).
3. `M3_CP4c_Frozen_Definitions.md` — **Part X operative for the Euler criterion**; Part IX (amended by Part IX-A)
   operative for everything else. Part X supersedes **Part IX §5 only**.
4. `Architecture_M3_CP4c3_TB37_Independent_Review_Record.md` — **CZ0–CZ6**, the evidence and the checks.
5. `Regression_Root_Cause_Tracker.md` — the DEFN-R6 section and the authoritative next step.
6. `Required_Green_Selector_Manifest.md`, `TODO.md`, `CHANGELOG.md`, `LESSONS.md` (**53, 144, 153, 154** govern).
7. `AGENT_POLICY.md`, `GitHub_Workflow_Policy.md` — CB mechanics.

Exact next is **`M3-CP4c-3-CB43`** under **CZ7.1–CZ7.7**. **Accepted prefix 365/365, and ordinals 312 and 409
PASS, are stop conditions**, and DEFN-R6.7's per-region equivalence must be **proved, not assumed**.
