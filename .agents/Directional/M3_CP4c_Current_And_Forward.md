# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-08** at `M3-CP4c-3-TB41-EXEC` closeout.

---

## 1. Where the checkpoint stands

**`M3-CP4c-3-TB39` remains the current promoted semantic runtime authority.** Selector **409**,
**402 PASS / 7 RED**, **accepted 1–365 = 365/365**, package104.

**`M3-CP4c-3-TB41-EXEC` is mechanically valid, semantic-gate RED, and NOT promoted.** It executed immutable CB46
package106 / source `4cdffe5514ab9f747da38e74c57663ee8806efa6`, run `34256568679`, and returned
**398 PASS / 11 RED**, accepted **365/365**, RED
`[366,367,368,369,370,374,390,393,398,406,407]`.

311/314/356/357 recover under content-derived anchors; 312/315/409 remain PASS; 404/408 PASS and certified
ownership remains **300 / 0 / 0**. Protected 390/393/406/407 remain RED with
`regionFrontierComponentCount == 0`. 366/367 remain `RegionSourceFaceOwningFragmentMissing` and now publish the
named source face, `regionOwningFragmentOrbit`, and owner census required for review.

CP4c-3 remains **OPEN**. Stable accounting remains **47 events / 14 categories / 33 recurrences**, debt **5**,
packages **106** pending independent TB41 review.

## 2. TB41 mechanical evidence — accepted repair recovered, protected frontier correction did not

- **Accepted prefix restored on package106:** 365/365 PASS. The four TB40 `RP-05` oracle losses
  311/314/356/357 all PASS after CB46 replaced foreign ordinal comparison with canonical oriented boundary content.
- **The anchor census is non-vacuous:** 356/357 each emit four region rows with unique oriented anchors,
  `upstreamMatchCount=1`, matching region/certificate arc counts, disc=true and field=true. Orbits 0/1 may remain
  transposed because orbit ordinal is not the independent identity.
- **Binding falsifiers remain live:** 312/315/409 PASS.
- **Protected frontier surface remains broken:** 390/393/406/407 all RED at the same frozen
  `regionFrontierComponentCount > 0`, actual 0. CB46's terminal-enum decoupling was insufficient.
- **Missing-fragment measurement is sharper:** 366/367 publish `sourceFace=10,11,79`,
  `regionOwningFragmentOrbit=1` and 74 owner rows. The named face has 3 local fragments, 3 owners, expected 3,
  deficit 0, so the missing owning fragment is relational rather than a simple face-level count shortage.
- **Preserved controls:** 404/408 PASS; ownership 300/0/0; retired
  `RegionEulerCharacteristicNotOne`, `RegionInteriorDisconnected`, `TraceArcDoesNotSeparateItsSides`, and
  `UncutFaceComponentOrbitSeedNotUnique` are absent from all raw logs.
- **Carried:** 368/369/370/374/398 remain under their established separate owners.

TB41-EXEC records these facts without promotion or stable repricing. Independent TB41-REV owns adjudication.

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

## 3.6 TB38 refuted DEFN-R6.4, and the fault is the definition's

CB43 implemented Part X **exactly as frozen** — hoisted the sub-mesh accumulation, added the total fields, computed
χ from them, deleted **both** premise comments, did not repurpose `vertexCount`/`edgeCount`, did not touch region
construction, extended the semantic digest. **`DEFN-R6.4` is what cost the accepted prefix.**

### The measurement

```text
torus region (356/357/362/367, detail d976514d…):
    X = 24   E_one = 24   B_int = 1
    V_total/E_total/F = 24/48/24   → chiFull    = 0
    V_int  /E_int  /F =  0/23/24   → chiReduced = 1
mechanical region (TB37, ordinals 366/367):
    X = 36   E_one = 20   B_int = 12  → chiReduced = −3, chiFull = 1
```

Cross-checks close on the torus: `E_both = 48 − 24 = 24`, `E_int = 24 − 1 = 23`,
`2·E_both + E_one = 72 = 3F`.

| Fixture | `X − E_one − B_int` | χ_reduced | χ_full |
|---|---:|---:|---:|
| mechanical | **+4** | −3 | **1** |
| torus | **−1** | **1** | 0 |

> **Opposite signs. Neither formula is correct on both fixtures**, and DEFN-R6 had exactly one fixture's numbers.
> `LESSONS.md` 156.

### Why the reduced form wins on the torus

That region is 24 triangles, 24 vertices, 48 edges, 24 boundary edges and **zero interior vertices** — a
one-triangle-wide closed band, χ = 0, an **annulus**. It has exactly **one** interior barrier edge, and the reduced
form drops it. Removing one edge raises χ by 1, opening the annulus into a disc. **That is topologically what the
trace along that edge does** — so where the reduced form drops interior barrier edges it is modelling the cut
correctly, and where it additionally drops 16 vertices against 12 edges via `allOwned` on the mechanical fixture it
over-removes.

### The real defect is older than Part X

`certificate.faceCount = fragments.size()` is one entry per `region.sourceFaces` element, so **F counts whole faces
even where a trace splits one**. Meanwhile `V_int`'s `allOwned` exclusion only has meaning if that face is
**split**, and `E_int`'s barrier exclusion is the cut.

> **The certificate has always mixed the whole-face rounding with a partial model of the traced region.**

Part X resolved that mixture toward whole faces; TB38 refutes it. **The third complex — the traced/split region,
using the `fragmentCorners` ownership map DEFN-R4 established — has never been computed.** `DEFN-R6.4` is
**withdrawn**; **at TB38-REV, `DEFN-R6.3` became the live question**, exactly as Part X §9's own falsifier said it would be. TB39-REV now resolves that question toward the upstream actual-embedded face authority.

### The safeguard discharged over an empty set

DEFN-R6.7 required a per-region equivalence proof on every accepted fixture and explicitly refused the hand-wave
excuse. It produced **zero rows**: `emit_region_euler_certificate_diagnostics` is correctly placed before the χ
test but guarded by `if (diagnostics != nullptr)`, non-null only under `DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS=1`
(`GlobalTopologyPlan.cpp:86–89`, `:2460–2462`), which the accepted identities never set. The verifier reported
`accepted_euler_arithmetic_ok=true` over the empty table. **Part X named the check, its four identities and the
inadmissible excuse — and never said how many rows must exist.** `LESSONS.md` 155. It also blocks naming which
region drives ordinal 366's `RegionInteriorDisconnected`.

### Ordinal 366 is the predicted advance, not a regression

The mechanical region passed χ under the full count and certification reached a stage never previously executed.
Part X's falsifier called this "a new frontier, not a regression of this one". Ordinals 390/393/406/407 fail the
frozen `regionFrontierComponentCount > 0` assertion (`FieldAlignedCurveNetworkTests.cpp:4364`, actual 0) purely
because the plan now stops where no frontier annotation is attached — a **DEFN-R4 pattern recurrence**.

## 3.7 DEFN-R7 freezes the actual-embedded face binding

TB39 remains current semantic runtime authority: package104, selector409 **402 PASS / 7 RED**, accepted **365/365**,
RED `[366,367,368,369,370,374,398]`. DEFN-R7 is static and changes no runtime accounting: **46 / 14 / 32**, debt
**5**, packages **104**.

Part XI now supersedes DEFN-R6.3/R6.4 as the region-disc contract. Exact source inspection establishes the binding
constructively: `SurfaceCutGraph::certify_actual_embedded_graph()` and `GlobalTopologyPlan::canonical_candidate()`
both call `build_embedded_graph_topology(...)` on the same source/network/cut edges; A2a′ publishes one face
certificate per non-exterior orbit; A2b drafts one region per non-exterior orbit; `region_orbit()` re-derives the
current region's orbit by exact ordered boundary equality. The downstream region certificate therefore consumes the
matching upstream face certificate rather than re-proving topology over `region.sourceFaces`.

The current `sourceFacesConnected`, reduced/full V/E/F and Euler fields are removed from disc-topology authority.
`RegionEulerCharacteristicNotOne` and `RegionInteriorDisconnected` are retired as A2b disc-theorem producers; pinch
checking cannot override A2a′. Field regularity remains a separate A2b proof. Support arithmetic can survive only as
domain-explicit diagnostics. `regionChiFull` is frozen to mean whole-source-face Euler if retained; assigning the
reduced value is forbidden.

The checked candidate seam remains load-bearing: copied candidates must re-derive boundary→orbit→upstream-face
binding. This preserves 312/409. Ordinal315 moves its tamper target from proxy Euler to the consumed face binding;
311/314 and produced-witness proof helpers assert the exact 1:1 producer/consumer relation. Selector409 stays
byte-frozen.

**TB40-EXEC then exercised immutable package105.** That mechanically valid runtime was semantically RED: accepted 311/314/356/357 and protected 390/393/406/407 regressed; its independent TB40-REV subsequently established that 356/357 exposed a foreign-label oracle defect rather than a production binding defect. See §3.9.

## 3.8 Part XI-A — what the bound certificate actually proves

A verification pass over the delegated TB39-REV/DEFN-R7 work **upheld Part XI** and verified its structural claims
from source: both stages call `build_embedded_graph_topology(...)` with identical arguments
(`GlobalTopologyPlan.cpp:2500–2502`, `SurfaceCutGraph.cpp:863`), share `exterior_boundary_orbits(...)`
(`:869`, `:866`), and publish one face certificate per non-exterior orbit (`:883`) against one region draft per
non-exterior orbit (`:986`). **The 1:1 correspondence is real.**

**But the certificate carries no per-face evidence.**

- **A.1** — `discTopologyEstablished` is the **same value on every non-exterior face**: `discEmbeddingEstablished`,
  computed once at `SurfaceCutGraph.cpp:879` as
  `graphComponents == sourceComponentCount && exterior.size() == *boundaryLoops && graphEuler == sourceEuler`, and
  stamped identically at `:883`. **The binding stays sound** — that is the standard cellularity criterion, which
  *is* the theorem that every non-exterior face is a disc — but the authority is **complex-level**, and a face
  certificate is that authority restricted to one orbit, not an independent observation about it.
- **A.2** — `boundaryWalkCount` is the **literal `1U`**, so Part XI §2 item 6's `boundaryWalkCount == 1` conjunct
  **cannot fail** and is **withdrawn as evidence**. It is correct-by-construction (Part IX DEFN-R5.1), which is
  precisely why it carries no information. **The `LESSONS.md` 155 failure mode, inside the contract written to
  prevent it.**
- **A.3** — CB45 must publish the complex-level inputs **once per complex** rather than one bit per region; ordinal
  315's tamper target must **vary** (`orbit` or `boundaryArcCount`); and **a census whose every row carries the
  same value for the field under test is not a measurement.** `LESSONS.md` 157.

Part XI's decisions, consumer inventory, tamper contract and CB45 boundary are otherwise unchanged.

## 3.9 TB40 confirmed the binding and refuted the oracles

**The binding works.** TB40's census, on accepted ordinals 356/357, publishes 4 regions against 4 face
certificates:

```text
region 0: derivedOrbit=0  certificateOrbit=1  upstreamMatchCount=1
region 1: derivedOrbit=1  certificateOrbit=0  upstreamMatchCount=1
region 2: derivedOrbit=2  certificateOrbit=2  upstreamMatchCount=1
region 3: derivedOrbit=3  certificateOrbit=3  upstreamMatchCount=1
```

Everything DEFN-R7.1 asserts **holds**: `upstreamMatchCount == 1` on every row, the map injective, boundary-arc
counts matching, `discTopologyEstablished=true` and `fieldRegularity=true` throughout, and the complex row
published once per Part XI-A §A.3 — a **non-empty, non-uniform** census, so R7.7 is discharged.

**Only the orbit label disagrees.** `derivedOrbit` and `certificateOrbit` index **two different enumerations of
one partition**: production numbers orbits by **dart index** (`EmbeddedGraphTopology.cpp:1742`), inherited by both
A2a′ and A2b from the shared builder; the test oracle numbers them by **sorted-incidence order** —
`std::set<Incidence> all` (`tests/FieldAlignedCurveNetworkTests.cpp:1871`) iterated at `:1880`. Orbits 0 and 1
transpose.

**CB45's lookup is correct** (`faceCertificate.orbit == owningOrbit`, exactly one match, arc count, disc). The
defect is entirely in four re-aimed assertions — 311 at `:3254`, 314 via
`IndependentDiscProofClause::PublishedCertificate`, 356/357 in the census. **`ORIENTATION.md` §8 already carries
the rule: never match two partitions by index.** And the arc-count check did not catch it, because regions 0 and 1
have equal arc counts — **a control insensitive to the case under test is not a control.** `LESSONS.md` 158.

**The label cannot be checked independently.** `SurfaceCutGraphFaceCertificate` publishes only `orbit`,
`boundaryWalkCount`, `boundaryArcCount`, `discTopologyEstablished` (`SurfaceCutGraph.h:53–63`). An independent
consumer can verify the **bijection**; it cannot verify **which face** a certificate holds. Third way the bound
certificate carries less evidence than its name suggests. `M3-CP4c3-TB40-REV-CAND-01`.

**366/367 advanced** off both retired proxies to `RegionSourceFaceOwningFragmentMissing` at `RegionCertification` —
Part XI §10 prediction 4 confirmed, and **a new frontier, not a regression** (`M3-CP4c3-TB40-REV-CAND-02`).
**390/393/406/407 regress on `regionFrontierComponentCount == 0` for the second consecutive turn** — the DEFN-R4
pattern, now permanent because the codes that carried the annotation are retired by design.

**312, 409 and 315 PASS.** No sticky construction-time binding, and 315 tampers `actualEmbeddedFace.orbit`, a field
that **varies** — Part XI-A §A.3's tamper amendment was honoured.

## 3.10 TB41 executed package106; exact next turn — `M3-CP4c-3-TB41-REV`

CB46 package106 remains immutable at semantic source
`4cdffe5514ab9f747da38e74c57663ee8806efa6`, compile run/job `34253044050 / 102152247907`, result artifact
`10066942690`. TB41 authoritative runtime run/job `34256568679 / 102164030279` used selector409 unchanged and
produced **398 PASS / 11 RED**, accepted **365/365**.

The content-anchor correction is runtime-proved: 311/314/356/357 PASS and the 356/357 census is unique,
non-vacuous and content-derived. The production orbit-keyed binding remains intact and 312/315/409 PASS.

The frontier correction is runtime-refuted at its frozen protected controls: 390/393/406/407 still see
`regionFrontierComponentCount=0`. 366/367 publish the newly requested `regionOwningFragmentOrbit=1` against
`sourceFace=10,11,79`; that face reports 3/3 owners, so review must identify the absent relation rather than assume
an owner-count deficit. 404/408 PASS with ownership 300/0/0. Carried 368/369/370/374/398 remain untouched.

TB41 is mechanically valid but **semantic-gate RED / NOT promoted**. Stable accounting remains **47 / 14 / 33**,
debt **5**, packages **106** pending review. **TB39 remains current promoted runtime authority.**

Exact next is independent **`M3-CP4c-3-TB41-REV`**. No retry, compile, or semantic mutation occurs before review.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB40-EXEC-CAND-01` | **RUNTIME RECOVERED IN TB41 / STABLE RP-05 EVENT RETAINED** — 311/314/356/357 PASS under unique content-derived anchors; historical event remains counted. |
| `M3-CP4c3-TB40-EXEC-CAND-02` | **ACTIVE / TB41 RECONFIRMED / NON-STABLE GATING / REVIEW REQUIRED** — 390/393/406/407 remain RED at `regionFrontierComponentCount=0` after CB46's broader collection. |
| `M3-CP4c3-TB39-EXEC-CAND-01` | **TB41 RAW RECONFIRMED / REVIEW PENDING / NON-STABLE / RP-01** — 366/367 stay beyond retired proxies at `RegionSourceFaceOwningFragmentMissing`; TB41 now names source face/orbit and owner census. |
| `M3-CP4c3-TB38-EXEC-CAND-01` | **RESOLVED AT CURRENT RUNTIME / STABLE EVENT RETAINED** — CB44/TB39 recover the lost greens; the TB38 `RP-01` event remains in 46 / 14 / 32. |
| `M3-CP4c3-TB38-EXEC-CAND-02` | **CLOSED / RUNTIME-PROVED / NON-STABLE** — TB39 emits 513 non-empty rows and all five equations hold. Arithmetic proof is now non-vacuous; it does not select a semantic proxy. |
| `M3-CP4c3-TB31-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — the guard is retired and the authorized merge causes no downstream failure; `TraceArcDoesNotSeparateItsSides` appears in none of the 408 raw logs. |
| `M3-CP4c3-TB31-REV-CAND-02` | **CLOSED / RUNTIME PROVED** — 390/393/406/407 PASS with selector 408 byte-unchanged and nothing they legitimately own relaxed. |
| `M3-CP4c3-TB31-REV-CAND-03` | **CLOSED / IMPLEMENTED** — frontier evidence publishes at both annotation sites. Its **over-reach** is carried forward as `M3-CP4c3-TB32-REV-CAND-01` rather than left inside a closed candidate. |
| `M3-CP4c3-TB32-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — 366/367 publish `regionFrontierFailureStage=RegionCertification` and their detail bytes contain **no legacy `uncutFaceComponent*` fields**. |
| `M3-CP4c3-TB33-REV-CAND-01` | **RECONCILED** — recorded refuted at TB34-REV, which was right about the synthetic region and wrong as a general statement. Superseded by `M3-CP4c3-TB35-REV-CAND-01`. |
| `M3-CP4c3-TB34-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — the rejection is restored; ordinal 312 PASS and the accepted prefix is 365/365. |
| `M3-CP4c3-TB34-REV-CAND-02` | **CLOSED / RUNTIME PROVED** — ordinal 409 re-aimed at the constructible shared-start shape and PASSes its oracle. |
| `M3-CP4c3-TB34-REV-CAND-03` | **CLOSED** — open since TB34, now diagnosed to the cell: the region is a disc (`chiFull=1`) and the certificate drops 12 interior barrier edges against 16 vertices, netting −4. |
| `M3-CP4c3-TB35-REV-CAND-01` | **CLOSED / RUNTIME PROVED** — TB36 advanced 366/367 past `ClosedBeforeEnd` on `FaceWalkOrbit` while 312/409, which mutate a **copy** of a real region, stayed PASS on `Unguaranteed`. Part IX's derived relation is confirmed in both directions. |
| `M3-CP4c3-TB36-REV-CAND-01` | **REOPENED** — "the region is a disc" holds for the mechanical region under the **whole-face** reading only, and TB38 refutes that reading as a general criterion. Subsumed by `TB37-REV-CAND-01`. |
| `M3-CP4c3-TB37-REV-CAND-01` | **IMPLEMENTED IN CB45 / TB40 RAW FALSIFIER OBSERVED / REVIEW PENDING / RP-01** — 356/357 observe derived orbits 0/1 consuming certificate orbits 1/0; review owns classification/correction. |
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

- **An A2b plan region and its matching A2a′ certified face are the same topology object under the exact orbit
  binding frozen by DEFN-R7.** A2a′ and A2b rebuild the same deterministic actual embedded graph from the same
  source/network/cut edges; the region boundary equals one non-exterior face-walk orbit and consumes that orbit's
  `SurfaceCutGraphFaceCertificate`. `region.sourceFaces` is support/provenance and may not re-certify the face.
  `RegionBoundaryNotSingleWalk` remains a synthetic/current-candidate binding validator; region-support Euler is not
  the disc theorem.
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

After the durable start-of-turn checklist, TB41-REV loads only the minimum authority:

1. `ORIENTATION.md` — read first; REVIEW must update it before closeout.
2. **this file** — §3.9 (TB40 binding adjudication) and §3.10 (TB41 runtime result / exact next).
3. `Architecture_M3_CP4c3_TB41_EXEC_Report.md` — exact package106 runtime evidence.
4. `Architecture_M3_CP4c3_CB46_Code_Build_Report.md` — package106 semantic/build provenance.
5. `Architecture_M3_CP4c3_TB41_Artifact_Only_Test_Benchmark_Plan.md` — frozen expectations TB41 measured.
6. `Architecture_M3_CP4c3_TB40_Independent_Review_Record.md` — EB0–EB7 owner/falsifier context.
7. `M3_CP4c_Frozen_Definitions.md` — Part XI operative, amended by Part XI-A.
8. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`, `LESSONS.md` 155/157/158.

Exact next is independent **`M3-CP4c-3-TB41-REV`**. It must not retry TB41 or compile first. It owns the protected
390/393/406/407 adjudication, the 366/367 fragment/orbit relation, promotion/accounting, review-owned orientation
updates, mandatory document consolidation, and the next bounded corrective plan.
