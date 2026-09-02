# Directional — Orientation

> **Current CP4c-3 runtime authority (2026-09-02):** TB11 on immutable package 81 / selector 377 is 369 PASS / 8 RED with accepted prefix 365/365. First red 366 is now `RotationRayOrderKeyCollision` at source vertex 47, certification attempt 0 / zero cut edges, localized to post-sort trace-key collision validation in `build_rotation_system`. Exact next is independent `M3-CP4c-3-TB11-REV`; no semantic fix is authorized yet.


## DURABLE — DO NOT DELETE, AND UPDATE AT EVERY REVIEW TURN

**This document is durable project authority.** It may be corrected or extended. It must **not** be deleted,
renamed away, collapsed into another document, or replaced by a summary without explicit user authorization.

**Every REVIEW turn must update this file before closing**, so a cold-start agent is never more than one review
behind. The required update covers:

1. the **currency line** below — turn ID and date;
2. **§3 Where we are** — selector authority, stable accounting, checkpoint status;
3. **§4 the witness table** — if any witness's state changed;
4. **§7 Open problems** — re-ordered by current priority, with resolved items removed;
5. **§8 Recurring defect patterns** — if the turn found a new pattern or a new instance of an existing one.

**Keep it substance-only.** No turn workflow, no policies, no checklists, no transport or connector mechanics.
That boundary is what makes this document cheap enough to read first, and it is the reason it exists.

Authority for this rule: user instruction, preserved in `M3_CP4c_Consolidated_Record.md` §6.6 and the
2026-08-29 `M3-CP4c-2-TB-X2-R7-REV` changelog entry.

---

**Purpose.** Get an agent from cold start to useful in one read. This is *substance only*: what the system is,
where it stands, what is broken, and where to look. It deliberately contains **no procedural information** — no
turn workflow, no policies, no checklists, no transport or connector mechanics. Those live in
`Future_Chat_Session_Handoff.md`, `AGENT_POLICY.md`, `RETENTION_POLICY.md`, `CLEAN_UP_POLICY.md`,
`TOOL_USE_CONSERVATION_POLICY.md` and `GitHub_Workflow_Policy.md`.

**Currency.** Last updated 2026-09-02 at `M3-CP4c-3-CB13`, which is **COMPLETE / BUILD GREEN / DIAGNOSTIC-ONLY**. Exact compile/package source is `3070173894ee097f631b96c1c6d29f276df89a66`; immutable package **81** is artifact `9834661539` with inner tar SHA-256 `4f49b3de157e51aff05736f9ac4b210372eb4bfb4dec3ddc793869071b2f9d88`. No Directional runtime executed in CB13.

**The moved ordinal-366 red is now instrumented, not corrected.** CB13 independently reconciled the review census: `EmbeddedGraphTopology.cpp` has 46 `RotationSystemInconsistent` emission sites, **37** meet BF1's exact missing-reason predicate, while the review's **28** is the narrower subset missing both reason and edge/face locus. All 37 were typed, and the eight reasonless same-code sites in `GlobalTopologyPlan.cpp` were typed too: **45 sites / 53 new condition names**. Existing reason values 0–8 remain unchanged.

`SurfaceCutGraphError` now carries `sourceVertex`; `topology_error` copies it; `cut_graph_failure_locus` projects the rotation reason, vertex, trace/event, position reason/pass and cut-attempt shape; `canonical_candidate` records the certification attempt index and current cut-edge count; and `append_cp4c_failure_locus` renders them into **ordinal 366's own existing failure message**. No topology decision, gate identity, selector byte, ray ordering, cellularity rule, cut proposal, admissibility rule or tolerance changed.

**Exact next is `M3-CP4c-3-TB11`.** Artifact-only package-81 runtime must determine which typed condition actually fires and whether certification failed on the initial uncut graph or a later proposal. A reason in `walk_graph_faces` or `exterior_boundary_orbits` falsifies the current fan-order hypothesis and is a valid outcome. Selector 377 remains frozen; accepted authority remains **365/365**; stable accounting **44 / 14 / 30**; debt **5**; semantic packages **78**.

*(Prior turn, retained for lineage: `M3-CP4c-3-TB9-REV` classified TB9's first red as a **genuine product ownership
defect on a valid witness** — a `FieldAlignedSingularityPort`, an *origin* credential, was being used as an
*arrival* credential, and a `BarrierAbsorbed` singularity has no ports by design although its network node is
allocated unconditionally. It froze `M3-CP4c-3-CB12` under BD0–BD9, which TB10 has now runtime-proved.)*

*(Prior turn, retained for lineage: `M3-CP4c-3-TB8-REV` reduced the twelve `InvalidNetworkTerminalOwnership`
emission sites to **two** and classified the red as **diagnostic insufficiency**, because the two survivors emitted
an identical rendered locus while every discriminating field of `FieldAlignedCurveNetworkError` was dropped at the
pipeline projection — and accepted ordinal 329's losslessness guarantee turned out to assert against a
**test-local** renderer. CB11 discharged BB0–BB9 diagnostically: the discriminator was added as a **field**, so
accepted ordinal 328 still asserts `InvalidNetworkTerminalOwnership` unchanged.)*

*(Prior turn, retained for lineage: `M3-CP4c-3-TB7-REV` proved ordinal 366 was a **CB9-introduced** product defect —
CB9's fifth seed guard reused the **half-open ownership convention** as an admissibility test on one incoming ray,
making every edge-collinear vertex arrival unresolvable in `FaceInterior` mode — and classified ordinal 374 as an
**invalid witness**: the folded cone has `Θ = 3π/2`, so Gauss–Bonnet forces `exactLift = 1` against
`make_zero_transport_field`'s declared `effort ≡ 0`, and that helper carries an unstated precondition — the mesh
must be **intrinsically flat at every interior vertex**. Amendments 22 and 23 survived intact. Ordinal 374 remains
deferred as `M3-CP4c3-TB7-CAND-02` and the atlas must not be weakened for it.)*

*(Prior turn, retained for lineage: `M3-CP4c-3-DEFN-R2` discharged CB8-REV's AX1–AX8 and froze the vertex-star
continuation semantics. **Amendment 22:** a curve continues through a source vertex along the **straightest
geodesic** of the intrinsic vertex star — one exact arrival-anchored ray, one isometric development of the fan,
continuation at `β = α + Θ/2`, the *unchanged* half-open sector convention applied to developed sectors, one typed
certificate. Choosing `Θ/2` over `π` makes the gap/overlap pathology of a non-flat star **impossible** rather than
adjudicated, and coincides with the ordinary straight line at every flat vertex. **Amendment 23:** the exact
election is the sign of a sum of arccosines, degree up to `4^k` in fan length, so the architecture owes a certified
filter, an implemented exact fallback, and a **published budget** with a typed fail-closed state. Vertex 30 is
proved exactly there: four rational identities give `Θ(v30) = 2π` with no factorization and no floating point, the
developed sectors give `sector(209) ∪ sector(208) = [π, 3π/2)`, so the owner is row 209 `(30,119,123)` or row 208
`(30,31,119)` split at `α = θ₂₀₉`, and **row 41 `(25,30,31)` is unreachable by any continuation**.)*

*(Prior turns, retained for lineage: `CB8-REV` upheld CB8's architectural stop and proved the missing authority was
definition-level; `TB3-R1-REV` confirmed Amendment 16/P2 effective and ordered the typed failure-locus channel CB5
delivered; `TB4-REV` falsified all three enumerated mechanisms and declared **Amendment 17**.)*

---

## 1. What the project is

A hard fork of **libdirectional** adding a **quad-remeshing pipeline** built on exact arithmetic. Given a
triangle mesh and a cross field, it produces a pure-quad mesh carrying an explicit, independently verified
guarantee. The distinguishing commitments:

- **Exact arithmetic, no tolerances** in topological decisions. `FieldExactRational` / GMP-backed integers.
  A predicate that needs an epsilon is treated as a design defect, not a tuning problem.
- **Single-writer authority.** Every datum has exactly one producer. Consumers get `const` views or typed IDs.
  Products are immutable once produced; a later stage may not repair an earlier stage's output.
- **Derived, not assumed.** Regions, ports, terminations and certificates are computed and certified, never
  asserted by fiat.
- **Typed failure over silent degradation.** Every stage fails closed with a typed error and a locus.

`DESIGN.md` is the normative architecture. `ROADMAP.md` maps checkpoints to the production-ready exit
(`M8-CP3`).

## 2. Pipeline stages

| Stage | Product | One-line contract |
|---|---|---|
| A0 | `SourceAuthoritySnapshot` | exact source support, typed IDs, topology regions |
| A1 | `FieldTransportAtlas` | per-face cross frame + typed transport across every interior edge; singularities |
| A2a | `FieldAlignedCurveNetwork` | traces from singularity ports + mandatory edges from features/boundaries |
| **A2a′** | **`SurfaceCutGraph`** | **added cuts guaranteeing the network's complement is a disjoint union of discs** |
| A2b | `GlobalTopologyPlan` | regions as faces of the embedded graph, with disc proofs |
| A3 | `GlobalConformityPlan` | — |
| A4 | `RegionCellComplex` per region | — |
| A5 | `SurfaceOccurrenceComplex` | — |
| A6 | `QuotientCertificate` + quad mesh | — |
| A7 | source-attached vertex geometry | — |
| A8 | `VerificationReport` + `OutputDisposition` | independent verifier assigns the tier |
| A9 | logs and public result | — |

A2a′ was added and closed in CP4c-2. A2b now derives regions with disc proofs on the produced torus. Everything
from A3 onward is unreached, and the prescribed sphere still cannot reach A2b (§7 item 1).

**Disposition ladder** (assigned by A8, never asserted by a producer; a run only moves down):
`D0 Certified` → `D1 QualityRelaxed` → `D2 LocallyDegraded` → `D3 Partial` → `D4 DiagnosticOnly`.

## 3. Where we are

**Current authority — TB10-REV.** Accepted authority remains selector **365**. CP4c-3's frozen unaccepted gate is
selector **374** (`d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f`), byte-frozen since CB9.
Diagnostic **375** (`aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0`), **376**
(`6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8`) and current execution selector **377**
(`7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`) each append **exactly one** identity to their
predecessor and reorder nothing; the first 365 lines of 377 are byte-identical to accepted selector 365. All were
recomputed from committed bytes at this review.

**TB10 is the latest semantic runtime evidence** (package 80, source
`a3b6f1a41feaa8a115faf11de52f85ce4cc42a15`, run/job `33584653692 / 100106147126`, result artifact `9829700900`):
377 fresh processes, **369 PASS / 8 RED**; ordinals **1–365 green**; first red **366**, moved into
`surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent` with **no** reason, vertex, edge,
face, trace or event; report-only 367–377 with zero gate credit; immutable pre/postflight PASS.

`M3-CP4c-3-TB10-REV` classified that red **BE2 diagnostic insufficiency, producer-side** (§7 item 1) — proving,
not assuming, that the exact condition is unavailable — and froze **`M3-CP4c-3-CB13` under BF0–BF9**,
diagnostic-only. Stable accounting is **44 / 14 / 30**, produced-witness debt **5**, semantic M3 packages **77**.
Ordinal 370, the sphere, saturation, the folded-cone witness and the mechanical zero-unbound debt remain deferred
and were untouched. **Vertex 30 is still not reached**, so the frozen row-209/row-208 owner election has no runtime
acceptance and `M3-CP4c3-TB6-CAND-01` stays ACTIVE.

**Accepted authority: CP4c-2 at 365/365.** CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are CLOSED / ACCEPTED. The
accepted selector is cumulative and each checkpoint's prefix is byte-identical to its predecessor, so
`first_red_ordinal` is comparable across the whole arc.

| selector | SHA-256 |
|---|---|
| accepted 316 prefix | `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` |
| accepted 346 prefix | `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` |
| accepted 353 prefix | `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5` |
| accepted 355 | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| CP4c-2 357 prefix (superseded as a gate; retained) | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| CP4c-2 358 (**withdrawn** as a gate; retained) | `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62` |
| CP4c-2 361 prefix (superseded by accepted 365; retained) | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` |
| **accepted 365 (CP4c-2, closed at R10)** | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| CP4c-3 367 prefix (frozen at DEFN; superseded as a gate, retained) | `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf` |
| CP4c-3 370 prefix (AL7 append; retained) | `9160ea619afb9e10cbad30012d0bd354c263a2b749e690c271f653db3bf83525` |
| **CP4c-3 gate 373 (frozen at CB2 under AM8, unselected)** | `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834` |
| **CP4c-3 gate 374 (frozen at CB9 under AY6; current gate)** | `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f` |
| CP4c-3 diagnostic 375 (one append) | `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0` |
| CP4c-3 376 (one append) | `6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8` |
| **CP4c-3 execution selector 377 (current, TB10)** | `7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1` |

**All fifteen values are authority**, each recomputed from committed bytes — never transcribed. The current
execution selector file `Architecture_M3_CP4c3_Required_Green_Selector_377.txt` was re-verified independently at
`M3-CP4c-3-TB10-REV`: 377 lines, 377 unique identities, and `head -365`, `head -367`, `head -370`, `head -373`,
`head -374`, `head -375` and `head -376` **each reproduce their frozen hash exactly**.
`Architecture_M3_CP4c1_Required_Green_Selector.txt` was retired in a cleanup and **no longer exists**; that is by
design, because every accepted hash survives as a **prefix of its successor file**. Derive the older values from
377 with `head -316`, `head -346`, `head -353`, `head -355`, `head -357`, `head -361`, `head -365`. 358 has its own
retained file. **Every selector file reproduces all of its predecessor prefixes exactly**, which is what keeps
`first_red_ordinal` comparable across the whole arc. **Recompute rather than copy**, validate every expected digest
as exactly 64 lowercase hex at authoring, and never write one as `PREFIX…SUFFIX` where a value is expected: `PR8`
orchestration defect `R7-ORCH-01` was four hashes expanded back to full length from abbreviations, one of them only
63 characters long.


**CP4c-2 CLOSED / ACCEPTED at 365/365.** R10 (run/job `33331453506 / 99310594268`) executed the frozen gate from
ordinal 1 against immutable CB9 package `9736088354`, one identity per fresh process, with green immutable
pre/postflight and every mutation and benchmark flag false. Accepted source
`57444781af7bdc460e38cc68930a9a8c8199eeea`; package SHA-256 `78f542c7…0490ebdf`. Criteria **C1**, **C3** and **C6**
are green.

**What CP4c-2 did not deliver**, so the closure is not read as more than it is: the **prescribed sphere** still
fails before cut selection and was outside the gate by recorded decision, so CP4c-2 closed with one of its three
witnesses unable to reach A2b at all (§7 item 2); Amendment 14's **ordinary** trace-crossed proposal path is
unexercised (§7 item 3); and the zero-node/zero-arc question was undecided (§7 item 4). All three passed to CP4c-3,
which has now **gated the sphere** and **decided** the zero-node question.

**The torus is done, and this is the checkpoint's headline result.** Ordinal 356 publishes `networkV=48`,
`networkE=48`, `cutEdgeCount=28`, `torusRegionCount=4`; the independent oracle publishes actual graph
`V/E/F = 72/76/4`. `72 − 48 = 24` added vertices and `76 − 48 = 28` added edges — **28 is exactly the producer's
cut-edge count**, so producer and oracle agree term for term. A2a′ takes a closed genus-1 surface from a
non-cellular network to a certified cellular embedding and A2b derives four regions. Criteria **C1**, **C3** and
**C6** all hold on the produced torus (ordinals 356, 357, 362).

Stable regression accounting **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**;
authoritative M3 packages **68**. `selected_r2_branch=NONE`; selector **365** is now accepted authority;
`gate_execution_authorized=false`. TB1 added **+0 events / +0 recurrences**: ordinal 366 belongs to a gate that has
never been accepted, and the accepted 365 prefix went green in that very run.

**CP4c-3 is open, and its gate is frozen at 373** — accepted 365, plus criterion **C2** (ordinal 366) and criterion
**C3**'s full torus-and-mechanical form (367), plus the inherited prescribed sphere (368), the ordinary
trace-crossed proposal (369) and the typed empty-network rejection (370), plus Amendment 15's three self-checks
(371–373). All eight are red or unreached today, which is correct for a required-green selector.
`M3-CP4c-3-DEFN` also put the **prescribed sphere in the gate** after two checkpoints outside one, and decided
`R8-CAND-02`.

**TB3 packaging review is now decisive.** Package 71 never reached runtime. Raw CB3 artifact `9750227619` independently retains all six exact executable hashes with mode `0755`; final package 71 retains those bytes but exposes `0644`. The loss point is the fixture-packaging job's `actions/download-artifact@v4` materialization boundary. The correction is transport-only: package the immutable tree inside `tar.gz` so executable metadata survives outer Actions transport. Accepted authority remains CP4c-2 at **365/365**; CP4c-3 selector 373 is still frozen and runtime-unproved beyond the prior TB2 first-red history. Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **70**.

**Phase 1 is done and its answers are in.** `M3-CP4c-3-TB1` (run/job `33340448381 / 99335020672`, immutable CB1
package `9739919234`, semantic source `48dd011c4aa689a245b74527ed9df0900ada9bf3`) re-proved the **accepted 365
prefix green on package 68** and hard-stopped at ordinal **366** — a valid semantic red, with every immutability
flag green and every configure/compile/relink/repair/benchmark/mutation flag false. Selector 367 is byte-identical
to its freeze.

- **Mechanical witness — cause ESTABLISHED, and it is an architectural disagreement, not a bug at a line.**
  `IncompleteCycleBasis → CycleTransportAdjacencyMissing`, region `0`, source edge `0-3`,
  `fieldTransportAdjacencyExists=false`. Edge `0-3` is a `HardFeature` **barrier**, established by elimination over
  `FieldTransportAtlas::make`'s four adjacency buckets: `SourceBoundary` is excluded by `globalEF=1,158` (two
  incident faces), `NonTraversable` by a region count of 1 over all 300 faces, and `adjacencies` by the measurement
  itself. **The region decomposition and the traversability classification disagree about the same edge.** Regions
  skip hard-feature edges when flood-filling, but skipping an adjacency **disconnects nothing unless the removed
  edges actually separate**; here region 0 is all 300 faces with `boundaryLoops=0`, so the edge stays *interior* to
  the local mesh (`localEF=1,158`), enters `innerAdjacencies` (450 = E), is spanned by the cycle basis, and the
  transport walk demands the adjacency the atlas deliberately withheld. §7 item 1 carries the corrective options.
- **Prescribed sphere — the measurement is one level short.** `RotationSystemInconsistent →
  TraceEventPositionInvalid`, reached with source topology, atlas and network all available (24 traces / 56 events).
  AK3 did exactly what it was asked, but `TraceEventPositionInvalid` is **itself a two-way collapse** whose two
  branches need opposite fixes. AL3 resolves it; AL4 forbids designing across it. §7 item 2.
- **The two causes do not share a locus** — A1 `FieldTransportAtlas` versus A2a′ `EmbeddedGraphTopology`, no shared
  code and no shared datum — so they may be worked independently. That is what unblocked phase 2 for the mechanical
  witness alone.
- Frozen non-gating diagnostics ran in full: **0 PASS / 3 RED**, report-only. Three workflow controls failed in
  preflight and executed no Directional runtime; one of them is the **third** occurrence of the `R7-ORCH-01`
  malformed-digest defect, escalated from a reminder to a mechanism by AL8.

**`M3-CP4c-3-TB5` moved the first red to a zero-candidate, zero-diagnostic locus — and that is the finding.**
Run/job `33448925069 / 99674216849`, immutable package **74**, semantic source
`49536cf7b4b261bd52f36a91c861b6459db356a4`. Ordinals **1–365 green**; ordinal 366 still
`VertexTransitSectorUnresolved`, now at `sourceVertex=11`, face `(8,10,11)`, branch 1, region 0, `FaceInterior`,
**`publishedFaceCount=0`**, `barrierAbsorbed=false`, `barrierIncident=false`, and **zero `vertexTransitState`
rows**.

- **It is a silent seed-drop, not an election.** CB6 made the BFS seed *conditional*
  (`SurfaceCellTracing.cpp:659-667`): if the arrival pairing is missing or its direction fails to convert, `pending`
  is empty, the loop never runs, `diagnostics` stays empty, and the function still returns "sector unresolved".
  Four exits drop states without recording anything (§7 item 2). Vertex 11 is a structurally ordinary **regular**
  vertex with a closed, consistently oriented 6-face fan — reproduced from the fixture — so zero examined states is
  a defect in seeding, not in geometry.
- **CB6 broke exactness to satisfy Amendment 17.** The "single datum" is carried as a **world-space `double`**:
  exact barycentric → `to_double()` → normalized 3-vector → transported in doubles → `from_double_exact()` → fed to
  the exact sector comparison. The comparison stayed exact; the datum did not. **Amendment 18** now governs this.
- **Amendment 17 is masked, not cleared.** The stop precedes any election, so AS1's falsifier never ran and the
  vertex-30 reconstruction remains untested.
- **The sphere advanced:** ordinal 368 resolves to **`NoCarrierMatch / SourceEdgeUnavailable`** — AL3's
  discriminator is answered, the ambiguity suspicion carried since TB1 is **dead**, and AL4's blocking condition is
  discharged. **Ordinal 370 is classified**: the atlas's `NonIntegralCycleLift` rejection of a constant ambient
  field on a closed torus is legitimate, so that witness is invalid, not the product.

**`M3-CP4c-3-TB4` published the vertex-30 locus and falsified every mechanism the previous review named.** Run/job
`33436492493 / 99634138202`, immutable package **73** (`9773591345`), semantic source
`2d22ef293363058cfdca96d01158a93d2c0200f8`. Ordinals **1–365 green**; ordinal 366 still first-reds at
`VertexTransitSectorUnresolved`, now with `sourceVertex=30`, arrival face `(24,30,32)`, `branch=1`, region 0,
`arrivalMode=FaceInterior`, **two** candidate faces `(25,30,31)` and `(30,31,119)`, `barrierAbsorbed=false`,
`barrierIncident=false`. CB5's typed locus channel (AP1) worked exactly as ordered — no fourth review had to
recover a locus by elimination.

- **All three enumerated mechanisms are dead.** M1 (zero candidates) — cardinality is 2. M3 (P2 consumer mismatch
  at a barrier-absorbed vertex) — the vertex is neither absorbed nor barrier-incident. M2 (singular-vertex
  holonomy) — vertex 30 is **regular**, reproduced from the committed fixture: six incident faces forming one
  closed, consistently oriented fan, and Poincaré–Hopf closes with exactly the eight known index-`+1`
  singularities (`4χ = 8`), so there are no others.
- **A proof replaces the guesswork.** The half-open predicate `direction[next] > 0 && direction[prev] >= 0` is an
  exact partition of the full turn: adjacent wedges share one ray, owned by the face where it is `next`. The two
  candidates are **fan-adjacent**, sharing ray 30→31, which `(25,30,31)` owns. A single direction can elect at
  most one wedge — **so the two elected states were tested against two geometrically distinct vectors.** They are
  two representations of **one** semantic continuation, not two continuations.
- **`AP6`'s report-only pass paid for itself immediately**, turning a three-turn blackout into four findings: 369
  gives the first *runtime* confirmation of `saturationUsed=true`; 370 fails at its own precondition before its
  contract; 373 passes only on a **synthetic** fixture; and 367/371/372 are **blocked upstream**, so Amendment 15's
  arithmetic remains **unmeasured, not falsified**.
- **`M3-CP4c-3-TB4-REV` declared Amendment 17.** See §7 item 1.

**`M3-CP4c-3-TB3-R1` proved Amendment 16/P2 works, and A1 is clear end to end.** Run/job
`33416686424 / 99568970224`, immutable mode-preserving package **72** (`9765247195`), semantic source
`93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`. `MissingSingularityBranchTransport` is **gone**; the mechanical
witness clears the cut transport domain, the tangent bundle, the cycle basis, index accounting **and** singularity
port attachment, and first-reds for the first time in **A2a** at
`NotProductionReady/field-aligned-network/VertexTransitSectorUnresolved`. **Ordinals 1–365 stayed green** through
this second invasive A1 change, as they did through the first.

- CB3 chose Amendment 16 policy **P2** on measured evidence: 8 prescribed singularities, **4 barrier-incident**,
  all `InteriorArc` with `d_B(v)=2` and a 2-component star, now `PortPolicy::BarrierAbsorbed` and emitting no
  ports; the other four (vertices **10, 35, 47, 71**) emit normally.
- CB3's census also **statically confirms DEFN-R1's Theorem 2**: the mechanical barrier graph is a four-component
  forest, `n=16`, `m=12`, `c=4`, `χ(B)=4`, **no cycles**. Static, not runtime — ordinals 371–373 still have never
  executed.
- **Cause of the new red is NOT established**, deliberately. The locus exists in the typed error and was discarded
  by the pipeline's failure funnel (§7 item 7), so zero-versus-multiple candidates cannot be decided from this run.
  Three mechanisms remain live and one measurement discriminates all three — see §7 item 1.
- `M3-CP4c3-TB2-ORCH-01`, `M3-CP4c3-TB2-REV-CAND-01` and `M3-CP4c3-TB3-ORCH-01` are all **resolved and
  runtime-proved** by package 72 and this run.

**`M3-CP4c-3-TB2` proved Amendment 15 works, and that remains the prior stage's headline result.** Run `33355714664`,
semantic package **69** (`9742715856`), semantic source `005512f20ed56edc793f4d6505f3d2b4c2999c71`, executed
against fixture-only transport package **70**. The mechanical witness **advanced past `IncompleteCycleBasis`** —
TB1's stop is gone, the cut transport domain is constructed, the tangent bundle initializes, the cycle basis is
built and validated, and execution reaches a later stage of the same producer. **Ordinals 1–365 are green**, so a
deeply invasive change to A1's local mesh construction regressed nothing in the accepted gate.

- **New first red at ordinal 366: `MissingSingularityBranchTransport`** — and it is the *same architectural
  disagreement one consumer later*. `build_singularity_attachments` (`FieldTransportAtlas.cpp:597-618`) walks the
  ordered one-ring fan of a singular vertex and demands a branch transport on **every** radial edge;
  `ordered_incident_fan` (`:351-402`) builds that fan from the **global** `sourceMesh.F` and *requires it to
  close*; and `branchTransports` (`:304-342`, built at `:1827` from `adjacencies`) **excludes every barrier by
  construction**. So a singular vertex incident to a hard feature fails by construction. Established by the same
  elimination as TB1: the failing radial edge is not `SourceBoundary` (the domain is closed) and not
  `NonTraversable` (one region over all 300 faces), so it is `HardFeature`.
- **It is pre-existing and was merely unmasked — not a regression.** Call order is `build_branch_transports`
  `:1827` → cycle-basis loop `:1865` → `build_singularity_attachments` `:2384`, so the cycle failure fired first at
  TB1; and CB2's diff to that file begins at old line **842**, leaving all three functions untouched. The
  mechanical witness simply got further.
- **Amendment 15's own self-checks never ran.** First-red at 366 left ordinals 367–373 unexecuted, so the barrier
  decomposition, the Euler cut identity and the unbound-singularity count are still **unmeasured**, and every
  DEFN-R1 prediction remains unverified. The amendment is *effective* and *unverified* at once.
- **`M3-CP4c-3-TB2-REV` declared Amendment 16**, generalizing 15 from the cycle basis to **every** A1 derivation
  that walks transport. See §7 item 1.

**`M3-CP4c-3-DEFN-R1` settled the normative question with Amendment 15 (`DESIGN.md` §7.2.1).** A region's face set
and its published `euler_characteristic()` / `boundary_loop_count()` are facts about the **uncut** source complex
and are unchanged; A1 instead derives its tangent bundle, cycle basis and index quantities from the region's
**transport domain** — the region **cut along** `B(R) = { e ∈ hardFeatureEdges : both incident faces ∈ R }`. The
cut lives in A1's derived local mesh, **not** in the region product, for three reasons: the region product
literally cannot express an open slit (§7 item 1); it is the Amendment 14 precedent — an immutability guarantee
constrains the writer, not a derived view; and it makes the two classifications agree **by construction** instead
of by an unwritten assumption. The corrective is now defined; **`M3-CP4c-3-CB2` implements it under AM0–AM9**.

**The gate is selector 365**, frozen by CB7 under AG7: selector 361 plus criterion C3's torus identity and the
three Amendment-14 identities. Every prefix is byte-identical to its predecessor — 355, 357, 361 — so
`first_red_ordinal` is comparable across the whole CP4c arc.

- **361 is superseded** by 365 and retained for lineage; **357 is superseded**, not wrong — its two
  `GlobalTopologyPlan` torus identities are retained in both.
- **358 is withdrawn.** Its sole addition, `RotationSystemAndFaceWalkAgreeOnProducedWitnesses`, binds
  `cp4c_mechanical_fixture()`, and the mechanical witness has no atlas and is out of CP4c-2 scope — a gate may not
  bind a witness its own checkpoint excludes. Criterion **C3** survives: its torus half becomes its own identity
  and enters the gate; the mechanical half moves to CP4c-3.
- **Two of the four appended identities enter the gate red.** That is correct — a required-green selector says what
  must be true for the checkpoint to close, not what happens to pass today.

`selected_gate` is still **NONE** and `gate_execution_authorized` is still **false**: freezing a gate's bytes is not
selecting it.

## 4. The three witnesses — the fastest way to understand the problem

| witness | source | A2a result | current state |
|---|---|---|---|
| **torus** | fixture, closed genus 1, `χ=0`, V/E/F = 72/216/144 | 48 `HardFeature` mandatory edges, 0 singularities, 48 nodes, **0 traces**, 0 events | **A2a′ and A2b both work end to end through the production path.** 28 cut edges; actual embedded graph `V/E/F = 72/76/4`, `χ=0`; 4 regions with disc proofs. Producer and independent oracle agree term for term (`76 − 48 = 28`). Criteria C1/C6 green at ordinals 356/357. Fails later, downstream of A2b, at `tracing` (out of CP4c-2 scope) |
| **prescribed sphere** | fixture, closed genus 0, `χ=2`, V/E/F = 98/288/192, zero mandatory edges | 24 traces / 56 events | A2a′ remains deferred. TB6 report-only ordinal 368 localizes the current producer stop to `TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable`. This is localization only; no sphere semantic fix is authorized. |
| **two-ring** | constructed, disc, `χ=1`, V/E/F = 11/25/15 | 3 traces / 8 events | actual embedded graph `V/E/F = 9/11/3`; the accepted invariance witness, and the **only** witness on which the A2a′ semantic/provenance split is runtime-proved |
| **mechanical feature** | fixture, 152 V / 300 F, closed, `chi=2`, 0 boundary edges | clears all A1, the vertex-11 transit (CB10) and, since CB12, the whole of A2a | **Current owner of the critical path, now in A2a′.** TB10 first-reds at ordinal 366 in `SurfaceCutGraph` with `CellularityNotEstablished/origin=RotationSystemInconsistent` and **no** reason, vertex, edge, face, trace or event. CB12's termination correction is runtime-proved: identity 377 passes at terminal **v36** / singularity 4 / `BarrierAbsorbed` / network node **7**, and `oldOrdinal366ConditionSeedPair=false`. TB10-REV proved the firing site is one of **28** `RotationSystemInconsistent` emission sites that publish neither a reason nor an edge/face locus, so the failing phase — before, during or after fan ray ordering — is **undecidable at the current instrumentation**. This is the first closed witness carrying **both** traces and non-separating hard features, so `build_rotation_system` meets `Mandatory`, `Trace` and `Cut` rays at one vertex fan for the first time — a hypothesis for the next measurement to discriminate, not an assignment. Vertex **30** is **still not reached**. See §7 item 1. |

## 5. The central theorem of CP4c-2

For a graph embedded in a closed surface with every complement component an open disc, Euler gives
`V − E + F = χ`. The torus network has `V = 48`, `E = 48`, `χ = 0`, so `F = 0` — impossible, since the
complement is non-empty. **At least one component is not a disc.**

Stronger and more useful: a disjoint union of closed curves always has `E = V`, so **no disjoint union of closed
curves can ever be a cut graph of the torus.** This is not a defect of the committed fixture and cannot be fixed
by choosing better feature curves. A cut graph of a genus-`g` surface needs vertices of degree ≥ 3 and must
realize a homology basis; a feature/singularity-derived network guarantees neither.

That is why A2a′ exists. `UncutFaceComponentOrbitSeedNotUnique` at `GlobalTopologyPlan.cpp:1741` was **correct
behaviour reporting a missing input** — there was never a bug at that line.

## 6. The normative complex — read this before touching A2a′

Frozen by **DEFN-R1 Amendment 13**. The complex in which cellularity is certified is the **actual embedded
graph** of `FieldAlignedCurveNetwork ∪ cutEdges`:

- **vertices** = network nodes + nodes created by cuts
- **edges** = network arcs + cut arcs
- **faces** = **dart orbits** under the node rotation system

The machinery already exists and must be reused, never reimplemented:

| concept | where |
|---|---|
| arc, dart | `GlobalTopologyArc`, `GlobalTopologyOrientedArc` — `include/directional/geometry/GlobalTopologyPlan.h:33-47` |
| rotation | `GlobalTopologyNodeRotation.counterClockwise` |
| face walk | `walk_graph_faces(arcs, rotations)` → `FaceWalkResult{orbits, orbitByDart}` — `src/geometry/GlobalTopologyPlan.cpp:1168-1260` |
| fragment | `fragmentOrbits[SourceFaceTopologyKey] → {orbit}` — `:1534-1660` |
| shared authority | `src/geometry/EmbeddedGraphTopology.{h,cpp}` — created by CB4, the single owner |

**Two conventions decide correctness and must be derived, not guessed:**

1. **Exterior-orbit exclusion** on surfaces with boundary. The two-ring walks 4 orbits, exactly one exterior →
   `F = 3`. On a closed surface there is no exterior orbit.
2. **Disconnected-graph correction.** The torus's 48 arcs over 48 degree-2 nodes form **four components**;
   unqualified `V − E + F = χ` is false there *before* any cut is considered. Mistaking that for
   non-cellularity is right for the wrong reason.

**Withdrawn:** the whole-source-face / source-edge-barrier partition is **not** cellularity authority. It
survives only as a cut-proposal heuristic and diagnostic provenance, and any publication of it must say so.
Two complexes exist for the two-ring and both satisfy Euler — actual `9/11/3` and proxy `10/11/2` — which is
precisely why self-consistency proves nothing about *which* object was measured.

**Cut admissibility — revised by Amendment 14 (DEFN-R2); the old rule below it is withdrawn.** A cut is a source
edge promoted to a graph arc, and **every source edge that is not already a graph arc is admissible, including one
a trace crosses at an interior point.** Promoting a crossed edge adds one arc per sub-interval between consecutive
crossings and one cut-created node per crossing, and splits the trace arc **in the derived arrangement only**.

The old rule — "a trace-crossed source edge is inadmissible because promoting it would subdivide an immutable
trace" — rested on a premise that is false about this codebase. `build_arcs` already emits **one trace arc per
event**, so a trace is many arcs, not one; it already splits a mandatory source edge at a trace terminal; and the
crossing point is already published exactly by the network as `segments[i].entryPoint`, at a segment position the
subdivision machinery already keys on. Nothing upstream is mutated either way. Amendment 12 forbids A2a′ *repairing*
an upstream product; it never forbade A2a′'s own arrangement from placing a node where the network already says two
curves meet.

**Completeness is therefore proved outright.** The complement of the source 1-skeleton is the open triangles, each
a disc; trace sub-arcs cut those discs into discs; so `network ∪ (source 1-skeleton)` is cellular, a sufficient cut
set always exists, and at most `|E_source|` promotions are ever needed. `NoAdmissibleCutForNonDiscComponent` can no
longer describe a real configuration and is retired; a distinct code reports "the search heuristic made no
progress", and saturation — promoting the component's remaining admissible edges — is the defined, *published*
last resort. It must never fire silently, and is predicted never to fire on the three witnesses.

**The one real gap this opens:** at an edge-locus node, `build_rotation_system` handles only `Mandatory` (at exactly
degree three) and `Trace` rays — a `Cut` ray there is an unhandled shape. A crossing node is two collinear `Cut`
rays plus two `Trace` rays, degree four, and the existing four-sector model generalizes to it. CB7 implemented that
generalization; ordinal 364 would prove it and **has not yet executed**.

**Building an A2a′ witness by hand — the trap that produced R8's red.** The production feature authority is a
**chain of four products**, and it is acyclic:

```
featureMap → build_authoritative_surface_cell_rails → authoritativeRails
           → hard_feature_edge_keys_from_rails      → hardFeatureEdges
           → SourceTopologyRegions(hardFeatureEdges, componentByFace, localSheetByFace, authoritativeRails)
           → FieldTransportAtlas::make(…, hardFeatureEdges, …)
```

The test helper `rails_from_atlas` reads rails **back out** of an atlas, keeping only `SourceBoundary` and
`HardFeature` non-traversable edges. That is correct only if the atlas was built with the hard features already.
On a **closed** witness built with `hardFeatureEdges = {}` it returns **nothing**: no boundary, no declared
features, and uniform component/sheet labels leave no `NonTraversable` edges either. The result is an empty rail
set, an empty network, and a red that looks like a cut-graph failure. `make_source_authority(mesh)` supplies none
of the four products — it zeroes components and sheets and passes no rails. Two call sites already do this right:
`observe_cp4c_witness` (all four production inputs) and `build_cp4c_trace_crossed_cut_fixture` (computes hard
features first, then threads them through source authority *and* atlas). Copy one of those; never call
`rails_from_atlas` on an atlas that was not told about the features.

## 7. Open problems, in priority order

1. **Mechanical rotation-system rejection in A2a′ — ACTIVE and gating; the cause is provably unreadable, and that
   is the finding.** TB10's first red is
   `NotProductionReady/surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent`, with no
   reason, no source vertex, edge or face, no trace and no event. `M3-CP4c-3-TB10-REV` proved:

   - **46 emission sites, 9 with a reason, and the two sets are disjoint from what is missing.**
     `EmbeddedGraphTopology.cpp` emits `RotationSystemInconsistent` from 46 sites, all reachable from
     `SurfaceCutGraph::make`; only 9 publish a `RotationSystemInconsistencyReason`, and **every one of those 9 also
     sets `sourceEdge` and/or `sourceFace`**. The ordinal-366 renderer prints both when present and printed
     neither, so the firing site is one of the **28** that publish neither — 14 `build_rotation_system`,
     9 `walk_graph_faces`, 2 `build_arcs`, 2 `build_node_loci`, 1 `exterior_boundary_orbits`. **23 of the 28
     publish nothing at all**; 5 publish only `sourceVertex`.
   - **Three sequential losses of one datum, and the reported one is the last.** (1) the 28 producer sites;
     (2) `SurfaceCutGraph::topology_error`, whose `SurfaceCutGraphError` has **no `sourceVertex` field**, dropping
     the only datum the remaining 5 carry; (3) `RemeshPipeline::cut_graph_failure_locus`, which publishes only
     `sourceEdge`/`sourceFace` while the same file forty lines earlier renders the atlas failure with full
     per-region rows. **Repairing (3) alone changes ordinal 366's output by nothing.**
   - **No snapshot or existing identity rescues it.** There is no `surfaceCutGraphError` in
     `SurfaceCellDiagnosticProductSnapshots`, and `productSnapshots.surfaceCutGraph` is set only on success.
     `observe_cp4c_witness` — the idiom that makes the *sphere* legible at ordinal 368, already applied to the
     mechanical witness by the unselected `MechanicalWitnessStageReachabilityIsObservable` — reads the same
     `SurfaceCutGraphError` and would print `originatingRotationSystemReason=none`.
   - **The failing phase is undecidable today.** The 28 candidates straddle before, during and after fan ray
     ordering, and nothing published says whether the failing `certify_actual_embedded_graph` call was the initial
     uncut certification or a later cut proposal.

   **`M3-CP4c-3-CB13` (BF0–BF9) is diagnostic-only**: one typed name per condition at every silent producer site
   found *by predicate*, `sourceVertex` carried through the mapper, the projection extended, the failing
   certification attempt identified, and **ordinal 366's own failure message named as the carrier** so no gate
   ordinal is added. Prohibited: changing any topology decision, ray ordering, cellularity test or cut proposal;
   inferring and "fixing" a producer before the measurement names it.

   *(Still open and separately owned: the `finalize_field_aligned_events` contact fall-through TB8-REV documented —
   `terminalContact` is never read in `:3745-3935`. Neither TB9 nor TB10 makes it the first mechanical failure, and
   CB13 must not repair it.)*

2. **AY5 folded-cone witness — ACTIVE, gating at ordinal 374, cause classified, correction deferred.** The witness
   is invalid and the product is right. `make_three_right_angle_cone_fan` has `Θ = 3π/2` at its center, hence angle
   defect `K = π/2`, while `make_zero_transport_field` declares `effort ≡ 0` on every edge and no singularities.
   Discrete Gauss–Bonnet forces `exactLift = (0 + 4K)/2π = 1`, which contradicts both the declared matchings
   (`2, 2, 0`, composing to `0 mod 4`) and the empty singularity set. The atlas fails with
   **`CycleTransportMismatch`** at `FieldTransportAtlas.cpp:2098`, with `SingularityMismatch` behind it. **No atlas
   invariant may be weakened.**

   **The reusable finding:** `make_zero_transport_field` has an **unstated precondition — the mesh must be
   intrinsically flat at every interior vertex** — and every prior consumer satisfied it by accident
   (`make_four_triangle_fan` is planar). `DEFN-R2` §7.2 listed five witness properties and omitted the constraint a
   non-flat **regular** vertex forces: production terminates traces at singular vertices *before* vertex-star
   transit, so any AY5 witness must satisfy `Σ_cycle effort = −4K` with matching composing to lift `0`, plus the
   boundary index correction. Corrective (test-only, specified but **not authorized in CB10**): derive
   matching/effort/singularities with `directional::fields::principal_matching` instead of declaring them, keep the
   exact expected-owner derivation, and certify the witness against the atlas's whole admissibility chain.
   **Selector 374 stays byte-frozen and is not withdrawn** — only the fixture and field inside the identity's body
   are invalid. **Ordinal 374 will still be red in TB8; that is pre-classified and must not consume a review.**

3. **Production transit audit projection — ACTIVE; AY7 was delivered producer-side only.** Three defects on one
   path: the `VertexStarTransitAudit` is constructed **after** all five seed guards, so every seed failure publishes
   `std::nullopt`; `VertexStarTransitState::SeedUnavailable` is therefore **dead by construction**; and the 26 AX8
   fields CB9 added to `SurfaceCellFailureLocusDiagnostics` have **no reader** — `append_cp4c_failure_locus`, the
   only renderer the CP4c identities use, prints none of them and `vertexTransitStates` has no projection at all.
   Third consecutive turn in which an ordered measurement was built and discarded at a stage boundary. Owned by
   **AZ4–AZ5**, with the consumer set found **by search against a predicate**.

4. **Minimal transit witness / selector governance — ACTIVE, still conditional.** Selector 374 stays byte-immutable.
   The gate covers only `FoldedConeArrivalRayElectsOneOwnerAndFalsifiesCandidateLocalElection`; the boundary-ray and
   radial-arrival companion instances are **ungated**, and the radial one was written in `EdgeTransit` mode
   specifically because CB9's guards block `FaceInterior` — so no gated identity covers the case production actually
   produces. **AZ6** must derive that witness from the mechanical vertex-11 star (coordinates already committed,
   arrival already proved exact), instantiate **both** radial orientations, and show it failing under CB9 and
   passing under the correction. Ordinal **375** is appended only then.

5. **Ordinal 370 empty closed network — ACTIVE, measured independent A2a′ product red.** TB7 reproduces
   `CellularityNotEstablished` (4) where `EmptyNetworkOnClosedSurface` (6) is required, with the `sourceFace` locus
   absent. Independent owner; deferred until the mechanical path clears; must not be combined with vertex transit.

6. **Prescribed sphere — ACTIVE / deferred.** Report-only 368 reproduces `NoCarrierMatch / SourceEdgeUnavailable` at
   trace 2 / event 30. Preserve AL4: no sphere semantic correction while the mechanical gate owns the critical path.

7. **Ordinary trace-crossed proposal quality — ACTIVE / deferred.** Report-only 369 still publishes
   `certificate.saturationUsed=true`. Amendment-14 representation is proved; ordinary-proposal coverage is debt.

8. **Mechanical zero-unbound singularity proof — PARTIAL.** Ordinal 373 is green only on its synthetic barrier-arc
   witness. `M3-CP4c3-DEFN-R1-CAND-01` stays open until production publishes `unboundSingularityCount=0`.

9. **Report-only 367, 371, 372 — UNMEASURED, and 371/372 are blocked by a fixture helper rather than by their own
   contracts.** All three abort inside the shared `cp4c_mechanical_fixture()` constructor, which throws unless *all
   five* of `sourceAuthority`, `atlas`, `network`, `cutGraph` and `plan` are retained — so their TB10 reds are one
   upstream cause, not three. But **371 and 372 read only `fixture.atlas`**, an A1 product that is available and
   built successfully in the same run: their contracts are independently reachable today and are held hostage three
   stages downstream. Amendment 15's barrier-cycle and Euler-cut contracts have therefore been "unmeasured, not
   falsified" from TB2 through TB10 for a reason unrelated to either. Ordinal 367 genuinely needs `plan` and is
   legitimately blocked. Recorded as `M3-CP4c3-TB10-REV-CAND-01` with a test-only corrective and **deliberately
   deferred**: clearing ordinal 366 unblocks 371/372 automatically, so the candidate exists to make the coupling's
   cost visible if it does not.

10. **CB9 static audit debt — ACTIVE, static.** `M3-CP4c3-CB9-AUDIT-01` (`build_boundary_pairing` computes `u/v` in
    `double` and exactifies them before the flow classification reads their signs) and `M3-CP4c3-CB9-AUDIT-02`
    (`integer_sqrt_floor` has no published bit-width budget). Worth knowing: AUDIT-01 is the mechanism that produced
    the exact zero item 1 turns on, and on that witness it produced the **right** answer — the field genuinely is
    tangent to edge `(10,11)` — so it is **not** the cause of ordinal 366 and must not be repaired as if it were.

## 8. Recurring defect patterns — the highest-value section

**A discriminator added only to the sites that already had a locus discriminates nothing new.** Nine of
`EmbeddedGraphTopology.cpp`'s forty-six `RotationSystemInconsistent` sites gained a
`RotationSystemInconsistencyReason` — and all nine already published a `sourceEdge` or a `sourceFace`. The cases
that were already localisable became more legible; the twenty-eight that published nothing stayed silent, and one
of those is the current gating red. When resolving a collapsed error code, **enumerate the sites that publish
nothing and start there** — the ones you can already localise are the ones that least need a name. This is the
counterpart of `LESSONS.md` 57/64: it is not enough to add a reason, the reason has to reach the *silent* sites.

**Count the losses before repairing one.** The TB10 report localised a real projection loss — `cut_graph_failure_locus`
publishes only two of the ten fields `SurfaceCutGraphError` carries — and named it the cause. There were **three**
losses of the same datum in series (silent producers → a mapper with no `sourceVertex` field → the projection), and
the reported one was the **last**. Repairing it alone would have bought a whole turn of identical evidence. Before
proposing a diagnostic fix, walk the datum from producer to reader and count every boundary that drops it; then fix
the earliest.

**Two identities observing the same stage can have very different eyesight, and the idiom decides.** The prescribed
sphere's cut-graph failure is fully legible at ordinal 368 because it uses `observe_cp4c_witness`, which calls
`SurfaceCutGraph::make` directly and holds the typed error. The mechanical failure is opaque at ordinal 366 because
it uses `build_cp4c_production_fixture`, which throws a string assembled from the lossy pipeline locus. Same stage,
same error family, same test file — different observation idiom. When one witness is legible and another is not,
compare the observation idioms before concluding anything about the witnesses.

**A shared fixture helper's precondition is a coupling that can silence contracts for many turns.** Ordinals 371 and
372 assert only about the A1 atlas, which has been available and correct throughout, yet they have been unmeasurable
since TB2 because the helper that hands them the atlas also demands four downstream products. A helper that returns
*all or nothing* converts every downstream failure into a blackout over every upstream contract that shares it.

**Shared error strings are not shared causes.** Ordinals 366 and 370 both render `CellularityNotEstablished`. One
arrives through `topology_error` carrying `origin=RotationSystemInconsistent`; the other is a direct `cut_error`
with no origin. Check the producer before merging two reds that read alike.

**An origin credential used as an arrival credential.** A singularity **port** records where a trace may
*start*; a singularity **node** records what a trace may *end at*. The product allocates the node
**unconditionally** and the port **conditionally** (`portPolicy == BarrierAbsorbed` emits none), then asks the port
a question only the node can answer — so the very policy whose purpose is to suppress ports made a legitimate
arrival unrepresentable. The authoring control: when two tables model the same entity at different cardinalities,
name which one the question is about before writing the lookup. A lookup that reaches its real target *through* an
optional table (`terminalPort->node`) is the smell. `LESSONS.md` §4 81.

**A reachability witness proves the name, not the branch.** CB11's BB5 measure demanded a witness for each
surviving emission site, and its witness for the port-ownership condition is valid — but it fires the *third*
disjunct (a port exists owning a different vertex), which TB9-REV proves the production path **cannot reach**. The
production path always fires the *second* (no port at all). A condition that is a disjunction owes a witness **per
disjunct**; "reachable by some route" is not "reachable by the route production takes". `LESSONS.md` §4 82.

**Geometry locates a failure; only the source predicate adjudicates it.** Every edge of TB9's traced chain has an
exactly 90° dihedral, and the natural inference — sharp implies barrier — is **false on this witness**: v47 is
equally sharp and provably emits ports. The barrier set is region-restricted at `FieldTransportAtlas.cpp:962`
(both incident faces must lie inside the region), so a hard feature edge that *bounds* a region is not a barrier
while one *interior* to it is. Reconstructing a fixture is the right way to find where a trace went and the wrong
way to decide whether the product was correct. `LESSONS.md` §4 83.

**A guarantee is scoped by its call graph, not by its name.** Accepted ordinal 329,
`NetworkDiagnosticsPublishEveryRequiredLocusLosslessly`, has passed every gate since it was written — while the
production projection silently discards fifteen fields of `FieldAlignedCurveNetworkError`. The identity constructs
errors by hand and asserts tokens against `network_error_locus`, a **test-local** renderer. The path every CP4c
production witness reports through — `network_failure_locus` → `SurfaceCellFailureLocusDiagnostics` →
`append_cp4c_failure_locus` — is never touched. The authoring control: an identity whose name asserts a property of
*the system* must be routed through the entry point the system actually uses; if it constructs the DTO itself, its
name may only claim a property of the DTO. `LESSONS.md` §4 78.

**One typed name over many emission conditions is an untyped failure.**
`FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership` is emitted at **twelve** distinct sites for
twelve distinct conditions. When it fired at ordinal 366, static proof could eliminate ten and no further. CB10's
AZ3 rule — one typed name per condition — was applied to the three vertex-star seed conditions and nowhere else.
The generalization has a catch worth remembering: **splitting the enum is often unavailable**, because an accepted
identity may assert the name (ordinal 328 asserts this one). The discriminator then belongs in an **added field**,
which is additive and cannot break an accepted assertion. `LESSONS.md` §4 79.

**A measurement produced and then discarded at a stage boundary — the fourth consecutive instance.** AS1, AU1/AU3,
AY7, and now the trace-scoped group (`traceSeedVertex`, `traceSeedSingularity`, `traceHistory`, `traceSteps`, …).
Each fix corrected the instance that turn's red exposed and left the class intact. AZ5 even required the consumer
set to be found *by search against a predicate* — and it was, for the fields AY7 named. The predicate was scoped to
the wrong set: it must be **every field of the error DTO that has no projected counterpart**, not every field this
turn added. A related smell in the same family: `FieldAlignedCurveNetworkError::publishedFaces` is **declared and
never assigned anywhere**, so `publishedFaceCount=0` renders as an observation on every network error and means
nothing. A dead diagnostic field is worse than a missing one.

**A convention that makes a choice unique is not a precondition on one of the alternatives.** The half-open sector
rule `next > 0 ∧ prev ≥ 0` exists so that exactly one sector of a fan owns each ray — its asymmetry is deliberate
and correct. CB9 asked it a different question: *is this one face the owner of the ray I arrived on?* Asked that
way, the deliberate exclusion of the `previous` ray becomes an arbitrary, orientation-dependent rejection of a
perfectly ordinary arrival, and the answer depends on which side of a shared edge the mesh happened to number
first. The family is familiar — two authorities for one datum, two classifications never proved to coincide — but
this instance is new and sharper: **one correct rule, reused for a question it was not written to answer.** The
authoring control is cheap: when a predicate's name or comment says *partition*, *elect*, *own*, or *choose*, it
answers a question about a **set**; a question about a **single member** needs its own predicate, and the two must
not share a call. `LESSONS.md` §4 77.

**A fixture helper's silent precondition surfaces the first time a witness stops being degenerate.**
`make_zero_transport_field` declares `effort ≡ 0` and no singularities, which is consistent **only** on a mesh that
is intrinsically flat at every interior vertex — because `exactLift = 4K/2π` is `0` only when the angle defect `K`
is. Every consumer before AY5 satisfied that by accident: `make_four_triangle_fan` is entirely planar. AY5 needed
the project's *first* non-flat star — `DEFN-R2` §7.2 asked for a non-coplanar hinge precisely because vertex 30 is
flat and cannot separate `β = α + Θ/2` from `β = α + π` — and inherited the flat-only helper unchanged, producing a
witness the atlas correctly refuses. This is the degenerate-fixture family arriving from the opposite direction:
not a witness too degenerate to exercise the code, but a helper too degenerate to describe the witness. The
counter-control is the one CP3a demonstrated: **make the helper assert its own precondition at runtime**, so the
next author cannot inherit it silently. `LESSONS.md` §2 22r.

**A witness written around an implementation's restriction cannot falsify that restriction.** `DEFN-R2` §7.2 item 5
required a seed "placed exactly on a radial ray". CB9's guards make that unreachable in `FaceInterior` mode, so its
third AY5 instance was written in `EdgeTransit` mode with the comment *"EdgeTransit is the admissible arrival mode
for that exact radial seed"* — encoding the invented restriction into the witness that existed to test it. The
production defect then survived its own falsifier. When a witness must choose a mode, a flag, or a path to make an
assertion pass, ask whether the thing being avoided is the contract or the implementation.

**A measure that orders a projection must name the consumer that renders it, not only the struct it fills.** AY7
said "extend the `RemeshDiagnostics` projection in the same change so the rows have a reader", and CB9 implemented
that exactly: 26 new fields on `SurfaceCellFailureLocusDiagnostics`, all populated in `network_failure_locus`, and
not one of them printed by `append_cp4c_failure_locus`, which is the only renderer the gate identities use. The
field set grew and no reader appeared, because "the projection" named the producer-side artefact. Third consecutive
turn for this pattern (AS1, AU1/AU3, AY7), each one layer further out. Related and equally cheap: **"record the
diagnostic before the guard" means the whole diagnostic, including its container** — AY4 was honoured for the rows
and missed for the audit object, which left `VertexStarTransitState::SeedUnavailable` reachable by no execution at
all. `LESSONS.md` §4 75.

**A representation gap can reveal that the semantic operation itself was never defined.** CB8 first looked like a
missing exact transport type: branch lift is exact, arbitrary-ray transport is not. CB8-REV found the deeper gap:
for a general non-flat vertex star the design has never stated what "straight through the vertex" means when an
intrinsic development has a gap or overlap. Choosing an algebraic type, moving an owner upstream, or adding a
certificate before that semantic choice would only encode an undefined operation more carefully. **Define the
reference geometry and all typed non-owner states before choosing its representation.** This is `LESSONS.md` 74a.

**A definition gap can hide behind a *cost* — and the cost is a first-class architectural fact.** Having frozen
what continuation *means* (Amendment 22), DEFN-R2 found the next layer: electing a developed sector is the sign of a
signed sum of arccosines, and composing the fan's rotations exactly lands in a tower of degree up to `4^k` in fan
length. There is no bounded algebraic representation as valence grows. The wrong responses are all tempting and all
familiar — carry the value through `double` and exactify (the CB6 defect), pick a tolerance, or let "the filter was
inconclusive" become an answer. The right response is to **publish the budget**: a certified filter that returns the
correct answer or defers, an exact fallback that is actually implemented (here it is the *only* path that can decide
a continuation lying exactly on a radial ray, so it is load-bearing rather than ceremonial), and a declared limit
with a typed fail-closed state above it. An unbounded computation with no declared limit is Amendment 19's
unreportable exit wearing a performance costume. Worth recording alongside it: the *worst* case need not be the
*measured* case — at vertex 30 every sign test collapsed to rational identities, and an exactly-recognizable
rational short-circuit is a legitimate optimization as long as it is an exact identity and the general path stays
reachable. `DESIGN.md` Amendment 23, `LESSONS.md` 76.

**A measurement is evidence only if some identity or projection carries it.** `vertexTransitStates` was built at the
failure site by CB6, extended exactly and correctly by CB7, attached to the typed error — and read zero times,
because it has no projection out of the producer. Three consecutive measures (AS1, AU1, AU3) ordered it; three
consecutive reviews observed its absence; every turn complied exactly. The two authoring-time controls cost nothing:
**a measure that orders a measurement must name the identity or projection that will carry it**, and **a diagnostic
added to a typed error for operational reporting must have its projection extended in the same change**. A
diagnostic built and destroyed at a stage boundary is unexecuted authority (`LESSONS.md` 56) wearing a diagnostic's
costume. `LESSONS.md` 75.

**Exact representation can still carry the wrong semantic authority.** TB6-REV adds a sharper instance to the
single-authority family. CB7 correctly removed the CB6 float round-trip and made every value reaching the sector
predicate exact, but the transition step then renamed each target face's `nextPairing->direction` as
`incomingDirection`. Exactness was restored while Amendment 17's one-datum invariant was lost: a branch
**correspondence** (`signedLift`) is not an exact continuous transport of an arbitrary geometric ray, and a local
field representative is not a projection of the original datum merely because it has the corresponding branch
label. **Audit the writer of the semantic datum after every representation correction, not only its numeric type.**
This is also a diagnostic-funnel instance: the resolver owns the exact state rows but the production DTO drops them,
so the most important evidence disappears at a stage boundary.


Four families account for nearly every CP4c-2 turn that went sideways. Check against these *before* writing a
plan or a fix.

**`RP-01 / AUTHORITY_DOMAIN_CONFLATION` — two authorities for one datum.** Rails from `rails_from_atlas` versus
the pipeline's `authoritativeRails` has now bitten **five** times, most recently as R8's gating red at ordinal 359.
A number and the expectation it is compared against must come from the same authority, and every published record
should name the authority it used. Two refinements the fifth instance taught: the production authority is a **chain
of four products** (rails, hard-feature edges, component labels, sheet labels), so naming one of them is not naming
the authority; and a **corrective measure can introduce the very pattern it was written to prevent** — R7-REV's AF3
narrowed "the production torus authority" to "the field" in a parenthetical, and CB7 implemented that exactly.
`LESSONS.md` 59.

**Two classifications of the same datum that were never proved to coincide — the sixth instance, and the first
that is not about rails.** A1's cycle-basis machinery assumes region **boundaries** and **non-traversable** edges
are the same set. That holds for source boundaries and for *separating* feature curves, and is false for a feature
that does not separate — which is exactly the mechanical witness (§7 item 1). Neither classifier is wrong on its
own terms; nobody ever wrote down that they agree, and the code depends on it. When two subsystems partition the
same set of edges/faces for different purposes, state the coincidence as an invariant and test it, or make one
derive from the other.

**`RP-05 / REPRESENTATION_DEPENDENT_IDENTITY` — one digest, two domains.** Semantic identity contaminated with
gauge-dependent provenance. Stabilized at CP2b, fixed for the network at CP3a, and reintroduced by A2a′ now.
Semantic and provenance are **two digests**, always.

**A representation change breaks its consumers in two ways, and only one of them tells you.** Amendment 14 gave a
promoted source edge several derived arcs. A2b read that in two places: a binding check demanding exactly one arc,
which failed **loudly** with a typed code and was localized in one runtime; and a `boundaryVertices` insertion that
assumed a whole-edge arc and therefore **over-inserts into a skip list**, suppressing an ownership check with no
error and no symptom. Fixing only the loud one converts a red gate into a quiet weakening. After changing a
representation, grep every consumer and classify each **by failure mode**, not by whether it compiles — a
permissive consumer is the dangerous one precisely because nothing will report it. `LESSONS.md` 62.

**Two paths that reconcile the same obligation, and only one fails closed.** The sharpest form of the pattern
above, found while deriving Amendment 15. `FieldTransportAtlas` splits prescribed singularities into an interior
map and a boundary map, then reconciles them in two loops written years apart in spirit: the boundary loop
demands an owner and raises `SingularityMismatch` without one; the interior loop looks the owner up, and on a miss
leaves two `std::optional` fields empty and carries on. Both loops "handle" a missing owner. Only one reports it.
A change that moves items from one path to the other — which is exactly what cutting a region does — silently
converts a verified fact into an unverified one. **When one obligation is discharged by two paths, diff their
failure behaviour, not their success behaviour**, and be most suspicious when the split key belongs to a
*different* object than the thing being reconciled (here: the **global** mesh's boundary flag deciding how a
**local** mesh's cycle is checked). `LESSONS.md` 65.

**Wrong-representation, right-arithmetic.** A computation can be internally flawless and describe the wrong
object. Self-consistency is never evidence that the complex is the right one. `LESSONS.md` 22d/22e: check that
the representation can *express* the answer before debugging the algorithm, and convert every consumer of a
representation or none.

**Product property applied to the representation — the same family, one level up.** DEFN-R1 excluded trace-crossed
cut edges by reasoning "the trace is an immutable product, therefore the arrangement may not subdivide it." True
premise, invalid conclusion: `build_arcs` already emits one trace arc per event, and already splits a mandatory
source edge at a trace terminal, without touching the product. An immutability guarantee constrains the *writer*,
not the *derived view*. Before ruling a representation out on an upstream guarantee, read what the existing
consumers of that representation already do — the same control (`LESSONS.md` 22e) that the R2 error missed.

**A green gate proves exactly what it enumerates, and its silence is the finding.** CP4c-2 closed at 365/365 with
one of its three witnesses — the prescribed sphere — unable to reach A2b at all, and with Amendment 14's ordinary
proposal path unexercised. Both were outside the gate by recorded decision, and both are real. A closure record that
lists only what went green is a misleading record: say what the gate did **not** cover, in the same breath. The
converse discipline matters equally — once a gate is frozen and its evidence arrives, do not add conditions to it,
whether the new information favours strictness (`PR8-R044` at R7-REV) or leniency (`AH6` at R10-REV).

**One typed name over many mechanisms — the pattern that has cost the most.** It has now been found twice, in two
different stages, and both times it was believed. `SurfaceCutGraph::topology_error` collapses 36
`GlobalTopologyPlanErrorCode` values into `CellularityNotEstablished`, and the sphere's eight-turn misdiagnosis was
the cost. `FieldTransportAtlas`'s `IncompleteCycleBasis` collapses **seven distinct conditions across eight sites**,
five of which publish only a region id, and the mechanical witness has never been diagnosed at all. **Before
planning around any typed failure that crossed a stage boundary or aggregated several checks, find the translation
site and count how many conditions share the name.** The fix is cheap and additive both times: carry the originating
reason as provenance (AF0 for A2a′, AK1 for A1) without touching the mapping. `LESSONS.md` 57.

**…and the reason you add may itself be a collapse.** The sphere has now been resolved three times, one layer per
turn: `topology_error` collapsed 36 codes → AF0 gave `RotationSystemInconsistent`; nine sites shared that name →
AK3 gave `TraceEventPositionInvalid`; that name covers **two** conditions with opposite fixes. Every layer was
worth resolving and none was wasted, but each was declared "the cause" one turn too early. The rule that falls out:
**when instrumenting a collapsed error, check whether the reason you are adding is itself a collapse before
declaring the layer done** — read the site that sets it and count the distinct conditions that reach it. A one-line
check at authoring time replaces a whole turn. `LESSONS.md` 64.

**Gated observation — the measurement suppressed by its own harness.** Publications gated behind a call that
fails; one error code collapsing several mechanisms with no locus; one witness's failure aborting the loop
before the others publish; a typed error flattened to a bare string. **The witness the design reasoned about is
not the witness that exercises the code** — this bit at ordinal 13, at the C5 torus, and at the sphere. Its most
expensive instance to date is §7 item 1: a `default:` case that assigned a semantic-sounding name to 36 distinct
errors and was believed for eight turns. Related and equally cheap to avoid: an assertion that discards a typed
error it already holds (`ASSERT_TRUE(atlasBuild)` where `atlasBuild.error()` and
`field_atlas_build_error_code_name()` both exist); a diagnostic loop whose per-witness rows are collected and then
summarized down to one row; and a frozen non-gating selector a plan silently declines to run.

**An audit scoped by symbol is not an audit scoped by assumption — and the search can be done perfectly and still
miss.** The sharpest form of the enumeration family, and the first where the discipline was honoured. AM2 told the
implementer that `globalVertexByLocal` becomes many-to-one and that **every consumer of it** must be found *by
search, not by copying the measure's list*. That search was correct, and correctly returned nothing about
`build_singularity_attachments` — which touches neither that map, nor the local mesh, nor the cut, and which holds
the exact assumption Amendment 15 invalidated: *the transport neighbourhood is fully traversable*. It broke the
moment the cut let execution reach it. **Write the audit predicate as the invalidated assumption, in words, and
name at least one consumer that does not touch the changed data structure** — that last item is the evidence the
predicate was not silently reduced to a symbol search. `LESSONS.md` 66.

**A diagnostic channel rebuilt once per stage is a funnel defect wearing three costumes — and the scope of a
measure should come from its reasoning, not from the code you read.** These are one pattern seen from two sides,
and together they account for the last three turns. On the diagnostics side: `fail_surface_cells` takes only
`(code, stage)` and every caller drops the typed error it holds, so TB1, TB2 and TB3-R1 each recovered a locus by
elimination, and each was answered with a bespoke per-code channel — one site had already grown a hand-rolled one
by string-concatenating stage and code. **When the same information is lost at the same boundary twice, give the
boundary a typed payload and convert every call site at once.** On the measures side: AM2 scoped a consumer audit
by **symbol**, AN1 scoped instrumentation by **enum**, and Amendment 16 was written for **A1** — each narrower
than the reasoning that produced it, and each invisible because the implementer complied exactly. **Write the
scope from the argument, and prefer a predicate a reader can apply to code you have not read over an enumeration
of the code you have.** `LESSONS.md` 68 and 69.

**A witness set built to isolate contracts is guaranteed to be silent about degeneracy, so its silence carries no
information.** Every witness this project has run is near-uniform and sliver-free: measured area ratios 2.05–3.17,
maximum aspect ratios 1.72–2.67, valences 4–6, ≤ 152 vertices, all singularities `+1`, genus ≤ 1, every input field
admissible by construction. Production inputs carry area ratios of `10⁶`+ and aspect ratios in the hundreds. Five
architecture proposals were rejected as *unnecessary* on the strength of measurements from that base, and five were
reversed once the base itself was measured. **A rejection of the form "unnecessary, no such case is observed" is
invalid when the evidence cannot produce the case** — the correct disposition is **"unmeasured, witness owed."**
Always separate *"wrong as a diagnosis of what we measured"* from *"wrong as an architecture"*; the first almost
never implies the second. `LESSONS.md` 74.

**Exactness is a property of the derivation chain, not of the final comparison — and a measure that names an
operator will be satisfied by changing the operand.** Amendment 17 required an election to test one datum; AS9
prohibited any tolerance *in the predicate*. CB6 complied with both and still broke the guarantee: it left the
predicate exact and carried the datum through **world-space `double`** — exact barycentric → `to_double()` →
normalized vector → transported in doubles → `from_double_exact()` → exact comparison. An exact comparison on a
float-derived operand is a floating-point decision with an exact final rounding step, and the conversions brought
three silent failure modes into the least observable place in the pipeline. Where speed demands it, only a
**certified filter** is admissible: it returns the provably-correct answer or defers to exact, never an
approximation. `DESIGN.md` Amendment 18, `LESSONS.md` 72.

**A producer with an unreportable exit will eventually report a name that is false.** Four paths in
`resolve_field_vertex_transit` skip a state *before* the per-state diagnostic is recorded, so when the seed itself
dropped, the function returned `VertexTransitSectorUnresolved` with zero candidates **and zero diagnostic rows** —
a typed name asserting an election that never ran. Record the diagnostic **before** any conditional that can skip
the state, and make an empty diagnostic set its own named condition: *"we examined nothing"* and *"we examined
everything and none qualified"* are opposite findings and must never share a code. `DESIGN.md` Amendment 19,
`LESSONS.md` 73.

**An enumeration of candidate *mechanisms* is as dangerous as an enumeration of candidate *consumers*, and a
partition test needs one point, not one point per cell.** At TB3-R1-REV three mechanisms were enumerated for the
vertex-transit red — barrier truncation, singular-vertex holonomy, and a port-policy consumer mismatch — and one
run falsified **all three**: cardinality 2 rather than 0, a vertex that is neither barrier-incident nor
barrier-absorbed, and — proved from the fixture — a **regular** vertex with trivial holonomy. The frozen plan had
listed "exact sector predicate/election defect" among five options and the review's own enumeration dropped it.
**Enumerate mechanisms to design the measurement, never to bound the answer**, and say which observation would fall
outside every listed mechanism. The measurement design was the part that worked: one published field discriminated
all three at once. The technical residue is reusable: the sector predicate is an **exact** half-open partition of
the turn, so a single direction elects at most one wedge — two elections **prove** two distinct directions were
tested, because the routine feeds each cell its own representative. **When an election looks ambiguous, check
whether every candidate is tested against the same datum before touching the partition; when the predicate is
already exact, ambiguity is evidence about the inputs, never a reason to add a tolerance.** `LESSONS.md` 70 and 71.

**Instrument the stage's error surface, not the site that is failing.** AK1/AK2 resolved `IncompleteCycleBasis`
into an enumerated reason plus a full locus row, and did it well — scoped to that one code. One turn later the same
producer failed on the neighbouring code, whose typed error already carries `sourceEdge`, `sourceFace`,
`sourceVertex` and `topologyRegion`, and the harness published only `code/stage`, so the locus had to be recovered
by elimination instead of read. A per-site instrumentation measure buys exactly one turn of visibility.
`LESSONS.md` 67.

**An enumeration inside a measure is read as exhaustive.** Twice in consecutive turns a corrective measure listed
items next to a universal instruction and the list was taken for the instruction's scope. AF3 named "the production
torus authority" then narrowed it in a parenthetical to *the field*, leaving three of four products unconverted;
DEFN-R2 §4 itemized five Amendment-14 changes under "convert every consumer" and omitted A2b's cut-arc binding. Both
were implemented exactly as written and both went red on the omitted part. Put the enumeration in the measure,
produced by search — or say explicitly that the implementer owes it, and require the search rather than a copy.
`LESSONS.md` 59 and 61.

**Transcribed constants and abbreviated digests.** A hash copied from prose is not evidence; a hash written as
`PREFIX…SUFFIX` in a table where values belong invites a later reader to reconstruct the middle, and the
reconstruction looks plausible. Four such values reached an executor and one was not even 64 characters.
Recompute from the named file, and validate any expected digest as exactly 64 lowercase hex at authoring time.
**This has now happened three times** — `R7-ORCH-01`, and again in a rejected TB1 control that transcribed a
packaged-source SHA-256 as a **63-hex** value, despite `LESSONS.md` 22n and measure AE4 existing to prevent
precisely it. A rule that has failed to prevent its own defect twice needs a **mechanism**: AL8 moves the 64-hex
validation into the orchestration payload authoring path, so the check runs where the value is written rather than
depending on an author remembering it.

A sixth, meta-level: **a result that discharges a premise must be reported as a finding, not left as a field
value.** The torus's `pipelinePlanAvailable=true` — the fact that A2a′ works end to end — sat unremarked in an
evidence table under a "semantic red" verdict.

**Artifact bytes are not the whole package contract.** Executable permission is semantic runtime metadata for packaged binaries. A transport can preserve every file hash while silently destroying executability. If a package crosses Actions artifact download/upload boundaries, carry permission-sensitive trees inside a mode-preserving archive and verify modes after a clean round trip. Never make TB repair package permissions: that hides a packaging defect and invalidates immutable-artifact authority.

## 9. Where to look

**Architecture and plan:** `DESIGN.md` (§4.5 grazing, §4.6 motorcycle graph, §7.2 region derivation with
Amendments 12 and 13), `ROADMAP.md`, `REORIENTATION_PLAN.md`.

**Current state:** `TODO.md` current-focus block; `Future_Chat_Session_Handoff.md` next-turn block;
`Regression_Root_Cause_Tracker.md` for every open defect; `CHANGELOG.md` newest-first for how we got here.

**Durable knowledge:** `LESSONS.md` — organized in eight sections; §2 fixtures/witnesses, §4 single authority,
§5 cross-field conventions and §6 gate authoring carry the most reusable content.

**CP4c history:** `M3_CP4c_Consolidated_Record.md` holds the retired per-turn records with their evidence,
review arcs and withdrawn predictions. Closure records: `M1_`, `M2_`, `M3_CP2_`, `M3_CP2b_`, `M3_CP3_`,
`M3_CP4ab_`, `M3_CP4c1_Closure_Record.md`.

**Key source:**

| what | where |
|---|---|
| tracing, grazing transit, termination | `src/geometry/SurfaceCellTracing.cpp`, `include/directional/geometry/SurfaceCellTracing.h` |
| cut graph (A2a′) | `src/geometry/SurfaceCutGraph.cpp`, `include/directional/geometry/SurfaceCutGraph.h` |
| shared embedded-graph authority | `src/geometry/EmbeddedGraphTopology.{h,cpp}` |
| region derivation (A2b) | `src/geometry/GlobalTopologyPlan.cpp` |
| pipeline wiring, product snapshots | `src/pipeline/RemeshPipeline.cpp` (~6560-6640) |
| exact arithmetic | `include/directional/numerics/BigInteger.h`, `ENumberGMP.h`, `authority/FieldTransportAtlas.h` |
| the whole test suite | `tests/FieldAlignedCurveNetworkTests.cpp` |

**Witness fixtures:** `benchmarks/fixtures/milestone-g/{torus,sphere_prescribed,mechanical_feature}.{obj,rawfield}`.
The two-ring is constructed in the test file, not a fixture.

## 10. Facts worth not re-deriving

- Sphere: 98 V / 192 F / 288 E, `χ=2`, 8 index-¼ singularities at cube corners, 24 ports, 24 traces, 56 events,
  **zero mandatory edges**. Its pre-cut actual embedded graph is `V/E/F = 18/30/18`, one component, `χ=6` — excess
  4 over `sourceChi=2`, hence non-cellular.
  Of 48 directed trace ends, 42 terminate at singularities; the remaining 6 once circulated forever and are now
  terminated by crash-on-contact.
- Torus: 72 V / 144 F / 216 E, `χ=0`, zero singularities, 48 hard-feature mandatory edges forming (inferred,
  and consistent with the measurements) four loops of twelve edges; four annular complement components. Those
  loops **separate** the torus into the four annuli, which is precisely why its hard-feature edges land on region
  boundaries and never enter a local mesh's inner adjacency set.
- Mechanical feature: 152 V / 300 F, and **one** topology region covering all 300 faces —
  `V/E/F = 152/450/300`, `χ=2`, `genus=0`, `boundaryLoops=0`, 152 interior local vertices, 152 expected cycles,
  450 inner adjacencies, `globalEF = localEF = 1,158` at edge `0-3`. Its hard features therefore do **not**
  separate, and since every closed curve on a sphere separates, the feature set must contain at least one **open
  arc**. This is the whole of criterion C2's difficulty.
- Two-ring: actual embedded graph `V/E/F = 9/11/3`; source-edge-barrier proxy `10/11/2`. Both satisfy Euler.
- Torus actual embedded graph **after** cuts: `V/E/F = 72/76/4`, `χ = 0 = sourceChi` — i.e. cuts added 24 vertices
  and 28 edges to the 48/48 pre-cut network.
- `SurfaceCutGraphErrorCode::CellularityNotEstablished` is **not** always a cellularity finding. Via
  `topology_error`'s `default:` it is the bucket for 36 distinct `GlobalTopologyPlanErrorCode` values. Check
  whether the error carries a `sourceFace`: only `topology_error` sets one, so a populated `sourceFace` means the
  failure came from `EmbeddedGraphTopology`, upstream of any cellularity decision. On the prescribed sphere the
  full resolved chain is now `CellularityNotEstablished → RotationSystemInconsistent → TraceEventPositionInvalid`,
  and the last of those is still two conditions wide.
- Cutting a surface along a subgraph `B` of its 1-skeleton: duplicate each vertex into one copy per connected
  component of `star(v) ∖ B` — `copies(v) = d_B(v)` interior, `d_B(v) + 1` on the boundary, so a degree-1 **tip is
  not duplicated**. Then `ΔV = (2|B| − |V(B)|) + ∂`, `ΔE = |B|`, `ΔF = 0`, giving
  **`χ(cut) = χ − χ(B) + ∂`** where `χ(B) = |V(B)| − |B|` and `∂` counts `B`'s vertices already on the boundary.
  Verified against: sphere + one arc → disc; torus + one non-separating loop → annulus; disc + arc to the
  boundary → disc; disc + arc between two boundary points → two discs.
- `dual_cycles` (`geometry/MeshTopology.h:55-74`) emits `#V − #b` inner-vertex cycles **in vertex order**, then
  `#b` boundary cycles, then `2g` generators, with columns indexed into **inner edges only**. That column rule is
  why making an edge a boundary edge removes it from the cycle basis entirely — the mechanism Amendment 15 relies
  on. The row count exceeds the dual cycle space dimension by exactly **1** (one linear dependency), on both the
  uncut and the cut mesh.
- `TriMesh::set_mesh` (`core/TriMesh.h:202-241`) derives `EV`, `EF`, `isBoundaryVertex`, `isBoundaryEdge` and
  `boundaryLoops` from V/F, and `gaussian_curvature` consumes `isBoundaryVertex`. So a cut expressed purely as a
  rewritten face array propagates to every count and curvature with no further bookkeeping.
- `build_source_topology_regions` requires **every** region-boundary vertex to have exactly two boundary
  neighbours (`SurfaceCellTracing.cpp:6905`) and fails the whole `SourceTopologyRegions` product otherwise. An
  open slit is therefore inexpressible at the region level — its tip would have one — which is why Amendment 15
  puts the cut in A1's derived local mesh instead.
- `trace_event_position` (`EmbeddedGraphTopology.cpp:138-173`) returns `std::nullopt` from a single
  `if (positions.size() != 1U)`, so "no carrier matched" and "several carriers matched" are indistinguishable at
  the call site. It also runs **two** passes — segments whose `sourceFace` matches the event's, then, only if that
  found nothing, all segments ignoring the face — so the widening pass can report an *ambiguous* failure for an
  event whose precise pass was *empty*.
- Terminal event kinds: `SingularityPortOrigin(0)`, `FirstContact(1)`, `TraceIntersection(2)`,
  `MandatoryBarrierTermination(3)`, `SingularityTermination(4)`, `SingularityPortJunction(5)`,
  `TraceSelfClosure(6)`. The observed terminal union across witnesses is exactly `{2, 3, 4}`.
- `direction_in_vertex_sector` (`FieldTransportAtlas.cpp:1623-1653` → `direction_in_incident_vertex_sector`
  `:404-426`) is exactly `direction[next] > 0 && direction[previous] >= 0`, indexed **by vertex identity** —
  `SourceFaceTopologyKey::make` **sorts** its three vertices, so canonical-key order is not the mesh row's corner
  order, and `next`/`previous` come from `F(row, (c+1)%3)` / `F(row, (c+2)%3)`. It includes the `next` radial ray
  and excludes the `previous` one. It is an **ownership partition of a fan**, not a membership test for one face.
- A `VertexHit` arrives with **two** possible shapes. `|M| = 2` is the ordinary T2 transit: `d[hit] > 0` and both
  other coordinates negative, so the reversed arrival ray is strictly inside the wedge. `|M| = 1` with a vertex
  landing is Amendment 3: some `d[k] = 0` **exactly** and `p[k] = 0`, meaning the trace runs along the mesh edge
  opposite `v_k` and stops at its far endpoint — and then the reversed arrival ray lies exactly **on** a radial ray.
  Both publish `arrivalMode = FaceInterior`.
- On the mechanical witness, face `(8,10,11)` is mesh row 8 with corner order `[8,10,11]`, and its branch-1
  direction is `(0, −2.77777777777777857, +2.77777777777777857)` over `(v8, v10, v11)` — an exact IEEE zero at
  `v8`. Vertex **10** is one of the four port-emitting singularities (10, 35, 47, 71), so the first segment of that
  port trace is the mesh edge `10 → 11`.
- `FieldTransportAtlas::make` derives a cycle's lift as `exactLift = (cycles · effort + 4 · cycleCurvature) / 2π`,
  where `cycleCurvature` for an inner-vertex cycle is *the Gaussian curvature* (angle defect `2π − Θ`) and `effort`
  is read from `CrossFieldEdgeTransition::effort` — **never recomputed**. Branch transport is
  `QuarterTurn::from_integer(raw.matching)`. So a synthetic field that declares `effort ≡ 0` is asserting a flat
  star, and a synthetic field whose matching does not compose to the resulting lift fails `CycleTransportMismatch`
  before anything else looks at it.
- Vertex-star transit only ever runs at a **regular** vertex: both call sites check
  `field_aligned_singularity_at` first and terminate the trace with `SingularityTermination` when a singularity
  fact exists there. So a witness for vertex-star continuation may not put its interesting geometry on a singular
  vertex — a non-flat center must carry `Σ_cycle effort = −4K` so that its lift is `0`.
- `EmbeddedGraphTopology.cpp` emits `GlobalTopologyPlanErrorCode::RotationSystemInconsistent` from **46 sites**,
  all reachable from `SurfaceCutGraph::make` via `build_embedded_graph_topology` (`build_cut_node_bindings`,
  `build_arcs`, `build_rotation_system`, `walk_graph_faces`) and `exterior_boundary_orbits`. Only **9** publish a
  `RotationSystemInconsistencyReason`, and all 9 also set `sourceEdge` and/or `sourceFace`. Per function —
  `build_arcs` 4 sites / 2 reasons, `build_node_loci` 5 / 3, `build_rotation_system` 27 / 4, `walk_graph_faces`
  9 / 0, `exterior_boundary_orbits` 1 / 0. `GlobalTopologyPlan.cpp` emits the same code from a further 8 sites.
- The `RotationSystemInconsistent` datum is dropped at **three** boundaries in series: the silent producer sites;
  `SurfaceCutGraph::topology_error`, whose `SurfaceCutGraphError` has **no `sourceVertex` field**; and
  `RemeshPipeline::cut_graph_failure_locus`, which publishes only `sourceEdge`/`sourceFace` out of the ten fields
  the error carries.
- `SurfaceCellDiagnosticProductSnapshots` retains `fieldTransportAtlasError` but has **no** `surfaceCutGraphError`
  and no `globalTopologyPlanError`; `productSnapshots.surfaceCutGraph` is assigned only on success. So a cut-graph
  failure leaves no typed object behind.
- The two CP4c witness-observation idioms differ in what they can see. `build_cp4c_production_fixture` **throws**
  unless all five of `sourceAuthority`, `atlas`, `network`, `cutGraph`, `plan` are retained, rendering only
  `terminalFailureLocus` through `append_cp4c_failure_locus`. `observe_cp4c_witness` re-invokes each stage directly
  from the four production inputs and therefore holds each typed error, rendering the cut-graph reason, trace,
  event and position diagnostics. Ordinals 366 and 368 differ by exactly this choice.
- `SurfaceCutGraph::make` certifies inside a `while(true)` cut-proposal loop and returns the **first**
  `certify_actual_embedded_graph` failure, so a published cut-graph error does not say whether it came from the
  initial uncut certification or from a later proposal.
- Grazing is **edge transit**, not termination — decided on a continuity argument, not on cost data.
- Trace termination is **crash-on-contact** (motorcycle graph), on an exact predicate, with mutual termination
  on a tie; the production arrival priority is `ArcLengthFiltered` with a certified forward error bound.
- GMP/GMPXX linkage is mandatory for every compile; fallback exact arithmetic is not authoritative build
  evidence.
- `FieldAlignedCurveNetworkError` carries far more than the locus can render. The projection
  `RemeshPipeline.cpp::network_failure_locus` → `SurfaceCellFailureLocusDiagnostics` carries `sourceVertex`,
  `sourceEdge`, `sourceFace`, `branch`, `topologyRegion`, `vertexArrivalMode`, `vertexTransitStates`,
  `vertexStarTransit` and `publishedFaces` — **and nothing else**. `traceSeedVertex`, `traceSeedSingularity`,
  `traceHistory`, `traceSteps`, `traceStepBudget`, `traceCombinatorialVisits`, `traceCombinatorialVisitAllowance`,
  `singularity`, `rail`, `relatedSourceFace`, `relatedBranch`, `signedLift`, `parameter`, `exactValues` and
  `publishedEdges` have **no projected field at all**. Their only readers are the test-local renderer
  `network_error_locus` (`tests/FieldAlignedCurveNetworkTests.cpp:4808-4834`) and assertions in ordinals 328/329.
- `append_cp4c_failure_locus` prints in a **fixed order**: `sourceVertex`, `sourceEdge`, `sourceFace`, `branch`,
  `topologyRegion`, `arrivalMode`, `publishedFaceCount`, `publishedFaces`, `barrier*`,
  `transportStarComponentCount`, `vertexTransitState[…]`, `vertexStar*`. So a **missing** token proves the
  underlying optional was empty — absence is evidence, not truncation.
- `FieldAlignedCurveNetworkError::publishedFaces` is declared (`SurfaceCellTracing.h:311`) and **never assigned**
  anywhere in `src/` or `include/`. Every network-stage error renders `publishedFaceCount=0` by construction.
- The mechanical fixture is **closed with `χ = 2`** — 152 V / 300 F, 0 boundary edges. Its `x = ±1.4` sides are
  50-face **coplanar** patches, so many interior edges there have an exactly 0° dihedral and can never be hard
  feature edges (and therefore never barriers, and never a `terminalBarrier`). Face row 51 is exactly `(36,38,39)`.
- `terminalContact` is set by `field_aligned_publish_contact` but is **never read in
  `finalize_field_aligned_events`**; that function branches only on `terminalSingularity` and `terminalBarrier`,
  and everything else falls through to a **loop-closure** test. `field_aligned_first_trace_contact` compares trace
  `i` only against indices `< i`, so it can never match trace 0 — and it declares a contact on **mere source-face
  coincidence**, with no crossing test (`field_aligned_segments_properly_cross` feeds the census only).
- A singularity **port** and a singularity **node** are different authorities with different cardinality.
  `nodeVertices.insert(singularity.sourceVertex)` runs for **every** singularity, before and outside the
  `portPolicy` test, and `candidate.nodes` is materialized **before** `candidate.singularityPorts`. The port loop
  then skips `BarrierAbsorbed` entirely, so such a singularity has a node and **zero** ports. Ports constrain a
  trace's **origin** only.
- `FieldSingularityFact::PortPolicy` is `BarrierAbsorbed` iff the vertex is in `slitCycleByGlobalVertex`
  (`FieldTransportAtlas.cpp:2467-2470`), populated at `:2296-2300` iff *not a mesh-boundary vertex* ∧
  *in `local->barrierVertices`* ∧ *singular*. Local-cycle and slit-cycle ownership are an exclusive XOR over all
  singularities (`:2428-2432`). On a closed witness this reduces to **singular ∧ barrier-incident**.
- **Barrier edges are region-restricted, not merely sharp** (`FieldTransportAtlas.cpp:955-966`): a hard feature
  edge becomes a barrier only when **both** incident faces lie in the region being localized. So a sharp edge that
  bounds a region is not a barrier. Do not use dihedral angle as a proxy for `barrierVertices` — v47 has three
  exactly-90° incident edges and is proved `Emit` by TB9's own trace seed.
- `FieldBoundaryPoint::source_support()` (`FieldTransportAtlas.h:601-610`) returns `SourceVertexSupport{edge.first()}`
  at parameter 0, `SourceVertexSupport{edge.second()}` at parameter 1, and `SourceEdgeSupport` strictly between.
  Both `VertexHit` constructions are built to invert exactly that mapping, so on the production path the terminal
  support vertex always equals `decision.sourceVertex`.
- `trace.terminalSingularity` is set at exactly one place — the `VertexHit` branch of
  `field_aligned_advance_trace_proposal` — via `field_aligned_singularity_at(atlas, *decision.sourceVertex, …)`,
  which matches **by vertex**. The `VertexHit` check runs **before** the `mandatoryByEdge` barrier check, so a
  vertex that is both a barrier endpoint and a singularity is adjudicated as a singularity termination.
- Trace history in a production locus is exact: `entryParameter=1/1` on every row means every entry point sat on a
  vertex, i.e. the trace transited vertices rather than edge interiors. `incomingCarrier=none` on a first segment
  is a port origin.
